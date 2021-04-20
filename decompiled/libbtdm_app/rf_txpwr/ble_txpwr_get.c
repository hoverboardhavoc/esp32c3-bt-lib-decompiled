/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> rf_txpwr.o -> ble_txpwr_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint ble_txpwr_get(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if ((param_1 < 0xc) && (_r_plf_funcs_p != 0)) {
    iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if ((*(byte *)(iVar1 + 0xc) & 1) == 0) {
      return 0xff;
    }
    if (param_1 == 9) {
      uVar2 = 4;
    }
    else if (param_1 == 10) {
      uVar2 = 8;
    }
    else {
      uVar2 = 0xff;
    }
    uVar3 = (**(code **)(_r_modules_funcs_p + 0x208))
                      (uVar2,0xff,*(code **)(_r_modules_funcs_p + 0x208));
    iVar1 = sdk_config_get_opts_ext();
    if ((*(uint *)(iVar1 + 0xc) >> 0x10 & 0xff) == 1) {
      if (0xf < uVar3) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"rf_txpwr.c",0x99,*(code **)(_r_plf_funcs_p + 8));
      }
    }
    else {
      if (7 < uVar3) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"rf_txpwr.c",0x9c,*(code **)(_r_plf_funcs_p + 8));
      }
      uVar3 = (uint)(byte)(&_LANCHOR1)[uVar3];
    }
    return uVar3;
  }
  return 0xff;
}

