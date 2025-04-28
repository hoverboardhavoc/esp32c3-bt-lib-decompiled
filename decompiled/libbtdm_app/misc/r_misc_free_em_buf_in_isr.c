/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
                    /* WARNING: Could not recover jumptable at 0x000100b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(iVar1 + 0xe0))(*(code **)(iVar1 + 0xe0));
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000100d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 8))("misc.c",0xa3,*(code **)(_r_plf_funcs_p + 8));
  return;
}

