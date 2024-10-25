/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc.o -> r_llc_cleanup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_cleanup(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = *(int **)(&llc_env + param_1 * 4);
  piVar1 = (int *)piVar2[10];
  while (piVar1 != (int *)0x0) {
    piVar1 = (int *)*piVar1;
    (**(code **)(_r_modules_funcs_p + 0x110))(*(code **)(_r_modules_funcs_p + 0x110));
  }
  if (piVar2[1] != 0) {
    (**(code **)(_r_modules_funcs_p + 0x110))
              (piVar2[1] + -0xc,*(code **)(_r_modules_funcs_p + 0x110));
  }
  if (*piVar2 != 0) {
    (**(code **)(_r_modules_funcs_p + 0x110))(*piVar2 + -0xc,*(code **)(_r_modules_funcs_p + 0x110))
    ;
  }
  (**(code **)(_r_ip_funcs_p + 0x668))(param_1,0,0,*(code **)(_r_ip_funcs_p + 0x668));
  (**(code **)(_r_ip_funcs_p + 0x668))(param_1,1,0,*(code **)(_r_ip_funcs_p + 0x668));
  (**(code **)(_r_modules_funcs_p + 0x154))
            (param_1 << 8 | 1,0xff,*(code **)(_r_modules_funcs_p + 0x154));
  (**(code **)(_r_modules_funcs_p + 0x110))(piVar2,*(code **)(_r_modules_funcs_p + 0x110));
  *(undefined4 *)(&llc_env + param_1 * 4) = 0;
  return;
}

