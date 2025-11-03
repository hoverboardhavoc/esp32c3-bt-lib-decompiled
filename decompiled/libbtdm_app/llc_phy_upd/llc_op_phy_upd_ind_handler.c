/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar3 + 0x18) != '\0') {
    param_3 = param_3 >> 8;
    iVar5 = *(int *)(&llc_env + param_3 * 4);
    iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(param_1,param_4,*(code **)(_r_plf_funcs_p + 0x38));
    if (((param_3 < *(byte *)(iVar3 + 0xd)) &&
        (iVar3 = *(int *)(&llc_env + param_3 * 4), iVar3 != 0)) &&
       ((*(byte *)(iVar3 + 0x44) & 3) != 3)) {
      iVar3 = (**(code **)(_r_ip_funcs_p + 0x678))(param_3,0,*(code **)(_r_ip_funcs_p + 0x678));
      if ((iVar3 == 0) &&
         (((*(ushort *)(iVar5 + 0x42) & 0x10) == 0 ||
          (iVar3 = (**(code **)(_r_ip_funcs_p + 0x680))(param_2,*(code **)(_r_ip_funcs_p + 0x680)),
          iVar3 != 0)))) {
        iVar3 = (**(code **)(_r_ip_funcs_p + 0x680))(param_2,*(code **)(_r_ip_funcs_p + 0x680));
        if ((iVar3 != 0) &&
           (iVar3 = (**(code **)(_r_ip_funcs_p + 0x680))(param_2,*(code **)(_r_ip_funcs_p + 0x680)),
           iVar3 != 1)) {
          pcVar4 = *(code **)(_r_plf_funcs_p + 0xc);
          uVar1 = (**(code **)(_r_ip_funcs_p + 0x680))(param_2,*(code **)(_r_ip_funcs_p + 0x680));
          (*pcVar4)(param_3,uVar1,"llc_phy_upd.c",0x5e5);
        }
        (**(code **)(_r_ip_funcs_p + 0x67c))(param_3,0,param_2,*(code **)(_r_ip_funcs_p + 0x67c));
        uVar1 = 1;
        pcVar4 = *(code **)(_r_ip_funcs_p + 0x648);
        uVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(param_2,*(code **)(_r_ip_funcs_p + 0x680));
        (*pcVar4)(param_3,uVar2,0);
      }
      else {
        uVar1 = 2;
      }
    }
    else {
      uVar1 = 0;
      if (*(char *)(param_2 + 0xe) != '\0') {
        (**(code **)(_r_ip_funcs_p + 0x644))
                  (param_3,*(undefined1 *)(iVar5 + 0x46),*(undefined1 *)(iVar5 + 0x1c),
                   *(undefined1 *)(iVar5 + 0x1d),*(code **)(_r_ip_funcs_p + 0x644));
      }
    }
    return uVar1;
  }
  if (*(char *)(param_2 + 0xe) != '\0') {
    (**(code **)(_r_ip_funcs_p + 0x644))(param_3 >> 8,0xc,0,0,*(code **)(_r_ip_funcs_p + 0x644));
  }
  return 0;
}

