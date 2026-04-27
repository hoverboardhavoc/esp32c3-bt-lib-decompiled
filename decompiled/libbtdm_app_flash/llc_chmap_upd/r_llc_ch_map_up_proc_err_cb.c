/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llc_chmap_upd.o -> r_llc_ch_map_up_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_ch_map_up_proc_err_cb(uint param_1,int param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  int iVar2;
  
  if (param_2 == 0) {
    uVar1 = *param_3;
    iVar2 = r_llc_proc_id_get();
    if (iVar2 == 6) {
      r_llc_loc_ch_map_proc_continue_hack(param_1,2);
    }
    else {
      iVar2 = r_llc_proc_id_get(param_1,1);
      if (iVar2 == 6) {
        r_llc_rem_ch_map_proc_continue(param_1,5,uVar1);
      }
    }
  }
  else if (2 < (param_2 - 1U & 0xff)) {
    r_assert_param(0x10000,0x172);
  }
  r_ble_log_internal_x1(0x804f0083,param_2 << 8 | param_1);
  return;
}

