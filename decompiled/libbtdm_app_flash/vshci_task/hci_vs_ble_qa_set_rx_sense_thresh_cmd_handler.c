/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  
  puVar1 = (undefined1 *)r_ke_msg_alloc(0x1101,param_3,0xfd13,2);
  bt_bb_set_rx_sense(*param_2 != '\0',param_2[1],
                     ((int)param_2[2] >> 7) - ((uint)(byte)param_2[2] ^ (int)param_2[2] >> 7) & 0xff
                    );
  puVar1[1] = param_1;
  *puVar1 = 0;
  r_hci_send_2_host(puVar1);
  return 0;
}

