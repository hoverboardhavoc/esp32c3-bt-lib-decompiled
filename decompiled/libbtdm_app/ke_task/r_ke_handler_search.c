/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app -> ke_task.o -> r_ke_handler_search
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_ke_handler_search(uint param_1,int param_2,int param_3)

{
  ushort *puVar1;
  
  param_3 = param_3 + -1;
  if (param_3 == -1) {
    return 0;
  }
  while( true ) {
    puVar1 = (ushort *)(param_3 * 8 + param_2);
    if ((*puVar1 == param_1) || (*puVar1 == 0xffff)) break;
    param_3 = param_3 + -1;
    if (param_3 == -1) {
      return 0;
    }
  }
  if (*(int *)(puVar1 + 2) == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"ke_task.c",0x135,*(code **)(_r_plf_funcs_p + 8));
  }
  return *(undefined4 *)(puVar1 + 2);
}

