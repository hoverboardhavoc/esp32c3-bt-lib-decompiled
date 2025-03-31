/*
 * Last changed at upstream commit 2fd7ad255fceabdfba56882ce4523efdba2fc255
 * https://github.com/espressif/esp32c3-bt-lib/commit/2fd7ad255fceabdfba56882ce4523efdba2fc255
 * Upstream date: 2025-03-31 11:18:40 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(566c8e3)
 * Source: libbtdm_app_flash -> vshci_task.o -> hci_vs_ble_qa_enable_cca_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
hci_vs_ble_qa_enable_cca_cmd_handler(undefined1 param_1,undefined1 *param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  
  puVar1 = (undefined1 *)r_ke_msg_alloc(0x1101,param_3,0xfd13,2);
  iVar2 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar2 + 0x19) == '\x01') {
    uVar3 = (int)(char)param_2[1] >> 0x1f;
    bt_bb_tx_cca_set(*param_2,(uVar3 - ((int)(char)param_2[1] ^ uVar3)) + 0x100,0,0,0,0,0,0);
    *puVar1 = 0;
  }
  else {
    *puVar1 = 1;
  }
  puVar1[1] = param_1;
  r_hci_send_2_host(puVar1);
  return 0;
}

