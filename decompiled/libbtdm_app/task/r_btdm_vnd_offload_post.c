/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> task.o -> r_btdm_vnd_offload_post
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_btdm_vnd_offload_post(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 < 2) {
                    /* WARNING: Could not recover jumptable at 0x00010286. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(_r_plf_funcs_p + 0x104))
                      (0xd,param_1 & 0xff,param_2,0,*(code **)(_r_plf_funcs_p + 0x104));
    return uVar1;
  }
  return 0xffffffff;
}

