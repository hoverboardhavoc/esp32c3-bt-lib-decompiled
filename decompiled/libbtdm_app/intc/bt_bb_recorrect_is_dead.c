/*
 * Last changed at upstream commit b223604efd557d0a5314afb3b751229df424d244
 * https://github.com/espressif/esp32c3-bt-lib/commit/b223604efd557d0a5314afb3b751229df424d244
 * Upstream date: 2021-06-24 21:26:02 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (9c99115)
 * Source: libbtdm_app -> intc.o -> bt_bb_recorrect_is_dead
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 bt_bb_recorrect_is_dead(void)

{
  char cVar1;
  
  cVar1 = '\x03';
  do {
    if (2 < (_DAT_6001186c >> 0x10 & 0xf) - 6) {
      return 0;
    }
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  return 1;
}

