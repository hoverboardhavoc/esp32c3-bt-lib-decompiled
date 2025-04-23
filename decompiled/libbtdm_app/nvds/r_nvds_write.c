/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> nvds.o -> r_nvds_write
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_nvds_write(int param_1,int param_2,undefined4 param_3)

{
  if (DAT_000106fc < (uint)(param_1 + param_2)) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"nvds.c",0x1de,param_3,*(code **)(_r_plf_funcs_p + 8));
  }
                    /* WARNING: Could not recover jumptable at 0x00010216. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 100))
            (DAT_00010700,DAT_000106f8 + param_1,param_2,param_3,0,*(code **)(_r_plf_funcs_p + 100))
  ;
  return;
}

