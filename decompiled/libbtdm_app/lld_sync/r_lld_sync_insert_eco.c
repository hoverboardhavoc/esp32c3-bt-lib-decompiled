/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> lld_sync.o -> r_lld_sync_insert_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_sync_insert_eco(int param_1)

{
  if (*(char *)(*(int *)(&lld_sync_env + param_1 * 4) + 0x57) == '\0') {
    *(undefined1 *)(*(int *)(&lld_sync_env + param_1 * 4) + 0x16) = 0x1f;
  }
  r_lld_sync_insert();
  return;
}

