/*
 * Last changed at upstream commit d4922c5890feb6ee1733e6063369ff54a30f5930
 * https://github.com/espressif/esp32c3-bt-lib/commit/d4922c5890feb6ee1733e6063369ff54a30f5930
 * Upstream date: 2024-07-23 16:16:25 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(4e58df9)
 * Source: libbtdm_app -> lld.o -> lld_le_pkt_err_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 lld_le_pkt_err_get(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = CONCAT22(*(undefined2 *)(&lld_le_pkt_env + param_1),
                        *(undefined2 *)((int)&lld_le_pkt_env + param_1 * 4 + 2));
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  return 0;
}

