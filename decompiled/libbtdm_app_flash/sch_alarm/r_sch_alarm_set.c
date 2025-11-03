/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
  int extraout_a1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = r_rwip_time_get();
  iVar3 = 1;
  if (0x270U - extraout_a1 < 0x1f5) {
    iVar3 = 2;
  }
  uVar4 = iVar3 + iVar1 & 0xfffffff;
  if (0x7fffffe < (*(int *)(param_1 + 4) - uVar4 & 0xfffffff)) {
    *(uint *)(param_1 + 4) = uVar4;
  }
  piVar2 = (int *)0;
  piVar5 = (int *)_sch_alarm_env;
  while ((piVar5 != (int *)0x0 && (0x7fffffe < (piVar5[1] - *(int *)(param_1 + 4) & 0xfffffffU)))) {
    piVar2 = piVar5;
    piVar5 = (int *)*piVar5;
  }
  if (piVar2 == (int *)0x0) {
    r_co_list_push_front(&sch_alarm_env,param_1);
    r_sch_alarm_prog();
  }
  else {
    r_co_list_insert_after(&sch_alarm_env,param_1);
  }
  r_ble_log_internal_x2(0x4029019b,param_1,*(undefined4 *)(param_1 + 4));
                    /* WARNING: Could not recover jumptable at 0x000101b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

