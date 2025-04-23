/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  
  bVar2 = *(byte *)(param_1 + 0x51);
  uVar7 = bVar2 & 2;
  if ((bVar2 & 2) == 0) {
    uVar6 = (uint)*(ushort *)(param_1 + 0x2c);
    if ((bVar2 & 0x10) != 0) {
      if ((bVar2 & 1) == 0) {
        pbVar5 = (byte *)(param_1 + 0x4e);
        pbVar8 = (byte *)((int)param_2 + 0xf);
        uVar7 = 0;
        do {
          if ((uint)*(byte *)(param_1 + 0x50) <= (uVar7 & 0xff)) goto _L41;
          iVar3 = uVar7 + uVar6;
          bVar2 = *pbVar8;
          bVar1 = *pbVar5;
          uVar7 = uVar7 + 1;
          pbVar5 = pbVar5 + -1;
          pbVar8 = pbVar8 + -1;
        } while (bVar1 == (*(byte *)(iVar3 + *(int *)(param_1 + 0x24)) ^ bVar2));
        uVar4 = 1;
      }
      else {
        iVar3 = *(int *)(param_1 + 0x28);
        for (; uVar7 < *(byte *)(param_1 + 0x50); uVar7 = uVar7 + 1 & 0xff) {
          *(byte *)(iVar3 + uVar7 + uVar6) =
               *(byte *)((0xf - uVar7) + param_1 + 0x3f) ^ *(byte *)((int)param_2 + (0xf - uVar7));
        }
_L41:
        uVar4 = 0;
      }
      if (*(code **)(param_1 + 0x18) != (code *)0x0) {
        (**(code **)(param_1 + 0x18))(uVar4,*(undefined4 *)(param_1 + 0x14));
      }
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
    if ((bVar2 & 1) == 0) {
      (**(code **)(_r_modules_funcs_p + 0x30c))
                (iVar3,iVar9,param_2,*(code **)(_r_modules_funcs_p + 0x30c));
      (**(code **)(_r_modules_funcs_p + 0x308))
                (iVar10,iVar10,iVar3,uVar7,0,*(code **)(_r_modules_funcs_p + 0x308));
    }
    else {
      (**(code **)(_r_modules_funcs_p + 0x308))
                (iVar10,iVar10,iVar9,0,*(code **)(_r_modules_funcs_p + 0x308));
      (**(code **)(_r_modules_funcs_p + 0x30c))
                (iVar3,iVar9,param_2,uVar7,*(code **)(_r_modules_funcs_p + 0x30c));
    }
    *(byte *)(param_1 + 0x51) = *(byte *)(param_1 + 0x51) | 2;
    *(char *)(param_1 + 0x2e) = *(char *)(param_1 + 0x2e) + '\x01';
    goto _L30;
  }
  memcpy((void *)(param_1 + 0x3f),param_2,0x10);
  if ((bVar2 & 0x10) == 0) {
    if ((bVar2 & 4) == 0) {
      *(byte *)(param_1 + 0x51) = bVar2 & 0xfd;
      if ((uint)*(ushort *)(param_1 + 0x2c) <= (uint)*(byte *)(param_1 + 0x2e) << 4) {
        *(byte *)(param_1 + 0x51) = bVar2 & 0xf5 | 0x10;
      }
      goto _L30;
    }
    uVar7 = *(byte *)(param_1 + 0x2e) + 1;
    *(char *)(param_1 + 0x2e) = (char)uVar7;
    if ((int)((uVar7 & 0xff) * 0x10 + -2) <= (int)(uint)*(byte *)(param_1 + 0x4f)) goto _L30;
    bVar1 = 0xf9;
_L51:
    bVar2 = bVar2 & bVar1 | 8;
  }
  else {
    if (*(char *)(param_1 + 0x4f) == '\0') {
      bVar1 = 0xe9;
      goto _L51;
    }
    bVar2 = bVar2 & 0xef | 4;
  }
  *(byte *)(param_1 + 0x51) = bVar2;
  *(undefined1 *)(param_1 + 0x2e) = 0;
_L30:
  (**(code **)(_r_modules_funcs_p + 0x300))(param_1,*(code **)(_r_modules_funcs_p + 0x300));
  return 0;
}

