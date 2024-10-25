/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_con_upd.o -> lld_con_offset_upd_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_con_offset_upd_ind_handler(ushort *param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  uint uVar5;
  
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x4f0))(param_2 >> 8,*(code **)(_r_ip_funcs_p + 0x4f0));
  if (*(int *)(&llc_env + (param_2 >> 8) * 4) == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x6cf,*(code **)(_r_plf_funcs_p + 8));
  }
  if (iVar3 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x6d0,*(code **)(_r_plf_funcs_p + 8));
  }
  if (*(int *)(iVar3 + 4) == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x6d1,*(code **)(_r_plf_funcs_p + 8));
  }
  if (*(uint *)(iVar3 + 4) <= (uint)*param_1) {
    (**(code **)(_r_plf_funcs_p + 0xc))("llc_con_upd.c",0x6d2,*(code **)(_r_plf_funcs_p + 0xc));
  }
  iVar2 = *(int *)(iVar3 + 8);
  uVar5 = *(uint *)(iVar3 + 4);
  if (uVar5 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x94,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((uint)*param_1 != (iVar2 + 1U) % uVar5) {
    (**(code **)(_r_ip_funcs_p + 0x6f4))(iVar3,*(code **)(_r_ip_funcs_p + 0x6f4));
    uVar1 = *param_1;
    uVar5 = *(uint *)(iVar3 + 4);
    if (uVar5 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x94,*(code **)(_r_plf_funcs_p + 8));
    }
    pcVar4 = *(code **)(_r_ip_funcs_p + 0x6fc);
    *(uint *)(iVar3 + 8) = ((uVar1 - 1) + uVar5) % uVar5;
    (*pcVar4)(iVar3,pcVar4);
  }
  return 0;
}

