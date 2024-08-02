/*
 * Last changed at upstream commit 929c19d35d3c2c5568206f22d077d2d3ee9f1883
 * https://github.com/espressif/esp32c3-bt-lib/commit/929c19d35d3c2c5568206f22d077d2d3ee9f1883
 * Upstream date: 2024-08-02 17:03:33 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b445b5f)
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
  
  if (0xb < param_1) {
    return 0xff;
  }
  if ((_r_plf_funcs_p != 0) &&
     (iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
     (*(byte *)(iVar1 + 0xc) & 1) != 0)) {
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
    iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    if ((*(uint *)(iVar1 + 0xc) >> 0x10 & 0xff) == 1) {
      if (0xf < uVar3) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"rf_txpwr.c",0x9e,*(code **)(_r_plf_funcs_p + 8));
      }
    }
    else {
      if (7 < uVar3) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"rf_txpwr.c",0xa1,*(code **)(_r_plf_funcs_p + 8));
      }
      uVar3 = (uint)(byte)(&_LANCHOR2)[uVar3];
    }
    return uVar3;
  }
  return 0xff;
}

