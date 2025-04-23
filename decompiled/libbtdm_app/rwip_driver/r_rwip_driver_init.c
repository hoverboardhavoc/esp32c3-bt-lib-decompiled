/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> rwip_driver.o -> r_rwip_driver_init
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
  ushort auStack_22 [5];
  
  if (param_1 == 0) {
    iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    if (*(char *)(iVar1 + 0x20) != '\0') {
      (**(code **)(_r_modules_funcs_p + 0x100))
                (2,*(undefined4 *)(_r_modules_funcs_p + 0x294),
                 *(code **)(_r_modules_funcs_p + 0x100));
    }
    if (sdk_cfg_priv_opts != '\0') {
      _DAT_6003138c = 0x1000;
    }
    _DAT_6003100c = _DAT_6003100c | 0x1180;
    (**(code **)(_r_modules_funcs_p + 0x2b4))(0x100,*(code **)(_r_modules_funcs_p + 0x2b4));
    iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    if (*(char *)(iVar1 + 0x19) == '\0') {
      return;
    }
    (**(code **)(_r_modules_funcs_p + 0x100))
              (0xe,*(undefined4 *)(_r_ip_funcs_p + 0x24c),*(code **)(_r_modules_funcs_p + 0x100));
                    /* WARNING: Could not recover jumptable at 0x000100ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0x100))
              (0xd,*(undefined4 *)(_r_ip_funcs_p + 0x2ac),*(code **)(_r_modules_funcs_p + 0x100));
    return;
  }
  if (1 < (param_1 - 1U & 0xff)) {
    return;
  }
  _rwip_env = 0xffffffff;
  uStack_27 = 0;
  _rwip_prog_delay = 0xffffffff;
  _rwip_param = (code *)0xffffffff;
  _DAT_00012026 = 0;
  _DAT_60031000 = _DAT_60031000 | 0x80000000;
  do {
  } while ((int)_DAT_60031000 < 0);
  uStack_28 = 1;
  iVar1 = (*(code *)0xffffffff)(0x11,&uStack_28,&uStack_27,0xffffffff);
  if (iVar1 != 0) {
    uStack_27 = 0;
  }
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (*(char *)(iVar1 + 0xe) == '\x01') {
    iVar1 = (**(code **)(_r_plf_funcs_p + 0x34))(*(code **)(_r_plf_funcs_p + 0x34));
    uStack_27 = (undefined1)iVar1;
    if (iVar1 != 0) {
      _btdm_slp_err = CONCAT11(btdm_slp_err_1,DAT_0001200f);
      uStack_28 = 2;
      iVar1 = (*_rwip_param)(0x2e,&uStack_28,&rwip_env,_rwip_param);
      if (iVar1 != 0) {
        _btdm_pwr_state = 400;
      }
      uStack_28 = 2;
      _memcpy = 0;
      iVar1 = (*_rwip_param)(0xf,&uStack_28,auStack_22,_rwip_param);
      if (iVar1 != 0) {
        auStack_22[0] = _btdm_pwr_state;
      }
      uStack_28 = 2;
      iVar1 = (*_rwip_param)(0xe,&uStack_28,&uStack_24,_rwip_param);
      if (iVar1 != 0) {
        uStack_24 = _DAT_00012026;
      }
      uStack_28 = 2;
      iVar1 = (*_rwip_param)(0xd,&uStack_28,&uStack_26,_rwip_param);
      if (iVar1 != 0) {
        uStack_26 = _btdm_slp_err;
      }
      auStack_22[0] =
           (**(code **)(_r_modules_funcs_p + 0x2a4))
                     ((uint)auStack_22[0] << 1,*(code **)(_r_modules_funcs_p + 0x2a4));
      uStack_24 = (**(code **)(_r_modules_funcs_p + 0x2a4))
                            ((uint)uStack_24 << 1,*(code **)(_r_modules_funcs_p + 0x2a4));
      uStack_26 = (**(code **)(_r_modules_funcs_p + 0x2a4))
                            ((uint)uStack_26 << 1,*(code **)(_r_modules_funcs_p + 0x2a4));
      uVar2 = (uint)uStack_24;
      uVar3 = (uint)uStack_26;
      if (uStack_24 >> 0xb != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x135,*(code **)(_r_plf_funcs_p + 8));
      }
      if (0x3ff < uVar3) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x136,*(code **)(_r_plf_funcs_p + 8));
      }
      _DAT_6004200c = uVar2 << 10 | uVar3 | uVar3 << 0x15;
      _r_osi_funcs_p = (uint)uStack_26;
      if ((uint)uStack_26 < (uint)auStack_22[0]) {
        _r_osi_funcs_p = (uint)auStack_22[0];
      }
      if (_r_osi_funcs_p < uStack_24) {
        _r_osi_funcs_p = (uint)uStack_24;
      }
      _DAT_60042000 = (btdm_slp_err ^ 1) << 0x1f | _DAT_60042000 & 0x7fffffff;
      goto _L19;
    }
  }
  else {
    uStack_27 = 0;
  }
  (**(code **)(_r_modules_funcs_p + 0x2b4))(0x100,*(code **)(_r_modules_funcs_p + 0x2b4));
_L19:
  uStack_28 = 1;
  iVar1 = (*_rwip_param)(0x18,&uStack_28,&rwip_prog_delay,_rwip_param);
  if (iVar1 != 0) {
    _rwip_prog_delay = CONCAT31(rwip_prog_delay_1,sdk_cfg_priv_opts);
  }
  return;
}

