/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> rwip_driver.o -> rwip_aes_encrypt_sync
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x0001043a) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rwip_aes_encrypt_sync(void *param_1,size_t param_2)

{
  void *__dest;
  
  enc_in_buf_0 = 0;
  DAT_00011250 = 0;
  DAT_00011254 = 0;
  DAT_00011258 = 0;
  memcpy(&enc_in_buf_0,param_1,param_2);
  (**(code **)(_r_modules_funcs_p + 0x2b4))(0x20,*(code **)(_r_modules_funcs_p + 0x2b4));
  __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x128,*(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(__dest,&enc_in_buf_0,0x10);
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  do {
  } while( true );
}

