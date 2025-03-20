/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
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
    goto _L619;
  case 3:
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x3c0);
_L619:
                    /* WARNING: Could not recover jumptable at 0x000133ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)(param_1);
    return;
  case 4:
                    /* WARNING: Could not recover jumptable at 0x000133d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x360))(param_2);
    return;
  default:
                    /* WARNING: Could not recover jumptable at 0x000133f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 0xc))(param_3,"lld_con.c",0xd19);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000133ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE_00)(param_1,uVar1);
  return;
}

