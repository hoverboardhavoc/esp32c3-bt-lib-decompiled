/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> flash.o -> r_flash_read
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_flash_read(uint param_1,int param_2,size_t param_3,void *param_4)

{
  undefined4 uVar1;
  
  if (sdk_cfg_priv_opts == '\0') {
    uVar1 = 0x1f;
  }
  else {
    uVar1 = 0x12;
    if ((DAT_00010210 == param_1) && (param_2 + param_3 < DAT_0001020c)) {
      memcpy(param_4,(void *)(param_2 + flash_env),param_3);
      return 0;
    }
  }
  return uVar1;
}

