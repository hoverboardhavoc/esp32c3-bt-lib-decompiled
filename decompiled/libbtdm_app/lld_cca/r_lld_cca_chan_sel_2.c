/*
 * Last changed at upstream commit 040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * https://github.com/espressif/esp32c3-bt-lib/commit/040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * Upstream date: 2023-08-03 10:45:08 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ff6efe7)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_chan_sel_2
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_lld_cca_chan_sel_2(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (**(code **)(_r_ip_funcs_p + 0x96c))(*(code **)(_r_ip_funcs_p + 0x96c));
  uVar2 = uVar1 % 0x25;
  if (((int)(uint)*(byte *)((uVar2 >> 3) + param_1) >> (uVar2 & 7) & 1U) == 0) {
                    /* WARNING: Could not recover jumptable at 0x000101f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(_r_ip_funcs_p + 0x958))(param_1,param_2 * uVar1 >> 0x10 & 0xff);
    return uVar1;
  }
  return uVar2;
}

