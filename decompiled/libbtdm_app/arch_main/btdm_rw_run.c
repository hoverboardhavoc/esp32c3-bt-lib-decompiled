/*
 * Last changed at upstream commit ebd6043a8e3c3bbde45ee483895303b9c1229ab5
 * https://github.com/espressif/esp32c3-bt-lib/commit/ebd6043a8e3c3bbde45ee483895303b9c1229ab5
 * Upstream date: 2026-02-06 15:59:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b7de11e)
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
      (**(code **)(_r_osi_funcs_p + 0xa8))();
    }
    _btdm_pwr_state = 0;
    pcVar1 = (char *)coex_schm_wakeup_flag_get();
    if (pcVar1 != (char *)0x0) {
      pcVar1 = (char *)coex_schm_process_in_active();
    }
  }
  if (param_1 == (char *)0x2) {
    if (_btdm_pwr_state != 2) {
      rw_schedule();
      pcVar1 = (char *)(**(code **)(_r_plf_funcs_p + 0xf4))(*(code **)(_r_plf_funcs_p + 0xf4));
      if ((*pcVar1 != '\0') && (_btdm_pwr_state == 0)) {
        pll_track_state =
             (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
        uVar2 = pll_track_state - DAT_0001269c & 0xfffffff;
        pcVar1 = (char *)0x0;
        DAT_00012698 = extraout_a1;
        if ((uVar2 < 0x8000001) && (0xc80 < uVar2)) {
          DAT_0001269c = pll_track_state;
          bt_track_pll_cap(0);
          pcVar1 = (char *)0x1;
        }
        return pcVar1;
      }
    }
  }
  else if ((char *)0x1 < param_1) {
                    /* WARNING: Could not recover jumptable at 0x000118c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar1 = (char *)(**(code **)(_r_plf_funcs_p + 8))
                               (0,"arch_main.c",0x566,*(code **)(_r_plf_funcs_p + 8));
    return pcVar1;
  }
  return pcVar1;
}

