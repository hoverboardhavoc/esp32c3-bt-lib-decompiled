/*
 * Last changed at upstream commit 040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * https://github.com/espressif/esp32c3-bt-lib/commit/040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * Upstream date: 2023-08-03 10:45:08 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ff6efe7)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_chan_prn_s
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_chan_prn_s(uint param_1,uint param_2)

{
  char cVar1;
  
  param_1 = param_1 ^ param_2;
  cVar1 = '\x03';
  do {
    cVar1 = cVar1 + -1;
    (**(code **)(_r_ip_funcs_p + 0x960))(param_1,*(code **)(_r_ip_funcs_p + 0x960));
    param_1 = (**(code **)(_r_ip_funcs_p + 0x964))(param_2,*(code **)(_r_ip_funcs_p + 0x964));
  } while (cVar1 != '\0');
  return;
}

