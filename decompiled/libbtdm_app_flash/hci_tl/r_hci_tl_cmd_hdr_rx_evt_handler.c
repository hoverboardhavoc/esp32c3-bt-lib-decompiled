/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
    r_assert_err(0,"hci_tl.c",0x5a5);
  }
  r_ke_event_clear(6);
  r_hci_cmd_received(*(undefined2 *)(iVar1 + 1),*(undefined1 *)(iVar1 + 3),0);
  r_vhci_notify_host_send_available();
  return;
}

