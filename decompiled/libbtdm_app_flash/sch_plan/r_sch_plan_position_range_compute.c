/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> sch_plan.o -> r_sch_plan_position_range_compute
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
r_sch_plan_position_range_compute
          (ushort param_1,int param_2,uint param_3,int param_4,ushort *param_5,ushort *param_6)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  if (param_3 == 0) {
    return 1;
  }
  if (param_4 != 0) {
    uVar5 = (uint)*param_5;
    uVar10 = (uint)*param_6;
    if (uVar5 <= uVar10) {
      uVar2 = param_3 - param_4 & 0xffff;
      piVar1 = _sch_plan_env;
      uVar11 = uVar2;
      while (piVar1 != (int *)0x0) {
        if (uVar10 < uVar5) goto _L151;
        if (param_2 == 0xff) break;
        uVar8 = piVar1[1];
        if (((uVar8 == 0) || (iVar6 = piVar1[3], iVar6 == 0)) ||
           ((*(ushort *)(piVar1 + 5) & 0x7f) == param_1)) goto _L135;
        uVar7 = param_3;
        if (uVar8 < param_3) {
          uVar7 = uVar8;
        }
        if (uVar7 < (uint)(param_4 + iVar6)) {
          uVar3 = 3;
          goto _L137;
        }
        if ((param_3 % (uVar7 & 0xffff) == 0) && (uVar8 % uVar7 == 0)) {
          uVar9 = ((piVar1[2] + uVar7) - uVar5 % (uVar7 & 0xffff)) % uVar7;
          uVar8 = uVar9 & 0xffff;
          uVar7 = (iVar6 + -1 + uVar9) % uVar7 & 0xffff;
          if (((param_4 - 1U & 0xffff) < uVar8) && (uVar8 <= uVar7)) {
            if ((int)uVar9 < (int)(uVar11 + param_4)) {
              uVar11 = uVar8 - param_4 & 0xffff;
            }
            goto _L135;
          }
          uVar5 = uVar5 + 1 + uVar7 & 0xffff;
          piVar1 = _sch_plan_env;
          uVar11 = uVar2;
        }
        else {
_L135:
          piVar1 = (int *)*piVar1;
        }
      }
      uVar3 = 0;
_L137:
      if (uVar5 < uVar10) {
        uVar2 = uVar10 - uVar5;
        if ((int)uVar11 < (int)(uVar10 - uVar5)) {
          uVar2 = uVar11;
        }
        uVar4 = (ushort)(uVar5 % param_3);
        *param_5 = uVar4;
        *param_6 = uVar4 + (short)uVar2;
      }
      else {
_L151:
        uVar3 = 3;
      }
      return uVar3;
    }
  }
  return 1;
}

