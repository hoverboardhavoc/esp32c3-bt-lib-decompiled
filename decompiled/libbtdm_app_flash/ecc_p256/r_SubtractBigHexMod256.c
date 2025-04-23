/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  ushort *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined1 auStack_3c [36];
  undefined4 uStack_18;
  
  if (*(int *)(param_1 + 0x28) == 0) {
    if (*(int *)(param_2 + 0x28) != 0) {
      r_AddBigHex256();
      goto _L89;
    }
    uVar5 = *(uint *)(param_1 + 0x24);
    iVar7 = param_1;
    iVar3 = param_2;
    if (uVar5 <= *(uint *)(param_2 + 0x24)) {
      if (uVar5 < *(uint *)(param_2 + 0x24)) {
_L104:
        r_SubtractBigHex256(iVar3,iVar7,param_3);
_L90:
        r_SubtractBigHex256(&bigHexP256,param_3,auStack_3c);
        memcpy(param_3,auStack_3c,0x22);
        *(undefined4 *)((int)param_3 + 0x28) = 0;
        *(undefined4 *)((int)param_3 + 0x24) = uStack_18;
        return;
      }
      for (uVar5 = 0x11 - uVar5; uVar5 < 0x11; uVar5 = uVar5 + 1) {
        uVar2 = *(ushort *)(param_2 + uVar5 * 2);
        uVar1 = *(ushort *)(uVar5 * 2 + param_1);
        if (uVar1 < uVar2) goto _L104;
        if (uVar2 < uVar1) break;
      }
    }
  }
  else {
    if (*(int *)(param_2 + 0x28) == 0) {
      r_AddBigHex256();
      goto _L90;
    }
    uVar5 = *(uint *)(param_2 + 0x24);
    iVar7 = param_2;
    iVar3 = param_1;
    if (uVar5 <= *(uint *)(param_1 + 0x24)) {
      if (uVar5 < *(uint *)(param_1 + 0x24)) goto _L104;
      for (uVar5 = 0x11 - uVar5; uVar5 < 0x11; uVar5 = uVar5 + 1) {
        uVar2 = *(ushort *)(param_1 + uVar5 * 2);
        uVar1 = *(ushort *)(uVar5 * 2 + param_2);
        if (uVar1 < uVar2) goto _L104;
        if (uVar2 < uVar1) break;
      }
    }
  }
  r_SubtractBigHex256(iVar7,iVar3,param_3);
_L89:
  uVar5 = _r_co_list_push_back;
  uVar6 = *(uint *)((int)param_3 + 0x24);
  *(undefined4 *)((int)param_3 + 0x28) = 0;
  if (uVar6 <= uVar5) {
    if (uVar6 < uVar5) {
      return;
    }
    for (uVar6 = 0x11 - uVar6; uVar6 < 0x11; uVar6 = uVar6 + 1) {
      uVar2 = *(ushort *)(uVar6 * 2 + (int)param_3);
      if (uVar2 < *(ushort *)(&bigHexP256 + uVar6 * 2)) {
        return;
      }
      if (*(ushort *)(&bigHexP256 + uVar6 * 2) < uVar2) break;
    }
  }
  iVar7 = 0x20;
  uVar5 = 0;
  do {
    puVar4 = (ushort *)((int)param_3 + iVar7);
    uVar2 = *puVar4;
    uVar1 = *(ushort *)(&bigHexP256 + iVar7);
    iVar7 = iVar7 + -2;
    *puVar4 = (uVar2 - (short)uVar5) - uVar1;
    uVar5 = (uint)((uint)uVar2 < uVar5 + uVar1);
  } while (iVar7 != -2);
  iVar7 = 0;
  do {
    if (*(short *)(iVar7 * 2 + (int)param_3) != 0) break;
    iVar7 = iVar7 + 1;
  } while (iVar7 != 0x11);
  *(int *)((int)param_3 + 0x24) = 0x11 - iVar7;
  return;
}

