/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ecc_p256.o -> r_MultiplyByU16ModP256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_MultiplyByU16ModP256(short param_1,short *param_2)

{
  short sVar1;
  
  sVar1 = param_1 + -1;
  *param_2 = sVar1;
  param_2[10] = sVar1;
  param_2[1] = -1;
  param_2[2] = -param_1;
  param_2[3] = 0;
  param_2[4] = param_1;
  param_2[5] = 0;
  param_2[6] = 0;
  param_2[7] = 0;
  param_2[8] = 0;
  param_2[9] = 0;
  param_2[0xb] = -1;
  param_2[0xc] = -1;
  param_2[0xd] = -1;
  param_2[0xe] = -1;
  param_2[0xf] = -1;
  param_2[0x10] = -param_1;
  param_2[0x14] = 0;
  param_2[0x15] = 0;
  *(uint *)(param_2 + 0x12) = (sVar1 != 0) + 0x10;
  return;
}

