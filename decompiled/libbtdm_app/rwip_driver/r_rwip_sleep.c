/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> rwip_driver.o -> r_rwip_sleep
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
  
  if (((_r_ip_funcs_p & 0x10000) == 0) &&
     (iVar1 = (**(code **)(_r_modules_funcs_p + 0x138))(*(code **)(_r_modules_funcs_p + 0x138)),
     iVar1 == 0)) {
    _btdm_slp_err = 2;
    return 0;
  }
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if ((*(char *)(iVar1 + 0xe) == '\x01') &&
     (iVar1 = (**(code **)(_r_plf_funcs_p + 0x34))(*(code **)(_r_plf_funcs_p + 0x34)), iVar1 != 0))
  {
    if (_btdm_pwr_state == 0) {
      if (_DAT_00012016 == 0) {
        iStack_28 = (**(code **)(_r_modules_funcs_p + 0x2c4))
                              (*(code **)(_r_modules_funcs_p + 0x2c4));
        uVar3 = iStack_28 + 3;
        if ((_r_ip_funcs_p & 0xffff) <= 0x270U - extraout_a1) {
          uVar3 = iStack_28 + 2;
        }
        uStack_2c = _DAT_00012034;
        uVar3 = uVar3 & 0xfffffff;
        if (_r_plf_funcs_p != -1) {
          uVar2 = _r_plf_funcs_p - uVar3 & 0xfffffff;
          if (0x8000000 < uVar2) {
            uVar2 = -(uVar3 - _r_plf_funcs_p & 0xfffffff);
          }
          uStack_2c = _DAT_00012034;
          if ((int)uVar2 < (int)_DAT_00012034) {
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
        if (_rwip_param != -1) {
          uVar2 = _rwip_param - uVar3 & 0xfffffff;
          if (0x8000000 < uVar2) {
            uVar2 = -(uVar3 - _rwip_param & 0xfffffff);
          }
          if ((int)uVar2 < (int)uStack_2c) {
            uStack_2c = uVar2;
          }
        }
        if ((_DAT_00012038 < (int)uStack_2c) &&
           (iStack_24 = extraout_a1,
           iVar1 = (**(code **)(_r_osi_funcs_p + 0x94))
                             (&uStack_2c,*(code **)(_r_osi_funcs_p + 0x94)), iVar1 != 0)) {
          iVar1 = (**(code **)(_r_modules_funcs_p + 0x2a0))
                            (uStack_2c,*(code **)(_r_modules_funcs_p + 0x2a0));
          uVar3 = iVar1 - 1;
          if (_sdk_cfg_priv_opts + 1U <= uVar3) {
            iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
            if (((*(char *)(iVar1 + 0x17) == '\x01') &&
                (iVar1 = (**(code **)(_r_plf_funcs_p + 0xd4))(*(code **)(_r_plf_funcs_p + 0xd4)),
                iVar1 == 0)) ||
               ((iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
                *(char *)(iVar1 + 0x17) == '\0' &&
                (iVar1 = (**(code **)(_r_modules_funcs_p + 0x90))
                                   (*(code **)(_r_modules_funcs_p + 0x90)), iVar1 == 0)))) {
              _btdm_slp_err = 5;
              return 0;
            }
            _btdm_pwr_state = 1;
            _btdm_slp_err = 0;
            (**(code **)(_r_ip_funcs_p + 0x130))(*(code **)(_r_ip_funcs_p + 0x130));
            _DAT_6003100c = 8;
            if (rwip_prog_delay == '\0') {
              _DAT_60042000 = _DAT_60042000 | 0x80000000;
            }
            _DAT_60042004 = uVar3;
            (**(code **)(_r_modules_funcs_p + 0x2b4))(0x10,*(code **)(_r_modules_funcs_p + 0x2b4));
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

