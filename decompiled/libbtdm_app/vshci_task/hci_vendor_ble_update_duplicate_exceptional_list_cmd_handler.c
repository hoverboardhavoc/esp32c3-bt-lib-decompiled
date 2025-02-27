/*
 * Last changed at upstream commit 0cfafa1e0aa30b7d59f53c38588f0598e228d127
 * https://github.com/espressif/esp32c3-bt-lib/commit/0cfafa1e0aa30b7d59f53c38588f0598e228d127
 * Upstream date: 2025-02-27 20:50:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b34b7d6)
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
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar3 + 0x23) == '\0') {
    puVar4 = (undefined1 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x1101,0xfd08,0x10,*(code **)(_r_modules_funcs_p + 200));
    *puVar4 = 0xc;
    cVar1 = *param_1;
    *(undefined4 *)(puVar4 + 4) = 0;
    puVar4[1] = cVar1;
    (**(code **)(_r_ip_funcs_p + 0x8c))(*(code **)(_r_ip_funcs_p + 0x8c));
    return 0;
  }
  uVar2 = (**(code **)(_r_ip_funcs_p + 0x8cc))
                    (*param_1,*(undefined4 *)(param_1 + 4),param_1 + 8,
                     *(code **)(_r_ip_funcs_p + 0x8cc));
  puVar4 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,param_2,0xfd08,0x10,*(code **)(_r_modules_funcs_p + 200));
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
      goto _L133;
    }
    uVar6 = 6;
  }
  *(undefined4 *)(puVar4 + 4) = uVar6;
_L133:
  if (cVar1 == '\x02') {
    *(undefined4 *)(puVar4 + 4) = 0;
  }
  memcpy(puVar4 + 8,param_1 + 8,*(size_t *)(puVar4 + 4));
  (**(code **)(_r_ip_funcs_p + 0x8c))(puVar4,*(code **)(_r_ip_funcs_p + 0x8c));
  return 0;
}

