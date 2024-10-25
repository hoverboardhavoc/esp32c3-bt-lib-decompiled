/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> arch_main.o -> btdm_lpclk_select_src
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool btdm_lpclk_select_src(uint param_1)

{
  if (param_1 < 4) {
    _DAT_600c0024 = _DAT_600c0024 & 0xfff000 | *(uint *)(&_LANCHOR1 + param_1 * 4);
    return (_DAT_600c0024 & *(uint *)(&_LANCHOR1 + param_1 * 4)) != 0;
  }
  return false;
}

