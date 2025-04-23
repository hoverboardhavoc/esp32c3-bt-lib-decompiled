/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> co_list.o -> r_co_list_pop_front
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_co_list_pop_front(int *param_1)

{
  int iVar1;
  
  if (((int *)*param_1 != (int *)0x0) && (iVar1 = *(int *)*param_1, *param_1 = iVar1, iVar1 == 0)) {
    param_1[1] = 0;
  }
  return;
}

