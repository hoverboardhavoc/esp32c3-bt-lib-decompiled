/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtbb -> bt_bb_v2.o -> bt_bb_restart_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bt_bb_restart_set(void)

{
  _DAT_6001c084 = _DAT_6001c084 & 0xffe001ff | 0x189e00;
  _DAT_6001c058 = _DAT_6001c058 & 0xffdfffff;
  _DAT_60011888 = _DAT_60011888 & 0xefffffff;
  _DAT_6001c090 = _DAT_6001c090 & 0xfffff | 0xd8a00000;
  _DAT_600118a4 = _DAT_600118a4 & 0xf8007fc0 | 0x145000f;
  _DAT_6001c1a0 = _DAT_6001c1a0 & 0xfffff000 | 0xc4c;
  _DAT_600118ac = _DAT_600118ac & 0xfffc0000 | 0x31db1;
  return;
}

