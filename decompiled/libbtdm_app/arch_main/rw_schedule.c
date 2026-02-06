/*
 * Last changed at upstream commit ebd6043a8e3c3bbde45ee483895303b9c1229ab5
 * https://github.com/espressif/esp32c3-bt-lib/commit/ebd6043a8e3c3bbde45ee483895303b9c1229ab5
 * Upstream date: 2026-02-06 15:59:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b7de11e)
 * Source: libbtdm_app -> arch_main.o -> rw_schedule
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rw_schedule(void)

{
  int iVar1;
  
  (**(code **)(_r_modules_funcs_p + 0x284))(*(code **)(_r_modules_funcs_p + 0x284));
  iVar1 = (**(code **)(_r_osi_funcs_p + 0x34))
                    (_g_waking_sleeping_sem,0,*(code **)(_r_osi_funcs_p + 0x34));
  if (iVar1 != 0) {
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    (**(code **)(_r_modules_funcs_p + 0x2b8))(*(code **)(_r_modules_funcs_p + 0x2b8));
    (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
    (**(code **)(_r_osi_funcs_p + 0x38))(_g_waking_sleeping_sem,*(code **)(_r_osi_funcs_p + 0x38));
  }
  if (_btdm_pwr_state != 1) {
    return;
  }
  do {
  } while ((_DAT_60042000 & 0x8000) == 0);
  if (*(code **)(_r_osi_funcs_p + 0x9c) != (code *)0x0) {
    (**(code **)(_r_osi_funcs_p + 0x9c))();
  }
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  if (_btdm_pwr_state == 1) {
    _btdm_pwr_state = 2;
  }
                    /* WARNING: Could not recover jumptable at 0x00010e7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

