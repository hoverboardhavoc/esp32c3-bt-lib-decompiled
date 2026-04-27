/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_evt_canceled_cbk_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_evt_canceled_cbk_eco(int param_1)

{
  int iVar1;
  uint uVar2;
  
  r_lld_con_evt_canceled_cbk_hack();
  iVar1 = r_lld_read_clock();
  uVar2 = r_lld_con_count_get();
  if ((1 < uVar2) && (0x1900 < (uint)(iVar1 - _DAT_00015694))) {
    r_lld_update_con_offset();
    r_llc_con_conflict_check(*(undefined1 *)(param_1 + 0x8e));
    _DAT_00015694 = iVar1;
  }
  return;
}

