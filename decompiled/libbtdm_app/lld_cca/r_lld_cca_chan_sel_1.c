/*
 * Last changed at upstream commit 040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * https://github.com/espressif/esp32c3-bt-lib/commit/040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * Upstream date: 2023-08-03 10:45:08 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ff6efe7)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_chan_sel_1
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_chan_sel_1(int param_1,int param_2,int param_3,int param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = ((param_3 + 1) * param_2 + param_1) % 0x25;
  uVar1 = uVar2 & 0xff;
  if (((int)(uint)*(byte *)((uVar1 >> 3) + param_4) >> (uVar2 & 7) & 1U) == 0) {
                    /* WARNING: Could not recover jumptable at 0x00010190. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x958))(param_4,uVar1 % param_5);
    return;
  }
  return;
}

