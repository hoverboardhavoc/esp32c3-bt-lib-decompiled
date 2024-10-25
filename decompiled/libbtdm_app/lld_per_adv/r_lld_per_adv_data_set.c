/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_per_adv.o -> r_lld_per_adv_data_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_data_set
               (int param_1,undefined2 param_2,undefined2 param_3,int param_4,int param_5)

{
  short sVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  int iVar3;
  
  iVar3 = *(int *)(&lld_per_adv_env + param_1 * 4);
  sVar1 = 0;
  if (param_4 != 0) {
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    sVar1 = *(short *)(iVar2 + (param_1 * 9 & 0xffU) * 0xe + 4);
  }
  iVar2 = _r_ip_funcs_p;
  *(undefined2 *)(iVar3 + 0x50) = param_2;
  UNRECOVERED_JUMPTABLE = *(code **)(iVar2 + 0x2c4);
  *(undefined2 *)(iVar3 + 0x4e) = param_3;
  (*UNRECOVERED_JUMPTABLE)(*(undefined1 *)(iVar3 + 0x52),UNRECOVERED_JUMPTABLE);
  if ((param_4 != 0) && (sVar1 != 0)) {
    if (param_5 == 0) {
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0xd8);
    }
    else {
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0xdc);
    }
                    /* WARNING: Could not recover jumptable at 0x00010e84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(sVar1);
    return;
  }
  return;
}

