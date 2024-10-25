/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> rwip_driver.o -> r_rwip_driver_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_driver_init(uint param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 uStack_28;
  char cStack_27;
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
    if (*(char *)(iVar2 + 0x19) != '\0') {
      r_ke_event_callback_set(0xe,&r_lld_hw_cca_evt_handler);
      r_ke_event_callback_set(0xd,&r_lld_sw_cca_evt_handler);
    }
  }
  else if (param_1 < 3) {
    _rwip_env = 0xffffffff;
    _r_sch_alarm_timer_isr = 0xffffffff;
    _sdk_cfg_priv_opts = 0xffffffff;
    cStack_27 = '\0';
    _DAT_0001202e = 0;
    _DAT_60031000 = _DAT_60031000 | 0x80000000;
    do {
    } while ((int)_DAT_60031000 < 0);
    uStack_28 = 1;
    iVar2 = (*_rwip_param)(0x11,&uStack_28,&cStack_27,_rwip_param);
    if (iVar2 != 0) {
      cStack_27 = '\0';
    }
    iVar2 = r_sdk_config_get_opts();
    cVar1 = *(char *)(iVar2 + 0xe);
    if ((cVar1 == '\x01') && (iVar2 = r_sdk_config_get_bt_sleep_enable(), iVar2 != 0)) {
      _rwip_param = (code *)CONCAT31(rwip_param_1,DAT_00012023);
      uStack_28 = 2;
      cStack_27 = cVar1;
      iVar2 = (*_rwip_param)(0x2e,&uStack_28,&rwip_env,_rwip_param);
      if (iVar2 != 0) {
        _r_sch_arb_sw_isr = 400;
      }
      uStack_28 = 2;
      _r_sch_arb_event_start_isr = 0;
      iVar2 = (*_rwip_param)(0xf,&uStack_28,auStack_22,_rwip_param);
      if (iVar2 != 0) {
        auStack_22[0] = _r_sdk_config_get_bt_sleep_enable;
      }
      uStack_28 = 2;
      iVar2 = (*_rwip_param)(0xe,&uStack_28,&uStack_24,_rwip_param);
      if (iVar2 != 0) {
        uStack_24 = _DAT_0001203a;
      }
      uStack_28 = 2;
      iVar2 = (*_rwip_param)(0xd,&uStack_28,&uStack_26,_rwip_param);
      if (iVar2 != 0) {
        uStack_26 = _r_sdk_config_get_opts_ext;
      }
      auStack_22[0] = r_rwip_hus_2_lpcycles((uint)auStack_22[0] << 1);
      uStack_24 = r_rwip_hus_2_lpcycles((uint)uStack_24 << 1);
      uVar3 = r_rwip_hus_2_lpcycles((uint)uStack_26 << 1);
      uVar4 = (uint)uStack_24;
      uStack_26 = (ushort)uVar3;
      if ((uVar4 << 10 & 0x3e00000) != 0) {
        r_assert_err(0,"rwip_driver.c",0x135);
      }
      if ((uVar3 & 0xfc00) != 0) {
        r_assert_err(0,"rwip_driver.c",0x136);
      }
      _DAT_6004200c = uVar3 << 0x15 | uVar3 & 0xffff | uVar4 << 10;
      _r_ke_event_set = (uint)uStack_26;
      if ((uint)uStack_26 < (uint)auStack_22[0]) {
        _r_ke_event_set = (uint)auStack_22[0];
      }
      if (_r_ke_event_set < uStack_24) {
        _r_ke_event_set = (uint)uStack_24;
      }
      _DAT_60042000 = ((uint)_rwip_param & 0xff ^ 1) << 0x1f | _DAT_60042000 & 0x7fffffff;
    }
    else {
      cStack_27 = '\0';
      r_rwip_prevent_sleep_set(0x100);
    }
    uStack_28 = 1;
    iVar2 = (*_rwip_param)(0x18,&uStack_28,&rwip_prog_delay,_rwip_param);
    if (iVar2 != 0) {
      rwip_prog_delay = sdk_cfg_priv_opts;
    }
  }
  return;
}

