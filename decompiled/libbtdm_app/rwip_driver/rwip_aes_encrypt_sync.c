/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> rwip_driver.o -> rwip_aes_encrypt_sync
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x0001042a) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rwip_aes_encrypt_sync(void *param_1,size_t param_2)

{
  void *__dest;
  
  enc_in_buf_0 = 0;
  DAT_0001115c = 0;
  DAT_00011160 = 0;
  DAT_00011164 = 0;
  memcpy(&enc_in_buf_0,param_1,param_2);
  (**(code **)(_r_modules_funcs_p + 0x2b4))(0x20,*(code **)(_r_modules_funcs_p + 0x2b4));
  __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x128,*(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(__dest,&enc_in_buf_0,0x10);
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  do {
  } while( true );
}

