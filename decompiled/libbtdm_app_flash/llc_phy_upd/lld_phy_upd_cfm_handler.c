/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_phy_upd.o -> lld_phy_upd_cfm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 lld_phy_upd_cfm_handler(uint param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x18) == '\0') {
    r_assert_err(0,"llc_phy_upd.c",0x608,param_2);
    return 0;
  }
  param_1 = param_1 >> 8;
  iVar1 = r_llc_proc_id_get(param_1,0);
  if (iVar1 == 9) {
    r_llc_loc_phy_upd_proc_continue(param_1,4,0);
  }
  else {
    iVar1 = r_llc_proc_id_get(param_1,1);
    if (iVar1 == 9) {
      r_llc_rem_phy_upd_proc_continue_eco(param_1,7,0);
    }
  }
  return 0;
}

