/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_le_ping.o -> hci_wr_auth_payl_to_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_wr_auth_payl_to_cmd_handler(uint param_1,undefined2 *param_2)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,*param_2,0xc7c,4,*(code **)(_r_modules_funcs_p + 200));
  iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if ((((param_1 < *(byte *)(iVar3 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
      ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) &&
     (iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0)),
     *(char *)(iVar3 + 0x20) != '\0')) {
    uVar1 = (**(code **)(_r_ip_funcs_p + 0x614))
                      (param_1,param_2[1],*(code **)(_r_ip_funcs_p + 0x614));
  }
  else {
    uVar1 = 0xc;
  }
  *puVar2 = uVar1;
  *(undefined2 *)(puVar2 + 2) = *param_2;
  (**(code **)(_r_ip_funcs_p + 0x8c))(puVar2,*(code **)(_r_ip_funcs_p + 0x8c));
  return 0;
}

