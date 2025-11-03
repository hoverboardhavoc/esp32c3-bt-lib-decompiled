/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llm_hci.o -> r_llm_hci_command_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_llm_hci_command_handler(undefined4 param_1,uint param_2)

{
  ushort *puVar1;
  undefined4 uVar2;
  ushort *puVar3;
  
  puVar1 = llm_hci_command_handler_tab;
  do {
    puVar3 = puVar1;
    if (puVar3 == llm_hci_command_handler_tab + 0x130) {
      return 0;
    }
    puVar1 = puVar3 + 4;
  } while (*puVar3 != param_2);
  if (*(code **)(puVar3 + 2) == (code *)0x0) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x00010dd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(puVar3 + 2))(param_1);
  return uVar2;
}

