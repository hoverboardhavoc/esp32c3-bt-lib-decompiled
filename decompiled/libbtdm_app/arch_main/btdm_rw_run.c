/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> arch_main.o -> btdm_rw_run
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char * btdm_rw_run(char *param_1)

{
  char *pcVar1;
  undefined4 extraout_a1;
  uint uVar2;
  
  pcVar1 = param_1;
  if ((_btdm_pwr_state == 4) &&
     (pcVar1 = (char *)(**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
     pcVar1[0xe] == '\x01')) {
    if (*(code **)(_r_osi_funcs_p + 0xa8) != (code *)0x0) {
      pcVar1 = (char *)(**(code **)(_r_osi_funcs_p + 0xa8))();
    }
    _btdm_pwr_state = 0;
    if (param_1 != (char *)0x2) {
_L245:
      if (param_1 < (char *)0x2) {
        return pcVar1;
      }
                    /* WARNING: Could not recover jumptable at 0x00010de0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pcVar1 = (char *)(**(code **)(_r_plf_funcs_p + 8))(0,"arch_main.c",0x3be);
      return pcVar1;
    }
  }
  else {
    if (param_1 != (char *)0x2) goto _L245;
    if (_btdm_pwr_state == 2) {
      return pcVar1;
    }
  }
  rw_schedule();
  pcVar1 = (char *)(**(code **)(_r_plf_funcs_p + 0xf4))(*(code **)(_r_plf_funcs_p + 0xf4));
  if ((*pcVar1 != '\0') && (_btdm_pwr_state == 0)) {
    pll_track_state =
         (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
    uVar2 = pll_track_state - DAT_00011730 & 0xfffffff;
    pcVar1 = (char *)0x0;
    DAT_0001172c = extraout_a1;
    if ((uVar2 < 0x8000001) && (0xc80 < uVar2)) {
      DAT_00011730 = pll_track_state;
      bt_track_pll_cap(0);
      pcVar1 = (char *)0x1;
    }
    return pcVar1;
  }
  return pcVar1;
}

