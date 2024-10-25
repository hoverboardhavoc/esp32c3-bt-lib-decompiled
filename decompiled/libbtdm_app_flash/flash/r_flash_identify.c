/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> flash.o -> r_flash_identify
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_flash_identify(undefined1 *param_1)

{
  if (sdk_cfg_priv_opts != '\0') {
    *_LANCHOR0 = 0x34;
    _LANCHOR0[1] = 0x12;
    _LANCHOR0[2] = 0xff;
    _LANCHOR0[3] = 0xff;
    DAT_00010218 = 4;
    DAT_00010214 = 0x800;
    *param_1 = 4;
    return 0;
  }
  return 0x1f;
}

