/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> vshci_task.o -> r_vnd_hci_command_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_vnd_hci_command_handler(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  ushort *puVar3;
  
  if ((param_1 >> 10 == 0x3f) && (0xfc80 < param_1)) {
    if (_esp_handler != (ushort *)0x0) {
      puVar3 = _esp_handler;
      for (uVar2 = 0; uVar2 < _vshci_state; uVar2 = uVar2 + 1) {
        if (*puVar3 == param_1) {
          if (*(code **)(puVar3 + 2) == (code *)0x0) {
            return 0;
          }
                    /* WARNING: Could not recover jumptable at 0x000111fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar1 = (**(code **)(puVar3 + 2))(param_1);
          return uVar1;
        }
        puVar3 = puVar3 + 4;
      }
    }
    return 0;
  }
  return 0;
}

