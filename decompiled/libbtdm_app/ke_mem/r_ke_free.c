/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ke_mem.o -> r_ke_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_free(int *param_1)

{
  ushort uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  short sVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  
  if (param_1 == (int *)0x0) {
    (**(code **)(_r_plf_funcs_p + 0xc))(0,"ke_mem.c",0x19b,*(code **)(_r_plf_funcs_p + 0xc));
  }
  piVar8 = param_1 + -1;
  if ((short)param_1[-1] != -0x7cc8) {
    (**(code **)(_r_plf_funcs_p + 0xc))(param_1,"ke_mem.c",0x1a3,*(code **)(_r_plf_funcs_p + 0xc));
  }
  *(short *)(param_1 + -1) = -0xff1;
  uVar1 = *(ushort *)((int)param_1 + -2);
  uVar6 = 0;
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  do {
    while (iVar4 = (**(code **)(_r_modules_funcs_p + 300))
                             (uVar6,param_1,*(code **)(_r_modules_funcs_p + 300)), iVar4 != 0) {
      piVar2 = *(int **)(&r_plf_funcs_p + (uVar6 + 4) * 4);
      if (piVar2 != (int *)0x0) {
        if (param_1 <= piVar2) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"ke_mem.c",0x1c4,*(code **)(_r_plf_funcs_p + 8));
        }
        piVar7 = (int *)0x0;
        goto _L71;
      }
    }
    uVar6 = uVar6 + 1 & 0xff;
  } while (uVar6 != 4);
  piVar7 = (int *)0x0;
  (**(code **)(_r_plf_funcs_p + 8))("ke_mem.c",0x1c3,*(code **)(_r_plf_funcs_p + 8));
_L84:
  piVar7[1] = (int)piVar8;
  *param_1 = 0;
  param_1[1] = (int)piVar7;
  *(ushort *)((int)param_1 + -2) = uVar1;
  *(short *)(param_1 + -1) = -0x5aa6;
_L76:
                    /* WARNING: Could not recover jumptable at 0x000104f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
_L71:
  piVar3 = piVar2;
  if (piVar3 == (int *)0x0) goto _L84;
  if ((short)*piVar3 != -0x5aa6) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"ke_mem.c",0x1cc,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((int *)((uint)*(ushort *)((int)piVar3 + 2) + (int)piVar3) == piVar8) {
    uVar6 = (uint)*(ushort *)((int)piVar3 + 2) + (uint)uVar1;
    iVar4 = piVar3[1];
    sVar5 = (short)(uVar6 * 0x10000 >> 0x10);
    *(short *)((int)piVar3 + 2) = sVar5;
    if (iVar4 == (uVar6 & 0xffff) + (int)piVar3) {
      *(short *)((int)piVar3 + 2) = sVar5 + *(short *)(iVar4 + 2);
      iVar4 = *(int *)(iVar4 + 4);
      piVar3[1] = iVar4;
      if (iVar4 != 0) {
        *(int **)(iVar4 + 8) = piVar3;
      }
    }
    goto _L76;
  }
  if (piVar8 < piVar3) {
    if (piVar7 == (int *)0x0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"ke_mem.c",0x1e7,*(code **)(_r_plf_funcs_p + 8));
    }
    piVar7[1] = (int)piVar8;
    *(short *)(param_1 + -1) = -0x5aa6;
    param_1[1] = (int)piVar7;
    if (piVar3 == (int *)((int)piVar8 + (uint)uVar1)) {
      iVar4 = piVar3[1];
      *param_1 = iVar4;
      if (iVar4 != 0) {
        *(int **)(iVar4 + 8) = piVar8;
      }
      *(ushort *)((int)param_1 + -2) = *(short *)((int)piVar3 + 2) + uVar1;
    }
    else {
      *param_1 = (int)piVar3;
      piVar3[2] = (int)piVar8;
      *(ushort *)((int)param_1 + -2) = uVar1;
    }
    goto _L76;
  }
  piVar2 = (int *)piVar3[1];
  piVar7 = piVar3;
  goto _L71;
}

