/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
 * Source: libbtdm_app_flash -> rwip_driver.o -> r_rwip_prevent_sleep_set_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_prevent_sleep_set_hack(int param_1)

{
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  _DAT_0001202e = _DAT_0001202e | (ushort)param_1;
  if (param_1 == 0x200) {
    _DAT_600110e0 = _DAT_600110e0 | 0x20000000;
  }
                    /* WARNING: Could not recover jumptable at 0x000102b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

