/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_set_priv_mode_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_priv_mode_cmd_handler(byte *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(char *)(_p_llm_env + 0xc6) != '\0') {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x504))(*(code **)(_r_ip_funcs_p + 0x504));
    uVar2 = 0xc;
    if (iVar1 != 0) goto _L60;
  }
  uVar2 = 0x12;
  if (param_1[7] < 2) {
    uVar2 = 0x12;
    if (*param_1 < 2) {
      uVar2 = (**(code **)(_r_ip_funcs_p + 0x28c))(param_1 + 1,*(code **)(_r_ip_funcs_p + 0x28c));
    }
  }
_L60:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar2,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

