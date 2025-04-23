/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_scan.o -> ble_ll_scan_aa_setting
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool ble_ll_scan_aa_setting(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 != 0) {
    if (param_2 != 0) {
      iVar1 = r_ble_ll_qa_config_get(1);
      *(short *)(iVar1 + 0x14) = (short)param_1;
      *(short *)(iVar1 + 0x16) = (short)param_2;
    }
    return param_2 == 0;
  }
  return true;
}

