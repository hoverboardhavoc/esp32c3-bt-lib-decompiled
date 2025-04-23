/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> lld_con_offset_upd_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 lld_con_offset_upd_ind_handler(ushort *param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = r_llm_plan_elt_get(param_2 >> 8);
  if (*(int *)(&llc_env + (param_2 >> 8) * 4) == 0) {
    r_assert_err(0,"llc_con_upd.c",0x6cf);
  }
  if (iVar2 == 0) {
    r_assert_err(0,"llc_con_upd.c",0x6d0);
  }
  if (*(int *)(iVar2 + 4) == 0) {
    r_assert_err(0,"llc_con_upd.c",0x6d1);
  }
  if (*(uint *)(iVar2 + 4) <= (uint)*param_1) {
    r_assert_param("llc_con_upd.c",0x6d2);
  }
  iVar3 = *(int *)(iVar2 + 8);
  uVar4 = *(uint *)(iVar2 + 4);
  if (uVar4 == 0) {
    r_assert_err(0,"llc_con_upd.c",0x94);
  }
  if ((uint)*param_1 != (iVar3 + 1U) % uVar4) {
    r_sch_plan_rem(iVar2);
    uVar1 = *param_1;
    uVar4 = *(uint *)(iVar2 + 4);
    if (uVar4 == 0) {
      r_assert_err(0,"llc_con_upd.c",0x94);
    }
    *(uint *)(iVar2 + 8) = ((uVar1 - 1) + uVar4) % uVar4;
    r_sch_plan_set(iVar2);
  }
  return 0;
}

