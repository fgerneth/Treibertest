/* -*- pse-c -*-
 *-----------------------------------------------------------------------------
 * Filename: ovl_dispatch.h
 * $Revision: 1.4 $
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
 *
 *-----------------------------------------------------------------------------
 */

#ifndef _OVERLAY_DISPATCH_H
#define _OVERLAY_DISPATCH_H

typedef struct _ovl_dispatch {
	int (*blend_surf_needed)(igd_display_context_t *display,
		igd_surface_t       *src_surf,
		igd_rect_t          *src_rect,
		igd_rect_t          *dest_rect,
		unsigned int         flags,
		igd_surface_t       *blend_surf,
		igd_rect_t          *blend_rect);
	int (*alter_ovl)(igd_display_context_t *display,
		igd_surface_t       *src_surf,
		igd_rect_t          *src_rect,
		igd_rect_t          *dest_rect,
		igd_ovl_info_t      *ovl_info,
		unsigned int         flags);
	int (*query_ovl)(igd_display_h display_h,
		unsigned int flags);
	int (*query_max_size_ovl)(igd_display_h display_h,
		unsigned long pf,
		unsigned int *max_width,
		unsigned int *max_height);
} ovl_dispatch_t;

#endif
