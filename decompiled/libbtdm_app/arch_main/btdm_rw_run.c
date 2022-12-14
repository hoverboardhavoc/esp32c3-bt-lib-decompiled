/*
 * Last changed at upstream commit bba9af9259e0999ef246426d31a793fe0a3ff4db
 * https://github.com/espressif/esp32c3-bt-lib/commit/bba9af9259e0999ef246426d31a793fe0a3ff4db
 * Upstream date: 2022-12-14 15:32:37 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(80abacdd)
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
    if (param_1 != 2) {
_L172:
      if (param_1 < 2) {
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x0001147a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 8))(0,"arch_main.c",0x37b);
      return;
    }
  }
  else {
    if (param_1 != 2) goto _L172;
    if (_btdm_pwr_state == 2) {
      return;
    }
  }
  rw_schedule();
  if ((sdk_cfg_priv_opts_extend != '\0') && (_btdm_pwr_state == 0)) {
    ble_try_turn_on_pll_track();
    return;
  }
  return;
}

