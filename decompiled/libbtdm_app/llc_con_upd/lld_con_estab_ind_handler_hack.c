/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> llc_con_upd.o -> lld_con_estab_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_con_estab_ind_handler_hack(ushort *param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x4f0))(param_2 >> 8,*(code **)(_r_ip_funcs_p + 0x4f0));
  if (*(int *)(&llc_env + (param_2 >> 8) * 4) == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0xf1,*(code **)(_r_plf_funcs_p + 8));
  }
  if (iVar2 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0xf2,*(code **)(_r_plf_funcs_p + 8));
  }
  if (*(int *)(iVar2 + 4) == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0xf3,*(code **)(_r_plf_funcs_p + 8));
  }
  if (*(uint *)(iVar2 + 4) <= (uint)*param_1) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0xf4,*(code **)(_r_plf_funcs_p + 8));
  }
  uVar1 = *param_1;
  uVar4 = *(uint *)(iVar2 + 4);
  if (uVar4 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x94,*(code **)(_r_plf_funcs_p + 8));
  }
  *(uint *)(iVar2 + 8) = ((uVar1 - 1) + uVar4) % uVar4;
  iVar3 = sdk_config_get_opts_ext();
  *(uint *)(iVar2 + 0xc) = *(byte *)(iVar3 + 0x10) + 3;
  iVar3 = sdk_config_get_opts_ext();
  *(uint *)(iVar2 + 0x10) = *(byte *)(iVar3 + 0x10) + 3;
  (**(code **)(_r_ip_funcs_p + 0x6fc))(iVar2,*(code **)(_r_ip_funcs_p + 0x6fc));
  return 0;
}

