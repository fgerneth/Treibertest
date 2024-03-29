/* -*- pse-c -*-
 *-----------------------------------------------------------------------------
 * Filename: dsp_plb.c
 * $Revision: 1.5 $
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


#include <io.h>
#include <memory.h>

#include <igd.h>
#include <igd_mode.h>
#include <igd_pwr.h>

#include <mode.h>
#include <utils.h>

#include <plb/regs.h>
#include <plb/context.h>

#include "../cmn/dsp_dispatch.h"

#ifdef CONFIG_PLB

extern igd_framebuffer_info_t fb_info_cmn[];

/*
 * NOTE: Some of these format lists are shared with GMM. For this reason
 * they cannot be static.
 */
unsigned long fb_pixel_formats_plb[] = {
	IGD_PF_ARGB32,
	IGD_PF_xRGB32,
	IGD_PF_ABGR32,
	IGD_PF_ARGB32_2101010,
	IGD_PF_RGB16_565,
	IGD_PF_ARGB8_INDEXED,
	0
};

unsigned long vga_pixel_formats_plb[] = {
	IGD_PF_ARGB8_INDEXED,
	0
};

#ifndef CONFIG_MICRO
unsigned long sprite_pixel_formats_plb[] = {
	IGD_PF_ARGB32,
	IGD_PF_ABGR32,
	IGD_PF_ARGB32_2101010,
	IGD_PF_RGB16_565,
	IGD_PF_ARGB8_INDEXED,
	IGD_PF_YUV422_PACKED_YUY2,
	IGD_PF_YUV422_PACKED_UYVY,
	0
};

unsigned long render_pixel_formats_plb[] = {
	IGD_PF_ARGB32,
	IGD_PF_xRGB32,
	IGD_PF_ARGB32_2101010,
	IGD_PF_RGB16_565,
	IGD_PF_xRGB16_555,
	IGD_PF_ARGB16_1555,
	IGD_PF_ARGB16_4444,
	IGD_PF_YUV422_PACKED_YUY2,
	IGD_PF_YUV422_PACKED_UYVY,
	IGD_PF_R16F,
	IGD_PF_GR32_1616F,
	IGD_PF_R32F,
	IGD_PF_ABGR64_16161616F,
	IGD_PF_YUV420_PLANAR_NV12,
	IGD_PF_YUV410_PLANAR_YVU9,
	0
};

unsigned long texture_pixel_formats_plb[] = {
	IGD_PF_ARGB32,
	IGD_PF_xRGB32,
	IGD_PF_ABGR32,
	IGD_PF_xBGR32,
	IGD_PF_RGB16_565,
	IGD_PF_xRGB16_555,
	IGD_PF_ARGB16_1555,
	IGD_PF_ARGB16_4444,
	IGD_PF_ARGB8_INDEXED,
	IGD_PF_YUV422_PACKED_YUY2,
	IGD_PF_YUV422_PACKED_UYVY,
	IGD_PF_YUV420_PLANAR_I420,
	IGD_PF_YUV420_PLANAR_IYUV,
	IGD_PF_YUV420_PLANAR_YV12,
	IGD_PF_YUV410_PLANAR_YVU9,
	IGD_PF_YUV420_PLANAR_NV12,
	IGD_PF_DVDU_88,
	IGD_PF_LDVDU_655,
	IGD_PF_xLDVDU_8888,
	IGD_PF_DXT1,
	IGD_PF_DXT2,
	IGD_PF_DXT3,
	IGD_PF_DXT4,
	IGD_PF_DXT5,
	IGD_PF_L8,
	IGD_PF_A8,
	IGD_PF_AL88,
	IGD_PF_AI44,
	IGD_PF_L16,
	IGD_PF_ARGB32_2101010,
	IGD_PF_AWVU32_2101010,
	IGD_PF_QWVU32_8888,
	IGD_PF_GR32_1616,
	IGD_PF_VU32_1616,
	IGD_PF_R16F,
	IGD_PF_GR32_1616F,
	IGD_PF_R32F,
	IGD_PF_ABGR64_16161616F,
	0
};

unsigned long depth_pixel_formats_plb[] = {
	IGD_PF_Z16,
	IGD_PF_Z24,
	IGD_PF_S8Z24,
	0
};


unsigned long cursor_pixel_formats_plb[] = {
	IGD_PF_ARGB32,
	IGD_PF_RGB_2,
	IGD_PF_RGB_XOR_2,
	IGD_PF_RGB_T_2,
	0
};

unsigned long overlay_pixel_formats_plb[] = {
	IGD_PF_YUV422_PACKED_YUY2,
	IGD_PF_YUV422_PACKED_UYVY,
	IGD_PF_YUV420_PLANAR_I420,
	IGD_PF_YUV420_PLANAR_IYUV,
	IGD_PF_YUV420_PLANAR_YV12,
	IGD_PF_YUV420_PLANAR_NV12,
	IGD_PF_YUV410_PLANAR_YVU9,
	0
};

unsigned long video_pixel_formats_plb[] = {
	IGD_PF_YUV420_PLANAR_NV12,
	0
};

unsigned long blt_pixel_formats_plb[] = {
	IGD_PF_ARGB32,
	IGD_PF_xRGB32,
	IGD_PF_ABGR32,
	IGD_PF_xBGR32,
	IGD_PF_RGB16_565,
	IGD_PF_xRGB16_555,
	IGD_PF_ARGB16_1555,
	IGD_PF_ARGB16_4444,
	IGD_PF_ARGB8_INDEXED,
	IGD_PF_YUV422_PACKED_YUY2,
	IGD_PF_YUV422_PACKED_UYVY,
	IGD_PF_YUV420_PLANAR_I420,
	IGD_PF_YUV420_PLANAR_IYUV,
	IGD_PF_YUV420_PLANAR_YV12,
	IGD_PF_YUV420_PLANAR_NV12,
	IGD_PF_YUV410_PLANAR_YVU9,
	IGD_PF_DVDU_88,
	IGD_PF_LDVDU_655,
	IGD_PF_xLDVDU_8888,
	IGD_PF_DXT1,
	IGD_PF_DXT2,
	IGD_PF_DXT3,
	IGD_PF_DXT4,
	IGD_PF_DXT5,
	IGD_PF_Z16,
	IGD_PF_Z24,
	IGD_PF_S8Z24,
	IGD_PF_RGB_2,
	IGD_PF_RGB_XOR_2,
	IGD_PF_RGB_T_2,
	IGD_PF_L8,
	IGD_PF_A8,
	IGD_PF_AL88,
	IGD_PF_AI44,
	IGD_PF_L16,
	IGD_PF_ARGB32_2101010,
	IGD_PF_AWVU32_2101010,
	IGD_PF_QWVU32_8888,
	IGD_PF_GR32_1616,
	IGD_PF_VU32_1616,
	IGD_PF_R16F,
	IGD_PF_GR32_1616F,
	IGD_PF_R32F,
	IGD_PF_ABGR64_16161616F,
	0
};

static igd_fb_caps_t caps_table_plb[] = {
	{IGD_PF_ARGB32, IGD_CAP_FULL_2D | IGD_CAP_BLEND},
	{IGD_PF_xRGB32, IGD_CAP_FULL_2D | IGD_CAP_BLEND},
	{IGD_PF_ABGR32, IGD_CAP_FULL_2D | IGD_CAP_BLEND},
	{IGD_PF_xBGR32, IGD_CAP_FULL_2D | IGD_CAP_BLEND},
	{IGD_PF_ARGB32_2101010, IGD_CAP_FULL_2D | IGD_CAP_BLEND},
	{IGD_PF_RGB16_565, IGD_CAP_FULL_2D | IGD_CAP_BLEND},
	{IGD_PF_ARGB8_INDEXED, IGD_CAP_FULL_2D},
	{0, 0}
};

#endif

/*
 * Plane Definitions for PLB family.
 */
static igd_plane_t planea_plb = {
	DSPACNTR, IGD_PLANE_DISPLAY | IGD_PLANE_DIH, 0, 0,
	fb_pixel_formats_plb, &fb_info_cmn[0], NULL
};

static igd_plane_t planeb_plb = {
	DSPBCNTR, IGD_PLANE_DISPLAY | IGD_PLANE_SPRITE | IGD_PLANE_DIH, 0, 0,
	fb_pixel_formats_plb, &fb_info_cmn[1], NULL
};

static igd_plane_t planec_plb = {
	DSPCCNTR, IGD_PLANE_SPRITE, 0, 0,
	OPT_MICRO_VALUE(sprite_pixel_formats_plb, NULL), NULL, NULL
};

static igd_plane_t plane_vga_plb = {
	VGACNTRL, IGD_PLANE_VGA, 0, 0,
	vga_pixel_formats_plb, NULL, NULL
};

static igd_plane_t plane_overlay_plb = {
	OVADD, IGD_PLANE_OVERLAY, 0, 0,
	OPT_MICRO_VALUE(overlay_pixel_formats_plb, NULL), NULL, NULL
};

static igd_plane_t plane_cursora_plb = {
	CUR_A_CNTR, IGD_PLANE_CURSOR|IGD_CURSOR_USE_PIPEA|IGD_CURSOR_USE_PIPEB, 0,0,
	OPT_MICRO_VALUE(cursor_pixel_formats_plb, NULL), NULL, NULL
};

static igd_plane_t plane_cursorb_plb = {
	CUR_B_CNTR, IGD_PLANE_CURSOR|IGD_CURSOR_USE_PIPEA|IGD_CURSOR_USE_PIPEB, 0,0,
	OPT_MICRO_VALUE(cursor_pixel_formats_plb, NULL), NULL, NULL
};

/*
 * Plane lists for PLB family members.
 */
/* Two Main Plane, One Sprite, One VGA, One Overlay, Two Cursor */
static igd_plane_t *plane_table_plb[] = {
	&planeb_plb,
	&planea_plb,
	&planec_plb,
	&plane_vga_plb,
	&plane_overlay_plb,
	&plane_cursora_plb,
	&plane_cursorb_plb,
	NULL
};

static igd_clock_t clock_a_plb = {
	DPLLACNTR, FPA0, 16
};

static igd_clock_t clock_b_plb = {
	DPLLBCNTR, FPB0, 16
};

/*
 * Pipe definitions for PLB family.
 */
static igd_display_pipe_t pipea_plb = {
	0, PIPEA_CONF, PIPEA_TIMINGS, DPALETTE_A, &clock_a_plb,
	(IGD_PIPE_IS_PIPEA | IGD_PORT_SHARE_DIGITAL),
	0, 0,{NULL, NULL, NULL}, NULL, NULL, NULL,
	NULL, NULL
};

static igd_display_pipe_t pipeb_plb = {
	1, PIPEB_CONF, PIPEB_TIMINGS, DPALETTE_B, &clock_b_plb,
	(IGD_PIPE_IS_PIPEB | IGD_PORT_SHARE_LVDS),
	0, 0,{NULL, NULL, NULL}, NULL, NULL, NULL,
	NULL, NULL
};

static igd_display_pipe_t *pipe_table_plb[] = {
	&pipea_plb,
	&pipeb_plb,
	NULL
};

/*
 * Port definitions for PLB family.
 */

/*
 * Port number: Port number is 1-number of available ports on any hardware.
 * Here are the definitions:
 *
 * On PLB:
 * =======
 * Port mappings:
 *   1 - None
 *   2 - DVO B port
 *   3 - None
 *   4 - Internal LVDS port
 *   5 - None
 *
 * Note: Port number should match with port numbers in port parameters.
 *       See igd_init.h for more information.
 */

#endif
/*
 * These are the port attributes that the PLB core support.
 * Note that currently it only contains color correction attributes.
 * Eventually, this will include all the attributes.
 */
igd_attr_t port_attrib_plb[IGD_MAX_PORTS][5] = {
	{ /* Config for port 1:  Integrated TV Encoder (Alviso only) */
		PD_MAKE_ATTR(
			PD_ATTR_ID_FB_GAMMA,
			PD_ATTR_TYPE_RANGE,
			"Frame Buffer Gamma",
			PD_ATTR_FLAG_PD_INVISIBLE,
			0x202020,  /* default */
			0x202020,  /* current */
			0x131313,  /* Min:  ~0.6 in 3i.5f format for R-G-B*/
			0xC0C0C0,  /* Max:  6 in 3i.5f format for R-G-B   */
			1),
		PD_MAKE_ATTR(
			PD_ATTR_ID_FB_BRIGHTNESS,
			PD_ATTR_TYPE_RANGE,
			"Frame Buffer Brightness",
			PD_ATTR_FLAG_PD_INVISIBLE,
			0x808080,
			0x808080,
			0x000000,    /* Min: */
			0xFFFFFF,    /* Max: */
			1),
		PD_MAKE_ATTR(
			PD_ATTR_ID_FB_CONTRAST,
			PD_ATTR_TYPE_RANGE,
			"Frame Buffer Contrast",
			PD_ATTR_FLAG_PD_INVISIBLE,
			0x808080,
			0x808080,
			0x000000,    /* Min: */
			0xFFFFFF,    /* Max: */
			1),
		PD_MAKE_ATTR(
			PD_ATTR_ID_EXTENSION,
			0,
			"",
			PD_ATTR_FLAG_PD_INVISIBLE|PD_ATTR_FLAG_USER_INVISIBLE,
			0,
			0,
			0,
			0,
			0),
		PD_MAKE_ATTR(
			PD_ATTR_LIST_END,
			0,
			"",
			0,
			0,
			0,
			0,
			0,
			0)
	},
	{ /* Config for port 2:  DVO B */
		PD_MAKE_ATTR(
			PD_ATTR_ID_FB_GAMMA,
			PD_ATTR_TYPE_RANGE,
			"Frame Buffer Gamma",
			PD_ATTR_FLAG_PD_INVISIBLE,
			0x202020,  /* default */
			0x202020,  /* current */
			0x131313,  /* Min:  ~0.6 in 3i.5f format for R-G-B*/
			0xC0C0C0,  /* Max:  6 in 3i.5f format for R-G-B   */
			1),
		PD_MAKE_ATTR(
			PD_ATTR_ID_FB_BRIGHTNESS,
			PD_ATTR_TYPE_RANGE,
			"Frame Buffer Brightness",
			PD_ATTR_FLAG_PD_INVISIBLE,
			0x808080,
			0x808080,
			0x000000,    /* Min: */
			0xFFFFFF,    /* Max: */
			1),
		PD_MAKE_ATTR(
			PD_ATTR_ID_FB_CONTRAST,
			PD_ATTR_TYPE_RANGE,
			"Frame Buffer Contrast",
			PD_ATTR_FLAG_PD_INVISIBLE,
			0x808080,
			0x808080,
			0x000000,    /* Min: */
			0xFFFFFF,    /* Max: */
			1),
		PD_MAKE_ATTR(
			PD_ATTR_ID_EXTENSION,
			0,
			"",
			PD_ATTR_FLAG_PD_INVISIBLE|PD_ATTR_FLAG_USER_INVISIBLE,
			0,
			0,
			0,
			0,
			0),
		PD_MAKE_ATTR(
			PD_ATTR_LIST_END,
			0,
			"",
			0,
			0,
			0,
			0,
			0,
			0)
	},
	{ /* Config for port 3:  DVO C */
		PD_MAKE_ATTR(
			PD_ATTR_ID_FB_GAMMA,
			PD_ATTR_TYPE_RANGE,
			"Frame Buffer Gamma",
			PD_ATTR_FLAG_PD_INVISIBLE,
			0x202020,  /* default */
			0x202020,  /* current */
			0x131313,  /* Min:  ~0.6 in 3i.5f format for R-G-B*/
			0xC0C0C0,  /* Max:  6 in 3i.5f format for R-G-B   */
			1),
		PD_MAKE_ATTR(
			PD_ATTR_ID_FB_BRIGHTNESS,
			PD_ATTR_TYPE_RANGE,
			"Frame Buffer Brightness",
			PD_ATTR_FLAG_PD_INVISIBLE,
			0x808080,
			0x808080,
			0x000000,    /* Min: */
			0xFFFFFF,    /* Max: */
			1),
		PD_MAKE_ATTR(
			PD_ATTR_ID_FB_CONTRAST,
			PD_ATTR_TYPE_RANGE,
			"Frame Buffer Contrast",
			PD_ATTR_FLAG_PD_INVISIBLE,
			0x808080,
			0x808080,
			0x000000,    /* Min: */
			0xFFFFFF,    /* Max: */
			1),
		PD_MAKE_ATTR(
			PD_ATTR_ID_EXTENSION,
			0,
			"",
			PD_ATTR_FLAG_PD_INVISIBLE|PD_ATTR_FLAG_USER_INVISIBLE,
			0,
			0,
			0,
			0,
			0),
		PD_MAKE_ATTR(
			PD_ATTR_LIST_END,
			0,
			"",
			0,
			0,
			0,
			0,
			0,
			0)
	},
	{ /* Config for port 4:  LVDS */
		PD_MAKE_ATTR(
			PD_ATTR_ID_FB_GAMMA,
			PD_ATTR_TYPE_RANGE,
			"Frame Buffer Gamma",
			PD_ATTR_FLAG_PD_INVISIBLE,
			0x202020,  /* default */
			0x202020,  /* current */
			0x131313,  /* Min:  ~0.6 in 3i.5f format for R-G-B*/
			0xC0C0C0,  /* Max:  6 in 3i.5f format for R-G-B   */
			1),
		PD_MAKE_ATTR(
			PD_ATTR_ID_FB_BRIGHTNESS,
			PD_ATTR_TYPE_RANGE,
			"Frame Buffer Brightness",
			PD_ATTR_FLAG_PD_INVISIBLE,
			0x808080,
			0x808080,
			0x000000,    /* Min: */
			0xFFFFFF,    /* Max: */
			1),
		PD_MAKE_ATTR(
			PD_ATTR_ID_FB_CONTRAST,
			PD_ATTR_TYPE_RANGE,
			"Frame Buffer Contrast",
			PD_ATTR_FLAG_PD_INVISIBLE,
			0x808080,
			0x808080,
			0x000000,    /* Min: */
			0xFFFFFF,    /* Max: */
			1),
		PD_MAKE_ATTR(
			PD_ATTR_ID_EXTENSION,
			0,
			"",
			PD_ATTR_FLAG_PD_INVISIBLE|PD_ATTR_FLAG_USER_INVISIBLE,
			0,
			0,
			0,
			0,
			0),
		PD_MAKE_ATTR(
			PD_ATTR_LIST_END,
			0,
			"",
			0,
			0,
			0,
			0,
			0,
			0)
	},
	{ /* Config for port 5:  ANALOG */
		PD_MAKE_ATTR(
			PD_ATTR_ID_FB_GAMMA,
			PD_ATTR_TYPE_RANGE,
			"Frame Buffer Gamma",
			PD_ATTR_FLAG_PD_INVISIBLE,
			0x202020,  /* default */
			0x202020,  /* current */
			0x131313,  /* Min:  ~0.6 in 3i.5f format for R-G-B*/
			0xC0C0C0,  /* Max:  6 in 3i.5f format for R-G-B   */
			1),
		PD_MAKE_ATTR(
			PD_ATTR_ID_FB_BRIGHTNESS,
			PD_ATTR_TYPE_RANGE,
			"Frame Buffer Brightness",
			PD_ATTR_FLAG_PD_INVISIBLE,
			0x808080,
			0x808080,
			0x000000,    /* Min: */
			0xFFFFFF,    /* Max: */
			1),
		PD_MAKE_ATTR(
			PD_ATTR_ID_FB_CONTRAST,
			PD_ATTR_TYPE_RANGE,
			"Frame Buffer Contrast",
			PD_ATTR_FLAG_PD_INVISIBLE,
			0x808080,
			0x808080,
			0x000000,    /* Min: */
			0xFFFFFF,    /* Max: */
			1),
		PD_MAKE_ATTR(
			PD_ATTR_ID_EXTENSION,
			0,
			"",
			PD_ATTR_FLAG_PD_INVISIBLE|PD_ATTR_FLAG_USER_INVISIBLE,
			0,
			0,
			0,
			0,
			0),
		PD_MAKE_ATTR(
			PD_ATTR_LIST_END,
			0,
			"",
			0,
			0,
			0,
			0,
			0,
			0)
	}
};

#ifdef CONFIG_PLB

igd_display_port_t dvob_port_plb = {
	IGD_PORT_DIGITAL, 2, "SDVO B", 0x61140, GMBUS_DVO_REG, 0,
	GMBUS_DVOB_DDC, 0xA0,
	(IGD_PORT_USE_PIPEA | IGD_VGA_COMPRESS | IGD_RGBA_COLOR |
	 IGD_PORT_GANG),
	TVCLKINBC, 0, IGD_POWERSTATE_D0, IGD_POWERSTATE_D0,
	NULL, NULL,
	NULL, NULL, NULL, 0, NULL, 0,
	DDC_DEFAULT_SPEED, NULL, NULL, NULL, NULL, 0, NULL, 0, 0,
	IGD_POWERSTATE_UNDEFINED,
	port_attrib_plb[2 - 1], /* Port Number - 1 */
	0, { NULL },
	(BIT14 | BIT16 | BIT17),
	(BIT17), 1,

};

static igd_display_port_t lvds_port_plb = {
	IGD_PORT_LVDS, 4, "IntLVDS", 0x61180, 0, 0,
	GMBUS_INT_LVDS_DDC, 0xA0,
	(IGD_PORT_USE_PIPEB | IGD_VGA_COMPRESS),
	DREFCLK, 0, IGD_POWERSTATE_D0, IGD_POWERSTATE_D0, NULL, NULL,
	NULL, NULL, NULL, 0, NULL, 0,
	DDC_DEFAULT_SPEED, NULL, NULL, NULL, NULL, 0, NULL, 0, 0,
	IGD_POWERSTATE_UNDEFINED,
	port_attrib_plb[4 - 1], /* Port Number - 1 */
	0, { NULL }, 0, 0, 0,
};

static igd_display_port_t *port_table_plb[] = {
	&lvds_port_plb,
	&dvob_port_plb,
	NULL
};

static int dsp_init_plb(igd_context_t *context)
{
	return 0;
}


dsp_dispatch_t dsp_dispatch_plb = {
	plane_table_plb, pipe_table_plb, port_table_plb,
	OPT_MICRO_VALUE(caps_table_plb, NULL),
	OPT_MICRO_VALUE(overlay_pixel_formats_plb, NULL),
	OPT_MICRO_VALUE(render_pixel_formats_plb, NULL),
	OPT_MICRO_VALUE(texture_pixel_formats_plb, NULL),
	dsp_init_plb
};

#endif
