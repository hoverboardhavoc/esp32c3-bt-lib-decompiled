/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> ble_log_simple_output.o -> r_ble_log_simple_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ble_log_simple_deinit(void)

{
  if (_ble_log_env != 0) {
    if (*(int *)(_ble_log_env + 0x1c) != 0) {
      (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
      *(undefined4 *)(_ble_log_env + 0x1c) = 0;
    }
    (**(code **)(_r_osi_funcs_p + 0x7c))(_ble_log_env,*(code **)(_r_osi_funcs_p + 0x7c));
    _ble_log_env = 0;
  }
  return;
}

