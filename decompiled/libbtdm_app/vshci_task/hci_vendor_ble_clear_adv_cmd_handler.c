/*
 * Last changed at upstream commit ec7ef197cb8018c468cd59dca893dbe018f47a2a
 * https://github.com/espressif/esp32c3-bt-lib/commit/ec7ef197cb8018c468cd59dca893dbe018f47a2a
 * Upstream date: 2023-10-26 19:39:25 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(f817304)
 * Source: libbtdm_app -> vshci_task.o -> hci_vendor_ble_clear_adv_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_vendor_ble_clear_adv_cmd_handler(undefined4 param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  uVar1 = llm_clear_adv();
  puVar2 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,param_1,0xfd0c,1,*(code **)(_r_modules_funcs_p + 200));
  *puVar2 = uVar1;
  (**(code **)(_r_ip_funcs_p + 0x8c))(*(code **)(_r_ip_funcs_p + 0x8c));
  return 0;
}

