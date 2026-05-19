/*
 * Last changed at upstream commit 7e73ebf92e5aa995065351043c13d2ac0f00772e
 * https://github.com/espressif/esp32c3-bt-lib/commit/7e73ebf92e5aa995065351043c13d2ac0f00772e
 * Upstream date: 2026-05-19 17:43:45 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(bc853c5)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_frm_cbk(undefined4 param_1,undefined1 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE_00;
  
  switch(param_3) {
  case 0:
    uVar1 = 0;
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x35c);
    break;
  case 1:
    uVar1 = 1;
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x35c);
    break;
  case 2:
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x3a4);
    goto _L658;
  case 3:
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x3c0);
_L658:
                    /* WARNING: Could not recover jumptable at 0x00013896. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)(param_1,UNRECOVERED_JUMPTABLE_00);
    return;
  case 4:
                    /* WARNING: Could not recover jumptable at 0x000138aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x360))(param_2,*(code **)(_r_ip_funcs_p + 0x360));
    return;
  default:
                    /* WARNING: Could not recover jumptable at 0x000138c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 0xc))(param_3,"lld_con.c",0xe8c,*(code **)(_r_plf_funcs_p + 0xc));
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0001387e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE_00)(param_1,uVar1,UNRECOVERED_JUMPTABLE_00);
  return;
}

