/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
    iVar1 = 2;
  }
  else {
    iVar1 = r_sdk_config_get_opts();
    if ((*(char *)(iVar1 + 0xe) == '\x01') &&
       (iVar1 = r_sdk_config_get_bt_sleep_enable(), iVar1 != 0)) {
      if (_btdm_pwr_state == 0) {
        iVar1 = 4;
        if (_DAT_0001202e == 0) {
          iStack_28 = r_rwip_time_get();
          uVar3 = iStack_28 + 3;
          if ((uint)_r_sch_arb_sw_isr <= 0x270U - extraout_a1) {
            uVar3 = iStack_28 + 2;
          }
          uStack_2c = _rwip_param;
          uVar3 = uVar3 & 0xfffffff;
          if (_r_sch_alarm_timer_isr != -1) {
            uVar2 = _r_sch_alarm_timer_isr - uVar3 & 0xfffffff;
            if (0x8000000 < uVar2) {
              uVar2 = -(uVar3 - _r_sch_alarm_timer_isr & 0xfffffff);
            }
            uStack_2c = _rwip_param;
            if ((int)uVar2 < (int)_rwip_param) {
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
          iStack_24 = extraout_a1;
          if ((_r_sdk_config_get_opts < (int)uStack_2c) &&
             (iVar1 = (**(code **)(_r_osi_funcs_p + 0x94))
                                (&uStack_2c,*(code **)(_r_osi_funcs_p + 0x94)), iVar1 != 0)) {
            iVar1 = r_rwip_half_slot_2_lpcycles(uStack_2c);
            uVar3 = iVar1 - 1;
            if (_r_ke_event_set + 1U <= uVar3) {
              iVar1 = r_sdk_config_get_opts();
              if (((*(char *)(iVar1 + 0x17) != '\x01') || (iVar1 = r_vhci_flow_off(), iVar1 != 0))
                 && ((iVar1 = r_sdk_config_get_opts(), *(char *)(iVar1 + 0x17) != '\0' ||
                     (iVar1 = r_h4tl_stop(), iVar1 != 0)))) {
                _btdm_pwr_state = 1;
                _btdm_slp_err = 0;
                r_rwble_sleep_enter();
                _DAT_6003100c = 8;
                if (r_sdk_config_get_opts_ext == (code)0x0) {
                  _DAT_60042000 = _DAT_60042000 | 0x80000000;
                }
                _DAT_60042004 = uVar3;
                r_rwip_prevent_sleep_set(0x10);
                iVar1 = r_sdk_config_get_opts_ext();
                if (((*(uint *)(iVar1 + 0x28) & 0x200) != 0) &&
                   (iVar1 = r_sdk_config_get_opts_ext(), *(byte *)(iVar1 + 0x2c) < 3)) {
                  r_ble_log_internal_x2(0x400c0000,_btdm_pwr_state,uStack_2c);
                }
                (*_DAT_00012090)(_DAT_00012090);
                if (*(code **)(_r_osi_funcs_p + 0x98) == (code *)0x0) {
                  return 2;
                }
                (**(code **)(_r_osi_funcs_p + 0x98))(uVar3);
                return 2;
              }
              iVar1 = 5;
              goto _L108;
            }
          }
          iVar1 = 6;
        }
      }
      else {
        iVar1 = 3;
      }
    }
    else {
      iVar1 = 1;
    }
  }
_L108:
  _btdm_slp_err = iVar1;
  iVar1 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar1 + 0x28) & 0x200) != 0) &&
     (iVar1 = r_sdk_config_get_opts_ext(), *(byte *)(iVar1 + 0x2c) < 2)) {
    r_ble_log_internal_x2
              (0x200c0001,(uint)_DAT_0001202e << 0x18 | _btdm_pwr_state << 0x10 | _btdm_slp_err << 8
               ,uStack_2c);
  }
  return 0;
}

