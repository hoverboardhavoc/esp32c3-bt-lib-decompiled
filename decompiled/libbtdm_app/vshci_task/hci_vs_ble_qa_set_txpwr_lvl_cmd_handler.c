/*
 * Last changed at upstream commit ef1dfc518572e9cda55f13906e32207b40ee280b
 * https://github.com/espressif/esp32c3-bt-lib/commit/ef1dfc518572e9cda55f13906e32207b40ee280b
 * Upstream date: 2024-08-07 12:57:51 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(f583012)
 * Source: libbtdm_app -> vshci_task.o -> hci_vs_ble_qa_set_txpwr_lvl_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
hci_vs_ble_qa_set_txpwr_lvl_cmd_handler(undefined1 param_1,undefined1 *param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,param_3,0xfd13,2,*(code **)(_r_modules_funcs_p + 200));
  *puVar1 = 0;
  iVar2 = ble_txpwr_set(*param_2,0xffff,*(undefined4 *)(param_2 + 1));
  if (iVar2 != 0) {
    *puVar1 = 0x12;
  }
  puVar1[1] = param_1;
  (**(code **)(_r_ip_funcs_p + 0x8c))(puVar1,*(code **)(_r_ip_funcs_p + 0x8c));
  return 0;
}

