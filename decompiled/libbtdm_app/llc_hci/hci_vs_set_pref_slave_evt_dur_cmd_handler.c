/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_hci.o -> hci_vs_set_pref_slave_evt_dur_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_vs_set_pref_slave_evt_dur_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  uVar2 = 0xc;
  if (param_1 < *(byte *)(iVar1 + 0xd)) {
    uVar2 = 0xc;
    if ((*(int *)(&llc_env + param_1 * 4) != 0) &&
       ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
      (**(code **)(_r_ip_funcs_p + 0x380))
                (param_1,*(undefined2 *)(param_2 + 2),*(char *)(param_2 + 4) != '\0',
                 *(code **)(_r_ip_funcs_p + 0x380));
      uVar2 = 0;
    }
  }
  (**(code **)(_r_ip_funcs_p + 0x630))(param_1,param_3,uVar2,*(code **)(_r_ip_funcs_p + 0x630));
  return 0;
}

