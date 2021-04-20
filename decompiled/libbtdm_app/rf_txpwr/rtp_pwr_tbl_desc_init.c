/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> rf_txpwr.o -> rtp_pwr_tbl_desc_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void rtp_pwr_tbl_desc_init(void)

{
  int iVar1;
  undefined *__src;
  
  iVar1 = sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0xe) == '\x01') {
    __src = &_LANCHOR2;
  }
  else {
    __src = &_LANCHOR3;
  }
  memcpy(g_rf_pwr_tbl_desc,__src,0xc);
  return;
}

