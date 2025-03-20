/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app -> vshci_task.o -> advFilter_stack_enableDupExcListVsCmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void advFilter_stack_enableDupExcListVsCmd(int param_1)

{
  code *pcVar1;
  short *psVar2;
  int iVar3;
  
  if (param_1 == 0) {
    pcVar1 = hci_unknown_hci_cmd_handler;
  }
  else {
    pcVar1 = hci_vendor_ble_update_duplicate_exceptional_list_cmd_handler;
  }
  psVar2 = &hci_command_handler_tab_esp_hack;
  iVar3 = 0;
  do {
    if (*psVar2 == -0x2f8) {
      (&PTR_hci_unknown_hci_cmd_handler_00011134)[iVar3 * 2] = pcVar1;
      return;
    }
    iVar3 = iVar3 + 1;
    psVar2 = psVar2 + 4;
  } while (iVar3 != 7);
  return;
}

