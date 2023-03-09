/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> vshci_task.o -> hci_vendor_ble_update_adv_report_flow_control_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
hci_vendor_ble_update_adv_report_flow_control_cmd_handler(short *param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  
  if ((param_1 == (short *)0x0) || (*param_1 == 0)) {
    puVar1 = (undefined1 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x1101,param_2,0xfd0a,1,*(code **)(_r_modules_funcs_p + 200));
    *puVar1 = 0x12;
    (**(code **)(_r_ip_funcs_p + 0x8c))(*(code **)(_r_ip_funcs_p + 0x8c));
  }
  else {
    (**(code **)(_r_ip_funcs_p + 0x52c))(*(code **)(_r_ip_funcs_p + 0x52c));
    (**(code **)(_r_ip_funcs_p + 0x60))(*(code **)(_r_ip_funcs_p + 0x60));
    (**(code **)(_r_ip_funcs_p + 0x34))(*(code **)(_r_ip_funcs_p + 0x34));
  }
  return 0;
}

