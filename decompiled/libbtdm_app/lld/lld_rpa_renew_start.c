/*
 * Last changed at upstream commit 9780fd66d97866977d972fb63319830f47f12785
 * https://github.com/espressif/esp32c3-bt-lib/commit/9780fd66d97866977d972fb63319830f47f12785
 * Upstream date: 2024-04-23 11:19:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a771b7c)
 * Source: libbtdm_app -> lld.o -> lld_rpa_renew_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lld_rpa_renew_start(uint param_1)

{
  uint uVar1;
  
  if (_LANCHOR6 != '\0') {
    uVar1 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
    _DAT_60031178 = uVar1 & 0x3fffff | 0x80000000;
    uVar1 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
    _DAT_6003117c = uVar1 & 0x3fffff | 0x80000000;
    _LANCHOR6 = '\0';
  }
  if ((param_1 & 2) != 0) {
    llm_rpa_renew_timer_start();
    return;
  }
  return;
}

