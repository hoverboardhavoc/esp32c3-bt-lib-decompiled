/*
 * Last changed at upstream commit a075a8fde411bdd92973051edf2cd234601b259c
 * https://github.com/espressif/esp32c3-bt-lib/commit/a075a8fde411bdd92973051edf2cd234601b259c
 * Upstream date: 2023-11-30 21:15:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(70ab55f)
 * Source: libbtdm_app -> aes.o -> rw_crypto_aes_encrypt_sync
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void rw_crypto_aes_encrypt_sync(int param_1,int param_2,char param_3,int param_4)

{
  if ((((DAT_00011008 == '\0') && ((byte)(param_3 - 1U) < 0x10)) && (param_1 != 0)) &&
     ((param_2 != 0 && (param_4 != 0)))) {
    DAT_00011008 = 1;
    rwip_aes_encrypt_sync();
    DAT_00011008 = '\0';
  }
  return;
}

