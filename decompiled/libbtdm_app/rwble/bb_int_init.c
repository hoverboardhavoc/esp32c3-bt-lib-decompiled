/*
 * Last changed at upstream commit 2a91d90e33b3b1104daf1bff898fe5bc3f814811
 * https://github.com/espressif/esp32c3-bt-lib/commit/2a91d90e33b3b1104daf1bff898fe5bc3f814811
 * Upstream date: 2022-09-07 12:18:28 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(2ee0168e)
 * Source: libbtdm_app -> rwble.o -> bb_int_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bb_int_init(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x11) != '\0') {
    bb_hw_intr_set(0x10400);
  }
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if ((*(char *)(iVar1 + 0x11) == '\0') && (sdk_cfg_priv_opts == '\0')) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0001026a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x120))(param_1);
  return;
}

