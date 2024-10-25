/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm.o -> r_llm_activity_free_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_activity_free_set(int param_1)

{
  int iVar1;
  
  *(undefined4 *)((param_1 + 0x1800c4cb) * 4) = 0;
  iVar1 = *(int *)(_p_llm_env + 8) + param_1 * 0x44;
  *(undefined1 *)(iVar1 + 0x40) = 0;
  r_sch_plan_rem(iVar1 + 0xc);
  return;
}

