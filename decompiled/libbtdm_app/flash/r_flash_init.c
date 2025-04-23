/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> flash.o -> r_flash_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_flash_init(void)

{
  flash_env = vflash_mem;
  DAT_00010258 = 0;
  DAT_0001025c = 0;
  if (sdk_cfg_priv_opts != '\0') {
    memset(vflash_mem,0xff,0x800);
    (**(code **)(_r_plf_funcs_p + 0x6c))(&flash_env,0,*(code **)(_r_plf_funcs_p + 0x6c));
                    /* WARNING: Could not recover jumptable at 0x000100ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 0x54))(*(code **)(_r_plf_funcs_p + 0x54));
    return;
  }
  return;
}

