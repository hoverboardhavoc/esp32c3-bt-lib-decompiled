/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
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
  if ((param_1 & 0x800) != 0) {
    _DAT_60031018 = 0x800;
    r_rwip_timer_hus_handler_hack();
  }
  if ((param_1 & 1) != 0) {
    _DAT_60031018 = 1;
    if ((_rwip_env & 1) != 0) {
      r_rwip_wakeup_end_hack();
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
  if ((param_1 & 0x1000) != 0) {
    _DAT_60031018 = 0x1000;
    r_rwip_sw_int_handler();
  }
  if ((param_1 & 0x80000) != 0) {
    _DAT_60031018 = _DAT_60031018 & 0xfff7ffff | 0x80000;
    r_ble_sw_cca_check_isr();
    return;
  }
  return;
}

