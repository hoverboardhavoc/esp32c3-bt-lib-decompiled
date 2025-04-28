/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> coex_schm.o -> coex_schm_ble_scan_stop_interval_num_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint coex_schm_ble_scan_stop_interval_num_get(int param_1,uint param_2,int param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_000101e8 - param_3 & 0xfffffff;
  if (0x8000000 < uVar2) {
    uVar2 = -(param_3 - DAT_000101e8 & 0xfffffffU);
  }
  if ((int)uVar2 < 0) {
    uVar2 = 0;
  }
  uVar1 = (int)uVar2 / (param_1 << 1) & 0xff;
  uVar2 = (int)uVar2 % (param_1 << 1) >> 1;
  if (uVar2 < param_2) {
    *param_4 = uVar2;
    return uVar1;
  }
  *param_4 = 0;
  return uVar1 + 1 & 0xff;
}

