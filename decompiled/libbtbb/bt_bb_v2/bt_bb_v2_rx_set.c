/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtbb -> bt_bb_v2.o -> bt_bb_v2_rx_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bt_bb_v2_rx_set(uint param_1)

{
  _DAT_60026010 = _DAT_60026010 | 0xf000f;
  _DAT_60011008 = (param_1 & 0x3f) << 0x17 | _DAT_60011008 & 0xe07fffff;
  bt_bb_corr_set();
  bt_bb_dpo_set();
  bt_bb_restart_set();
  bt_bb_target_set();
  bt_bb_detect_set();
  bt_bb_gain_set();
  bt_bb_v2_rx_rssi_thresh(0xffffff9c,0xffffff92);
  bt_bb_v2_recorrect();
  _DAT_60033c18 = _DAT_60033c18 & 0x7fffffff;
  _DAT_60011888 = _DAT_60011888 & 0xdffbffff;
  return;
}

