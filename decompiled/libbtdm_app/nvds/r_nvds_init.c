/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> nvds.o -> r_nvds_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_nvds_init(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (sdk_cfg_priv_opts == '\0') {
    (**(code **)(_r_modules_funcs_p + 0x250))(*(code **)(_r_modules_funcs_p + 0x250));
    uVar2 = 7;
  }
  else {
    (**(code **)(_r_plf_funcs_p + 0x6c))(&DAT_000106b4,0,*(code **)(_r_plf_funcs_p + 0x6c));
    if ((byte)(DAT_000106b4 - 1U) < 4) {
      _LANCHOR0 = *(undefined4 *)(_r_modules_funcs_p + 0x25c);
      DAT_000106a4 = *(undefined4 *)(_r_modules_funcs_p + 0x264);
      DAT_000106a8 = *(undefined4 *)(_r_modules_funcs_p + 0x238);
      DAT_000106ac = param_1;
      DAT_000106b0 = param_2;
      iVar1 = (**(code **)(_r_modules_funcs_p + 0x248))(*(code **)(_r_modules_funcs_p + 0x248));
      uVar2 = 0;
      if (iVar1 == 0) {
        if (1 < _g_bt_plf_log_level) {
          ets_printf("NVDS MAGIC FAILED\n");
        }
        (**(code **)(_r_modules_funcs_p + 0x244))(*(code **)(_r_modules_funcs_p + 0x244));
        uVar2 = 0;
      }
    }
    else {
      (**(code **)(_r_modules_funcs_p + 0x250))(*(code **)(_r_modules_funcs_p + 0x250));
      uVar2 = 1;
    }
  }
  return uVar2;
}

