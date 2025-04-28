/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> h4tl.o -> r_h4tl_tx_evt_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_h4tl_tx_evt_handler(void)

{
  int iVar1;
  
  (**(code **)(_r_modules_funcs_p + 0xec))(8,*(code **)(_r_modules_funcs_p + 0xec));
  if (DAT_00011040 != 0xff) {
    iVar1 = (uint)DAT_00011040 * 0xc;
    if (*(int *)(&DAT_00011034 + iVar1) != 0) {
      return;
    }
    if (*(code **)(&DAT_00011038 + iVar1) != (code *)0x0) {
      (**(code **)(&DAT_00011038 + iVar1))();
    }
    DAT_00011040 = 0xff;
    if (_DAT_00011034 != 0) {
      DAT_00011040 = -(DAT_0001103e == '\0');
    }
    if (DAT_00011040 != 0xff) {
                    /* WARNING: Could not recover jumptable at 0x000102de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_h4tl_env + 4))
                (_DAT_0001103c + 1,*(undefined4 *)(_r_modules_funcs_p + 0x94),&h4tl_env,
                 *(code **)(_h4tl_env + 4));
      return;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x000102f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x2b0))(2,*(code **)(_r_modules_funcs_p + 0x2b0));
  return;
}

