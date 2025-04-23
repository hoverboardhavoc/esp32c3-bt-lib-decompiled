/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
  if ((DAT_0001025c == param_1) && (param_2 + param_3 < DAT_00010258)) {
    memset((void *)(flash_env + param_2),0xff,param_3);
    return 0;
  }
  return 0x12;
}

