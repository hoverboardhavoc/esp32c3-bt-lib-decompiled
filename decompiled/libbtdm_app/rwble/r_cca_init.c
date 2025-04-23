/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> rwble.o -> r_cca_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_cca_init(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    if (*(char *)(iVar1 + 0x19) == '\x01') {
      _DAT_600110d4 = _DAT_600110d4 & 0xfe1fffff | 0x200000;
      (**(code **)(_r_ip_funcs_p + 0x11c))(*(code **)(_r_ip_funcs_p + 0x11c));
    }
    if (sdk_cfg_priv_opts != '\0') {
      (**(code **)(_r_plf_funcs_p + 0xe4))(0,0,0,*(code **)(_r_plf_funcs_p + 0xe4));
    }
  }
  else if (1 < (param_1 - 1U & 0xff)) {
    return;
  }
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar1 + 0x19) == '\x01') {
    _DAT_600110d4 = _DAT_600110d4 & 0xfe1fffff | 0x200000;
  }
  return;
}

