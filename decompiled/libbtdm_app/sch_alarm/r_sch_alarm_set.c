/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> sch_alarm.o -> r_sch_alarm_set
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
  iVar1 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
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
    (**(code **)(_r_modules_funcs_p + 0x4c))
              (&sch_alarm_env,param_1,*(code **)(_r_modules_funcs_p + 0x4c));
    (**(code **)(_r_ip_funcs_p + 0x708))(*(code **)(_r_ip_funcs_p + 0x708));
  }
  else {
    (**(code **)(_r_modules_funcs_p + 0x30))(&sch_alarm_env,*(code **)(_r_modules_funcs_p + 0x30));
  }
                    /* WARNING: Could not recover jumptable at 0x000101d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

