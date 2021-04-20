/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> bt_rw_v9.o -> rw_rf_le_exit_test_mode
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rw_rf_le_exit_test_mode(void)

{
  _DAT_600310f8 = _DAT_600310f8 & 0xfffff7ff;
  if (2 < _g_bt_plf_log_level) {
    ets_printf("clear <reg_force_usecswinsz> for phasematchp reg\n");
  }
  _DAT_60031098 = _DAT_60031098 & 0xff00ffff | 0x20000;
  _DAT_6003109c = _DAT_6003109c & 0xff80ffff | 0x20000;
  if (2 < _g_bt_plf_log_level) {
    ets_printf("set rfrxtmda2 %d, set rfrxtmda3 %d\n",2,2);
    return;
  }
  return;
}

