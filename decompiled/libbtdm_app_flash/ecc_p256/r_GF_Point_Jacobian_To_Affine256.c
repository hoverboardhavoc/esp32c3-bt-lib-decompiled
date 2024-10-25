/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> ecc_p256.o -> r_GF_Point_Jacobian_To_Affine256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_GF_Point_Jacobian_To_Affine256(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 auStack_3c [44];
  
  r_bigHexInversion256(param_1 + 0x58,auStack_3c);
  r_MultiplyBigHexModP256(param_1,auStack_3c,param_2);
  r_MultiplyBigHexModP256(param_1 + 0x2c,auStack_3c,param_3);
  return;
}

