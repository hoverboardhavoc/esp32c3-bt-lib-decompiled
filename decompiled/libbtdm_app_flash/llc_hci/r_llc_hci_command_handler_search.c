/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llc_hci.o -> r_llc_hci_command_handler_search
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_llc_hci_command_handler_search(uint param_1)

{
  ushort *puVar1;
  
  puVar1 = &llc_hci_command_handler_tab;
  do {
    if (*puVar1 == param_1) {
      return *(undefined4 *)(puVar1 + 2);
    }
    puVar1 = puVar1 + 4;
  } while (puVar1 != (ushort *)0x10750);
  return 0;
}

