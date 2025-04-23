/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> sch_slice.o -> r_sch_slice_per_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_slice_per_add(int param_1,uint param_2,undefined4 param_3,undefined2 param_4)

{
  if (param_1 - 3U < 2) {
    *(undefined2 *)(r_assert_err + param_2 * 8) = param_4;
    *(undefined4 *)(r_sdk_config_get_opts + param_2 * 8) = param_3;
    ___clzsi2 = 1 << (param_2 & 0x1f) | ___clzsi2;
  }
  else {
    r_assert_err(0,0x10000,0x21d);
  }
  r_sch_slice_compute();
  return;
}

