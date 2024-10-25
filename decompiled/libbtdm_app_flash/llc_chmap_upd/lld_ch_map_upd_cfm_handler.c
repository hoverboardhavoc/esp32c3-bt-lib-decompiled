/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
    r_llc_loc_ch_map_proc_continue(param_1,1,0);
  }
  else {
    iVar1 = r_llc_proc_id_get(param_1,1);
    if (iVar1 == 6) {
      r_llc_rem_ch_map_proc_continue(param_1,4,0);
    }
  }
  return 0;
}

