/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> rwip_driver.o -> r_rwip_driver_init
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
  ushort auStack_22 [3];
  
  if (param_1 == 0) {
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    if (*(char *)(iVar2 + 0x20) != '\0') {
      (**(code **)(_r_modules_funcs_p + 0x100))
                (2,*(undefined4 *)(_r_modules_funcs_p + 0x294),
                 *(code **)(_r_modules_funcs_p + 0x100));
    }
    if (sdk_cfg_priv_opts != '\0') {
      _DAT_6003138c = 0x1000;
    }
    _DAT_6003100c = _DAT_6003100c | 0x1180;
    (**(code **)(_r_modules_funcs_p + 0x2b4))(0x100,*(code **)(_r_modules_funcs_p + 0x2b4));
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    if (*(char *)(iVar2 + 0x19) != '\0') {
      (**(code **)(_r_modules_funcs_p + 0x100))
                (0xe,*(undefined4 *)(_r_ip_funcs_p + 0x24c),*(code **)(_r_modules_funcs_p + 0x100));
      (**(code **)(_r_modules_funcs_p + 0x100))
                (0xd,*(undefined4 *)(_r_ip_funcs_p + 0x2ac),*(code **)(_r_modules_funcs_p + 0x100));
    }
  }
  else if (param_1 < 3) {
    _rwip_env = 0xffffffff;
    _r_plf_funcs_p = -1;
    _rwip_param = (code *)0xffffffff;
    cStack_27 = '\0';
    _r_ip_funcs_p = _r_ip_funcs_p & 0xffff;
    _DAT_60031000 = _DAT_60031000 | 0x80000000;
    do {
    } while ((int)_DAT_60031000 < 0);
    uStack_28 = 1;
    iVar2 = (*(code *)0xffffffff)(0x11,&uStack_28,&cStack_27,0xffffffff);
    if (iVar2 != 0) {
      cStack_27 = '\0';
    }
    iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    cVar1 = *(char *)(iVar2 + 0xe);
    if ((cVar1 == '\x01') &&
       (iVar2 = (**(code **)(_r_plf_funcs_p + 0x34))(*(code **)(_r_plf_funcs_p + 0x34)), iVar2 != 0)
       ) {
      rwip_prog_delay = DAT_00012017;
      uStack_28 = 2;
      cStack_27 = cVar1;
      iVar2 = (*_rwip_param)(0x2e,&uStack_28,&rwip_env,_rwip_param);
      if (iVar2 != 0) {
        _r_ip_funcs_p = CONCAT22(_DAT_00012016,400);
      }
      uStack_28 = 2;
      _r_modules_funcs_p = 0;
      iVar2 = (*_rwip_param)(0xf,&uStack_28,auStack_22,_rwip_param);
      if (iVar2 != 0) {
        auStack_22[0] = _rwip_rf;
      }
      uStack_28 = 2;
      iVar2 = (*_rwip_param)(0xe,&uStack_28,&uStack_24,_rwip_param);
      if (iVar2 != 0) {
        uStack_24 = _DAT_0001202e;
      }
      uStack_28 = 2;
      iVar2 = (*_rwip_param)(0xd,&uStack_28,&uStack_26,_rwip_param);
      if (iVar2 != 0) {
        uStack_26 = _DAT_00012030;
      }
      auStack_22[0] =
           (**(code **)(_r_modules_funcs_p + 0x2a4))
                     ((uint)auStack_22[0] << 1,*(code **)(_r_modules_funcs_p + 0x2a4));
      uStack_24 = (**(code **)(_r_modules_funcs_p + 0x2a4))
                            ((uint)uStack_24 << 1,*(code **)(_r_modules_funcs_p + 0x2a4));
      uVar3 = (**(code **)(_r_modules_funcs_p + 0x2a4))
                        ((uint)uStack_26 << 1,*(code **)(_r_modules_funcs_p + 0x2a4));
      uVar4 = (uint)uStack_24;
      uStack_26 = (ushort)uVar3;
      if ((uVar4 << 10 & 0x3e00000) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"rwip_driver.c",0x135,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((uVar3 & 0xfc00) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"rwip_driver.c",0x136,*(code **)(_r_plf_funcs_p + 8));
      }
      _DAT_6004200c = uVar3 << 0x15 | uVar3 & 0xffff | uVar4 << 10;
      _sdk_cfg_priv_opts = (uint)uStack_26;
      if ((uint)uStack_26 < (uint)auStack_22[0]) {
        _sdk_cfg_priv_opts = (uint)auStack_22[0];
      }
      if (_sdk_cfg_priv_opts < uStack_24) {
        _sdk_cfg_priv_opts = (uint)uStack_24;
      }
      _DAT_60042000 = (rwip_prog_delay ^ 1) << 0x1f | _DAT_60042000 & 0x7fffffff;
    }
    else {
      cStack_27 = '\0';
      (**(code **)(_r_modules_funcs_p + 0x2b4))(0x100,*(code **)(_r_modules_funcs_p + 0x2b4));
    }
    uStack_28 = 1;
    iVar2 = (*_rwip_param)(0x18,&uStack_28,&rwip_prog_delay,_rwip_param);
    if (iVar2 != 0) {
      rwip_prog_delay = sdk_cfg_priv_opts;
    }
  }
  return;
}

