/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> h4tl.o -> r_h4tl_tx_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_h4tl_tx_done(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"h4tl.c",0x1e8,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar1 = _r_modules_funcs_p;
  *(undefined4 *)(param_1 + (uint)*(byte *)(param_1 + 0x24) * 0xc + 0x18) = 0;
                    /* WARNING: Could not recover jumptable at 0x0001024e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar1 + 0x108))(8);
  return;
}

