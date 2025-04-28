/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_rx_test_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rx_test_cmd_handler(byte *param_1,undefined4 param_2)

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
    if ((iVar2 != 0) && (uVar3 = 0x12, *param_1 < 0x28)) {
      rw_rf_le_enter_test_mode(0x12);
      bStack_17 = *param_1;
      uStack_18 = 0;
      uStack_14 = CONCAT31(uStack_14._1_3_,1);
      uVar3 = (**(code **)(_r_ip_funcs_p + 0x218))(&uStack_18,*(code **)(_r_ip_funcs_p + 0x218));
    }
    (**(code **)(_r_ip_funcs_p + 0x4b8))(uVar1,uVar3,*(code **)(_r_ip_funcs_p + 0x4b8));
    return 0;
  }
  (**(code **)(_r_ip_funcs_p + 0x4b8))(uStack_14,0xc,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

