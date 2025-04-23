/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  uint uVar2;
  int iVar3;
  int extraout_a1;
  uint uVar4;
  
  while( true ) {
    iVar3 = r_rwip_time_get();
    iVar1 = _sch_alarm_env;
    if (_sch_alarm_env == 0) {
      return;
    }
    if (0x7fffffe < (iVar3 - *(int *)(_sch_alarm_env + 4) & 0xfffffffU)) break;
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
    iVar3 = r_rwip_time_get(0xffffffff);
    uVar4 = (0x270U - extraout_a1 < 0x191) + 1 + iVar3 & 0xfffffff;
    uVar2 = *(uint *)(iVar1 + 4);
    if (0x7fffffe < (*(uint *)(iVar1 + 4) - uVar4 & 0xfffffff)) {
      *(uint *)(iVar1 + 4) = uVar4;
      uVar2 = uVar4;
    }
  }
  r_rwip_timer_hs_set(uVar2);
  return;
}

