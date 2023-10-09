/*
 * Last changed at upstream commit 7fb979154bec81163d55aa4e3134425aea0d52ab
 * https://github.com/espressif/esp32c3-bt-lib/commit/7fb979154bec81163d55aa4e3134425aea0d52ab
 * Upstream date: 2023-10-09 11:09:21 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(510fd043)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_enh_tx_test_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_enh_tx_test_cmd_handler(byte *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 uStack_18;
  byte bStack_17;
  byte bStack_16;
  byte bStack_15;
  byte bStack_14;
  
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x50c))(*(code **)(_r_ip_funcs_p + 0x50c));
  uVar2 = 0xc;
  if ((((iVar1 != 0) && (uVar2 = 0x12, *param_1 < 0x28)) && (param_1[2] < 8)) &&
     ((byte)(param_1[3] - 1) < 4)) {
    rw_rf_le_enter_test_mode(0x12);
    uStack_18 = 1;
    bStack_17 = *param_1;
    bStack_16 = param_1[1];
    bStack_15 = param_1[2];
    bStack_14 = param_1[3];
    uVar2 = (**(code **)(_r_ip_funcs_p + 0x218))(&uStack_18,*(code **)(_r_ip_funcs_p + 0x218));
  }
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar2,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

