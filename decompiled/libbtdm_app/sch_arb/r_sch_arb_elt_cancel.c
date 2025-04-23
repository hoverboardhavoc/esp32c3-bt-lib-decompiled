/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> sch_arb.o -> r_sch_arb_elt_cancel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_arb_elt_cancel(int param_1)

{
  ushort uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  
  piVar8 = (int *)_r_ip_funcs_p;
  piVar3 = (int *)0;
_L45:
  do {
    do {
      iVar4 = (int)piVar3;
      piVar3 = piVar8;
      if (piVar3 == (int *)0x0) {
        if (_r_ip_funcs_p == 0) {
          return;
        }
                    /* WARNING: Could not recover jumptable at 0x00010276. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_modules_funcs_p + 0x2c0))(*(code **)(_r_modules_funcs_p + 0x2c0));
        return;
      }
      uVar1 = *(ushort *)(piVar3 + 5);
      piVar8 = (int *)*piVar3;
    } while ((uVar1 >> 0xe == 0) || (uVar7 = (int)(uint)uVar1 >> 4 & 0x3f, uVar7 == 0));
    *(byte *)((int)piVar3 + 0x16) = *(char *)((int)piVar3 + 0x16) + ((byte)uVar1 & 0xf);
    *(ushort *)(piVar3 + 5) = ((short)uVar7 + -1) * 0x10 | uVar1 & 0xfc0f;
    piVar2 = (int *)param_1;
    piVar10 = (int *)0;
    while ((piVar9 = piVar2, piVar9 != (int *)0x0 &&
           (iVar5 = (**(code **)(_r_ip_funcs_p + 0x6a0))
                              (piVar3,piVar9,*(code **)(_r_ip_funcs_p + 0x6a0)), iVar5 != 0))) {
      if (iVar5 != 5) {
        uVar7 = (uint)(piVar9[2] + piVar9[4]) / 0x271 + piVar9[1] +
                (uint)((uint)piVar3[2] < (uint)(piVar9[2] + piVar9[4]) % 0x271) & 0xfffffff;
        piVar3[1] = uVar7;
        if (1 < *(ushort *)(piVar3 + 5) >> 0xe) {
          uVar6 = piVar3[3] - uVar7 & 0xfffffff;
          if (0x8000000 < uVar6) {
            uVar6 = -(uVar7 - piVar3[3] & 0xfffffff);
          }
          if ((int)uVar6 < (int)((uint)piVar3[4] / 0x271)) goto _L45;
        }
      }
      piVar2 = (int *)*piVar9;
      piVar10 = piVar9;
    }
    (**(code **)(_r_modules_funcs_p + 0x20))
              (&sch_arb_env,iVar4,piVar3,*(code **)(_r_modules_funcs_p + 0x20));
    (**(code **)(_r_modules_funcs_p + 0x30))
              (&sch_arb_env,piVar10,piVar3,*(code **)(_r_modules_funcs_p + 0x30));
    piVar3 = (int *)iVar4;
  } while( true );
}

