/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> sch_slice.o -> r_sch_slice_per_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_slice_per_add(int param_1,uint param_2,undefined4 param_3,undefined2 param_4)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 - 3U < 2) {
    *(undefined2 *)(memset + param_2 * 8) = param_4;
    *(undefined4 *)(__clzsi2 + param_2 * 8) = param_3;
    _r_plf_funcs_p = 1 << (param_2 & 0x1f) | _r_plf_funcs_p;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x71c);
  }
  else {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x21d,*(code **)(_r_plf_funcs_p + 8));
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x71c);
  }
                    /* WARNING: Could not recover jumptable at 0x00010318. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(UNRECOVERED_JUMPTABLE);
  return;
}

