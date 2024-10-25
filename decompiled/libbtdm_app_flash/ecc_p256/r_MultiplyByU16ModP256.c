/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> ecc_p256.o -> r_MultiplyByU16ModP256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_MultiplyByU16ModP256(short param_1,short *param_2)

{
  short sVar1;
  undefined4 uVar2;
  
  sVar1 = param_1 + -1;
  param_2[1] = -1;
  param_2[0xb] = -1;
  *param_2 = sVar1;
  param_2[2] = -param_1;
  param_2[3] = 0;
  param_2[4] = param_1;
  param_2[5] = 0;
  param_2[6] = 0;
  param_2[7] = 0;
  param_2[8] = 0;
  param_2[9] = 0;
  param_2[10] = sVar1;
  param_2[0xc] = -1;
  param_2[0xd] = -1;
  param_2[0xe] = -1;
  param_2[0xf] = -1;
  param_2[0x10] = -param_1;
  param_2[0x14] = 0;
  param_2[0x15] = 0;
  if (sVar1 == 0) {
    uVar2 = 0x10;
  }
  else {
    uVar2 = 0x11;
  }
  *(undefined4 *)(param_2 + 0x12) = uVar2;
  return;
}

