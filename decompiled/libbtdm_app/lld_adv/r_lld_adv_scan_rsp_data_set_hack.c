/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_scan_rsp_data_set_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_scan_rsp_data_set_hack
               (int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  sVar1 = *(short *)(iVar3 + (param_1 * 9 + 1) * 0xe + 4);
  r_lld_adv_scan_rsp_data_set(param_1,param_2,param_3,param_4,param_5);
  if (((((*(ushort *)(iVar2 + 0x74) & 0x10) != 0) && (param_4 != 0)) && (sVar1 != 0)) &&
     (*(short *)(iVar2 + 0x80) == sVar1)) {
    *(undefined2 *)(iVar2 + 0x80) = 0;
  }
  return;
}

