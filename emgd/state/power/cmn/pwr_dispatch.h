/* -*- pse-c -*-
 *-----------------------------------------------------------------------------
 * Filename: pwr_dispatch.h
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
 *  This file contains the protocols for the plaform-specific dispatch
 *  functions that the power module uses.
 *-----------------------------------------------------------------------------
 */

#ifndef _PWR_DISPATCH_H
#define _PWR_DISPATCH_H

#include <context.h>

typedef struct _pwr_dispatch {
	/* Queries support for power_state
	 * ret:  0 if power_state is supported, <0 otherwise
	 */
	int (*pwr_query)(unsigned int power_state);
	/* Dispatch function to set device dependent part of set power */
	int (*pwr_set)(igd_context_t *context, unsigned int power_state);
	/* Dispatch function to set init time device dependent power settings */
	int (*pwr_init)(igd_context_t *context);
} pwr_dispatch_t;

extern pwr_dispatch_t pwr_dispatch_plb;

#endif

/*-----------------------------------------------------------------------------
 * $Id: pwr_dispatch.h,v 1.5 2011/02/16 17:04:49 astead Exp $
 * $Source: /nfs/fm/proj/eia/cvsroot/koheo/linux/egd_drm/emgd/state/power/cmn/pwr_dispatch.h,v $
 *-----------------------------------------------------------------------------
 */
