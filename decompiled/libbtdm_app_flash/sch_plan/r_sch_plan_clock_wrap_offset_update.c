/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> sch_plan.o -> r_sch_plan_clock_wrap_offset_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_plan_clock_wrap_offset_update(void)

{
  uint uVar1;
  int *piVar2;
  
  for (piVar2 = (int *)_sch_plan_env; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
    uVar1 = piVar2[1];
    piVar2[2] = ((piVar2[2] + uVar1) - 0x10000000U % uVar1) % uVar1;
  }
  return;
}

