/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> hci_msg.o -> r_hci_look_for_le_evt_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * r_hci_look_for_le_evt_desc(uint param_1)

{
  byte *pbVar1;
  int iVar2;
  
  pbVar1 = &hci_evt_le_desc_tab_flash;
  iVar2 = 0;
  do {
    if (*pbVar1 == param_1) {
      return &hci_evt_le_desc_tab_flash + iVar2 * 8;
    }
    iVar2 = iVar2 + 1;
    pbVar1 = pbVar1 + 8;
  } while (iVar2 != 0x14);
  return (undefined1 *)0x0;
}

