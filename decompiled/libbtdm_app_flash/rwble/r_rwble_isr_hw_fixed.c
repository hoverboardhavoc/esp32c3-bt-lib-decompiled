/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
    DAT_00010778 = DAT_00010778 + 1;
  }
  else {
    if (param_1 != 0x400001) {
      _g_bt_plf_log_level = 3;
      return 0xffffffff;
    }
    ble_isr_state = ble_isr_state + 1;
    DAT_0001078c = DAT_0001078c + 1;
  }
  return 0;
}

