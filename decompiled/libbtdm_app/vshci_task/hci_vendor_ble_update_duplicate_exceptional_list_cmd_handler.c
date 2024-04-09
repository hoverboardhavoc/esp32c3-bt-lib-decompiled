/*
 * Last changed at upstream commit 76ed4114ee7d081435a3c65793b4c8eb1dfaf199
 * https://github.com/espressif/esp32c3-bt-lib/commit/76ed4114ee7d081435a3c65793b4c8eb1dfaf199
 * Upstream date: 2024-04-09 17:28:48 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(c23ab4c)
 * Source: libbtdm_app -> vshci_task.o -> hci_vendor_ble_update_duplicate_exceptional_list_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
hci_vendor_ble_update_duplicate_exceptional_list_cmd_handler(char *param_1,undefined4 param_2)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar2 = (**(code **)(_r_ip_funcs_p + 0x8cc))
                    (*param_1,*(undefined4 *)(param_1 + 4),param_1 + 8,
                     *(code **)(_r_ip_funcs_p + 0x8cc));
  puVar3 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,param_2,0xfd08,0x10,*(code **)(_r_modules_funcs_p + 200));
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
      goto _L89;
    }
    uVar5 = 6;
  }
  *(undefined4 *)(puVar3 + 4) = uVar5;
_L89:
  if (cVar1 == '\x02') {
    *(undefined4 *)(puVar3 + 4) = 0;
  }
  memcpy(puVar3 + 8,param_1 + 8,*(size_t *)(puVar3 + 4));
  (**(code **)(_r_ip_funcs_p + 0x8c))(puVar3,*(code **)(_r_ip_funcs_p + 0x8c));
  return 0;
}

