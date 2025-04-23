/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> vshci_task.o -> chanSel_stack_enableSetCsaVsCmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void chanSel_stack_enableSetCsaVsCmd(int param_1)

{
  code *pcVar1;
  short *psVar2;
  int iVar3;
  
  if (param_1 == 0) {
    pcVar1 = hci_unknown_hci_cmd_handler;
  }
  else {
    pcVar1 = hci_vendor_ble_csa_select_cmd_handler;
  }
  psVar2 = &hci_command_handler_tab_esp_hack;
  iVar3 = 0;
  do {
    if (*psVar2 == -0x2ee) {
      (&PTR_hci_unknown_hci_cmd_handler_000110f4)[iVar3 * 2] = pcVar1;
      return;
    }
    iVar3 = iVar3 + 1;
    psVar2 = psVar2 + 4;
  } while (iVar3 != 7);
  return;
}

