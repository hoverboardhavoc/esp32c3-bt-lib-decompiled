/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_llcp.o -> r_llc_llcp_pdu_handler_get_overwrite
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined * r_llc_llcp_pdu_handler_get_overwrite(int param_1)

{
  if (param_1 == 1) {
    return &ll_channel_map_ind_handler_hack;
  }
  if (param_1 != 0) {
    if (param_1 != 0x18) {
      return (&_LANCHOR1)[param_1 * 3];
    }
    return &ll_phy_update_ind_handler_hack;
  }
  return &ll_connection_update_ind_handler_hack;
}

