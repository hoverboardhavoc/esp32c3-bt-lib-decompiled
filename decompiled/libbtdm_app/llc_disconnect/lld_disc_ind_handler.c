/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> llc_disconnect.o -> lld_disc_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_disc_ind_handler(char *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  param_2 = param_2 >> 8;
  iVar1 = *(int *)(&llc_env + param_2 * 4);
  if (iVar1 == 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (param_2,0,"llc_disconnect.c",0x164,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if (*param_1 != '\x16') {
    *(char *)(iVar1 + 0x46) = *param_1;
    *(undefined1 *)(iVar1 + 0x47) = 0;
  }
  *(undefined1 *)(iVar1 + 0x49) = 1;
  (**(code **)(_r_ip_funcs_p + 0x670))(param_2,0,0,iVar1 + 0x46,*(code **)(_r_ip_funcs_p + 0x670));
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(param_2,0,*(code **)(_r_ip_funcs_p + 0x678));
  if (iVar2 != 0) {
    pcVar4 = *(code **)(_r_plf_funcs_p + 0xc);
    uVar3 = (**(code **)(_r_ip_funcs_p + 0x678))(param_2,0,*(code **)(_r_ip_funcs_p + 0x678));
    (*pcVar4)(param_2,uVar3,"llc_disconnect.c",0x172);
  }
  (**(code **)(_r_ip_funcs_p + 0x670))(param_2,1,0,iVar1 + 0x46,*(code **)(_r_ip_funcs_p + 0x670));
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(param_2,1,*(code **)(_r_ip_funcs_p + 0x678));
  if (iVar1 != 0) {
    pcVar4 = *(code **)(_r_plf_funcs_p + 0xc);
    uVar3 = (**(code **)(_r_ip_funcs_p + 0x678))(param_2,1,*(code **)(_r_ip_funcs_p + 0x678));
    (*pcVar4)(param_2,uVar3,"llc_disconnect.c",0x175);
  }
  (**(code **)(_r_ip_funcs_p + 0x69c))(param_2,*(code **)(_r_ip_funcs_p + 0x69c));
  return 0;
}

