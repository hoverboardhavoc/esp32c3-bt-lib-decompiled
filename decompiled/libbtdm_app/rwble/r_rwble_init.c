/*
 * Last changed at upstream commit 2a91d90e33b3b1104daf1bff898fe5bc3f814811
 * https://github.com/espressif/esp32c3-bt-lib/commit/2a91d90e33b3b1104daf1bff898fe5bc3f814811
 * Upstream date: 2022-09-07 12:18:28 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(2ee0168e)
 * Source: libbtdm_app -> rwble.o -> r_rwble_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwble_init(int param_1)

{
  int iVar1;
  int extraout_a1;
  
  if (param_1 == 0) {
    iVar1 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
    (**(code **)(_r_osi_funcs_p + 0x84))(iVar1 + extraout_a1,*(code **)(_r_osi_funcs_p + 0x84));
  }
  (**(code **)(_r_ip_funcs_p + 0x124))(param_1,*(code **)(_r_ip_funcs_p + 0x124));
  (**(code **)(_r_ip_funcs_p + 0x4c0))(param_1,*(code **)(_r_ip_funcs_p + 0x4c0));
  (**(code **)(_r_ip_funcs_p + 0x23c))(param_1,*(code **)(_r_ip_funcs_p + 0x23c));
  (**(code **)(_r_ip_funcs_p + 0xf0))(param_1,*(code **)(_r_ip_funcs_p + 0xf0));
  if (param_1 != 0) {
    (**(code **)(_r_ip_funcs_p + 0x254))(param_1,*(code **)(_r_ip_funcs_p + 0x254));
  }
  (**(code **)(_r_ip_funcs_p + 0x660))(param_1,*(code **)(_r_ip_funcs_p + 0x660));
                    /* WARNING: Could not recover jumptable at 0x00010150. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x4d4))(param_1);
  return;
}

