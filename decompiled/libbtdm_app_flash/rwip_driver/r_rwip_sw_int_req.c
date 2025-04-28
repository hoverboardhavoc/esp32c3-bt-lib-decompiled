/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> rwip_driver.o -> r_rwip_sw_int_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_sw_int_req(void)

{
  _DAT_60031018 = 0x1000;
  if (sdk_cfg_priv_opts != '\0') {
    _DAT_6003138c = 0x1000;
  }
  _DAT_6003100c = _DAT_6003100c & 0xffffefff | 0x1000;
  _DAT_60031000 = _DAT_60031000 & 0xf7ffffff | 0x8000000;
  return;
}

