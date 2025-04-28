/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  if (*(char *)(iVar1 + 0xe) == '\x01') {
    __src = cs_rf_pwr_tbl_chip;
  }
  else {
    __src = cs_rf_pwr_tbl_fpga;
  }
  memcpy(&g_rf_pwr_tbl_desc,__src,0xc);
  return;
}

