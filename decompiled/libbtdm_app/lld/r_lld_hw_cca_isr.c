/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld.o -> r_lld_hw_cca_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_hw_cca_isr(undefined1 param_1,int param_2,undefined1 param_3)

{
  int iVar1;
  
  iVar1 = _p_lld_env;
  *(undefined1 *)(_p_lld_env + 0x104) = param_1;
  *(char *)(iVar1 + 0x105) = (char)param_2;
  *(undefined1 *)(*(int *)(iVar1 + 0x114) + param_2) = param_3;
                    /* WARNING: Could not recover jumptable at 0x00013348. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x108))(0xe,*(code **)(_r_modules_funcs_p + 0x108));
  return;
}

