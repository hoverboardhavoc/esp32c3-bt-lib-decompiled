/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> task.o -> btdm_task_post_from_isr_impl
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
btdm_task_post_from_isr_impl(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  if ((0x2f84U >> (param_1 & 0x1f) & 1) != 0) {
    uStack_28 = (uint)CONCAT11((char)param_2,(char)param_1);
    uStack_24 = param_3;
    iVar1 = (**(code **)(_r_osi_funcs_p + 0x58))
                      (_g_rw_schd_queue,&uStack_28,0,*(code **)(_r_osi_funcs_p + 0x58));
    if (iVar1 != 1) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (param_1,param_2,"task.c",0x59,*(code **)(_r_plf_funcs_p + 0xc));
    }
  }
  uStack_28 = 0;
  (**(code **)(_r_osi_funcs_p + 0x30))(g_rw_schd_sem,&uStack_28,*(code **)(_r_osi_funcs_p + 0x30));
  if ((param_4 != 0) && (uStack_28 != 0)) {
    (**(code **)(_r_osi_funcs_p + 0x20))(*(code **)(_r_osi_funcs_p + 0x20));
  }
  return 0;
}

