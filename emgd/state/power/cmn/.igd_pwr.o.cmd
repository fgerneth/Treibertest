cmd_drivers/staging/emgd/emgd/state/power/cmn/igd_pwr.o := gcc -Wp,-MD,drivers/staging/emgd/emgd/state/power/cmn/.igd_pwr.o.d  -nostdinc -isystem /usr/lib/gcc/i586-meego-linux/4.5.1/include -I/root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include -Iinclude  -include include/generated/autoconf.h -D__KERNEL__ -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -Os -m32 -msoft-float -mregparm=3 -freg-struct-return -mpreferred-stack-boundary=2 -march=atom -mtune=atom -mtune=generic -Wa,-mtune=generic32 -ffreestanding -DCONFIG_AS_CFI=1 -DCONFIG_AS_CFI_SIGNAL_FRAME=1 -DCONFIG_AS_CFI_SECTIONS=1 -pipe -Wno-sign-compare -fno-asynchronous-unwind-tables -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -Wframe-larger-than=1024 -fno-stack-protector -fno-omit-frame-pointer -fno-optimize-sibling-calls -g -pg -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO -Idrivers/staging/emgd/include -Idrivers/staging/emgd/emgd/display/mode/cmn -Idrivers/staging/emgd/emgd/video/overlay/cmn -Idrivers/staging/emgd/emgd/video/msvdx -Idrivers/staging/emgd/emgd/include -Idrivers/staging/emgd/emgd/cfg -Idrivers/staging/emgd/emgd/pal/lpd -Idrivers/staging/emgd/emgd/drm -Iinclude/drm -Idrivers/staging/emgd/pvr/include4 -Idrivers/staging/emgd/pvr/services4/include -Idrivers/staging/emgd/pvr/services4/include/env/linux -Idrivers/staging/emgd/pvr/services4/srvkm/env/linux -Idrivers/staging/emgd/pvr/services4/srvkm/include -Idrivers/staging/emgd/pvr/services4/srvkm/bridged -Idrivers/staging/emgd/pvr/services4/system/plb -Idrivers/staging/emgd/pvr/services4/system/tnc -Idrivers/staging/emgd/pvr/services4/system/include -Idrivers/staging/emgd/pvr/services4/srvkm/hwdefs -Idrivers/staging/emgd/pvr/services4/srvkm/bridged/sgx -Idrivers/staging/emgd/pvr/services4/srvkm/devices/sgx -Idrivers/staging/emgd/pvr/tools/intern/debug -DSUPPORT_DRI_DRM_EXT -DLINUX -DPVR_BUILD_DIR="\"emgd\"" -DPVR_BUILD_DATE="20100408" -DPVR_SECURE_HANDLES -DPVR_PROC_USE_SEQ_FILE -DLDM_PCI -DSUPPORT_CACHEFLUSH_ON_ALLOC -DSUPPORT_DRI_DRM -DSGX535 -DSGX_CORE_REV=121 -UDEBUG_LOG_PATH_TRUNCATE -DDISPLAY_CONTROLLER=emgd_dc -D_XOPEN_SOURCE=600 -DSERVICES4 -DPVR2D_VALIDATE_INPUT_PARAMS -DSUPPORT_SRVINIT -DSUPPORT_SGX -DSUPPORT_PERCONTEXT_PB -DSUPPORT_LINUX_X86_WRITECOMBINE -DSUPPORT_SECURE_DRM_AUTH_EXPORT -DSUPPORT_PDUMP_DELAYED_INITPHASE_TERMINATION -DTRANSFER_QUEUE -DSYS_USING_INTERRUPTS -DSUPPORT_HW_RECOVERY -DSUPPORT_ACTIVE_POWER_MANAGEMENT -DPVR_SECURE_HANDLES -DUSE_PTHREADS -DSUPPORT_SGX_EVENT_OBJECT -DSUPPORT_SGX_HWPERF -DSUPPORT_SGX_LOW_LATENCY_SCHEDULING -DSUPPORT_LINUX_X86_PAT -DSUPPORT_SGX535 -DSUPPORT_CACHE_LINE_FLUSH -DSUPPORT_CPU_CACHED_BUFFERS -DDEBUG_MESA_OGL_TRACE -DSUPPORT_EGL_IMAGE_SYNC_DEPENDENCY -DBUILD="\"release\"" -DPVR_BUILD_TYPE="\"release\"" -DRELEASE  -DMODULE  -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(igd_pwr)"  -D"KBUILD_MODNAME=KBUILD_STR(emgd)" -c -o drivers/staging/emgd/emgd/state/power/cmn/igd_pwr.o drivers/staging/emgd/emgd/state/power/cmn/igd_pwr.c

deps_drivers/staging/emgd/emgd/state/power/cmn/igd_pwr.o := \
  drivers/staging/emgd/emgd/state/power/cmn/igd_pwr.c \
    $(wildcard include/config/plb.h) \
    $(wildcard include/config/tnc.h) \
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
  drivers/staging/emgd/include/io.h \
  include/linux/kernel.h \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/spinlock/sleep.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/ring/buffer.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
  /usr/lib/gcc/i586-meego-linux/4.5.1/include/stdarg.h \
  include/linux/linkage.h \
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
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/linkage.h \
    $(wildcard include/config/x86/32.h) \
    $(wildcard include/config/x86/64.h) \
    $(wildcard include/config/x86/alignment/16.h) \
  include/linux/stringify.h \
  include/linux/stddef.h \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/types.h \
    $(wildcard include/config/highmem64g.h) \
  include/asm-generic/types.h \
  include/asm-generic/int-ll64.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/bitsperlong.h \
  include/asm-generic/bitsperlong.h \
  include/linux/posix_types.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/posix_types.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/posix_types_32.h \
  include/linux/bitops.h \
    $(wildcard include/config/generic/find/last/bit.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/bitops.h \
    $(wildcard include/config/x86/cmov.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/alternative.h \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/paravirt.h) \
    $(wildcard include/config/dynamic/ftrace.h) \
  include/linux/jump_label.h \
    $(wildcard include/config/jump/label.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/asm.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/cpufeature.h \
    $(wildcard include/config/x86/invlpg.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/required-features.h \
    $(wildcard include/config/x86/minimum/cpu/family.h) \
    $(wildcard include/config/math/emulation.h) \
    $(wildcard include/config/x86/pae.h) \
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
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/io.h \
    $(wildcard include/config/x86/oostore.h) \
    $(wildcard include/config/x86/ppro/fence.h) \
    $(wildcard include/config/xen.h) \
  include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/string.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/string_32.h \
    $(wildcard include/config/kmemcheck.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/page.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/page_types.h \
  include/linux/const.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/page_32_types.h \
    $(wildcard include/config/highmem4g.h) \
    $(wildcard include/config/page/offset.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/page_32.h \
    $(wildcard include/config/hugetlb/page.h) \
    $(wildcard include/config/debug/virtual.h) \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/x86/3dnow.h) \
  include/asm-generic/memory_model.h \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/sparsemem/vmemmap.h) \
    $(wildcard include/config/sparsemem.h) \
  include/asm-generic/getorder.h \
  include/xen/xen.h \
    $(wildcard include/config/xen/dom0.h) \
  include/asm-generic/iomap.h \
  include/linux/vmalloc.h \
    $(wildcard include/config/mmu.h) \
  include/linux/spinlock.h \
    $(wildcard include/config/debug/spinlock.h) \
    $(wildcard include/config/generic/lockbreak.h) \
    $(wildcard include/config/preempt.h) \
    $(wildcard include/config/debug/lock/alloc.h) \
  include/linux/preempt.h \
    $(wildcard include/config/debug/preempt.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/preempt/notifiers.h) \
  include/linux/thread_info.h \
    $(wildcard include/config/compat.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/thread_info.h \
    $(wildcard include/config/debug/stack/usage.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/processor.h \
    $(wildcard include/config/x86/vsmp.h) \
    $(wildcard include/config/cc/stackprotector.h) \
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
  include/linux/init.h \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/hotplug.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/math_emu.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/sigcontext.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/current.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/percpu.h \
    $(wildcard include/config/x86/64/smp.h) \
  include/asm-generic/percpu.h \
    $(wildcard include/config/have/setup/per/cpu/area.h) \
  include/linux/threads.h \
    $(wildcard include/config/nr/cpus.h) \
    $(wildcard include/config/base/small.h) \
  include/linux/percpu-defs.h \
    $(wildcard include/config/debug/force/weak/per/cpu.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/system.h \
    $(wildcard include/config/ia32/emulation.h) \
    $(wildcard include/config/x86/32/lazy/gs.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/cmpxchg.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/cmpxchg_32.h \
    $(wildcard include/config/x86/cmpxchg.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/nops.h \
    $(wildcard include/config/mk7.h) \
  include/linux/irqflags.h \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/irqflags.h \
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
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/ftrace.h \
    $(wildcard include/config/function/tracer.h) \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/atomic.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/atomic64_32.h \
  include/asm-generic/atomic-long.h \
  include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  include/linux/poison.h \
    $(wildcard include/config/illegal/pointer/value.h) \
  include/linux/prefetch.h \
  include/linux/bottom_half.h \
  include/linux/spinlock_types.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/spinlock_types.h \
  include/linux/lockdep.h \
    $(wildcard include/config/lockdep.h) \
    $(wildcard include/config/lock/stat.h) \
    $(wildcard include/config/prove/rcu.h) \
  include/linux/rwlock_types.h \
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
  drivers/staging/emgd/include/igd_debug.h \
  drivers/staging/emgd/include/igd_init.h \
    $(wildcard include/config/bin.h) \
  drivers/staging/emgd/include/igd.h \
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
  drivers/staging/emgd/include/igd_pwr.h \
  drivers/staging/emgd/emgd/include/module_init.h \
    $(wildcard include/config/2d.h) \
    $(wildcard include/config/blend.h) \
    $(wildcard include/config/cmd.h) \
    $(wildcard include/config/reset.h) \
    $(wildcard include/config/interrupt.h) \
  drivers/staging/emgd/emgd/include/context.h \
  drivers/staging/emgd/emgd/include/pci.h \
    $(wildcard include/config/8.h) \
    $(wildcard include/config/16.h) \
    $(wildcard include/config/32.h) \
  drivers/staging/emgd/emgd/include/mode.h \
  drivers/staging/emgd/emgd/include/general.h \
  drivers/staging/emgd/emgd/include/cmd.h \
  drivers/staging/emgd/emgd/include/pd.h \
  drivers/staging/emgd/emgd/include/edid.h \
  drivers/staging/emgd/emgd/include/displayid.h \
  drivers/staging/emgd/emgd/include/dsp.h \
  drivers/staging/emgd/emgd/include/intelpci.h \
  drivers/staging/emgd/emgd/include/dispatch.h \
  drivers/staging/emgd/emgd/state/power/cmn/pwr_dispatch.h \

drivers/staging/emgd/emgd/state/power/cmn/igd_pwr.o: $(deps_drivers/staging/emgd/emgd/state/power/cmn/igd_pwr.o)

$(deps_drivers/staging/emgd/emgd/state/power/cmn/igd_pwr.o):
