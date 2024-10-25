/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> rwip_driver.o -> r_rwip_timer_10ms_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_timer_10ms_set(uint param_1)

{
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  if (param_1 == 0xffffffff) {
    _DAT_6003100c = _DAT_6003100c & 0xfffffdff;
    _r_plf_funcs_p = -1;
    if (DAT_00012055 != '\0') {
      _DAT_6003138c = 0x200;
    }
  }
  else {
    _r_plf_funcs_p = param_1 * 0x20;
    if ((param_1 & 0xff800000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"rwip_driver.c",0xc07,*(code **)(_r_plf_funcs_p + 8));
    }
    _DAT_60031018 = 0x200;
    if (DAT_00012055 != '\0') {
      _DAT_6003138c = 0x200;
    }
    _DAT_6003100c = _DAT_6003100c | 0x200;
    _DAT_600310e4 = param_1;
  }
                    /* WARNING: Could not recover jumptable at 0x00010d3e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

