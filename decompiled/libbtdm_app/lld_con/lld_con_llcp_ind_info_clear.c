/*
 * Last changed at upstream commit 420ae1726dede6bbd4f3393744a8f3a252330b6a
 * https://github.com/espressif/esp32c3-bt-lib/commit/420ae1726dede6bbd4f3393744a8f3a252330b6a
 * Upstream date: 2022-09-16 21:21:40 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(421c2790)
 * Source: libbtdm_app -> lld_con.o -> lld_con_llcp_ind_info_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void lld_con_llcp_ind_info_clear(int param_1)

{
  *(undefined2 *)(llcp_ind_info + param_1 * 2) = 0;
  return;
}

