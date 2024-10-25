/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> ke_event.o -> r_ke_event_schedule
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_event_schedule(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  while (iVar1 = _ke_event_env, _ke_event_env != 0) {
    iVar3 = __clzsi2(_ke_event_env);
    uVar2 = 0x1fU - iVar3 & 0xff;
    if (0xe < uVar2) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (uVar2,iVar1,"ke_event.c",0xba,*(code **)(_r_plf_funcs_p + 0xc));
    }
    if (*(code **)(memset + uVar2 * 4) == (code *)0x0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"ke_event.c",0xc6,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      (**(code **)(memset + uVar2 * 4))();
    }
  }
  return;
}

