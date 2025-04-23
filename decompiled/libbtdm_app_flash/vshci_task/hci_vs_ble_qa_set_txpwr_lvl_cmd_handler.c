/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> vshci_task.o -> hci_vs_ble_qa_set_txpwr_lvl_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
hci_vs_ble_qa_set_txpwr_lvl_cmd_handler(undefined1 param_1,byte *param_2,undefined4 param_3)

{
  byte bVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  bVar1 = *param_2;
  uVar4 = 4;
  if (8 < bVar1) {
    uVar4 = 1;
    if (bVar1 != 9) {
      uVar4 = 2;
      if (bVar1 != 10) {
        uVar4 = 5;
        if (bVar1 == 0xb) {
          uVar4 = 0;
        }
      }
    }
  }
  puVar2 = (undefined1 *)r_ke_msg_alloc(0x1101,param_3,0xfd13,2);
  *puVar2 = 0;
  iVar3 = ble_txpwr_set(uVar4,0xffff,*(undefined4 *)(param_2 + 1));
  if (iVar3 != 0) {
    *puVar2 = 0x12;
  }
  puVar2[1] = param_1;
  r_hci_send_2_host(puVar2);
  return 0;
}

