/* -*- pse-c -*-
 *-----------------------------------------------------------------------------
 * Filename: gmm.c
 * $Revision: 1.46 $
 *-----------------------------------------------------------------------------
 * Copyright © 2002-2010, Intel Corporation.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 *-----------------------------------------------------------------------------
 * Description:
 *  Very basic video memory managment functions required by HAL.
 *-----------------------------------------------------------------------------
 */

#define MODULE_NAME hal.gmm

#include <igd_debug.h>
#include <drmP.h>
#include <memlist.h>
#include <io.h>
#include <memory.h>

#include <asm/agp.h>

#define AGP_PHYS_MEMORY 2 /* Physical contigous memory */


gmm_context_t gmm_context;

gmm_chunk_t *gmm_get_chunk(igd_context_t *context, unsigned long offset);
static int gmm_flush_cache(void);
static int gmm_alloc_linear_surface(unsigned long *offset,
		unsigned long pixel_format,
		unsigned int *width,
		unsigned int *height,
		unsigned int *pitch,
		unsigned long *size,
		unsigned long type,
		unsigned long flags,
		unsigned long phys);

static int gmm_alloc_chunk_space(gmm_context_t *gmm_context,
		unsigned long *offset,
		unsigned long size,
		unsigned long phys,
		unsigned long flags);

static int gmm_get_page_list(unsigned long offset,
		unsigned long **pages,
		unsigned long *page_cnt);

gmm_mem_buffer_t *emgd_alloc_pages(unsigned long num_pages, int type);
void emgd_free_pages(gmm_mem_buffer_t *mem);
void emgd_gtt_remove(igd_context_t *context, gmm_mem_buffer_t *mem,
		unsigned long offset);
void emgd_gtt_insert(igd_context_t *context, gmm_mem_buffer_t *mem,
		unsigned long offset);


static void gmm_free(unsigned long offset)
{
	gmm_chunk_t *chunk;

	EMGD_DEBUG("Enter gmm_free(0x%lx)", offset);

	/* Walk the chunk list */
	chunk = gmm_context.head_chunk;
	while (chunk) {
		if (chunk->offset == offset) {
			if (chunk->used == 0) {
				EMGD_DEBUG("WARNING: The chunk 0x%lx is already freed", offset);
			} else {
				EMGD_DEBUG("Freeing the chunk 0x%lx", offset);
			}

			/*
			 * What to do if the ref count is > 0?  Unmapping is
			 * probably the right thing since nothing should try
			 * to use this. If something does, it should probably
			 * fail.
			 */
			if (chunk->ref_cnt > 0) {
				EMGD_DEBUG("WARNING: The chunk 0x%lx is mapped", offset);
				chunk->ref_cnt = 0;
				vunmap(chunk->addr);
				chunk->addr = NULL;
			}
			/* Free the array of page address, if applicable: */
			if (chunk->page_addresses != NULL) {
				EMGD_DEBUG("About to free chunk->page_addresses = 0x%p",
					chunk->page_addresses);
				OS_FREE(chunk->page_addresses);
				chunk->page_addresses = NULL;
			}

			chunk->used = 0;  /* mark as free */
			return;
		}
		chunk = chunk->next;
	}

	EMGD_ERROR("gmm_free() did not find the chunk 0x%lx to free", offset);
	return;
}

static int gmm_alloc_region(unsigned long *offset,
	unsigned long *size,
	unsigned int type,
	unsigned long flags)
{
	int ret;
	unsigned long aligned_size;
	unsigned long phys = 0;

	EMGD_TRACE_ENTER;
	EMGD_DEBUG("Parameters: size=%lu, type=%d, flags=0x%lx", *size, type, flags);

	*offset = 0;

	switch(type) {
	case IGD_GMM_REGION_TYPE_OVLREG:
		flags |= IGD_GMM_REGION_ALIGN_MMAP;
		phys = 1;
		break;
	case IGD_GMM_REGION_TYPE_OVLREG64:
		flags |= IGD_GMM_REGION_ALIGN_64K;
		phys = 1;
		break;
	case IGD_GMM_REGION_TYPE_HWSTATUS:
		flags |= IGD_GMM_REGION_ALIGN_MMAP;
		*size = 4096;
		phys = 1;
		break;
	case IGD_GMM_REGION_TYPE_DMA:
		flags |= IGD_GMM_REGION_ALIGN_MMAP;
		break;
	case IGD_GMM_REGION_TYPE_PERSISTENT:
		flags |= IGD_GMM_REGION_ALIGN_MMAP;
		break;
	case IGD_GMM_REGION_TYPE_BPL:
		flags |= IGD_GMM_REGION_ALIGN_MMAP;
		phys = 1;
		break;
	case IGD_GMM_REGION_TYPE_CONTEXT:
		flags |= IGD_GMM_REGION_ALIGN_CONTEXT | IGD_GMM_REGION_ALIGN_MMAP;
		*size = 4096;
		phys = 1;
		break;
	default:
		EMGD_ERROR_EXIT("Invalid Region type requested: 0x%8.8x", type);
		return -IGD_INVAL;
	}

	aligned_size = (*size + 4095) & ~4095;
	EMGD_DEBUG("aligned_size=%lu", aligned_size);

	do {
		ret = gmm_alloc_chunk_space(&gmm_context, offset, aligned_size, phys,
				flags);
	} while ((ret == -IGD_ERROR_NOMEM) && gmm_flush_cache());

	EMGD_DEBUG("EXIT  Returning %d", ret);
	return ret;
}

static int gmm_get_num_surface(unsigned long *count)
{
	gmm_chunk_t *chunk;

	EMGD_TRACE_ENTER;

	/* Walk the chunk list */
	chunk = gmm_context.head_chunk;
	*count = 0;
	while (chunk) {
		(*count)++;
		chunk = chunk->next;
	}

	EMGD_TRACE_EXIT;
	return 0;
}

static int gmm_get_surface_list(unsigned long allocated_size,
	unsigned long *list_size,
	igd_surface_list_t **surface_list)
{
	gmm_chunk_t *chunk;
	igd_surface_list_t *tmp_list;

	EMGD_TRACE_ENTER;
	gmm_get_num_surface(list_size);

	if (*list_size > 0){
		*surface_list = vmalloc(*list_size * sizeof(igd_surface_list_t));

		/* Walk the chunk list */
		chunk = gmm_context.head_chunk;
		tmp_list = *surface_list;

		while (chunk){
			tmp_list->offset = chunk->offset;
			tmp_list->size = chunk->size;

			chunk = chunk->next;
			tmp_list++;
		}
	}
	EMGD_TRACE_EXIT;
	return 0;
}

static int gmm_alloc_surface(unsigned long *offset,
	unsigned long pixel_format,
	unsigned int *width,
	unsigned int *height,
	unsigned int *pitch,
	unsigned long *size,
	unsigned int type,
	unsigned long *flags)
{
	int ret;
	unsigned long phys;

	EMGD_TRACE_ENTER;
	EMGD_DEBUG("Parameters: pixel_format=0x%08lx,", pixel_format);
	EMGD_DEBUG("  width=%u, height=%u", *width, *height);
	EMGD_DEBUG("  pitch=%u, type=%d, flags=0x%08lx", *pitch, type, *flags);

	*offset = 0;
	*size = 0;
	if (! (*flags & IGD_MIN_PITCH)) {
		*pitch = 0;
	}

	if (*flags & IGD_SURFACE_CURSOR) {
		phys = 1;
	} else {
		phys = 0;
	}

	ret = gmm_alloc_linear_surface(offset, pixel_format, width, height, pitch,
			size, type, *flags, phys);

	EMGD_DEBUG("EXIT  Returning %d", ret);
	return ret;
}


/*
 * Given an offset, find the chunk and return the physical address.
 */
static int gmm_virt_to_phys(unsigned long offset,
	unsigned long *physical)
{
	gmm_chunk_t *chunk;

	EMGD_TRACE_ENTER;
	EMGD_DEBUG("Looking for offset=0x%lx", offset);

	/* Walk the chunk list */
	chunk = gmm_context.head_chunk;
	while (chunk) {
		if (chunk->offset == offset) {
			*physical = chunk->gtt_mem->physical;
			EMGD_DEBUG("Physical address = 0x%08lx", *physical);
			EMGD_TRACE_EXIT;
			return 0;
		}
		chunk = chunk->next;
	}

	/* offset not found */
	EMGD_ERROR_EXIT("Did not find offset (0x%lx); returning %d",
		offset, -IGD_ERROR_NOMEM);
	return -IGD_ERROR_NOMEM;
}


static int gmm_flush_cache(void)
{
	EMGD_DEBUG("Enter gmm_flush_cache(), which is stubbed");
	return 0;
}

static void gmm_save(igd_context_t *context, void **state)
{
	EMGD_DEBUG("Enter gmm_save(), which is stubbed");
	return;
}

static void gmm_restore(igd_context_t *context, void *state)
{
	EMGD_DEBUG("Enter gmm_restore(), which is stubbed");
	return;
}

/*
 * Create a virtual address mapping for a block of video memory.
 */
static void *gmm_map(unsigned long offset)
{
	gmm_chunk_t *chunk;
	struct page **page_map;
	int i;
	void *addr = NULL;
	unsigned long num_pages;
	unsigned long size;

	EMGD_TRACE_ENTER;
	EMGD_DEBUG("Parameter: offset=0x%lx", offset);

	chunk = gmm_get_chunk(gmm_context.context, offset);

	if (chunk == NULL) {
		printk(KERN_ERR"[EMGD] gmm_map: Failed to find chunk: 0x%lx\n", offset);
		return NULL;
	}

	/*
	 * Check if this as been mapped already and return that map instead
	 * of remapping it.
	 */
	chunk->ref_cnt++;
	if (chunk->addr) {
		EMGD_DEBUG("This chunk is already mapped!");
		return chunk->addr;
	}

	/*
	 * Read the physical addresses of the allocation from the GTT
	 * and convert that to a page list.
	 */

	size = PAGE_ALIGN(chunk->size);
	num_pages = size / PAGE_SIZE;

	if (num_pages != chunk->gtt_mem->page_count) {
		printk(KERN_ERR"[EMGD] gmm_map: Num pages don't match %lu vs. %lu\n",
				num_pages, (unsigned long)chunk->gtt_mem->page_count);
		return NULL;
	}

	/*
	 * chunk->memory is an agp_memory struct
	 * This has an elements struct page **pages and page_count
	 */
	page_map = vmalloc(num_pages * sizeof(struct page *));
	if (page_map == NULL) {
		printk(KERN_ERR"[EMGD] gmm_map: vmalloc failed.\n");
		return NULL;
	}

	for (i = 0; i < num_pages; i++) {
		page_map[i] = chunk->gtt_mem->pages[i];
	}

	addr = vmap(page_map, num_pages, VM_MAP, PAGE_KERNEL_UC_MINUS);

	vfree(page_map);
	chunk->addr = addr;

	EMGD_DEBUG("Mapped address = 0x%p", addr);
	EMGD_TRACE_EXIT;

	return addr;
}


static void gmm_unmap(void *addr)
{
	gmm_chunk_t *chunk;

	EMGD_TRACE_ENTER;
	EMGD_DEBUG("Parameter: addr=0x%p", addr);

	/* Look up the chunk that was mapped to this address */
	chunk = gmm_context.head_chunk;
	while (chunk) {
		if (chunk->addr == addr) {
			EMGD_DEBUG("The chunk with addr=0x%p has the offset = 0x%08lx", addr,
				chunk->offset);
			chunk->ref_cnt--;
			if (chunk->ref_cnt == 0) {
				EMGD_DEBUG("About to call vunmap(0x%p)", addr);
				vunmap(addr);
				chunk->addr = NULL;
			}
			return;
		}
		chunk = chunk->next;
	}

	EMGD_TRACE_EXIT;
}

int gmm_init(igd_context_t *context,
	unsigned long scratch_mem,
	unsigned long max_fb_mem)
{
	EMGD_TRACE_ENTER;
	EMGD_DEBUG("Parameters: scratch_mem=0x%lx, max_fb_mem=%lu",
		scratch_mem, max_fb_mem);

	context->dispatch.gmm_alloc_surface = gmm_alloc_surface;
	context->dispatch.gmm_alloc_region = gmm_alloc_region;
	context->dispatch.gmm_virt_to_phys = gmm_virt_to_phys;
	context->dispatch.gmm_free = gmm_free;
	context->dispatch.gmm_memstat = NULL;
	context->dispatch.gmm_alloc_cached = NULL;
	context->dispatch.gmm_free_cached = NULL;
	context->dispatch.gmm_alloc_cached_region = NULL;
	context->dispatch.gmm_free_cached_region = NULL;
	context->dispatch.gmm_flush_cache = gmm_flush_cache;
	context->dispatch.gmm_alloc_reservation = NULL;
	context->dispatch.gmm_alloc_heap = NULL;
	context->dispatch.gmm_alloc_heap_block = NULL;
	context->dispatch.gmm_free_heap_block = NULL;
	context->dispatch.gmm_get_heap_from_block = NULL;
	context->dispatch.gmm_get_pvtheap_size = NULL;
	context->dispatch.gmm_get_cache_mem = NULL;
	context->dispatch.gmm_alloc_persistent_region = NULL;
	context->dispatch.gmm_free_persistent_region = NULL;
	context->dispatch.gmm_map = gmm_map;
	context->dispatch.gmm_unmap = gmm_unmap;
	context->dispatch.gmm_get_page_list = gmm_get_page_list;
	context->dispatch.gmm_get_num_surface = gmm_get_num_surface;
	context->dispatch.gmm_get_surface_list = gmm_get_surface_list;

	context->mod_dispatch.gmm_save = gmm_save;
	context->mod_dispatch.gmm_restore = gmm_restore;

	gmm_context.context = context;
	gmm_context.head_chunk = NULL;
	gmm_context.tail_chunk = NULL;

	/* Reserve memory for framebuffer ??? */

	EMGD_DEBUG("EXIT  Returning %d", 0);
	return 0;
}


void gmm_shutdown(igd_context_t *context)
{
	gmm_chunk_t *chunk, *del;
	struct drm_device *dev;

	EMGD_TRACE_ENTER;

	dev = (struct drm_device *)context->drm_dev;

	/* Walk the chunk list */
	chunk = gmm_context.head_chunk;
	while (chunk) {
		EMGD_DEBUG("process chunk at 0x%lx", chunk->offset);
		if (chunk->used == 1) {
			EMGD_ERROR("Chunk at 0x%lx not properly freed", chunk->offset);
		}

		if (chunk->addr != NULL) {
			vunmap(chunk->addr);
		}

		if (chunk->bound) {
			emgd_gtt_remove(context, chunk->gtt_mem, chunk->offset);
		}
		emgd_free_pages(chunk->gtt_mem);

		/* Free the array of page address, if applicable: */
		if (chunk->page_addresses != NULL) {
			EMGD_DEBUG("About to free chunk->page_addresses = 0x%p",
				chunk->page_addresses);
			OS_FREE(chunk->page_addresses);
		}

		/* Free the chunk */
		del = chunk;
		chunk = chunk->next;
		OS_FREE(del);
	}

	EMGD_TRACE_EXIT;
	return;
}

gmm_chunk_t *gmm_get_chunk(igd_context_t *context, unsigned long offset)
{
	gmm_chunk_t *chunk;

	chunk = gmm_context.head_chunk;
	while (chunk) {
		if (chunk->offset == offset) {
			return chunk;
		}
		chunk = chunk->next;
	}

	printk(KERN_ERR "[EMGD] gmm_get_chunk: Failed to find chunk 0x%lx\n",
		offset);
	return NULL;
}



static int gmm_alloc_linear_surface(unsigned long *offset,
	unsigned long pixel_format,
	unsigned int *width,
	unsigned int *height,
	unsigned int *pitch,
	unsigned long *size,
	unsigned long type,
	unsigned long flags,
	unsigned long phys)
{
	int ret;
	unsigned long align;
	unsigned long min_pitch;
	unsigned long test = 1;

	EMGD_TRACE_ENTER;
	EMGD_DEBUG("Parameters: pixel_format=0x%08lx,", pixel_format);
	EMGD_DEBUG("  width=%u, height=%u", *width, *height);
	EMGD_DEBUG("  pitch=%u, size=%lu, type=%lu", *pitch, *size, type);
	EMGD_DEBUG("  flags=0x%08lx; phys=%lu", flags, phys);

	/* Validate surface */
	if (! *width) {
		*width = 1;
	}

	if (! *height) {
		*height = 1;
	}

	/* Set the minimum surface pitch */
	min_pitch = (IGD_PF_DEPTH(pixel_format) * *width) >> 3;
	if (min_pitch < *pitch) {
		min_pitch = *pitch;
	}

	/* Make sure pitch is power of two */
	while (test < min_pitch) {
		test <<= 1;
	}
	min_pitch = test;

	/*
	 * Size should be based on pixel format and pitch, not just pitch.
	 * For YUV surfaces, it is smaller than RGB surfaces.
	 */
	switch (IGD_PF_TYPE(pixel_format)) {
	case PF_TYPE_YUV_PLANAR:
		*size = min_pitch * (*height + (*height>>1));
		break;
	case PF_TYPE_YUV_PACKED:
		/* FIXME: What should this really be? */
		*size = min_pitch * *height;
		break;
	default:
		*size = min_pitch * *height;
		break;
	}

	*pitch = min_pitch;

	/* Page align size */
	align = (*size + 4095) & ~4095;

	/*
	 * Flags provide information on the type of surface being requested
	 *   0x04 = cursor surface
	 *   0x08 = overlay surface
	 *   0x10 = display surface
	 *   0x40 = video surface
	 */
	do {
		ret = gmm_alloc_chunk_space(&gmm_context, offset, *size, phys, flags);
	} while ((ret == -IGD_ERROR_NOMEM) && gmm_flush_cache());

	EMGD_DEBUG("EXIT  Returning %d", ret);
	return ret;
}



/*
 * Maintain a very simple linear linked list of memory allocations. Try
 * to re-use freed blocks.  No error checking is done and alignment is
 * hard codeded.
 */

static int gmm_alloc_chunk_space(gmm_context_t *gmm_context,
		unsigned long *offset,
		unsigned long size,
		unsigned long phys,
		unsigned long flags)
{
	gmm_chunk_t *chunk;
	struct drm_device *dev;

	EMGD_TRACE_ENTER;
	EMGD_DEBUG("Parameters: size=%lu; phys=%lu", size, phys);
	EMGD_DEBUG("  flags=0x%08lx", flags);

	/* Check for a free chunk of sufficent size */
	chunk = gmm_context->head_chunk;
	while (chunk) {
		if ((chunk->used == 0) && (chunk->size >= size) &&
			(chunk->type == (phys ? AGP_PHYS_MEMORY : AGP_NORMAL_MEMORY))) {
			chunk->used = 1;
			*offset = chunk->offset;
			EMGD_DEBUG("Re-using old chunk with offset=0x%lx", chunk->offset);
			EMGD_DEBUG("EXIT  Returning %d", 0);
			return 0;
		}
		chunk = chunk->next;
	}

	/* Allocate a new chunk */
	chunk = (gmm_chunk_t *)OS_ALLOC(sizeof(gmm_chunk_t));
	if (!chunk) {
		printk(KERN_ALERT "[EMGD] Cannot allocate gmm_chunk_t");
		EMGD_ERROR_EXIT("Returning %d", -IGD_ERROR_NOMEM);
		return -IGD_ERROR_NOMEM;
	}
	OS_MEMSET(chunk, 0, sizeof(gmm_chunk_t));

	/*
	 * First allocate the memory from the gart driver. If this failes,
	 * don't bother allocating a new chunk.
	 */
	dev = (struct drm_device *)gmm_context->context->drm_dev;
	chunk->size = size;
	chunk->pages = (size + PAGE_SIZE - 1) / PAGE_SIZE;
	/*
	 * If we need phyical contiguous memory, then we need to
	 * set the type to AGP_PHYS_MEMORY, otherwise use AGP_NORMAL_MEMORY
	 */
	if (phys) {
		chunk->type = AGP_PHYS_MEMORY;
		EMGD_DEBUG("Allocate AGP_PHYS; size = 0x%08lx", chunk->size);
	} else {
		chunk->type = AGP_NORMAL_MEMORY;
		EMGD_DEBUG("Allocate AGP_NORMAL; size = 0x%08lx", chunk->size);
	}

	if (dev == NULL) {
		OS_FREE(chunk);
		EMGD_ERROR_EXIT("drm device is NULL; Returning %d", -IGD_ERROR_NOMEM);
		return -IGD_ERROR_NOMEM;
	}


	/* Allocate memory from the AGPGART */
	chunk->gtt_mem = emgd_alloc_pages(chunk->pages, chunk->type);
	if (!chunk->gtt_mem) {
		OS_FREE(chunk);
		printk(KERN_ALERT "[EMGD] Failed to allocated AGP memory.\n");
		EMGD_DEBUG("gmm_alloc_chunk_space() returning %d", -IGD_ERROR_NOMEM);
		return -IGD_ERROR_NOMEM;
	}


	chunk->used = 1;
	chunk->ref_cnt = 0;
	chunk->page_addresses = NULL;

	/*
	 * Get the next available offset that works for this allocation.
	 * Currently this just uses the next linear offset available. No
	 * attempt is made to keep track of or utilize gaps introduced
	 * because of alignments.
	 *
	 * Eventually, this should mainting different "heaps" of offsets
	 * for different types of allocations.  For example, display vs.
	 * video.
	 *
	 * See igd_gmm.h for the different surface types supported. Below
	 * are the ones of interest
	 *
	 * #define IGD_SURFACE_RENDER           0x00000001
	 * #define IGD_SURFACE_CURSOR           0x00000004
	 * #define IGD_SURFACE_OVERLAY          0x00000008
	 * #define IGD_SURFACE_DISPLAY          0x00000010
	 * #define IGD_SURFACE_VIDEO            0x00000040
	 * #define IGD_SURFACE_VIDEO_ENCODE     0x00000080
	 * #define IGD_SURFACE_SYS_MEM          0x00008000
	 * #define IGD_SURFACE_PHYS_PTR         0x00010000
	 *
	 */
	if (gmm_context->tail_chunk == NULL) {
		chunk->offset = 0;
	} else {
		chunk->offset = gmm_context->tail_chunk->offset +
			gmm_context->tail_chunk->size;
	}
	EMGD_DEBUG("- Before alignment: offset=0x%lx", chunk->offset);

	/*
	 * Alignment varies depending on the type of surface being allocated.
	 */
	if (flags & IGD_SURFACE_DISPLAY) {
		/* 256KB aligned */
		chunk->offset = (chunk->offset + 0x3ffff) & ~0x3ffff;
	} else {
		/* 4KB aligned */
		chunk->offset = (chunk->offset + 0x0fff) & ~0x0fff;
	}

	EMGD_DEBUG("-  After alignment: offset=0x%lx", chunk->offset);
	chunk->next = NULL;

	if (gmm_context->head_chunk == NULL) {
		gmm_context->head_chunk = chunk;
	} else {
		gmm_context->tail_chunk->next = chunk;
	}
	gmm_context->tail_chunk = chunk;

	/* Bind the gart memory to the offset */
	/*
	 * This updates the GTT table with the actual allocated pages
	 * so the display hardware can access the memory.
	 *
	 * TODO: Add ability to use other MMU's depending on the
	 * type of memory requested.
	 */
	emgd_gtt_insert(gmm_context->context, chunk->gtt_mem, chunk->offset);
	chunk->bound = 1;

	/*
	 * Physical is only meaningfull for single page or contiguous pages.
	 * It represents the physical address of the first allocated page.
	 */
	if (chunk->gtt_mem->physical == 0x0) {
		chunk->gtt_mem->physical = page_to_phys(chunk->gtt_mem->pages[0]);
	}

	*offset = chunk->offset;

	EMGD_DEBUG("Allocated chunk @ 0x%lx (0x%lx)", chunk->offset,
		(unsigned long)chunk->gtt_mem->physical);
	EMGD_TRACE_EXIT;
	return 0;
}


static int gmm_get_page_list(unsigned long offset,
		unsigned long **pages,
		unsigned long *page_cnt)
{
	gmm_chunk_t *chunk;
	int i;

	EMGD_TRACE_ENTER;
	EMGD_DEBUG("Parameters: offset=0x%08lx", offset);
	EMGD_DEBUG("  pages=0x%p, *pages=0x%p", pages, *pages);
	chunk = gmm_get_chunk(gmm_context.context, offset);

	if (chunk == NULL) {
		printk(KERN_ERR"[EMGD] gmm_get_page_list: Failed to find chunk: "
			"0x%lx\n", offset);
		return -IGD_ERROR_NOMEM;
	}

	*page_cnt = chunk->gtt_mem->page_count;

	/* Allocate an array of page addresses: */
	if (chunk->page_addresses == NULL) {
		chunk->page_addresses = OS_ALLOC(sizeof(unsigned long) * *page_cnt);
		EMGD_DEBUG("Allocated chunk->page_addresses = 0x%p",
			chunk->page_addresses);
		if (chunk->page_addresses == NULL) {
			printk(KERN_ERR "[EMGD] gmm_get_page_list: failed to allocate the "
				"array of page addresses for chunk: 0x%lx\n", offset);
			return -IGD_ERROR_NOMEM;
		}
	} else {
		EMGD_DEBUG("Re-using chunk->page_addresses = 0x%p",
			chunk->page_addresses);
	}

	/* Populate the array with the starting addresses of the pages: */
	for (i = 0; i < *page_cnt; i++) {
		chunk->page_addresses[i] = page_to_phys(chunk->gtt_mem->pages[i]);
	}

	*pages = chunk->page_addresses;

	EMGD_DEBUG("*pages=0x%p", *pages);
	EMGD_DEBUG("page_count=%lu", *page_cnt);
	EMGD_TRACE_EXIT;
	return 0;
}
