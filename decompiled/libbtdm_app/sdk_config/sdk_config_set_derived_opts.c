/*
 * Last changed at upstream commit d4922c5890feb6ee1733e6063369ff54a30f5930
 * https://github.com/espressif/esp32c3-bt-lib/commit/d4922c5890feb6ee1733e6063369ff54a30f5930
 * Upstream date: 2024-07-23 16:16:25 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(4e58df9)
 * Source: libbtdm_app -> sdk_config.o -> sdk_config_set_derived_opts
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sdk_config_set_derived_opts(void)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  uVar1 = *(undefined1 *)(iVar2 + 0xd);
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  ble_txpwr_set_inter(0,uVar1,*(undefined1 *)(iVar2 + 0x1e));
  return;
}

