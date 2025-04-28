/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> vshci_task.o -> hci_vendor_ble_init_adv_flow_control_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_vendor_ble_init_adv_flow_control_cmd_handler(undefined1 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar1 + 0x23) == '\0') {
    puVar2 = (undefined1 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x1101,param_2,0xfd09,1,*(code **)(_r_modules_funcs_p + 200));
    *puVar2 = 0xc;
    (**(code **)(_r_ip_funcs_p + 0x8c))(*(code **)(_r_ip_funcs_p + 0x8c));
    return 0;
  }
  uVar3 = 0x12;
  if (param_1 != (undefined1 *)0x0) {
    uVar3 = 0;
    (**(code **)(_r_ip_funcs_p + 0x528))
              (*param_1,*(undefined2 *)(param_1 + 2),*(undefined2 *)(param_1 + 4),
               *(code **)(_r_ip_funcs_p + 0x528));
  }
  puVar2 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,param_2,0xfd09,1,*(code **)(_r_modules_funcs_p + 200));
  *puVar2 = uVar3;
  (**(code **)(_r_ip_funcs_p + 0x8c))(*(code **)(_r_ip_funcs_p + 0x8c));
  return 0;
}

