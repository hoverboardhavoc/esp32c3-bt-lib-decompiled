/*
 * Last changed at upstream commit 2fd7ad255fceabdfba56882ce4523efdba2fc255
 * https://github.com/espressif/esp32c3-bt-lib/commit/2fd7ad255fceabdfba56882ce4523efdba2fc255
 * Upstream date: 2025-03-31 11:18:40 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(566c8e3)
 * Source: libbtdm_app_flash -> vshci_task.o -> bt_stack_enableEchoVsCmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bt_stack_enableEchoVsCmd(int param_1)

{
  code *pcVar1;
  short *psVar2;
  int iVar3;
  
  if (param_1 == 0) {
    pcVar1 = hci_unknown_hci_cmd_handler;
  }
  else {
    pcVar1 = hci_dbg_common_echo_cmd_handler;
  }
  psVar2 = &hci_command_handler_tab_esp_hack;
  iVar3 = 0;
  do {
    if (*psVar2 == -0x37f) {
      (&PTR_hci_unknown_hci_cmd_handler_0001103c)[iVar3 * 2] = pcVar1;
      return;
    }
    iVar3 = iVar3 + 1;
    psVar2 = psVar2 + 4;
  } while (iVar3 != 7);
  return;
}

