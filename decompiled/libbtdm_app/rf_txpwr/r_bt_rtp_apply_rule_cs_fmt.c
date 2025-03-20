/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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
  
  if (((DAT_00011011 == '\0') ||
      (iVar2 = (**(code **)(_r_modules_funcs_p + 0x20c))(*(code **)(_r_modules_funcs_p + 0x20c)),
      iVar2 == 0xe)) || (-1 < (char)(&DAT_00011012)[iVar2])) {
    uVar1 = 0;
  }
  else {
    *param_1 = (&DAT_00011012)[iVar2] & 0x7f;
    uVar1 = 1;
  }
  return uVar1;
}

