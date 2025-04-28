/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> rwip.o -> r_rwip_wlcoex_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_wlcoex_set(int param_1)

{
  if (param_1 == 0) {
    _DAT_60031150 = _DAT_60031150 & 0xfffffffc;
  }
  else {
    _DAT_60031150 = _DAT_60031150 | 3;
    _DAT_6003115c =
         (**(code **)(_r_modules_funcs_p + 0x19c))(0,*(code **)(_r_modules_funcs_p + 0x19c));
    _DAT_60031160 =
         (**(code **)(_r_modules_funcs_p + 0x19c))(1,*(code **)(_r_modules_funcs_p + 0x19c));
  }
  return;
}

