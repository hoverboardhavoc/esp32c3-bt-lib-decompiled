/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  
  iVar3 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  sVar1 = *(short *)(param_1 * 0x7e + 0x12 + iVar2);
  r_lld_adv_scan_rsp_data_set(param_1,param_2,param_3,param_4,param_5);
  if (((((*(ushort *)(iVar3 + 0x74) & 0x10) != 0) && (param_4 != 0)) && (sVar1 != 0)) &&
     (*(short *)(iVar3 + 0x80) == sVar1)) {
    *(undefined2 *)(iVar3 + 0x80) = 0;
  }
  return;
}

