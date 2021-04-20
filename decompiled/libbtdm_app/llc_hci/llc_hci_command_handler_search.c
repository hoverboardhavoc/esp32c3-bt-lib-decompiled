/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> llc_hci.o -> llc_hci_command_handler_search
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 llc_hci_command_handler_search(uint param_1)

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

