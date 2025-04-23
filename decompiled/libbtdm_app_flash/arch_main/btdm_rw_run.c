/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> arch_main.o -> btdm_rw_run
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
  int iVar3;
  undefined4 extraout_a1;
  
  pcVar2 = param_1;
  if ((_btdm_pwr_state == 4) && (pcVar2 = (char *)r_sdk_config_get_opts(), pcVar2[0xe] == '\x01')) {
    if (*(code **)(_r_osi_funcs_p + 0xa8) != (code *)0x0) {
      (**(code **)(_r_osi_funcs_p + 0xa8))();
    }
    _btdm_pwr_state = 0;
    iVar3 = coex_schm_wakeup_flag_get();
    if (iVar3 != 0) {
      coex_schm_process_in_active();
    }
    pcVar2 = (char *)r_sdk_config_get_opts_ext();
    if (((*(uint *)(pcVar2 + 0x28) & 0x200) != 0) &&
       (pcVar2 = (char *)r_sdk_config_get_opts_ext(), (byte)pcVar2[0x2c] < 3)) {
      pcVar2 = (char *)r_ble_log_internal_x1(0x400c0005,_btdm_pwr_state << 8 | (uint)param_1);
    }
  }
  if (param_1 == (char *)0x2) {
    if (_btdm_pwr_state != 2) {
      rw_schedule();
      pcVar2 = (char *)r_sdk_cfg_priv_opts_ext_get();
      if ((*pcVar2 != '\0') && (_btdm_pwr_state == 0)) {
        pll_track_state = r_rwip_time_get();
        bVar1 = (pll_track_state - DAT_00011f9c & 0xfffffffU) - 0xc81 < 0x7fff380;
        DAT_00011f98 = extraout_a1;
        if (bVar1) {
          DAT_00011f9c = pll_track_state;
          bt_track_pll_cap();
        }
        return (char *)(uint)bVar1;
      }
    }
  }
  else if ((char *)0x1 < param_1) {
    pcVar2 = (char *)r_assert_err(0,"arch_main.c",0x44a);
  }
  return pcVar2;
}

