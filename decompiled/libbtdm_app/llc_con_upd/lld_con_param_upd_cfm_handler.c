/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_con_upd.o -> lld_con_param_upd_cfm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_con_param_upd_cfm_handler(uint param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = param_1 >> 8 & 0xff;
  iVar6 = *(int *)(&llc_env + (param_1 >> 8) * 4);
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (*(byte *)(iVar2 + 0xd) <= uVar5) {
    return 0;
  }
  iVar2 = *(int *)(&llc_env + (param_1 >> 8) * 4);
  if (iVar2 == 0) {
    return 0;
  }
  if ((*(byte *)(iVar2 + 0x44) & 3) == 3) {
    return 0;
  }
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(uVar5,0,*(code **)(_r_ip_funcs_p + 0x678));
  if ((iVar2 != 5) &&
     (iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(uVar5,1,*(code **)(_r_ip_funcs_p + 0x678)),
     iVar2 != 5)) {
    pcVar1 = *(code **)(_r_plf_funcs_p + 0xc);
    uVar3 = (**(code **)(_r_ip_funcs_p + 0x678))(uVar5,0,*(code **)(_r_ip_funcs_p + 0x678));
    uVar4 = (**(code **)(_r_ip_funcs_p + 0x678))(uVar5,1,*(code **)(_r_ip_funcs_p + 0x678));
    (*pcVar1)(uVar3,uVar4,"llc_con_upd.c",0x697);
  }
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(uVar5,0,*(code **)(_r_ip_funcs_p + 0x678));
  if (iVar2 == 5) {
    pcVar1 = *(code **)(_r_ip_funcs_p + 0x5f4);
    uVar3 = 4;
  }
  else {
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(uVar5,1,*(code **)(_r_ip_funcs_p + 0x678));
    if (iVar2 != 5) goto _L328;
    uVar3 = 10;
    pcVar1 = *(code **)(_r_ip_funcs_p + 0x600);
  }
  (*pcVar1)(uVar5,uVar3,0,pcVar1);
_L328:
  if ((iVar6 != 0) &&
     (iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0)),
     *(char *)(iVar2 + 0x20) != '\0')) {
    (**(code **)(_r_ip_funcs_p + 0x614))
              (uVar5,*(undefined2 *)(iVar6 + 0x3e),*(code **)(_r_ip_funcs_p + 0x614));
  }
  return 0;
}

