/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
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
                    /* WARNING: Could not recover jumptable at 0x000132fa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x108))(0xe,*(code **)(_r_modules_funcs_p + 0x108));
  return;
}

