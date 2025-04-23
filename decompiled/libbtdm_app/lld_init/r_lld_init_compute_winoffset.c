/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_init.o -> r_lld_init_compute_winoffset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_lld_init_compute_winoffset(int param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 * 4;
  if (param_1 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0x10000,0x94,*(code **)(_r_plf_funcs_p + 8));
  }
  uVar1 = (param_2 * 2 + uVar2) - param_4 % uVar2;
  if (uVar1 < param_3 * 4 + 8U) {
    uVar1 = uVar1 + uVar2;
  }
  return (uVar1 >> 2) - param_3 & 0xffff;
}

