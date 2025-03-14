/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> sch_arb.o -> r_sch_arb_prog_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_arb_prog_timer(void)

{
  uint uVar1;
  uint uVar2;
  int extraout_a1;
  uint uVar3;
  
  uVar1 = r_rwip_time_get();
  uVar3 = extraout_a1 + 400;
  if (0x270 < uVar3) {
    uVar3 = extraout_a1 - 0xe1;
    uVar1 = uVar1 + 1 & 0xfffffff;
  }
  if (_sch_arb_env == 0) {
    uVar3 = 0;
    uVar1 = 0xffffffff;
  }
  else {
    uVar2 = *(int *)(_sch_arb_env + 4) - (uint)rwip_prog_delay & 0xfffffff;
    if (((uVar2 - uVar1 & 0xfffffff) < 0x7ffffff) &&
       ((uVar2 != uVar1 || (uVar1 = uVar2, uVar3 < *(uint *)(_sch_arb_env + 8))))) {
      uVar1 = uVar2;
      uVar3 = *(uint *)(_sch_arb_env + 8);
    }
  }
  r_rwip_timer_hus_set(uVar1,uVar3);
  return;
}

