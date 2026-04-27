/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_rpa_renew_evt_start_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_rpa_renew_evt_start_cbk(int param_1)

{
  int iVar1;
  
  if (_lld_rpa_renew_env != 0) {
    iVar1 = r_lld_read_clock();
    _DAT_60031000 = _DAT_60031000 & 0xfcffffff | 0x3000000;
    *(uint *)(param_1 + 0x28) = (uint)rwip_prog_delay + iVar1 & 0xfffffff;
    *(code **)(param_1 + 0x2c) = r_lld_rpa_renew_instant_cbk;
    r_ble_log_internal_x1(0x202800cb);
    r_sch_alarm_set(param_1 + 0x24);
    return;
  }
  r_assert_err(0,"lld.c",0x490);
  return;
}

