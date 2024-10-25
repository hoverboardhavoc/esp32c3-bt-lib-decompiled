/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> sch_slice.o -> r_sch_slice_per_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_slice_per_add(int param_1,uint param_2,undefined4 param_3,undefined2 param_4)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 - 3U < 2) {
    *(undefined4 *)(memset + param_2 * 8) = param_3;
    iVar1 = _r_ip_funcs_p;
    _r_plf_funcs_p = 1 << (param_2 & 0x1f) | _r_plf_funcs_p;
    *(undefined2 *)(&rwip_param + param_2 * 8) = param_4;
    UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x71c);
  }
  else {
    (**(code **)(_r_plf_funcs_p + 8))(0,"sch_slice.c",0x21d,*(code **)(_r_plf_funcs_p + 8));
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x71c);
  }
                    /* WARNING: Could not recover jumptable at 0x0001030e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

