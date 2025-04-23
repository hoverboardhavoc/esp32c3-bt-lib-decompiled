/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld.o -> lld_rpa_renew_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lld_rpa_renew_start(uint param_1)

{
  uint uVar1;
  
  if (first_boot_0 != '\0') {
    uVar1 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
    _DAT_60031178 = uVar1 & 0x3fffff | 0x80000000;
    uVar1 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
    _DAT_6003117c = uVar1 & 0x3fffff | 0x80000000;
    first_boot_0 = '\0';
  }
  if ((param_1 & 2) != 0) {
    llm_rpa_renew_timer_start();
    return;
  }
  return;
}

