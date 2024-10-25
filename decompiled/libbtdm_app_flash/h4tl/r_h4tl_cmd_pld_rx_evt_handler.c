/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> h4tl.o -> r_h4tl_cmd_pld_rx_evt_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_h4tl_cmd_pld_rx_evt_handler(void)

{
  r_ke_event_clear(10);
  r_hci_cmd_received(_DAT_00011012,r_hci_cmd_received,_r_ke_event_clear);
  if (_r_ke_event_clear != 0) {
    r_ke_free();
    _r_rwip_prevent_sleep_clear = 0;
    _r_ke_event_clear = 0;
  }
  r_rwip_prevent_sleep_set = (code)0x0;
  (*(code *)*_h4tl_env)(0x1101b,1,r_h4tl_rx_done,&h4tl_env,(code *)*_h4tl_env);
  r_rwip_prevent_sleep_clear(4);
  return;
}

