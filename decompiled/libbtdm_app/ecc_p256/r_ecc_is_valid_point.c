/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> ecc_p256.o -> r_ecc_is_valid_point
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool r_ecc_is_valid_point(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_144 [36];
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined1 auStack_118 [36];
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined1 auStack_ec [36];
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined1 auStack_c0 [36];
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined1 auStack_94 [36];
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined1 auStack_68 [36];
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined1 auStack_3c [36];
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  memset(auStack_144,0,0x22);
  uStack_120 = 0;
  uStack_11c = 0;
  memset(auStack_118,0,0x22);
  uStack_f4 = 0;
  uStack_f0 = 0;
  memset(auStack_ec,0,0x22);
  uStack_c8 = 0;
  uStack_c4 = 0;
  memset(auStack_c0,0,0x22);
  uStack_9c = 0;
  uStack_98 = 0;
  memset(auStack_94,0,0x22);
  uStack_70 = 0;
  uStack_6c = 0;
  memset(auStack_68,0,0x22);
  uStack_44 = 0;
  uStack_40 = 0;
  memset(auStack_3c,0,0x22);
  uStack_18 = 0;
  uStack_14 = 0;
  (**(code **)(_r_modules_funcs_p + 0x39c))
            (param_2,param_2,auStack_144,*(code **)(_r_modules_funcs_p + 0x39c));
  (**(code **)(_r_modules_funcs_p + 0x39c))
            (param_1,param_1,auStack_118,*(code **)(_r_modules_funcs_p + 0x39c));
  (**(code **)(_r_modules_funcs_p + 0x39c))
            (param_1,auStack_118,auStack_ec,*(code **)(_r_modules_funcs_p + 0x39c));
  (**(code **)(_r_modules_funcs_p + 0x354))
            (param_1,param_1,auStack_c0,*(code **)(_r_modules_funcs_p + 0x354));
  (**(code **)(_r_modules_funcs_p + 0x354))
            (auStack_c0,param_1,auStack_94,*(code **)(_r_modules_funcs_p + 0x354));
  (**(code **)(_r_modules_funcs_p + 0x3b0))
            (auStack_ec,auStack_94,auStack_68,*(code **)(_r_modules_funcs_p + 0x3b0));
  (**(code **)(_r_modules_funcs_p + 0x354))
            (auStack_68,&coef_B,auStack_3c,*(code **)(_r_modules_funcs_p + 0x354));
  iVar1 = memcmp(auStack_144,auStack_3c,0x22);
  return iVar1 == 0;
}

