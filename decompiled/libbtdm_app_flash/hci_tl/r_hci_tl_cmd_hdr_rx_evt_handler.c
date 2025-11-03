/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> hci_tl.o -> r_hci_tl_cmd_hdr_rx_evt_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_tl_cmd_hdr_rx_evt_handler(void)

{
  int iVar1;
  
  iVar1 = _memcpy;
  if (_memcpy == 0) {
    r_assert_err(0,"hci_tl.c",0x5a6);
  }
  r_ke_event_clear(6);
  r_hci_cmd_received(*(undefined2 *)(iVar1 + 1),*(undefined1 *)(iVar1 + 3),0);
  r_vhci_notify_host_send_available();
  return;
}

