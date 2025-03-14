/*
 * Last changed at upstream commit bc9fd38197fb6a50e1b09791498782a1797e4757
 * https://github.com/espressif/esp32c3-bt-lib/commit/bc9fd38197fb6a50e1b09791498782a1797e4757
 * Upstream date: 2025-03-14 10:49:41 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(99e9a8dd)
 * Source: libbtdm_app_flash -> vshci_task.o -> hci_vendor_ble_update_duplicate_exceptional_list_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
hci_vendor_ble_update_duplicate_exceptional_list_cmd_handler(char *param_1,undefined4 param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  
  iVar3 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar3 + 0x23) == '\0') {
    puVar4 = (undefined1 *)r_ke_msg_alloc(0x1101,0xfd08,0x10);
    *puVar4 = 0xc;
    cVar1 = *param_1;
    *(undefined4 *)(puVar4 + 4) = 0;
    puVar4[1] = cVar1;
    r_hci_send_2_host();
    return 0;
  }
  uVar2 = r_llm_update_duplicate_scan_exceptional_list
                    (*param_1,*(undefined4 *)(param_1 + 4),param_1 + 8);
  puVar4 = (undefined1 *)r_ke_msg_alloc(0x1101,param_2,0xfd08,0x10);
  *puVar4 = uVar2;
  cVar1 = *param_1;
  puVar4[1] = cVar1;
  uVar5 = *(uint *)(param_1 + 4);
  if (uVar5 == 1) {
    uVar6 = 4;
  }
  else {
    if (uVar5 != 0) {
      if (uVar5 < 5) {
        *(undefined4 *)(puVar4 + 4) = 0;
      }
      goto _L146;
    }
    uVar6 = 6;
  }
  *(undefined4 *)(puVar4 + 4) = uVar6;
_L146:
  if (cVar1 == '\x02') {
    *(undefined4 *)(puVar4 + 4) = 0;
  }
  memcpy(puVar4 + 8,param_1 + 8,*(size_t *)(puVar4 + 4));
  r_hci_send_2_host(puVar4);
  return 0;
}

