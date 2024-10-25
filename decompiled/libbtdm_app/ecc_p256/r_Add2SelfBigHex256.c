/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> ecc_p256.o -> r_Add2SelfBigHex256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_Add2SelfBigHex256(int param_1,int param_2)

{
  uint uVar1;
  ushort *puVar2;
  int iVar3;
  ushort *puVar4;
  
  iVar3 = 0x20;
  uVar1 = 0;
  do {
    puVar2 = (ushort *)(param_1 + iVar3);
    puVar4 = (ushort *)(param_2 + iVar3);
    iVar3 = iVar3 + -2;
    uVar1 = (uint)*puVar4 + (uint)*puVar2 + uVar1;
    *puVar2 = (ushort)uVar1;
    uVar1 = uVar1 >> 0x10 & 1;
  } while (iVar3 != -2);
  iVar3 = 0;
  do {
    if (puVar2[iVar3] != 0) break;
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0x11);
  *(int *)(puVar2 + 0x12) = 0x11 - iVar3;
  return;
}

