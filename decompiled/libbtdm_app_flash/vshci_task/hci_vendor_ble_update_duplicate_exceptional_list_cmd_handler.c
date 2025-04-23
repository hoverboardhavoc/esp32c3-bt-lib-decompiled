/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> vshci_task.o -> hci_vendor_ble_update_duplicate_exceptional_list_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
hci_vendor_ble_update_duplicate_exceptional_list_cmd_handler
          (undefined4 param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  iVar2 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar2 + 0x23) == '\0') {
    puVar3 = (undefined1 *)r_ke_msg_alloc(0x1101,0xfd08,0xc);
    *puVar3 = 0xc;
    uVar1 = *param_2;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[1] = uVar1;
    puVar3[4] = 0;
    puVar3[5] = 0;
    r_hci_send_2_host();
  }
  else {
    f_hci_vendor_ble_update_duplicate_exceptional_list_cmd_handler(param_1,param_2,param_3,param_4);
  }
  return 0;
}

