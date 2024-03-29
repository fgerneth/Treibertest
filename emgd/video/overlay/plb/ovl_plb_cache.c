/* -*- pse-c -*-
 *-----------------------------------------------------------------------------
 * Filename: ovl_plb_cache.c
 * $Revision: 1.3 $
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
 *  Support functions for overlay caching.
 *-----------------------------------------------------------------------------
 */
#define MODULE_NAME hal.overlay

#include "ovl_plb_cache.h"

/*
 * Caching helper functions.  Implemented in ovl_plb.c, but used by
 * the ovl2 and micro_ovl modules as well.
 */

/* Tells if a rectangle has changed */
int is_changed_rect(
		    igd_rect_t *old_rect,
		    igd_rect_t *new_rect)
{
	return ((old_rect->x1 != new_rect->x1) ||
		(old_rect->x2 != new_rect->x2) ||
		(old_rect->y1 != new_rect->y1) ||
		(old_rect->y2 != new_rect->y2) );
}

/* Tells if a surface has changed */
int is_changed_surf(
			 igd_surface_t *old_surf,
			 igd_surface_t *new_surf)
{
	return( (old_surf->pitch        !=  new_surf-> pitch)        ||
		(old_surf->width        !=  new_surf-> width)        ||
		(old_surf->height       !=  new_surf-> height)       ||
		(old_surf->pixel_format !=  new_surf-> pixel_format) ||
		(old_surf->u_pitch      !=  new_surf-> u_pitch)      ||
		(old_surf->v_pitch      !=  new_surf-> v_pitch)      ||
		(old_surf->palette_info !=  new_surf-> palette_info) ||
		(old_surf->flags        !=  new_surf-> flags)        ||
		(old_surf->logic_ops    !=  new_surf-> logic_ops)    ||
		(old_surf->render_ops   !=  new_surf-> render_ops)   ||
		(old_surf->alpha        !=  new_surf-> alpha)        ||
		(old_surf->diffuse      !=  new_surf-> diffuse)      ||
		(old_surf->chroma_high  !=  new_surf-> chroma_high)  ||
		(old_surf->chroma_low   !=  new_surf-> chroma_low)   );

}

/* Tells if the color key has changed */
 int is_changed_color_key(
			 igd_ovl_info_t *old_info,
			 igd_ovl_info_t *new_info)
{
	return ( (old_info->color_key.src_lo != new_info->color_key.src_lo)  ||
		 (old_info->color_key.src_hi != new_info->color_key.src_hi)  ||
		 (old_info->color_key.dest   != new_info->color_key.dest)    ||
		 (old_info->color_key.flags  != new_info->color_key.flags)   );

}

/* Tells if the video quality has changed */
int is_changed_vq(
			 igd_ovl_info_t *old_info,
			 igd_ovl_info_t *new_info)
{
	return ( (old_info->video_quality.contrast   !=
		  new_info->video_quality.contrast)        ||
		 (old_info->video_quality.brightness !=
		  new_info->video_quality.brightness)      ||
		 (old_info->video_quality.saturation !=
		  new_info->video_quality.saturation)       );

}

/* Tells if the gamma has changed */
int is_changed_gamma(
			 igd_ovl_info_t *old_info,
			 igd_ovl_info_t *new_info)
{
	return ((old_info->gamma.red   != new_info->gamma.red)   ||
		(old_info->gamma.green != new_info->gamma.green) ||
		(old_info->gamma.blue  != new_info->gamma.blue)  ||
		(old_info->gamma.flags != new_info->gamma.flags) );

}

/* Copies a source rectangle to the cache */
void copy_src_rect_plb(igd_rect_t *src_rect, povl_plb_cache_t ovl_cache)
{
	if (src_rect) {
		OS_MEMCPY(&ovl_cache->src_rect,
			  src_rect,
			  sizeof(igd_rect_t));
	} else {
		OS_MEMSET(&ovl_cache->src_rect,
			  0,
			  sizeof(igd_rect_t));
	}
}


/* Copies a dest rectangle to the cache */
void copy_dest_rect_plb( igd_rect_t *dest_rect, povl_plb_cache_t ovl_cache)
{
	if (dest_rect) {
		OS_MEMCPY(&ovl_cache->dest_rect,
			  dest_rect,
			  sizeof(igd_rect_t));
	} else {
		OS_MEMSET(&ovl_cache->dest_rect,
			  0,
			  sizeof(igd_rect_t));
	}
}


/* Copies a surface to the cache */
void copy_surf_plb(igd_surface_t *src_surf, povl_plb_cache_t ovl_cache)
{
	if (src_surf) {
		OS_MEMCPY(&ovl_cache->src_surf,
			  src_surf,
			  sizeof(igd_surface_t));
	} else {
		OS_MEMSET(&ovl_cache->src_surf,
			  0,
			  sizeof(igd_surface_t));
	}
}


/* Copies the color key to the cache */
void copy_color_key_plb( igd_ovl_info_t *ovl_info, povl_plb_cache_t ovl_cache)
{
	if (ovl_info) {
		OS_MEMCPY(&ovl_cache->ovl_info.color_key,
			  &(ovl_info->color_key),
			  sizeof(igd_ovl_color_key_info_t));
	} else {
		OS_MEMSET(&ovl_cache->ovl_info.color_key,
			  0,
			  sizeof(igd_ovl_color_key_info_t));
	}
}


/* Copies the video quality info to the cache */
void copy_vq_plb(igd_ovl_info_t *ovl_info, povl_plb_cache_t ovl_cache)
{
	if (ovl_info) {
		OS_MEMCPY(&ovl_cache->ovl_info.video_quality,
			  &(ovl_info->video_quality),
			  sizeof(igd_ovl_video_quality_info_t));
	} else {
		OS_MEMSET(&ovl_cache->ovl_info.video_quality,
			  0,
			  sizeof(igd_ovl_video_quality_info_t));
	}
}


/* Copies the gamma to the cache */
void copy_gamma_plb(igd_ovl_info_t *ovl_info, povl_plb_cache_t ovl_cache)
{
	if (ovl_info) {
		OS_MEMCPY(&ovl_cache->ovl_info.gamma,
			  &(ovl_info->gamma),
			  sizeof(igd_ovl_gamma_info_t));
	} else {
		OS_MEMSET(&ovl_cache->ovl_info.gamma,
			  0,
			  sizeof(igd_ovl_gamma_info_t));
	}
}



/* Checks to see what, if anything has changed.
 * Clears bits in the command and config register that are invalid.
 * Returns a set of flags telling what changed */
unsigned int get_cache_changes_plb(
			       igd_surface_t  *src_surf,
			       igd_rect_t     *src_rect,
			       igd_rect_t     *dest_rect,
			       igd_ovl_info_t *ovl_info,
			       unsigned int    flags,
			       povl_plb_cache_t ovl_cache)
{
	unsigned int cache_changed = 0;

	ovl_cache->ovl2_regs.control = 0;

	/* Have the flags changed? */
	if (ovl_cache->flags != flags) {

		/* NOTE that we did not check which flags changed.
		   Currently if any flag changes, we invalidate all
		   the flags. We could further optimize caching if
		   we tested for individual flag changes, but I don't
		   think it will really help much.  Once a movie starts
		   playing, it pretty much uses the same flags
		   for its entire duration, unless the user is mucking
		   about with it as it plays, in which case it's going
		   to be slow anyway. */

		ovl_cache->flags = flags;
		cache_changed |= IGD_OVL_PLB_UPDATE_FLAGS;

		/* Invalidating the flags cache will cause the following
		 * bits to be re-calculated.  Clear them in preparation for
		 * re-calculation. */
		ovl_cache->ovl_regs.command &= ~ (OVL_CMD_FRAME_MODE      |
						 OVL_CMD_FIELD_MODE      |
						 OVL_CMD_FIELD_SYNC_FLIP |
						 OVL_CMD_ACT_FLD1        |
						 OVL_CMD_ACT_FLD0        );
	}

	/* Do a comparison to source surface */
	if (is_changed_surf(&ovl_cache->src_surf, src_surf)) {
		cache_changed |= IGD_OVL_PLB_UPDATE_SURF;
		copy_surf_plb(src_surf, ovl_cache);

		/* invalidating the source surface will cause the driver
		 * to recalculate the following bits in command */
		ovl_cache->ovl_regs.command &= ~( OVL_CMD_YUV_422  |
						 OVL_CMD_YUV_420P |
						 OVL_CMD_YUV_410P |
						 OVL_CMD_YUV_NV12 |
						 OVL_CMD_Y_SWAP   |
						 OVL_CMD_UV_SWAP  |
						 OVL_CMD_RGB_8888 |
						 OVL_CMD_RGB_565  |
						 OVL_CMD_RGB_555  );

		/* Invalidating the source surface will cause the driver
		 * to recalculate the following bits in config */
		ovl_cache->ovl_regs.config &= ~ ( (1<<4)                    |
					    OVL_CONFIG_LINE_BUFF_MASK );

	}

	/* Do a comparison to source rectangle */
	if (is_changed_rect(&ovl_cache->src_rect, src_rect)) {
		cache_changed |= IGD_OVL_PLB_UPDATE_SRC;
		copy_src_rect_plb(src_rect, ovl_cache);

		/* invalidating the source rectangle will cause the driver
		 * to recalculate the following bits in command */
		ovl_cache->ovl_regs.command &= ~( OVL_CMD_YUV_422  |
						 OVL_CMD_YUV_420P |
						 OVL_CMD_YUV_410P |
						 OVL_CMD_YUV_NV12 |
						 OVL_CMD_Y_SWAP   |
						 OVL_CMD_UV_SWAP  |
						 OVL_CMD_RGB_8888 |
						 OVL_CMD_RGB_565  |
						 OVL_CMD_RGB_555  );

		/* Invalidating the source rectangle will cause the driver
		 * to recalculate the following bits in config */
		ovl_cache->ovl_regs.config &= ~ ( (1<<4)                    |
					    OVL_CONFIG_LINE_BUFF_MASK );


	}

	/* Has our destination rectangle changed? */
	if (is_changed_rect(&ovl_cache->dest_rect, dest_rect)) {
		cache_changed |= IGD_OVL_PLB_UPDATE_DEST;
		copy_dest_rect_plb(dest_rect, ovl_cache);
	}

	/* Do a comparison to overlay info color key */
	if (is_changed_color_key(&ovl_cache->ovl_info, ovl_info)) {
		cache_changed |= (IGD_OVL_PLB_UPDATE_INFO |
				  IGD_OVL_PLB_UPDATE_COLORKEY);
		copy_color_key_plb(ovl_info, ovl_cache);
	}

	/* Do a comparison to overlay info video quality */
	if (is_changed_vq(&ovl_cache->ovl_info, ovl_info)) {
		cache_changed |= ( IGD_OVL_PLB_UPDATE_INFO |
				   IGD_OVL_PLB_UPDATE_VQ);
		copy_vq_plb(ovl_info, ovl_cache);
	}

	/* Do a comparison to overlay info gamma */
	if (is_changed_gamma(&ovl_cache->ovl_info, ovl_info)) {
		cache_changed |= ( IGD_OVL_PLB_UPDATE_INFO |
				   IGD_OVL_PLB_UPDATE_GAMMA);
		copy_gamma_plb(ovl_info, ovl_cache);
	}

	return cache_changed;
}
