/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ecc_p256.o -> r_MultiplyBigHexModP256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_MultiplyBigHexModP256(int param_1,ushort *param_2,void *param_3)

{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  ushort *puVar6;
  uint uVar7;
  short *psVar8;
  short local_98;
  undefined1 auStack_96 [30];
  ushort uStack_78;
  int iStack_74;
  uint uStack_70;
  ushort local_6c [34];
  uint uStack_28;
  uint uStack_24;
  
  memset(local_6c,0,0x44);
  iVar5 = 0x10;
  do {
    uVar2 = *(ushort *)(param_1 + iVar5 * 2);
    uVar7 = 0;
    puVar4 = param_2 + 0x10;
    puVar6 = local_6c + iVar5;
    do {
      uVar7 = uVar7 + (uint)*puVar4 * (uint)uVar2 + (uint)puVar6[0x11];
      puVar6[0x11] = (ushort)uVar7;
      uVar7 = uVar7 >> 0x10;
      bVar1 = param_2 != puVar4;
      puVar4 = puVar4 + -1;
      puVar6 = puVar6 + -1;
    } while (bVar1);
    iVar5 = iVar5 + -1;
  } while (iVar5 != -1);
  iVar5 = 0;
  puVar4 = local_6c;
  do {
    if (*puVar4 != 0) break;
    iVar5 = iVar5 + 1;
    puVar4 = puVar4 + 1;
  } while (iVar5 != 0x22);
  uStack_28 = 0x22 - iVar5;
  uStack_24 = (uint)(*(int *)(param_1 + 0x28) != *(int *)(param_2 + 0x14));
  puVar4 = local_6c;
  for (iVar3 = 0; (*puVar4 == 0 && (puVar4 = puVar4 + 1, iVar3 != 0x11)); iVar3 = iVar3 + 1) {
  }
  uStack_70 = uStack_24;
  if (uStack_28 <= _DAT_00013058) {
    if (uStack_28 < _DAT_00013058) goto _L118;
    iVar5 = iVar5 << 1;
    do {
      if (iVar5 == 0x44) goto _L121;
      puVar6 = (ushort *)(&veryBigHexP256 + iVar5);
      puVar4 = (ushort *)((int)local_6c + iVar5);
      iVar5 = iVar5 + 2;
    } while (*puVar6 == *puVar4);
    if (*puVar4 <= *puVar6) goto _L118;
  }
_L121:
  for (; local_6c[iVar3] == 0; iVar3 = iVar3 + 1) {
  }
_L118:
  memcpy(&local_98,local_6c + iVar3,0x22);
  psVar8 = &local_98;
  iStack_74 = 0;
  do {
    if (*psVar8 != 0) break;
    iStack_74 = iStack_74 + 1;
    psVar8 = psVar8 + 1;
  } while (iStack_74 != 0x11);
  uVar7 = iVar3 + 0x11;
  do {
    iStack_74 = 0x11 - iStack_74;
    if (0x21 < uVar7) {
      (**(code **)(_r_modules_funcs_p + 0x3a8))(&local_98);
      memcpy(param_3,&local_98,0x22);
      *(int *)((int)param_3 + 0x24) = iStack_74;
      *(uint *)((int)param_3 + 0x28) = uStack_70;
      return;
    }
    (**(code **)(_r_modules_funcs_p + 0x3a8))(&local_98);
    memcpy(&local_98,auStack_96,0x20);
    psVar8 = &local_98;
    uStack_78 = local_6c[uVar7];
    iStack_74 = 0;
    do {
      if (*psVar8 != 0) break;
      iStack_74 = iStack_74 + 1;
      psVar8 = psVar8 + 1;
    } while (iStack_74 != 0x11);
    uVar7 = uVar7 + 1;
  } while( true );
}

