/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_encrypt.o -> f_llc_op_encrypt_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_llc_op_encrypt_ind_handler(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  param_2 = param_2 >> 8;
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  iVar2 = *(int *)(&llc_env + param_2 * 4);
  if (((param_2 < *(byte *)(iVar1 + 0xd)) && (iVar2 != 0)) && ((*(byte *)(iVar2 + 0x44) & 3) != 3))
  {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(param_2,0,*(code **)(_r_ip_funcs_p + 0x678));
    uVar3 = 2;
    if (iVar1 == 0) {
      (**(code **)(_r_ip_funcs_p + 0x67c))(param_2,0,param_1,*(code **)(_r_ip_funcs_p + 0x67c));
      (**(code **)(_r_ip_funcs_p + 0x594))(param_2,0,0,*(code **)(_r_ip_funcs_p + 0x594));
      uVar3 = 1;
    }
  }
  else {
    (**(code **)(_r_ip_funcs_p + 0x57c))
              (param_2,*(undefined1 *)(iVar2 + 0x46),0,*(code **)(_r_ip_funcs_p + 0x57c));
    uVar3 = 0;
  }
  return uVar3;
}

