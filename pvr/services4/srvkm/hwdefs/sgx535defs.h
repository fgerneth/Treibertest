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

#ifndef _SGX535DEFS_KM_H_
#define _SGX535DEFS_KM_H_

#define EUR_CR_CLKGATECTL                   0x0000
#define EUR_CR_CLKGATECTL_2D_CLKG_MASK      0x00000003UL
#define EUR_CR_CLKGATECTL_2D_CLKG_SHIFT     0
#define EUR_CR_CLKGATECTL_ISP_CLKG_MASK     0x00000030UL
#define EUR_CR_CLKGATECTL_ISP_CLKG_SHIFT    4
#define EUR_CR_CLKGATECTL_TSP_CLKG_MASK     0x00000300UL
#define EUR_CR_CLKGATECTL_TSP_CLKG_SHIFT    8
#define EUR_CR_CLKGATECTL_TA_CLKG_MASK      0x00003000UL
#define EUR_CR_CLKGATECTL_TA_CLKG_SHIFT     12
#define EUR_CR_CLKGATECTL_DPM_CLKG_MASK     0x00030000UL
#define EUR_CR_CLKGATECTL_DPM_CLKG_SHIFT    16
#define EUR_CR_CLKGATECTL_USE_CLKG_MASK     0x00300000UL
#define EUR_CR_CLKGATECTL_USE_CLKG_SHIFT    20
#define EUR_CR_CLKGATECTL_AUTO_MAN_REG_MASK 0x01000000UL
#define EUR_CR_CLKGATECTL_AUTO_MAN_REG_SHIFT 24
#define EUR_CR_CLKGATESTATUS                0x0004
#define EUR_CR_CLKGATESTATUS_2D_CLKS_MASK   0x00000001UL
#define EUR_CR_CLKGATESTATUS_2D_CLKS_SHIFT  0
#define EUR_CR_CLKGATESTATUS_ISP_CLKS_MASK  0x00000010UL
#define EUR_CR_CLKGATESTATUS_ISP_CLKS_SHIFT 4
#define EUR_CR_CLKGATESTATUS_TSP_CLKS_MASK  0x00000100UL
#define EUR_CR_CLKGATESTATUS_TSP_CLKS_SHIFT 8
#define EUR_CR_CLKGATESTATUS_TA_CLKS_MASK   0x00001000UL
#define EUR_CR_CLKGATESTATUS_TA_CLKS_SHIFT  12
#define EUR_CR_CLKGATESTATUS_DPM_CLKS_MASK  0x00010000UL
#define EUR_CR_CLKGATESTATUS_DPM_CLKS_SHIFT 16
#define EUR_CR_CLKGATESTATUS_USE_CLKS_MASK  0x00100000UL
#define EUR_CR_CLKGATESTATUS_USE_CLKS_SHIFT 20
#define EUR_CR_CLKGATECTLOVR                0x0008
#define EUR_CR_CLKGATECTLOVR_2D_CLKO_MASK   0x00000003UL
#define EUR_CR_CLKGATECTLOVR_2D_CLKO_SHIFT  0
#define EUR_CR_CLKGATECTLOVR_ISP_CLKO_MASK  0x00000030UL
#define EUR_CR_CLKGATECTLOVR_ISP_CLKO_SHIFT 4
#define EUR_CR_CLKGATECTLOVR_TSP_CLKO_MASK  0x00000300UL
#define EUR_CR_CLKGATECTLOVR_TSP_CLKO_SHIFT 8
#define EUR_CR_CLKGATECTLOVR_TA_CLKO_MASK   0x00003000UL
#define EUR_CR_CLKGATECTLOVR_TA_CLKO_SHIFT  12
#define EUR_CR_CLKGATECTLOVR_DPM_CLKO_MASK  0x00030000UL
#define EUR_CR_CLKGATECTLOVR_DPM_CLKO_SHIFT 16
#define EUR_CR_CLKGATECTLOVR_USE_CLKO_MASK  0x00300000UL
#define EUR_CR_CLKGATECTLOVR_USE_CLKO_SHIFT 20
#define EUR_CR_CORE_ID                      0x0010
#define EUR_CR_CORE_ID_CONFIG_MASK          0x0000FFFFUL
#define EUR_CR_CORE_ID_CONFIG_SHIFT         0
#define EUR_CR_CORE_ID_ID_MASK              0xFFFF0000UL
#define EUR_CR_CORE_ID_ID_SHIFT             16
#define EUR_CR_CORE_REVISION                0x0014
#define EUR_CR_CORE_REVISION_MAINTENANCE_MASK 0x000000FFUL
#define EUR_CR_CORE_REVISION_MAINTENANCE_SHIFT 0
#define EUR_CR_CORE_REVISION_MINOR_MASK     0x0000FF00UL
#define EUR_CR_CORE_REVISION_MINOR_SHIFT    8
#define EUR_CR_CORE_REVISION_MAJOR_MASK     0x00FF0000UL
#define EUR_CR_CORE_REVISION_MAJOR_SHIFT    16
#define EUR_CR_CORE_REVISION_DESIGNER_MASK  0xFF000000UL
#define EUR_CR_CORE_REVISION_DESIGNER_SHIFT 24
#define EUR_CR_DESIGNER_REV_FIELD1          0x0018
#define EUR_CR_DESIGNER_REV_FIELD1_DESIGNER_REV_FIELD1_MASK 0xFFFFFFFFUL
#define EUR_CR_DESIGNER_REV_FIELD1_DESIGNER_REV_FIELD1_SHIFT 0
#define EUR_CR_DESIGNER_REV_FIELD2          0x001C
#define EUR_CR_DESIGNER_REV_FIELD2_DESIGNER_REV_FIELD2_MASK 0xFFFFFFFFUL
#define EUR_CR_DESIGNER_REV_FIELD2_DESIGNER_REV_FIELD2_SHIFT 0
#define EUR_CR_SOFT_RESET                   0x0080
#define EUR_CR_SOFT_RESET_BIF_RESET_MASK    0x00000001UL
#define EUR_CR_SOFT_RESET_BIF_RESET_SHIFT   0
#define EUR_CR_SOFT_RESET_TWOD_RESET_MASK   0x00000002UL
#define EUR_CR_SOFT_RESET_TWOD_RESET_SHIFT  1
#define EUR_CR_SOFT_RESET_DPM_RESET_MASK    0x00000004UL
#define EUR_CR_SOFT_RESET_DPM_RESET_SHIFT   2
#define EUR_CR_SOFT_RESET_TA_RESET_MASK     0x00000008UL
#define EUR_CR_SOFT_RESET_TA_RESET_SHIFT    3
#define EUR_CR_SOFT_RESET_USE_RESET_MASK    0x00000010UL
#define EUR_CR_SOFT_RESET_USE_RESET_SHIFT   4
#define EUR_CR_SOFT_RESET_ISP_RESET_MASK    0x00000020UL
#define EUR_CR_SOFT_RESET_ISP_RESET_SHIFT   5
#define EUR_CR_SOFT_RESET_TSP_RESET_MASK    0x00000040UL
#define EUR_CR_SOFT_RESET_TSP_RESET_SHIFT   6
#define EUR_CR_EVENT_HOST_ENABLE2           0x0110
#define EUR_CR_EVENT_HOST_ENABLE2_BIF_REQUESTER_FAULT_MASK 0x00000010UL
#define EUR_CR_EVENT_HOST_ENABLE2_BIF_REQUESTER_FAULT_SHIFT 4
#define EUR_CR_EVENT_HOST_ENABLE2_DPM_DHOST_FREE_LOAD_MASK 0x00000008UL
#define EUR_CR_EVENT_HOST_ENABLE2_DPM_DHOST_FREE_LOAD_SHIFT 3
#define EUR_CR_EVENT_HOST_ENABLE2_DPM_HOST_FREE_LOAD_MASK 0x00000004UL
#define EUR_CR_EVENT_HOST_ENABLE2_DPM_HOST_FREE_LOAD_SHIFT 2
#define EUR_CR_EVENT_HOST_ENABLE2_DPM_3D_FREE_LOAD_MASK 0x00000002UL
#define EUR_CR_EVENT_HOST_ENABLE2_DPM_3D_FREE_LOAD_SHIFT 1
#define EUR_CR_EVENT_HOST_ENABLE2_DPM_TA_FREE_LOAD_MASK 0x00000001UL
#define EUR_CR_EVENT_HOST_ENABLE2_DPM_TA_FREE_LOAD_SHIFT 0
#define EUR_CR_EVENT_HOST_CLEAR2            0x0114
#define EUR_CR_EVENT_HOST_CLEAR2_BIF_REQUESTER_FAULT_MASK 0x00000010UL
#define EUR_CR_EVENT_HOST_CLEAR2_BIF_REQUESTER_FAULT_SHIFT 4
#define EUR_CR_EVENT_HOST_CLEAR2_DPM_DHOST_FREE_LOAD_MASK 0x00000008UL
#define EUR_CR_EVENT_HOST_CLEAR2_DPM_DHOST_FREE_LOAD_SHIFT 3
#define EUR_CR_EVENT_HOST_CLEAR2_DPM_HOST_FREE_LOAD_MASK 0x00000004UL
#define EUR_CR_EVENT_HOST_CLEAR2_DPM_HOST_FREE_LOAD_SHIFT 2
#define EUR_CR_EVENT_HOST_CLEAR2_DPM_3D_FREE_LOAD_MASK 0x00000002UL
#define EUR_CR_EVENT_HOST_CLEAR2_DPM_3D_FREE_LOAD_SHIFT 1
#define EUR_CR_EVENT_HOST_CLEAR2_DPM_TA_FREE_LOAD_MASK 0x00000001UL
#define EUR_CR_EVENT_HOST_CLEAR2_DPM_TA_FREE_LOAD_SHIFT 0
#define EUR_CR_EVENT_STATUS2                0x0118
#define EUR_CR_EVENT_STATUS2_BIF_REQUESTER_FAULT_MASK 0x00000010UL
#define EUR_CR_EVENT_STATUS2_BIF_REQUESTER_FAULT_SHIFT 4
#define EUR_CR_EVENT_STATUS2_DPM_DHOST_FREE_LOAD_MASK 0x00000008UL
#define EUR_CR_EVENT_STATUS2_DPM_DHOST_FREE_LOAD_SHIFT 3
#define EUR_CR_EVENT_STATUS2_DPM_HOST_FREE_LOAD_MASK 0x00000004UL
#define EUR_CR_EVENT_STATUS2_DPM_HOST_FREE_LOAD_SHIFT 2
#define EUR_CR_EVENT_STATUS2_DPM_3D_FREE_LOAD_MASK 0x00000002UL
#define EUR_CR_EVENT_STATUS2_DPM_3D_FREE_LOAD_SHIFT 1
#define EUR_CR_EVENT_STATUS2_DPM_TA_FREE_LOAD_MASK 0x00000001UL
#define EUR_CR_EVENT_STATUS2_DPM_TA_FREE_LOAD_SHIFT 0
#define EUR_CR_EVENT_STATUS                 0x012CUL
#define EUR_CR_EVENT_STATUS_MASTER_INTERRUPT_MASK 0x80000000UL
#define EUR_CR_EVENT_STATUS_MASTER_INTERRUPT_SHIFT 31
#define EUR_CR_EVENT_STATUS_TIMER_MASK      0x20000000UL
#define EUR_CR_EVENT_STATUS_TIMER_SHIFT     29
#define EUR_CR_EVENT_STATUS_TA_DPM_FAULT_MASK 0x10000000UL
#define EUR_CR_EVENT_STATUS_TA_DPM_FAULT_SHIFT 28
#define EUR_CR_EVENT_STATUS_TWOD_COMPLETE_MASK 0x08000000UL
#define EUR_CR_EVENT_STATUS_TWOD_COMPLETE_SHIFT 27
#define EUR_CR_EVENT_STATUS_MADD_CACHE_INVALCOMPLETE_MASK 0x04000000UL
#define EUR_CR_EVENT_STATUS_MADD_CACHE_INVALCOMPLETE_SHIFT 26
#define EUR_CR_EVENT_STATUS_DPM_OUT_OF_MEMORY_ZLS_MASK 0x02000000UL
#define EUR_CR_EVENT_STATUS_DPM_OUT_OF_MEMORY_ZLS_SHIFT 25
#define EUR_CR_EVENT_STATUS_DPM_TA_MEM_FREE_MASK 0x01000000UL
#define EUR_CR_EVENT_STATUS_DPM_TA_MEM_FREE_SHIFT 24
#define EUR_CR_EVENT_STATUS_ISP_END_TILE_MASK 0x00800000UL
#define EUR_CR_EVENT_STATUS_ISP_END_TILE_SHIFT 23
#define EUR_CR_EVENT_STATUS_DPM_INITEND_MASK 0x00400000UL
#define EUR_CR_EVENT_STATUS_DPM_INITEND_SHIFT 22
#define EUR_CR_EVENT_STATUS_OTPM_LOADED_MASK 0x00200000UL
#define EUR_CR_EVENT_STATUS_OTPM_LOADED_SHIFT 21
#define EUR_CR_EVENT_STATUS_OTPM_INV_MASK   0x00100000UL
#define EUR_CR_EVENT_STATUS_OTPM_INV_SHIFT  20
#define EUR_CR_EVENT_STATUS_OTPM_FLUSHED_MASK 0x00080000UL
#define EUR_CR_EVENT_STATUS_OTPM_FLUSHED_SHIFT 19
#define EUR_CR_EVENT_STATUS_PIXELBE_END_RENDER_MASK 0x00040000UL
#define EUR_CR_EVENT_STATUS_PIXELBE_END_RENDER_SHIFT 18
#define EUR_CR_EVENT_STATUS_ISP_HALT_MASK   0x00020000UL
#define EUR_CR_EVENT_STATUS_ISP_HALT_SHIFT  17
#define EUR_CR_EVENT_STATUS_ISP_VISIBILITY_FAIL_MASK 0x00010000UL
#define EUR_CR_EVENT_STATUS_ISP_VISIBILITY_FAIL_SHIFT 16
#define EUR_CR_EVENT_STATUS_BREAKPOINT_MASK 0x00008000UL
#define EUR_CR_EVENT_STATUS_BREAKPOINT_SHIFT 15
#define EUR_CR_EVENT_STATUS_SW_EVENT_MASK   0x00004000UL
#define EUR_CR_EVENT_STATUS_SW_EVENT_SHIFT  14
#define EUR_CR_EVENT_STATUS_TA_FINISHED_MASK 0x00002000UL
#define EUR_CR_EVENT_STATUS_TA_FINISHED_SHIFT 13
#define EUR_CR_EVENT_STATUS_TA_TERMINATE_MASK 0x00001000UL
#define EUR_CR_EVENT_STATUS_TA_TERMINATE_SHIFT 12
#define EUR_CR_EVENT_STATUS_TPC_CLEAR_MASK  0x00000800UL
#define EUR_CR_EVENT_STATUS_TPC_CLEAR_SHIFT 11
#define EUR_CR_EVENT_STATUS_TPC_FLUSH_MASK  0x00000400UL
#define EUR_CR_EVENT_STATUS_TPC_FLUSH_SHIFT 10
#define EUR_CR_EVENT_STATUS_DPM_CONTROL_CLEAR_MASK 0x00000200UL
#define EUR_CR_EVENT_STATUS_DPM_CONTROL_CLEAR_SHIFT 9
#define EUR_CR_EVENT_STATUS_DPM_CONTROL_LOAD_MASK 0x00000100UL
#define EUR_CR_EVENT_STATUS_DPM_CONTROL_LOAD_SHIFT 8
#define EUR_CR_EVENT_STATUS_DPM_CONTROL_STORE_MASK 0x00000080UL
#define EUR_CR_EVENT_STATUS_DPM_CONTROL_STORE_SHIFT 7
#define EUR_CR_EVENT_STATUS_DPM_STATE_CLEAR_MASK 0x00000040UL
#define EUR_CR_EVENT_STATUS_DPM_STATE_CLEAR_SHIFT 6
#define EUR_CR_EVENT_STATUS_DPM_STATE_LOAD_MASK 0x00000020UL
#define EUR_CR_EVENT_STATUS_DPM_STATE_LOAD_SHIFT 5
#define EUR_CR_EVENT_STATUS_DPM_STATE_STORE_MASK 0x00000010UL
#define EUR_CR_EVENT_STATUS_DPM_STATE_STORE_SHIFT 4
#define EUR_CR_EVENT_STATUS_DPM_REACHED_MEM_THRESH_MASK 0x00000008UL
#define EUR_CR_EVENT_STATUS_DPM_REACHED_MEM_THRESH_SHIFT 3
#define EUR_CR_EVENT_STATUS_DPM_OUT_OF_MEMORY_GBL_MASK 0x00000004UL
#define EUR_CR_EVENT_STATUS_DPM_OUT_OF_MEMORY_GBL_SHIFT 2
#define EUR_CR_EVENT_STATUS_DPM_OUT_OF_MEMORY_MT_MASK 0x00000002UL
#define EUR_CR_EVENT_STATUS_DPM_OUT_OF_MEMORY_MT_SHIFT 1
#define EUR_CR_EVENT_STATUS_DPM_3D_MEM_FREE_MASK 0x00000001UL
#define EUR_CR_EVENT_STATUS_DPM_3D_MEM_FREE_SHIFT 0
#define EUR_CR_EVENT_HOST_ENABLE            0x0130
#define EUR_CR_EVENT_HOST_ENABLE_MASTER_INTERRUPT_MASK 0x80000000UL
#define EUR_CR_EVENT_HOST_ENABLE_MASTER_INTERRUPT_SHIFT 31
#define EUR_CR_EVENT_HOST_ENABLE_TIMER_MASK 0x20000000UL
#define EUR_CR_EVENT_HOST_ENABLE_TIMER_SHIFT 29
#define EUR_CR_EVENT_HOST_ENABLE_TA_DPM_FAULT_MASK 0x10000000UL
#define EUR_CR_EVENT_HOST_ENABLE_TA_DPM_FAULT_SHIFT 28
#define EUR_CR_EVENT_HOST_ENABLE_TWOD_COMPLETE_MASK 0x08000000UL
#define EUR_CR_EVENT_HOST_ENABLE_TWOD_COMPLETE_SHIFT 27
#define EUR_CR_EVENT_HOST_ENABLE_MADD_CACHE_INVALCOMPLETE_MASK 0x04000000UL
#define EUR_CR_EVENT_HOST_ENABLE_MADD_CACHE_INVALCOMPLETE_SHIFT 26
#define EUR_CR_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_ZLS_MASK 0x02000000UL
#define EUR_CR_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_ZLS_SHIFT 25
#define EUR_CR_EVENT_HOST_ENABLE_DPM_TA_MEM_FREE_MASK 0x01000000UL
#define EUR_CR_EVENT_HOST_ENABLE_DPM_TA_MEM_FREE_SHIFT 24
#define EUR_CR_EVENT_HOST_ENABLE_ISP_END_TILE_MASK 0x00800000UL
#define EUR_CR_EVENT_HOST_ENABLE_ISP_END_TILE_SHIFT 23
#define EUR_CR_EVENT_HOST_ENABLE_DPM_INITEND_MASK 0x00400000UL
#define EUR_CR_EVENT_HOST_ENABLE_DPM_INITEND_SHIFT 22
#define EUR_CR_EVENT_HOST_ENABLE_OTPM_LOADED_MASK 0x00200000UL
#define EUR_CR_EVENT_HOST_ENABLE_OTPM_LOADED_SHIFT 21
#define EUR_CR_EVENT_HOST_ENABLE_OTPM_INV_MASK 0x00100000UL
#define EUR_CR_EVENT_HOST_ENABLE_OTPM_INV_SHIFT 20
#define EUR_CR_EVENT_HOST_ENABLE_OTPM_FLUSHED_MASK 0x00080000UL
#define EUR_CR_EVENT_HOST_ENABLE_OTPM_FLUSHED_SHIFT 19
#define EUR_CR_EVENT_HOST_ENABLE_PIXELBE_END_RENDER_MASK 0x00040000UL
#define EUR_CR_EVENT_HOST_ENABLE_PIXELBE_END_RENDER_SHIFT 18
#define EUR_CR_EVENT_HOST_ENABLE_ISP_HALT_MASK 0x00020000UL
#define EUR_CR_EVENT_HOST_ENABLE_ISP_HALT_SHIFT 17
#define EUR_CR_EVENT_HOST_ENABLE_ISP_VISIBILITY_FAIL_MASK 0x00010000UL
#define EUR_CR_EVENT_HOST_ENABLE_ISP_VISIBILITY_FAIL_SHIFT 16
#define EUR_CR_EVENT_HOST_ENABLE_BREAKPOINT_MASK 0x00008000UL
#define EUR_CR_EVENT_HOST_ENABLE_BREAKPOINT_SHIFT 15
#define EUR_CR_EVENT_HOST_ENABLE_SW_EVENT_MASK 0x00004000UL
#define EUR_CR_EVENT_HOST_ENABLE_SW_EVENT_SHIFT 14
#define EUR_CR_EVENT_HOST_ENABLE_TA_FINISHED_MASK 0x00002000UL
#define EUR_CR_EVENT_HOST_ENABLE_TA_FINISHED_SHIFT 13
#define EUR_CR_EVENT_HOST_ENABLE_TA_TERMINATE_MASK 0x00001000UL
#define EUR_CR_EVENT_HOST_ENABLE_TA_TERMINATE_SHIFT 12
#define EUR_CR_EVENT_HOST_ENABLE_TPC_CLEAR_MASK 0x00000800UL
#define EUR_CR_EVENT_HOST_ENABLE_TPC_CLEAR_SHIFT 11
#define EUR_CR_EVENT_HOST_ENABLE_TPC_FLUSH_MASK 0x00000400UL
#define EUR_CR_EVENT_HOST_ENABLE_TPC_FLUSH_SHIFT 10
#define EUR_CR_EVENT_HOST_ENABLE_DPM_CONTROL_CLEAR_MASK 0x00000200UL
#define EUR_CR_EVENT_HOST_ENABLE_DPM_CONTROL_CLEAR_SHIFT 9
#define EUR_CR_EVENT_HOST_ENABLE_DPM_CONTROL_LOAD_MASK 0x00000100UL
#define EUR_CR_EVENT_HOST_ENABLE_DPM_CONTROL_LOAD_SHIFT 8
#define EUR_CR_EVENT_HOST_ENABLE_DPM_CONTROL_STORE_MASK 0x00000080UL
#define EUR_CR_EVENT_HOST_ENABLE_DPM_CONTROL_STORE_SHIFT 7
#define EUR_CR_EVENT_HOST_ENABLE_DPM_STATE_CLEAR_MASK 0x00000040UL
#define EUR_CR_EVENT_HOST_ENABLE_DPM_STATE_CLEAR_SHIFT 6
#define EUR_CR_EVENT_HOST_ENABLE_DPM_STATE_LOAD_MASK 0x00000020UL
#define EUR_CR_EVENT_HOST_ENABLE_DPM_STATE_LOAD_SHIFT 5
#define EUR_CR_EVENT_HOST_ENABLE_DPM_STATE_STORE_MASK 0x00000010UL
#define EUR_CR_EVENT_HOST_ENABLE_DPM_STATE_STORE_SHIFT 4
#define EUR_CR_EVENT_HOST_ENABLE_DPM_REACHED_MEM_THRESH_MASK 0x00000008UL
#define EUR_CR_EVENT_HOST_ENABLE_DPM_REACHED_MEM_THRESH_SHIFT 3
#define EUR_CR_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_GBL_MASK 0x00000004UL
#define EUR_CR_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_GBL_SHIFT 2
#define EUR_CR_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_MT_MASK 0x00000002UL
#define EUR_CR_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_MT_SHIFT 1
#define EUR_CR_EVENT_HOST_ENABLE_DPM_3D_MEM_FREE_MASK 0x00000001UL
#define EUR_CR_EVENT_HOST_ENABLE_DPM_3D_MEM_FREE_SHIFT 0
#define EUR_CR_EVENT_HOST_CLEAR             0x0134
#define EUR_CR_EVENT_HOST_CLEAR_MASTER_INTERRUPT_MASK 0x80000000UL
#define EUR_CR_EVENT_HOST_CLEAR_MASTER_INTERRUPT_SHIFT 31
#define EUR_CR_EVENT_HOST_CLEAR_TIMER_MASK  0x20000000UL
#define EUR_CR_EVENT_HOST_CLEAR_TIMER_SHIFT 29
#define EUR_CR_EVENT_HOST_CLEAR_TA_DPM_FAULT_MASK 0x10000000UL
#define EUR_CR_EVENT_HOST_CLEAR_TA_DPM_FAULT_SHIFT 28
#define EUR_CR_EVENT_HOST_CLEAR_TWOD_COMPLETE_MASK 0x08000000UL
#define EUR_CR_EVENT_HOST_CLEAR_TWOD_COMPLETE_SHIFT 27
#define EUR_CR_EVENT_HOST_CLEAR_MADD_CACHE_INVALCOMPLETE_MASK 0x04000000UL
#define EUR_CR_EVENT_HOST_CLEAR_MADD_CACHE_INVALCOMPLETE_SHIFT 26
#define EUR_CR_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_ZLS_MASK 0x02000000UL
#define EUR_CR_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_ZLS_SHIFT 25
#define EUR_CR_EVENT_HOST_CLEAR_DPM_TA_MEM_FREE_MASK 0x01000000UL
#define EUR_CR_EVENT_HOST_CLEAR_DPM_TA_MEM_FREE_SHIFT 24
#define EUR_CR_EVENT_HOST_CLEAR_ISP_END_TILE_MASK 0x00800000UL
#define EUR_CR_EVENT_HOST_CLEAR_ISP_END_TILE_SHIFT 23
#define EUR_CR_EVENT_HOST_CLEAR_DPM_INITEND_MASK 0x00400000UL
#define EUR_CR_EVENT_HOST_CLEAR_DPM_INITEND_SHIFT 22
#define EUR_CR_EVENT_HOST_CLEAR_OTPM_LOADED_MASK 0x00200000UL
#define EUR_CR_EVENT_HOST_CLEAR_OTPM_LOADED_SHIFT 21
#define EUR_CR_EVENT_HOST_CLEAR_OTPM_INV_MASK 0x00100000UL
#define EUR_CR_EVENT_HOST_CLEAR_OTPM_INV_SHIFT 20
#define EUR_CR_EVENT_HOST_CLEAR_OTPM_FLUSHED_MASK 0x00080000UL
#define EUR_CR_EVENT_HOST_CLEAR_OTPM_FLUSHED_SHIFT 19
#define EUR_CR_EVENT_HOST_CLEAR_PIXELBE_END_RENDER_MASK 0x00040000UL
#define EUR_CR_EVENT_HOST_CLEAR_PIXELBE_END_RENDER_SHIFT 18
#define EUR_CR_EVENT_HOST_CLEAR_ISP_HALT_MASK 0x00020000UL
#define EUR_CR_EVENT_HOST_CLEAR_ISP_HALT_SHIFT 17
#define EUR_CR_EVENT_HOST_CLEAR_ISP_VISIBILITY_FAIL_MASK 0x00010000UL
#define EUR_CR_EVENT_HOST_CLEAR_ISP_VISIBILITY_FAIL_SHIFT 16
#define EUR_CR_EVENT_HOST_CLEAR_BREAKPOINT_MASK 0x00008000UL
#define EUR_CR_EVENT_HOST_CLEAR_BREAKPOINT_SHIFT 15
#define EUR_CR_EVENT_HOST_CLEAR_SW_EVENT_MASK 0x00004000UL
#define EUR_CR_EVENT_HOST_CLEAR_SW_EVENT_SHIFT 14
#define EUR_CR_EVENT_HOST_CLEAR_TA_FINISHED_MASK 0x00002000UL
#define EUR_CR_EVENT_HOST_CLEAR_TA_FINISHED_SHIFT 13
#define EUR_CR_EVENT_HOST_CLEAR_TA_TERMINATE_MASK 0x00001000UL
#define EUR_CR_EVENT_HOST_CLEAR_TA_TERMINATE_SHIFT 12
#define EUR_CR_EVENT_HOST_CLEAR_TPC_CLEAR_MASK 0x00000800UL
#define EUR_CR_EVENT_HOST_CLEAR_TPC_CLEAR_SHIFT 11
#define EUR_CR_EVENT_HOST_CLEAR_TPC_FLUSH_MASK 0x00000400UL
#define EUR_CR_EVENT_HOST_CLEAR_TPC_FLUSH_SHIFT 10
#define EUR_CR_EVENT_HOST_CLEAR_DPM_CONTROL_CLEAR_MASK 0x00000200UL
#define EUR_CR_EVENT_HOST_CLEAR_DPM_CONTROL_CLEAR_SHIFT 9
#define EUR_CR_EVENT_HOST_CLEAR_DPM_CONTROL_LOAD_MASK 0x00000100UL
#define EUR_CR_EVENT_HOST_CLEAR_DPM_CONTROL_LOAD_SHIFT 8
#define EUR_CR_EVENT_HOST_CLEAR_DPM_CONTROL_STORE_MASK 0x00000080UL
#define EUR_CR_EVENT_HOST_CLEAR_DPM_CONTROL_STORE_SHIFT 7
#define EUR_CR_EVENT_HOST_CLEAR_DPM_STATE_CLEAR_MASK 0x00000040UL
#define EUR_CR_EVENT_HOST_CLEAR_DPM_STATE_CLEAR_SHIFT 6
#define EUR_CR_EVENT_HOST_CLEAR_DPM_STATE_LOAD_MASK 0x00000020UL
#define EUR_CR_EVENT_HOST_CLEAR_DPM_STATE_LOAD_SHIFT 5
#define EUR_CR_EVENT_HOST_CLEAR_DPM_STATE_STORE_MASK 0x00000010UL
#define EUR_CR_EVENT_HOST_CLEAR_DPM_STATE_STORE_SHIFT 4
#define EUR_CR_EVENT_HOST_CLEAR_DPM_REACHED_MEM_THRESH_MASK 0x00000008UL
#define EUR_CR_EVENT_HOST_CLEAR_DPM_REACHED_MEM_THRESH_SHIFT 3
#define EUR_CR_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_GBL_MASK 0x00000004UL
#define EUR_CR_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_GBL_SHIFT 2
#define EUR_CR_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_MT_MASK 0x00000002UL
#define EUR_CR_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_MT_SHIFT 1
#define EUR_CR_EVENT_HOST_CLEAR_DPM_3D_MEM_FREE_MASK 0x00000001UL
#define EUR_CR_EVENT_HOST_CLEAR_DPM_3D_MEM_FREE_SHIFT 0
#define EUR_CR_PDS                          0x0ABC
#define EUR_CR_PDS_DOUT_TIMEOUT_DISABLE_MASK 0x00000040UL
#define EUR_CR_PDS_DOUT_TIMEOUT_DISABLE_SHIFT 6
#define EUR_CR_PDS_EXEC_BASE                0x0AB8
#define EUR_CR_PDS_EXEC_BASE_ADDR_MASK      0xFFF00000UL
#define EUR_CR_PDS_EXEC_BASE_ADDR_SHIFT     20
#define EUR_CR_EVENT_KICKER                 0x0AC4
#define EUR_CR_EVENT_KICKER_ADDRESS_MASK    0xFFFFFFF0UL
#define EUR_CR_EVENT_KICKER_ADDRESS_SHIFT   4
#define EUR_CR_EVENT_KICK                   0x0AC8
#define EUR_CR_EVENT_KICK_NOW_MASK          0x00000001UL
#define EUR_CR_EVENT_KICK_NOW_SHIFT         0
#define EUR_CR_EVENT_TIMER                  0x0ACC
#define EUR_CR_EVENT_TIMER_ENABLE_MASK      0x01000000UL
#define EUR_CR_EVENT_TIMER_ENABLE_SHIFT     24
#define EUR_CR_EVENT_TIMER_VALUE_MASK       0x00FFFFFFUL
#define EUR_CR_EVENT_TIMER_VALUE_SHIFT      0
#define EUR_CR_PDS_INV0                     0x0AD0
#define EUR_CR_PDS_INV0_DSC_MASK            0x00000001UL
#define EUR_CR_PDS_INV0_DSC_SHIFT           0
#define EUR_CR_PDS_INV1                     0x0AD4
#define EUR_CR_PDS_INV1_DSC_MASK            0x00000001UL
#define EUR_CR_PDS_INV1_DSC_SHIFT           0
#define EUR_CR_PDS_INV2                     0x0AD8
#define EUR_CR_PDS_INV2_DSC_MASK            0x00000001UL
#define EUR_CR_PDS_INV2_DSC_SHIFT           0
#define EUR_CR_PDS_INV3                     0x0ADC
#define EUR_CR_PDS_INV3_DSC_MASK            0x00000001UL
#define EUR_CR_PDS_INV3_DSC_SHIFT           0
#define EUR_CR_PDS_INV_CSC                  0x0AE0
#define EUR_CR_PDS_INV_CSC_KICK_MASK        0x00000001UL
#define EUR_CR_PDS_INV_CSC_KICK_SHIFT       0
#define EUR_CR_PDS_PC_BASE                  0x0B2C
#define EUR_CR_PDS_PC_BASE_ADDRESS_MASK     0x3FFFFFFFUL
#define EUR_CR_PDS_PC_BASE_ADDRESS_SHIFT    0
#define EUR_CR_BIF_CTRL                     0x0C00
#define EUR_CR_BIF_CTRL_NOREORDER_MASK      0x00000001UL
#define EUR_CR_BIF_CTRL_NOREORDER_SHIFT     0
#define EUR_CR_BIF_CTRL_PAUSE_MASK          0x00000002UL
#define EUR_CR_BIF_CTRL_PAUSE_SHIFT         1
#define EUR_CR_BIF_CTRL_FLUSH_MASK          0x00000004UL
#define EUR_CR_BIF_CTRL_FLUSH_SHIFT         2
#define EUR_CR_BIF_CTRL_INVALDC_MASK        0x00000008UL
#define EUR_CR_BIF_CTRL_INVALDC_SHIFT       3
#define EUR_CR_BIF_CTRL_CLEAR_FAULT_MASK    0x00000010UL
#define EUR_CR_BIF_CTRL_CLEAR_FAULT_SHIFT   4
#define EUR_CR_BIF_CTRL_MMU_BYPASS_CACHE_MASK 0x00000100UL
#define EUR_CR_BIF_CTRL_MMU_BYPASS_CACHE_SHIFT 8
#define EUR_CR_BIF_CTRL_MMU_BYPASS_VDM_MASK 0x00000200UL
#define EUR_CR_BIF_CTRL_MMU_BYPASS_VDM_SHIFT 9
#define EUR_CR_BIF_CTRL_MMU_BYPASS_TE_MASK  0x00000400UL
#define EUR_CR_BIF_CTRL_MMU_BYPASS_TE_SHIFT 10
#define EUR_CR_BIF_CTRL_MMU_BYPASS_TWOD_MASK 0x00000800UL
#define EUR_CR_BIF_CTRL_MMU_BYPASS_TWOD_SHIFT 11
#define EUR_CR_BIF_CTRL_MMU_BYPASS_PBE_MASK 0x00001000UL
#define EUR_CR_BIF_CTRL_MMU_BYPASS_PBE_SHIFT 12
#define EUR_CR_BIF_CTRL_MMU_BYPASS_TSPP_MASK 0x00002000UL
#define EUR_CR_BIF_CTRL_MMU_BYPASS_TSPP_SHIFT 13
#define EUR_CR_BIF_CTRL_MMU_BYPASS_ISP_MASK 0x00004000UL
#define EUR_CR_BIF_CTRL_MMU_BYPASS_ISP_SHIFT 14
#define EUR_CR_BIF_CTRL_MMU_BYPASS_USE_MASK 0x00008000UL
#define EUR_CR_BIF_CTRL_MMU_BYPASS_USE_SHIFT 15
#define EUR_CR_BIF_CTRL_MMU_BYPASS_HOST_MASK 0x00010000UL
#define EUR_CR_BIF_CTRL_MMU_BYPASS_HOST_SHIFT 16
#define EUR_CR_BIF_INT_STAT                 0x0C04
#define EUR_CR_BIF_INT_STAT_FAULT_MASK      0x00003FFFUL
#define EUR_CR_BIF_INT_STAT_FAULT_SHIFT     0
#define EUR_CR_BIF_INT_STAT_PF_N_RW_MASK    0x00004000UL
#define EUR_CR_BIF_INT_STAT_PF_N_RW_SHIFT   14
#define EUR_CR_BIF_FAULT                    0x0C08
#define EUR_CR_BIF_FAULT_ADDR_MASK          0xFFFFF000UL
#define EUR_CR_BIF_FAULT_ADDR_SHIFT         12
#define EUR_CR_BIF_TILE0                    0x0C0C
#define EUR_CR_BIF_TILE0_MIN_ADDRESS_MASK   0x00000FFFUL
#define EUR_CR_BIF_TILE0_MIN_ADDRESS_SHIFT  0
#define EUR_CR_BIF_TILE0_MAX_ADDRESS_MASK   0x00FFF000UL
#define EUR_CR_BIF_TILE0_MAX_ADDRESS_SHIFT  12
#define EUR_CR_BIF_TILE0_CFG_MASK           0x0F000000UL
#define EUR_CR_BIF_TILE0_CFG_SHIFT          24
#define EUR_CR_BIF_TILE1                    0x0C10
#define EUR_CR_BIF_TILE1_MIN_ADDRESS_MASK   0x00000FFFUL
#define EUR_CR_BIF_TILE1_MIN_ADDRESS_SHIFT  0
#define EUR_CR_BIF_TILE1_MAX_ADDRESS_MASK   0x00FFF000UL
#define EUR_CR_BIF_TILE1_MAX_ADDRESS_SHIFT  12
#define EUR_CR_BIF_TILE1_CFG_MASK           0x0F000000UL
#define EUR_CR_BIF_TILE1_CFG_SHIFT          24
#define EUR_CR_BIF_TILE2                    0x0C14
#define EUR_CR_BIF_TILE2_MIN_ADDRESS_MASK   0x00000FFFUL
#define EUR_CR_BIF_TILE2_MIN_ADDRESS_SHIFT  0
#define EUR_CR_BIF_TILE2_MAX_ADDRESS_MASK   0x00FFF000UL
#define EUR_CR_BIF_TILE2_MAX_ADDRESS_SHIFT  12
#define EUR_CR_BIF_TILE2_CFG_MASK           0x0F000000UL
#define EUR_CR_BIF_TILE2_CFG_SHIFT          24
#define EUR_CR_BIF_TILE3                    0x0C18
#define EUR_CR_BIF_TILE3_MIN_ADDRESS_MASK   0x00000FFFUL
#define EUR_CR_BIF_TILE3_MIN_ADDRESS_SHIFT  0
#define EUR_CR_BIF_TILE3_MAX_ADDRESS_MASK   0x00FFF000UL
#define EUR_CR_BIF_TILE3_MAX_ADDRESS_SHIFT  12
#define EUR_CR_BIF_TILE3_CFG_MASK           0x0F000000UL
#define EUR_CR_BIF_TILE3_CFG_SHIFT          24
#define EUR_CR_BIF_TILE4                    0x0C1C
#define EUR_CR_BIF_TILE4_MIN_ADDRESS_MASK   0x00000FFFUL
#define EUR_CR_BIF_TILE4_MIN_ADDRESS_SHIFT  0
#define EUR_CR_BIF_TILE4_MAX_ADDRESS_MASK   0x00FFF000UL
#define EUR_CR_BIF_TILE4_MAX_ADDRESS_SHIFT  12
#define EUR_CR_BIF_TILE4_CFG_MASK           0x0F000000UL
#define EUR_CR_BIF_TILE4_CFG_SHIFT          24
#define EUR_CR_BIF_TILE5                    0x0C20
#define EUR_CR_BIF_TILE5_MIN_ADDRESS_MASK   0x00000FFFUL
#define EUR_CR_BIF_TILE5_MIN_ADDRESS_SHIFT  0
#define EUR_CR_BIF_TILE5_MAX_ADDRESS_MASK   0x00FFF000UL
#define EUR_CR_BIF_TILE5_MAX_ADDRESS_SHIFT  12
#define EUR_CR_BIF_TILE5_CFG_MASK           0x0F000000UL
#define EUR_CR_BIF_TILE5_CFG_SHIFT          24
#define EUR_CR_BIF_TILE6                    0x0C24
#define EUR_CR_BIF_TILE6_MIN_ADDRESS_MASK   0x00000FFFUL
#define EUR_CR_BIF_TILE6_MIN_ADDRESS_SHIFT  0
#define EUR_CR_BIF_TILE6_MAX_ADDRESS_MASK   0x00FFF000UL
#define EUR_CR_BIF_TILE6_MAX_ADDRESS_SHIFT  12
#define EUR_CR_BIF_TILE6_CFG_MASK           0x0F000000UL
#define EUR_CR_BIF_TILE6_CFG_SHIFT          24
#define EUR_CR_BIF_TILE7                    0x0C28
#define EUR_CR_BIF_TILE7_MIN_ADDRESS_MASK   0x00000FFFUL
#define EUR_CR_BIF_TILE7_MIN_ADDRESS_SHIFT  0
#define EUR_CR_BIF_TILE7_MAX_ADDRESS_MASK   0x00FFF000UL
#define EUR_CR_BIF_TILE7_MAX_ADDRESS_SHIFT  12
#define EUR_CR_BIF_TILE7_CFG_MASK           0x0F000000UL
#define EUR_CR_BIF_TILE7_CFG_SHIFT          24
#define EUR_CR_BIF_TILE8                    0x0C2C
#define EUR_CR_BIF_TILE8_MIN_ADDRESS_MASK   0x00000FFFUL
#define EUR_CR_BIF_TILE8_MIN_ADDRESS_SHIFT  0
#define EUR_CR_BIF_TILE8_MAX_ADDRESS_MASK   0x00FFF000UL
#define EUR_CR_BIF_TILE8_MAX_ADDRESS_SHIFT  12
#define EUR_CR_BIF_TILE8_CFG_MASK           0x0F000000UL
#define EUR_CR_BIF_TILE8_CFG_SHIFT          24
#define EUR_CR_BIF_TILE9                    0x0C30
#define EUR_CR_BIF_TILE9_MIN_ADDRESS_MASK   0x00000FFFUL
#define EUR_CR_BIF_TILE9_MIN_ADDRESS_SHIFT  0
#define EUR_CR_BIF_TILE9_MAX_ADDRESS_MASK   0x00FFF000UL
#define EUR_CR_BIF_TILE9_MAX_ADDRESS_SHIFT  12
#define EUR_CR_BIF_TILE9_CFG_MASK           0x0F000000UL
#define EUR_CR_BIF_TILE9_CFG_SHIFT          24
#define EUR_CR_BIF_DIR_LIST_BASE1           0x0C38
#define EUR_CR_BIF_DIR_LIST_BASE1_ADDR_MASK 0xFFFFF000UL
#define EUR_CR_BIF_DIR_LIST_BASE1_ADDR_SHIFT 12
#define EUR_CR_BIF_DIR_LIST_BASE2           0x0C3C
#define EUR_CR_BIF_DIR_LIST_BASE2_ADDR_MASK 0xFFFFF000UL
#define EUR_CR_BIF_DIR_LIST_BASE2_ADDR_SHIFT 12
#define EUR_CR_BIF_DIR_LIST_BASE3           0x0C40
#define EUR_CR_BIF_DIR_LIST_BASE3_ADDR_MASK 0xFFFFF000UL
#define EUR_CR_BIF_DIR_LIST_BASE3_ADDR_SHIFT 12
#define EUR_CR_BIF_DIR_LIST_BASE4           0x0C44
#define EUR_CR_BIF_DIR_LIST_BASE4_ADDR_MASK 0xFFFFF000UL
#define EUR_CR_BIF_DIR_LIST_BASE4_ADDR_SHIFT 12
#define EUR_CR_BIF_DIR_LIST_BASE5           0x0C48
#define EUR_CR_BIF_DIR_LIST_BASE5_ADDR_MASK 0xFFFFF000UL
#define EUR_CR_BIF_DIR_LIST_BASE5_ADDR_SHIFT 12
#define EUR_CR_BIF_DIR_LIST_BASE6           0x0C4C
#define EUR_CR_BIF_DIR_LIST_BASE6_ADDR_MASK 0xFFFFF000UL
#define EUR_CR_BIF_DIR_LIST_BASE6_ADDR_SHIFT 12
#define EUR_CR_BIF_DIR_LIST_BASE7           0x0C50
#define EUR_CR_BIF_DIR_LIST_BASE7_ADDR_MASK 0xFFFFF000UL
#define EUR_CR_BIF_DIR_LIST_BASE7_ADDR_SHIFT 12
#define EUR_CR_BIF_DIR_LIST_BASE8           0x0C54
#define EUR_CR_BIF_DIR_LIST_BASE8_ADDR_MASK 0xFFFFF000UL
#define EUR_CR_BIF_DIR_LIST_BASE8_ADDR_SHIFT 12
#define EUR_CR_BIF_DIR_LIST_BASE9           0x0C58
#define EUR_CR_BIF_DIR_LIST_BASE9_ADDR_MASK 0xFFFFF000UL
#define EUR_CR_BIF_DIR_LIST_BASE9_ADDR_SHIFT 12
#define EUR_CR_BIF_DIR_LIST_BASE10          0x0C5C
#define EUR_CR_BIF_DIR_LIST_BASE10_ADDR_MASK 0xFFFFF000UL
#define EUR_CR_BIF_DIR_LIST_BASE10_ADDR_SHIFT 12
#define EUR_CR_BIF_DIR_LIST_BASE11          0x0C60
#define EUR_CR_BIF_DIR_LIST_BASE11_ADDR_MASK 0xFFFFF000UL
#define EUR_CR_BIF_DIR_LIST_BASE11_ADDR_SHIFT 12
#define EUR_CR_BIF_DIR_LIST_BASE12          0x0C64
#define EUR_CR_BIF_DIR_LIST_BASE12_ADDR_MASK 0xFFFFF000UL
#define EUR_CR_BIF_DIR_LIST_BASE12_ADDR_SHIFT 12
#define EUR_CR_BIF_DIR_LIST_BASE13          0x0C68
#define EUR_CR_BIF_DIR_LIST_BASE13_ADDR_MASK 0xFFFFF000UL
#define EUR_CR_BIF_DIR_LIST_BASE13_ADDR_SHIFT 12
#define EUR_CR_BIF_DIR_LIST_BASE14          0x0C6C
#define EUR_CR_BIF_DIR_LIST_BASE14_ADDR_MASK 0xFFFFF000UL
#define EUR_CR_BIF_DIR_LIST_BASE14_ADDR_SHIFT 12
#define EUR_CR_BIF_DIR_LIST_BASE15          0x0C70
#define EUR_CR_BIF_DIR_LIST_BASE15_ADDR_MASK 0xFFFFF000UL
#define EUR_CR_BIF_DIR_LIST_BASE15_ADDR_SHIFT 12
#define EUR_CR_BIF_BANK_SET                 0x0C74
#define EUR_CR_BIF_BANK_SET_SELECT_MASK     0x000003FFUL
#define EUR_CR_BIF_BANK_SET_SELECT_SHIFT    0
#define EUR_CR_BIF_BANK0                    0x0C78
#define EUR_CR_BIF_BANK0_INDEX_EDM_MASK     0x0000000FUL
#define EUR_CR_BIF_BANK0_INDEX_EDM_SHIFT    0
#define EUR_CR_BIF_BANK0_INDEX_TA_MASK      0x000000F0UL
#define EUR_CR_BIF_BANK0_INDEX_TA_SHIFT     4
#define EUR_CR_BIF_BANK0_INDEX_HOST_MASK    0x00000F00UL
#define EUR_CR_BIF_BANK0_INDEX_HOST_SHIFT   8
#define EUR_CR_BIF_BANK0_INDEX_3D_MASK      0x0000F000UL
#define EUR_CR_BIF_BANK0_INDEX_3D_SHIFT     12
#define EUR_CR_BIF_BANK0_INDEX_2D_MASK      0x000F0000UL
#define EUR_CR_BIF_BANK0_INDEX_2D_SHIFT     16
#define EUR_CR_BIF_BANK1                    0x0C7C
#define EUR_CR_BIF_BANK1_INDEX_EDM_MASK     0x0000000FUL
#define EUR_CR_BIF_BANK1_INDEX_EDM_SHIFT    0
#define EUR_CR_BIF_BANK1_INDEX_TA_MASK      0x000000F0UL
#define EUR_CR_BIF_BANK1_INDEX_TA_SHIFT     4
#define EUR_CR_BIF_BANK1_INDEX_HOST_MASK    0x00000F00UL
#define EUR_CR_BIF_BANK1_INDEX_HOST_SHIFT   8
#define EUR_CR_BIF_BANK1_INDEX_3D_MASK      0x0000F000UL
#define EUR_CR_BIF_BANK1_INDEX_3D_SHIFT     12
#define EUR_CR_BIF_BANK1_INDEX_2D_MASK      0x000F0000UL
#define EUR_CR_BIF_BANK1_INDEX_2D_SHIFT     16
#define EUR_CR_BIF_ADT_TTE                  0x0C80
#define EUR_CR_BIF_ADT_TTE_VALUE_MASK       0x000000FFUL
#define EUR_CR_BIF_ADT_TTE_VALUE_SHIFT      0
#define EUR_CR_BIF_DIR_LIST_BASE0           0x0C84
#define EUR_CR_BIF_DIR_LIST_BASE0_ADDR_MASK 0xFFFFF000UL
#define EUR_CR_BIF_DIR_LIST_BASE0_ADDR_SHIFT 12
#define EUR_CR_BIF_TWOD_REQ_BASE            0x0C88
#define EUR_CR_BIF_TWOD_REQ_BASE_ADDR_MASK  0xFFF00000UL
#define EUR_CR_BIF_TWOD_REQ_BASE_ADDR_SHIFT 20
#define EUR_CR_BIF_TA_REQ_BASE              0x0C90
#define EUR_CR_BIF_TA_REQ_BASE_ADDR_MASK    0xFFF00000UL
#define EUR_CR_BIF_TA_REQ_BASE_ADDR_SHIFT   20
#define EUR_CR_BIF_MEM_ARB_FLOWRATES_1      0x0C94
#define EUR_CR_BIF_MEM_ARB_FLOWRATES_1_MMU_MASK 0x00000007UL
#define EUR_CR_BIF_MEM_ARB_FLOWRATES_1_MMU_SHIFT 0
#define EUR_CR_BIF_MEM_ARB_FLOWRATES_1_CACHE_MASK 0x00000038UL
#define EUR_CR_BIF_MEM_ARB_FLOWRATES_1_CACHE_SHIFT 3
#define EUR_CR_BIF_MEM_ARB_FLOWRATES_1_VDM_MASK 0x000001C0UL
#define EUR_CR_BIF_MEM_ARB_FLOWRATES_1_VDM_SHIFT 6
#define EUR_CR_BIF_MEM_ARB_FLOWRATES_1_TE_MASK 0x00000E00UL
#define EUR_CR_BIF_MEM_ARB_FLOWRATES_1_TE_SHIFT 9
#define EUR_CR_BIF_MEM_ARB_FLOWRATES_1_TWOD_MASK 0x00007000UL
#define EUR_CR_BIF_MEM_ARB_FLOWRATES_1_TWOD_SHIFT 12
#define EUR_CR_BIF_MEM_ARB_FLOWRATES_1_PBE_MASK 0x00038000UL
#define EUR_CR_BIF_MEM_ARB_FLOWRATES_1_PBE_SHIFT 15
#define EUR_CR_BIF_MEM_ARB_FLOWRATES_2      0x0C98
#define EUR_CR_BIF_MEM_ARB_FLOWRATES_2_HOST_MASK 0x00000007UL
#define EUR_CR_BIF_MEM_ARB_FLOWRATES_2_HOST_SHIFT 0
#define EUR_CR_BIF_MEM_ARB_FLOWRATES_2_USE_MASK 0x00000038UL
#define EUR_CR_BIF_MEM_ARB_FLOWRATES_2_USE_SHIFT 3
#define EUR_CR_BIF_MEM_ARB_FLOWRATES_2_ISP_MASK 0x000001C0UL
#define EUR_CR_BIF_MEM_ARB_FLOWRATES_2_ISP_SHIFT 6
#define EUR_CR_BIF_MEM_ARB_FLOWRATES_2_TSPP_MASK 0x00000E00UL
#define EUR_CR_BIF_MEM_ARB_FLOWRATES_2_TSPP_SHIFT 9
#define EUR_CR_BIF_MEM_ARB_CONFIG           0x0CA0
#define EUR_CR_BIF_MEM_ARB_CONFIG_PAGE_SIZE_MASK 0x0000000FUL
#define EUR_CR_BIF_MEM_ARB_CONFIG_PAGE_SIZE_SHIFT 0
#define EUR_CR_BIF_MEM_ARB_CONFIG_BEST_CNT_MASK 0x00000FF0UL
#define EUR_CR_BIF_MEM_ARB_CONFIG_BEST_CNT_SHIFT 4
#define EUR_CR_BIF_MEM_ARB_CONFIG_TTE_THRESH_MASK 0x00FFF000UL
#define EUR_CR_BIF_MEM_ARB_CONFIG_TTE_THRESH_SHIFT 12
#define EUR_CR_BIF_MEM_REQ_STAT             0x0CA8
#define EUR_CR_BIF_MEM_REQ_STAT_READS_MASK  0x000000FFUL
#define EUR_CR_BIF_MEM_REQ_STAT_READS_SHIFT 0
#define EUR_CR_BIF_3D_REQ_BASE              0x0CAC
#define EUR_CR_BIF_3D_REQ_BASE_ADDR_MASK    0xFFF00000UL
#define EUR_CR_BIF_3D_REQ_BASE_ADDR_SHIFT   20
#define EUR_CR_BIF_ZLS_REQ_BASE             0x0CB0
#define EUR_CR_BIF_ZLS_REQ_BASE_ADDR_MASK   0xFFF00000UL
#define EUR_CR_BIF_ZLS_REQ_BASE_ADDR_SHIFT  20
#define EUR_CR_BIF_BANK_STATUS              0x0CB4
#define EUR_CR_BIF_BANK_STATUS_3D_CURRENT_BANK_MASK 0x00000001UL
#define EUR_CR_BIF_BANK_STATUS_3D_CURRENT_BANK_SHIFT 0
#define EUR_CR_BIF_BANK_STATUS_TA_CURRENT_BANK_MASK 0x00000002UL
#define EUR_CR_BIF_BANK_STATUS_TA_CURRENT_BANK_SHIFT 1
#define EUR_CR_2D_BLIT_STATUS               0x0E04
#define EUR_CR_2D_BLIT_STATUS_COMPLETE_MASK 0x00FFFFFFUL
#define EUR_CR_2D_BLIT_STATUS_COMPLETE_SHIFT 0
#define EUR_CR_2D_BLIT_STATUS_BUSY_MASK     0x01000000UL
#define EUR_CR_2D_BLIT_STATUS_BUSY_SHIFT    24
#define EUR_CR_2D_VIRTUAL_FIFO_0            0x0E10
#define EUR_CR_2D_VIRTUAL_FIFO_0_ENABLE_MASK 0x00000001UL
#define EUR_CR_2D_VIRTUAL_FIFO_0_ENABLE_SHIFT 0
#define EUR_CR_2D_VIRTUAL_FIFO_0_FLOWRATE_MASK 0x0000000EUL
#define EUR_CR_2D_VIRTUAL_FIFO_0_FLOWRATE_SHIFT 1
#define EUR_CR_2D_VIRTUAL_FIFO_0_FLOWRATE_DIV_MASK 0x00000FF0UL
#define EUR_CR_2D_VIRTUAL_FIFO_0_FLOWRATE_DIV_SHIFT 4
#define EUR_CR_2D_VIRTUAL_FIFO_0_FLOWRATE_MUL_MASK 0x0000F000UL
#define EUR_CR_2D_VIRTUAL_FIFO_0_FLOWRATE_MUL_SHIFT 12
#define EUR_CR_2D_VIRTUAL_FIFO_1            0x0E14
#define EUR_CR_2D_VIRTUAL_FIFO_1_MIN_ACC_MASK 0x00000FFFUL
#define EUR_CR_2D_VIRTUAL_FIFO_1_MIN_ACC_SHIFT 0
#define EUR_CR_2D_VIRTUAL_FIFO_1_MAX_ACC_MASK 0x00FFF000UL
#define EUR_CR_2D_VIRTUAL_FIFO_1_MAX_ACC_SHIFT 12
#define EUR_CR_2D_VIRTUAL_FIFO_1_MIN_METRIC_MASK 0xFF000000UL
#define EUR_CR_2D_VIRTUAL_FIFO_1_MIN_METRIC_SHIFT 24
#define EUR_CR_2D_SOCIF                     0x0E18
#define EUR_CR_2D_SOCIF_FREESPACE_MASK      0x000000FFUL
#define EUR_CR_2D_SOCIF_FREESPACE_SHIFT     0
#define EUR_CR_2D_ALPHA						0x0E1C
#define EUR_CR_2D_ALPHA_COMPONENT_ONE_MASK  0x0000FF00UL
#define EUR_CR_2D_ALPHA_COMPONENT_ONE_SHIFT 8
#define EUR_CR_2D_ALPHA_COMPONENT_ZERO_MASK 0x000000FFUL
#define EUR_CR_2D_ALPHA_COMPONENT_ZERO_SHIFT 0
#define EUR_CR_USE_CODE_BASE(X)     (0x0A0C + (4 * (X)))
#define EUR_CR_USE_CODE_BASE_ADDR_MASK      0x01FFFFFFUL
#define EUR_CR_USE_CODE_BASE_ADDR_SHIFT     0
#define EUR_CR_USE_CODE_BASE_DM_MASK        0x06000000UL
#define EUR_CR_USE_CODE_BASE_DM_SHIFT       25
#define EUR_CR_USE_CODE_BASE_SIZE_UINT32 16
#define EUR_CR_USE_CODE_BASE_NUM_ENTRIES 16

#define EUR_CR_MNE_CR_CTRL						0x0D00
#define EUR_CR_MNE_CR_CTRL_BYP_CC_MASK			0x00008000UL
#define EUR_CR_MNE_CR_CTRL_INVAL				0x0D20

#endif
