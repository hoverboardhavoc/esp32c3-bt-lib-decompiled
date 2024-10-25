/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> rwip_driver.o -> r_rwip_sleep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_rwip_sleep(void)

{
  int iVar1;
  int extraout_a1;
  uint uVar2;
  uint uVar3;
  uint uStack_2c;
  int iStack_28;
  int iStack_24;
  
  if (((_DAT_0001202e & 1) == 0) && (iVar1 = r_ke_sleep_check(), iVar1 == 0)) {
    _btdm_slp_err = 2;
    return 0;
  }
  iVar1 = r_sdk_config_get_opts();
  if ((*(char *)(iVar1 + 0xe) == '\x01') && (iVar1 = r_sdk_config_get_bt_sleep_enable(), iVar1 != 0)
     ) {
    if (_btdm_pwr_state == 0) {
      if (_DAT_0001202e == 0) {
        iStack_28 = r_rwip_time_get();
        uVar3 = iStack_28 + 3;
        if ((uint)_r_sch_arb_sw_isr <= 0x270U - extraout_a1) {
          uVar3 = iStack_28 + 2;
        }
        uStack_2c = _r_ke_event_callback_set;
        uVar3 = uVar3 & 0xfffffff;
        if (_r_sch_alarm_timer_isr != -1) {
          uVar2 = _r_sch_alarm_timer_isr - uVar3 & 0xfffffff;
          if (0x8000000 < uVar2) {
            uVar2 = -(uVar3 - _r_sch_alarm_timer_isr & 0xfffffff);
          }
          uStack_2c = _r_ke_event_callback_set;
          if ((int)uVar2 < (int)_r_ke_event_callback_set) {
            uStack_2c = uVar2;
          }
        }
        if (_rwip_env != -1) {
          uVar2 = _rwip_env - uVar3 & 0xfffffff;
          if (0x8000000 < uVar2) {
            uVar2 = -(uVar3 - _rwip_env & 0xfffffff);
          }
          if ((int)uVar2 < (int)uStack_2c) {
            uStack_2c = uVar2;
          }
        }
        if (_sdk_cfg_priv_opts != -1) {
          uVar2 = _sdk_cfg_priv_opts - uVar3 & 0xfffffff;
          if (0x8000000 < uVar2) {
            uVar2 = -(uVar3 - _sdk_cfg_priv_opts & 0xfffffff);
          }
          if ((int)uVar2 < (int)uStack_2c) {
            uStack_2c = uVar2;
          }
        }
        if ((_r_lld_hw_cca_evt_handler < (int)uStack_2c) &&
           (iStack_24 = extraout_a1,
           iVar1 = (**(code **)(_r_osi_funcs_p + 0x94))
                             (&uStack_2c,*(code **)(_r_osi_funcs_p + 0x94)), iVar1 != 0)) {
          iVar1 = r_rwip_half_slot_2_lpcycles(uStack_2c);
          uVar3 = iVar1 - 1;
          if (_r_ke_event_set + 1U <= uVar3) {
            iVar1 = r_sdk_config_get_opts();
            if (((*(char *)(iVar1 + 0x17) == '\x01') && (iVar1 = r_vhci_flow_off(), iVar1 == 0)) ||
               ((iVar1 = r_sdk_config_get_opts(), *(char *)(iVar1 + 0x17) == '\0' &&
                (iVar1 = r_h4tl_stop(), iVar1 == 0)))) {
              _btdm_slp_err = 5;
              return 0;
            }
            _btdm_pwr_state = 1;
            _btdm_slp_err = 0;
            r_rwble_sleep_enter();
            _DAT_6003100c = 8;
            if (rwip_param == '\0') {
              _DAT_60042000 = _DAT_60042000 | 0x80000000;
            }
            _DAT_60042004 = uVar3;
            r_rwip_prevent_sleep_set(0x10);
            (*_rwip_rf)(_rwip_rf);
            if (*(code **)(_r_osi_funcs_p + 0x98) != (code *)0x0) {
              (**(code **)(_r_osi_funcs_p + 0x98))(uVar3);
              return 2;
            }
            return 2;
          }
        }
        _btdm_slp_err = 6;
      }
      else {
        _btdm_slp_err = 4;
      }
    }
    else {
      _btdm_slp_err = 3;
    }
  }
  else {
    _btdm_slp_err = 1;
  }
  return 0;
}

