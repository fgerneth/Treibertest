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

#ifndef _METRICS_
#define _METRICS_


#if defined (__cplusplus)
extern "C" {
#endif


#if defined(DEBUG) || defined(TIMING)


typedef struct
{
	IMG_UINT32 ui32Start;
	IMG_UINT32 ui32Stop;
	IMG_UINT32 ui32Total;
	IMG_UINT32 ui32Count;
} Temporal_Data;

extern Temporal_Data asTimers[];

extern IMG_UINT32 PVRSRVTimeNow(IMG_VOID);
extern IMG_VOID   PVRSRVSetupMetricTimers(IMG_VOID *pvDevInfo);
extern IMG_VOID   PVRSRVOutputMetricTotals(IMG_VOID);


#define PVRSRV_TIMER_DUMMY				0

#define PVRSRV_TIMER_EXAMPLE_1			1
#define PVRSRV_TIMER_EXAMPLE_2			2


#define PVRSRV_NUM_TIMERS		(PVRSRV_TIMER_EXAMPLE_2 + 1)

#define PVRSRV_TIME_START(X)	{ \
									asTimers[X].ui32Count += 1; \
									asTimers[X].ui32Count |= 0x80000000L; \
									asTimers[X].ui32Start = PVRSRVTimeNow(); \
									asTimers[X].ui32Stop  = 0; \
								}

#define PVRSRV_TIME_SUSPEND(X)	{ \
									asTimers[X].ui32Stop += PVRSRVTimeNow() - asTimers[X].ui32Start; \
								}

#define PVRSRV_TIME_RESUME(X)	{ \
									asTimers[X].ui32Start = PVRSRVTimeNow(); \
								}

#define PVRSRV_TIME_STOP(X)		{ \
									asTimers[X].ui32Stop  += PVRSRVTimeNow() - asTimers[X].ui32Start; \
									asTimers[X].ui32Total += asTimers[X].ui32Stop; \
									asTimers[X].ui32Count &= 0x7FFFFFFFL; \
								}

#define PVRSRV_TIME_RESET(X)	{ \
									asTimers[X].ui32Start = 0; \
									asTimers[X].ui32Stop  = 0; \
									asTimers[X].ui32Total = 0; \
									asTimers[X].ui32Count = 0; \
								}


#if defined(__sh__)

#define TST_REG   ((volatile IMG_UINT8 *) (psDevInfo->pvSOCRegsBaseKM))

#define TCOR_2    ((volatile IMG_UINT *)  (psDevInfo->pvSOCRegsBaseKM+28))
#define TCNT_2    ((volatile IMG_UINT *)  (psDevInfo->pvSOCRegsBaseKM+32))
#define TCR_2     ((volatile IMG_UINT16 *)(psDevInfo->pvSOCRegsBaseKM+36))

#define TIMER_DIVISOR  4

#endif





#else



#define PVRSRV_TIME_START(X)
#define PVRSRV_TIME_SUSPEND(X)
#define PVRSRV_TIME_RESUME(X)
#define PVRSRV_TIME_STOP(X)
#define PVRSRV_TIME_RESET(X)

#define PVRSRVSetupMetricTimers(X)
#define PVRSRVOutputMetricTotals()



#endif

#if defined(__cplusplus)
}
#endif


#endif
