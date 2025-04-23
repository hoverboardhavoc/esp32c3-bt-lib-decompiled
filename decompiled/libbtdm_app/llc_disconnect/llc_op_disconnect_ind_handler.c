/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_disconnect.o -> llc_op_disconnect_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 llc_op_disconnect_ind_handler(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  int iVar4;
  
  param_2 = param_2 >> 8;
  iVar4 = *(int *)(&llc_env + param_2 * 4);
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  uVar2 = 0;
  if ((((param_2 < *(byte *)(iVar1 + 0xd)) && (iVar1 = *(int *)(&llc_env + param_2 * 4), iVar1 != 0)
       ) && ((*(byte *)(iVar1 + 0x44) & 3) != 3)) &&
     (uVar2 = 2, (*(ushort *)(iVar4 + 0x42) & 0x200) == 0)) {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(param_2,0,*(code **)(_r_ip_funcs_p + 0x678));
    if (iVar1 != 0) {
      (**(code **)(_r_ip_funcs_p + 0x670))
                (param_2,0,0,param_1 + 9,*(code **)(_r_ip_funcs_p + 0x670));
      iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(param_2,0,*(code **)(_r_ip_funcs_p + 0x678));
      if (iVar1 != 0) {
        pcVar3 = *(code **)(_r_plf_funcs_p + 0xc);
        uVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(param_2,0,*(code **)(_r_ip_funcs_p + 0x678));
        (*pcVar3)(param_2,uVar2,"llc_disconnect.c",0x1c8);
      }
    }
    (**(code **)(_r_ip_funcs_p + 0x67c))(param_2,0,param_1,*(code **)(_r_ip_funcs_p + 0x67c));
    (**(code **)(_r_ip_funcs_p + 0x564))(param_2,0,*(code **)(_r_ip_funcs_p + 0x564));
    uVar2 = 1;
  }
  return uVar2;
}

