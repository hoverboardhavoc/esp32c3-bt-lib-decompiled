/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> rwip_driver.o -> r_rwip_sleep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010a80) */
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
  
  if (((_btdm_pwr_state & 0x10000) == 0) &&
     (iVar1 = (**(code **)(_r_modules_funcs_p + 0x138))(*(code **)(_r_modules_funcs_p + 0x138)),
     iVar1 == 0)) {
    _btdm_slp_err = 2;
  }
  else {
    iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if ((*(char *)(iVar1 + 0xe) == '\x01') &&
       (iVar1 = (**(code **)(_r_plf_funcs_p + 0x34))(*(code **)(_r_plf_funcs_p + 0x34)), iVar1 != 0)
       ) {
      if (_btdm_pwr_state == 0) {
        iStack_28 = (**(code **)(_r_modules_funcs_p + 0x2c4))
                              (*(code **)(_r_modules_funcs_p + 0x2c4));
        uVar3 = (uint)(0x270U - extraout_a1 < (_btdm_pwr_state & 0xffff)) + iStack_28 + 2 &
                0xfffffff;
        uStack_2c = _rwip_rf;
        if (_rwip_prog_delay != -1) {
          uVar2 = _rwip_prog_delay - uVar3 & 0xfffffff;
          if (0x8000000 < uVar2) {
            uVar2 = -(uVar3 - _rwip_prog_delay & 0xfffffff);
          }
          if ((int)uVar2 < (int)_rwip_rf) {
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
        if ((_DAT_00012030 < (int)uStack_2c) &&
           (iStack_24 = extraout_a1,
           iVar1 = (**(code **)(_r_osi_funcs_p + 0x94))
                             (&uStack_2c,*(code **)(_r_osi_funcs_p + 0x94)), iVar1 != 0)) {
          iVar1 = (**(code **)(_r_modules_funcs_p + 0x2a0))
                            (uStack_2c,*(code **)(_r_modules_funcs_p + 0x2a0));
          uVar3 = iVar1 - 1;
          if (_r_osi_funcs_p + 1U <= uVar3) {
            iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
            if (((*(char *)(iVar1 + 0x17) != '\x01') ||
                (iVar1 = (**(code **)(_r_plf_funcs_p + 0xd4))(*(code **)(_r_plf_funcs_p + 0xd4)),
                iVar1 != 0)) &&
               ((iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
                *(char *)(iVar1 + 0x17) != '\0' ||
                (iVar1 = (**(code **)(_r_modules_funcs_p + 0x90))
                                   (*(code **)(_r_modules_funcs_p + 0x90)), iVar1 != 0)))) {
              _btdm_pwr_state = 1;
              _btdm_slp_err = 0;
              (**(code **)(_r_ip_funcs_p + 0x130))(*(code **)(_r_ip_funcs_p + 0x130));
              _DAT_6003100c = 8;
              if (btdm_slp_err == '\0') {
                _DAT_60042000 = _DAT_60042000 | 0x80000000;
              }
              _DAT_60042004 = uVar3;
              (**(code **)(_r_modules_funcs_p + 0x2b4))(0x10,*(code **)(_r_modules_funcs_p + 0x2b4))
              ;
              (*_DAT_00012058)(_DAT_00012058);
              if (*(code **)(_r_osi_funcs_p + 0x98) != (code *)0x0) {
                (**(code **)(_r_osi_funcs_p + 0x98))(uVar3);
              }
              return 2;
            }
            _btdm_slp_err = 5;
            return 0;
          }
        }
        _btdm_slp_err = 6;
      }
      else {
        _btdm_slp_err = 3;
      }
    }
    else {
      _btdm_slp_err = 1;
    }
  }
  return 0;
}

