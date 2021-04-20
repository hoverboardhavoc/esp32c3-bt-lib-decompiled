/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> rf_espressif.o -> r_rf_txpwr_cs_get_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_rf_txpwr_cs_get_hack(int param_1,int param_2)

{
  uint uVar1;
  
  for (uVar1 = (uint)DAT_00011034;
      (uVar1 <= DAT_00011035 && (*(char *)(_g_rf_pwr_tbl_desc + uVar1) < param_1));
      uVar1 = uVar1 + 1 & 0xff) {
  }
  if (((param_1 != *(char *)(_g_rf_pwr_tbl_desc + uVar1)) && (param_2 == 0)) &&
     (DAT_00011034 < uVar1)) {
    uVar1 = uVar1 - 1 & 0xff;
  }
  return uVar1;
}

