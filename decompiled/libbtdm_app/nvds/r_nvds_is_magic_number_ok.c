/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
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
  iVar1 = memcmp(auStack_14,"NVDSNVDS MAGIC FAILED\n",4);
  return iVar1 == 0;
}

