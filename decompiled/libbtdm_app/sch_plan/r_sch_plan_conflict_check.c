/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> sch_plan.o -> r_sch_plan_conflict_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_plan_conflict_check(int param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"sch_plan.c",0x5e,*(code **)(_r_plf_funcs_p + 8));
  }
  local_20 = *(undefined4 *)(param_1 + 4);
  uStack_1c = *(undefined4 *)(param_1 + 0xc);
  uStack_14 = *(undefined2 *)(param_1 + 0x14);
  uStack_18 = *(undefined4 *)(param_1 + 8);
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x6ec))(1,0,0,&local_20,*(code **)(_r_ip_funcs_p + 0x6ec));
  if ((iVar1 == 3) && (_g_conflict_elt != 0)) {
    pcVar2 = *(code **)(_g_conflict_elt + 0x18);
    iVar1 = _g_conflict_elt;
    if (*(code **)(param_1 + 0x18) == (code *)0x0) {
      if (pcVar2 == (code *)0x0) {
        return;
      }
    }
    else if ((pcVar2 == (code *)0x0) ||
            (*(byte *)(_g_conflict_elt + 0x16) <= *(byte *)(param_1 + 0x16))) {
      pcVar2 = *(code **)(param_1 + 0x18);
      iVar1 = param_1;
    }
    (*pcVar2)(*(undefined2 *)(iVar1 + 0x14),pcVar2);
  }
  return;
}

