/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_test.o -> r_lld_test_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_test_frm_cbk(undefined4 param_1,int param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar1;
  
  if (param_2 == 1) {
    uVar1 = 1;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x208);
  }
  else {
    if (param_2 != 0) {
      if (param_2 != 2) {
                    /* WARNING: Could not recover jumptable at 0x000106be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_plf_funcs_p + 0xc))(param_1,"lld_test.c",0x238);
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x000106ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 0x210))(2);
      return;
    }
    uVar1 = 0;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x208);
  }
                    /* WARNING: Could not recover jumptable at 0x000106ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar1);
  return;
}

