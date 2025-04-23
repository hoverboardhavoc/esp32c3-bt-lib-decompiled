/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> sch_alarm.o -> r_sch_alarm_prog
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_alarm_prog(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int extraout_a1;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = _sch_alarm_env;
  if (_sch_alarm_env == 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0x2d4);
    uVar3 = 0xffffffff;
  }
  else {
    iVar2 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
    uVar3 = *(uint *)(iVar1 + 4);
    uVar4 = (0x270U - extraout_a1 < 0x191) + 1 + iVar2 & 0xfffffff;
    if (0x7fffffe < (uVar3 - uVar4 & 0xfffffff)) {
      *(uint *)(iVar1 + 4) = uVar4;
      uVar3 = uVar4;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0x2d4);
  }
                    /* WARNING: Could not recover jumptable at 0x00010060. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar3,UNRECOVERED_JUMPTABLE);
  return;
}

