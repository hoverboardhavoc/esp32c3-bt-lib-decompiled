/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> intc.o -> r_intc_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_intc_deinit(void)

{
  if (_LANCHOR0 != 0) {
    (**(code **)(_r_osi_funcs_p + 0xc))(*(code **)(_r_osi_funcs_p + 0xc));
    _LANCHOR0 = 0;
  }
  if (_LANCHOR1 != 0) {
    (**(code **)(_r_osi_funcs_p + 0xc))(*(code **)(_r_osi_funcs_p + 0xc));
    _LANCHOR1 = 0;
  }
  return;
}

