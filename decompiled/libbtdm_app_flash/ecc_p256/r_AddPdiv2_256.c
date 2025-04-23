/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  ushort uVar2;
  ushort *puVar3;
  uint uVar4;
  int iVar5;
  ushort *puVar6;
  undefined1 auStack_3c [52];
  
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar5 = 0x20;
    uVar4 = 0;
    do {
      puVar3 = (ushort *)((int)param_1 + iVar5);
      puVar6 = (ushort *)(&bigHexP256 + iVar5);
      iVar5 = iVar5 + -2;
      uVar4 = (uint)*puVar6 + (uint)*puVar3 + uVar4;
      *puVar3 = (ushort)uVar4;
      uVar4 = uVar4 >> 0x10 & 1;
    } while (iVar5 != -2);
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x12);
    if (_r_co_list_push_back < uVar4) {
_L61:
      iVar5 = 0x20;
      uVar4 = 0;
      do {
        puVar3 = (ushort *)((int)param_1 + iVar5);
        uVar1 = *puVar3;
        uVar2 = *(ushort *)(&bigHexP256 + iVar5);
        iVar5 = iVar5 + -2;
        *puVar3 = (uVar1 - (short)uVar4) - uVar2;
        uVar4 = (uint)((uint)uVar1 < uVar4 + uVar2);
      } while (iVar5 != -2);
    }
    else {
      if (_r_co_list_push_back <= uVar4) {
        for (uVar4 = 0x11 - uVar4; uVar4 < 0x11; uVar4 = uVar4 + 1) {
          if (param_1[uVar4] < *(ushort *)(&bigHexP256 + uVar4 * 2)) break;
          if (*(ushort *)(&bigHexP256 + uVar4 * 2) < param_1[uVar4]) goto _L61;
        }
      }
      r_SubtractBigHex256(&bigHexP256,param_1,auStack_3c);
      memcpy(param_1,auStack_3c,0x22);
      param_1[0x14] = 0;
      param_1[0x15] = 0;
    }
  }
  uVar4 = 0;
  puVar3 = param_1;
  do {
    puVar6 = puVar3 + 1;
    uVar4 = uVar4 * 0x10000 + (uint)*puVar3;
    *puVar3 = (ushort)(uVar4 >> 1);
    uVar4 = uVar4 & 1;
    puVar3 = puVar6;
  } while (param_1 + 0x11 != puVar6);
  iVar5 = 0;
  do {
    if (param_1[iVar5] != 0) break;
    iVar5 = iVar5 + 1;
  } while (iVar5 != 0x11);
  *(int *)(param_1 + 0x12) = 0x11 - iVar5;
  return;
}

