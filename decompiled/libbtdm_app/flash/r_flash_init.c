/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> flash.o -> r_flash_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_flash_init(void)

{
  _LANCHOR0 = vflash_mem;
  DAT_00010264 = 0;
  DAT_00010268 = 0;
  if (sdk_cfg_priv_opts != '\0') {
    memset(vflash_mem,0xff,0x800);
    (**(code **)(_r_plf_funcs_p + 0x6c))(&DAT_00010268,0,*(code **)(_r_plf_funcs_p + 0x6c));
                    /* WARNING: Could not recover jumptable at 0x000100f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 0x54))();
    return;
  }
  return;
}

