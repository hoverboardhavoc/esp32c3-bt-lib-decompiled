/*
 * Last changed at upstream commit 2c453f09b7d1102ef496278d2cd2be96ff1ea071
 * https://github.com/espressif/esp32c3-bt-lib/commit/2c453f09b7d1102ef496278d2cd2be96ff1ea071
 * Upstream date: 2021-04-28 17:55:23 +0800
 * Upstream subject: update ESP32C3/ESP32S3 libbtbb.a
 * Source: libbtbb -> bt_bb_v2.o -> bt_bb_v2_init_cmplx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bt_bb_v2_init_cmplx(int param_1)

{
  _DAT_6000e0c4 = _DAT_6000e0c4 | 0x2000000;
  bt_bb_v2_tx_set(0);
  bt_bb_v2_rx_set(4);
  _DAT_600060fc = _DAT_600060fc & 0xffff00ff | 0xc800;
  _DAT_6000e0c4 = _DAT_6000e0c4 & 0xfdffffff;
  if (param_1 == 0) {
    return;
  }
  ets_printf("libbtbb version: %s, %s, %s\n","cdc7508","Apr 26 2021","14:28:20");
  return;
}

