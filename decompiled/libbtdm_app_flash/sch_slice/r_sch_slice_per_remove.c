/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> sch_slice.o -> r_sch_slice_per_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_slice_per_remove(int param_1,uint param_2)

{
  if (param_1 - 3U < 2) {
    _r_sdk_config_get_opts = ~(1 << (param_2 & 0x1f)) & _r_sdk_config_get_opts;
    *(undefined4 *)(r_assert_err + param_2 * 8) = 0;
  }
  else {
    r_assert_err(0,"sch_slice.c",0x248);
  }
  r_sch_slice_compute();
  return;
}

