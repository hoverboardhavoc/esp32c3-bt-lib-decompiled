/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> nvds.o -> r_nvds_walk_tag
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_nvds_walk_tag(int param_1,char *param_2,uint *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  (*nvds_env)(3,param_2,nvds_env);
  uVar1 = 2;
  if (*param_2 != -1) {
    uVar1 = 0;
    uVar2 = (uint)(byte)param_2[2] + param_1 + 3;
    *param_3 = uVar2;
    if (DAT_00010700 - 1U < uVar2) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"nvds.c",0x199,*(code **)(_r_plf_funcs_p + 8));
      uVar1 = 6;
    }
  }
  return uVar1;
}

