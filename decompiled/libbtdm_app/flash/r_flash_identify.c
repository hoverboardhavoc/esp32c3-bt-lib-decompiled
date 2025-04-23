/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> flash.o -> r_flash_identify
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_flash_identify(undefined1 *param_1)

{
  if (sdk_cfg_priv_opts != '\0') {
    (**(code **)(_r_plf_funcs_p + 0x74))(flash_env,0x34,*(code **)(_r_plf_funcs_p + 0x74));
    (**(code **)(_r_plf_funcs_p + 0x74))(flash_env + 1,0x12,*(code **)(_r_plf_funcs_p + 0x74));
    (**(code **)(_r_plf_funcs_p + 0x74))(flash_env + 2,0xff,*(code **)(_r_plf_funcs_p + 0x74));
    (**(code **)(_r_plf_funcs_p + 0x74))(flash_env + 3,0xff,*(code **)(_r_plf_funcs_p + 0x74));
    DAT_0001025c = 4;
    DAT_00010258 = 0x800;
    *param_1 = 4;
    return 0;
  }
  return 0x1f;
}

