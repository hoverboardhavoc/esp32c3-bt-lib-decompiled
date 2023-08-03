/*
 * Last changed at upstream commit 040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * https://github.com/espressif/esp32c3-bt-lib/commit/040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * Upstream date: 2023-08-03 10:45:08 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ff6efe7)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_chan_perm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_lld_cca_chan_perm(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x95c))(param_1 >> 8,*(code **)(_r_ip_funcs_p + 0x95c));
  uVar2 = (**(code **)(_r_ip_funcs_p + 0x95c))(param_1 & 0xff,*(code **)(_r_ip_funcs_p + 0x95c));
  return (uVar2 | iVar1 << 8) & 0xffff;
}

