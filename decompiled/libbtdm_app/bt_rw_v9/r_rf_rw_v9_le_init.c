/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> bt_rw_v9.o -> r_rf_rw_v9_le_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rf_rw_v9_le_init(void)

{
  _DAT_60031080 = _DAT_60031080 & 0xff00ff00 | 0x640064;
  _DAT_60031084 = _DAT_60031084 & 0xff00ff00 | 0x640064;
  _DAT_60031088 = _DAT_60031088 & 0xff00ff00 | 0x640064;
  _DAT_6003108c = _DAT_6003108c & 0xff00ff00 | 0x640064;
  _DAT_60031090 = _DAT_60031090 & 0xffffff80 | 0xd;
  _DAT_60031000 = _DAT_60031000 | 0xf;
  _DAT_600310e0 = _DAT_600310e0 & 0xfc00fe00 | 0x1be00fa;
  _DAT_60031070 = 0;
  _DAT_60031074 = _DAT_60031074 & 0xffffdfff | 0x1020;
  _DAT_60031078 = 0xcc10100;
  _DAT_60031094 = 0x20202;
  _DAT_60031098 = 0xf020202;
  _DAT_6003109c = 0xf020202;
  _DAT_60011050 = (100 - (uint)sdk_cfg_priv_opts) * 8 & 0x7f8 | _DAT_60011050 & 0xfffff800;
  return;
}

