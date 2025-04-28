/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  uint uVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  
  piVar7 = (int *)_r_ip_funcs_p;
  piVar3 = (int *)0;
_L37:
  do {
    do {
      iVar9 = (int)piVar3;
      piVar3 = piVar7;
      if (piVar3 == (int *)0x0) {
        if (_r_ip_funcs_p == 0) {
          return;
        }
                    /* WARNING: Could not recover jumptable at 0x00010270. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_modules_funcs_p + 0x2c0))(*(code **)(_r_modules_funcs_p + 0x2c0));
        return;
      }
      uVar1 = *(ushort *)(piVar3 + 5);
      piVar7 = (int *)*piVar3;
    } while ((uVar1 >> 0xe == 0) || (uVar6 = (int)(uint)uVar1 >> 4 & 0x3f, uVar6 == 0));
    *(byte *)((int)piVar3 + 0x16) = *(char *)((int)piVar3 + 0x16) + ((byte)uVar1 & 0xf);
    *(ushort *)(piVar3 + 5) = ((short)uVar6 + -1) * 0x10 | uVar1 & 0xfc0f;
    piVar2 = (int *)param_1;
    piVar10 = (int *)0;
    while ((piVar8 = piVar2, piVar8 != (int *)0x0 &&
           (iVar4 = (**(code **)(_r_ip_funcs_p + 0x6a0))
                              (piVar3,piVar8,*(code **)(_r_ip_funcs_p + 0x6a0)), iVar4 != 0))) {
      if (iVar4 != 5) {
        uVar6 = (uint)(piVar8[2] + piVar8[4]) / 0x271 + piVar8[1];
        if ((uint)piVar3[2] < (uint)(piVar8[2] + piVar8[4]) % 0x271) {
          uVar6 = uVar6 + 1;
        }
        uVar6 = uVar6 & 0xfffffff;
        piVar3[1] = uVar6;
        if (1 < *(ushort *)(piVar3 + 5) >> 0xe) {
          uVar5 = piVar3[3] - uVar6 & 0xfffffff;
          if (0x8000000 < uVar5) {
            uVar5 = -(uVar6 - piVar3[3] & 0xfffffff);
          }
          if ((int)uVar5 < (int)((uint)piVar3[4] / 0x271)) goto _L37;
        }
      }
      piVar2 = (int *)*piVar8;
      piVar10 = piVar8;
    }
    (**(code **)(_r_modules_funcs_p + 0x20))
              (&sch_arb_env,iVar9,piVar3,*(code **)(_r_modules_funcs_p + 0x20));
    (**(code **)(_r_modules_funcs_p + 0x30))
              (&sch_arb_env,piVar10,piVar3,*(code **)(_r_modules_funcs_p + 0x30));
    piVar3 = (int *)iVar9;
  } while( true );
}

