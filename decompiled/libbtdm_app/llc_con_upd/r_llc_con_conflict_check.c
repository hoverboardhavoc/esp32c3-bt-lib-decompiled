/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_con_upd.o -> r_llc_con_conflict_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_con_conflict_check(uint param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (((param_1 < *(byte *)(iVar1 + 0xd)) && (iVar1 = *(int *)(&llc_env + param_1 * 4), iVar1 != 0))
     && ((*(byte *)(iVar1 + 0x44) & 3) != 3)) {
    if (((*(byte *)(iVar1 + 0x45) & 0x10) == 0) && (-1 < (char)*(byte *)(iVar1 + 0x45))) {
      (**(code **)(_r_ip_funcs_p + 0x4f0))(param_1,*(code **)(_r_ip_funcs_p + 0x4f0));
                    /* WARNING: Could not recover jumptable at 0x000102a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 0x908))();
      return;
    }
  }
  return;
}

