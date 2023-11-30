/*
 * Last changed at upstream commit a075a8fde411bdd92973051edf2cd234601b259c
 * https://github.com/espressif/esp32c3-bt-lib/commit/a075a8fde411bdd92973051edf2cd234601b259c
 * Upstream date: 2023-11-30 21:15:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(70ab55f)
 * Source: libbtdm_app -> lld.o -> lld_wl_res_rem
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lld_wl_res_rem(uint param_1)

{
  if (0xb < param_1) {
    (**(code **)(_r_plf_funcs_p + 0xc))(0,"lld.c",0x3ac,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if ((&lld_wl_res_list)[param_1] != 0) {
    (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
    (&lld_wl_res_list)[param_1] = 0;
  }
  return;
}

