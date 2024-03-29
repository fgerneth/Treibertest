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

#ifndef __RESMAN_H__
#define __RESMAN_H__

#if defined (__cplusplus)
extern "C" {
#endif

enum {

	RESMAN_TYPE_SHARED_PB_DESC = 1,
	RESMAN_TYPE_SHARED_PB_DESC_CREATE_LOCK,
	RESMAN_TYPE_HW_RENDER_CONTEXT,
	RESMAN_TYPE_HW_TRANSFER_CONTEXT,
	RESMAN_TYPE_HW_2D_CONTEXT,
	RESMAN_TYPE_TRANSFER_CONTEXT,





	RESMAN_TYPE_DISPLAYCLASS_SWAPCHAIN_REF,
	RESMAN_TYPE_DISPLAYCLASS_DEVICE,


	RESMAN_TYPE_BUFFERCLASS_DEVICE,


	RESMAN_TYPE_OS_USERMODE_MAPPING,


	RESMAN_TYPE_DEVICEMEM_CONTEXT,
	RESMAN_TYPE_DEVICECLASSMEM_MAPPING,
	RESMAN_TYPE_DEVICEMEM_MAPPING,
	RESMAN_TYPE_DEVICEMEM_WRAP,
	RESMAN_TYPE_DEVICEMEM_ALLOCATION,
	RESMAN_TYPE_EVENT_OBJECT,
    RESMAN_TYPE_SHARED_MEM_INFO,
    RESMAN_TYPE_MODIFY_SYNC_OPS,


	RESMAN_TYPE_KERNEL_DEVICEMEM_ALLOCATION
};

#define RESMAN_CRITERIA_ALL				0x00000000
#define RESMAN_CRITERIA_RESTYPE			0x00000001
#define RESMAN_CRITERIA_PVOID_PARAM		0x00000002
#define RESMAN_CRITERIA_UI32_PARAM		0x00000004

typedef PVRSRV_ERROR (*RESMAN_FREE_FN)(IMG_PVOID pvParam, IMG_UINT32 ui32Param);

typedef struct _RESMAN_ITEM_ *PRESMAN_ITEM;
typedef struct _RESMAN_CONTEXT_ *PRESMAN_CONTEXT;

PVRSRV_ERROR ResManInit(IMG_VOID);
IMG_VOID ResManDeInit(IMG_VOID);

PRESMAN_ITEM ResManRegisterRes(PRESMAN_CONTEXT	hResManContext,
							   IMG_UINT32		ui32ResType,
							   IMG_PVOID		pvParam,
							   IMG_UINT32		ui32Param,
							   RESMAN_FREE_FN	pfnFreeResource);

PVRSRV_ERROR ResManFreeResByPtr(PRESMAN_ITEM	psResItem);

PVRSRV_ERROR ResManFreeResByCriteria(PRESMAN_CONTEXT	hResManContext,
									 IMG_UINT32			ui32SearchCriteria,
									 IMG_UINT32			ui32ResType,
									 IMG_PVOID			pvParam,
									 IMG_UINT32			ui32Param);

PVRSRV_ERROR ResManDissociateRes(PRESMAN_ITEM		psResItem,
							 PRESMAN_CONTEXT	psNewResManContext);

PVRSRV_ERROR ResManFindResourceByPtr(PRESMAN_CONTEXT	hResManContext,
									 PRESMAN_ITEM		psItem);

PVRSRV_ERROR PVRSRVResManConnect(IMG_HANDLE			hPerProc,
								 PRESMAN_CONTEXT	*phResManContext);
IMG_VOID PVRSRVResManDisconnect(PRESMAN_CONTEXT hResManContext,
								IMG_BOOL		bKernelContext);

#if defined (__cplusplus)
}
#endif

#endif
