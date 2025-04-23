/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ecc_p256.o -> r_isValidSecretKey_256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_isValidSecretKey_256(char *param_1)

{
  int iVar1;
  
  iVar1 = 0x1f;
  do {
    if (param_1[iVar1] != '\0') goto _L7;
    iVar1 = iVar1 + -1;
  } while (iVar1 != -1);
  if (*param_1 == '\0') {
    return 0;
  }
_L7:
  iVar1 = 0x1f;
  do {
    if ((byte)(&maxSecretKey_256)[iVar1] < (byte)param_1[iVar1]) {
      return 0;
    }
  } while (((byte)(&maxSecretKey_256)[iVar1] <= (byte)param_1[iVar1]) &&
          (iVar1 = iVar1 + -1, iVar1 != -1));
  return 1;
}

