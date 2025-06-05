/*
 * Last changed at upstream commit 3ff529142f6e2707d57b10eb87ac8d86e9098b88
 * https://github.com/espressif/esp32c3-bt-lib/commit/3ff529142f6e2707d57b10eb87ac8d86e9098b88
 * Upstream date: 2025-06-05 11:04:06 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(4713a69)
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
                    /* WARNING: Could not recover jumptable at 0x00010294. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(_r_plf_funcs_p + 0x104))
                      (0xd,param_1 & 0xff,param_2,0,1,*(code **)(_r_plf_funcs_p + 0x104));
    return uVar1;
  }
  return 0xffffffff;
}

