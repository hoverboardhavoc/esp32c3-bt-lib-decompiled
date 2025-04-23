/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc.o -> r_llc_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_stop(int param_1)

{
  uint uVar1;
  
  uVar1 = param_1 << 8 | 1;
  if (*(int *)(&llc_env + param_1 * 4) != 0) {
    (**(code **)(_r_ip_funcs_p + 0x664))(2,3,*(code **)(_r_ip_funcs_p + 0x664));
  }
  (**(code **)(_r_modules_funcs_p + 0x154))(uVar1,0xff,*(code **)(_r_modules_funcs_p + 0x154));
                    /* WARNING: Could not recover jumptable at 0x00010282. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0xe4))(0x104,uVar1,uVar1,*(code **)(_r_modules_funcs_p + 0xe4));
  return;
}

