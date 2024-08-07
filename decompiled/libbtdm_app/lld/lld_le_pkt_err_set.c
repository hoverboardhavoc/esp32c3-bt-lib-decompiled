/*
 * Last changed at upstream commit ef1dfc518572e9cda55f13906e32207b40ee280b
 * https://github.com/espressif/esp32c3-bt-lib/commit/ef1dfc518572e9cda55f13906e32207b40ee280b
 * Upstream date: 2024-08-07 12:57:51 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(f583012)
 * Source: libbtdm_app -> lld.o -> lld_le_pkt_err_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lld_le_pkt_err_set(uint param_1,uint param_2)

{
  if (9 < param_1) {
    (**(code **)(_r_plf_funcs_p + 0xc))(10,"lld.c",699,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if ((param_2 & 0xf) != 0) {
    if ((param_2 & 1) != 0) {
      *(short *)(&lld_le_pkt_env + param_1) = *(short *)(&lld_le_pkt_env + param_1) + 1;
    }
    if ((param_2 & 8) != 0) {
      *(short *)((int)&lld_le_pkt_env + param_1 * 4 + 2) =
           *(short *)((int)&lld_le_pkt_env + param_1 * 4 + 2) + 1;
    }
  }
  return;
}

