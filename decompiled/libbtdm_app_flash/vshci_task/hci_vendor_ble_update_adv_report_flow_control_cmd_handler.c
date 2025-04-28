/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> vshci_task.o -> hci_vendor_ble_update_adv_report_flow_control_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
hci_vendor_ble_update_adv_report_flow_control_cmd_handler
          (short *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x23) == '\0') {
    puVar2 = (undefined1 *)r_ke_msg_alloc(0x1101,param_3,0xfd0a,1);
    *puVar2 = 0xc;
    r_hci_send_2_host();
    return 0;
  }
  if ((param_1 == (short *)0x0) || (*param_1 == 0)) {
    puVar2 = (undefined1 *)r_ke_msg_alloc(0x1101,param_3,0xfd0a,1);
    *puVar2 = 0x12;
    r_hci_send_2_host();
  }
  else {
    r_llm_ble_update_adv_flow_control(param_2);
    r_hci_tl_inc_nb_h2c_cmd_pkts();
    r_hci_tl_c2h_data_flow_on();
  }
  return 0;
}

