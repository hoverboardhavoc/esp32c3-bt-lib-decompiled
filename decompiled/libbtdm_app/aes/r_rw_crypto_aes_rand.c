/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> aes.o -> r_rw_crypto_aes_rand
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rw_crypto_aes_rand(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 auStack_40 [4];
  undefined1 auStack_30 [16];
  undefined4 auStack_20 [3];
  
  puVar1 = auStack_40;
  do {
    puVar2 = puVar1 + 1;
    uVar3 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
    *puVar1 = uVar3;
    puVar1 = puVar2;
  } while (puVar2 != auStack_20);
  (**(code **)(_r_modules_funcs_p + 0x32c))
            (auStack_40,auStack_30,1,*(code **)(_r_modules_funcs_p + 0x32c));
  return;
}

