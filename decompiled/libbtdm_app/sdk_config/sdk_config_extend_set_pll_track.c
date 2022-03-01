/*
 * Last changed at upstream commit 98dcc9591365b5ac486a9f0b474c36bf8c4ca97b
 * https://github.com/espressif/esp32c3-bt-lib/commit/98dcc9591365b5ac486a9f0b474c36bf8c4ca97b
 * Upstream date: 2022-03-01 14:41:26 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (d913766) Add the pll track feature to keep the ble connection stable when the environment temprature increase form 0 to 74.
 * Source: libbtdm_app -> sdk_config.o -> sdk_config_extend_set_pll_track
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void sdk_config_extend_set_pll_track(undefined1 param_1)

{
  sdk_cfg_priv_opts_extend = param_1;
  return;
}

