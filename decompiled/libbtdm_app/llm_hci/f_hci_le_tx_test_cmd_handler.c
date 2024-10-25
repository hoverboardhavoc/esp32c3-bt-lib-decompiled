/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm_hci.o -> f_hci_le_tx_test_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_tx_test_cmd_handler(byte *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 uStack_18;
  byte bStack_17;
  byte bStack_16;
  byte bStack_15;
  undefined1 uStack_14;
  
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x50c))(*(code **)(_r_ip_funcs_p + 0x50c));
  uVar2 = 0xc;
  if (((iVar1 != 0) && (uVar2 = 0x12, *param_1 < 0x28)) && (param_1[2] < 8)) {
    rw_rf_le_enter_test_mode(0x12);
    bStack_17 = *param_1;
    uStack_18 = 1;
    bStack_16 = param_1[1];
    uStack_14 = 1;
    bStack_15 = param_1[2];
    uVar2 = (**(code **)(_r_ip_funcs_p + 0x218))(&uStack_18,*(code **)(_r_ip_funcs_p + 0x218));
  }
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar2,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

