/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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

