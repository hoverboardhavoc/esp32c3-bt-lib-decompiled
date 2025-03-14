/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
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
    DAT_000106ec = DAT_000106ec + 1;
  }
  else {
    if (param_1 != 0x400001) {
      _g_bt_plf_log_level = 3;
      return 0xffffffff;
    }
    ble_isr_state = ble_isr_state + 1;
    DAT_00010700 = DAT_00010700 + 1;
  }
  return 0;
}

