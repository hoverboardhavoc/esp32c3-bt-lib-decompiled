/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> aes_ccm.o -> r_aes_ccm_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_aes_ccm_continue(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  short asStack_22 [7];
  
  bVar1 = *(byte *)(param_1 + 0x51);
  bVar5 = bVar1 & 2;
  bVar4 = bVar1 & 0x10;
  if ((bVar1 & 2) == 0) {
    if ((bVar1 & 0x10) == 0) {
      bVar5 = *(char *)(param_1 + 0x2e) + 1;
    }
    *(undefined1 *)(param_1 + 0x3e) = 1;
    *(byte *)(param_1 + 0x2f) = bVar5;
    *(undefined1 *)(param_1 + 0x30) = 0;
  }
  else {
    if ((bVar1 & 0x10) == 0) {
      iVar2 = param_1 + 0x3f;
      if ((bVar1 & 4) != 0) {
        uVar7 = (uint)*(byte *)(param_1 + 0x2e) * 0x10;
        if (*(byte *)(param_1 + 0x2e) == 0) {
          asStack_22[0] = (ushort)*(byte *)(param_1 + 0x4f) << 8;
          (**(code **)(_r_modules_funcs_p + 0x308))
                    (iVar2,iVar2,asStack_22,2,0,*(code **)(_r_modules_funcs_p + 0x308));
          uVar3 = 0xe;
          bVar4 = 2;
        }
        else {
          uVar7 = uVar7 - 2 & 0xffff;
          uVar3 = 0x10;
        }
        uVar6 = *(byte *)(param_1 + 0x4f) - uVar7;
        if ((int)uVar6 < (int)uVar3) {
          uVar3 = uVar6 & 0xff;
        }
        (**(code **)(_r_modules_funcs_p + 0x308))
                  (iVar2,iVar2,*(int *)(param_1 + 0x20) + uVar7,uVar3,bVar4,
                   *(code **)(_r_modules_funcs_p + 0x308));
      }
      goto _L11;
    }
    *(byte *)(param_1 + 0x3e) =
         (*(char *)(param_1 + 0x4f) != '\0') << 6 | *(byte *)(param_1 + 0x3e) & 0x3f;
    if ((uint)((int)(*(byte *)(param_1 + 0x50) - 2) / 2 << 3) >> 6 != 0) {
      (**(code **)(_r_plf_funcs_p + 0xc))(0x38,"aes_ccm.c",0xcf,*(code **)(_r_plf_funcs_p + 0xc));
    }
    *(byte *)(param_1 + 0x3e) =
         *(byte *)(param_1 + 0x3e) & 0xc0 | (byte)((int)(*(byte *)(param_1 + 0x50) - 2) / 2 << 3) |
         1;
    *(char *)(param_1 + 0x2f) = (char)*(undefined2 *)(param_1 + 0x2c);
    *(char *)(param_1 + 0x30) = (char)((ushort)*(undefined2 *)(param_1 + 0x2c) >> 8);
  }
  iVar2 = param_1 + 0x2f;
_L11:
                    /* WARNING: Could not recover jumptable at 0x00010184. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x324))
            (param_1,*(undefined4 *)(param_1 + 0x1c),iVar2,*(code **)(_r_modules_funcs_p + 0x324));
  return;
}

