/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> sch_slice.o -> r_sch_slice_fg_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_slice_fg_add(uint param_1,undefined4 param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  
  sch_slice_env = sch_slice_env | (byte)(1 << (param_1 & 0x1f));
  if (param_1 == 2) {
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x71c);
    _sch_slice_params = param_2;
  }
  else {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x1b4,*(code **)(_r_plf_funcs_p + 8));
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x71c);
  }
                    /* WARNING: Could not recover jumptable at 0x00010224. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(UNRECOVERED_JUMPTABLE);
  return;
}

