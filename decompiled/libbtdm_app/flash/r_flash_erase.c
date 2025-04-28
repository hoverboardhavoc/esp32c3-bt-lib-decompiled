/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> flash.o -> r_flash_erase
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_flash_erase(uint param_1,int param_2,size_t param_3)

{
  if (sdk_cfg_priv_opts == '\0') {
    return 0x1f;
  }
  if ((DAT_0001026c == param_1) && (param_2 + param_3 < DAT_00010268)) {
    memset((void *)(flash_env + param_2),0xff,param_3);
    return 0;
  }
  return 0x12;
}

