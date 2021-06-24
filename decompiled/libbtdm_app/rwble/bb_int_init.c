/*
 * Last changed at upstream commit b223604efd557d0a5314afb3b751229df424d244
 * https://github.com/espressif/esp32c3-bt-lib/commit/b223604efd557d0a5314afb3b751229df424d244
 * Upstream date: 2021-06-24 21:26:02 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (9c99115)
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
                    /* WARNING: Could not recover jumptable at 0x000101ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x120))(param_1);
  return;
}

