/*
 * Last changed at upstream commit 040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * https://github.com/espressif/esp32c3-bt-lib/commit/040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * Upstream date: 2023-08-03 10:45:08 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ff6efe7)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_chan_avl_timeout_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_chan_avl_timeout_check(int param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  
  pbVar1 = (byte *)(param_1 * 0xc + *(int *)(p_lld_cca + 0x28));
  if (((*pbVar1 & 1) != 0) &&
     (((uint)*(ushort *)(p_lld_cca + 0x10) - (uint)*(ushort *)(p_lld_cca + 0x14)) * 2 <
      (param_2 - *(int *)(pbVar1 + 4) & 0xfffffffU))) {
    if ((*(ushort *)(p_lld_cca + 4) & 1) != 0) {
      (**(code **)(_r_ip_funcs_p + 0x998))(pbVar1,*(code **)(_r_ip_funcs_p + 0x998));
    }
    if ((*pbVar1 & 2) == 0) {
      if (*(ushort *)(p_lld_cca + 4) >> 0xc == 4) {
                    /* WARNING: Could not recover jumptable at 0x000108d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_ip_funcs_p + 0x980))(pbVar1);
        return;
      }
      *(int *)(pbVar1 + 4) = param_2;
      bVar2 = *pbVar1 & 0xf7;
    }
    else {
      (**(code **)(_r_ip_funcs_p + 0x978))(1,*(code **)(_r_ip_funcs_p + 0x978));
      bVar2 = *pbVar1 | 0x10;
    }
    *pbVar1 = bVar2;
  }
  return;
}

