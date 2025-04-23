/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_chan_sel_2
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_chan_sel_2(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = (**(code **)(_r_ip_funcs_p + 0x96c))(*(code **)(_r_ip_funcs_p + 0x96c));
  if (((int)(uint)*(byte *)((uVar1 % 0x25 >> 3) + param_1) >> (uVar1 % 0x25 & 7) & 1U) == 0) {
                    /* WARNING: Could not recover jumptable at 0x000101f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x958))
              (param_1,param_2 * uVar1 >> 0x10 & 0xff,*(code **)(_r_ip_funcs_p + 0x958));
    return;
  }
  return;
}

