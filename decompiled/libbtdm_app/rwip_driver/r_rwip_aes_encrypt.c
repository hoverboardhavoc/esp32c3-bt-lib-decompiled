/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> rwip_driver.o -> r_rwip_aes_encrypt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_aes_encrypt(undefined4 *param_1,void *param_2)

{
  void *__dest;
  
  (**(code **)(_r_modules_funcs_p + 0x2b4))(0x20,*(code **)(_r_modules_funcs_p + 0x2b4));
  __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x128,*(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(__dest,param_2,0x10);
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  _DAT_600310b4 = *param_1;
  _DAT_600310b8 = param_1[1];
  _DAT_600310bc = param_1[2];
  _DAT_600310c0 = param_1[3];
  _DAT_600310c4 = 0x128;
  _DAT_60031018 = 0x80;
  if (sdk_cfg_priv_opts != '\0') {
    _DAT_6003138c = 0x80;
  }
  _DAT_6003100c = _DAT_6003100c | 0x80;
  _DAT_600310b0 = _DAT_600310b0 | 1;
                    /* WARNING: Could not recover jumptable at 0x0001100a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

