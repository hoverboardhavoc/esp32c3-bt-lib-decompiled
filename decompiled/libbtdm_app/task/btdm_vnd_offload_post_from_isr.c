/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> task.o -> btdm_vnd_offload_post_from_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 btdm_vnd_offload_post_from_isr(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iStack_28;
  undefined4 uStack_24;
  
  if (param_1 == 0) {
    iStack_28 = 0xd;
    uStack_24 = param_2;
    iVar1 = (**(code **)(_r_osi_funcs_p + 0x58))
                      (_g_rw_schd_queue,&iStack_28,0,*(code **)(_r_osi_funcs_p + 0x58));
    if (iVar1 != 1) {
      (**(code **)(_r_plf_funcs_p + 0xc))(0xd,0,"task.c",0x59,*(code **)(_r_plf_funcs_p + 0xc));
    }
    iStack_28 = 0;
    (**(code **)(_r_osi_funcs_p + 0x30))(g_rw_schd_sem,&iStack_28,*(code **)(_r_osi_funcs_p + 0x30))
    ;
    if ((param_3 != 0) && (iStack_28 != 0)) {
      (**(code **)(_r_osi_funcs_p + 0x20))(*(code **)(_r_osi_funcs_p + 0x20));
    }
    return 0;
  }
  return 0xffffffff;
}

