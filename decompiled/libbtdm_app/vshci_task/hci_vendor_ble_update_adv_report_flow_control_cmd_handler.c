/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> vshci_task.o -> hci_vendor_ble_update_adv_report_flow_control_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
hci_vendor_ble_update_adv_report_flow_control_cmd_handler
          (short *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar1 + 0x23) == '\0') {
    puVar2 = (undefined1 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x1101,param_3,0xfd0a,1,*(code **)(_r_modules_funcs_p + 200));
    *puVar2 = 0xc;
    (**(code **)(_r_ip_funcs_p + 0x8c))(*(code **)(_r_ip_funcs_p + 0x8c));
    return 0;
  }
  if ((param_1 == (short *)0x0) || (*param_1 == 0)) {
    puVar2 = (undefined1 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x1101,param_3,0xfd0a,1,*(code **)(_r_modules_funcs_p + 200));
    *puVar2 = 0x12;
    (**(code **)(_r_ip_funcs_p + 0x8c))(*(code **)(_r_ip_funcs_p + 0x8c));
  }
  else {
    (**(code **)(_r_ip_funcs_p + 0x52c))(param_2,*(code **)(_r_ip_funcs_p + 0x52c));
    (**(code **)(_r_ip_funcs_p + 0x60))(*(code **)(_r_ip_funcs_p + 0x60));
    (**(code **)(_r_ip_funcs_p + 0x34))(*(code **)(_r_ip_funcs_p + 0x34));
  }
  return 0;
}

