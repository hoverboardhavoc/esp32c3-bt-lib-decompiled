/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
  byte *pbVar3;
  
  if (param_1 == (undefined4 *)0x0) {
    r_assert_err(0x10000,0x46);
  }
  pbVar2 = (byte *)*param_1;
  pbVar3 = pbVar2 + 1;
  *param_1 = pbVar3;
  sVar1 = *pbVar2 - 0x30;
  while ((byte)(*pbVar3 - 0x30) < 10) {
    *param_1 = pbVar3 + 1;
    sVar1 = sVar1 * 10 + -0x30 + (ushort)*pbVar3;
    pbVar3 = pbVar3 + 1;
  }
  return sVar1;
}

