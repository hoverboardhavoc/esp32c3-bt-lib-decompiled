/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_scan.o -> f_hci_le_per_adv_term_sync_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_per_adv_term_sync_cmd_handler(byte *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar1 = (uint)*param_1;
    iVar2 = r_sdk_config_get_opts();
    if ((uVar1 < *(byte *)(iVar2 + 0xd)) &&
       (*(char *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44 + 0x40) == '\x0f')) {
      iVar2 = r_lld_sync_stop(uVar1);
      if (iVar2 == 0) {
        *(undefined1 *)(uVar1 * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) = 0x10;
        if (_bt_rf_coex_hooks_p == (undefined4 *)0x0) {
          return 0;
        }
        if ((code *)*_bt_rf_coex_hooks_p == (code *)0x0) {
          return 0;
        }
        (*(code *)*_bt_rf_coex_hooks_p)(uVar1,5,0);
        return 0;
      }
      goto _L87;
    }
  }
  iVar2 = 0xc;
_L87:
  r_llm_cmd_cmp_send(param_2,iVar2);
  return 0;
}

