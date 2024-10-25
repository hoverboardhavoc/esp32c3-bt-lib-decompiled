/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> nvds.o -> r_nvds_null_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_nvds_null_init(void)

{
  _LANCHOR0 = 0x10000;
  DAT_000106e4 = nvds_null_write;
  DAT_000106ec = 0;
  DAT_000106f0 = 0;
  _DAT_000106f4 = 0;
  DAT_000106e8 = nvds_null_erase;
  return 0;
}

