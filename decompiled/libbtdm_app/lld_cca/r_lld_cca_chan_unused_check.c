/*
 * Last changed at upstream commit 040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * https://github.com/espressif/esp32c3-bt-lib/commit/040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * Upstream date: 2023-08-03 10:45:08 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ff6efe7)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_chan_unused_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_cca_chan_unused_check(byte *param_1)

{
  byte *pbVar1;
  
  if (param_1[8] == *(byte *)(p_lld_cca + 0x1a)) {
    pbVar1 = (byte *)(*(int *)(p_lld_cca + 0x1c) + (uint)(*(byte *)(p_lld_cca + 8) >> 3));
    *pbVar1 = ~(byte)(1 << (*(byte *)(p_lld_cca + 8) & 7)) & *pbVar1;
    param_1[8] = 0;
    *param_1 = *param_1 | 4;
  }
  return;
}

