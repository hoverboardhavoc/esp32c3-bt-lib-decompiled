/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app -> rf_txpwr.o -> ble_txpwr_set_inter
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ble_txpwr_set_inter(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  if (4 < param_1) {
    return 0xffffffff;
  }
  if (0xf < param_3) {
    return 0xfffffffe;
  }
  if ((_r_plf_funcs_p == 0) ||
     (iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
     (*(byte *)(iVar1 + 0xc) & 1) == 0)) {
    return 0xfffffffd;
  }
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  uVar2 = bt_controller_txpwr_level_2_index(*(undefined4 *)(iVar1 + 0xc),param_3);
  if (param_1 == 2) {
    (**(code **)(_r_modules_funcs_p + 0x1f0))(8,uVar2,*(code **)(_r_modules_funcs_p + 0x1f0));
    (**(code **)(_r_modules_funcs_p + 0x1f0))(9,uVar2,*(code **)(_r_modules_funcs_p + 0x1f0));
    (**(code **)(_r_modules_funcs_p + 0x1f0))(10,uVar2,*(code **)(_r_modules_funcs_p + 0x1f0));
    param_2 = 0xb;
    pcVar3 = *(code **)(_r_modules_funcs_p + 0x1f0);
  }
  else {
    if ((int)param_1 < 3) {
      if (param_1 != 1) {
_L57:
        iVar1 = (**(code **)(_r_plf_funcs_p + 0xf4))(*(code **)(_r_plf_funcs_p + 0xf4));
        *(char *)(iVar1 + 1) = (char)uVar2;
        return 0;
      }
      iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      if (*(byte *)(iVar1 + 0xd) <= param_2) {
        (**(code **)(_r_modules_funcs_p + 0x1f0))(4,uVar2,*(code **)(_r_modules_funcs_p + 0x1f0));
        (**(code **)(_r_modules_funcs_p + 0x1f0))(5,uVar2,*(code **)(_r_modules_funcs_p + 0x1f0));
        param_2 = 6;
        pcVar3 = *(code **)(_r_modules_funcs_p + 0x1f0);
        goto _L69;
      }
    }
    else {
      if (param_1 == 3) {
        (**(code **)(_r_modules_funcs_p + 0x1f0))(0xe,uVar2,*(code **)(_r_modules_funcs_p + 0x1f0));
        param_2 = 0xf;
        pcVar3 = *(code **)(_r_modules_funcs_p + 0x1f0);
        goto _L69;
      }
      if (param_1 != 4) goto _L57;
      iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      if (*(byte *)(iVar1 + 0xd) <= param_2) {
        (**(code **)(_r_modules_funcs_p + 0x1f0))(2,uVar2,*(code **)(_r_modules_funcs_p + 0x1f0));
        param_2 = 3;
        pcVar3 = *(code **)(_r_modules_funcs_p + 0x1f0);
        goto _L69;
      }
    }
    pcVar3 = *(code **)(_r_modules_funcs_p + 0x1fc);
  }
_L69:
  (*pcVar3)(param_2,uVar2,pcVar3);
  return 0;
}

