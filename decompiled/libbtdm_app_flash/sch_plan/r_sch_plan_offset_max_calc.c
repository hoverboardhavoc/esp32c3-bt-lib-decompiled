/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> sch_plan.o -> r_sch_plan_offset_max_calc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_sch_plan_offset_max_calc(uint param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = (param_1 - 1) + param_3;
  for (piVar2 = (int *)_sch_plan_env; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
    if (*(ushort *)(piVar2 + 5) != param_4) {
      uVar3 = piVar2[1];
      if (param_1 < (uint)piVar2[1]) {
        uVar3 = param_1;
      }
      if (uVar3 == 0) {
        r_assert_err(0,"sch_plan.c",0x95);
      }
      if ((param_1 % uVar3 == 0) && ((uint)piVar2[1] % uVar3 == 0)) {
        for (uVar1 = (uint)piVar2[2] % uVar3; uVar1 <= param_3; uVar1 = uVar1 + uVar3) {
        }
        if (uVar1 < param_3 + param_2) {
          r_assert_err(0,"sch_plan.c",0xa5);
        }
        if (uVar1 - param_2 < uVar4) {
          uVar4 = uVar1 - param_2;
        }
      }
    }
  }
  return uVar4 % param_1;
}

