/*
 * Last changed at upstream commit 3ff529142f6e2707d57b10eb87ac8d86e9098b88
 * https://github.com/espressif/esp32c3-bt-lib/commit/3ff529142f6e2707d57b10eb87ac8d86e9098b88
 * Upstream date: 2025-06-05 11:04:06 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(4713a69)
 * Source: libbtdm_app_flash -> arch_main.o -> btdm_rw_run
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char * btdm_rw_run(char *param_1)

{
  char *pcVar1;
  int iVar2;
  undefined4 extraout_a1;
  uint uVar3;
  
  pcVar1 = param_1;
  if ((_btdm_pwr_state == 4) && (pcVar1 = (char *)r_sdk_config_get_opts(), pcVar1[0xe] == '\x01')) {
    if (*(code **)(_r_osi_funcs_p + 0xa8) != (code *)0x0) {
      (**(code **)(_r_osi_funcs_p + 0xa8))();
    }
    _btdm_pwr_state = 0;
    iVar2 = coex_schm_wakeup_flag_get();
    if (iVar2 != 0) {
      coex_schm_process_in_active();
    }
    pcVar1 = (char *)r_sdk_config_get_opts_ext();
    if (((*(uint *)(pcVar1 + 0x28) & 0x200) != 0) &&
       (pcVar1 = (char *)r_sdk_config_get_opts_ext(), (byte)pcVar1[0x2c] < 3)) {
      pcVar1 = (char *)r_ble_log_internal_x1(0x400c0005,_btdm_pwr_state << 8 | (uint)param_1);
    }
  }
  if (param_1 == (char *)0x2) {
    if (_btdm_pwr_state != 2) {
      rw_schedule();
      pcVar1 = (char *)r_sdk_cfg_priv_opts_ext_get();
      if ((*pcVar1 != '\0') && (_btdm_pwr_state == 0)) {
        pll_track_state = r_rwip_time_get();
        uVar3 = pll_track_state - DAT_0001200c & 0xfffffff;
        pcVar1 = (char *)0x0;
        DAT_00012008 = extraout_a1;
        if ((uVar3 < 0x8000001) && (0xc80 < uVar3)) {
          DAT_0001200c = pll_track_state;
          bt_track_pll_cap(0);
          pcVar1 = (char *)0x1;
        }
        return pcVar1;
      }
    }
  }
  else if ((char *)0x1 < param_1) {
    pcVar1 = (char *)r_assert_err(0,"arch_main.c",0x55d);
  }
  return pcVar1;
}

