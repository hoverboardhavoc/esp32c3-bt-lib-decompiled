/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
                    /* WARNING: Could not recover jumptable at 0x0001050e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x6ec))(0,0,param_1,0,*(code **)(_r_ip_funcs_p + 0x6ec));
    return;
  }
  return;
}

