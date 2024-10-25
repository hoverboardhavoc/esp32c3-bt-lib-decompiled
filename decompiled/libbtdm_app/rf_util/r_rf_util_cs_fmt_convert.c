/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> rf_util.o -> r_rf_util_cs_fmt_convert
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 r_rf_util_cs_fmt_convert(int param_1)

{
  undefined1 uVar1;
  uint uVar2;
  
  uVar2 = param_1 - 2U & 0xff;
  uVar1 = 0xe;
  if (uVar2 < 0x1d) {
    uVar1 = (&_LANCHOR0)[uVar2];
  }
  return uVar1;
}

