/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  
  iVar3 = r_llm_plan_elt_get(param_2 >> 8);
  if (*(int *)(&llc_env + (param_2 >> 8) * 4) == 0) {
    r_assert_err(0,"llc_con_upd.c",0x6cf);
  }
  if (iVar3 == 0) {
    r_assert_err(0,"llc_con_upd.c",0x6d0);
  }
  if (*(int *)(iVar3 + 4) == 0) {
    r_assert_err(0,"llc_con_upd.c",0x6d1);
  }
  if (*(uint *)(iVar3 + 4) <= (uint)*param_1) {
    r_assert_param("llc_con_upd.c",0x6d2);
  }
  iVar2 = *(int *)(iVar3 + 8);
  uVar4 = *(uint *)(iVar3 + 4);
  if (uVar4 == 0) {
    r_assert_err(0,"llc_con_upd.c",0x94);
  }
  if ((uint)*param_1 != (iVar2 + 1U) % uVar4) {
    r_sch_plan_rem(iVar3);
    uVar1 = *param_1;
    uVar4 = *(uint *)(iVar3 + 4);
    if (uVar4 == 0) {
      r_assert_err(0,"llc_con_upd.c",0x94);
    }
    *(uint *)(iVar3 + 8) = ((uVar1 - 1) + uVar4) % uVar4;
    r_sch_plan_set(iVar3);
  }
  return 0;
}

