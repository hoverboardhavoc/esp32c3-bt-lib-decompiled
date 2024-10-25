/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> misc.o -> r_misc_free_em_buf_in_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_misc_free_em_buf_in_isr(undefined1 param_1,undefined2 param_2)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x901,4,0xff,4,*(code **)(_r_modules_funcs_p + 200));
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = param_1;
    iVar1 = _r_modules_funcs_p;
    *(undefined2 *)(puVar2 + 2) = param_2;
                    /* WARNING: Could not recover jumptable at 0x000100a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(iVar1 + 0xe0))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000100cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 8))("misc.c",0xa3);
  return;
}

