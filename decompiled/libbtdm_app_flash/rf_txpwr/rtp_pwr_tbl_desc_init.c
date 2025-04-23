/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> rf_txpwr.o -> rtp_pwr_tbl_desc_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void rtp_pwr_tbl_desc_init(void)

{
  int iVar1;
  undefined1 *__src;
  
  iVar1 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar1 + 0xc) & 0xff0000) == 0x10000) {
    __src = cs_rf_pwr_tbl_chip;
  }
  else {
    __src = cs_rf_pwr_tbl_fpga;
  }
  memcpy(&g_rf_pwr_tbl_desc,__src,0xc);
  return;
}

