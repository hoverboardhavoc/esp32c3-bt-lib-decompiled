/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app_flash -> vshci_task.o -> hci_vs_ble_qa_get_scan_backoff_upperlimit_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
hci_vs_ble_qa_get_scan_backoff_upperlimit_cmd_handler(undefined1 param_1,undefined4 param_2)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)r_ke_msg_alloc(0x1101,param_2,0xfd13,4);
  puVar2[1] = param_1;
  *puVar2 = 0;
  uVar1 = ble_ll_scan_upperlimit_getting();
  puVar2[2] = (char)uVar1;
  puVar2[3] = (char)((ushort)uVar1 >> 8);
  r_hci_send_2_host(puVar2);
  return 0;
}

