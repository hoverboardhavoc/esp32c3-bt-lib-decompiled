/*
 * Last changed at upstream commit 0caae2bd70a999ac8a1c07330f7168e185db81ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/0caae2bd70a999ac8a1c07330f7168e185db81ba
 * Upstream date: 2024-01-31 19:37:46 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(91980c2)
 * Source: libbtdm_app -> rwip_driver.o -> r_rwip_wakeup_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_wakeup_hack(void)

{
  r_rwip_wakeup();
  _DAT_6003100c = 0x600009;
  return;
}

