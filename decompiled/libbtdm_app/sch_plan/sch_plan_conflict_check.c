/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> sch_plan.o -> sch_plan_conflict_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sch_plan_conflict_check(int param_1)

{
  int iVar1;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"sch_plan.c",0x61,*(code **)(_r_plf_funcs_p + 8));
  }
  local_20 = *(undefined4 *)(param_1 + 4);
  uStack_1c = *(undefined4 *)(param_1 + 0xc);
  uStack_14 = *(undefined2 *)(param_1 + 0x14);
  uStack_18 = *(undefined4 *)(param_1 + 8);
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x6ec))(1,0,0,&local_20,*(code **)(_r_ip_funcs_p + 0x6ec));
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

