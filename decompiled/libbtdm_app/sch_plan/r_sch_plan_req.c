/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> sch_plan.o -> r_sch_plan_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_plan_req(int param_1)

{
  int iVar1;
  
  (**(code **)(_r_ip_funcs_p + 0x6e4))(*(code **)(_r_ip_funcs_p + 0x6e4));
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x6ec))(0,1,param_1,0,*(code **)(_r_ip_funcs_p + 0x6ec));
  if ((iVar1 != 0) && (*(uint *)(param_1 + 8) < *(uint *)(param_1 + 0xc))) {
                    /* WARNING: Could not recover jumptable at 0x000104f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x6ec))(0,0,param_1,0,*(code **)(_r_ip_funcs_p + 0x6ec));
    return;
  }
  return;
}

