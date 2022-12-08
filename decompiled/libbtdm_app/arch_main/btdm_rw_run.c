/*
 * Last changed at upstream commit 723f44c70ceea734bb9075b3c59993103d1dac23
 * https://github.com/espressif/esp32c3-bt-lib/commit/723f44c70ceea734bb9075b3c59993103d1dac23
 * Upstream date: 2022-12-08 17:22:39 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(2b9445a6) - Fixed some memory was not released after bluetooth controller init failed
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
_L124:
      if (param_1 < 2) {
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x00011458. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 8))(0,"arch_main.c",0x37b);
      return;
    }
  }
  else {
    if (param_1 != 2) goto _L124;
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

