/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> vshci_task.o -> f_hci_vendor_ble_init_adv_flow_control_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
f_hci_vendor_ble_init_adv_flow_control_cmd_handler(undefined1 *param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  
  uVar2 = 0x12;
  if (param_1 != (undefined1 *)0x0) {
    uVar2 = 0;
    (**(code **)(_r_ip_funcs_p + 0x528))
              (*param_1,*(undefined2 *)(param_1 + 2),*(undefined2 *)(param_1 + 4),
               *(code **)(_r_ip_funcs_p + 0x528));
  }
  puVar1 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,param_2,0xfd09,1,*(code **)(_r_modules_funcs_p + 200));
  *puVar1 = uVar2;
  (**(code **)(_r_ip_funcs_p + 0x8c))(*(code **)(_r_ip_funcs_p + 0x8c));
  return 0;
}

