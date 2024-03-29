/* -*- pse-c -*-
 *-----------------------------------------------------------------------------
 * Filename: instr_common.h
 * $Revision: 1.6 $
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
 *  Common tools for hardware that uses instruction engines.
 *-----------------------------------------------------------------------------
 */

#ifndef _IGD_INSTR_COMMON_H
#define _IGD_INSTR_COMMON_H

/* Write instructions macro. */
#ifdef DEBUG_BUILD_TYPE
#define INSTR_WRITE(data, addr)											\
    if(igd_debug->hal.instr) {											\
		EMGD_DEBUG_S("    addr:%p   data:0x%8.8x", ((void *)(addr)),	\
			(unsigned int)(data));										\
    }																	\
	EMGD_WRITE32 (data, (addr));											\
	addr++;

#define IGD_PRINT_INSTR(name)                                    \
    if(igd_debug->hal.instr) {									 \
		EMGD_DEBUG_S("GMCH Instruction: %s", name);				 \
    }
#else
#define INSTR_WRITE(data, addr) EMGD_WRITE32(data, (addr)++);
#define IGD_PRINT_INSTR(name)
#endif

#endif
