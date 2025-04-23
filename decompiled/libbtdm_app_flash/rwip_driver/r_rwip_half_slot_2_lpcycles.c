/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> rwip_driver.o -> r_rwip_half_slot_2_lpcycles
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_rwip_half_slot_2_lpcycles(uint param_1)

{
  uint uVar1;
  
  if (0x3ffffe < param_1) {
    r_assert_err(0,"rwip_driver.c",0x24a);
  }
  if (*(code **)(_r_osi_funcs_p + 0x90) == (code *)0x0) {
    return (param_1 * 0x9c4000 + 500000) / 1000000;
  }
                    /* WARNING: Could not recover jumptable at 0x000100c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(_r_osi_funcs_p + 0x90))();
  return uVar1;
}

