/*
 * Last changed at upstream commit 2c453f09b7d1102ef496278d2cd2be96ff1ea071
 * https://github.com/espressif/esp32c3-bt-lib/commit/2c453f09b7d1102ef496278d2cd2be96ff1ea071
 * Upstream date: 2021-04-28 17:55:23 +0800
 * Upstream subject: update ESP32C3/ESP32S3 libbtbb.a
 * Source: libbtbb -> bt_bb_v2.o -> bt_bb_v2_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bt_bb_v2_version(void)

{
  ets_printf("libbtbb version: %s, %s, %s\n","cdc7508","Apr 26 2021","14:28:20");
  return;
}

