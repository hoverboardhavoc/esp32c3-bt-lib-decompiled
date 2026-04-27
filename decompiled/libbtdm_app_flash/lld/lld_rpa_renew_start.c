/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
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
    if (_lld_rpa_renew_env == 0) {
      r_lld_rpa_renew();
    }
    llm_rpa_renew_timer_start();
    return;
  }
  return;
}

