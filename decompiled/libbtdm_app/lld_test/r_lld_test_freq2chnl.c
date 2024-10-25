/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_test.o -> r_lld_test_freq2chnl
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint r_lld_test_freq2chnl(uint param_1)

{
  if (param_1 == 0xc) {
    return 0x26;
  }
  if (param_1 != 0x27) {
    if (param_1 != 0) {
      if (param_1 < 0xc) {
        param_1 = param_1 - 1;
      }
      else {
        param_1 = param_1 - 2;
      }
      return param_1 & 0xff;
    }
    param_1 = 0x25;
  }
  return param_1;
}

