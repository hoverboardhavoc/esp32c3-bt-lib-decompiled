/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
    r_assert_param(0,"arch_main.c",0x758);
  }
  _g_eif_api = *(undefined4 *)(_r_h4tl_eif_p + 0x18);
  _gpio_matrix_out = *(undefined4 *)(_r_h4tl_eif_p + 0x1c);
  _DAT_000121a0 = *(undefined4 *)(_r_h4tl_eif_p + 0x20);
  _DAT_0001219c = *(undefined4 *)(_r_h4tl_eif_p + 0x24);
  return &g_eif_api;
}

