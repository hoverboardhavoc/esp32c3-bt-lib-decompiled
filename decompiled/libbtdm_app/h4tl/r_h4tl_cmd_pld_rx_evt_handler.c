/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> h4tl.o -> r_h4tl_cmd_pld_rx_evt_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_h4tl_cmd_pld_rx_evt_handler(void)

{
  (**(code **)(_r_modules_funcs_p + 0xec))(10,*(code **)(_r_modules_funcs_p + 0xec));
  (**(code **)(_r_ip_funcs_p + 0x2c))
            (_DAT_00011026,DAT_00011028,_r_hli_funcs_p,*(code **)(_r_ip_funcs_p + 0x2c));
  if (_r_hli_funcs_p != 0) {
    (**(code **)(_r_modules_funcs_p + 0x110))(*(code **)(_r_modules_funcs_p + 0x110));
    _DAT_00011024 = 0;
    _r_hli_funcs_p = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x00010686. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x78))(&h4tl_env,*(code **)(_r_modules_funcs_p + 0x78));
  return;
}

