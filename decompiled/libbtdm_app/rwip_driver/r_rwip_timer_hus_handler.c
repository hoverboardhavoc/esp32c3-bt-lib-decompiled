/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> rwip_driver.o -> r_rwip_timer_hus_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_timer_hus_handler(void)

{
  _rwip_env = 0xffffffff;
  _DAT_6003100c = _DAT_6003100c & 0xfffff7ff;
  if (sdk_cfg_priv_opts != '\0') {
    _DAT_6003138c = 0x800;
  }
                    /* WARNING: Could not recover jumptable at 0x00010722. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x6a8))(*(code **)(_r_ip_funcs_p + 0x6a8));
  return;
}

