/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> aes_ccm.o -> r_aes_ccm_process_e
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_aes_ccm_process_e(int param_1,void *param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  int iVar9;
  int iVar10;
  
  bVar1 = *(byte *)(param_1 + 0x51);
  if ((bVar1 & 2) == 0) {
    uVar6 = (uint)*(ushort *)(param_1 + 0x2c);
    if ((bVar1 & 0x10) != 0) {
      if ((bVar1 & 1) == 0) {
        pbVar5 = (byte *)(param_1 + 0x4e);
        pbVar8 = (byte *)((int)param_2 + 0xf);
        uVar7 = 0;
        do {
          if ((uint)*(byte *)(param_1 + 0x50) <= (uVar7 & 0xff)) goto _L41;
          iVar3 = uVar6 + uVar7;
          bVar1 = *pbVar8;
          bVar2 = *pbVar5;
          uVar7 = uVar7 + 1;
          pbVar5 = pbVar5 + -1;
          pbVar8 = pbVar8 + -1;
        } while (bVar2 == (*(byte *)(iVar3 + *(int *)(param_1 + 0x24)) ^ bVar1));
        uVar4 = 1;
      }
      else {
        iVar3 = *(int *)(param_1 + 0x28);
        for (uVar7 = 0; uVar7 < *(byte *)(param_1 + 0x50); uVar7 = uVar7 + 1 & 0xff) {
          *(byte *)(iVar3 + uVar7 + uVar6) =
               *(byte *)((0xf - uVar7) + param_1 + 0x3f) ^ *(byte *)((int)param_2 + (0xf - uVar7));
        }
_L41:
        uVar4 = 0;
      }
      if (*(code **)(param_1 + 0x18) == (code *)0x0) {
        return 1;
      }
      (**(code **)(param_1 + 0x18))(uVar4,*(undefined4 *)(param_1 + 0x14));
      return 1;
    }
    uVar7 = 0x10;
    iVar3 = (uint)*(byte *)(param_1 + 0x2e) * 0x10;
    if (uVar6 <= iVar3 + 0xfU) {
      uVar7 = uVar6 + (uint)*(byte *)(param_1 + 0x2e) * -0x10 & 0xff;
    }
    iVar9 = *(int *)(param_1 + 0x24) + iVar3;
    iVar3 = *(int *)(param_1 + 0x28) + iVar3;
    iVar10 = param_1 + 0x3f;
    if ((bVar1 & 1) == 0) {
      (**(code **)(_r_modules_funcs_p + 0x30c))
                (iVar3,iVar9,param_2,uVar7,*(code **)(_r_modules_funcs_p + 0x30c));
      (**(code **)(_r_modules_funcs_p + 0x308))
                (iVar10,iVar10,iVar3,uVar7,0,*(code **)(_r_modules_funcs_p + 0x308));
    }
    else {
      (**(code **)(_r_modules_funcs_p + 0x308))
                (iVar10,iVar10,iVar9,uVar7,0,*(code **)(_r_modules_funcs_p + 0x308));
      (**(code **)(_r_modules_funcs_p + 0x30c))
                (iVar3,iVar9,param_2,uVar7,*(code **)(_r_modules_funcs_p + 0x30c));
    }
    *(byte *)(param_1 + 0x51) = *(byte *)(param_1 + 0x51) | 2;
    *(char *)(param_1 + 0x2e) = *(char *)(param_1 + 0x2e) + '\x01';
    goto _L30;
  }
  memcpy((void *)(param_1 + 0x3f),param_2,0x10);
  if ((bVar1 & 0x10) == 0) {
    if ((bVar1 & 4) == 0) {
      *(byte *)(param_1 + 0x51) = bVar1 & 0xfd;
      if ((uint)*(ushort *)(param_1 + 0x2c) <= (uint)*(byte *)(param_1 + 0x2e) << 4) {
        *(byte *)(param_1 + 0x51) = bVar1 & 0xf5 | 0x10;
      }
      goto _L30;
    }
    uVar6 = *(byte *)(param_1 + 0x2e) + 1;
    *(char *)(param_1 + 0x2e) = (char)uVar6;
    if ((int)((uVar6 & 0xff) * 0x10 + -2) <= (int)(uint)*(byte *)(param_1 + 0x4f)) goto _L30;
    bVar2 = 0xf9;
_L50:
    *(byte *)(param_1 + 0x51) = bVar1 & bVar2 | 8;
  }
  else {
    *(byte *)(param_1 + 0x51) = bVar1 & 0xef;
    if (*(char *)(param_1 + 0x4f) == '\0') {
      bVar2 = 0xe9;
      goto _L50;
    }
    *(byte *)(param_1 + 0x51) = bVar1 & 0xef | 4;
  }
  *(undefined1 *)(param_1 + 0x2e) = 0;
_L30:
  (**(code **)(_r_modules_funcs_p + 0x300))(param_1,*(code **)(_r_modules_funcs_p + 0x300));
  return 0;
}

