/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
                    /* WARNING: Could not recover jumptable at 0x00010254. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar1 + 0x108))(8,*(code **)(iVar1 + 0x108));
  return;
}

