/*
 * Last changed at upstream commit 70f95a1b6f8f232018b17c687cc819044501774c
 * https://github.com/espressif/esp32c3-bt-lib/commit/70f95a1b6f8f232018b17c687cc819044501774c
 * Upstream date: 2024-04-02 18:59:02 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(5274796)
 * Source: libbtdm_app -> sdk_config.o -> sdk_config_set_opts_ext
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void sdk_config_set_opts_ext(void *param_1)

{
  memcpy(&_LANCHOR3,param_1,0x20);
  return;
}

