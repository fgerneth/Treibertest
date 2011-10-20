cmd_drivers/staging/emgd/emgd/video/msvdx/msvdx_pvr.o := gcc -Wp,-MD,drivers/staging/emgd/emgd/video/msvdx/.msvdx_pvr.o.d  -nostdinc -isystem /usr/lib/gcc/i586-meego-linux/4.5.1/include -I/root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include -Iinclude  -include include/generated/autoconf.h -D__KERNEL__ -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -Os -m32 -msoft-float -mregparm=3 -freg-struct-return -mpreferred-stack-boundary=2 -march=atom -mtune=atom -mtune=generic -Wa,-mtune=generic32 -ffreestanding -DCONFIG_AS_CFI=1 -DCONFIG_AS_CFI_SIGNAL_FRAME=1 -DCONFIG_AS_CFI_SECTIONS=1 -pipe -Wno-sign-compare -fno-asynchronous-unwind-tables -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -Wframe-larger-than=1024 -fno-stack-protector -fno-omit-frame-pointer -fno-optimize-sibling-calls -g -pg -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO -Idrivers/staging/emgd/include -Idrivers/staging/emgd/emgd/display/mode/cmn -Idrivers/staging/emgd/emgd/video/overlay/cmn -Idrivers/staging/emgd/emgd/video/msvdx -Idrivers/staging/emgd/emgd/include -Idrivers/staging/emgd/emgd/cfg -Idrivers/staging/emgd/emgd/pal/lpd -Idrivers/staging/emgd/emgd/drm -Iinclude/drm -Idrivers/staging/emgd/pvr/include4 -Idrivers/staging/emgd/pvr/services4/include -Idrivers/staging/emgd/pvr/services4/include/env/linux -Idrivers/staging/emgd/pvr/services4/srvkm/env/linux -Idrivers/staging/emgd/pvr/services4/srvkm/include -Idrivers/staging/emgd/pvr/services4/srvkm/bridged -Idrivers/staging/emgd/pvr/services4/system/plb -Idrivers/staging/emgd/pvr/services4/system/tnc -Idrivers/staging/emgd/pvr/services4/system/include -Idrivers/staging/emgd/pvr/services4/srvkm/hwdefs -Idrivers/staging/emgd/pvr/services4/srvkm/bridged/sgx -Idrivers/staging/emgd/pvr/services4/srvkm/devices/sgx -Idrivers/staging/emgd/pvr/tools/intern/debug -DSUPPORT_DRI_DRM_EXT -DLINUX -DPVR_BUILD_DIR="\"emgd\"" -DPVR_BUILD_DATE="20100408" -DPVR_SECURE_HANDLES -DPVR_PROC_USE_SEQ_FILE -DLDM_PCI -DSUPPORT_CACHEFLUSH_ON_ALLOC -DSUPPORT_DRI_DRM -DSGX535 -DSGX_CORE_REV=121 -UDEBUG_LOG_PATH_TRUNCATE -DDISPLAY_CONTROLLER=emgd_dc -D_XOPEN_SOURCE=600 -DSERVICES4 -DPVR2D_VALIDATE_INPUT_PARAMS -DSUPPORT_SRVINIT -DSUPPORT_SGX -DSUPPORT_PERCONTEXT_PB -DSUPPORT_LINUX_X86_WRITECOMBINE -DSUPPORT_SECURE_DRM_AUTH_EXPORT -DSUPPORT_PDUMP_DELAYED_INITPHASE_TERMINATION -DTRANSFER_QUEUE -DSYS_USING_INTERRUPTS -DSUPPORT_HW_RECOVERY -DSUPPORT_ACTIVE_POWER_MANAGEMENT -DPVR_SECURE_HANDLES -DUSE_PTHREADS -DSUPPORT_SGX_EVENT_OBJECT -DSUPPORT_SGX_HWPERF -DSUPPORT_SGX_LOW_LATENCY_SCHEDULING -DSUPPORT_LINUX_X86_PAT -DSUPPORT_SGX535 -DSUPPORT_CACHE_LINE_FLUSH -DSUPPORT_CPU_CACHED_BUFFERS -DDEBUG_MESA_OGL_TRACE -DSUPPORT_EGL_IMAGE_SYNC_DEPENDENCY -DBUILD="\"release\"" -DPVR_BUILD_TYPE="\"release\"" -DRELEASE  -DMODULE  -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(msvdx_pvr)"  -D"KBUILD_MODNAME=KBUILD_STR(emgd)" -c -o drivers/staging/emgd/emgd/video/msvdx/msvdx_pvr.o drivers/staging/emgd/emgd/video/msvdx/msvdx_pvr.c

deps_drivers/staging/emgd/emgd/video/msvdx/msvdx_pvr.o := \
  drivers/staging/emgd/emgd/video/msvdx/msvdx_pvr.c \
  drivers/staging/emgd/emgd/include/msvdx.h \
  include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/types.h \
    $(wildcard include/config/x86/64.h) \
    $(wildcard include/config/highmem64g.h) \
  include/asm-generic/types.h \
  include/asm-generic/int-ll64.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/bitsperlong.h \
  include/asm-generic/bitsperlong.h \
  include/linux/posix_types.h \
  include/linux/stddef.h \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  include/linux/compiler-gcc4.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/posix_types.h \
    $(wildcard include/config/x86/32.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/posix_types_32.h \
  include/linux/poison.h \
    $(wildcard include/config/illegal/pointer/value.h) \
  include/linux/prefetch.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/processor.h \
    $(wildcard include/config/x86/vsmp.h) \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/cc/stackprotector.h) \
    $(wildcard include/config/paravirt.h) \
    $(wildcard include/config/m386.h) \
    $(wildcard include/config/m486.h) \
    $(wildcard include/config/x86/debugctlmsr.h) \
    $(wildcard include/config/cpu/sup/amd.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/processor-flags.h \
    $(wildcard include/config/vm86.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/vm86.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/ptrace.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/ptrace-abi.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/segment.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/page_types.h \
  include/linux/const.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/page_32_types.h \
    $(wildcard include/config/highmem4g.h) \
    $(wildcard include/config/page/offset.h) \
    $(wildcard include/config/x86/pae.h) \
  include/linux/init.h \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/hotplug.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/math_emu.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/sigcontext.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/current.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/percpu.h \
    $(wildcard include/config/x86/64/smp.h) \
  include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/spinlock/sleep.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/ring/buffer.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
  /usr/lib/gcc/i586-meego-linux/4.5.1/include/stdarg.h \
  include/linux/linkage.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/linkage.h \
    $(wildcard include/config/x86/alignment/16.h) \
  include/linux/stringify.h \
  include/linux/bitops.h \
    $(wildcard include/config/generic/find/last/bit.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/bitops.h \
    $(wildcard include/config/x86/cmov.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/alternative.h \
    $(wildcard include/config/dynamic/ftrace.h) \
  include/linux/jump_label.h \
    $(wildcard include/config/jump/label.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/asm.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/cpufeature.h \
    $(wildcard include/config/x86/invlpg.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/required-features.h \
    $(wildcard include/config/x86/minimum/cpu/family.h) \
    $(wildcard include/config/math/emulation.h) \
    $(wildcard include/config/x86/cmpxchg64.h) \
    $(wildcard include/config/x86/use/3dnow.h) \
    $(wildcard include/config/x86/p6/nop.h) \
  include/asm-generic/bitops/find.h \
    $(wildcard include/config/generic/find/first/bit.h) \
  include/asm-generic/bitops/sched.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/arch_hweight.h \
  include/asm-generic/bitops/const_hweight.h \
  include/asm-generic/bitops/fls64.h \
  include/asm-generic/bitops/ext2-non-atomic.h \
  include/asm-generic/bitops/le.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/byteorder.h \
  include/linux/byteorder/little_endian.h \
  include/linux/swab.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/swab.h \
    $(wildcard include/config/x86/bswap.h) \
  include/linux/byteorder/generic.h \
  include/asm-generic/bitops/minix.h \
  include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  include/linux/typecheck.h \
  include/linux/printk.h \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
  include/linux/dynamic_debug.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/debug/bugverbose.h) \
  include/asm-generic/bug.h \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/div64.h \
  include/asm-generic/percpu.h \
    $(wildcard include/config/debug/preempt.h) \
    $(wildcard include/config/have/setup/per/cpu/area.h) \
  include/linux/threads.h \
    $(wildcard include/config/nr/cpus.h) \
    $(wildcard include/config/base/small.h) \
  include/linux/percpu-defs.h \
    $(wildcard include/config/debug/force/weak/per/cpu.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/system.h \
    $(wildcard include/config/ia32/emulation.h) \
    $(wildcard include/config/x86/32/lazy/gs.h) \
    $(wildcard include/config/x86/ppro/fence.h) \
    $(wildcard include/config/x86/oostore.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/cmpxchg.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/cmpxchg_32.h \
    $(wildcard include/config/x86/cmpxchg.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/nops.h \
    $(wildcard include/config/mk7.h) \
  include/linux/irqflags.h \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/irqflags.h \
    $(wildcard include/config/debug/lock/alloc.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/page.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/page_32.h \
    $(wildcard include/config/hugetlb/page.h) \
    $(wildcard include/config/debug/virtual.h) \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/x86/3dnow.h) \
  include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/string.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/string_32.h \
    $(wildcard include/config/kmemcheck.h) \
  include/asm-generic/memory_model.h \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/sparsemem/vmemmap.h) \
    $(wildcard include/config/sparsemem.h) \
  include/asm-generic/getorder.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/pgtable_types.h \
    $(wildcard include/config/compat/vdso.h) \
    $(wildcard include/config/proc/fs.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/pgtable_32_types.h \
    $(wildcard include/config/highmem.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/pgtable-2level_types.h \
  include/asm-generic/pgtable-nopud.h \
  include/asm-generic/pgtable-nopmd.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/msr.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/msr-index.h \
  include/linux/ioctl.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/ioctl.h \
  include/asm-generic/ioctl.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/errno.h \
  include/asm-generic/errno.h \
  include/asm-generic/errno-base.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/cpumask.h \
  include/linux/cpumask.h \
    $(wildcard include/config/cpumask/offstack.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/debug/per/cpu/maps.h) \
    $(wildcard include/config/disable/obsolete/cpumask/functions.h) \
  include/linux/bitmap.h \
  include/linux/errno.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/desc_defs.h \
  include/linux/personality.h \
  include/linux/cache.h \
    $(wildcard include/config/arch/has/cache/line/size.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/cache.h \
    $(wildcard include/config/x86/l1/cache/shift.h) \
    $(wildcard include/config/x86/internode/cache/shift.h) \
  include/linux/math64.h \
  include/linux/err.h \
  drivers/staging/emgd/emgd/include/context.h \
  drivers/staging/emgd/emgd/include/pci.h \
    $(wildcard include/config/8.h) \
    $(wildcard include/config/16.h) \
    $(wildcard include/config/32.h) \
  drivers/staging/emgd/include/igd.h \
  drivers/staging/emgd/emgd/cfg/config.h \
    $(wildcard include/config/h.h) \
    $(wildcard include/config/oal.h) \
    $(wildcard include/config/oal/windows/miniport.h) \
    $(wildcard include/config/new/match.h) \
    $(wildcard include/config/use/info/priority.h) \
    $(wildcard include/config/default/width.h) \
    $(wildcard include/config/default/height.h) \
    $(wildcard include/config/default/pf.h) \
    $(wildcard include/config/nofences.h) \
    $(wildcard include/config/limit/pds.h) \
    $(wildcard include/config/pd/analog.h) \
    $(wildcard include/config/pd/lvds.h) \
    $(wildcard include/config/pd/sdvo.h) \
    $(wildcard include/config/pd/tv.h) \
    $(wildcard include/config/link/pd/lvds.h) \
    $(wildcard include/config/link/pd/sdvo.h) \
    $(wildcard include/config/decode.h) \
    $(wildcard include/config/st.h) \
  drivers/staging/emgd/emgd/cfg/config_default.h \
    $(wildcard include/config/.h) \
    $(wildcard include/config/foo.h) \
    $(wildcard include/config/enable/foo.h) \
    $(wildcard include/config/limit/foo.h) \
    $(wildcard include/config/limit/modes.h) \
    $(wildcard include/config/default/h.h) \
    $(wildcard include/config/micro.h) \
    $(wildcard include/config/full.h) \
    $(wildcard include/config/limit/cores.h) \
    $(wildcard include/config/plb.h) \
    $(wildcard include/config/tnc.h) \
    $(wildcard include/config/deprecated.h) \
    $(wildcard include/config/810.h) \
    $(wildcard include/config/810dc.h) \
    $(wildcard include/config/810e.h) \
    $(wildcard include/config/815.h) \
    $(wildcard include/config/830.h) \
    $(wildcard include/config/835.h) \
    $(wildcard include/config/845.h) \
    $(wildcard include/config/855.h) \
    $(wildcard include/config/865.h) \
    $(wildcard include/config/915gd.h) \
    $(wildcard include/config/915al.h) \
    $(wildcard include/config/945g.h) \
    $(wildcard include/config/945gm.h) \
    $(wildcard include/config/945gme.h) \
    $(wildcard include/config/q35.h) \
    $(wildcard include/config/965g.h) \
    $(wildcard include/config/965gm.h) \
    $(wildcard include/config/ctg.h) \
    $(wildcard include/config/q45.h) \
    $(wildcard include/config/pnv.h) \
    $(wildcard include/config/limit/modules.h) \
    $(wildcard include/config/init.h) \
    $(wildcard include/config/reg.h) \
    $(wildcard include/config/power.h) \
    $(wildcard include/config/mode.h) \
    $(wildcard include/config/dsp.h) \
    $(wildcard include/config/pi.h) \
    $(wildcard include/config/pd.h) \
    $(wildcard include/config/appcontext.h) \
    $(wildcard include/config/overlay.h) \
    $(wildcard include/config/pd/hdmi.h) \
    $(wildcard include/config/pd/softpd.h) \
    $(wildcard include/config/pd/sii164.h) \
    $(wildcard include/config/pd/ch7009.h) \
    $(wildcard include/config/pd/tl955.h) \
    $(wildcard include/config/pd/rgba.h) \
    $(wildcard include/config/pd/ns2501.h) \
    $(wildcard include/config/pd/th164.h) \
    $(wildcard include/config/pd/fs454.h) \
    $(wildcard include/config/pd/ns387.h) \
    $(wildcard include/config/pd/cx873.h) \
    $(wildcard include/config/pd/fs460.h) \
    $(wildcard include/config/pd/ch7017.h) \
    $(wildcard include/config/pd/ti410.h) \
    $(wildcard include/config/debug/flags.h) \
    $(wildcard include/config/debug/ial/flags.h) \
    $(wildcard include/config/enable/binning.h) \
    $(wildcard include/config/enable/threads.h) \
    $(wildcard include/config/nap.h) \
    $(wildcard include/config/wht.h) \
    $(wildcard include/config/alm.h) \
    $(wildcard include/config/gn4.h) \
  drivers/staging/emgd/emgd/cfg/personality.h \
    $(wildcard include/config/copp.h) \
  drivers/staging/emgd/include/igd_version.h \
  drivers/staging/emgd/include/igd_errno.h \
  drivers/staging/emgd/include/igd_mode.h \
    $(wildcard include/config/single.h) \
    $(wildcard include/config/clone.h) \
    $(wildcard include/config/twin.h) \
    $(wildcard include/config/extended.h) \
    $(wildcard include/config/mask.h) \
  drivers/staging/emgd/include/igd_appcontext.h \
  drivers/staging/emgd/include/igd_render.h \
  drivers/staging/emgd/include/igd_2d.h \
  drivers/staging/emgd/include/igd_pd.h \
  drivers/staging/emgd/include/igd_gmm.h \
    $(wildcard include/config/gmm.h) \
  drivers/staging/emgd/include/igd_rb.h \
  drivers/staging/emgd/include/igd_ovl.h \
  drivers/staging/emgd/include/emgd_shared.h \
  drivers/staging/emgd/include/igd_init.h \
    $(wildcard include/config/bin.h) \
  drivers/staging/emgd/emgd/video/msvdx/msvdx_pvr.h \
  drivers/staging/emgd/pvr/services4/srvkm/include/services_headers.h \
  drivers/staging/emgd/pvr/include4/img_defs.h \
  drivers/staging/emgd/pvr/include4/img_types.h \
  drivers/staging/emgd/pvr/include4/img_defs.h \
  drivers/staging/emgd/pvr/include4/services.h \
  drivers/staging/emgd/pvr/include4/servicesext.h \
  drivers/staging/emgd/pvr/include4/pdumpdefs.h \
  drivers/staging/emgd/pvr/services4/include/servicesint.h \
  drivers/staging/emgd/pvr/services4/system/include/sysinfo.h \
  drivers/staging/emgd/pvr/services4/srvkm/include/power.h \
  drivers/staging/emgd/pvr/services4/srvkm/include/resman.h \
  drivers/staging/emgd/pvr/services4/srvkm/include/queue.h \
  include/linux/seq_file.h \
  include/linux/mutex.h \
    $(wildcard include/config/debug/mutexes.h) \
  include/linux/spinlock_types.h \
    $(wildcard include/config/generic/lockbreak.h) \
    $(wildcard include/config/debug/spinlock.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/spinlock_types.h \
  include/linux/lockdep.h \
    $(wildcard include/config/lockdep.h) \
    $(wildcard include/config/lock/stat.h) \
    $(wildcard include/config/prove/rcu.h) \
  include/linux/rwlock_types.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/atomic.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/atomic64_32.h \
  include/asm-generic/atomic-long.h \
  include/linux/nodemask.h \
  include/linux/numa.h \
    $(wildcard include/config/nodes/shift.h) \
  drivers/staging/emgd/pvr/services4/srvkm/include/srvkm.h \
  drivers/staging/emgd/pvr/services4/include/kerneldisplay.h \
  drivers/staging/emgd/pvr/services4/system/include/sysconfig.h \
    $(wildcard include/config/space.h) \
  drivers/staging/emgd/pvr/services4/system/include/sysinfo.h \
  drivers/staging/emgd/pvr/services4/srvkm/include/queue.h \
  drivers/staging/emgd/pvr/services4/srvkm/include/power.h \
  drivers/staging/emgd/pvr/services4/srvkm/include/resman.h \
  drivers/staging/emgd/pvr/services4/srvkm/include/ra.h \
  drivers/staging/emgd/pvr/include4/img_types.h \
  drivers/staging/emgd/pvr/services4/srvkm/include/hash.h \
  drivers/staging/emgd/pvr/services4/srvkm/include/osfunc.h \
  include/linux/hardirq.h \
    $(wildcard include/config/preempt.h) \
    $(wildcard include/config/bkl.h) \
    $(wildcard include/config/generic/hardirqs.h) \
    $(wildcard include/config/virt/cpu/accounting.h) \
    $(wildcard include/config/irq/time/accounting.h) \
    $(wildcard include/config/no/hz.h) \
    $(wildcard include/config/tiny/rcu.h) \
    $(wildcard include/config/tiny/preempt/rcu.h) \
  include/linux/preempt.h \
    $(wildcard include/config/preempt/notifiers.h) \
  include/linux/thread_info.h \
    $(wildcard include/config/compat.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/thread_info.h \
    $(wildcard include/config/debug/stack/usage.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/ftrace.h \
    $(wildcard include/config/function/tracer.h) \
  include/linux/ftrace_irq.h \
    $(wildcard include/config/ftrace/nmi/enter.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/hardirq.h \
    $(wildcard include/config/x86/local/apic.h) \
    $(wildcard include/config/x86/thermal/vector.h) \
    $(wildcard include/config/x86/mce/threshold.h) \
  include/linux/irq.h \
    $(wildcard include/config/s390.h) \
    $(wildcard include/config/irq/per/cpu.h) \
    $(wildcard include/config/generic/hardirqs/no/deprecated.h) \
    $(wildcard include/config/irq/release/method.h) \
    $(wildcard include/config/generic/pending/irq.h) \
  include/linux/smp.h \
    $(wildcard include/config/use/generic/smp/helpers.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/smp.h \
    $(wildcard include/config/x86/io/apic.h) \
    $(wildcard include/config/x86/32/smp.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/mpspec.h \
    $(wildcard include/config/x86/numaq.h) \
    $(wildcard include/config/mca.h) \
    $(wildcard include/config/eisa.h) \
    $(wildcard include/config/x86/mpparse.h) \
    $(wildcard include/config/acpi.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/mpspec_def.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/x86_init.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/bootparam.h \
  include/linux/screen_info.h \
  include/linux/apm_bios.h \
  include/linux/edd.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/e820.h \
    $(wildcard include/config/efi.h) \
    $(wildcard include/config/intel/txt.h) \
    $(wildcard include/config/hibernation.h) \
    $(wildcard include/config/memtest.h) \
  include/linux/ioport.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/ist.h \
  include/video/edid.h \
    $(wildcard include/config/x86.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/apic.h \
    $(wildcard include/config/x86/x2apic.h) \
  include/linux/delay.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/delay.h \
  include/linux/pm.h \
    $(wildcard include/config/pm.h) \
    $(wildcard include/config/pm/sleep.h) \
    $(wildcard include/config/pm/runtime.h) \
    $(wildcard include/config/pm/ops.h) \
  include/linux/workqueue.h \
    $(wildcard include/config/debug/objects/work.h) \
    $(wildcard include/config/freezer.h) \
  include/linux/timer.h \
    $(wildcard include/config/timer/stats.h) \
    $(wildcard include/config/debug/objects/timers.h) \
  include/linux/ktime.h \
    $(wildcard include/config/ktime/scalar.h) \
  include/linux/time.h \
    $(wildcard include/config/arch/uses/gettimeoffset.h) \
  include/linux/seqlock.h \
  include/linux/spinlock.h \
  include/linux/bottom_half.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/spinlock.h \
    $(wildcard include/config/paravirt/spinlocks.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/rwlock.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/paravirt.h \
  include/linux/rwlock.h \
  include/linux/spinlock_api_smp.h \
    $(wildcard include/config/inline/spin/lock.h) \
    $(wildcard include/config/inline/spin/lock/bh.h) \
    $(wildcard include/config/inline/spin/lock/irq.h) \
    $(wildcard include/config/inline/spin/lock/irqsave.h) \
    $(wildcard include/config/inline/spin/trylock.h) \
    $(wildcard include/config/inline/spin/trylock/bh.h) \
    $(wildcard include/config/inline/spin/unlock.h) \
    $(wildcard include/config/inline/spin/unlock/bh.h) \
    $(wildcard include/config/inline/spin/unlock/irq.h) \
    $(wildcard include/config/inline/spin/unlock/irqrestore.h) \
  include/linux/rwlock_api_smp.h \
    $(wildcard include/config/inline/read/lock.h) \
    $(wildcard include/config/inline/write/lock.h) \
    $(wildcard include/config/inline/read/lock/bh.h) \
    $(wildcard include/config/inline/write/lock/bh.h) \
    $(wildcard include/config/inline/read/lock/irq.h) \
    $(wildcard include/config/inline/write/lock/irq.h) \
    $(wildcard include/config/inline/read/lock/irqsave.h) \
    $(wildcard include/config/inline/write/lock/irqsave.h) \
    $(wildcard include/config/inline/read/trylock.h) \
    $(wildcard include/config/inline/write/trylock.h) \
    $(wildcard include/config/inline/read/unlock.h) \
    $(wildcard include/config/inline/write/unlock.h) \
    $(wildcard include/config/inline/read/unlock/bh.h) \
    $(wildcard include/config/inline/write/unlock/bh.h) \
    $(wildcard include/config/inline/read/unlock/irq.h) \
    $(wildcard include/config/inline/write/unlock/irq.h) \
    $(wildcard include/config/inline/read/unlock/irqrestore.h) \
    $(wildcard include/config/inline/write/unlock/irqrestore.h) \
  include/linux/jiffies.h \
  include/linux/timex.h \
  include/linux/param.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/param.h \
  include/asm-generic/param.h \
    $(wildcard include/config/hz.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/timex.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/tsc.h \
    $(wildcard include/config/x86/tsc.h) \
  include/linux/debugobjects.h \
    $(wildcard include/config/debug/objects.h) \
    $(wildcard include/config/debug/objects/free.h) \
  include/linux/wait.h \
  include/linux/completion.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/apicdef.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/fixmap.h \
    $(wildcard include/config/provide/ohci1394/dma/init.h) \
    $(wildcard include/config/x86/visws/apic.h) \
    $(wildcard include/config/x86/f00f/bug.h) \
    $(wildcard include/config/x86/cyclone/timer.h) \
    $(wildcard include/config/pci/mmconfig.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/acpi.h \
    $(wildcard include/config/acpi/numa.h) \
  include/acpi/pdc_intel.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/numa.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/numa_32.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/mmu.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/kmap_types.h \
    $(wildcard include/config/debug/highmem.h) \
  include/asm-generic/kmap_types.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/io_apic.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/irq_vectors.h \
    $(wildcard include/config/sparse/irq.h) \
  include/linux/gfp.h \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/zone/dma32.h) \
    $(wildcard include/config/debug/vm.h) \
  include/linux/mmzone.h \
    $(wildcard include/config/force/max/zoneorder.h) \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/compaction.h) \
    $(wildcard include/config/arch/populates/node/map.h) \
    $(wildcard include/config/flat/node/mem/map.h) \
    $(wildcard include/config/cgroup/mem/res/ctlr.h) \
    $(wildcard include/config/no/bootmem.h) \
    $(wildcard include/config/have/memory/present.h) \
    $(wildcard include/config/have/memoryless/nodes.h) \
    $(wildcard include/config/need/node/memmap/size.h) \
    $(wildcard include/config/need/multiple/nodes.h) \
    $(wildcard include/config/have/arch/early/pfn/to/nid.h) \
    $(wildcard include/config/sparsemem/extreme.h) \
    $(wildcard include/config/nodes/span/other/nodes.h) \
    $(wildcard include/config/holes/in/zone.h) \
    $(wildcard include/config/arch/has/holes/memorymodel.h) \
  include/linux/pageblock-flags.h \
    $(wildcard include/config/hugetlb/page/size/variable.h) \
  include/generated/bounds.h \
  include/linux/memory_hotplug.h \
    $(wildcard include/config/memory/hotremove.h) \
    $(wildcard include/config/have/arch/nodedata/extension.h) \
  include/linux/notifier.h \
  include/linux/rwsem.h \
    $(wildcard include/config/rwsem/generic/spinlock.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/rwsem.h \
  include/linux/srcu.h \
  include/linux/topology.h \
    $(wildcard include/config/sched/smt.h) \
    $(wildcard include/config/sched/mc.h) \
    $(wildcard include/config/sched/book.h) \
    $(wildcard include/config/use/percpu/numa/node/id.h) \
  include/linux/percpu.h \
    $(wildcard include/config/need/per/cpu/embed/first/chunk.h) \
    $(wildcard include/config/need/per/cpu/page/first/chunk.h) \
  include/linux/pfn.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/topology.h \
    $(wildcard include/config/x86/ht.h) \
    $(wildcard include/config/x86/64/acpi/numa.h) \
  include/asm-generic/topology.h \
  include/linux/mmdebug.h \
  include/linux/irqreturn.h \
  include/linux/irqnr.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/irq.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/irq_regs.h \
  include/linux/irqdesc.h \
    $(wildcard include/config/generic/hardirqs/no//do/irq.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/hw_irq.h \
    $(wildcard include/config/intr/remap.h) \
  include/linux/profile.h \
    $(wildcard include/config/profiling.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/sections.h \
    $(wildcard include/config/debug/rodata.h) \
  include/asm-generic/sections.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/uaccess.h \
    $(wildcard include/config/x86/wp/works/ok.h) \
    $(wildcard include/config/x86/intel/usercopy.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/uaccess_32.h \
    $(wildcard include/config/debug/strict/user/copy/checks.h) \
  drivers/staging/emgd/pvr/services4/srvkm/include/device.h \
  drivers/staging/emgd/pvr/services4/srvkm/include/ra.h \
  drivers/staging/emgd/pvr/services4/srvkm/include/buffer_manager.h \
  drivers/staging/emgd/pvr/services4/srvkm/include/perproc.h \
  drivers/staging/emgd/pvr/services4/srvkm/include/handle.h \
  drivers/staging/emgd/pvr/include4/pvr_debug.h \
  drivers/staging/emgd/pvr/services4/srvkm/include/metrics.h \
  drivers/staging/emgd/pvr/services4/srvkm/devices/sgx/sgxinfokm.h \
  drivers/staging/emgd/pvr/services4/srvkm/hwdefs/sgxdefs.h \
  drivers/staging/emgd/pvr/services4/srvkm/hwdefs/sgxerrata.h \
  drivers/staging/emgd/pvr/services4/srvkm/hwdefs/sgxfeaturedefs.h \
  drivers/staging/emgd/pvr/services4/srvkm/hwdefs/sgx535defs.h \
    $(wildcard include/config/shift.h) \
    $(wildcard include/config/page/size/mask.h) \
    $(wildcard include/config/page/size/shift.h) \
    $(wildcard include/config/best/cnt/mask.h) \
    $(wildcard include/config/best/cnt/shift.h) \
    $(wildcard include/config/tte/thresh/mask.h) \
    $(wildcard include/config/tte/thresh/shift.h) \
  drivers/staging/emgd/pvr/include4/sgxscript.h \
  drivers/staging/emgd/pvr/services4/include/sgxinfo.h \
  drivers/staging/emgd/pvr/services4/include/servicesint.h \
  drivers/staging/emgd/pvr/include4/sgxapi_km.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/unistd.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/unistd_32.h \
  drivers/staging/emgd/pvr/services4/include/sgx_mkif_km.h \
  drivers/staging/emgd/pvr/services4/srvkm/include/perproc.h \
  drivers/staging/emgd/pvr/services4/include/pvr_bridge_km.h \
  drivers/staging/emgd/pvr/services4/include/pvr_bridge.h \
  drivers/staging/emgd/pvr/services4/include/pvrmmap.h \
  drivers/staging/emgd/pvr/services4/system/include/syscommon.h \
  drivers/staging/emgd/pvr/services4/system/include/sysconfig.h \
  drivers/staging/emgd/emgd/include/memory.h \
  include/linux/slab.h \
    $(wildcard include/config/slab/debug.h) \
    $(wildcard include/config/failslab.h) \
    $(wildcard include/config/slub.h) \
    $(wildcard include/config/slob.h) \
    $(wildcard include/config/debug/slab.h) \
    $(wildcard include/config/slab.h) \
  include/linux/slab_def.h \
  include/trace/events/kmem.h \
  include/linux/tracepoint.h \
    $(wildcard include/config/tracepoints.h) \
  include/linux/rcupdate.h \
    $(wildcard include/config/rcu/torture/test.h) \
    $(wildcard include/config/preempt/rcu.h) \
    $(wildcard include/config/tree/rcu.h) \
    $(wildcard include/config/tree/preempt/rcu.h) \
    $(wildcard include/config/debug/objects/rcu/head.h) \
    $(wildcard include/config/preempt/rt.h) \
  include/linux/rcutree.h \
  include/trace/events/gfpflags.h \
  include/trace/define_trace.h \
    $(wildcard include/config/event/tracing.h) \
  include/linux/kmalloc_sizes.h \
  drivers/staging/emgd/include/memmap.h \
  drivers/staging/emgd/emgd/drm/drm_emgd_private.h \
  include/drm/drmP.h \
    $(wildcard include/config/mtrr.h) \
    $(wildcard include/config/agp.h) \
    $(wildcard include/config/debug/fs.h) \
  include/linux/module.h \
    $(wildcard include/config/symbol/prefix.h) \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/unused/symbols.h) \
    $(wildcard include/config/kallsyms.h) \
    $(wildcard include/config/module/unload.h) \
    $(wildcard include/config/constructors.h) \
    $(wildcard include/config/sysfs.h) \
  include/linux/stat.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/stat.h \
  include/linux/kmod.h \
  include/linux/elf.h \
  include/linux/elf-em.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/elf.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/user.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/user_32.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/auxvec.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/vdso.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/desc.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/ldt.h \
  include/linux/kobject.h \
  include/linux/sysfs.h \
  include/linux/kobject_ns.h \
  include/linux/kref.h \
  include/linux/moduleparam.h \
    $(wildcard include/config/alpha.h) \
    $(wildcard include/config/ia64.h) \
    $(wildcard include/config/ppc64.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/module.h \
    $(wildcard include/config/m586.h) \
    $(wildcard include/config/m586tsc.h) \
    $(wildcard include/config/m586mmx.h) \
    $(wildcard include/config/mcore2.h) \
    $(wildcard include/config/matom.h) \
    $(wildcard include/config/m686.h) \
    $(wildcard include/config/mpentiumii.h) \
    $(wildcard include/config/mpentiumiii.h) \
    $(wildcard include/config/mpentiumm.h) \
    $(wildcard include/config/mpentium4.h) \
    $(wildcard include/config/mk6.h) \
    $(wildcard include/config/mk8.h) \
    $(wildcard include/config/x86/elan.h) \
    $(wildcard include/config/mcrusoe.h) \
    $(wildcard include/config/mefficeon.h) \
    $(wildcard include/config/mwinchipc6.h) \
    $(wildcard include/config/mwinchip3d.h) \
    $(wildcard include/config/mcyrixiii.h) \
    $(wildcard include/config/mviac3/2.h) \
    $(wildcard include/config/mviac7.h) \
    $(wildcard include/config/mgeodegx1.h) \
    $(wildcard include/config/mgeode/lx.h) \
  include/asm-generic/module.h \
  include/trace/events/module.h \
  include/linux/miscdevice.h \
  include/linux/major.h \
  include/linux/fs.h \
    $(wildcard include/config/quota.h) \
    $(wildcard include/config/fsnotify.h) \
    $(wildcard include/config/ima.h) \
    $(wildcard include/config/security.h) \
    $(wildcard include/config/fs/posix/acl.h) \
    $(wildcard include/config/epoll.h) \
    $(wildcard include/config/debug/writecount.h) \
    $(wildcard include/config/file/locking.h) \
    $(wildcard include/config/auditsyscall.h) \
    $(wildcard include/config/block.h) \
    $(wildcard include/config/fs/xip.h) \
    $(wildcard include/config/migration.h) \
  include/linux/limits.h \
  include/linux/blk_types.h \
    $(wildcard include/config/blk/dev/integrity.h) \
  include/linux/kdev_t.h \
  include/linux/dcache.h \
  include/linux/rculist.h \
  include/linux/path.h \
  include/linux/radix-tree.h \
  include/linux/prio_tree.h \
  include/linux/pid.h \
  include/linux/capability.h \
  include/linux/semaphore.h \
  include/linux/fiemap.h \
  include/linux/quota.h \
    $(wildcard include/config/quota/netlink/interface.h) \
  include/linux/percpu_counter.h \
  include/linux/dqblk_xfs.h \
  include/linux/dqblk_v1.h \
  include/linux/dqblk_v2.h \
  include/linux/dqblk_qtree.h \
  include/linux/nfs_fs_i.h \
  include/linux/nfs.h \
  include/linux/sunrpc/msg_prot.h \
  include/linux/inet.h \
  include/linux/fcntl.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/fcntl.h \
  include/asm-generic/fcntl.h \
  include/linux/proc_fs.h \
    $(wildcard include/config/proc/devicetree.h) \
    $(wildcard include/config/proc/kcore.h) \
    $(wildcard include/config/mmu.h) \
  include/linux/magic.h \
  include/linux/file.h \
  include/linux/platform_device.h \
  include/linux/device.h \
    $(wildcard include/config/of.h) \
    $(wildcard include/config/debug/devres.h) \
    $(wildcard include/config/devtmpfs.h) \
    $(wildcard include/config/sysfs/deprecated.h) \
  include/linux/klist.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/device.h \
    $(wildcard include/config/x86/dev/dma/ops.h) \
    $(wildcard include/config/dmar.h) \
    $(wildcard include/config/amd/iommu.h) \
  include/linux/pm_wakeup.h \
  include/linux/mod_devicetable.h \
  include/linux/pci.h \
    $(wildcard include/config/pci/iov.h) \
    $(wildcard include/config/pcieaspm.h) \
    $(wildcard include/config/pci/msi.h) \
    $(wildcard include/config/pci.h) \
    $(wildcard include/config/pcie/ecrc.h) \
    $(wildcard include/config/ht/irq.h) \
    $(wildcard include/config/pci/domains.h) \
    $(wildcard include/config/pci/quirks.h) \
    $(wildcard include/config/hotplug/pci.h) \
  include/linux/pci_regs.h \
  include/linux/io.h \
    $(wildcard include/config/has/ioport.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/io.h \
    $(wildcard include/config/xen.h) \
  include/xen/xen.h \
    $(wildcard include/config/xen/dom0.h) \
  include/asm-generic/iomap.h \
  include/linux/vmalloc.h \
  include/linux/pci_ids.h \
  include/linux/pci-dma.h \
  include/linux/dmapool.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/scatterlist.h \
  include/asm-generic/scatterlist.h \
    $(wildcard include/config/debug/sg.h) \
    $(wildcard include/config/need/sg/dma/length.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/pci.h \
  include/linux/mm.h \
    $(wildcard include/config/sysctl.h) \
    $(wildcard include/config/stack/growsup.h) \
    $(wildcard include/config/ksm.h) \
    $(wildcard include/config/debug/pagealloc.h) \
    $(wildcard include/config/memory/failure.h) \
  include/linux/rbtree.h \
  include/linux/debug_locks.h \
    $(wildcard include/config/debug/locking/api/selftests.h) \
  include/linux/mm_types.h \
    $(wildcard include/config/split/ptlock/cpus.h) \
    $(wildcard include/config/want/page/debug/flags.h) \
    $(wildcard include/config/aio.h) \
    $(wildcard include/config/mm/owner.h) \
    $(wildcard include/config/mmu/notifier.h) \
  include/linux/auxvec.h \
  include/linux/page-debug-flags.h \
    $(wildcard include/config/page/poisoning.h) \
    $(wildcard include/config/page/debug/something/else.h) \
  include/linux/range.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/pgtable.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/pgtable_32.h \
    $(wildcard include/config/highpte.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/pgtable_32_types.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/pgtable-2level.h \
  include/asm-generic/pgtable.h \
  include/linux/page-flags.h \
    $(wildcard include/config/pageflags/extended.h) \
    $(wildcard include/config/arch/uses/pg/uncached.h) \
    $(wildcard include/config/swap.h) \
  include/linux/vmstat.h \
    $(wildcard include/config/vm/event/counters.h) \
  include/asm-generic/pci-dma-compat.h \
  include/linux/dma-mapping.h \
    $(wildcard include/config/has/dma.h) \
    $(wildcard include/config/have/dma/attrs.h) \
    $(wildcard include/config/need/dma/map/state.h) \
  include/linux/dma-attrs.h \
  include/linux/bug.h \
  include/linux/scatterlist.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/dma-mapping.h \
    $(wildcard include/config/isa.h) \
  include/linux/kmemcheck.h \
  include/linux/dma-debug.h \
    $(wildcard include/config/dma/api/debug.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/swiotlb.h \
    $(wildcard include/config/swiotlb.h) \
  include/linux/swiotlb.h \
  include/asm-generic/dma-coherent.h \
    $(wildcard include/config/have/generic/dma/coherent.h) \
  include/asm-generic/dma-mapping-common.h \
  include/asm-generic/pci.h \
  include/linux/cdev.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/mman.h \
  include/asm-generic/mman.h \
  include/asm-generic/mman-common.h \
    $(wildcard include/config/mmap/allow/uninitialized.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/mtrr.h \
  include/linux/agp_backend.h \
  include/linux/poll.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/poll.h \
  include/asm-generic/poll.h \
  include/linux/sysctl.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/pgalloc.h \
  include/linux/pagemap.h \
  include/linux/highmem.h \
  include/linux/uaccess.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/cacheflush.h \
    $(wildcard include/config/x86/pat.h) \
    $(wildcard include/config/debug/rodata/test.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/highmem.h \
  include/linux/interrupt.h \
    $(wildcard include/config/generic/irq/probe.h) \
  include/linux/hrtimer.h \
    $(wildcard include/config/high/res/timers.h) \
  include/trace/events/irq.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/tlbflush.h \
  include/linux/sched.h \
    $(wildcard include/config/sched/debug.h) \
    $(wildcard include/config/lockup/detector.h) \
    $(wildcard include/config/detect/hung/task.h) \
    $(wildcard include/config/core/dump/default/elf/headers.h) \
    $(wildcard include/config/bsd/process/acct.h) \
    $(wildcard include/config/taskstats.h) \
    $(wildcard include/config/audit.h) \
    $(wildcard include/config/inotify/user.h) \
    $(wildcard include/config/fanotify.h) \
    $(wildcard include/config/posix/mqueue.h) \
    $(wildcard include/config/keys.h) \
    $(wildcard include/config/perf/events.h) \
    $(wildcard include/config/schedstats.h) \
    $(wildcard include/config/task/delay/acct.h) \
    $(wildcard include/config/fair/group/sched.h) \
    $(wildcard include/config/rt/group/sched.h) \
    $(wildcard include/config/blk/dev/io/trace.h) \
    $(wildcard include/config/sysvipc.h) \
    $(wildcard include/config/rt/mutexes.h) \
    $(wildcard include/config/task/xacct.h) \
    $(wildcard include/config/cpusets.h) \
    $(wildcard include/config/cgroups.h) \
    $(wildcard include/config/futex.h) \
    $(wildcard include/config/fault/injection.h) \
    $(wildcard include/config/latencytop.h) \
    $(wildcard include/config/function/graph/tracer.h) \
    $(wildcard include/config/have/unstable/sched/clock.h) \
    $(wildcard include/config/cgroup/sched.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/cputime.h \
  include/asm-generic/cputime.h \
  include/linux/sem.h \
  include/linux/ipc.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/ipcbuf.h \
  include/asm-generic/ipcbuf.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/sembuf.h \
  include/linux/signal.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/signal.h \
  include/asm-generic/signal-defs.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/siginfo.h \
  include/asm-generic/siginfo.h \
  include/linux/proportions.h \
  include/linux/seccomp.h \
    $(wildcard include/config/seccomp.h) \
  include/linux/rtmutex.h \
    $(wildcard include/config/debug/rt/mutexes.h) \
  include/linux/plist.h \
    $(wildcard include/config/debug/pi/list.h) \
  include/linux/resource.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/resource.h \
  include/asm-generic/resource.h \
  include/linux/task_io_accounting.h \
    $(wildcard include/config/task/io/accounting.h) \
  include/linux/latencytop.h \
  include/linux/cred.h \
    $(wildcard include/config/debug/credentials.h) \
  include/linux/key.h \
  include/linux/selinux.h \
    $(wildcard include/config/security/selinux.h) \
  include/linux/aio.h \
  include/linux/aio_abi.h \
  include/linux/uio.h \
  include/linux/hugetlb_inline.h \
  include/drm/drm.h \
  include/drm/drm_mode.h \
  include/linux/idr.h \
  include/drm/drm_os_linux.h \
  include/drm/drm_hashtab.h \
  include/drm/drm_mm.h \
  include/drm/drm_crtc.h \
  include/linux/i2c.h \
    $(wildcard include/config/i2c.h) \
    $(wildcard include/config/i2c/boardinfo.h) \
  include/linux/i2c-id.h \
  include/linux/of.h \
    $(wildcard include/config/sparc.h) \
    $(wildcard include/config/of/dynamic.h) \
  include/linux/fb.h \
    $(wildcard include/config/fb/backlight.h) \
    $(wildcard include/config/fb/deferred/io.h) \
    $(wildcard include/config/fb/tileblitting.h) \
    $(wildcard include/config/fb/foreign/endian.h) \
    $(wildcard include/config/fb/both/endian.h) \
    $(wildcard include/config/fb/big/endian.h) \
    $(wildcard include/config/fb/little/endian.h) \
  include/linux/kgdb.h \
    $(wildcard include/config/have/arch/kgdb.h) \
    $(wildcard include/config/kgdb.h) \
  include/linux/serial_8250.h \
  include/linux/serial_core.h \
    $(wildcard include/config/console/poll.h) \
    $(wildcard include/config/type.h) \
    $(wildcard include/config/irq.h) \
    $(wildcard include/config/serial/core/console.h) \
    $(wildcard include/config/hard/pps.h) \
  include/linux/serial.h \
  include/linux/circ_buf.h \
  include/linux/tty.h \
  include/linux/termios.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/termios.h \
  include/asm-generic/termios.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/termbits.h \
  include/asm-generic/termbits.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/ioctls.h \
  include/asm-generic/ioctls.h \
  include/linux/tty_driver.h \
  include/linux/tty_ldisc.h \
  include/linux/sysrq.h \
    $(wildcard include/config/magic/sysrq.h) \
  include/linux/tty_flip.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/kgdb.h \
  include/linux/backlight.h \
  include/drm/drm_memory.h \
  include/drm/drmP.h \
  include/drm/drm_global.h \
  include/drm/drm_mem_util.h \
  include/drm/drm.h \
  drivers/staging/emgd/include/emgd_drm.h \
  drivers/staging/emgd/include/igd_pi.h \
  drivers/staging/emgd/include/igd_pwr.h \

drivers/staging/emgd/emgd/video/msvdx/msvdx_pvr.o: $(deps_drivers/staging/emgd/emgd/video/msvdx/msvdx_pvr.o)

$(deps_drivers/staging/emgd/emgd/video/msvdx/msvdx_pvr.o):
