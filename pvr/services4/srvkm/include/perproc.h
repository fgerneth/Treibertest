/**********************************************************************
 Copyright (c) Imagination Technologies Ltd.

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ******************************************************************************/

#ifndef __PERPROC_H__
#define __PERPROC_H__

#if defined (__cplusplus)
extern "C" {
#endif

#include "img_types.h"
#include "resman.h"

#include "handle.h"

typedef struct _PVRSRV_PER_PROCESS_DATA_
{
	IMG_UINT32		ui32PID;
	IMG_HANDLE		hBlockAlloc;
	PRESMAN_CONTEXT 	hResManContext;
	IMG_HANDLE		hPerProcData;
	PVRSRV_HANDLE_BASE 	*psHandleBase;
#if defined (PVR_SECURE_HANDLES)

	IMG_BOOL		bHandlesBatched;
#endif
	IMG_UINT32		ui32RefCount;


	IMG_BOOL		bInitProcess;


	IMG_HANDLE		hOsPrivateData;
} PVRSRV_PER_PROCESS_DATA;

PVRSRV_PER_PROCESS_DATA *PVRSRVPerProcessData(IMG_UINT32 ui32PID);

PVRSRV_ERROR PVRSRVPerProcessDataConnect(IMG_UINT32	ui32PID);
IMG_VOID PVRSRVPerProcessDataDisconnect(IMG_UINT32	ui32PID);

PVRSRV_ERROR PVRSRVPerProcessDataInit(IMG_VOID);
PVRSRV_ERROR PVRSRVPerProcessDataDeInit(IMG_VOID);

#ifdef INLINE_IS_PRAGMA
#pragma inline(PVRSRVFindPerProcessData)
#endif
static INLINE
PVRSRV_PER_PROCESS_DATA *PVRSRVFindPerProcessData(IMG_VOID)
{
	return PVRSRVPerProcessData(OSGetCurrentProcessIDKM());
}


#ifdef INLINE_IS_PRAGMA
#pragma inline(PVRSRVProcessPrivateData)
#endif
static INLINE
IMG_HANDLE PVRSRVProcessPrivateData(PVRSRV_PER_PROCESS_DATA *psPerProc)
{
	return (psPerProc != IMG_NULL) ? psPerProc->hOsPrivateData : IMG_NULL;
}


#ifdef INLINE_IS_PRAGMA
#pragma inline(PVRSRVPerProcessPrivateData)
#endif
static INLINE
IMG_HANDLE PVRSRVPerProcessPrivateData(IMG_UINT32 ui32PID)
{
	return PVRSRVProcessPrivateData(PVRSRVPerProcessData(ui32PID));
}

#ifdef INLINE_IS_PRAGMA
#pragma inline(PVRSRVFindPerProcessPrivateData)
#endif
static INLINE
IMG_HANDLE PVRSRVFindPerProcessPrivateData(IMG_VOID)
{
	return PVRSRVProcessPrivateData(PVRSRVFindPerProcessData());
}

#if defined (__cplusplus)
}
#endif

#endif
