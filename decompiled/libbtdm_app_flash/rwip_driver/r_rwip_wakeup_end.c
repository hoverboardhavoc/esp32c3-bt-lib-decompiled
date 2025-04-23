/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> rwip_driver.o -> r_rwip_wakeup_end
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_wakeup_end(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (*(code **)(_r_osi_funcs_p + 0xa4) != (code *)0x0) {
    (**(code **)(_r_osi_funcs_p + 0xa4))();
  }
  iVar2 = r_rwip_time_get();
  iVar3 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar3 + 0x28) & 0x200) != 0) {
    iVar3 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar3 + 0x2c) < 3) {
      r_ble_log_internal_x2(0x400c0004,_sdk_cfg_priv_opts,iVar2);
    }
  }
  _DAT_6003100c = _DAT_6003100c & 0xfffffffe;
  r_rwble_sleep_wakeup_end();
  uVar1 = _DAT_6003100c | 0x1188;
  if (_rwip_env != -1) {
    if ((iVar2 - _rwip_env & 0xfffffffU) < 0x7ffffff) {
      _DAT_6003100c = _DAT_6003100c | 0x1188;
      r_rwip_timer_hs_handler();
      uVar1 = _DAT_6003100c;
    }
    else {
      uVar1 = _DAT_6003100c | 0x1588;
    }
  }
  _DAT_6003100c = uVar1;
  if (_sdk_cfg_priv_opts != -1) {
    if ((iVar2 - _sdk_cfg_priv_opts & 0xfffffffU) < 0x7ffffff) {
      r_rwip_timer_hus_handler_hack();
    }
    else {
      _DAT_6003100c = _DAT_6003100c | 0x800;
    }
  }
  if (_r_sch_alarm_timer_isr != -1) {
    if ((iVar2 - _r_sch_alarm_timer_isr & 0xfffffffU) < 0x7ffffff) {
      r_rwip_timer_10ms_handler();
    }
    else {
      _DAT_6003100c = _DAT_6003100c | 0x200;
    }
  }
  iVar2 = r_sdk_config_get_opts();
  if (*(char *)(iVar2 + 0x17) == '\x01') {
    r_vhci_flow_on();
  }
  else {
    iVar2 = r_sdk_config_get_opts();
    if (*(char *)(iVar2 + 0x17) == '\0') {
      r_h4tl_start();
    }
  }
  r_rwip_prevent_sleep_clear(1);
  _btdm_pwr_state = 4;
  r_btdm_task_post_from_isr(3);
  return;
}

