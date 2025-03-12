/*
 * Last changed at upstream commit b5ead6b6d5758629370c91897168b8bcdfdcc169
 * https://github.com/espressif/esp32c3-bt-lib/commit/b5ead6b6d5758629370c91897168b8bcdfdcc169
 * Upstream date: 2025-03-12 20:14:26 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(9f6be86f)
 * Source: libbtdm_app_flash -> vshci_task.o -> f_hci_vendor_ble_update_duplicate_exceptional_list_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
f_hci_vendor_ble_update_duplicate_exceptional_list_cmd_handler(char *param_1,undefined4 param_2)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar2 = r_llm_update_duplicate_scan_exceptional_list
                    (*param_1,*(undefined4 *)(param_1 + 4),param_1 + 8);
  puVar3 = (undefined1 *)r_ke_msg_alloc(0x1101,param_2,0xfd08,0x10);
  *puVar3 = uVar2;
  cVar1 = *param_1;
  puVar3[1] = cVar1;
  uVar4 = *(uint *)(param_1 + 4);
  if (uVar4 == 1) {
    uVar5 = 4;
  }
  else {
    if (uVar4 != 0) {
      if (uVar4 < 5) {
        *(undefined4 *)(puVar3 + 4) = 0;
      }
      goto _L149;
    }
    uVar5 = 6;
  }
  *(undefined4 *)(puVar3 + 4) = uVar5;
_L149:
  if (cVar1 == '\x02') {
    *(undefined4 *)(puVar3 + 4) = 0;
  }
  memcpy(puVar3 + 8,param_1 + 8,*(size_t *)(puVar3 + 4));
  r_hci_send_2_host(puVar3);
  return 0;
}

