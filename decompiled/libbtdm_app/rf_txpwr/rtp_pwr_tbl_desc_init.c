/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  undefined1 *__src;
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if ((*(uint *)(iVar1 + 0xc) & 0xff0000) == 0x10000) {
    __src = cs_rf_pwr_tbl_chip;
  }
  else {
    __src = cs_rf_pwr_tbl_fpga;
  }
  __dest = (void *)(**(code **)(_r_modules_funcs_p + 0x3c0))(*(code **)(_r_modules_funcs_p + 0x3c0))
  ;
  memcpy(__dest,__src,0xc);
  return;
}

