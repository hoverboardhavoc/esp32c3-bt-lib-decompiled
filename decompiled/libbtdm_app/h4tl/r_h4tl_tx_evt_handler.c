/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  if (DAT_0001103c != 0xff) {
    iVar1 = (uint)DAT_0001103c * 0xc;
    if (*(int *)(&DAT_00011030 + iVar1) != 0) {
      return;
    }
    if (*(code **)(&DAT_00011034 + iVar1) != (code *)0x0) {
      (**(code **)(&DAT_00011034 + iVar1))();
    }
    if ((_DAT_00011030 != 0) && (DAT_0001103a != '\0')) {
      DAT_0001103c = 0;
                    /* WARNING: Could not recover jumptable at 0x000102c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_h4tl_env + 4))
                (_DAT_00011038 + 1,*(undefined4 *)(_r_modules_funcs_p + 0x94),&h4tl_env);
      return;
    }
    DAT_0001103c = 0xff;
  }
                    /* WARNING: Could not recover jumptable at 0x000102e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x2b0))(2);
  return;
}

