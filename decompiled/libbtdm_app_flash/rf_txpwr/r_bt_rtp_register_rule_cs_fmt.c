/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> rf_txpwr.o -> r_bt_rtp_register_rule_cs_fmt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_bt_rtp_register_rule_cs_fmt(byte param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = r_rf_util_cs_fmt_convert();
  if (iVar1 == 0xe) {
    uVar2 = 0;
  }
  else {
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    if (-1 < (char)(&DAT_0001101a)[iVar1]) {
      DAT_00011019 = DAT_00011019 + '\x01';
    }
    (&DAT_0001101a)[iVar1] = param_1 | 0x80;
    (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
    uVar2 = 1;
  }
  return uVar2;
}

