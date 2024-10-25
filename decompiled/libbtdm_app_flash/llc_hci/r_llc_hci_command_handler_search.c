/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_hci.o -> r_llc_hci_command_handler_search
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_llc_hci_command_handler_search(uint param_1)

{
  ushort *puVar1;
  
  puVar1 = &_LANCHOR2;
  do {
    if (*puVar1 == param_1) {
      return *(undefined4 *)(puVar1 + 2);
    }
    puVar1 = puVar1 + 4;
  } while (puVar1 != (ushort *)0x10728);
  return 0;
}

