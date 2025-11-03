/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> llc_con_upd.o -> lld_con_param_upd_cfm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_con_param_upd_cfm_handler(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  code *pcVar5;
  
  param_1 = param_1 >> 8;
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (*(byte *)(iVar1 + 0xd) <= param_1) {
    return 0;
  }
  iVar1 = *(int *)(&llc_env + param_1 * 4);
  if (iVar1 == 0) {
    return 0;
  }
  if ((*(byte *)(iVar1 + 0x44) & 3) == 3) {
    return 0;
  }
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(param_1,0,*(code **)(_r_ip_funcs_p + 0x678));
  if ((iVar1 != 5) &&
     (iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(param_1,1,*(code **)(_r_ip_funcs_p + 0x678)),
     iVar1 != 5)) {
    pcVar5 = *(code **)(_r_plf_funcs_p + 0xc);
    uVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(param_1,0,*(code **)(_r_ip_funcs_p + 0x678));
    uVar3 = (**(code **)(_r_ip_funcs_p + 0x678))(param_1,1,*(code **)(_r_ip_funcs_p + 0x678));
    (*pcVar5)(uVar2,uVar3,"llc_con_upd.c",0x6ae);
  }
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(param_1,0,*(code **)(_r_ip_funcs_p + 0x678));
  if (iVar1 == 5) {
    pcVar5 = *(code **)(_r_ip_funcs_p + 0x5f4);
    uVar2 = 4;
  }
  else {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(param_1,1,*(code **)(_r_ip_funcs_p + 0x678));
    if (iVar1 != 5) goto _L325;
    uVar2 = 10;
    pcVar5 = *(code **)(_r_ip_funcs_p + 0x600);
  }
  (*pcVar5)(param_1,uVar2,0,pcVar5);
_L325:
  if ((iVar4 != 0) &&
     (iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0)),
     *(char *)(iVar1 + 0x20) != '\0')) {
    (**(code **)(_r_ip_funcs_p + 0x614))
              (param_1,*(undefined2 *)(iVar4 + 0x3e),*(code **)(_r_ip_funcs_p + 0x614));
  }
  return 0;
}

