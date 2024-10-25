/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm_scan.o -> hci_le_per_adv_term_sync_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_per_adv_term_sync_cmd_handler(byte *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar2 + 0x18) == '\0') {
    (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,0xc,*(code **)(_r_ip_funcs_p + 0x4b8));
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar1 = (uint)*param_1;
    iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if ((uVar1 < *(byte *)(iVar2 + 0xd)) &&
       (*(char *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44 + 0x40) == '\x0f')) {
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x174))(uVar1,*(code **)(_r_ip_funcs_p + 0x174));
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
      goto _L227;
    }
  }
  iVar2 = 0xc;
_L227:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar2,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

