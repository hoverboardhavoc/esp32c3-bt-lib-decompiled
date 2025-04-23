/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> task.o -> r_btdm_vnd_offload_post
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010062) */
/* WARNING: Removing unreachable block (ram,0x0001007a) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_btdm_vnd_offload_post(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined2 uStack_26;
  undefined4 uStack_24;
  
  if (param_1 < 2) {
    uStack_26 = 0;
    uStack_28 = 0xd;
    uStack_27 = (undefined1)param_1;
    uStack_24 = param_2;
    iVar1 = (**(code **)(_r_osi_funcs_p + 0x54))
                      (_g_rw_schd_queue,&uStack_28,0xffffffff,*(code **)(_r_osi_funcs_p + 0x54));
    if (iVar1 == 1) {
      uVar2 = 0;
    }
    else {
      if (0 < _g_bt_plf_log_level) {
        ets_printf("Send Queue Failed\n");
      }
      uVar2 = 0xfffffffd;
      (**(code **)(_r_osi_funcs_p + 0x7c))(uStack_24,*(code **)(_r_osi_funcs_p + 0x7c));
    }
    (**(code **)(_r_osi_funcs_p + 0x38))(btdm_ol_task_env._8_4_,*(code **)(_r_osi_funcs_p + 0x38));
    return uVar2;
  }
  return 0xffffffff;
}

