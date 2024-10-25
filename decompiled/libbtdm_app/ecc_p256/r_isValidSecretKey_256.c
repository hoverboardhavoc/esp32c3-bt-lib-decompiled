/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> ecc_p256.o -> r_isValidSecretKey_256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_isValidSecretKey_256(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = 0x1f;
  do {
    if (param_1[iVar1] != '\0') goto _L7;
    iVar1 = iVar1 + -1;
  } while (iVar1 != -1);
  uVar2 = 0;
  if (*param_1 != '\0') {
_L7:
    iVar1 = 0x1f;
    do {
      if ((byte)(&maxSecretKey_256)[iVar1] < (byte)param_1[iVar1]) {
        return 0;
      }
    } while (((byte)(&maxSecretKey_256)[iVar1] <= (byte)param_1[iVar1]) &&
            (iVar1 = iVar1 + -1, iVar1 != -1));
    uVar2 = 1;
  }
  return uVar2;
}

