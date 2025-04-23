/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> nvds.o -> r_nvds_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_nvds_init(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (sdk_cfg_priv_opts == '\0') {
    (**(code **)(_r_modules_funcs_p + 0x250))(*(code **)(_r_modules_funcs_p + 0x250));
    uVar1 = 7;
  }
  else {
    (**(code **)(_r_plf_funcs_p + 0x6c))(&nvds_env,0,*(code **)(_r_plf_funcs_p + 0x6c));
    if ((byte)(DAT_00010700 - 1U) < 4) {
      nvds_env = *(undefined4 *)(_r_modules_funcs_p + 0x25c);
      DAT_000106f0 = *(undefined4 *)(_r_modules_funcs_p + 0x264);
      DAT_000106f4 = *(undefined4 *)(_r_modules_funcs_p + 0x238);
      DAT_000106f8 = param_1;
      DAT_000106fc = param_2;
      iVar2 = (**(code **)(_r_modules_funcs_p + 0x248))(*(code **)(_r_modules_funcs_p + 0x248));
      if (iVar2 == 0) {
        if (1 < _g_bt_plf_log_level) {
          ets_printf("NVDS MAGIC FAILED\n");
        }
        (**(code **)(_r_modules_funcs_p + 0x244))(*(code **)(_r_modules_funcs_p + 0x244));
      }
      uVar1 = 0;
    }
    else {
      (**(code **)(_r_modules_funcs_p + 0x250))(*(code **)(_r_modules_funcs_p + 0x250));
      uVar1 = 1;
    }
  }
  return uVar1;
}

