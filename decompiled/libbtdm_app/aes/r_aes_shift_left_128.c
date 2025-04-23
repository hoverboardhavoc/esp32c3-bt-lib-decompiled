/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> aes.o -> r_aes_shift_left_128
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_aes_shift_left_128(char *param_1,byte *param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  pbVar1 = (byte *)(param_1 + 0xe);
  pbVar2 = param_2 + 0xf;
  do {
    pbVar3 = pbVar2 + -1;
    *pbVar2 = *pbVar1 >> 7 | pbVar1[1] << 1;
    pbVar1 = pbVar1 + -1;
    pbVar2 = pbVar3;
  } while (param_2 != pbVar3);
  *param_2 = *param_1 << 1;
  return;
}

