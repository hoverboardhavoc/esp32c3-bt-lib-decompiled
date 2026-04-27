/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llm_init.o -> hci_le_create_con_cancel_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_create_con_cancel_cmd_handler(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar3 + 0x22) == '\0') {
    r_llm_cmd_cmp_send(param_2,0xc);
    return 0;
  }
  uVar1 = 0;
  while ((iVar3 = r_sdk_config_get_opts(), uVar1 < *(byte *)(iVar3 + 0xd) &&
         (*(char *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44 + 0x40) != '\x05'))) {
    uVar1 = uVar1 + 1 & 0xff;
  }
  iVar3 = r_sdk_config_get_opts();
  if (uVar1 < *(byte *)(iVar3 + 0xd)) {
    iVar3 = uVar1 * 0x44;
    if (*(int *)(*(int *)(_p_llm_env + 8) + iVar3) == 0) {
      r_assert_err(0,0x10000,0x274);
    }
    iVar2 = r_lld_init_stop();
    if (iVar2 == 0xc) {
      r_ke_msg_forward(param_1,0,param_2);
      r_ble_log_internal_x1(0x802e01ec,0xc);
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
    r_ke_msg_free(*(int *)(*(int *)(_p_llm_env + 8) + iVar3) + -0xc);
    *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar3) = 0;
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

