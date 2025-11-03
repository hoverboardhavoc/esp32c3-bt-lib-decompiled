/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
        uVar2 = pll_track_state - DAT_0001266c & 0xfffffff;
        pcVar1 = (char *)0x0;
        DAT_00012668 = extraout_a1;
        if ((uVar2 < 0x8000001) && (0xc80 < uVar2)) {
          DAT_0001266c = pll_track_state;
          bt_track_pll_cap(0);
          pcVar1 = (char *)0x1;
        }
        return pcVar1;
      }
    }
  }
  else if ((char *)0x1 < param_1) {
                    /* WARNING: Could not recover jumptable at 0x00011892. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar1 = (char *)(**(code **)(_r_plf_funcs_p + 8))
                               (0,"arch_main.c",0x563,*(code **)(_r_plf_funcs_p + 8));
    return pcVar1;
  }
  return pcVar1;
}

