/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  int iVar1;
  undefined4 uVar2;
  
  if (sdk_cfg_priv_opts == '\0') {
    r_nvds_null_init();
    uVar2 = 7;
  }
  else {
    r_flash_identify(&DAT_000106a4,0);
    if ((byte)(DAT_000106a4 - 1U) < 4) {
      nvds_env = r_nvds_read;
      DAT_00010694 = r_nvds_write;
      DAT_00010698 = r_nvds_erase;
      DAT_0001069c = param_1;
      DAT_000106a0 = param_2;
      iVar1 = r_nvds_is_magic_number_ok();
      uVar2 = 0;
      if (iVar1 == 0) {
        if (1 < _g_bt_plf_log_level) {
          ets_printf("NVDS MAGIC FAILED\n");
        }
        r_nvds_init_memory();
        uVar2 = 0;
      }
    }
    else {
      r_nvds_null_init();
      uVar2 = 1;
    }
  }
  return uVar2;
}

