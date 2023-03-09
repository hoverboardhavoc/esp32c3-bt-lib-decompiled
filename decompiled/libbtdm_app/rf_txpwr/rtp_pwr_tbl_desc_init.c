/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> rf_txpwr.o -> rtp_pwr_tbl_desc_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rtp_pwr_tbl_desc_init(void)

{
  int iVar1;
  void *__dest;
  undefined *__src;
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar1 + 0xe) == '\x01') {
    __src = &_LANCHOR3;
  }
  else {
    __src = &_LANCHOR4;
  }
  __dest = (void *)(**(code **)(_r_modules_funcs_p + 0x3c0))(*(code **)(_r_modules_funcs_p + 0x3c0))
  ;
  memcpy(__dest,__src,0xc);
  return;
}

