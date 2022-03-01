/*
 * Last changed at upstream commit 98dcc9591365b5ac486a9f0b474c36bf8c4ca97b
 * https://github.com/espressif/esp32c3-bt-lib/commit/98dcc9591365b5ac486a9f0b474c36bf8c4ca97b
 * Upstream date: 2022-03-01 14:41:26 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (d913766) Add the pll track feature to keep the ble connection stable when the environment temprature increase form 0 to 74.
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
  if ((*(char *)(iVar1 + 0x11) != '\0') || (sdk_cfg_priv_opts != '\0')) {
    (**(code **)(_r_ip_funcs_p + 0x120))(param_1,*(code **)(_r_ip_funcs_p + 0x120));
  }
  if (sdk_cfg_priv_opts_extend != '\0') {
    bb_hw_intr_set(0x6000);
    return;
  }
  return;
}

