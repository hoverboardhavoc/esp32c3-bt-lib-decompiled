/*
 * Last changed at upstream commit e651b371c861ba23111db51dd76fd01fc2a69079
 * https://github.com/espressif/esp32c3-bt-lib/commit/e651b371c861ba23111db51dd76fd01fc2a69079
 * Upstream date: 2023-12-13 19:24:11 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(9129dec)
 * Source: libbtdm_app -> arch_main.o -> btdm_deep_sleep_mem_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btdm_deep_sleep_mem_deinit(void)

{
  if (_LANCHOR2 != 0) {
    (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
    _LANCHOR2 = 0;
  }
  if (_LANCHOR3 != 0) {
    (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
    _LANCHOR3 = 0;
  }
  if (_LANCHOR4 != 0) {
    (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
    _LANCHOR4 = 0;
  }
  return;
}

