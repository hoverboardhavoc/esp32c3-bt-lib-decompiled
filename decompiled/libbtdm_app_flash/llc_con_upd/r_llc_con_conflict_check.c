/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> r_llc_con_conflict_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_con_conflict_check(uint param_1)

{
  int iVar1;
  
  iVar1 = r_sdk_config_get_opts();
  if (((param_1 < *(byte *)(iVar1 + 0xd)) && (iVar1 = *(int *)(&llc_env + param_1 * 4), iVar1 != 0))
     && ((*(byte *)(iVar1 + 0x44) & 3) != 3)) {
    if (((*(byte *)(iVar1 + 0x45) & 0x10) == 0) && (-1 < (char)*(byte *)(iVar1 + 0x45))) {
      r_llm_plan_elt_get(param_1);
      r_sch_plan_conflict_check();
      return;
    }
  }
  return;
}

