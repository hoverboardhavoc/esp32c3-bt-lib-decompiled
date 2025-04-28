/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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

