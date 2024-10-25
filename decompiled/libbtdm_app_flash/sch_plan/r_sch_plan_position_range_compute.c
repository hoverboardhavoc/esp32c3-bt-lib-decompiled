/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  uint uVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  if (param_3 == 0) {
    return 1;
  }
  if (param_4 != 0) {
    uVar6 = (uint)*param_5;
    uVar9 = (uint)*param_6;
    if (uVar6 <= uVar9) {
      uVar3 = param_3 - param_4 & 0xffff;
      uVar1 = uVar3;
      piVar2 = _sch_plan_env;
      while (piVar2 != (int *)0x0) {
        if (uVar9 < uVar6) goto _L151;
        if (param_2 == 0xff) break;
        uVar11 = piVar2[1];
        if (((uVar11 == 0) || (iVar7 = piVar2[3], iVar7 == 0)) ||
           ((*(ushort *)(piVar2 + 5) & 0x7f) == param_1)) goto _L135;
        uVar10 = param_3;
        if (uVar11 < param_3) {
          uVar10 = uVar11;
        }
        if (uVar10 < (uint)(param_4 + iVar7)) {
          uVar4 = 3;
          goto _L137;
        }
        if ((param_3 % (uVar10 & 0xffff) == 0) && (uVar11 % uVar10 == 0)) {
          uVar8 = ((piVar2[2] + uVar10) - uVar6 % (uVar10 & 0xffff)) % uVar10;
          uVar12 = uVar8 & 0xffff;
          uVar11 = (iVar7 + -1 + uVar8) % uVar10 & 0xffff;
          if (((param_4 - 1U & 0xffff) < uVar12) && (uVar12 <= uVar11)) {
            if ((int)uVar8 < (int)(uVar1 + param_4)) {
              uVar1 = uVar12 - param_4 & 0xffff;
            }
            goto _L135;
          }
          uVar6 = uVar6 + 1 + uVar11 & 0xffff;
          uVar1 = uVar3;
          piVar2 = _sch_plan_env;
        }
        else {
_L135:
          piVar2 = (int *)*piVar2;
        }
      }
      uVar4 = 0;
_L137:
      if (uVar6 < uVar9) {
        uVar3 = uVar9 - uVar6;
        if ((int)uVar1 < (int)(uVar9 - uVar6)) {
          uVar3 = uVar1;
        }
        uVar5 = (ushort)(uVar6 % param_3);
        *param_5 = uVar5;
        *param_6 = uVar5 + (short)uVar3;
      }
      else {
_L151:
        uVar4 = 3;
      }
      return uVar4;
    }
  }
  return 1;
}

