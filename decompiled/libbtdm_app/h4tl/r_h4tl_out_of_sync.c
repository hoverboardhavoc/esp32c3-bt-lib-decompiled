/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> h4tl.o -> r_h4tl_out_of_sync
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_h4tl_out_of_sync(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1103,0,0x10,1,*(code **)(_r_modules_funcs_p + 200));
  *puVar1 = 0;
  (**(code **)(_r_ip_funcs_p + 0x8c))(*(code **)(_r_ip_funcs_p + 0x8c));
  memset((void *)(param_1 + 10),0,8);
  *(undefined1 *)(param_1 + 0x12) = *(undefined1 *)(param_1 + 0x13);
  (**(code **)(_r_modules_funcs_p + 0x70))(param_1,*(code **)(_r_modules_funcs_p + 0x70));
                    /* WARNING: Could not recover jumptable at 0x0001014c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x2b0))(4);
  return;
}

