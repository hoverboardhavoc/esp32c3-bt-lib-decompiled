/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  uint uVar4;
  code *pcVar5;
  
  param_2 = param_2 >> 8;
  iVar1 = *(int *)(&llc_env + param_2 * 4);
  uVar4 = param_2 & 0xff;
  if (iVar1 == 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (param_2,0,"llc_disconnect.c",0x15f,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if (*param_1 != '\x16') {
    *(char *)(iVar1 + 0x46) = *param_1;
    *(undefined1 *)(iVar1 + 0x47) = 0;
  }
  *(undefined1 *)(iVar1 + 0x49) = 1;
  (**(code **)(_r_ip_funcs_p + 0x670))(uVar4,0,0,iVar1 + 0x46,*(code **)(_r_ip_funcs_p + 0x670));
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(uVar4,0,*(code **)(_r_ip_funcs_p + 0x678));
  if (iVar2 != 0) {
    pcVar5 = *(code **)(_r_plf_funcs_p + 0xc);
    uVar3 = (**(code **)(_r_ip_funcs_p + 0x678))(uVar4,0,*(code **)(_r_ip_funcs_p + 0x678));
    (*pcVar5)(param_2,uVar3,"llc_disconnect.c",0x16b);
  }
  (**(code **)(_r_ip_funcs_p + 0x670))(uVar4,1,0,iVar1 + 0x46,*(code **)(_r_ip_funcs_p + 0x670));
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(uVar4,1,*(code **)(_r_ip_funcs_p + 0x678));
  if (iVar1 != 0) {
    pcVar5 = *(code **)(_r_plf_funcs_p + 0xc);
    uVar3 = (**(code **)(_r_ip_funcs_p + 0x678))(uVar4,1,*(code **)(_r_ip_funcs_p + 0x678));
    (*pcVar5)(param_2,uVar3,"llc_disconnect.c",0x16e);
  }
  (**(code **)(_r_ip_funcs_p + 0x69c))(uVar4,*(code **)(_r_ip_funcs_p + 0x69c));
  return 0;
}

