/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> rwip_driver.o -> r_rwip_timer_hus_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_timer_hus_set(uint param_1,uint param_2)

{
  _rwip_env = param_1;
  if (param_1 == 0xffffffff) {
    _DAT_6003100c = _DAT_6003100c & 0xfffff7ff;
    if (DAT_00012061 != '\0') {
      _DAT_6003138c = 0x800;
    }
  }
  else {
    if (0x270 < param_2) {
      r_assert_param(param_2,0,"rwip_driver.c",0x4b7);
    }
    if ((param_1 & 0xf0000000) != 0) {
      r_assert_err(0,"rwip_driver.c",0xc5d);
    }
    _DAT_600310ec = param_1;
    if ((0x270 - param_2 & 0xfc00) != 0) {
      r_assert_err(0,"rwip_driver.c",0xc88);
    }
    _DAT_60031018 = 0x800;
    if (DAT_00012061 != '\0') {
      _DAT_6003138c = 0x800;
    }
    _DAT_6003100c = _DAT_6003100c & 0xfffff7ff | 0x800;
    _DAT_600310f0 = 0x270 - param_2 & 0xffff;
  }
  return;
}

