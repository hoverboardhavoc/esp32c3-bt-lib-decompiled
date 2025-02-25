/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> ke_task.o -> r_ke_handler_search
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

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
    r_assert_err(0,"ke_task.c",0x135);
  }
  return *(undefined4 *)(puVar1 + 2);
}

