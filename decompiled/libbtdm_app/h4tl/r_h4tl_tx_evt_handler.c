/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
  bool bVar1;
  bool bVar2;
  int iVar3;
  
  (**(code **)(_r_modules_funcs_p + 0xec))(8,*(code **)(_r_modules_funcs_p + 0xec));
  bVar1 = false;
  bVar2 = false;
  while ((!bVar1 && (DAT_00011040 != 0xff))) {
    iVar3 = (uint)DAT_00011040 * 0xc;
    if (*(int *)(&DAT_00011034 + iVar3) != 0) {
      return;
    }
    if (*(code **)(&DAT_00011038 + iVar3) != (code *)0x0) {
      (**(code **)(&DAT_00011038 + iVar3))();
    }
    DAT_00011040 = 0xff;
    if ((!bVar1) && (_DAT_00011034 != 0)) {
      DAT_00011040 = -(DAT_0001103e == '\0');
    }
    bVar1 = true;
    if (DAT_00011040 != 0xff) {
      (**(code **)(_h4tl_env + 4))
                (_DAT_0001103c + 1,*(undefined4 *)(_r_modules_funcs_p + 0x94),&h4tl_env,
                 *(code **)(_h4tl_env + 4));
      bVar1 = true;
      bVar2 = true;
    }
  }
  if (bVar2) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000102b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x2b0))(2,*(code **)(_r_modules_funcs_p + 0x2b0));
  return;
}

