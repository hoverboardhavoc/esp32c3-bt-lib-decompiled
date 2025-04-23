/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> rwip_driver.o -> r_rwip_timer_hs_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_timer_hs_set(uint param_1)

{
  _rwip_env = param_1;
  if (param_1 == 0xffffffff) {
    _DAT_6003100c = _DAT_6003100c & 0xfffffbff;
    if (DAT_0001204d != '\0') {
      _DAT_6003138c = 0x400;
    }
  }
  else {
    if (0xfffffff < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0xc32,*(code **)(_r_plf_funcs_p + 8));
    }
    _DAT_60031018 = 0x400;
    if (DAT_0001204d != '\0') {
      _DAT_6003138c = 0x400;
    }
    _DAT_6003100c = _DAT_6003100c | 0x400;
    _DAT_600310e8 = param_1;
  }
  return;
}

