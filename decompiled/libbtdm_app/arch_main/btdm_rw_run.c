/*
 * Last changed at upstream commit 976ca00e43905df9e910b400a9e17c311b085ce2
 * https://github.com/espressif/esp32c3-bt-lib/commit/976ca00e43905df9e910b400a9e17c311b085ce2
 * Upstream date: 2022-11-03 19:06:39 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ef8a115a) - Added config to disable scan backoff - Fixed llm_scan.c assert at line 1485 during controller deinit if duplicate scan is not stopped - Call pll track in controller task
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
_L150:
      if (param_1 < 2) {
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x000114bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 8))(0,"arch_main.c",0x37a);
      return;
    }
  }
  else {
    if (param_1 != 2) goto _L150;
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

