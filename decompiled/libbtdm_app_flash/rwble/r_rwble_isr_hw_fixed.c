/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
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
    DAT_00010784 = DAT_00010784 + 1;
  }
  else {
    if (param_1 != 0x400001) {
      _g_bt_plf_log_level = 3;
      return 0xffffffff;
    }
    ble_isr_state = ble_isr_state + 1;
    DAT_00010798 = DAT_00010798 + 1;
  }
  return 0;
}

