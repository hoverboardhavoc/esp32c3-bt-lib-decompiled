/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> co_utils.o -> r_co_nb_good_le_channels
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char r_co_nb_good_le_channels(int param_1)

{
  int iVar1;
  char cVar2;
  byte *pbVar3;
  
  iVar1 = 4;
  cVar2 = '\0';
  do {
    pbVar3 = (byte *)(param_1 + iVar1);
    iVar1 = iVar1 + -1;
    cVar2 = (&one_bits)[*pbVar3 >> 4] + (&one_bits)[*pbVar3 & 0xf] + cVar2;
  } while (iVar1 != -1);
  return cVar2;
}

