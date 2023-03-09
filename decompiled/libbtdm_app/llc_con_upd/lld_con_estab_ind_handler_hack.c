/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
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
  code *pcVar4;
  uint uVar5;
  
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x4f0))(param_2 >> 8,*(code **)(_r_ip_funcs_p + 0x4f0));
  if (*(int *)(&llc_env + (param_2 >> 8) * 4) == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0xed,*(code **)(_r_plf_funcs_p + 8));
  }
  if (iVar2 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0xee,*(code **)(_r_plf_funcs_p + 8));
  }
  if (*(int *)(iVar2 + 4) == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0xef,*(code **)(_r_plf_funcs_p + 8));
  }
  if (*(uint *)(iVar2 + 4) <= (uint)*param_1) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0xf0,*(code **)(_r_plf_funcs_p + 8));
  }
  uVar1 = *param_1;
  uVar5 = *(uint *)(iVar2 + 4);
  if (uVar5 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x94,*(code **)(_r_plf_funcs_p + 8));
  }
  pcVar4 = *(code **)(_r_plf_funcs_p + 0xf0);
  *(uint *)(iVar2 + 8) = ((uVar1 - 1) + uVar5) % uVar5;
  iVar3 = (*pcVar4)(pcVar4);
  *(uint *)(iVar2 + 0xc) = *(byte *)(iVar3 + 0x10) + 3;
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  *(uint *)(iVar2 + 0x10) = *(byte *)(iVar3 + 0x10) + 3;
  (**(code **)(_r_ip_funcs_p + 0x6fc))(iVar2,*(code **)(_r_ip_funcs_p + 0x6fc));
  return 0;
}

