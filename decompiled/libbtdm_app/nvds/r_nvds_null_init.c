/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
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
  DAT_000106a4 = nvds_null_write;
  DAT_000106ac = 0;
  DAT_000106b0 = 0;
  _DAT_000106b4 = 0;
  DAT_000106a8 = nvds_null_erase;
  return 0;
}

