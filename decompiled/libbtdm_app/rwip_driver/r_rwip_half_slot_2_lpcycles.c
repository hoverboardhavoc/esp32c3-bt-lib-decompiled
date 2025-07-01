/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
 * Source: libbtdm_app -> rwip_driver.o -> r_rwip_half_slot_2_lpcycles
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_half_slot_2_lpcycles(uint param_1)

{
  if (0x3ffffe < param_1) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x24b,*(code **)(_r_plf_funcs_p + 8));
  }
                    /* WARNING: Could not recover jumptable at 0x000106ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x2a4))(param_1 * 0x271,*(code **)(_r_modules_funcs_p + 0x2a4));
  return;
}

