/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> vshci_task.o -> hci_vendor_ble_update_duplicate_exceptional_list_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
hci_vendor_ble_update_duplicate_exceptional_list_cmd_handler
          (undefined4 param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  code *pcVar4;
  
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar2 + 0x23) == '\0') {
    puVar3 = (undefined1 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x1101,0xfd08,0xc,*(code **)(_r_modules_funcs_p + 200));
    *puVar3 = 0xc;
    uVar1 = *param_2;
    puVar3[2] = 0;
    puVar3[1] = uVar1;
    iVar2 = _r_ip_funcs_p;
    puVar3[3] = 0;
    puVar3[4] = 0;
    pcVar4 = *(code **)(iVar2 + 0x8c);
    puVar3[5] = 0;
    (*pcVar4)(pcVar4);
  }
  else {
    f_hci_vendor_ble_update_duplicate_exceptional_list_cmd_handler(param_1,param_2,param_3,param_4);
  }
  return 0;
}

