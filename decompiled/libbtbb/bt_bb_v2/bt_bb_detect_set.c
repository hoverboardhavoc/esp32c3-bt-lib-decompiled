/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtbb -> bt_bb_v2.o -> bt_bb_detect_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bt_bb_detect_set(void)

{
  _DAT_6001c1a0 = _DAT_6001c1a0 & 0xffe1ffff | 0x1a0000;
  _DAT_600118ac = _DAT_600118ac & 0xff87ffff | 0x680000;
  _DAT_6001c07c = _DAT_6001c07c & 0xf0ffffff | 0x3000000;
  _DAT_600118a0 = _DAT_600118a0 & 0xf0ffffff | 0x3000000;
  _DAT_600118a8 = _DAT_600118a8 & 0xff83ffff | 0x100000;
  _DAT_6001c080 = _DAT_6001c080 & 0xffffffc1 | 8;
  return;
}

