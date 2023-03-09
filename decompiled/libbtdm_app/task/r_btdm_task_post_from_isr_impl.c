/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> task.o -> r_btdm_task_post_from_isr_impl
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
r_btdm_task_post_from_isr_impl(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  if ((0x2f84U >> (param_1 & 0x1f) & 1) != 0) {
    uStack_28 = (uint)CONCAT11((char)param_2,(char)param_1);
    uStack_24 = param_3;
    iVar2 = (**(code **)(_r_osi_funcs_p + 0x58))
                      (_g_rw_schd_queue,&uStack_28,0,*(code **)(_r_osi_funcs_p + 0x58));
    if (iVar2 != 1) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (param_1,param_2,"task.c",0x60,*(code **)(_r_plf_funcs_p + 0xc));
    }
  }
  uStack_28 = 0;
  pcVar1 = *(code **)(_r_osi_funcs_p + 0x30);
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xf8))(*(code **)(_r_plf_funcs_p + 0xf8));
  (*pcVar1)(*(undefined4 *)(iVar2 + 4),&uStack_28);
  if ((param_4 != 0) && (uStack_28 != 0)) {
    (**(code **)(_r_osi_funcs_p + 0x20))(*(code **)(_r_osi_funcs_p + 0x20));
  }
  return 0;
}

