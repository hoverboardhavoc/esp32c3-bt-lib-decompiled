/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> vshci_task.o -> hci_vs_ble_qa_enable_ch_assess_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
hci_vs_ble_qa_enable_ch_assess_cmd_handler
          (undefined1 param_1,undefined1 *param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)r_ke_msg_alloc(0x1101,param_3,0xfd13,2);
  esp_ble_enable_ch_assess(*param_2,param_2[1]);
  puVar1[1] = param_1;
  *puVar1 = 0;
  r_hci_send_2_host(puVar1);
  return 0;
}

