/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> aes.o -> r_rw_crypto_aes_rand
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rw_crypto_aes_rand(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 local_30 [4];
  undefined1 auStack_20 [16];
  undefined4 uStack_10;
  
  puVar1 = local_30;
  do {
    uVar2 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
    *puVar1 = uVar2;
    puVar1 = puVar1 + 1;
  } while (puVar1 != &uStack_10);
  r_rw_crypto_aes_encrypt_part_0(local_30,auStack_20);
  return;
}

