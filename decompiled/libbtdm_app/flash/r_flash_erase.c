/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> flash.o -> r_flash_erase
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_flash_erase(uint param_1,int param_2,size_t param_3)

{
  undefined4 uVar1;
  
  if (sdk_cfg_priv_opts == '\0') {
    uVar1 = 0x1f;
  }
  else {
    uVar1 = 0x12;
    if ((DAT_00010268 == param_1) && (param_2 + param_3 < DAT_00010264)) {
      memset((void *)(param_2 + _LANCHOR0),0xff,param_3);
      return 0;
    }
  }
  return uVar1;
}

