/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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
    r_assert_err(0,"rwip_driver.c",0x248);
  }
  if (*(code **)(_r_osi_funcs_p + 0x90) == (code *)0x0) {
    return (param_1 * 0x9c4000 + 500000) / 1000000;
  }
                    /* WARNING: Could not recover jumptable at 0x000100b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(_r_osi_funcs_p + 0x90))();
  return uVar1;
}

