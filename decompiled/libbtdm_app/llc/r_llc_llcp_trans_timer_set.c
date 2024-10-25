/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc.o -> r_llc_llcp_trans_timer_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_llcp_trans_timer_set(uint param_1,int param_2,int param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  
  uVar2 = param_1 << 8 | 1;
  iVar1 = (param_2 != 0) + 0x100;
  if (param_3 != 0) {
    iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (((param_1 < *(byte *)(iVar3 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
       ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
      uVar4 = 4000;
      UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0xc4);
    }
    else {
      uVar4 = *(undefined2 *)(*(int *)(&llc_env + param_1 * 4) + 0x12);
      UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0xc4);
    }
                    /* WARNING: Could not recover jumptable at 0x0001013a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(iVar1,uVar2,uVar4);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00010164. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0xb8))(iVar1,uVar2);
  return;
}

