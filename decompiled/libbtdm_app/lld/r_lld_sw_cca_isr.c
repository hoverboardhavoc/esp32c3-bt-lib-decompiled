/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld.o -> r_lld_sw_cca_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sw_cca_isr(undefined1 param_1,undefined1 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = _p_lld_env;
  if (param_3 == 0) {
    *(undefined1 *)(_p_lld_env + 0x104) = param_1;
    *(undefined1 *)(iVar1 + 0x105) = param_2;
  }
                    /* WARNING: Could not recover jumptable at 0x0001313e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x108))(0xd);
  return;
}

