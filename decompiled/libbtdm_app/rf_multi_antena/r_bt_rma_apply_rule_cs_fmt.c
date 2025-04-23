/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> rf_multi_antena.o -> r_bt_rma_apply_rule_cs_fmt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_bt_rma_apply_rule_cs_fmt(byte *param_1,byte *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (((DAT_00011001 == '\0') ||
      (iVar3 = (**(code **)(_r_modules_funcs_p + 0x20c))(*(code **)(_r_modules_funcs_p + 0x20c)),
      iVar3 == 0xe)) || (bVar1 = (&DAT_00011002)[iVar3], -1 < (char)bVar1)) {
    uVar2 = 0;
  }
  else {
    if (param_1 != (byte *)0x0) {
      *param_1 = bVar1 >> 2 & 3;
    }
    if (param_2 != (byte *)0x0) {
      *param_2 = bVar1 & 3;
    }
    uVar2 = 1;
  }
  return uVar2;
}

