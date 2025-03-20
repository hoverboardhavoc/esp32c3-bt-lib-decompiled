/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app -> rf_txpwr.o -> ble_txpwr_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint ble_txpwr_get(uint param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  code *pcVar4;
  
  if (4 < param_1) {
    return 0xff;
  }
  if (_r_plf_funcs_p == 0) {
    return 0xff;
  }
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if ((*(byte *)(iVar1 + 0xc) & 1) == 0) {
    return 0xff;
  }
  if (param_1 == 1) {
    iVar1 = adv_itf_version_is_legacy();
    if (iVar1 == 0) {
_L17:
      uVar2 = 0;
      if (param_2 != 0xffff) {
_L39:
        uVar3 = llm_hdl_to_id(uVar2);
        iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
        if (*(byte *)(iVar1 + 0xd) <= uVar3) {
          return 0xff;
        }
        pcVar4 = *(code **)(_r_modules_funcs_p + 0x208);
        goto _L38;
      }
    }
    uVar3 = 0xff;
    uVar2 = 4;
    pcVar4 = *(code **)(_r_modules_funcs_p + 0x208);
  }
  else {
    if (param_1 == 2) {
      uVar3 = 0xff;
      uVar2 = 8;
      pcVar4 = *(code **)(_r_modules_funcs_p + 0x208);
      goto _L36;
    }
    if ((int)param_1 < 3) {
      if (param_1 == 1) goto _L17;
    }
    else {
      if (param_1 == 3) {
        uVar3 = 0xff;
        uVar2 = 0xe;
        pcVar4 = *(code **)(_r_modules_funcs_p + 0x208);
        goto _L36;
      }
      if (param_1 == 4) {
        uVar2 = 3;
        if (param_2 == 0xffff) {
          uVar3 = 0xff;
          uVar2 = 2;
          pcVar4 = *(code **)(_r_modules_funcs_p + 0x208);
          goto _L36;
        }
        goto _L39;
      }
    }
    uVar3 = 0xff;
    pcVar4 = *(code **)(_r_modules_funcs_p + 0x208);
_L38:
    uVar2 = 0xff;
  }
_L36:
  uVar3 = (*pcVar4)(uVar2,uVar3,pcVar4);
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if ((*(uint *)(iVar1 + 0xc) >> 0x10 & 0xff) == 1) {
    if (0xf < uVar3) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"rf_txpwr.c",0xa0,*(code **)(_r_plf_funcs_p + 8));
    }
  }
  else {
    if (7 < uVar3) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"rf_txpwr.c",0xa3,*(code **)(_r_plf_funcs_p + 8));
    }
    uVar3 = (uint)(byte)(&_LANCHOR2)[uVar3];
  }
  return uVar3;
}

