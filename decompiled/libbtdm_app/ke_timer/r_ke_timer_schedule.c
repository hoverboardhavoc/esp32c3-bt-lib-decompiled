/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> ke_timer.o -> r_ke_timer_schedule
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_timer_schedule(void)

{
  int iVar1;
  int iVar2;
  
  do {
    (**(code **)(_r_modules_funcs_p + 0xec))(4,*(code **)(_r_modules_funcs_p + 0xec));
    iVar2 = _DAT_00011014;
    if (_DAT_00011014 == 0) {
      return;
    }
    iVar1 = (**(code **)(_r_modules_funcs_p + 0xac))
                      (*(int *)(_DAT_00011014 + 8) + -1,*(code **)(_r_modules_funcs_p + 0xac));
    if (iVar1 == 0) {
      (**(code **)(_r_modules_funcs_p + 0x2cc))
                (*(undefined4 *)(iVar2 + 8),*(code **)(_r_modules_funcs_p + 0x2cc));
      iVar2 = (**(code **)(_r_modules_funcs_p + 0xac))
                        (*(undefined4 *)(iVar2 + 8),*(code **)(_r_modules_funcs_p + 0xac));
      if (iVar2 == 0) {
        return;
      }
      (**(code **)(_r_modules_funcs_p + 0x2cc))(0xffffffff,*(code **)(_r_modules_funcs_p + 0x2cc));
    }
    iVar2 = (**(code **)(_r_modules_funcs_p + 0x40))(&ke_env,*(code **)(_r_modules_funcs_p + 0x40));
    (**(code **)(_r_modules_funcs_p + 0xe4))
              (*(undefined2 *)(iVar2 + 4),*(undefined2 *)(iVar2 + 6),0xff,
               *(code **)(_r_modules_funcs_p + 0xe4));
    (**(code **)(_r_modules_funcs_p + 0x110))(iVar2,*(code **)(_r_modules_funcs_p + 0x110));
  } while( true );
}

