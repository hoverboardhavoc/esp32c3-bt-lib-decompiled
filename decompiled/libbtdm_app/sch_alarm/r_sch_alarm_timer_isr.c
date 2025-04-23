/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> sch_alarm.o -> r_sch_alarm_timer_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_alarm_timer_isr(void)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  while( true ) {
    iVar2 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
    iVar1 = _sch_alarm_env;
    if (_sch_alarm_env == 0) {
      return;
    }
    if (0x7fffffe < (iVar2 - *(int *)(_sch_alarm_env + 4) & 0xfffffffU)) break;
    (**(code **)(_r_modules_funcs_p + 0x40))(&sch_alarm_env,*(code **)(_r_modules_funcs_p + 0x40));
    pcVar3 = *(code **)(iVar1 + 8);
    if (pcVar3 == (code *)0x0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"sch_alarm.c",0xbc,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      (*pcVar3)(iVar1);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x0001012c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x708))(*(code **)(_r_ip_funcs_p + 0x708));
  return;
}

