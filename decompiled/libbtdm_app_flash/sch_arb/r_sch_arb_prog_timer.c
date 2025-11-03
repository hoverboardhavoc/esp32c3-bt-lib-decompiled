/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> sch_arb.o -> r_sch_arb_prog_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_arb_prog_timer(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int extraout_a1;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = r_rwip_time_get();
  uVar6 = extraout_a1 + 400;
  if (0x270 < uVar6) {
    uVar6 = extraout_a1 - 0xe1;
    uVar3 = uVar3 + 1 & 0xfffffff;
  }
  if (_sch_arb_env == 0) {
    r_rwip_timer_hus_set(0xffffffff,0);
    uVar5 = 0;
    uVar3 = 0xffffffff;
  }
  else {
    uVar4 = *(uint *)(_sch_arb_env + 8);
    uVar2 = *(int *)(_sch_arb_env + 4) - (uint)rwip_prog_delay & 0xfffffff;
    uVar5 = uVar6;
    if ((((uVar2 - uVar3 & 0xfffffff) < 0x7ffffff) &&
        (bVar1 = uVar2 == uVar3, uVar3 = uVar2, uVar5 = uVar4, bVar1)) && (uVar4 < uVar6)) {
      uVar5 = uVar6;
    }
    r_rwip_timer_hus_set(uVar3,uVar5);
  }
  r_ble_log_internal_x2(0x2009019e,uVar3,uVar5);
  return;
}

