/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> rwble.o -> r_cca_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_cca_init(uint param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = r_sdk_config_get_opts_ext();
    if (*(char *)(iVar1 + 0x19) == '\x01') {
      _DAT_600110d4 = _DAT_600110d4 & 0xfe1fffff | 0x200000;
      r_cca_hw_intr_set(1);
    }
    if (sdk_cfg_priv_opts != '\0') {
      r_btdm_config_cca_sw(0,0,0);
    }
  }
  else if (2 < param_1) {
    return;
  }
  iVar1 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x19) == '\x01') {
    _DAT_600110d4 = _DAT_600110d4 & 0xfe1fffff | 0x200000;
  }
  return;
}

