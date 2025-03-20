/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app -> llc.o -> r_llc_proc_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_llc_proc_get(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(&llc_env + param_1 * 4);
  if (1 < param_2) {
    (**(code **)(_r_plf_funcs_p + 0xc))("llc.c",0x213,*(code **)(_r_plf_funcs_p + 0xc));
  }
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + param_2 * 4);
  }
  return uVar2;
}

