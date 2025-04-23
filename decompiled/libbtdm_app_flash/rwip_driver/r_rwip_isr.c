/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> rwip_driver.o -> r_rwip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_isr(uint param_1)

{
  if ((param_1 & 0x400) != 0) {
    _DAT_60031018 = 0x400;
    r_rwip_timer_hs_handler();
  }
  if ((int)(param_1 << 0x14) < 0) {
    _DAT_60031018 = 0x800;
    r_rwip_timer_hus_handler_hack();
  }
  if ((param_1 & 1) != 0) {
    _DAT_60031018 = 1;
    if ((_rwip_env & 1) != 0) {
      r_rwip_wakeup_end();
    }
  }
  if ((param_1 & 8) != 0) {
    _DAT_60031018 = 8;
    r_rwip_wakeup_hack();
  }
  if ((param_1 & 0x200) != 0) {
    _DAT_60031018 = 0x200;
    r_rwip_timer_10ms_handler();
  }
  if ((param_1 & 0x80) != 0) {
    _DAT_60031018 = 0x80;
    r_rwip_crypt_isr_handler();
  }
  if ((int)(param_1 << 0x13) < 0) {
    _DAT_60031018 = 0x1000;
    r_rwip_sw_int_handler();
  }
  if ((int)(param_1 << 0xc) < 0) {
    _DAT_60031018 = _DAT_60031018 | 0x80000;
    r_ble_sw_cca_check_isr();
    return;
  }
  return;
}

