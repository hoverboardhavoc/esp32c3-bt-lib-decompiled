/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> ecc_p256.o -> r_SubtractBigHexMod256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_SubtractBigHexMod256(int param_1,int param_2,void *param_3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  ushort *puVar6;
  uint uVar7;
  undefined1 auStack_3c [36];
  undefined4 uStack_18;
  
  if (*(int *)(param_1 + 0x28) == 0) {
    if (*(int *)(param_2 + 0x28) != 0) {
      r_AddBigHex256();
      goto _L109;
    }
    uVar4 = *(uint *)(param_1 + 0x24);
    iVar5 = param_1;
    iVar3 = param_2;
    if (uVar4 <= *(uint *)(param_2 + 0x24)) {
      if (uVar4 < *(uint *)(param_2 + 0x24)) {
_L112:
        r_SubtractBigHex256(iVar3,iVar5,param_3);
_L110:
        *(undefined4 *)((int)param_3 + 0x28) = 1;
        r_SubtractBigHex256(&bigHexP256,param_3,auStack_3c);
        memcpy(param_3,auStack_3c,0x22);
        *(undefined4 *)((int)param_3 + 0x28) = 0;
        *(undefined4 *)((int)param_3 + 0x24) = uStack_18;
        return;
      }
      for (uVar4 = 0x11 - uVar4; uVar4 < 0x11; uVar4 = uVar4 + 1) {
        uVar2 = *(ushort *)(param_2 + uVar4 * 2);
        uVar1 = *(ushort *)(uVar4 * 2 + param_1);
        if (uVar1 < uVar2) goto _L112;
        if (uVar2 < uVar1) break;
      }
    }
  }
  else {
    if (*(int *)(param_2 + 0x28) == 0) {
      r_AddBigHex256();
      goto _L110;
    }
    uVar4 = *(uint *)(param_2 + 0x24);
    iVar5 = param_2;
    iVar3 = param_1;
    if (uVar4 <= *(uint *)(param_1 + 0x24)) {
      if (uVar4 < *(uint *)(param_1 + 0x24)) goto _L112;
      for (uVar4 = 0x11 - uVar4; uVar4 < 0x11; uVar4 = uVar4 + 1) {
        uVar2 = *(ushort *)(param_1 + uVar4 * 2);
        uVar1 = *(ushort *)(uVar4 * 2 + param_2);
        if (uVar1 < uVar2) goto _L112;
        if (uVar2 < uVar1) break;
      }
    }
  }
  r_SubtractBigHex256(iVar5,iVar3,param_3);
_L109:
  uVar4 = _r_co_list_push_back;
  uVar7 = *(uint *)((int)param_3 + 0x24);
  *(undefined4 *)((int)param_3 + 0x28) = 0;
  if (uVar7 <= uVar4) {
    if (uVar7 < uVar4) {
      return;
    }
    for (uVar7 = 0x11 - uVar7; uVar7 < 0x11; uVar7 = uVar7 + 1) {
      uVar2 = *(ushort *)(uVar7 * 2 + (int)param_3);
      if (uVar2 < *(ushort *)(&bigHexP256 + uVar7 * 2)) {
        return;
      }
      if (*(ushort *)(&bigHexP256 + uVar7 * 2) < uVar2) break;
    }
  }
  iVar5 = 0x20;
  uVar4 = 0;
  do {
    puVar6 = (ushort *)((int)param_3 + iVar5);
    uVar2 = *puVar6;
    uVar1 = *(ushort *)(&bigHexP256 + iVar5);
    *puVar6 = (ushort)(((uVar2 - uVar4) - (uint)uVar1) * 0x10000 >> 0x10);
    uVar4 = (uint)((uint)uVar2 < uVar4 + uVar1);
    iVar5 = iVar5 + -2;
  } while (iVar5 != -2);
  iVar5 = 0;
  do {
    if (puVar6[iVar5] != 0) break;
    iVar5 = iVar5 + 1;
  } while (iVar5 != 0x11);
  *(int *)(puVar6 + 0x12) = 0x11 - iVar5;
  return;
}

