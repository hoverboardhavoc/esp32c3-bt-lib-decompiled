/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> co_utils.o -> r_co_bdaddr_compare
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_co_bdaddr_compare(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(char *)(param_1 + iVar1) != *(char *)(param_2 + iVar1)) {
      return 0;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 6);
  return 1;
}

