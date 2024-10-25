/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_disconnect.o -> r_llc_init_term_proc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_init_term_proc(int param_1,undefined1 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x108,param_1 << 8 | 1,0xc,*(code **)(_r_modules_funcs_p + 200));
  *(undefined1 *)(puVar1 + 1) = 1;
  (**(code **)(_r_ip_funcs_p + 0x684))(param_1,0,*(code **)(_r_ip_funcs_p + 0x684));
  uVar2 = *(undefined4 *)(_r_ip_funcs_p + 0x568);
  *(undefined1 *)(puVar1 + 2) = param_2;
  *(undefined1 *)((int)puVar1 + 9) = param_2;
  *puVar1 = uVar2;
                    /* WARNING: Could not recover jumptable at 0x000106c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0xe0))(puVar1);
  return;
}

