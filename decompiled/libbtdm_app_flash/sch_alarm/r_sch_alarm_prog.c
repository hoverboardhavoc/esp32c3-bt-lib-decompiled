/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> sch_alarm.o -> r_sch_alarm_prog
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_alarm_prog(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int extraout_a1;
  int iVar4;
  uint uVar5;
  
  iVar1 = _sch_alarm_env;
  uVar2 = 0xffffffff;
  if (_sch_alarm_env != 0) {
    iVar3 = r_rwip_time_get(0xffffffff);
    iVar4 = 2;
    if (400 < 0x270U - extraout_a1) {
      iVar4 = 1;
    }
    uVar5 = iVar4 + iVar3 & 0xfffffff;
    if (0x7fffffe < (*(int *)(iVar1 + 4) - uVar5 & 0xfffffff)) {
      *(uint *)(iVar1 + 4) = uVar5;
    }
    uVar2 = *(undefined4 *)(iVar1 + 4);
  }
  r_rwip_timer_hs_set(uVar2);
  return;
}

