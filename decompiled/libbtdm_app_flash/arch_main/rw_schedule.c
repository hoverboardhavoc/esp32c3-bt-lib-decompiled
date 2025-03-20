/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> arch_main.o -> rw_schedule
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rw_schedule(void)

{
  int iVar1;
  
  r_rwip_schedule();
  iVar1 = (**(code **)(_r_osi_funcs_p + 0x34))
                    (_g_waking_sleeping_sem,0,*(code **)(_r_osi_funcs_p + 0x34));
  if (iVar1 != 0) {
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    r_rwip_sleep();
    (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
    (**(code **)(_r_osi_funcs_p + 0x38))(_g_waking_sleeping_sem,*(code **)(_r_osi_funcs_p + 0x38));
  }
  if (_btdm_pwr_state == 1) {
    do {
    } while (-1 < _DAT_60042000 << 0x10);
    if (*(code **)(_r_osi_funcs_p + 0x9c) != (code *)0x0) {
      (**(code **)(_r_osi_funcs_p + 0x9c))();
    }
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    if (_btdm_pwr_state == 1) {
      _btdm_pwr_state = 2;
    }
    (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
    iVar1 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar1 + 0x28) & 0x200) != 0) &&
       (iVar1 = r_sdk_config_get_opts_ext(), *(byte *)(iVar1 + 0x2c) < 3)) {
      r_ble_log_internal_x2(0x400c0002,_btdm_pwr_state,_DAT_60042000);
      return;
    }
  }
  return;
}

