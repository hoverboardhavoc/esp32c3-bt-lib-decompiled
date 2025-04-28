/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> flash.o -> r_flash_identify
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_flash_identify(undefined1 *param_1)

{
  if (sdk_cfg_priv_opts != '\0') {
    *flash_env = 0x34;
    flash_env[1] = 0x12;
    flash_env[2] = 0xff;
    flash_env[3] = 0xff;
    DAT_0001021c = 4;
    DAT_00010218 = 0x800;
    *param_1 = 4;
    return 0;
  }
  return 0x1f;
}

