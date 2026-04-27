/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> sch_alarm.o -> r_sch_alarm_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_sch_alarm_clear(int param_1)

{
  int iVar1;
  uint uVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  if (param_1 == _sch_alarm_env) {
    r_co_list_pop_front(&sch_alarm_env);
    iVar1 = 0;
    if (_sch_alarm_env != 0) {
      r_sch_alarm_prog();
    }
  }
  else {
    uVar2 = r_co_list_extract(&sch_alarm_env,param_1);
    iVar1 = ((uVar2 ^ 1) & 0x7f) << 1;
  }
  r_ble_log_internal_x2(0x40290225,param_1,iVar1);
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return iVar1;
}

