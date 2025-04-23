/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> rwip_driver.o -> rwip_aes_encrypt_sync
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010946) */
/* WARNING: Removing unreachable block (ram,0x000107ea) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rwip_aes_encrypt_sync(void *param_1,size_t param_2)

{
  void *__dest;
  
  enc_in_buf_0 = 0;
  DAT_00011114 = 0;
  DAT_00011118 = 0;
  DAT_0001111c = 0;
  memcpy(&enc_in_buf_0,param_1,param_2);
  r_rwip_prevent_sleep_set(0x20);
  __dest = (void *)r_emi_get_mem_addr_by_offset(0x128);
  memcpy(__dest,&enc_in_buf_0,0x10);
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  do {
  } while( true );
}

