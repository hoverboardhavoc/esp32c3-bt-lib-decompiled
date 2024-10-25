/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
    r_assert_err(0,"ke_task.c",0x12e);
  }
  return *(undefined4 *)(puVar1 + 2);
}

