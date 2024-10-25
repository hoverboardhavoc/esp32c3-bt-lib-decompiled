/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> sch_slice.o -> r_sch_slice_fg_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_slice_fg_add(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  sch_slice_env = (byte)(1 << (param_1 & 0x1f)) | sch_slice_env;
  uVar1 = param_2;
  if (param_1 != 2) {
    r_assert_err(0,"sch_slice.c",0x1b4);
    uVar1 = _sch_slice_params;
  }
  _sch_slice_params = uVar1;
  r_sch_slice_compute();
  return;
}

