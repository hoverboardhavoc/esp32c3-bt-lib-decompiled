/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> co_utils.o -> r_co_util_read_array_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

short r_co_util_read_array_size(undefined4 *param_1)

{
  short sVar1;
  byte *pbVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    r_assert_err(0x10000,0x46);
  }
  pbVar2 = (byte *)*param_1;
  *param_1 = pbVar2 + 1;
  sVar1 = *pbVar2 - 0x30;
  while( true ) {
    pbVar2 = (byte *)*param_1;
    if (9 < (byte)(*pbVar2 - 0x30)) break;
    *param_1 = pbVar2 + 1;
    sVar1 = sVar1 * 10 + (*pbVar2 - 0x30);
  }
  return sVar1;
}

