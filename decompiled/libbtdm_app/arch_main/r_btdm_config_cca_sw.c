/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> arch_main.o -> r_btdm_config_cca_sw
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_btdm_config_cca_sw(uint param_1,uint param_2,uint param_3)

{
  if (sdk_cfg_priv_opts == '\0') {
    return;
  }
  _DAT_60031360 =
       (param_1 & 1) << 0xb | _DAT_60031360 & 0xe00ff000 | param_2 & 0xf | (param_3 & 0x7f) << 4 |
       (param_1 & 1) << 0x1c | 0x4e00000;
  if (sdk_cfg_priv_opts != '\0') {
    if (param_1 == 0) {
      _DAT_6003100c = _DAT_6003100c & 0xfff7ffff;
    }
    else {
      _DAT_6003100c = _DAT_6003100c | 0x80000;
    }
  }
  return;
}

