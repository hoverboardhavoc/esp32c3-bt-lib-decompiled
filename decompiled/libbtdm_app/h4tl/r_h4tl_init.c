/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> h4tl.o -> r_h4tl_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_h4tl_init(int param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = param_1 * 0x28;
  *(char *)(iVar1 + 0x11032) = (char)param_1;
  (&DAT_00011040)[iVar1] = 0xff;
  (&DAT_0001103e)[iVar1] = 0xff;
  pcVar2 = *(code **)(param_2 + 8);
  *(int *)(&h4tl_env + iVar1) = param_2;
  *(undefined4 *)(&DAT_00011034 + iVar1) = 0;
  (*pcVar2)(pcVar2);
  (**(code **)(_r_modules_funcs_p + 0x100))
            (8,*(undefined4 *)(_r_modules_funcs_p + 0x98),*(code **)(_r_modules_funcs_p + 0x100));
  (**(code **)(_r_modules_funcs_p + 0x100))
            (9,*(undefined4 *)(_r_modules_funcs_p + 0x58),*(code **)(_r_modules_funcs_p + 0x100));
  (**(code **)(_r_modules_funcs_p + 0x100))
            (10,*(undefined4 *)(_r_modules_funcs_p + 0x5c),*(code **)(_r_modules_funcs_p + 0x100));
  (**(code **)(_r_modules_funcs_p + 0x100))
            (0xb,*(undefined4 *)(_r_modules_funcs_p + 0x54),*(code **)(_r_modules_funcs_p + 0x100));
                    /* WARNING: Could not recover jumptable at 0x000107b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x78))(&h4tl_env + iVar1,*(code **)(_r_modules_funcs_p + 0x78));
  return;
}

