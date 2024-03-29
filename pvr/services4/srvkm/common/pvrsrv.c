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

#include "services_headers.h"
#include "buffer_manager.h"
#include "handle.h"
#include "perproc.h"
#include "pdump_km.h"
#include "ra.h"

#include "pvrversion.h"

#include "lists.h"


DECLARE_LIST_ANY_VA_2(BM_CONTEXT, PVRSRV_ERROR, PVRSRV_OK);

DECLARE_LIST_FOR_EACH_VA(BM_HEAP);

DECLARE_LIST_ANY_2(PVRSRV_DEVICE_NODE, PVRSRV_ERROR, PVRSRV_OK);
DECLARE_LIST_ANY_VA(PVRSRV_DEVICE_NODE);
DECLARE_LIST_ANY_VA_2(PVRSRV_DEVICE_NODE, PVRSRV_ERROR, PVRSRV_OK);
DECLARE_LIST_FOR_EACH_VA(PVRSRV_DEVICE_NODE);
DECLARE_LIST_FOR_EACH(PVRSRV_DEVICE_NODE);
DECLARE_LIST_INSERT(PVRSRV_DEVICE_NODE);
DECLARE_LIST_REMOVE(PVRSRV_DEVICE_NODE);

IMG_VOID* MatchDeviceKM_AnyVaCb(PVRSRV_DEVICE_NODE* psDeviceNode, va_list va);


PVRSRV_ERROR AllocateDeviceID(SYS_DATA *psSysData, IMG_UINT32 *pui32DevID)
{
	SYS_DEVICE_ID* psDeviceWalker;
	SYS_DEVICE_ID* psDeviceEnd;

	psDeviceWalker = &psSysData->sDeviceID[0];
	psDeviceEnd = psDeviceWalker + psSysData->ui32NumDevices;


	while (psDeviceWalker < psDeviceEnd)
	{
		if (!psDeviceWalker->bInUse)
		{
			psDeviceWalker->bInUse = IMG_TRUE;
			*pui32DevID = psDeviceWalker->uiID;
			return PVRSRV_OK;
		}
		psDeviceWalker++;
	}

	PVR_DPF((PVR_DBG_ERROR,"AllocateDeviceID: No free and valid device IDs "
			 "available!\nPerhaps need to increase SYS_DEVICE_COUNT (in "
			 "\"sysinfo.h\")."));


	PVR_ASSERT(psDeviceWalker < psDeviceEnd);

	return PVRSRV_ERROR_GENERIC;
}


PVRSRV_ERROR FreeDeviceID(SYS_DATA *psSysData, IMG_UINT32 ui32DevID)
{
	SYS_DEVICE_ID* psDeviceWalker;
	SYS_DEVICE_ID* psDeviceEnd;

	psDeviceWalker = &psSysData->sDeviceID[0];
	psDeviceEnd = psDeviceWalker + psSysData->ui32NumDevices;


	while (psDeviceWalker < psDeviceEnd)
	{

		if	(
				(psDeviceWalker->uiID == ui32DevID) &&
				(psDeviceWalker->bInUse)
			)
		{
			psDeviceWalker->bInUse = IMG_FALSE;
			return PVRSRV_OK;
		}
		psDeviceWalker++;
	}

	PVR_DPF((PVR_DBG_ERROR,"FreeDeviceID: no matching dev ID that is in use!"));


	PVR_ASSERT(psDeviceWalker < psDeviceEnd);

	return PVRSRV_ERROR_GENERIC;
}


#ifndef ReadHWReg
IMG_EXPORT
IMG_UINT32 ReadHWReg(IMG_PVOID pvLinRegBaseAddr, IMG_UINT32 ui32Offset)
{
	return *(volatile IMG_UINT32*)((IMG_UINTPTR_T)pvLinRegBaseAddr+ui32Offset);
}
#endif


#ifndef WriteHWReg
IMG_EXPORT
IMG_VOID WriteHWReg(IMG_PVOID pvLinRegBaseAddr, IMG_UINT32 ui32Offset, IMG_UINT32 ui32Value)
{
	PVR_DPF((PVR_DBG_MESSAGE,"WriteHWReg Base:%x, Offset: %x, Value %x",pvLinRegBaseAddr,ui32Offset,ui32Value));

	*(IMG_UINT32*)((IMG_UINTPTR_T)pvLinRegBaseAddr+ui32Offset) = ui32Value;
}
#endif


#ifndef WriteHWRegs
IMG_EXPORT
IMG_VOID WriteHWRegs(IMG_PVOID pvLinRegBaseAddr, IMG_UINT32 ui32Count, PVRSRV_HWREG *psHWRegs)
{
	while (ui32Count)
	{
		WriteHWReg (pvLinRegBaseAddr, psHWRegs->ui32RegAddr, psHWRegs->ui32RegVal);
		psHWRegs++;
		ui32Count--;
	}
}
#endif

IMG_VOID PVRSRVEnumerateDevicesKM_ForEachVaCb(PVRSRV_DEVICE_NODE *psDeviceNode, va_list va)
{
	IMG_UINT *pui32DevCount;
	PVRSRV_DEVICE_IDENTIFIER **ppsDevIdList;

	pui32DevCount = va_arg(va, IMG_UINT*);
	ppsDevIdList = va_arg(va, PVRSRV_DEVICE_IDENTIFIER**);

	if (psDeviceNode->sDevId.eDeviceType != PVRSRV_DEVICE_TYPE_EXT)
	{
		*(*ppsDevIdList) = psDeviceNode->sDevId;
		(*ppsDevIdList)++;
		(*pui32DevCount)++;
	}
}



IMG_EXPORT
PVRSRV_ERROR IMG_CALLCONV PVRSRVEnumerateDevicesKM(IMG_UINT32 *pui32NumDevices,
												   PVRSRV_DEVICE_IDENTIFIER *psDevIdList)
{
	SYS_DATA			*psSysData;
	IMG_UINT32 			i;

	if (!pui32NumDevices || !psDevIdList)
	{
		PVR_DPF((PVR_DBG_ERROR,"PVRSRVEnumerateDevicesKM: Invalid params"));
		return PVRSRV_ERROR_INVALID_PARAMS;
	}

	SysAcquireData(&psSysData);



	for (i=0; i<PVRSRV_MAX_DEVICES; i++)
	{
		psDevIdList[i].eDeviceType = PVRSRV_DEVICE_TYPE_UNKNOWN;
	}


	*pui32NumDevices = 0;





	List_PVRSRV_DEVICE_NODE_ForEach_va(psSysData->psDeviceNodeList,
									   PVRSRVEnumerateDevicesKM_ForEachVaCb,
									   pui32NumDevices,
									   &psDevIdList);


	return PVRSRV_OK;
}


PVRSRV_ERROR IMG_CALLCONV PVRSRVInit(PSYS_DATA psSysData)
{
	PVRSRV_ERROR	eError;


	eError = ResManInit();
	if (eError != PVRSRV_OK)
	{
		goto Error;
	}

	eError = PVRSRVPerProcessDataInit();
	if(eError != PVRSRV_OK)
	{
		goto Error;
	}


	eError = PVRSRVHandleInit();
	if(eError != PVRSRV_OK)
	{
		goto Error;
	}


	eError = OSCreateResource(&psSysData->sPowerStateChangeResource);
	if (eError != PVRSRV_OK)
	{
		goto Error;
	}


	psSysData->eCurrentPowerState = PVRSRV_SYS_POWER_STATE_D0;
	psSysData->eFailedPowerState = PVRSRV_SYS_POWER_STATE_Unspecified;


	if(OSAllocMem( PVRSRV_PAGEABLE_SELECT,
					 sizeof(PVRSRV_EVENTOBJECT) ,
					 (IMG_VOID **)&psSysData->psGlobalEventObject, 0,
					 "Event Object") != PVRSRV_OK)
	{

		goto Error;
	}

	if(OSEventObjectCreate("PVRSRV_GLOBAL_EVENTOBJECT", psSysData->psGlobalEventObject) != PVRSRV_OK)
	{
		goto Error;
	}

	return eError;

Error:
	PVRSRVDeInit(psSysData);
	return eError;
}



IMG_VOID IMG_CALLCONV PVRSRVDeInit(PSYS_DATA psSysData)
{
	PVRSRV_ERROR	eError;

	PVR_UNREFERENCED_PARAMETER(psSysData);

	if (psSysData == IMG_NULL)
	{
		PVR_DPF((PVR_DBG_ERROR,"PVRSRVDeInit: PVRSRVHandleDeInit failed - invalid param"));
		return;
	}


	if(psSysData->psGlobalEventObject)
	{
		OSEventObjectDestroy(psSysData->psGlobalEventObject);
		OSFreeMem( PVRSRV_PAGEABLE_SELECT,
						 sizeof(PVRSRV_EVENTOBJECT),
						 psSysData->psGlobalEventObject,
						 0);
		psSysData->psGlobalEventObject = IMG_NULL;
	}

	eError = PVRSRVHandleDeInit();
	if (eError != PVRSRV_OK)
	{
		PVR_DPF((PVR_DBG_ERROR,"PVRSRVDeInit: PVRSRVHandleDeInit failed"));
	}

	eError = PVRSRVPerProcessDataDeInit();
	if (eError != PVRSRV_OK)
	{
		PVR_DPF((PVR_DBG_ERROR,"PVRSRVDeInit: PVRSRVPerProcessDataDeInit failed"));
	}

	ResManDeInit();
}


PVRSRV_ERROR IMG_CALLCONV PVRSRVRegisterDevice(PSYS_DATA psSysData,
											  PVRSRV_ERROR (*pfnRegisterDevice)(PVRSRV_DEVICE_NODE*),
											  IMG_UINT32 ui32SOCInterruptBit,
											  IMG_UINT32 *pui32DeviceIndex)
{
	PVRSRV_ERROR		eError;
	PVRSRV_DEVICE_NODE	*psDeviceNode;


	if(OSAllocMem( PVRSRV_OS_NON_PAGEABLE_HEAP,
					 sizeof(PVRSRV_DEVICE_NODE),
					 (IMG_VOID **)&psDeviceNode, IMG_NULL,
					 "Device Node") != PVRSRV_OK)
	{
		PVR_DPF((PVR_DBG_ERROR,"PVRSRVRegisterDevice : Failed to alloc memory for psDeviceNode"));
		return (PVRSRV_ERROR_OUT_OF_MEMORY);
	}
	OSMemSet (psDeviceNode, 0, sizeof(PVRSRV_DEVICE_NODE));

	eError = pfnRegisterDevice(psDeviceNode);
	if (eError != PVRSRV_OK)
	{
		OSFreeMem(PVRSRV_OS_NON_PAGEABLE_HEAP,
					sizeof(PVRSRV_DEVICE_NODE), psDeviceNode, IMG_NULL);

		PVR_DPF((PVR_DBG_ERROR,"PVRSRVRegisterDevice : Failed to register device"));
		return (PVRSRV_ERROR_DEVICE_REGISTER_FAILED);
	}






	psDeviceNode->ui32RefCount = 1;
	psDeviceNode->psSysData = psSysData;
	psDeviceNode->ui32SOCInterruptBit = ui32SOCInterruptBit;


	AllocateDeviceID(psSysData, &psDeviceNode->sDevId.ui32DeviceIndex);


	List_PVRSRV_DEVICE_NODE_Insert(&psSysData->psDeviceNodeList, psDeviceNode);


	*pui32DeviceIndex = psDeviceNode->sDevId.ui32DeviceIndex;

	return PVRSRV_OK;
}


PVRSRV_ERROR IMG_CALLCONV PVRSRVInitialiseDevice (IMG_UINT32 ui32DevIndex)
{
	PVRSRV_DEVICE_NODE	*psDeviceNode;
	SYS_DATA			*psSysData;
	PVRSRV_ERROR		eError;

	PVR_DPF((PVR_DBG_MESSAGE, "PVRSRVInitialiseDevice"));

	SysAcquireData(&psSysData);


	psDeviceNode = (PVRSRV_DEVICE_NODE*)
					 List_PVRSRV_DEVICE_NODE_Any_va(psSysData->psDeviceNodeList,
													MatchDeviceKM_AnyVaCb,
													ui32DevIndex,
													IMG_TRUE);
	if(!psDeviceNode)
	{

		PVR_DPF((PVR_DBG_ERROR,"PVRSRVInitialiseDevice: requested device is not present"));
		return PVRSRV_ERROR_INIT_FAILURE;
	}
	PVR_ASSERT (psDeviceNode->ui32RefCount > 0);



	eError = PVRSRVResManConnect(IMG_NULL, &psDeviceNode->hResManContext);
	if (eError != PVRSRV_OK)
	{
		PVR_DPF((PVR_DBG_ERROR,"PVRSRVInitialiseDevice: Failed PVRSRVResManConnect call"));
		return eError;
	}


	if(psDeviceNode->pfnInitDevice != IMG_NULL)
	{
		eError = psDeviceNode->pfnInitDevice(psDeviceNode);
		if (eError != PVRSRV_OK)
		{
			PVR_DPF((PVR_DBG_ERROR,"PVRSRVInitialiseDevice: Failed InitDevice call"));
			return eError;
		}
	}

	return PVRSRV_OK;
}


PVRSRV_ERROR PVRSRVFinaliseSystem_SetPowerState_AnyCb(PVRSRV_DEVICE_NODE *psDeviceNode)
{
	PVRSRV_ERROR eError;
	eError = PVRSRVSetDevicePowerStateKM(psDeviceNode->sDevId.ui32DeviceIndex,
										 PVRSRV_DEV_POWER_STATE_DEFAULT,
										 KERNEL_ID, IMG_FALSE);
	if (eError != PVRSRV_OK)
	{
		PVR_DPF((PVR_DBG_ERROR,"PVRSRVFinaliseSystem: Failed PVRSRVSetDevicePowerStateKM call (device index: %d)", psDeviceNode->sDevId.ui32DeviceIndex));
	}
	return eError;
}

PVRSRV_ERROR PVRSRVFinaliseSystem_CompatCheck_AnyCb(PVRSRV_DEVICE_NODE *psDeviceNode)
{
	PVRSRV_ERROR eError;
	eError = PVRSRVDevInitCompatCheck(psDeviceNode);
	if (eError != PVRSRV_OK)
	{
		PVR_DPF((PVR_DBG_ERROR,"PVRSRVFinaliseSystem: Failed PVRSRVDevInitCompatCheck call (device index: %d)", psDeviceNode->sDevId.ui32DeviceIndex));
	}
	return eError;
}


PVRSRV_ERROR IMG_CALLCONV PVRSRVFinaliseSystem(IMG_BOOL bInitSuccessful)
{
	SYS_DATA		*psSysData;
	PVRSRV_ERROR		eError;

	PVR_DPF((PVR_DBG_MESSAGE, "PVRSRVFinaliseSystem"));

	SysAcquireData(&psSysData);

	if (bInitSuccessful)
	{
		eError = SysFinalise();
		if (eError != PVRSRV_OK)
		{
			PVR_DPF((PVR_DBG_ERROR,"PVRSRVFinaliseSystem: SysFinalise failed (%d)", eError));
			return eError;
		}


		eError = List_PVRSRV_DEVICE_NODE_PVRSRV_ERROR_Any(psSysData->psDeviceNodeList,
														PVRSRVFinaliseSystem_SetPowerState_AnyCb);
		if (eError != PVRSRV_OK)
		{
			return eError;
		}


		eError = List_PVRSRV_DEVICE_NODE_PVRSRV_ERROR_Any(psSysData->psDeviceNodeList,
													PVRSRVFinaliseSystem_CompatCheck_AnyCb);
		if (eError != PVRSRV_OK)
		{
			return eError;
		}
	}








#if !defined(SUPPORT_PDUMP_DELAYED_INITPHASE_TERMINATION)
	PDUMPENDINITPHASE();
#endif

	return PVRSRV_OK;
}


PVRSRV_ERROR PVRSRVDevInitCompatCheck(PVRSRV_DEVICE_NODE *psDeviceNode)
{

	if (psDeviceNode->pfnInitDeviceCompatCheck)
		return psDeviceNode->pfnInitDeviceCompatCheck(psDeviceNode);
	else
		return PVRSRV_OK;
}

IMG_VOID * PVRSRVAcquireDeviceDataKM_Match_AnyVaCb(PVRSRV_DEVICE_NODE *psDeviceNode, va_list va)
{
	PVRSRV_DEVICE_TYPE eDeviceType;
	IMG_UINT32 ui32DevIndex;

	eDeviceType = va_arg(va, PVRSRV_DEVICE_TYPE);
	ui32DevIndex = va_arg(va, IMG_UINT32);

	if ((eDeviceType != PVRSRV_DEVICE_TYPE_UNKNOWN &&
		psDeviceNode->sDevId.eDeviceType == eDeviceType) ||
		(eDeviceType == PVRSRV_DEVICE_TYPE_UNKNOWN &&
		 psDeviceNode->sDevId.ui32DeviceIndex == ui32DevIndex))
	{
		return psDeviceNode;
	}
	else
	{
		return IMG_NULL;
	}
}

IMG_EXPORT
PVRSRV_ERROR IMG_CALLCONV PVRSRVAcquireDeviceDataKM (IMG_UINT32			ui32DevIndex,
													 PVRSRV_DEVICE_TYPE	eDeviceType,
													 IMG_HANDLE			*phDevCookie)
{
	PVRSRV_DEVICE_NODE	*psDeviceNode;
	SYS_DATA			*psSysData;

	PVR_DPF((PVR_DBG_MESSAGE, "PVRSRVAcquireDeviceDataKM"));

	SysAcquireData(&psSysData);


	psDeviceNode = List_PVRSRV_DEVICE_NODE_Any_va(psSysData->psDeviceNodeList,
												PVRSRVAcquireDeviceDataKM_Match_AnyVaCb,
												eDeviceType,
												ui32DevIndex);


	if (!psDeviceNode)
	{

		PVR_DPF((PVR_DBG_ERROR,"PVRSRVAcquireDeviceDataKM: requested device is not present"));
		return PVRSRV_ERROR_INIT_FAILURE;
	}

	PVR_ASSERT (psDeviceNode->ui32RefCount > 0);


	if (phDevCookie)
	{
		*phDevCookie = (IMG_HANDLE)psDeviceNode;
	}

	return PVRSRV_OK;
}


PVRSRV_ERROR IMG_CALLCONV PVRSRVDeinitialiseDevice(IMG_UINT32 ui32DevIndex)
{
	PVRSRV_DEVICE_NODE	*psDeviceNode;
	SYS_DATA			*psSysData;
	PVRSRV_ERROR		eError;

	SysAcquireData(&psSysData);

	psDeviceNode = (PVRSRV_DEVICE_NODE*)
					 List_PVRSRV_DEVICE_NODE_Any_va(psSysData->psDeviceNodeList,
													MatchDeviceKM_AnyVaCb,
													ui32DevIndex,
													IMG_TRUE);

	if (!psDeviceNode)
	{
		PVR_DPF((PVR_DBG_ERROR,"PVRSRVDeinitialiseDevice: requested device %d is not present", ui32DevIndex));
		return PVRSRV_ERROR_GENERIC;
	}



	eError = PVRSRVSetDevicePowerStateKM(ui32DevIndex,
										 PVRSRV_DEV_POWER_STATE_OFF,
										 KERNEL_ID,
										 IMG_FALSE);
	if (eError != PVRSRV_OK)
	{
		PVR_DPF((PVR_DBG_ERROR,"PVRSRVDeinitialiseDevice: Failed PVRSRVSetDevicePowerStateKM call"));
		return eError;
	}



	eError = ResManFreeResByCriteria(psDeviceNode->hResManContext,
									 RESMAN_CRITERIA_RESTYPE,
									 RESMAN_TYPE_DEVICEMEM_ALLOCATION,
									 IMG_NULL, 0);
	if (eError != PVRSRV_OK)
	{
		PVR_DPF((PVR_DBG_ERROR,"PVRSRVDeinitialiseDevice: Failed ResManFreeResByCriteria call"));
		return eError;
	}



	if(psDeviceNode->pfnDeInitDevice != IMG_NULL)
	{
		eError = psDeviceNode->pfnDeInitDevice(psDeviceNode);
		if (eError != PVRSRV_OK)
		{
			PVR_DPF((PVR_DBG_ERROR,"PVRSRVDeinitialiseDevice: Failed DeInitDevice call"));
			return eError;
		}
	}



	PVRSRVResManDisconnect(psDeviceNode->hResManContext, IMG_TRUE);
	psDeviceNode->hResManContext = IMG_NULL;


	List_PVRSRV_DEVICE_NODE_Remove(psDeviceNode);


	(IMG_VOID)FreeDeviceID(psSysData, ui32DevIndex);
	OSFreeMem(PVRSRV_OS_NON_PAGEABLE_HEAP,
				sizeof(PVRSRV_DEVICE_NODE), psDeviceNode, IMG_NULL);


	return (PVRSRV_OK);
}


IMG_EXPORT
PVRSRV_ERROR IMG_CALLCONV PollForValueKM (volatile IMG_UINT32* pui32LinMemAddr,
										  IMG_UINT32 ui32Value,
										  IMG_UINT32 ui32Mask,
										  IMG_UINT32 ui32Waitus,
										  IMG_UINT32 ui32Tries)
{
	{
		IMG_UINT32	uiMaxTime = ui32Tries * ui32Waitus;

		LOOP_UNTIL_TIMEOUT(uiMaxTime)
		{
			if((*pui32LinMemAddr & ui32Mask) == ui32Value)
			{
				return PVRSRV_OK;
			}
			OSWaitus(ui32Waitus);
		} END_LOOP_UNTIL_TIMEOUT();
	}


	return PVRSRV_ERROR_GENERIC;
}


#if defined (USING_ISR_INTERRUPTS)

extern IMG_UINT32 gui32EventStatusServicesByISR;

PVRSRV_ERROR PollForInterruptKM (IMG_UINT32 ui32Value,
								 IMG_UINT32 ui32Mask,
								 IMG_UINT32 ui32Waitus,
								 IMG_UINT32 ui32Tries)
{
	IMG_UINT32	uiMaxTime;

	uiMaxTime = ui32Tries * ui32Waitus;


	LOOP_UNTIL_TIMEOUT(uiMaxTime)
	{
		if ((gui32EventStatusServicesByISR & ui32Mask) == ui32Value)
		{
			gui32EventStatusServicesByISR = 0;
			return PVRSRV_OK;
		}
		OSWaitus(ui32Waitus);
	} END_LOOP_UNTIL_TIMEOUT();

	return PVRSRV_ERROR_GENERIC;
}
#endif

IMG_VOID PVRSRVGetMiscInfoKM_RA_GetStats_ForEachVaCb(BM_HEAP *psBMHeap, va_list va)
{
	IMG_CHAR **ppszStr;
	IMG_UINT32 *pui32StrLen;

	ppszStr = va_arg(va, IMG_CHAR**);
	pui32StrLen = va_arg(va, IMG_UINT32*);

	if(psBMHeap->pImportArena)
	{
		RA_GetStats(psBMHeap->pImportArena,
					ppszStr,
					pui32StrLen);
	}

	if(psBMHeap->pVMArena)
	{
		RA_GetStats(psBMHeap->pVMArena,
					ppszStr,
					pui32StrLen);
	}
}

PVRSRV_ERROR PVRSRVGetMiscInfoKM_BMContext_AnyVaCb(BM_CONTEXT *psBMContext, va_list va)
{

	IMG_UINT32 *pui32StrLen;
	IMG_INT32 *pi32Count;
	IMG_CHAR **ppszStr;

	pui32StrLen = va_arg(va, IMG_UINT32*);
	pi32Count = va_arg(va, IMG_INT32*);
	ppszStr = va_arg(va, IMG_CHAR**);

	CHECK_SPACE(*pui32StrLen);
	*pi32Count = OSSNPrintf(*ppszStr, 100, "\nApplication Context (hDevMemContext) 0x%08X:\n",
							(IMG_HANDLE)psBMContext);
	UPDATE_SPACE(*ppszStr, *pi32Count, *pui32StrLen);

	List_BM_HEAP_ForEach_va(psBMContext->psBMHeap,
							PVRSRVGetMiscInfoKM_RA_GetStats_ForEachVaCb,
							ppszStr,
							pui32StrLen);
	return PVRSRV_OK;
}


PVRSRV_ERROR PVRSRVGetMiscInfoKM_Device_AnyVaCb(PVRSRV_DEVICE_NODE *psDeviceNode, va_list va)
{
	IMG_UINT32 *pui32StrLen;
	IMG_INT32 *pi32Count;
	IMG_CHAR **ppszStr;

	pui32StrLen = va_arg(va, IMG_UINT32*);
	pi32Count = va_arg(va, IMG_INT32*);
	ppszStr = va_arg(va, IMG_CHAR**);

	CHECK_SPACE(*pui32StrLen);
	*pi32Count = OSSNPrintf(*ppszStr, 100, "\n\nDevice Type %d:\n", psDeviceNode->sDevId.eDeviceType);
	UPDATE_SPACE(*ppszStr, *pi32Count, *pui32StrLen);


	if(psDeviceNode->sDevMemoryInfo.pBMKernelContext)
	{
		CHECK_SPACE(*pui32StrLen);
		*pi32Count = OSSNPrintf(*ppszStr, 100, "\nKernel Context:\n");
		UPDATE_SPACE(*ppszStr, *pi32Count, *pui32StrLen);


		List_BM_HEAP_ForEach_va(psDeviceNode->sDevMemoryInfo.pBMKernelContext->psBMHeap,
								PVRSRVGetMiscInfoKM_RA_GetStats_ForEachVaCb,
								ppszStr,
								pui32StrLen);
	}


	return List_BM_CONTEXT_PVRSRV_ERROR_Any_va(psDeviceNode->sDevMemoryInfo.pBMContext,
												PVRSRVGetMiscInfoKM_BMContext_AnyVaCb,
												pui32StrLen,
												pi32Count,
												ppszStr);
}


IMG_EXPORT
PVRSRV_ERROR IMG_CALLCONV PVRSRVGetMiscInfoKM(PVRSRV_MISC_INFO *psMiscInfo)
{
	SYS_DATA *psSysData;

	if(!psMiscInfo)
	{
		PVR_DPF((PVR_DBG_ERROR,"PVRSRVGetMiscInfoKM: invalid parameters"));
		return PVRSRV_ERROR_INVALID_PARAMS;
	}

	psMiscInfo->ui32StatePresent = 0;


	if(psMiscInfo->ui32StateRequest & ~( PVRSRV_MISC_INFO_TIMER_PRESENT
										|PVRSRV_MISC_INFO_CLOCKGATE_PRESENT
										|PVRSRV_MISC_INFO_MEMSTATS_PRESENT
										|PVRSRV_MISC_INFO_GLOBALEVENTOBJECT_PRESENT
										|PVRSRV_MISC_INFO_DDKVERSION_PRESENT
										|PVRSRV_MISC_INFO_CPUCACHEFLUSH_PRESENT
										|PVRSRV_MISC_INFO_RESET_PRESENT))
	{
		PVR_DPF((PVR_DBG_ERROR,"PVRSRVGetMiscInfoKM: invalid state request flags"));
		return PVRSRV_ERROR_INVALID_PARAMS;
	}

	SysAcquireData(&psSysData);


	if(((psMiscInfo->ui32StateRequest & PVRSRV_MISC_INFO_TIMER_PRESENT) != 0UL) &&
		(psSysData->pvSOCTimerRegisterKM != IMG_NULL))
	{
		psMiscInfo->ui32StatePresent |= PVRSRV_MISC_INFO_TIMER_PRESENT;
		psMiscInfo->pvSOCTimerRegisterKM = psSysData->pvSOCTimerRegisterKM;
		psMiscInfo->hSOCTimerRegisterOSMemHandle = psSysData->hSOCTimerRegisterOSMemHandle;
	}
	else
	{
		psMiscInfo->pvSOCTimerRegisterKM = IMG_NULL;
		psMiscInfo->hSOCTimerRegisterOSMemHandle = IMG_NULL;
	}


	if(((psMiscInfo->ui32StateRequest & PVRSRV_MISC_INFO_CLOCKGATE_PRESENT) != 0UL) &&
		(psSysData->pvSOCClockGateRegsBase != IMG_NULL))
	{
		psMiscInfo->ui32StatePresent |= PVRSRV_MISC_INFO_CLOCKGATE_PRESENT;
		psMiscInfo->pvSOCClockGateRegs = psSysData->pvSOCClockGateRegsBase;
		psMiscInfo->ui32SOCClockGateRegsSize = psSysData->ui32SOCClockGateRegsSize;
	}


	if(((psMiscInfo->ui32StateRequest & PVRSRV_MISC_INFO_MEMSTATS_PRESENT) != 0UL) &&
		(psMiscInfo->pszMemoryStr != IMG_NULL))
	{
		RA_ARENA			**ppArena;
		IMG_CHAR			*pszStr;
		IMG_UINT32			ui32StrLen;
		IMG_INT32			i32Count;

		pszStr = psMiscInfo->pszMemoryStr;
		ui32StrLen = psMiscInfo->ui32MemoryStrLen;

		psMiscInfo->ui32StatePresent |= PVRSRV_MISC_INFO_MEMSTATS_PRESENT;


		ppArena = &psSysData->apsLocalDevMemArena[0];
		while(*ppArena)
		{
			CHECK_SPACE(ui32StrLen);
			i32Count = OSSNPrintf(pszStr, 100, "\nLocal Backing Store:\n");
			UPDATE_SPACE(pszStr, i32Count, ui32StrLen);

			RA_GetStats(*ppArena,
							&pszStr,
							&ui32StrLen);

			ppArena++;
		}



		List_PVRSRV_DEVICE_NODE_PVRSRV_ERROR_Any_va(psSysData->psDeviceNodeList,
													PVRSRVGetMiscInfoKM_Device_AnyVaCb,
													&ui32StrLen,
													&i32Count,
													&pszStr);


		i32Count = OSSNPrintf(pszStr, 100, "\n\0");
		UPDATE_SPACE(pszStr, i32Count, ui32StrLen);
	}

	if(((psMiscInfo->ui32StateRequest & PVRSRV_MISC_INFO_GLOBALEVENTOBJECT_PRESENT) != 0UL) &&
		(psSysData->psGlobalEventObject != IMG_NULL))
	{
		psMiscInfo->ui32StatePresent |= PVRSRV_MISC_INFO_GLOBALEVENTOBJECT_PRESENT;
		psMiscInfo->sGlobalEventObject = *psSysData->psGlobalEventObject;
	}



	if (((psMiscInfo->ui32StateRequest & PVRSRV_MISC_INFO_DDKVERSION_PRESENT) != 0UL)
		&& ((psMiscInfo->ui32StateRequest & PVRSRV_MISC_INFO_MEMSTATS_PRESENT) == 0UL)
		&& (psMiscInfo->pszMemoryStr != IMG_NULL))
	{
		IMG_CHAR	*pszStr;
		IMG_UINT32	ui32StrLen;
		IMG_UINT32 	ui32LenStrPerNum = 12;
		IMG_INT32	i32Count;
		IMG_INT i;
		psMiscInfo->ui32StatePresent |= PVRSRV_MISC_INFO_DDKVERSION_PRESENT;


		psMiscInfo->aui32DDKVersion[0] = PVRVERSION_MAJ;
		psMiscInfo->aui32DDKVersion[1] = PVRVERSION_MIN;
		psMiscInfo->aui32DDKVersion[2] = PVRVERSION_BRANCH;
		psMiscInfo->aui32DDKVersion[3] = PVRVERSION_BUILD;

		pszStr = psMiscInfo->pszMemoryStr;
		ui32StrLen = psMiscInfo->ui32MemoryStrLen;

		for (i=0; i<4; i++)
		{
			if (ui32StrLen < ui32LenStrPerNum)
			{
				return PVRSRV_ERROR_INVALID_PARAMS;
			}

			i32Count = OSSNPrintf(pszStr, ui32LenStrPerNum, "%ld", psMiscInfo->aui32DDKVersion[i]);
			UPDATE_SPACE(pszStr, i32Count, ui32StrLen);
			if (i != 3)
			{
				i32Count = OSSNPrintf(pszStr, 2, ".");
				UPDATE_SPACE(pszStr, i32Count, ui32StrLen);
			}
		}
	}

#if defined(SUPPORT_CPU_CACHED_BUFFERS)
	if((psMiscInfo->ui32StateRequest & PVRSRV_MISC_INFO_CPUCACHEFLUSH_PRESENT) != 0UL)
	{
		if(psMiscInfo->bDeferCPUCacheFlush)
		{

			if(!psMiscInfo->bCPUCacheFlushAll)
			{



				PVR_DPF((PVR_DBG_MESSAGE,"PVRSRVGetMiscInfoKM: don't support deferred range flushes"));
				PVR_DPF((PVR_DBG_MESSAGE,"                     using deferred flush all instead"));
			}

			psSysData->bFlushAll = IMG_TRUE;
		}
		else
		{

			if(psMiscInfo->bCPUCacheFlushAll)
			{

				OSFlushCPUCacheKM();

				psSysData->bFlushAll = IMG_FALSE;
			}
			else
			{

				OSFlushCPUCacheRangeKM(psMiscInfo->pvRangeAddrStart, psMiscInfo->pvRangeAddrEnd);
			}
		}
	}
#endif

#if defined(PVRSRV_RESET_ON_HWTIMEOUT)
	if((psMiscInfo->ui32StateRequest & PVRSRV_MISC_INFO_RESET_PRESENT) != 0UL)
	{
		PVR_LOG(("User requested OS reset"));
		OSPanic();
	}
#endif

	return PVRSRV_OK;
}


PVRSRV_ERROR IMG_CALLCONV PVRSRVGetFBStatsKM(IMG_UINT32		*pui32Total,
											 IMG_UINT32		*pui32Available)
{
	IMG_UINT32 ui32Total = 0, i = 0;
	IMG_UINT32 ui32Available = 0;

	*pui32Total		= 0;
	*pui32Available = 0;


	while(BM_ContiguousStatistics(i, &ui32Total, &ui32Available) == IMG_TRUE)
	{
		*pui32Total		+= ui32Total;
		*pui32Available += ui32Available;

		i++;
	}

	return PVRSRV_OK;
}


IMG_BOOL IMG_CALLCONV PVRSRVDeviceLISR(PVRSRV_DEVICE_NODE *psDeviceNode)
{
	SYS_DATA			*psSysData;
	IMG_BOOL			bStatus = IMG_FALSE;
	IMG_UINT32			ui32InterruptSource;

	if(!psDeviceNode)
	{
		PVR_DPF((PVR_DBG_ERROR, "PVRSRVDeviceLISR: Invalid params\n"));
		goto out;
	}
	psSysData = psDeviceNode->psSysData;


	ui32InterruptSource = SysGetInterruptSource(psSysData, psDeviceNode);
	if(ui32InterruptSource & psDeviceNode->ui32SOCInterruptBit)
	{
		if(psDeviceNode->pfnDeviceISR != IMG_NULL)
		{
			bStatus = (*psDeviceNode->pfnDeviceISR)(psDeviceNode->pvISRData);
		}

		SysClearInterrupts(psSysData, psDeviceNode->ui32SOCInterruptBit);
	}

out:
	return bStatus;
}

IMG_VOID PVRSRVSystemLISR_ForEachVaCb(PVRSRV_DEVICE_NODE *psDeviceNode, va_list va)
{

	IMG_BOOL *pbStatus;
	IMG_UINT32 *pui32InterruptSource;
	IMG_UINT32 *pui32ClearInterrupts;

	pbStatus = va_arg(va, IMG_BOOL*);
	pui32InterruptSource = va_arg(va, IMG_UINT32*);
	pui32ClearInterrupts = va_arg(va, IMG_UINT32*);


	if(psDeviceNode->pfnDeviceISR != IMG_NULL)
	{
		if(*pui32InterruptSource & psDeviceNode->ui32SOCInterruptBit)
		{
			if((*psDeviceNode->pfnDeviceISR)(psDeviceNode->pvISRData))
			{

				*pbStatus = IMG_TRUE;
			}

			*pui32ClearInterrupts |= psDeviceNode->ui32SOCInterruptBit;
		}
	}
}

IMG_BOOL IMG_CALLCONV PVRSRVSystemLISR(IMG_VOID *pvSysData)
{
	SYS_DATA			*psSysData = pvSysData;
	IMG_BOOL			bStatus = IMG_FALSE;
	IMG_UINT32			ui32InterruptSource;
	IMG_UINT32			ui32ClearInterrupts = 0;
	if(!psSysData)
	{
		PVR_DPF((PVR_DBG_ERROR, "PVRSRVSystemLISR: Invalid params\n"));
	}
	else
	{

		ui32InterruptSource = SysGetInterruptSource(psSysData, IMG_NULL);


		if(ui32InterruptSource)
		{

			List_PVRSRV_DEVICE_NODE_ForEach_va(psSysData->psDeviceNodeList,
												PVRSRVSystemLISR_ForEachVaCb,
												&bStatus,
												&ui32InterruptSource,
												&ui32ClearInterrupts);

			SysClearInterrupts(psSysData, ui32ClearInterrupts);
		}
	}
	return bStatus;
}


IMG_VOID PVRSRVMISR_ForEachCb(PVRSRV_DEVICE_NODE *psDeviceNode)
{
	if(psDeviceNode->pfnDeviceMISR != IMG_NULL)
	{
		(*psDeviceNode->pfnDeviceMISR)(psDeviceNode->pvISRData);
	}
}

IMG_VOID IMG_CALLCONV PVRSRVMISR(IMG_VOID *pvSysData)
{
	SYS_DATA			*psSysData = pvSysData;
	if(!psSysData)
	{
		PVR_DPF((PVR_DBG_ERROR, "PVRSRVMISR: Invalid params\n"));
		return;
	}


	List_PVRSRV_DEVICE_NODE_ForEach(psSysData->psDeviceNodeList,
									PVRSRVMISR_ForEachCb);


	if (PVRSRVProcessQueues(ISR_ID, IMG_FALSE) == PVRSRV_ERROR_PROCESSING_BLOCKED)
	{
		PVRSRVProcessQueues(ISR_ID, IMG_FALSE);
	}


	if (psSysData->psGlobalEventObject)
	{
		IMG_HANDLE hOSEventKM = psSysData->psGlobalEventObject->hOSEventKM;
		if(hOSEventKM)
		{
			OSEventObjectSignal(hOSEventKM);
		}
	}
}


IMG_EXPORT
PVRSRV_ERROR IMG_CALLCONV PVRSRVProcessConnect(IMG_UINT32	ui32PID)
{
	return PVRSRVPerProcessDataConnect(ui32PID);
}


IMG_EXPORT
IMG_VOID IMG_CALLCONV PVRSRVProcessDisconnect(IMG_UINT32	ui32PID)
{
	PVRSRVPerProcessDataDisconnect(ui32PID);
}


PVRSRV_ERROR IMG_CALLCONV PVRSRVSaveRestoreLiveSegments(IMG_HANDLE hArena, IMG_PBYTE pbyBuffer,
														IMG_SIZE_T *puiBufSize, IMG_BOOL bSave)
{
	IMG_SIZE_T         uiBytesSaved = 0;
	IMG_PVOID          pvLocalMemCPUVAddr;
	RA_SEGMENT_DETAILS sSegDetails;

	if (hArena == IMG_NULL)
	{
		return (PVRSRV_ERROR_INVALID_PARAMS);
	}

	sSegDetails.uiSize = 0;
	sSegDetails.sCpuPhyAddr.uiAddr = 0;
	sSegDetails.hSegment = 0;


	while (RA_GetNextLiveSegment(hArena, &sSegDetails))
	{
		if (pbyBuffer == IMG_NULL)
		{

			uiBytesSaved += sizeof(sSegDetails.uiSize) + sSegDetails.uiSize;
		}
		else
		{
			if ((uiBytesSaved + sizeof(sSegDetails.uiSize) + sSegDetails.uiSize) > *puiBufSize)
			{
				return (PVRSRV_ERROR_OUT_OF_MEMORY);
			}

			PVR_DPF((PVR_DBG_MESSAGE, "PVRSRVSaveRestoreLiveSegments: Base %08x size %08x", sSegDetails.sCpuPhyAddr.uiAddr, sSegDetails.uiSize));


			pvLocalMemCPUVAddr = OSMapPhysToLin(sSegDetails.sCpuPhyAddr,
									sSegDetails.uiSize,
									PVRSRV_HAP_KERNEL_ONLY|PVRSRV_HAP_UNCACHED,
									IMG_NULL);
			if (pvLocalMemCPUVAddr == IMG_NULL)
			{
				PVR_DPF((PVR_DBG_ERROR, "PVRSRVSaveRestoreLiveSegments: Failed to map local memory to host"));
				return (PVRSRV_ERROR_OUT_OF_MEMORY);
			}

			if (bSave)
			{

				OSMemCopy(pbyBuffer, &sSegDetails.uiSize, sizeof(sSegDetails.uiSize));
				pbyBuffer += sizeof(sSegDetails.uiSize);

				OSMemCopy(pbyBuffer, pvLocalMemCPUVAddr, sSegDetails.uiSize);
				pbyBuffer += sSegDetails.uiSize;
			}
			else
			{
				IMG_UINT32 uiSize;

				OSMemCopy(&uiSize, pbyBuffer, sizeof(sSegDetails.uiSize));

				if (uiSize != sSegDetails.uiSize)
				{
					PVR_DPF((PVR_DBG_ERROR, "PVRSRVSaveRestoreLiveSegments: Segment size error"));
				}
				else
				{
					pbyBuffer += sizeof(sSegDetails.uiSize);

					OSMemCopy(pvLocalMemCPUVAddr, pbyBuffer, sSegDetails.uiSize);
					pbyBuffer += sSegDetails.uiSize;
				}
			}


			uiBytesSaved += sizeof(sSegDetails.uiSize) + sSegDetails.uiSize;

			OSUnMapPhysToLin(pvLocalMemCPUVAddr,
		                     sSegDetails.uiSize,
		                     PVRSRV_HAP_KERNEL_ONLY|PVRSRV_HAP_UNCACHED,
		                     IMG_NULL);
		}
	}

	if (pbyBuffer == IMG_NULL)
	{
		*puiBufSize = uiBytesSaved;
	}

	return (PVRSRV_OK);
}
