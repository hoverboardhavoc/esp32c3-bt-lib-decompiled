/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> rwble.o -> r_rwble_isr_hw_fixed
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_rwble_isr_hw_fixed(int param_1)

{
  if (param_1 == 0x20000) {
    DAT_000107a4 = DAT_000107a4 + 1;
  }
  else {
    if (param_1 != 0x400001) {
      _g_bt_plf_log_level = 3;
      return 0xffffffff;
    }
    ble_isr_state = ble_isr_state + 1;
    DAT_000107b8 = DAT_000107b8 + 1;
  }
  return 0;
}

