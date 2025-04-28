/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined1 uStack_28;
  undefined1 uStack_27;
  ushort uStack_26;
  ushort uStack_24;
  ushort auStack_22 [5];
  
  if (param_1 == 0) {
    iVar2 = r_sdk_config_get_opts_ext();
    if (*(char *)(iVar2 + 0x20) != '\0') {
      r_ke_event_callback_set(2,0x10000);
    }
    if (sdk_cfg_priv_opts != '\0') {
      _DAT_6003138c = 0x1000;
    }
    _DAT_6003100c = _DAT_6003100c | 0x1180;
    r_rwip_prevent_sleep_set(0x100);
    iVar2 = r_sdk_config_get_opts_ext();
    if (*(char *)(iVar2 + 0x19) == '\0') {
      return;
    }
    r_ke_event_callback_set(0xe,&r_lld_hw_cca_evt_handler);
    r_ke_event_callback_set(0xd,&r_lld_sw_cca_evt_handler);
    return;
  }
  if (1 < (param_1 - 1U & 0xff)) {
    return;
  }
  _r_sch_alarm_timer_isr = 0xffffffff;
  _rwip_env = 0xffffffff;
  _sdk_cfg_priv_opts = 0xffffffff;
  uStack_27 = 0;
  _DAT_0001202e = 0;
  _DAT_60031000 = _DAT_60031000 | 0x80000000;
  do {
  } while ((int)_DAT_60031000 < 0);
  uStack_28 = 1;
  iVar2 = (*_rwip_param)(0x11,&uStack_28,&uStack_27,_rwip_param);
  if (iVar2 != 0) {
    uStack_27 = 0;
  }
  iVar2 = r_sdk_config_get_opts();
  if (*(char *)(iVar2 + 0xe) == '\x01') {
    iVar2 = r_sdk_config_get_bt_sleep_enable();
    uStack_27 = (undefined1)iVar2;
    if (iVar2 != 0) {
      r_sdk_config_get_opts_ext = DAT_00012023;
      uStack_28 = 2;
      iVar2 = (*_rwip_param)(0x2e,&uStack_28,&rwip_env,_rwip_param);
      if (iVar2 != 0) {
        _r_sch_arb_sw_isr = 400;
      }
      uStack_28 = 2;
      _r_sch_arb_event_start_isr = 0;
      iVar2 = (*_rwip_param)(0xf,&uStack_28,auStack_22,_rwip_param);
      if (iVar2 != 0) {
        auStack_22[0] = _r_lld_hw_cca_evt_handler;
      }
      uStack_28 = 2;
      iVar2 = (*_rwip_param)(0xe,&uStack_28,&uStack_24,_rwip_param);
      if (iVar2 != 0) {
        uStack_24 = _DAT_0001203a;
      }
      uStack_28 = 2;
      iVar2 = (*_rwip_param)(0xd,&uStack_28,&uStack_26,_rwip_param);
      if (iVar2 != 0) {
        uStack_26 = _r_lld_sw_cca_evt_handler;
      }
      auStack_22[0] = r_rwip_hus_2_lpcycles((uint)auStack_22[0] << 1);
      uStack_24 = r_rwip_hus_2_lpcycles((uint)uStack_24 << 1);
      uVar1 = r_rwip_hus_2_lpcycles((uint)uStack_26 << 1);
      uVar3 = (uint)uStack_24;
      uStack_26 = uVar1;
      if ((uVar3 << 10 & 0x3e00000) != 0) {
        r_assert_err(0,"rwip_driver.c",0x135);
      }
      if ((uVar1 & 0xfc00) != 0) {
        r_assert_err(0,"rwip_driver.c",0x136);
      }
      _DAT_6004200c = uVar3 << 10 | (uint)uVar1 | (uint)uVar1 << 0x15;
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
  iVar2 = (*_rwip_param)(0x18,&uStack_28,&rwip_prog_delay,_rwip_param);
  if (iVar2 != 0) {
    rwip_prog_delay = sdk_cfg_priv_opts;
  }
  return;
}

