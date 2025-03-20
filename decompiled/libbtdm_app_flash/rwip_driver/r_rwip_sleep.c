/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
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
  int iVar3;
  uint uVar4;
  uint uStack_2c;
  int iStack_28;
  int iStack_24;
  
  if ((_DAT_0001202e & 1) == 0) {
    iVar1 = r_ke_sleep_check();
    iVar3 = 2;
    if (iVar1 == 0) goto _L149;
  }
  iVar3 = r_sdk_config_get_opts();
  if ((*(char *)(iVar3 + 0xe) == '\x01') && (iVar3 = r_sdk_config_get_bt_sleep_enable(), iVar3 != 0)
     ) {
    if (_btdm_pwr_state == 0) {
      if (_DAT_0001202e == 0) {
        iStack_28 = r_rwip_time_get();
        uVar4 = iStack_28 + 3;
        if ((uint)_r_sch_arb_sw_isr <= 0x270U - extraout_a1) {
          uVar4 = iStack_28 + 2;
        }
        uStack_2c = _r_ke_event_callback_set;
        uVar4 = uVar4 & 0xfffffff;
        if (_r_sch_alarm_timer_isr != -1) {
          uVar2 = _r_sch_alarm_timer_isr - uVar4 & 0xfffffff;
          if (0x8000000 < uVar2) {
            uVar2 = -(uVar4 - _r_sch_alarm_timer_isr & 0xfffffff);
          }
          uStack_2c = _r_ke_event_callback_set;
          if ((int)uVar2 < (int)_r_ke_event_callback_set) {
            uStack_2c = uVar2;
          }
        }
        if (_rwip_env != -1) {
          uVar2 = _rwip_env - uVar4 & 0xfffffff;
          if (0x8000000 < uVar2) {
            uVar2 = -(uVar4 - _rwip_env & 0xfffffff);
          }
          if ((int)uVar2 < (int)uStack_2c) {
            uStack_2c = uVar2;
          }
        }
        if (_sdk_cfg_priv_opts != -1) {
          uVar2 = _sdk_cfg_priv_opts - uVar4 & 0xfffffff;
          if (0x8000000 < uVar2) {
            uVar2 = -(uVar4 - _sdk_cfg_priv_opts & 0xfffffff);
          }
          if ((int)uVar2 < (int)uStack_2c) {
            uStack_2c = uVar2;
          }
        }
        iStack_24 = extraout_a1;
        if ((_r_lld_hw_cca_evt_handler < (int)uStack_2c) &&
           (iVar3 = (**(code **)(_r_osi_funcs_p + 0x94))
                              (&uStack_2c,*(code **)(_r_osi_funcs_p + 0x94)), iVar3 != 0)) {
          iVar3 = r_rwip_half_slot_2_lpcycles(uStack_2c);
          uVar4 = iVar3 - 1;
          if (_r_ke_event_set + 1U <= uVar4) {
            iVar3 = r_sdk_config_get_opts();
            if (((*(char *)(iVar3 + 0x17) != '\x01') || (iVar3 = r_vhci_flow_off(), iVar3 != 0)) &&
               ((iVar3 = r_sdk_config_get_opts(), *(char *)(iVar3 + 0x17) != '\0' ||
                (iVar3 = r_h4tl_stop(), iVar3 != 0)))) {
              _btdm_pwr_state = 1;
              _btdm_slp_err = 0;
              r_rwble_sleep_enter();
              _DAT_6003100c = 8;
              if (rwip_param == '\0') {
                _DAT_60042000 = _DAT_60042000 | 0x80000000;
              }
              _DAT_60042004 = uVar4;
              r_rwip_prevent_sleep_set(0x10);
              iVar3 = r_sdk_config_get_opts_ext();
              if (((*(uint *)(iVar3 + 0x28) & 0x200) != 0) &&
                 (iVar3 = r_sdk_config_get_opts_ext(), *(byte *)(iVar3 + 0x2c) < 3)) {
                r_ble_log_internal_x2(0x400c0000,_btdm_pwr_state,uStack_2c);
              }
              (*_rwip_rf)(_rwip_rf);
              if (*(code **)(_r_osi_funcs_p + 0x98) == (code *)0x0) {
                return 2;
              }
              (**(code **)(_r_osi_funcs_p + 0x98))(uVar4);
              return 2;
            }
            iVar3 = 5;
            goto _L149;
          }
        }
        iVar3 = 6;
      }
      else {
        iVar3 = 4;
      }
    }
    else {
      iVar3 = 3;
    }
  }
  else {
    iVar3 = 1;
  }
_L149:
  _btdm_slp_err = iVar3;
  iVar3 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar3 + 0x28) & 0x200) != 0) &&
     (iVar3 = r_sdk_config_get_opts_ext(), *(byte *)(iVar3 + 0x2c) < 2)) {
    r_ble_log_internal_x2
              (0x200c0001,(uint)_DAT_0001202e << 0x18 | _btdm_pwr_state << 0x10 | _btdm_slp_err << 8
               ,uStack_2c);
  }
  return 0;
}

