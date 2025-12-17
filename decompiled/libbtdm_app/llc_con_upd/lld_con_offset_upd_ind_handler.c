/*
 * Last changed at upstream commit 9b50531537e755792ac827d00d233eab499a0b37
 * https://github.com/espressif/esp32c3-bt-lib/commit/9b50531537e755792ac827d00d233eab499a0b37
 * Upstream date: 2025-12-17 10:51:37 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(5106725)
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
  code *pcVar3;
  int iVar4;
  uint uVar5;
  
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x4f0))(param_2 >> 8,*(code **)(_r_ip_funcs_p + 0x4f0));
  if (*(int *)(&llc_env + (param_2 >> 8) * 4) == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x6e8,*(code **)(_r_plf_funcs_p + 8));
  }
  if (iVar2 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x6e9,*(code **)(_r_plf_funcs_p + 8));
  }
  if (*(int *)(iVar2 + 4) == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x6ea,*(code **)(_r_plf_funcs_p + 8));
  }
  if (*(uint *)(iVar2 + 4) <= (uint)*param_1) {
    (**(code **)(_r_plf_funcs_p + 0xc))("llc_con_upd.c",0x6eb,*(code **)(_r_plf_funcs_p + 0xc));
  }
  iVar4 = *(int *)(iVar2 + 8);
  uVar5 = *(uint *)(iVar2 + 4);
  if (uVar5 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x94,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((uint)*param_1 != (iVar4 + 1U) % uVar5) {
    (**(code **)(_r_ip_funcs_p + 0x6f4))(iVar2,*(code **)(_r_ip_funcs_p + 0x6f4));
    uVar1 = *param_1;
    uVar5 = *(uint *)(iVar2 + 4);
    if (uVar5 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x94,*(code **)(_r_plf_funcs_p + 8));
    }
    pcVar3 = *(code **)(_r_ip_funcs_p + 0x6fc);
    *(uint *)(iVar2 + 8) = ((uVar1 - 1) + uVar5) % uVar5;
    (*pcVar3)(iVar2,pcVar3);
  }
  return 0;
}

