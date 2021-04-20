/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> nvds.o -> r_nvds_is_magic_number_ok
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool r_nvds_is_magic_number_ok(void)

{
  int iVar1;
  undefined1 auStack_14 [16];
  
  (*_LANCHOR0)(0,4,auStack_14,_LANCHOR0);
  iVar1 = memcmp(auStack_14,&_LANCHOR1,4);
  return iVar1 == 0;
}

