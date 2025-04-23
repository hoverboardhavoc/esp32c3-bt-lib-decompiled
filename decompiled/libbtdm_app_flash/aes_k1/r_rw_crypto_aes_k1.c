/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> aes_k1.o -> r_rw_crypto_aes_k1
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_rw_crypto_aes_k1(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined1 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  
  iVar1 = r_aes_alloc(0x4c,0x10000,param_6,param_7);
  *(undefined1 *)(iVar1 + 0x38) = param_5;
  *(undefined1 *)(iVar1 + 0x39) = 1;
  *(undefined4 *)(iVar1 + 0x34) = param_4;
  r_aes_cmac_start(param_1,param_2,param_3);
  return;
}

