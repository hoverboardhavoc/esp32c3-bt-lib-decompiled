/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> arch_main.o -> r_btdm_config_cca_sw
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_btdm_config_cca_sw(uint param_1,uint param_2,uint param_3)

{
  _DAT_60031360 =
       (param_3 & 0x7f) << 4 | _DAT_60031360 & 0xe00ff000 | param_2 & 0xf | (param_1 & 1) << 0x1c |
       0x4e00000;
  if (param_1 == 0) {
    _DAT_6003100c = _DAT_6003100c & 0xfff7ffff;
  }
  else {
    _DAT_6003100c = _DAT_6003100c | 0x80000;
  }
  return;
}

