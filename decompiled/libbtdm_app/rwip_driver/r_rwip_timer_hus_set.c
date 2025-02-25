/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app -> rwip_driver.o -> r_rwip_timer_hus_set
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
    if (DAT_00012055 != '\0') {
      _DAT_6003138c = 0x800;
    }
  }
  else {
    if (0x270 < param_2) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (param_2,0,"rwip_driver.c",0x4bb,*(code **)(_r_plf_funcs_p + 0xc));
    }
    if ((param_1 & 0xf0000000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"rwip_driver.c",0xc5d,*(code **)(_r_plf_funcs_p + 8));
    }
    _DAT_600310ec = param_1;
    if ((0x270 - param_2 & 0xfc00) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"rwip_driver.c",0xc88,*(code **)(_r_plf_funcs_p + 8));
    }
    _DAT_60031018 = 0x800;
    if (DAT_00012055 != '\0') {
      _DAT_6003138c = 0x800;
    }
    _DAT_6003100c = _DAT_6003100c & 0xfffff7ff | 0x800;
    _DAT_600310f0 = 0x270 - param_2 & 0xffff;
  }
  return;
}

