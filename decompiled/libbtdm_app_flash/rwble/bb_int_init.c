/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> rwble.o -> bb_int_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bb_int_init(int param_1)

{
  int iVar1;
  
  iVar1 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x11) != '\0') {
    iVar1 = r_sdk_config_get_opts_ext();
    if ((*(byte *)(iVar1 + 0x11) & 4) == 0) {
      bb_hw_intr_set(0x10400);
    }
    else {
      _DAT_600118fc = _DAT_600118fc | 0x8000000;
    }
  }
  iVar1 = r_sdk_config_get_opts_ext();
  if ((*(char *)(iVar1 + 0x19) != '\x01') && (sdk_cfg_priv_opts == '\0')) {
    return;
  }
  if (param_1 == 0) {
    iVar1 = r_sdk_config_get_opts_ext();
    if (*(char *)(iVar1 + 0x19) == '\x01') {
      _DAT_600110d4 = _DAT_600110d4 & 0xfe1fffff | 0x200000;
      r_cca_hw_intr_set();
    }
    if (sdk_cfg_priv_opts != '\0') {
      r_btdm_config_cca_sw(0,0,0);
    }
  }
  else if (1 < (param_1 - 1U & 0xff)) {
    return;
  }
  iVar1 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x19) == '\x01') {
    _DAT_600110d4 = _DAT_600110d4 & 0xfe1fffff | 0x200000;
  }
  return;
}

