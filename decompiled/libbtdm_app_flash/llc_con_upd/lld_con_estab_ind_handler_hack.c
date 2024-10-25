/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> lld_con_estab_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 lld_con_estab_ind_handler_hack(ushort *param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = r_llm_plan_elt_get(param_2 >> 8);
  if (*(int *)(&llc_env + (param_2 >> 8) * 4) == 0) {
    r_assert_err(0,"llc_con_upd.c",0xf0);
  }
  if (iVar2 == 0) {
    r_assert_err(0,"llc_con_upd.c",0xf1);
  }
  if (*(int *)(iVar2 + 4) == 0) {
    r_assert_err(0,"llc_con_upd.c",0xf2);
  }
  if (*(uint *)(iVar2 + 4) <= (uint)*param_1) {
    r_assert_err(0,"llc_con_upd.c",0xf3);
  }
  uVar1 = *param_1;
  uVar4 = *(uint *)(iVar2 + 4);
  if (uVar4 == 0) {
    r_assert_err(0,"llc_con_upd.c",0x94);
  }
  *(uint *)(iVar2 + 8) = ((uVar1 - 1) + uVar4) % uVar4;
  iVar3 = r_sdk_config_get_opts_ext();
  *(uint *)(iVar2 + 0xc) = *(byte *)(iVar3 + 0x10) + 3;
  iVar3 = r_sdk_config_get_opts_ext();
  *(uint *)(iVar2 + 0x10) = *(byte *)(iVar3 + 0x10) + 3;
  r_sch_plan_set(iVar2);
  return 0;
}

