/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> h4tl.o -> r_h4tl_read_hdr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_h4tl_read_hdr(undefined4 *param_1)

{
  *(undefined1 *)(param_1 + 5) = 1;
  (**(code **)*param_1)
            ((int)param_1 + 10,*(undefined4 *)(_r_modules_funcs_p + 0x84),param_1,*(code **)*param_1
            );
                    /* WARNING: Could not recover jumptable at 0x000100a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x2b4))(4,*(code **)(_r_modules_funcs_p + 0x2b4));
  return;
}

