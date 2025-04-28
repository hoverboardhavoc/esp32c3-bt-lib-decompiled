/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  
  puVar1 = local_30;
  do {
    uVar2 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
    *puVar1 = uVar2;
    puVar1 = puVar1 + 1;
  } while (puVar1 != (undefined4 *)&stack0xfffffff0);
  r_rw_crypto_aes_encrypt_part_0(local_30,auStack_20);
  return;
}

