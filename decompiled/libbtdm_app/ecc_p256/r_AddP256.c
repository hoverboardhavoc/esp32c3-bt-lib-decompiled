/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> ecc_p256.o -> r_AddP256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_AddP256(void *param_1)

{
  undefined1 auStack_3c [36];
  undefined4 uStack_18;
  
  (**(code **)(_r_modules_funcs_p + 0x3ac))
            (&bigHexP256,param_1,auStack_3c,*(code **)(_r_modules_funcs_p + 0x3ac));
  memcpy(param_1,auStack_3c,0x22);
  *(undefined4 *)((int)param_1 + 0x28) = 0;
  *(undefined4 *)((int)param_1 + 0x24) = uStack_18;
  return;
}

