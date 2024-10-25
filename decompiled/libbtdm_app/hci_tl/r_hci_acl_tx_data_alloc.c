/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> hci_tl.o -> r_hci_acl_tx_data_alloc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_hci_acl_tx_data_alloc(uint param_1,uint param_2)

{
  int iVar1;
  byte *pbVar2;
  undefined1 *puVar3;
  
  pbVar2 = (byte *)(**(code **)(_r_plf_funcs_p + 0x20))(*(code **)(_r_plf_funcs_p + 0x20));
  if ((param_1 & 0xfff) < (uint)*pbVar2) {
    iVar1 = 0;
    if (((param_1 >> 0xe == 0) && (param_2 < 0xfc)) &&
       (iVar1 = (**(code **)(_r_ip_funcs_p + 0xc4))(param_2,*(code **)(_r_ip_funcs_p + 0xc4)),
       iVar1 == 0)) {
      puVar3 = (undefined1 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x1103,0,0x1a,1,*(code **)(_r_modules_funcs_p + 200));
      *puVar3 = 1;
      (**(code **)(_r_ip_funcs_p + 0x8c))(*(code **)(_r_ip_funcs_p + 0x8c));
      hci_tl_env = 1;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

