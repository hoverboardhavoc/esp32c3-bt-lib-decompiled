/*
 * Last changed at upstream commit 76ed4114ee7d081435a3c65793b4c8eb1dfaf199
 * https://github.com/espressif/esp32c3-bt-lib/commit/76ed4114ee7d081435a3c65793b4c8eb1dfaf199
 * Upstream date: 2024-04-09 17:28:48 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(c23ab4c)
 * Source: libbtdm_app -> vshci_task.o -> hci_vs_ble_qa_set_scan_aa_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
hci_vs_ble_qa_set_scan_aa_cmd_handler(undefined1 param_1,undefined2 *param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,param_3,0xfd13,2,*(code **)(_r_modules_funcs_p + 200));
  *puVar1 = 0;
  iVar2 = ble_ll_scan_aa_setting(*param_2,param_2[1]);
  if (iVar2 != 0) {
    *puVar1 = 0x12;
  }
  puVar1[1] = param_1;
  (**(code **)(_r_ip_funcs_p + 0x8c))(puVar1,*(code **)(_r_ip_funcs_p + 0x8c));
  return 0;
}

