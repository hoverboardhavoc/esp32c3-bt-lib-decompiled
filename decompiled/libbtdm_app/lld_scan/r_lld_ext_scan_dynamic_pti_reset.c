/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_ext_scan_dynamic_pti_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_ext_scan_dynamic_pti_reset(int param_1)

{
  if (((param_1 != 0) && (*(char *)(_lld_scan_env + 0x17) != '\0')) &&
     (*(char *)(param_1 + 0x3d) == '\0')) {
                    /* WARNING: Could not recover jumptable at 0x000100ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x3d8))(1,*(code **)(_r_ip_funcs_p + 0x3d8));
    return;
  }
  return;
}

