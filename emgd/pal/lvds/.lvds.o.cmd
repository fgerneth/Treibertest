cmd_drivers/staging/emgd/emgd/pal/lvds/lvds.o := gcc -Wp,-MD,drivers/staging/emgd/emgd/pal/lvds/.lvds.o.d  -nostdinc -isystem /usr/lib/gcc/i586-meego-linux/4.5.1/include -I/root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include -Iinclude  -include include/generated/autoconf.h -D__KERNEL__ -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -Os -m32 -msoft-float -mregparm=3 -freg-struct-return -mpreferred-stack-boundary=2 -march=atom -mtune=atom -mtune=generic -Wa,-mtune=generic32 -ffreestanding -DCONFIG_AS_CFI=1 -DCONFIG_AS_CFI_SIGNAL_FRAME=1 -DCONFIG_AS_CFI_SECTIONS=1 -pipe -Wno-sign-compare -fno-asynchronous-unwind-tables -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -Wframe-larger-than=1024 -fno-stack-protector -fno-omit-frame-pointer -fno-optimize-sibling-calls -g -pg -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO -Idrivers/staging/emgd/include -Idrivers/staging/emgd/emgd/display/mode/cmn -Idrivers/staging/emgd/emgd/video/overlay/cmn -Idrivers/staging/emgd/emgd/video/msvdx -Idrivers/staging/emgd/emgd/include -Idrivers/staging/emgd/emgd/cfg -Idrivers/staging/emgd/emgd/pal/lpd -Idrivers/staging/emgd/emgd/drm -Iinclude/drm -Idrivers/staging/emgd/pvr/include4 -Idrivers/staging/emgd/pvr/services4/include -Idrivers/staging/emgd/pvr/services4/include/env/linux -Idrivers/staging/emgd/pvr/services4/srvkm/env/linux -Idrivers/staging/emgd/pvr/services4/srvkm/include -Idrivers/staging/emgd/pvr/services4/srvkm/bridged -Idrivers/staging/emgd/pvr/services4/system/plb -Idrivers/staging/emgd/pvr/services4/system/tnc -Idrivers/staging/emgd/pvr/services4/system/include -Idrivers/staging/emgd/pvr/services4/srvkm/hwdefs -Idrivers/staging/emgd/pvr/services4/srvkm/bridged/sgx -Idrivers/staging/emgd/pvr/services4/srvkm/devices/sgx -Idrivers/staging/emgd/pvr/tools/intern/debug -DSUPPORT_DRI_DRM_EXT -DLINUX -DPVR_BUILD_DIR="\"emgd\"" -DPVR_BUILD_DATE="20100408" -DPVR_SECURE_HANDLES -DPVR_PROC_USE_SEQ_FILE -DLDM_PCI -DSUPPORT_CACHEFLUSH_ON_ALLOC -DSUPPORT_DRI_DRM -DSGX535 -DSGX_CORE_REV=121 -UDEBUG_LOG_PATH_TRUNCATE -DDISPLAY_CONTROLLER=emgd_dc -D_XOPEN_SOURCE=600 -DSERVICES4 -DPVR2D_VALIDATE_INPUT_PARAMS -DSUPPORT_SRVINIT -DSUPPORT_SGX -DSUPPORT_PERCONTEXT_PB -DSUPPORT_LINUX_X86_WRITECOMBINE -DSUPPORT_SECURE_DRM_AUTH_EXPORT -DSUPPORT_PDUMP_DELAYED_INITPHASE_TERMINATION -DTRANSFER_QUEUE -DSYS_USING_INTERRUPTS -DSUPPORT_HW_RECOVERY -DSUPPORT_ACTIVE_POWER_MANAGEMENT -DPVR_SECURE_HANDLES -DUSE_PTHREADS -DSUPPORT_SGX_EVENT_OBJECT -DSUPPORT_SGX_HWPERF -DSUPPORT_SGX_LOW_LATENCY_SCHEDULING -DSUPPORT_LINUX_X86_PAT -DSUPPORT_SGX535 -DSUPPORT_CACHE_LINE_FLUSH -DSUPPORT_CPU_CACHED_BUFFERS -DDEBUG_MESA_OGL_TRACE -DSUPPORT_EGL_IMAGE_SYNC_DEPENDENCY -DBUILD="\"release\"" -DPVR_BUILD_TYPE="\"release\"" -DRELEASE  -DMODULE  -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(lvds)"  -D"KBUILD_MODNAME=KBUILD_STR(emgd)" -c -o drivers/staging/emgd/emgd/pal/lvds/lvds.o drivers/staging/emgd/emgd/pal/lvds/lvds.c

deps_drivers/staging/emgd/emgd/pal/lvds/lvds.o := \
  drivers/staging/emgd/emgd/pal/lvds/lvds.c \
    $(wildcard include/config/855.h) \
    $(wildcard include/config/915al.h) \
    $(wildcard include/config/945gm.h) \
    $(wildcard include/config/965gm.h) \
    $(wildcard include/config/ctg.h) \
    $(wildcard include/config/plb.h) \
    $(wildcard include/config/tnc.h) \
    $(wildcard include/config/micro.h) \
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
    $(wildcard include/config/865.h) \
    $(wildcard include/config/915gd.h) \
    $(wildcard include/config/945g.h) \
    $(wildcard include/config/945gme.h) \
    $(wildcard include/config/q35.h) \
    $(wildcard include/config/965g.h) \
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
  drivers/staging/emgd/include/igd_pd.h \
  drivers/staging/emgd/emgd/include/pd.h \
  drivers/staging/emgd/include/igd_debug.h \
  drivers/staging/emgd/emgd/pal/lpd/pd_print.h \
  drivers/staging/emgd/emgd/pal/lvds/lvds.h \
  drivers/staging/emgd/emgd/include/pci.h \
    $(wildcard include/config/8.h) \
    $(wildcard include/config/16.h) \
    $(wildcard include/config/32.h) \

drivers/staging/emgd/emgd/pal/lvds/lvds.o: $(deps_drivers/staging/emgd/emgd/pal/lvds/lvds.o)

$(deps_drivers/staging/emgd/emgd/pal/lvds/lvds.o):
