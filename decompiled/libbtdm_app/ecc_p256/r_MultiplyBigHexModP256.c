/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  ushort *puVar3;
  short *psVar4;
  short *psVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  short local_98;
  undefined1 auStack_96 [30];
  ushort uStack_78;
  int iStack_74;
  uint uStack_70;
  ushort local_6c [34];
  uint uStack_28;
  uint uStack_24;
  
  memset(local_6c,0,0x44);
  iVar6 = 0x20;
  do {
    uVar2 = *(ushort *)(param_1 + iVar6);
    psVar5 = (short *)((int)local_6c + iVar6);
    uVar7 = 0;
    puVar3 = param_2 + 0x10;
    psVar4 = psVar5;
    do {
      uVar7 = uVar7 + (uint)*puVar3 * (uint)uVar2 + (uint)(ushort)psVar4[0x11];
      psVar4[0x11] = (short)uVar7;
      uVar7 = uVar7 >> 0x10;
      bVar1 = param_2 != puVar3;
      puVar3 = puVar3 + -1;
      psVar4 = psVar4 + -1;
    } while (bVar1);
    iVar6 = iVar6 + -2;
  } while (iVar6 != -2);
  iVar6 = 0;
  psVar4 = psVar5;
  do {
    if (*psVar4 != 0) break;
    iVar6 = iVar6 + 1;
    psVar4 = psVar4 + 1;
  } while (iVar6 != 0x22);
  uStack_28 = 0x22 - iVar6;
  uStack_24 = (uint)(*(int *)(param_1 + 0x28) != *(int *)(param_2 + 0x14));
  for (iVar6 = 0; (*psVar5 == 0 && (psVar5 = psVar5 + 1, iVar6 != 0x11)); iVar6 = iVar6 + 1) {
  }
  uStack_70 = uStack_24;
  if (uStack_28 <= _DAT_00013058) {
    if (uStack_28 < _DAT_00013058) goto _L126;
    for (iVar8 = 0x22 - uStack_28; iVar8 < 0x22; iVar8 = iVar8 + 1) {
      if (*(ushort *)(&veryBigHexP256 + iVar8 * 2) != local_6c[iVar8]) {
        if (local_6c[iVar8] <= *(ushort *)(&veryBigHexP256 + iVar8 * 2)) goto _L126;
        break;
      }
    }
  }
  for (; local_6c[iVar6] == 0; iVar6 = iVar6 + 1) {
  }
_L126:
  memcpy(&local_98,local_6c + iVar6,0x22);
  psVar4 = &local_98;
  iStack_74 = 0;
  do {
    if (*psVar4 != 0) break;
    iStack_74 = iStack_74 + 1;
    psVar4 = psVar4 + 1;
  } while (iStack_74 != 0x11);
  uVar7 = iVar6 + 0x11;
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
    psVar4 = &local_98;
    uStack_78 = local_6c[uVar7];
    iStack_74 = 0;
    do {
      if (*psVar4 != 0) break;
      iStack_74 = iStack_74 + 1;
      psVar4 = psVar4 + 1;
    } while (iStack_74 != 0x11);
    uVar7 = uVar7 + 1;
  } while( true );
}

