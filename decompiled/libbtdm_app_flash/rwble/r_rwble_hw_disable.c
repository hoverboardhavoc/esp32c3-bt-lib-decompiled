/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> rwble.o -> r_rwble_hw_disable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwble_hw_disable(int param_1)

{
  if (param_1 == 2) {
    _DAT_60031000 = _DAT_60031000 & 0xfffffeff | 0x80000000;
    do {
    } while ((int)_DAT_60031000 < 0);
    _DAT_6003100c = 0;
    _DAT_60031018 = 0xffffffff;
    if (sdk_cfg_priv_opts != '\0') {
      _DAT_600312d8 = _DAT_600312d8 | 0x80000000;
    }
  }
  return;
}

