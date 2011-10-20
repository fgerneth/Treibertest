cmd_drivers/staging/emgd/pvr/services4/system/common/sysutils.o := gcc -Wp,-MD,drivers/staging/emgd/pvr/services4/system/common/.sysutils.o.d  -nostdinc -isystem /usr/lib/gcc/i586-meego-linux/4.5.1/include -I/root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include -Iinclude  -include include/generated/autoconf.h -D__KERNEL__ -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -Os -m32 -msoft-float -mregparm=3 -freg-struct-return -mpreferred-stack-boundary=2 -march=atom -mtune=atom -mtune=generic -Wa,-mtune=generic32 -ffreestanding -DCONFIG_AS_CFI=1 -DCONFIG_AS_CFI_SIGNAL_FRAME=1 -DCONFIG_AS_CFI_SECTIONS=1 -pipe -Wno-sign-compare -fno-asynchronous-unwind-tables -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -Wframe-larger-than=1024 -fno-stack-protector -fno-omit-frame-pointer -fno-optimize-sibling-calls -g -pg -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO -Idrivers/staging/emgd/include -Idrivers/staging/emgd/emgd/display/mode/cmn -Idrivers/staging/emgd/emgd/video/overlay/cmn -Idrivers/staging/emgd/emgd/video/msvdx -Idrivers/staging/emgd/emgd/include -Idrivers/staging/emgd/emgd/cfg -Idrivers/staging/emgd/emgd/pal/lpd -Idrivers/staging/emgd/emgd/drm -Iinclude/drm -Idrivers/staging/emgd/pvr/include4 -Idrivers/staging/emgd/pvr/services4/include -Idrivers/staging/emgd/pvr/services4/include/env/linux -Idrivers/staging/emgd/pvr/services4/srvkm/env/linux -Idrivers/staging/emgd/pvr/services4/srvkm/include -Idrivers/staging/emgd/pvr/services4/srvkm/bridged -Idrivers/staging/emgd/pvr/services4/system/plb -Idrivers/staging/emgd/pvr/services4/system/tnc -Idrivers/staging/emgd/pvr/services4/system/include -Idrivers/staging/emgd/pvr/services4/srvkm/hwdefs -Idrivers/staging/emgd/pvr/services4/srvkm/bridged/sgx -Idrivers/staging/emgd/pvr/services4/srvkm/devices/sgx -Idrivers/staging/emgd/pvr/tools/intern/debug -DSUPPORT_DRI_DRM_EXT -DLINUX -DPVR_BUILD_DIR="\"emgd\"" -DPVR_BUILD_DATE="20100408" -DPVR_SECURE_HANDLES -DPVR_PROC_USE_SEQ_FILE -DLDM_PCI -DSUPPORT_CACHEFLUSH_ON_ALLOC -DSUPPORT_DRI_DRM -DSGX535 -DSGX_CORE_REV=121 -UDEBUG_LOG_PATH_TRUNCATE -DDISPLAY_CONTROLLER=emgd_dc -D_XOPEN_SOURCE=600 -DSERVICES4 -DPVR2D_VALIDATE_INPUT_PARAMS -DSUPPORT_SRVINIT -DSUPPORT_SGX -DSUPPORT_PERCONTEXT_PB -DSUPPORT_LINUX_X86_WRITECOMBINE -DSUPPORT_SECURE_DRM_AUTH_EXPORT -DSUPPORT_PDUMP_DELAYED_INITPHASE_TERMINATION -DTRANSFER_QUEUE -DSYS_USING_INTERRUPTS -DSUPPORT_HW_RECOVERY -DSUPPORT_ACTIVE_POWER_MANAGEMENT -DPVR_SECURE_HANDLES -DUSE_PTHREADS -DSUPPORT_SGX_EVENT_OBJECT -DSUPPORT_SGX_HWPERF -DSUPPORT_SGX_LOW_LATENCY_SCHEDULING -DSUPPORT_LINUX_X86_PAT -DSUPPORT_SGX535 -DSUPPORT_CACHE_LINE_FLUSH -DSUPPORT_CPU_CACHED_BUFFERS -DDEBUG_MESA_OGL_TRACE -DSUPPORT_EGL_IMAGE_SYNC_DEPENDENCY -DBUILD="\"release\"" -DPVR_BUILD_TYPE="\"release\"" -DRELEASE  -DMODULE  -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(sysutils)"  -D"KBUILD_MODNAME=KBUILD_STR(emgd)" -c -o drivers/staging/emgd/pvr/services4/system/common/sysutils.o drivers/staging/emgd/pvr/services4/system/common/sysutils.c

deps_drivers/staging/emgd/pvr/services4/system/common/sysutils.o := \
  drivers/staging/emgd/pvr/services4/system/common/sysutils.c \
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
  include/linux/seq_file.h \
  include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
  /usr/lib/gcc/i586-meego-linux/4.5.1/include/stdarg.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/string.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/string_32.h \
    $(wildcard include/config/x86/use/3dnow.h) \
    $(wildcard include/config/kmemcheck.h) \
  include/linux/mutex.h \
    $(wildcard include/config/debug/mutexes.h) \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/debug/lock/alloc.h) \
  include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  include/linux/poison.h \
    $(wildcard include/config/illegal/pointer/value.h) \
  include/linux/prefetch.h \
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/processor.h \
    $(wildcard include/config/x86/vsmp.h) \
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
  /root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include/asm/page.h \
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
    $(wildcard include/config/h.h) \
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
  drivers/staging/emgd/pvr/services4/system/include/syslocal.h \

drivers/staging/emgd/pvr/services4/system/common/sysutils.o: $(deps_drivers/staging/emgd/pvr/services4/system/common/sysutils.o)

$(deps_drivers/staging/emgd/pvr/services4/system/common/sysutils.o):
