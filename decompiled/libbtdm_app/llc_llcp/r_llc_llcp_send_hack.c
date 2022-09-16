/*
 * Last changed at upstream commit 420ae1726dede6bbd4f3393744a8f3a252330b6a
 * https://github.com/espressif/esp32c3-bt-lib/commit/420ae1726dede6bbd4f3393744a8f3a252330b6a
 * Upstream date: 2022-09-16 21:21:40 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(421c2790)
 * Source: libbtdm_app -> llc_llcp.o -> r_llc_llcp_send_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_llcp_send_hack(char *param_1,undefined4 param_2)

{
  if (*param_1 == '\x01') {
    param_2 = 0x10000;
  }
  r_llc_llcp_send(param_2);
  return;
}

