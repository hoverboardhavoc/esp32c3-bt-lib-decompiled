/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> task.o -> r_btdm_task_post_from_isr_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_btdm_task_post_from_isr_hack(uint param_1)

{
  int iVar1;
  uint auStack_28 [5];
  
  if (param_1 < 0xe) {
    if ((0x2f84U >> (param_1 & 0x1f) & 1) != 0) {
      auStack_28[0] = param_1 & 0xff;
      auStack_28[1] = 0;
      iVar1 = (**(code **)(_r_osi_funcs_p + 0x58))
                        (_g_rw_schd_queue,auStack_28,0,*(code **)(_r_osi_funcs_p + 0x58));
      if (iVar1 != 1) {
        (**(code **)(_r_plf_funcs_p + 0xc))
                  (param_1 & 0xff,0,"task.c",0x59,*(code **)(_r_plf_funcs_p + 0xc));
      }
    }
    auStack_28[0] = 0;
    (**(code **)(_r_osi_funcs_p + 0x30))(g_rw_schd_sem,auStack_28,*(code **)(_r_osi_funcs_p + 0x30))
    ;
    if (auStack_28[0] != 0) {
      (**(code **)(_r_osi_funcs_p + 0x20))(*(code **)(_r_osi_funcs_p + 0x20));
    }
    return 0;
  }
  return 0xffffffff;
}

