/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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
    (**(code **)(_r_plf_funcs_p + 8))(0,"rwip_driver.c",0x248,*(code **)(_r_plf_funcs_p + 8));
  }
                    /* WARNING: Could not recover jumptable at 0x000106c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x2a4))(param_1 * 0x271);
  return;
}

