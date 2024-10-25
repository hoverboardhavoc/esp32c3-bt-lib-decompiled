/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_con_upd.o -> llc_op_con_upd_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 llc_op_con_upd_ind_handler(int param_1,uint param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  
  param_2 = param_2 >> 8;
  iVar6 = *(int *)(&llc_env + param_2 * 4);
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  uVar5 = param_2 & 0xff;
  if (((uVar5 < *(byte *)(iVar2 + 0xd)) && (iVar2 = *(int *)(&llc_env + param_2 * 4), iVar2 != 0))
     && ((*(byte *)(iVar2 + 0x44) & 3) != 3)) {
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(uVar5,0,*(code **)(_r_ip_funcs_p + 0x678));
    if ((iVar2 == 0) &&
       (((*(ushort *)(iVar6 + 0x42) & 0x10) == 0 ||
        (iVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(param_1,*(code **)(_r_ip_funcs_p + 0x680)),
        iVar2 != 0)))) {
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(param_1,*(code **)(_r_ip_funcs_p + 0x680));
      if ((iVar2 != 0) &&
         (iVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(param_1,*(code **)(_r_ip_funcs_p + 0x680)),
         iVar2 != 1)) {
        pcVar1 = *(code **)(_r_plf_funcs_p + 0xc);
        uVar3 = (**(code **)(_r_ip_funcs_p + 0x680))(param_1,*(code **)(_r_ip_funcs_p + 0x680));
        (*pcVar1)(param_2,uVar3,"llc_con_upd.c",0x679);
      }
      (**(code **)(_r_ip_funcs_p + 0x67c))(uVar5,0,param_1,*(code **)(_r_ip_funcs_p + 0x67c));
      pcVar1 = *(code **)(_r_ip_funcs_p + 0x5f4);
      uVar3 = (**(code **)(_r_ip_funcs_p + 0x680))(param_1,*(code **)(_r_ip_funcs_p + 0x680));
      (*pcVar1)(uVar5,uVar3,0);
      uVar3 = 1;
    }
    else {
      uVar3 = 2;
    }
  }
  else {
    if (*(char *)(param_1 + 0x2d) == '\0') {
      *(byte *)(iVar6 + 0x45) = *(byte *)(iVar6 + 0x45) & 0x7f;
    }
    else {
      cVar4 = *(char *)(iVar6 + 0x46);
      if (cVar4 == '\0') {
        cVar4 = *(char *)(iVar6 + 0x47);
      }
      (**(code **)(_r_ip_funcs_p + 0x5f0))(uVar5,cVar4,param_1,*(code **)(_r_ip_funcs_p + 0x5f0));
    }
    uVar3 = 0;
  }
  return uVar3;
}

