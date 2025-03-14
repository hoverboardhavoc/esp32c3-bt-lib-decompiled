/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> sch_alarm.o -> r_sch_alarm_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_alarm_set(int param_1)

{
  int iVar1;
  uint uVar2;
  int extraout_a1;
  int *piVar3;
  int iVar4;
  int *piVar5;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = r_rwip_time_get();
  iVar4 = 1;
  if (0x270U - extraout_a1 < 0x1f5) {
    iVar4 = 2;
  }
  uVar2 = iVar1 + iVar4 & 0xfffffff;
  if (0x7fffffe < (*(int *)(param_1 + 4) - uVar2 & 0xfffffff)) {
    *(uint *)(param_1 + 4) = uVar2;
  }
  piVar3 = (int *)0;
  piVar5 = (int *)_sch_alarm_env;
  while ((piVar5 != (int *)0x0 && (0x7fffffe < (piVar5[1] - *(int *)(param_1 + 4) & 0xfffffffU)))) {
    piVar3 = piVar5;
    piVar5 = (int *)*piVar5;
  }
  if (piVar3 == (int *)0x0) {
    r_co_list_push_front(&sch_alarm_env,param_1);
    r_sch_alarm_prog();
  }
  else {
    r_co_list_insert_after(&sch_alarm_env);
  }
                    /* WARNING: Could not recover jumptable at 0x00010192. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

