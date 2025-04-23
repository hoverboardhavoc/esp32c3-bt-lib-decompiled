/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> arch_main.o -> btdm_rw_run
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char * btdm_rw_run(char *param_1)

{
  bool bVar1;
  char *pcVar2;
  undefined4 extraout_a1;
  
  pcVar2 = param_1;
  if ((_btdm_pwr_state == 4) &&
     (pcVar2 = (char *)(**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
     pcVar2[0xe] == '\x01')) {
    if (*(code **)(_r_osi_funcs_p + 0xa8) != (code *)0x0) {
      (**(code **)(_r_osi_funcs_p + 0xa8))();
    }
    _btdm_pwr_state = 0;
    pcVar2 = (char *)coex_schm_wakeup_flag_get();
    if (pcVar2 != (char *)0x0) {
      pcVar2 = (char *)coex_schm_process_in_active();
    }
  }
  if (param_1 == (char *)0x2) {
    if (_btdm_pwr_state != 2) {
      rw_schedule();
      pcVar2 = (char *)(**(code **)(_r_plf_funcs_p + 0xf4))(*(code **)(_r_plf_funcs_p + 0xf4));
      if ((*pcVar2 != '\0') && (_btdm_pwr_state == 0)) {
        pll_track_state =
             (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
        bVar1 = (pll_track_state - DAT_00012154 & 0xfffffffU) - 0xc81 < 0x7fff380;
        DAT_00012150 = extraout_a1;
        if (bVar1) {
          DAT_00012154 = pll_track_state;
          bt_track_pll_cap();
        }
        return (char *)(uint)bVar1;
      }
    }
  }
  else if ((char *)0x1 < param_1) {
                    /* WARNING: Could not recover jumptable at 0x000113a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar2 = (char *)(**(code **)(_r_plf_funcs_p + 8))
                               (0,"arch_main.c",0x44a,*(code **)(_r_plf_funcs_p + 8));
    return pcVar2;
  }
  return pcVar2;
}

