/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> nvds.o -> r_nvds_init
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
    r_nvds_null_init();
    uVar1 = 7;
  }
  else {
    r_flash_identify(&nvds_env,0);
    if ((byte)(DAT_000106ac - 1U) < 4) {
      nvds_env = r_nvds_read;
      DAT_0001069c = r_nvds_write;
      DAT_000106a0 = r_nvds_erase;
      DAT_000106a4 = param_1;
      DAT_000106a8 = param_2;
      iVar2 = r_nvds_is_magic_number_ok();
      if (iVar2 == 0) {
        if (1 < _g_bt_plf_log_level) {
          ets_printf("NVDS MAGIC FAILED\n");
        }
        r_nvds_init_memory();
      }
      uVar1 = 0;
    }
    else {
      r_nvds_null_init();
      uVar1 = 1;
    }
  }
  return uVar1;
}

