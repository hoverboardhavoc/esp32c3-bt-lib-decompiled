/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> ecc_p256.o -> r_AddPdiv2_256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_AddPdiv2_256(ushort *param_1)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  int iVar4;
  ushort *puVar5;
  uint uVar6;
  undefined1 auStack_3c [52];
  
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar4 = 0x20;
    uVar3 = 0;
    do {
      puVar2 = (ushort *)((int)param_1 + iVar4);
      puVar5 = (ushort *)(&bigHexP256 + iVar4);
      iVar4 = iVar4 + -2;
      uVar3 = (uint)*puVar5 + (uint)*puVar2 + uVar3;
      *puVar2 = (ushort)uVar3;
      uVar3 = uVar3 >> 0x10 & 1;
    } while (iVar4 != -2);
  }
  else {
    uVar3 = *(uint *)(param_1 + 0x12);
    if (_r_co_list_push_back < uVar3) {
_L67:
      iVar4 = 0x20;
      uVar3 = 0;
      do {
        uVar6 = (uint)*(ushort *)((int)param_1 + iVar4);
        uVar1 = *(ushort *)(&bigHexP256 + iVar4);
        *(ushort *)((int)param_1 + iVar4) =
             (ushort)(((uVar6 - uVar3) - (uint)uVar1) * 0x10000 >> 0x10);
        uVar3 = (uint)(uVar6 < uVar3 + uVar1);
        iVar4 = iVar4 + -2;
      } while (iVar4 != -2);
    }
    else {
      if (_r_co_list_push_back <= uVar3) {
        for (uVar3 = 0x11 - uVar3; uVar3 < 0x11; uVar3 = uVar3 + 1) {
          if (param_1[uVar3] < *(ushort *)(&bigHexP256 + uVar3 * 2)) break;
          if (*(ushort *)(&bigHexP256 + uVar3 * 2) < param_1[uVar3]) goto _L67;
        }
      }
      r_SubtractBigHex256(&bigHexP256,param_1,auStack_3c);
      memcpy(param_1,auStack_3c,0x22);
      param_1[0x14] = 0;
      param_1[0x15] = 0;
    }
  }
  uVar3 = 0;
  puVar2 = param_1;
  do {
    puVar5 = puVar2 + 1;
    uVar3 = uVar3 * 0x10000 + (uint)*puVar2;
    *puVar2 = (ushort)(uVar3 >> 1);
    uVar3 = uVar3 & 1;
    puVar2 = puVar5;
  } while (param_1 + 0x11 != puVar5);
  iVar4 = 0;
  do {
    if (param_1[iVar4] != 0) break;
    iVar4 = iVar4 + 1;
  } while (iVar4 != 0x11);
  *(int *)(param_1 + 0x12) = 0x11 - iVar4;
  return;
}

