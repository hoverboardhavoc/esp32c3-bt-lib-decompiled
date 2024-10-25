/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> nvds.o -> r_nvds_read
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_nvds_read(int param_1,int param_2,undefined4 param_3)

{
  if (DAT_00010688 < (uint)(param_1 + param_2)) {
    r_assert_err(0,"nvds.c",0x1d4,param_3);
  }
  r_flash_read(DAT_0001068c,DAT_00010684 + param_1,param_2,param_3,0);
  return;
}

