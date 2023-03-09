/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> llc_hci.o -> r_llc_hci_command_handler_search
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_llc_hci_command_handler_search(uint param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  
  puVar1 = (ushort *)(**(code **)(_r_ip_funcs_p + 0x638))(*(code **)(_r_ip_funcs_p + 0x638));
  puVar2 = puVar1 + 0x4c;
  do {
    if (*puVar1 == param_1) {
      return *(undefined4 *)(puVar1 + 2);
    }
    puVar1 = puVar1 + 4;
  } while (puVar1 != puVar2);
  return 0;
}

