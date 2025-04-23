/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_hci.o -> r_llm_hci_command_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_llm_hci_command_handler(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  ushort *puVar2;
  
  puVar2 = llm_hci_command_handler_tab;
  do {
    if (*puVar2 == param_2) {
      if (*(code **)(puVar2 + 2) == (code *)0x0) {
        return 0;
      }
                    /* WARNING: Could not recover jumptable at 0x00010d5e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (**(code **)(puVar2 + 2))(param_1);
      return uVar1;
    }
    puVar2 = puVar2 + 4;
  } while (puVar2 != llm_hci_command_handler_tab + 0x130);
  return 0;
}

