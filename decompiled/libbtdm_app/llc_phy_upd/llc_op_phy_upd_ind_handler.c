/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_phy_upd.o -> llc_op_phy_upd_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
llc_op_phy_upd_ind_handler(undefined4 param_1,int param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar2 + 0x18) != '\0') {
    param_3 = param_3 >> 8;
    iVar4 = *(int *)(&llc_env + param_3 * 4);
    iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(param_1,param_4,*(code **)(_r_plf_funcs_p + 0x38));
    if (((param_3 < *(byte *)(iVar2 + 0xd)) &&
        (iVar2 = *(int *)(&llc_env + param_3 * 4), iVar2 != 0)) &&
       ((*(byte *)(iVar2 + 0x44) & 3) != 3)) {
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(param_3,0,*(code **)(_r_ip_funcs_p + 0x678));
      if ((iVar2 == 0) &&
         (((*(ushort *)(iVar4 + 0x42) & 0x10) == 0 ||
          (iVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(param_2,*(code **)(_r_ip_funcs_p + 0x680)),
          iVar2 != 0)))) {
        iVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(param_2,*(code **)(_r_ip_funcs_p + 0x680));
        if ((iVar2 != 0) &&
           (iVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(param_2,*(code **)(_r_ip_funcs_p + 0x680)),
           iVar2 != 1)) {
          pcVar3 = *(code **)(_r_plf_funcs_p + 0xc);
          uVar1 = (**(code **)(_r_ip_funcs_p + 0x680))(param_2,*(code **)(_r_ip_funcs_p + 0x680));
          (*pcVar3)(param_3,uVar1,"llc_phy_upd.c",0x5d1);
        }
        (**(code **)(_r_ip_funcs_p + 0x67c))(param_3,0,param_2,*(code **)(_r_ip_funcs_p + 0x67c));
        pcVar3 = *(code **)(_r_ip_funcs_p + 0x648);
        uVar1 = (**(code **)(_r_ip_funcs_p + 0x680))(param_2,*(code **)(_r_ip_funcs_p + 0x680));
        (*pcVar3)(param_3,uVar1,0);
        uVar1 = 1;
      }
      else {
        uVar1 = 2;
      }
    }
    else {
      if (*(char *)(param_2 + 0xe) != '\0') {
        (**(code **)(_r_ip_funcs_p + 0x644))
                  (param_3,*(undefined1 *)(iVar4 + 0x46),*(undefined1 *)(iVar4 + 0x1c),
                   *(undefined1 *)(iVar4 + 0x1d),*(code **)(_r_ip_funcs_p + 0x644));
      }
      uVar1 = 0;
    }
    return uVar1;
  }
  if (*(char *)(param_2 + 0xe) != '\0') {
    (**(code **)(_r_ip_funcs_p + 0x644))(param_3 >> 8,0xc,0,0,*(code **)(_r_ip_funcs_p + 0x644));
  }
  return 0;
}

