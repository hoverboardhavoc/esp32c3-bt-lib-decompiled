/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
    if ((iVar1 != 0) || (param_2 == 0xffff)) {
      uVar3 = 0xff;
      uVar2 = 4;
      pcVar4 = *(code **)(_r_modules_funcs_p + 0x208);
      goto _L35;
    }
_L26:
    uVar3 = llm_hdl_to_id();
    iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (*(byte *)(iVar1 + 0xd) <= uVar3) {
      return 0xff;
    }
    pcVar4 = *(code **)(_r_modules_funcs_p + 0x208);
  }
  else {
    if (param_1 == 3) {
      uVar3 = 0xff;
      uVar2 = 0xe;
      pcVar4 = *(code **)(_r_modules_funcs_p + 0x208);
      goto _L35;
    }
    if (param_1 == 4) {
      if (param_2 == 0xffff) {
        uVar3 = 0xff;
        uVar2 = 2;
        pcVar4 = *(code **)(_r_modules_funcs_p + 0x208);
        goto _L35;
      }
      goto _L26;
    }
    if (param_1 == 2) {
      uVar3 = 0xff;
      uVar2 = 8;
      pcVar4 = *(code **)(_r_modules_funcs_p + 0x208);
      goto _L35;
    }
    uVar3 = 0xff;
    pcVar4 = *(code **)(_r_modules_funcs_p + 0x208);
  }
  uVar2 = 0xff;
_L35:
  uVar3 = (*pcVar4)(uVar2,uVar3,pcVar4);
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if ((*(uint *)(iVar1 + 0xc) & 0xff0000) == 0x10000) {
    if (0xf < uVar3) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"rf_txpwr.c",0xa0,*(code **)(_r_plf_funcs_p + 8));
    }
  }
  else {
    if (7 < uVar3) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"rf_txpwr.c",0xa3,*(code **)(_r_plf_funcs_p + 8));
    }
    uVar3 = (uint)*(byte *)((int)&cs_bt_pwr_tbl_idx2lvl_fpga + uVar3);
  }
  return uVar3;
}

