/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> sch_alarm.o -> r_sch_alarm_timer_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_alarm_timer_isr(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int extraout_a1;
  int iVar5;
  
  while( true ) {
    iVar4 = r_rwip_time_get();
    iVar1 = _sch_alarm_env;
    if (_sch_alarm_env == 0) {
      return;
    }
    if (0x7fffffe < (iVar4 - *(int *)(_sch_alarm_env + 4) & 0xfffffffU)) break;
    r_co_list_pop_front(&sch_alarm_env);
    if (*(code **)(iVar1 + 8) == (code *)0x0) {
      r_assert_err(0,"sch_alarm.c",0xbc);
    }
    else {
      (**(code **)(iVar1 + 8))(iVar1);
    }
  }
  uVar2 = 0xffffffff;
  if (_sch_alarm_env != 0) {
    iVar4 = r_rwip_time_get(0xffffffff);
    iVar5 = 2;
    if (400 < 0x270U - extraout_a1) {
      iVar5 = 1;
    }
    uVar3 = iVar4 + iVar5 & 0xfffffff;
    if (0x7fffffe < (*(int *)(iVar1 + 4) - uVar3 & 0xfffffff)) {
      *(uint *)(iVar1 + 4) = uVar3;
    }
    uVar2 = *(undefined4 *)(iVar1 + 4);
  }
  r_rwip_timer_hs_set(uVar2);
  return;
}

