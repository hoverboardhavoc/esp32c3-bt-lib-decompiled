/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_per_adv.o -> r_lld_per_adv_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_frm_cbk(undefined4 param_1,undefined1 param_2,int param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar1;
  
  if (param_3 == 1) {
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x2f0);
    uVar1 = 1;
  }
  else {
    if (param_3 != 0) {
      if (param_3 == 2) {
        return;
      }
      if (param_3 != 4) {
                    /* WARNING: Could not recover jumptable at 0x00011934. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_plf_funcs_p + 0xc))("lld_per_adv.c",0x486);
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x0001196a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 0x2f4))(param_2,4);
      return;
    }
    uVar1 = 0;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x2f0);
  }
                    /* WARNING: Could not recover jumptable at 0x0001194a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_2,param_1,uVar1);
  return;
}

