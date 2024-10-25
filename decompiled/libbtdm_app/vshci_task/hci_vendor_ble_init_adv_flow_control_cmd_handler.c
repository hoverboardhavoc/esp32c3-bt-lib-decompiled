/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> vshci_task.o -> hci_vendor_ble_init_adv_flow_control_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_vendor_ble_init_adv_flow_control_cmd_handler(undefined1 *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar2 + 0x23) == '\0') {
    puVar3 = (undefined1 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x1101,param_2,0xfd09,1,*(code **)(_r_modules_funcs_p + 200));
    *puVar3 = 0xc;
    (**(code **)(_r_ip_funcs_p + 0x8c))(*(code **)(_r_ip_funcs_p + 0x8c));
    return 0;
  }
  uVar1 = 0x12;
  if (param_1 != (undefined1 *)0x0) {
    uVar1 = 0;
    (**(code **)(_r_ip_funcs_p + 0x528))
              (*param_1,*(undefined2 *)(param_1 + 2),*(undefined2 *)(param_1 + 4),
               *(code **)(_r_ip_funcs_p + 0x528));
  }
  puVar3 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,param_2,0xfd09,1,*(code **)(_r_modules_funcs_p + 200));
  *puVar3 = uVar1;
  (**(code **)(_r_ip_funcs_p + 0x8c))(*(code **)(_r_ip_funcs_p + 0x8c));
  return 0;
}

