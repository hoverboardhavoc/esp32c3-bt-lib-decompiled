/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  size_t __n;
  code *pcVar5;
  
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar3 + 0x23) == '\0') {
    puVar4 = (undefined1 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x1101,0xfd08,0xc,*(code **)(_r_modules_funcs_p + 200));
    *puVar4 = 0xc;
    cVar1 = *param_1;
    puVar4[2] = 0;
    puVar4[1] = cVar1;
    iVar3 = _r_ip_funcs_p;
    puVar4[3] = 0;
    puVar4[4] = 0;
    pcVar5 = *(code **)(iVar3 + 0x8c);
    puVar4[5] = 0;
    (*pcVar5)(pcVar5);
    return 0;
  }
  uVar2 = (**(code **)(_r_ip_funcs_p + 0x8cc))
                    (*param_1,*(undefined4 *)(param_1 + 4),param_1 + 8,
                     *(code **)(_r_ip_funcs_p + 0x8cc));
  puVar4 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,param_2,0xfd08,0xc,*(code **)(_r_modules_funcs_p + 200));
  *puVar4 = uVar2;
  cVar1 = *param_1;
  __n = 6;
  puVar4[1] = cVar1;
  if (*(int *)(param_1 + 4) != 0) {
    __n = (uint)(*(int *)(param_1 + 4) == 1) << 2;
  }
  if (cVar1 == '\x02') {
    __n = 0;
  }
  puVar4[2] = (char)__n;
  puVar4[3] = 0;
  puVar4[4] = 0;
  puVar4[5] = 0;
  memcpy(puVar4 + 6,param_1 + 8,__n);
  (**(code **)(_r_ip_funcs_p + 0x8c))(puVar4,*(code **)(_r_ip_funcs_p + 0x8c));
  return 0;
}

