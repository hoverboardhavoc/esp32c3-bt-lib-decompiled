/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  uint uVar3;
  int *piVar4;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = r_rwip_time_get();
  uVar3 = (0x270U - extraout_a1 < 0x1f5) + 1 + iVar1 & 0xfffffff;
  if (0x7fffffe < (*(int *)(param_1 + 4) - uVar3 & 0xfffffff)) {
    *(uint *)(param_1 + 4) = uVar3;
  }
  piVar2 = (int *)0;
  piVar4 = (int *)_sch_alarm_env;
  while ((piVar4 != (int *)0x0 && (0x7fffffe < (piVar4[1] - *(int *)(param_1 + 4) & 0xfffffffU)))) {
    piVar2 = piVar4;
    piVar4 = (int *)*piVar4;
  }
  if (piVar2 == (int *)0x0) {
    r_co_list_push_front(&sch_alarm_env,param_1);
    r_sch_alarm_prog();
  }
  else {
    r_co_list_insert_after(&sch_alarm_env,param_1);
  }
  iVar1 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar1 + 0x28) & 1) != 0) {
    iVar1 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar1 + 0x2c) < 3) {
      r_ble_log_internal_x3
                (0x40240000,param_1,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
    }
  }
                    /* WARNING: Could not recover jumptable at 0x000101f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

