/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> vshci_task.o -> hci_vendor_ble_init_adv_flow_control_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_vendor_ble_init_adv_flow_control_cmd_handler(undefined1 *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  iVar2 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar2 + 0x23) == '\0') {
    puVar3 = (undefined1 *)r_ke_msg_alloc(0x1101,param_2,0xfd09,1);
    *puVar3 = 0xc;
    r_hci_send_2_host();
    return 0;
  }
  uVar1 = 0x12;
  if (param_1 != (undefined1 *)0x0) {
    uVar1 = 0;
    r_llm_init_ble_adv_report_flow_contol
              (*param_1,*(undefined2 *)(param_1 + 2),*(undefined2 *)(param_1 + 4));
  }
  puVar3 = (undefined1 *)r_ke_msg_alloc(0x1101,param_2,0xfd09,1);
  *puVar3 = uVar1;
  r_hci_send_2_host();
  return 0;
}

