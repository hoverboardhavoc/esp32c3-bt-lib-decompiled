/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
    *(undefined2 *)(memset + param_2 * 8) = param_4;
    *(undefined4 *)(r_assert_err + param_2 * 8) = param_3;
    _r_sdk_config_get_opts = 1 << (param_2 & 0x1f) | _r_sdk_config_get_opts;
  }
  else {
    r_assert_err(0,0x10000,0x21d);
  }
  r_sch_slice_compute();
  return;
}

