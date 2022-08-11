/*
 * Last changed at upstream commit 3b0038690a644498d6d80f1de8df0efff8cd8cf5
 * https://github.com/espressif/esp32c3-bt-lib/commit/3b0038690a644498d6d80f1de8df0efff8cd8cf5
 * Upstream date: 2022-08-11 21:28:16 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(f2e5d813)
 * Source: libbtdm_app -> arch_main.o -> esp_ble_qa_set_scan_perfer_addr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_ble_qa_set_scan_perfer_addr(undefined1 *param_1)

{
  undefined1 uVar1;
  
  if (param_1 != (undefined1 *)0x0) {
    uVar1 = param_1[5];
    param_1[5] = *param_1;
    *param_1 = uVar1;
    uVar1 = param_1[4];
    param_1[4] = param_1[1];
    param_1[1] = uVar1;
    uVar1 = param_1[3];
    param_1[3] = param_1[2];
    param_1[2] = uVar1;
    ble_ll_scan_set_perfer_addr();
    return;
  }
  return;
}

