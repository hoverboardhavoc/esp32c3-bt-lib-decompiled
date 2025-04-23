/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> rwip_driver.o -> r_rwip_crypt_isr_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_crypt_isr_handler(void)

{
  int iVar1;
  
  (**(code **)(_r_modules_funcs_p + 0x2b0))(0x20,*(code **)(_r_modules_funcs_p + 0x2b0));
  _DAT_6003100c = _DAT_6003100c & 0xffffff7f;
  if (sdk_cfg_priv_opts != '\0') {
    _DAT_6003138c = 0x80;
  }
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar1 + 0x20) != '\0') {
                    /* WARNING: Could not recover jumptable at 0x00010832. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0x108))(2,*(code **)(_r_modules_funcs_p + 0x108));
    return;
  }
  return;
}

