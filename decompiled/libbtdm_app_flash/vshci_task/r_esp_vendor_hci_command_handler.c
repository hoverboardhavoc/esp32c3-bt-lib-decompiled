/*
 * Last changed at upstream commit 0cfafa1e0aa30b7d59f53c38588f0598e228d127
 * https://github.com/espressif/esp32c3-bt-lib/commit/0cfafa1e0aa30b7d59f53c38588f0598e228d127
 * Upstream date: 2025-02-27 20:50:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b34b7d6)
 * Source: libbtdm_app_flash -> vshci_task.o -> r_esp_vendor_hci_command_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_esp_vendor_hci_command_handler(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  ushort *puVar3;
  
  if (_esp_handler != (ushort *)0x0) {
    puVar3 = _esp_handler;
    for (uVar2 = 0; uVar2 < _vshci_state; uVar2 = uVar2 + 1) {
      if (*puVar3 == param_1) {
        if (*(code **)(puVar3 + 2) == (code *)0x0) {
          return 0;
        }
                    /* WARNING: Could not recover jumptable at 0x00010f74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar1 = (**(code **)(puVar3 + 2))(param_1);
        return uVar1;
      }
      puVar3 = puVar3 + 4;
    }
  }
  return 0;
}

