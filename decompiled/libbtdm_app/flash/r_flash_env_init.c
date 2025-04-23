/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> flash.o -> r_flash_env_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool r_flash_env_init(void)

{
  if (sdk_cfg_priv_opts != '\0') {
    vflash_mem = (**(code **)(_r_osi_funcs_p + 0x78))(0x800,*(code **)(_r_osi_funcs_p + 0x78));
    return vflash_mem != 0;
  }
  vflash_mem = 0;
  return true;
}

