cmd_drivers/staging/emgd/emgd/pal/sdvo/sdvo_port.o := gcc -Wp,-MD,drivers/staging/emgd/emgd/pal/sdvo/.sdvo_port.o.d  -nostdinc -isystem /usr/lib/gcc/i586-meego-linux/4.5.1/include -I/root/rpmbuild/BUILD/kernel-adaptation-connext-2.6.37.6/linux-2.6.37/arch/x86/include -Iinclude  -include include/generated/autoconf.h -D__KERNEL__ -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -Os -m32 -msoft-float -mregparm=3 -freg-struct-return -mpreferred-stack-boundary=2 -march=atom -mtune=atom -mtune=generic -Wa,-mtune=generic32 -ffreestanding -DCONFIG_AS_CFI=1 -DCONFIG_AS_CFI_SIGNAL_FRAME=1 -DCONFIG_AS_CFI_SECTIONS=1 -pipe -Wno-sign-compare -fno-asynchronous-unwind-tables -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -Wframe-larger-than=1024 -fno-stack-protector -fno-omit-frame-pointer -fno-optimize-sibling-calls -g -pg -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO -Idrivers/staging/emgd/include -Idrivers/staging/emgd/emgd/display/mode/cmn -Idrivers/staging/emgd/emgd/video/overlay/cmn -Idrivers/staging/emgd/emgd/video/msvdx -Idrivers/staging/emgd/emgd/include -Idrivers/staging/emgd/emgd/cfg -Idrivers/staging/emgd/emgd/pal/lpd -Idrivers/staging/emgd/emgd/drm -Iinclude/drm -Idrivers/staging/emgd/pvr/include4 -Idrivers/staging/emgd/pvr/services4/include -Idrivers/staging/emgd/pvr/services4/include/env/linux -Idrivers/staging/emgd/pvr/services4/srvkm/env/linux -Idrivers/staging/emgd/pvr/services4/srvkm/include -Idrivers/staging/emgd/pvr/services4/srvkm/bridged -Idrivers/staging/emgd/pvr/services4/system/plb -Idrivers/staging/emgd/pvr/services4/system/tnc -Idrivers/staging/emgd/pvr/services4/system/include -Idrivers/staging/emgd/pvr/services4/srvkm/hwdefs -Idrivers/staging/emgd/pvr/services4/srvkm/bridged/sgx -Idrivers/staging/emgd/pvr/services4/srvkm/devices/sgx -Idrivers/staging/emgd/pvr/tools/intern/debug -DSUPPORT_DRI_DRM_EXT -DLINUX -DPVR_BUILD_DIR="\"emgd\"" -DPVR_BUILD_DATE="20100408" -DPVR_SECURE_HANDLES -DPVR_PROC_USE_SEQ_FILE -DLDM_PCI -DSUPPORT_CACHEFLUSH_ON_ALLOC -DSUPPORT_DRI_DRM -DSGX535 -DSGX_CORE_REV=121 -UDEBUG_LOG_PATH_TRUNCATE -DDISPLAY_CONTROLLER=emgd_dc -D_XOPEN_SOURCE=600 -DSERVICES4 -DPVR2D_VALIDATE_INPUT_PARAMS -DSUPPORT_SRVINIT -DSUPPORT_SGX -DSUPPORT_PERCONTEXT_PB -DSUPPORT_LINUX_X86_WRITECOMBINE -DSUPPORT_SECURE_DRM_AUTH_EXPORT -DSUPPORT_PDUMP_DELAYED_INITPHASE_TERMINATION -DTRANSFER_QUEUE -DSYS_USING_INTERRUPTS -DSUPPORT_HW_RECOVERY -DSUPPORT_ACTIVE_POWER_MANAGEMENT -DPVR_SECURE_HANDLES -DUSE_PTHREADS -DSUPPORT_SGX_EVENT_OBJECT -DSUPPORT_SGX_HWPERF -DSUPPORT_SGX_LOW_LATENCY_SCHEDULING -DSUPPORT_LINUX_X86_PAT -DSUPPORT_SGX535 -DSUPPORT_CACHE_LINE_FLUSH -DSUPPORT_CPU_CACHED_BUFFERS -DDEBUG_MESA_OGL_TRACE -DSUPPORT_EGL_IMAGE_SYNC_DEPENDENCY -DBUILD="\"release\"" -DPVR_BUILD_TYPE="\"release\"" -DRELEASE  -DMODULE  -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(sdvo_port)"  -D"KBUILD_MODNAME=KBUILD_STR(emgd)" -c -o drivers/staging/emgd/emgd/pal/sdvo/sdvo_port.o drivers/staging/emgd/emgd/pal/sdvo/sdvo_port.c

deps_drivers/staging/emgd/emgd/pal/sdvo/sdvo_port.o := \
  drivers/staging/emgd/emgd/pal/sdvo/sdvo_port.c \
    $(wildcard include/config/micro.h) \
  drivers/staging/emgd/emgd/pal/sdvo/sdvo_port.h \
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
  drivers/staging/emgd/include/igd_pd.h \
  drivers/staging/emgd/emgd/include/pd.h \
  drivers/staging/emgd/include/igd_debug.h \
  drivers/staging/emgd/emgd/pal/lpd/pd_print.h \
  drivers/staging/emgd/emgd/pal/sdvo/sdvo_intf.h \
  drivers/staging/emgd/emgd/pal/sdvo/sdvo_attr.h \
  drivers/staging/emgd/emgd/pal/sdvo/sdvo_hdmi.h \

drivers/staging/emgd/emgd/pal/sdvo/sdvo_port.o: $(deps_drivers/staging/emgd/emgd/pal/sdvo/sdvo_port.o)

$(deps_drivers/staging/emgd/emgd/pal/sdvo/sdvo_port.o):
