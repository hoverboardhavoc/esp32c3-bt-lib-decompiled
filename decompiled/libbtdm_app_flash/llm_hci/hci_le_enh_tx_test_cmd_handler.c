/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_enh_tx_test_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_le_enh_tx_test_cmd_handler(byte *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 uStack_18;
  byte bStack_17;
  byte bStack_16;
  byte bStack_15;
  byte bStack_14;
  
  iVar1 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x1f) == '\0') {
    r_llm_cmd_cmp_send(param_2,0xc);
    return 0;
  }
  iVar1 = r_llm_no_activity();
  uVar2 = 0xc;
  if ((((iVar1 != 0) && (uVar2 = 0x12, *param_1 < 0x28)) && (param_1[2] < 8)) &&
     ((byte)(param_1[3] - 1) < 4)) {
    rw_rf_le_enter_test_mode(0x12);
    uStack_18 = 1;
    bStack_17 = *param_1;
    bStack_16 = param_1[1];
    bStack_15 = param_1[2];
    bStack_14 = param_1[3];
    uVar2 = r_lld_test_start(&uStack_18);
  }
  r_llm_cmd_cmp_send(param_2,uVar2);
  return 0;
}

