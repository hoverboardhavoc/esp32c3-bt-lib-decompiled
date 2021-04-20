/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> llm_scan.o -> llm_is_pal_empty
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool llm_is_pal_empty(void)

{
  char cVar1;
  byte *pbVar2;
  
  cVar1 = '\0';
  pbVar2 = (byte *)(_p_llm_env + 0x2d);
  do {
    if ((*pbVar2 & 4) != 0) break;
    cVar1 = cVar1 + '\x01';
    pbVar2 = pbVar2 + 10;
  } while (cVar1 != '\f');
  return cVar1 == '\f';
}

