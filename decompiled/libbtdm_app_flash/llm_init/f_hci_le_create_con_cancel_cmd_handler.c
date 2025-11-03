/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llm_init.o -> f_hci_le_create_con_cancel_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_create_con_cancel_cmd_handler(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar1 = 0;
  while ((iVar2 = r_sdk_config_get_opts(), uVar1 < *(byte *)(iVar2 + 0xd) &&
         (*(char *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44 + 0x40) != '\x05'))) {
    uVar1 = uVar1 + 1 & 0xff;
  }
  iVar2 = r_sdk_config_get_opts();
  if (uVar1 < *(byte *)(iVar2 + 0xd)) {
    iVar2 = uVar1 * 0x44;
    if (*(int *)(*(int *)(_p_llm_env + 8) + iVar2) == 0) {
      r_assert_err(0,0x10000,0x26b);
    }
    iVar3 = r_lld_init_stop();
    if (iVar3 == 0xc) {
      r_ke_msg_forward(param_1,0,param_2);
      r_ble_log_internal_x1(0x802e0163,0xc);
      return 1;
    }
    if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) && ((code *)*_bt_rf_coex_hooks_p != (code *)0x0))
    {
      uVar4 = 3;
      if (*(char *)(_p_llm_env + 0xd7) != '\x02') {
        uVar4 = 1;
      }
      (*(code *)*_bt_rf_coex_hooks_p)(uVar1,uVar4,0);
    }
    r_ke_msg_free(*(int *)(*(int *)(_p_llm_env + 8) + iVar2) + -0xc);
    *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar2) = 0;
  }
  else {
    uVar4 = 0xc;
    if ((_sdk_cfg_priv_opts & 0x20) != 0) {
      uVar4 = 0;
    }
    r_llm_cmd_cmp_send(param_2,uVar4);
  }
  return 0;
}

