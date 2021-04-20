/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
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
    (**(code **)(_r_plf_funcs_p + 0x74))(_LANCHOR0,0x34,*(code **)(_r_plf_funcs_p + 0x74));
    (**(code **)(_r_plf_funcs_p + 0x74))(_LANCHOR0 + 1,0x12,*(code **)(_r_plf_funcs_p + 0x74));
    (**(code **)(_r_plf_funcs_p + 0x74))(_LANCHOR0 + 2,0xff,*(code **)(_r_plf_funcs_p + 0x74));
    (**(code **)(_r_plf_funcs_p + 0x74))(_LANCHOR0 + 3,0xff,*(code **)(_r_plf_funcs_p + 0x74));
    DAT_00010268 = 4;
    DAT_00010264 = 0x800;
    *param_1 = 4;
    return 0;
  }
  return 0x1f;
}

