/*
 * Last changed at upstream commit 040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * https://github.com/espressif/esp32c3-bt-lib/commit/040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * Upstream date: 2023-08-03 10:45:08 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ff6efe7)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_scst_timeout_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_scst_timeout_check(int param_1,int param_2)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(*(int *)(p_lld_cca + 0x28) + param_1 * 0xc);
  if (((char)*pbVar1 < '\0') &&
     ((*(ushort *)(p_lld_cca + 0xe) / 10 - (uint)*(ushort *)(p_lld_cca + 0x14)) * 2 <
      (param_2 - *(int *)(pbVar1 + 4) & 0xfffffffU))) {
    (**(code **)(_r_ip_funcs_p + 0x978))(1,*(code **)(_r_ip_funcs_p + 0x978));
    *pbVar1 = *pbVar1 & 0x7f | 0x10;
  }
  return;
}

