/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> co_utils.o -> r_co_ble_pkt_dur_in_us
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_co_ble_pkt_dur_in_us(int param_1,int param_2)

{
  if (param_2 == 1) {
    return (param_1 + 0xb) * 4;
  }
  if (param_2 == 0) {
    return (param_1 + 10) * 8;
  }
  if (param_2 == 2) {
    return param_1 * 0x40 + 0x2d0;
  }
  if (param_2 != 3) {
    (**(code **)(_r_plf_funcs_p + 0xc))("co_utils.c",0x286,*(code **)(_r_plf_funcs_p + 0xc));
    return 0;
  }
  return param_1 * 0x10 + 0x1ce;
}

