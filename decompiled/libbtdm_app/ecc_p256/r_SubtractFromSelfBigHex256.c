/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> ecc_p256.o -> r_SubtractFromSelfBigHex256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_SubtractFromSelfBigHex256(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  ushort *puVar5;
  
  iVar4 = 0x20;
  uVar3 = 0;
  do {
    puVar5 = (ushort *)(param_1 + iVar4);
    uVar1 = *puVar5;
    uVar2 = *(ushort *)(param_2 + iVar4);
    *puVar5 = (ushort)(((uVar1 - uVar3) - (uint)uVar2) * 0x10000 >> 0x10);
    uVar3 = (uint)((uint)uVar1 < uVar3 + uVar2);
    iVar4 = iVar4 + -2;
  } while (iVar4 != -2);
  iVar4 = 0;
  do {
    if (puVar5[iVar4] != 0) break;
    iVar4 = iVar4 + 1;
  } while (iVar4 != 0x11);
  *(int *)(puVar5 + 0x12) = 0x11 - iVar4;
  return;
}

