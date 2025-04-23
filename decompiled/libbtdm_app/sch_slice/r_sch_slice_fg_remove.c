/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> sch_slice.o -> r_sch_slice_fg_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_slice_fg_remove(uint param_1)

{
  int iVar1;
  
  sch_slice_env = ~(byte)(1 << (param_1 & 0x1f)) & sch_slice_env;
  if (param_1 == 2) {
    _sch_slice_params = -1;
  }
  else {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x1db,*(code **)(_r_plf_funcs_p + 8));
  }
  (**(code **)(_r_ip_funcs_p + 0x71c))(*(code **)(_r_ip_funcs_p + 0x71c));
  if ((_sch_slice_params == -1) &&
     (iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0)),
     *(char *)(iVar1 + 0x23) != '\0')) {
                    /* WARNING: Could not recover jumptable at 0x000102c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x42c))(*(code **)(_r_ip_funcs_p + 0x42c));
    return;
  }
  return;
}

