/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_enh_rx_test_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_enh_rx_test_cmd_handler(byte *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 uStack_18;
  byte bStack_17;
  undefined4 uStack_14;
  
  uStack_14 = param_2;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  uVar1 = uStack_14;
  if (*(char *)(iVar2 + 0x1f) != '\0') {
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x50c))(*(code **)(_r_ip_funcs_p + 0x50c));
    uVar3 = 0xc;
    if ((((iVar2 != 0) && (uVar3 = 0x12, *param_1 < 0x28)) && ((byte)(param_1[1] - 1) < 3)) &&
       (param_1[2] < 2)) {
      rw_rf_le_enter_test_mode(0x12);
      bStack_17 = *param_1;
      uStack_18 = 0;
      uStack_14 = CONCAT31(uStack_14._1_3_,param_1[1]);
      uVar3 = (**(code **)(_r_ip_funcs_p + 0x218))(&uStack_18,*(code **)(_r_ip_funcs_p + 0x218));
    }
    (**(code **)(_r_ip_funcs_p + 0x4b8))(uVar1,uVar3,*(code **)(_r_ip_funcs_p + 0x4b8));
    return 0;
  }
  (**(code **)(_r_ip_funcs_p + 0x4b8))(uStack_14,0xc,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

