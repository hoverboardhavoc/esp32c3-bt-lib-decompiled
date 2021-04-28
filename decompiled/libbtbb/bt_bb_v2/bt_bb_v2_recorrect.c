/*
 * Last changed at upstream commit 2c453f09b7d1102ef496278d2cd2be96ff1ea071
 * https://github.com/espressif/esp32c3-bt-lib/commit/2c453f09b7d1102ef496278d2cd2be96ff1ea071
 * Upstream date: 2021-04-28 17:55:23 +0800
 * Upstream subject: update ESP32C3/ESP32S3 libbtbb.a
 * Source: libbtbb -> bt_bb_v2.o -> bt_bb_v2_recorrect
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bt_bb_v2_recorrect(void)

{
  _DAT_6001c080 = _DAT_6001c080 & 0x1fffffff | 0x40000000;
  _DAT_60011840 = _DAT_60011840 & 0xffffe3ff | 0x800;
  _DAT_6001c084 = _DAT_6001c084 & 0xbfffffff;
  _DAT_60011868 = _DAT_60011868 & 0xffffcfc0 | 10;
  _DAT_600118b0 = _DAT_600118b0 & 0xffffc00f | 0x14a0;
  return;
}

