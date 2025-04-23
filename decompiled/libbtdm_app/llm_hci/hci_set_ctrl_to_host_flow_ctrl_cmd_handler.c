/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_hci.o -> hci_set_ctrl_to_host_flow_ctrl_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_set_ctrl_to_host_flow_ctrl_cmd_handler(byte *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0x12;
  if (*param_1 < 4) {
    uVar1 = (**(code **)(_r_ip_funcs_p + 0xb0))(*param_1 & 1,0x12,*(code **)(_r_ip_funcs_p + 0xb0));
  }
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar1,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

