/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> sch_plan.o -> r_sch_plan_conflict_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_plan_conflict_check(int param_1)

{
  int iVar1;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    r_assert_err(0,"sch_plan.c",0x5e);
  }
  local_20 = *(undefined4 *)(param_1 + 4);
  uStack_1c = *(undefined4 *)(param_1 + 0xc);
  uStack_14 = *(undefined2 *)(param_1 + 0x14);
  uStack_18 = *(undefined4 *)(param_1 + 8);
  iVar1 = r_sch_plan_offset_req(1,0,0,&local_20);
  if ((iVar1 == 3) && (_g_conflict_elt != 0)) {
    if (*(int *)(param_1 + 0x18) == 0) {
      iVar1 = _g_conflict_elt;
      if (*(int *)(_g_conflict_elt + 0x18) == 0) {
        return;
      }
    }
    else {
      iVar1 = param_1;
      if ((*(int *)(_g_conflict_elt + 0x18) != 0) &&
         (iVar1 = param_1, *(byte *)(param_1 + 0x16) < *(byte *)(_g_conflict_elt + 0x16))) {
        iVar1 = _g_conflict_elt;
      }
    }
    (**(code **)(iVar1 + 0x18))(*(undefined2 *)(iVar1 + 0x14),*(code **)(iVar1 + 0x18));
  }
  return;
}

