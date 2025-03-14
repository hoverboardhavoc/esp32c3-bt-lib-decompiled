/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_evt_canceled_cbk_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_evt_canceled_cbk_eco(int param_1)

{
  int iVar1;
  uint uVar2;
  
  r_lld_con_evt_canceled_cbk();
  iVar1 = r_lld_read_clock();
  uVar2 = r_lld_con_count_get();
  if ((1 < uVar2) && (0x1900 < (uint)(iVar1 - DAT_00014a00))) {
    r_lld_update_con_offset();
    r_llc_con_conflict_check(*(undefined1 *)(param_1 + 0x8e));
    DAT_00014a00 = iVar1;
  }
  return;
}

