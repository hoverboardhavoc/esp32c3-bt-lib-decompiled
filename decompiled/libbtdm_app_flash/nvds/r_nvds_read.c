/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> nvds.o -> r_nvds_read
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_nvds_read(int param_1,int param_2,undefined4 param_3)

{
  if (DAT_000106a0 < (uint)(param_1 + param_2)) {
    r_assert_err(0,"nvds.c",0x1d4,param_3);
  }
  r_flash_read(DAT_000106a4,DAT_0001069c + param_1,param_2,param_3,0);
  return;
}

