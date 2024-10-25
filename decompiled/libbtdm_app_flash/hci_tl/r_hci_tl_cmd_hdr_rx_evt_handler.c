/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  
  iVar1 = _hci_tl_env;
  if (_hci_tl_env == 0) {
    r_assert_err(0,"hci_tl.c",0x5a5);
  }
  r_ke_event_clear(6);
  r_hci_cmd_received(*(undefined2 *)(iVar1 + 1),*(undefined1 *)(iVar1 + 3),0);
  r_vhci_notify_host_send_available();
  return;
}

