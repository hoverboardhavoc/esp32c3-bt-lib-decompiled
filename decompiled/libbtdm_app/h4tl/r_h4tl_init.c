/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  (&DAT_0001103c)[iVar1] = 0xff;
  (&DAT_0001103a)[iVar1] = 0xff;
  pcVar2 = *(code **)(param_2 + 8);
  *(int *)(&h4tl_env + iVar1) = param_2;
  *(char *)(iVar1 + 0x1102e) = (char)param_1;
  *(undefined4 *)(&DAT_00011030 + iVar1) = 0;
  (*pcVar2)(pcVar2);
  (**(code **)(_r_modules_funcs_p + 0x100))
            (8,*(undefined4 *)(_r_modules_funcs_p + 0x98),*(code **)(_r_modules_funcs_p + 0x100));
  (**(code **)(_r_modules_funcs_p + 0x100))
            (9,*(undefined4 *)(_r_modules_funcs_p + 0x58),*(code **)(_r_modules_funcs_p + 0x100));
  (**(code **)(_r_modules_funcs_p + 0x100))
            (10,*(undefined4 *)(_r_modules_funcs_p + 0x5c),*(code **)(_r_modules_funcs_p + 0x100));
  (**(code **)(_r_modules_funcs_p + 0x100))
            (0xb,*(undefined4 *)(_r_modules_funcs_p + 0x54),*(code **)(_r_modules_funcs_p + 0x100));
                    /* WARNING: Could not recover jumptable at 0x000107b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x78))(&h4tl_env + iVar1);
  return;
}

