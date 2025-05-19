/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> llc_chmap_upd.o -> lld_ch_map_upd_cfm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 lld_ch_map_upd_cfm_handler(uint param_1)

{
  int iVar1;
  
  param_1 = param_1 >> 8;
  iVar1 = r_llc_proc_id_get(param_1,0);
  if (iVar1 == 6) {
    r_llc_loc_ch_map_proc_continue_hack(param_1,1,0);
  }
  else {
    iVar1 = r_llc_proc_id_get(param_1,1);
    if (iVar1 == 6) {
      r_llc_rem_ch_map_proc_continue(param_1,4,0);
    }
  }
  return 0;
}

