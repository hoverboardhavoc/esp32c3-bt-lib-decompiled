/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> ecc_p256.o -> r_AddBigHex256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_AddBigHex256(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0x20;
  uVar1 = 0;
  do {
    uVar1 = (uint)*(ushort *)(param_1 + iVar2) + (uint)*(ushort *)(param_2 + iVar2) + uVar1;
    *(short *)(param_3 + iVar2) = (short)uVar1;
    iVar2 = iVar2 + -2;
    uVar1 = uVar1 >> 0x10 & 1;
  } while (iVar2 != -2);
  iVar2 = 0;
  do {
    if (*(short *)(iVar2 * 2 + param_3) != 0) break;
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x11);
  *(int *)(param_3 + 0x24) = 0x11 - iVar2;
  *(undefined4 *)(param_3 + 0x28) = 0;
  return;
}

