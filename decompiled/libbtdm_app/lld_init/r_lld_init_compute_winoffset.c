/*
 * Last changed at upstream commit a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * https://github.com/espressif/esp32c3-bt-lib/commit/a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * Upstream date: 2021-12-28 18:10:18 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (33175c8)
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
  
  uVar1 = param_1 * 4;
  if (uVar1 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x94,*(code **)(_r_plf_funcs_p + 8));
  }
  uVar2 = (param_2 * 2 + uVar1) - param_4 % uVar1;
  if (uVar2 < param_3 * 4 + 8U) {
    uVar2 = uVar2 + uVar1;
  }
  return (uVar2 >> 2) - param_3 & 0xffff;
}

