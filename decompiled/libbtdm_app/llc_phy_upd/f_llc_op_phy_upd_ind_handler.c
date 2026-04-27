/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> llc_phy_upd.o -> f_llc_op_phy_upd_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_llc_op_phy_upd_ind_handler(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  int iVar5;
  
  param_2 = param_2 >> 8;
  iVar5 = *(int *)(&llc_env + param_2 * 4);
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (((param_2 < *(byte *)(iVar2 + 0xd)) && (iVar2 = *(int *)(&llc_env + param_2 * 4), iVar2 != 0))
     && ((*(byte *)(iVar2 + 0x44) & 3) != 3)) {
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(param_2,0,*(code **)(_r_ip_funcs_p + 0x678));
    if ((iVar2 == 0) &&
       (((*(ushort *)(iVar5 + 0x42) & 0x10) == 0 ||
        (iVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(param_1,*(code **)(_r_ip_funcs_p + 0x680)),
        iVar2 != 0)))) {
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(param_1,*(code **)(_r_ip_funcs_p + 0x680));
      if ((iVar2 != 0) &&
         (iVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(param_1,*(code **)(_r_ip_funcs_p + 0x680)),
         iVar2 != 1)) {
        pcVar4 = *(code **)(_r_plf_funcs_p + 0xc);
        uVar1 = (**(code **)(_r_ip_funcs_p + 0x680))(param_1,*(code **)(_r_ip_funcs_p + 0x680));
        (*pcVar4)(param_2,uVar1,"llc_phy_upd.c",0x5ee);
      }
      (**(code **)(_r_ip_funcs_p + 0x67c))(param_2,0,param_1,*(code **)(_r_ip_funcs_p + 0x67c));
      uVar1 = 1;
      pcVar4 = *(code **)(_r_ip_funcs_p + 0x648);
      uVar3 = (**(code **)(_r_ip_funcs_p + 0x680))(param_1,*(code **)(_r_ip_funcs_p + 0x680));
      (*pcVar4)(param_2,uVar3,0);
    }
    else {
      uVar1 = 2;
    }
  }
  else {
    uVar1 = 0;
    if (*(char *)(param_1 + 0xe) != '\0') {
      (**(code **)(_r_ip_funcs_p + 0x644))
                (param_2,*(undefined1 *)(iVar5 + 0x46),*(undefined1 *)(iVar5 + 0x1c),
                 *(undefined1 *)(iVar5 + 0x1d),*(code **)(_r_ip_funcs_p + 0x644));
    }
  }
  return uVar1;
}

