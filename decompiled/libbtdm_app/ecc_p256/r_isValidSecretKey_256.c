/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ecc_p256.o -> r_isValidSecretKey_256
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
    if (param_1[iVar1] != '\0') goto _L6;
    iVar1 = iVar1 + -1;
  } while (iVar1 != -1);
  if (*param_1 == '\0') {
    return 0;
  }
_L6:
  iVar1 = 0x1f;
  do {
    if ((byte)(&maxSecretKey_256)[iVar1] < (byte)param_1[iVar1]) {
      return 0;
    }
  } while (((byte)(&maxSecretKey_256)[iVar1] <= (byte)param_1[iVar1]) &&
          (iVar1 = iVar1 + -1, iVar1 != -1));
  return 1;
}

