/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_frm_cbk(undefined4 param_1,undefined1 param_2,undefined4 param_3)

{
  code *UNRECOVERED_JUMPTABLE_00;
  undefined4 uVar1;
  
  switch(param_3) {
  case 0:
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x35c);
    uVar1 = 0;
    break;
  case 1:
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x35c);
    uVar1 = 1;
    break;
  case 2:
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x3a4);
    goto _L618;
  case 3:
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x3c0);
_L618:
                    /* WARNING: Could not recover jumptable at 0x000133be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)(param_1);
    return;
  case 4:
                    /* WARNING: Could not recover jumptable at 0x000133ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x360))(param_2);
    return;
  default:
                    /* WARNING: Could not recover jumptable at 0x000133e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 0xc))(param_3,"lld_con.c",0xcfb);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000133ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE_00)(param_1,uVar1);
  return;
}

