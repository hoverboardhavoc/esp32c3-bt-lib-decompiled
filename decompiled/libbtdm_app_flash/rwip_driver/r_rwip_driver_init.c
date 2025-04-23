/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> rwip_driver.o -> r_rwip_driver_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_driver_init(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined1 uStack_28;
  undefined1 uStack_27;
  ushort uStack_26;
  ushort uStack_24;
  ushort auStack_22 [7];
  
  if (param_1 == 0) {
    iVar1 = r_sdk_config_get_opts_ext();
    if (*(char *)(iVar1 + 0x20) != '\0') {
      r_ke_event_callback_set(2,0x10000);
    }
    if (sdk_cfg_priv_opts != '\0') {
      _DAT_6003138c = 0x1000;
    }
    _DAT_6003100c = _DAT_6003100c | 0x1180;
    r_rwip_prevent_sleep_set(0x100);
    iVar1 = r_sdk_config_get_opts_ext();
    if (*(char *)(iVar1 + 0x19) == '\0') {
      return;
    }
    r_ke_event_callback_set(0xe,&r_lld_hw_cca_evt_handler);
    r_ke_event_callback_set(0xd,&r_lld_sw_cca_evt_handler);
    return;
  }
  if (1 < (param_1 - 1U & 0xff)) {
    return;
  }
  _rwip_env = 0xffffffff;
  uStack_27 = 0;
  _r_sch_alarm_timer_isr = 0xffffffff;
  _sdk_cfg_priv_opts = 0xffffffff;
  _DAT_0001202e = 0;
  _DAT_60031000 = _DAT_60031000 | 0x80000000;
  do {
  } while ((int)_DAT_60031000 < 0);
  uStack_28 = 1;
  iVar1 = (*_rwip_param)(0x11,&uStack_28,&uStack_27,_rwip_param);
  if (iVar1 != 0) {
    uStack_27 = 0;
  }
  iVar1 = r_sdk_config_get_opts();
  if (*(char *)(iVar1 + 0xe) == '\x01') {
    iVar1 = r_sdk_config_get_bt_sleep_enable();
    uStack_27 = (undefined1)iVar1;
    if (iVar1 != 0) {
      r_sdk_config_get_opts_ext = DAT_00012023;
      uStack_28 = 2;
      iVar1 = (*_rwip_param)(0x2e,&uStack_28,&rwip_env,_rwip_param);
      if (iVar1 != 0) {
        _r_sch_arb_sw_isr = 400;
      }
      uStack_28 = 2;
      _r_sch_arb_event_start_isr = 0;
      iVar1 = (*_rwip_param)(0xf,&uStack_28,auStack_22,_rwip_param);
      if (iVar1 != 0) {
        auStack_22[0] = _r_lld_hw_cca_evt_handler;
      }
      uStack_28 = 2;
      iVar1 = (*_rwip_param)(0xe,&uStack_28,&uStack_24,_rwip_param);
      if (iVar1 != 0) {
        uStack_24 = _DAT_0001203a;
      }
      uStack_28 = 2;
      iVar1 = (*_rwip_param)(0xd,&uStack_28,&uStack_26,_rwip_param);
      if (iVar1 != 0) {
        uStack_26 = _r_lld_sw_cca_evt_handler;
      }
      auStack_22[0] = r_rwip_hus_2_lpcycles((uint)auStack_22[0] << 1);
      uStack_24 = r_rwip_hus_2_lpcycles((uint)uStack_24 << 1);
      uStack_26 = r_rwip_hus_2_lpcycles((uint)uStack_26 << 1);
      uVar2 = (uint)uStack_24;
      uVar3 = (uint)uStack_26;
      if (uStack_24 >> 0xb != 0) {
        r_assert_err(0,"rwip_driver.c",0x135);
      }
      if (0x3ff < uVar3) {
        r_assert_err(0,"rwip_driver.c",0x136);
      }
      _DAT_6004200c = uVar2 << 10 | uVar3 | uVar3 << 0x15;
      _r_ke_event_set = (uint)uStack_26;
      if ((uint)uStack_26 < (uint)auStack_22[0]) {
        _r_ke_event_set = (uint)auStack_22[0];
      }
      if (_r_ke_event_set < uStack_24) {
        _r_ke_event_set = (uint)uStack_24;
      }
      _DAT_60042000 = ((byte)r_sdk_config_get_opts_ext ^ 1) << 0x1f | _DAT_60042000 & 0x7fffffff;
      goto _L65;
    }
  }
  else {
    uStack_27 = 0;
  }
  r_rwip_prevent_sleep_set(0x100);
_L65:
  uStack_28 = 1;
  iVar1 = (*_rwip_param)(0x18,&uStack_28,&rwip_prog_delay,_rwip_param);
  if (iVar1 != 0) {
    rwip_prog_delay = sdk_cfg_priv_opts;
  }
  return;
}

