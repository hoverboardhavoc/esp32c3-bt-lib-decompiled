/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> sch_alarm.o -> r_sch_alarm_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_sch_alarm_clear(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  if (param_1 == _sch_alarm_env) {
    (**(code **)(_r_modules_funcs_p + 0x40))(&sch_alarm_env,*(code **)(_r_modules_funcs_p + 0x40));
    if (_sch_alarm_env != 0) {
      (**(code **)(_r_ip_funcs_p + 0x708))(*(code **)(_r_ip_funcs_p + 0x708));
    }
  }
  else {
    iVar2 = (**(code **)(_r_modules_funcs_p + 0x1c))
                      (&sch_alarm_env,*(code **)(_r_modules_funcs_p + 0x1c));
    if (iVar2 == 0) {
      uVar1 = 2;
      goto _L32;
    }
  }
  uVar1 = 0;
_L32:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar1;
}

