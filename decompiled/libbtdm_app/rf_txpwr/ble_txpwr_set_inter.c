/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> rf_txpwr.o -> ble_txpwr_set_inter
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ble_txpwr_set_inter(uint param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  if (0xb < param_1) {
    return 0xffffffff;
  }
  if (0xf < param_2) {
    return 0xfffffffe;
  }
  if ((_r_plf_funcs_p == 0) ||
     (iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
     (*(byte *)(iVar1 + 0xc) & 1) == 0)) {
    return 0xfffffffd;
  }
  iVar1 = sdk_config_get_opts_ext();
  uVar2 = bt_controller_txpwr_level_2_index(*(undefined4 *)(iVar1 + 0xc),param_2);
  if (param_1 == 10) {
    (**(code **)(_r_modules_funcs_p + 0x1f0))(8,uVar2,*(code **)(_r_modules_funcs_p + 0x1f0));
    (**(code **)(_r_modules_funcs_p + 0x1f0))(9,uVar2,*(code **)(_r_modules_funcs_p + 0x1f0));
    (**(code **)(_r_modules_funcs_p + 0x1f0))(10,uVar2,*(code **)(_r_modules_funcs_p + 0x1f0));
    uVar3 = 0xb;
    pcVar4 = *(code **)(_r_modules_funcs_p + 0x1f0);
  }
  else {
    if (param_1 == 0xb) {
      sdk_cfg_derived_opts = (char)uVar2;
      return 0;
    }
    if (param_1 != 9) {
      return 0;
    }
    (**(code **)(_r_modules_funcs_p + 0x1f0))(4,uVar2,*(code **)(_r_modules_funcs_p + 0x1f0));
    (**(code **)(_r_modules_funcs_p + 0x1f0))(5,uVar2,*(code **)(_r_modules_funcs_p + 0x1f0));
    uVar3 = 6;
    pcVar4 = *(code **)(_r_modules_funcs_p + 0x1f0);
  }
  (*pcVar4)(uVar3,uVar2,pcVar4);
  return 0;
}

