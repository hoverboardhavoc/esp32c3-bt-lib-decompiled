/*
 * Last changed at upstream commit 3ff529142f6e2707d57b10eb87ac8d86e9098b88
 * https://github.com/espressif/esp32c3-bt-lib/commit/3ff529142f6e2707d57b10eb87ac8d86e9098b88
 * Upstream date: 2025-06-05 11:04:06 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(4713a69)
 * Source: libbtdm_app_flash -> task.o -> r_btdm_task_post_from_isr_hack
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
        r_assert_param(param_1 & 0xff,0,"task.c",0x61);
      }
    }
    auStack_28[0] = 0;
    (**(code **)(_r_osi_funcs_p + 0x30))
              (btdm_ol_task_env._8_4_,auStack_28,*(code **)(_r_osi_funcs_p + 0x30));
    if (auStack_28[0] != 0) {
      (**(code **)(_r_osi_funcs_p + 0x20))(*(code **)(_r_osi_funcs_p + 0x20));
    }
    return 0;
  }
  return 0xffffffff;
}

