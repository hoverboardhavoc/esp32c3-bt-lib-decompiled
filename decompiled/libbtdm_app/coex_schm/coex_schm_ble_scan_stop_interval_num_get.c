/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> coex_schm.o -> coex_schm_ble_scan_stop_interval_num_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint coex_schm_ble_scan_stop_interval_num_get(int param_1,uint param_2,int param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_000101f8 - param_3 & 0xfffffff;
  if (0x8000000 < uVar2) {
    uVar2 = -(param_3 - DAT_000101f8 & 0xfffffffU);
  }
  uVar2 = uVar2 & (int)~uVar2 >> 0x1f;
  uVar1 = (int)uVar2 / (param_1 << 1) & 0xff;
  uVar2 = (int)uVar2 % (param_1 << 1) >> 1;
  if (param_2 <= uVar2) {
    uVar1 = uVar1 + 1 & 0xff;
    uVar2 = 0;
  }
  *param_4 = uVar2;
  return uVar1;
}

