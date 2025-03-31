/*
 * Last changed at upstream commit 2fd7ad255fceabdfba56882ce4523efdba2fc255
 * https://github.com/espressif/esp32c3-bt-lib/commit/2fd7ad255fceabdfba56882ce4523efdba2fc255
 * Upstream date: 2025-03-31 11:18:40 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(566c8e3)
 * Source: libbtdm_app -> rf_txpwr.o -> r_bt_rtp_apply_rule_cs_fmt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_bt_rtp_apply_rule_cs_fmt(byte *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (((DAT_00011015 == '\0') ||
      (iVar2 = (**(code **)(_r_modules_funcs_p + 0x20c))(*(code **)(_r_modules_funcs_p + 0x20c)),
      iVar2 == 0xe)) || (-1 < (char)(&DAT_00011016)[iVar2])) {
    uVar1 = 0;
  }
  else {
    *param_1 = (&DAT_00011016)[iVar2] & 0x7f;
    uVar1 = 1;
  }
  return uVar1;
}

