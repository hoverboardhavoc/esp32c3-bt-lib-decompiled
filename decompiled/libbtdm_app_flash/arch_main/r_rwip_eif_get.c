/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app_flash -> arch_main.o -> r_rwip_eif_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * r_rwip_eif_get(int param_1)

{
  if (param_1 != 0) {
    r_assert_param(0,"arch_main.c",0x778);
  }
  _g_eif_api = *(undefined4 *)(_r_h4tl_eif_p + 0x18);
  _gpio_matrix_out = *(undefined4 *)(_r_h4tl_eif_p + 0x1c);
  _DAT_000121a8 = *(undefined4 *)(_r_h4tl_eif_p + 0x20);
  _DAT_000121a4 = *(undefined4 *)(_r_h4tl_eif_p + 0x24);
  return &g_eif_api;
}

