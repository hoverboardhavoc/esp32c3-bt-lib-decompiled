/*
 * Last changed at upstream commit 4b93865b52ab92f0b7777ed415b6598b96ac1d6d
 * https://github.com/espressif/esp32c3-bt-lib/commit/4b93865b52ab92f0b7777ed415b6598b96ac1d6d
 * Upstream date: 2021-06-22 22:28:01 +0800
 * Upstream subject: Update ESP32-C3/ESP32-S3 bt-lib (e6e17bb4)
 * Source: libbtdm_app -> arch_main.o -> btdm_rw_run
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btdm_rw_run(uint param_1)

{
  int iVar1;
  
  if ((_btdm_pwr_state == 4) &&
     (iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
     *(char *)(iVar1 + 0xe) == '\x01')) {
    if (*(code **)(_r_osi_funcs_p + 0xa8) != (code *)0x0) {
      (**(code **)(_r_osi_funcs_p + 0xa8))();
    }
    _btdm_pwr_state = 0;
    if (param_1 == 2) {
_L134:
      (**(code **)(_r_modules_funcs_p + 0x284))(*(code **)(_r_modules_funcs_p + 0x284));
      iVar1 = (**(code **)(_r_osi_funcs_p + 0x34))
                        (_g_waking_sleeping_sem,0,*(code **)(_r_osi_funcs_p + 0x34));
      if (iVar1 != 0) {
        (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
        (**(code **)(_r_modules_funcs_p + 0x2b8))(*(code **)(_r_modules_funcs_p + 0x2b8));
        (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
        (**(code **)(_r_osi_funcs_p + 0x38))
                  (_g_waking_sleeping_sem,*(code **)(_r_osi_funcs_p + 0x38));
      }
      if (_btdm_pwr_state == 1) {
        do {
        } while (-1 < _DAT_60042000 << 0x10);
        if (*(code **)(_r_osi_funcs_p + 0x9c) != (code *)0x0) {
          (**(code **)(_r_osi_funcs_p + 0x9c))();
        }
        _btdm_pwr_state = 2;
      }
      return;
    }
  }
  else if (param_1 == 2) {
    if (_btdm_pwr_state == 2) {
      return;
    }
    goto _L134;
  }
  if (param_1 < 2) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0001136a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 8))(0,"arch_main.c",0x32d);
  return;
}

