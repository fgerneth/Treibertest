/* -*- pse-c -*-
 *-----------------------------------------------------------------------------
 * Filename: memmap.c
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
 *  This file contains the XFree86 implementations of the OAL
 *  memory.h abstractions.
 *-----------------------------------------------------------------------------
 */
#include <io.h>

#ifndef _OAL_LINUX_KERNEL_IO_MEMMAP_H
#define _OAL_LINUX_KERNEL_IO_MEMMAP_H


void * os_map_io_to_mem_nocache(
				unsigned long base_address,
				unsigned long size
				)
{
  return ioremap(base_address, size);
}

void os_unmap_io_from_mem(
			  void * virt_addr,
			  unsigned long size
			  )
{
  iounmap(virt_addr);
}


#endif
