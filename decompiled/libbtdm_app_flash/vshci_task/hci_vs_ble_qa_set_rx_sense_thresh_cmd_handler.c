/*
 * Last changed at upstream commit 2fd7ad255fceabdfba56882ce4523efdba2fc255
 * https://github.com/espressif/esp32c3-bt-lib/commit/2fd7ad255fceabdfba56882ce4523efdba2fc255
 * Upstream date: 2025-03-31 11:18:40 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(566c8e3)
 * Source: libbtdm_app_flash -> vshci_task.o -> hci_vs_ble_qa_set_rx_sense_thresh_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
hci_vs_ble_qa_set_rx_sense_thresh_cmd_handler(undefined1 param_1,char *param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  
  puVar1 = (undefined1 *)r_ke_msg_alloc(0x1101,param_3,0xfd13,2);
  uVar2 = (int)param_2[2] >> 0x1f;
  bt_bb_set_rx_sense(*param_2 != '\0',param_2[1],uVar2 - ((int)param_2[2] ^ uVar2) & 0xff);
  puVar1[1] = param_1;
  *puVar1 = 0;
  r_hci_send_2_host(puVar1);
  return 0;
}

