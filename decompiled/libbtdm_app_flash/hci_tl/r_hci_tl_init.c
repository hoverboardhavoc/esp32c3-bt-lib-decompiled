/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> hci_tl.o -> r_hci_tl_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_hci_tl_init(int param_1)

{
  if (param_1 == 0) {
    memset(&hci_tl_env,0,0x28);
    r_co_list_init(&hci_tl_env);
    r_co_list_init(&hci_tl_env);
    r_assert_err = (code)0x1;
    r_ke_event_callback_set(6,r_hci_tl_cmd_hdr_rx_evt_handler);
    r_ke_event_callback_set(7,r_hci_tl_cmd_pld_rx_evt_handler);
    r_ke_event_callback_set(5,r_hci_tl_hci_tx_done_evt_handler);
  }
  DAT_0001201d = 5;
  return;
}

