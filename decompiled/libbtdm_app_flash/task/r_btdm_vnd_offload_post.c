/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> task.o -> r_btdm_vnd_offload_post
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x0001005a) */
/* WARNING: Removing unreachable block (ram,0x00010072) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_btdm_vnd_offload_post(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  if (param_1 < 2) {
    uStack_28 = (uint)CONCAT11((char)param_1,0xd);
    uStack_24 = param_2;
    iVar2 = (**(code **)(_r_osi_funcs_p + 0x54))
                      (_g_rw_schd_queue,&uStack_28,0xffffffff,*(code **)(_r_osi_funcs_p + 0x54));
    if (iVar2 == 1) {
      uVar1 = 0;
    }
    else {
      if (0 < _g_bt_plf_log_level) {
        ets_printf("Send Queue Failed\n");
      }
      uVar1 = 0xfffffffd;
      (**(code **)(_r_osi_funcs_p + 0x7c))(uStack_24,*(code **)(_r_osi_funcs_p + 0x7c));
    }
    (**(code **)(_r_osi_funcs_p + 0x38))(btdm_ol_task_env._8_4_,*(code **)(_r_osi_funcs_p + 0x38));
    return uVar1;
  }
  return 0xffffffff;
}

