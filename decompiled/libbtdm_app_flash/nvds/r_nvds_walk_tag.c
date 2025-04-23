/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> nvds.o -> r_nvds_walk_tag
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

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
    if (DAT_000106a8 - 1U < uVar2) {
      r_assert_err(0,"nvds.c",0x199);
      uVar1 = 6;
    }
  }
  return uVar1;
}

