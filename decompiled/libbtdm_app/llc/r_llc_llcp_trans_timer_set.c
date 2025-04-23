/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc.o -> r_llc_llcp_trans_timer_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_llcp_trans_timer_set(uint param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  
  iVar1 = (param_2 != 0) + 0x100;
  if (param_3 != 0) {
    iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    iVar4 = *(int *)(&llc_env + param_1 * 4);
    if (((param_1 < *(byte *)(iVar2 + 0xd)) && (iVar4 != 0)) && ((*(byte *)(iVar4 + 0x44) & 3) != 3)
       ) {
      uVar3 = 4000;
    }
    else {
      uVar3 = *(undefined2 *)(iVar4 + 0x12);
    }
                    /* WARNING: Could not recover jumptable at 0x0001013a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0xc4))
              (iVar1,param_1 << 8 | 1,uVar3,*(code **)(_r_modules_funcs_p + 0xc4));
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00010158. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0xb8))(iVar1,*(code **)(_r_modules_funcs_p + 0xb8));
  return;
}

