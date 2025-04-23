/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> vshci_task.o -> scan_stack_enableAdvFlowCtrlVsCmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void scan_stack_enableAdvFlowCtrlVsCmd(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = r_vs_funcs_p;
  if (param_1 == 0) {
    ble_cmd_handler_register(0xfd09,hci_unknown_hci_cmd_handler);
    ble_cmd_handler_register(0xfd0a,hci_unknown_hci_cmd_handler);
    puVar2 = (undefined *)0x0;
  }
  else {
    ble_cmd_handler_register(0xfd09,hci_vendor_ble_init_adv_flow_control_cmd_handler);
    ble_cmd_handler_register(0xfd0a,hci_vendor_ble_update_adv_report_flow_control_cmd_handler);
    puVar2 = &r_llm_send_adv_lost_event_to_host;
  }
  *(undefined **)puVar1 = puVar2;
  return;
}

