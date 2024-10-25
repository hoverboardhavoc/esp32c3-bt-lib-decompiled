/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
    r_flash_identify(&DAT_0001068c,0);
    if ((byte)(DAT_0001068c - 1U) < 4) {
      _LANCHOR0 = r_nvds_read;
      DAT_0001067c = r_nvds_write;
      DAT_00010680 = r_nvds_erase;
      DAT_00010684 = param_1;
      DAT_00010688 = param_2;
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

