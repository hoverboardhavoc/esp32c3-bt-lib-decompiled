/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
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
  int iVar2;
  
  iVar1 = _p_lld_env;
  iVar2 = *(int *)(_p_lld_env + 0x114);
  *(undefined1 *)(_p_lld_env + 0x104) = param_1;
  *(char *)(iVar1 + 0x105) = (char)param_2;
  *(undefined1 *)(iVar2 + param_2) = param_3;
                    /* WARNING: Could not recover jumptable at 0x000132a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x108))(0xe);
  return;
}

