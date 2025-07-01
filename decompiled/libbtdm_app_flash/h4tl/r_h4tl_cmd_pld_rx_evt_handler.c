/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
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
    _r_rwip_prevent_sleep_clear_hack = 0;
    _r_ke_event_clear = 0;
  }
  r_rwip_prevent_sleep_set_hack = (code)0x0;
  (*(code *)*_h4tl_env)(0x1101b,1,r_h4tl_rx_done,&h4tl_env,(code *)*_h4tl_env);
  r_rwip_prevent_sleep_clear_hack(4);
  return;
}

