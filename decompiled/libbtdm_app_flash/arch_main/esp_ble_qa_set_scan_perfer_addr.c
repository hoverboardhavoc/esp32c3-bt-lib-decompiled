/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> arch_main.o -> esp_ble_qa_set_scan_perfer_addr
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

