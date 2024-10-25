/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> ke_msg.o -> r_ke_msg_forward
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_msg_forward(int param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  
  iVar1 = _r_modules_funcs_p;
  *(undefined2 *)(param_1 + -6) = param_2;
  *(undefined2 *)(param_1 + -4) = param_3;
                    /* WARNING: Could not recover jumptable at 0x00010102. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar1 + 0xe0))();
  return;
}

