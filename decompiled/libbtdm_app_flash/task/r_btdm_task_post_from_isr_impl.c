/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> task.o -> r_btdm_task_post_from_isr_impl
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
r_btdm_task_post_from_isr_impl(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

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
      r_assert_param(param_1,param_2,"task.c",0x5f);
    }
  }
  uStack_28 = 0;
  (**(code **)(_r_osi_funcs_p + 0x30))
            (btdm_ol_task_env._8_4_,&uStack_28,*(code **)(_r_osi_funcs_p + 0x30));
  if ((param_4 != 0) && (uStack_28 != 0)) {
    (**(code **)(_r_osi_funcs_p + 0x20))(*(code **)(_r_osi_funcs_p + 0x20));
  }
  return 0;
}

