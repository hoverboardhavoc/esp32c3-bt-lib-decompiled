/*
 * Last changed at upstream commit d874f55e1132416fe18293ae1aa9ac73c40b3261
 * https://github.com/espressif/esp32c3-bt-lib/commit/d874f55e1132416fe18293ae1aa9ac73c40b3261
 * Upstream date: 2024-09-02 19:56:58 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(8ce789b)
 * Source: libbtdm_app -> vshci_task.o -> hci_vs_ble_qa_clear_rand_addr_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_vs_ble_qa_clear_rand_addr_cmd_handler(undefined1 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,param_2,0xfd13,2,*(code **)(_r_modules_funcs_p + 200));
  uVar1 = esp_ble_clear_rand_addr();
  *puVar2 = uVar1;
  puVar2[1] = param_1;
  (**(code **)(_r_ip_funcs_p + 0x8c))(puVar2,*(code **)(_r_ip_funcs_p + 0x8c));
  return 0;
}

