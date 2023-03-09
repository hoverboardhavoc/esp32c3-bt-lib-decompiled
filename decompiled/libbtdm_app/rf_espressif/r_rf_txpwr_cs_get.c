/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> rf_espressif.o -> r_rf_txpwr_cs_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_rf_txpwr_cs_get(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = (**(code **)(_r_modules_funcs_p + 0x3c0))(*(code **)(_r_modules_funcs_p + 0x3c0));
  for (uVar2 = (uint)DAT_00011034;
      (iVar3 = (int)*(char *)(*(int *)(iVar1 + 8) + uVar2), uVar2 <= DAT_00011035 &&
      (iVar3 < param_1)); uVar2 = uVar2 + 1 & 0xff) {
  }
  if (((param_1 != iVar3) && (param_2 == 0)) && (DAT_00011034 < uVar2)) {
    uVar2 = uVar2 - 1 & 0xff;
  }
  return uVar2;
}

