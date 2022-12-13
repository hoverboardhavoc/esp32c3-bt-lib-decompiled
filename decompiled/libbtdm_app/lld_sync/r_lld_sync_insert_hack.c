/*
 * Last changed at upstream commit 84ebcda82aa5886d2a0b939dec1dbc62aa1c11c7
 * https://github.com/espressif/esp32c3-bt-lib/commit/84ebcda82aa5886d2a0b939dec1dbc62aa1c11c7
 * Upstream date: 2022-12-13 21:37:30 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3 (edd93b0)
 * Source: libbtdm_app -> lld_sync.o -> r_lld_sync_insert_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_sync_insert_hack(int param_1)

{
  if (*(char *)(*(int *)(&lld_sync_env + param_1 * 4) + 0x57) == '\0') {
    *(undefined1 *)(*(int *)(&lld_sync_env + param_1 * 4) + 0x16) = 0x1f;
  }
  r_lld_sync_insert();
  return;
}

