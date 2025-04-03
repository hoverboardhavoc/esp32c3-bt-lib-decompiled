/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app_flash -> lld_scan.o -> ble_ll_scan_upperlimit_setting
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ble_ll_scan_upperlimit_setting(short param_1)

{
  int iVar1;
  
  if ((ushort)(param_1 - 1U) < 0x100) {
    iVar1 = r_ble_ll_qa_config_get();
    *(short *)(iVar1 + 0x20) = param_1;
    return 0;
  }
  return 0x12;
}

