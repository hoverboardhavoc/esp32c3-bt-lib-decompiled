/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> hci.o -> r_hci_ble_conhdl_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_ble_conhdl_register(uint param_1)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (*(byte *)(iVar2 + 0xd) <= param_1) {
    pcVar1 = *(code **)(_r_plf_funcs_p + 0xc);
    iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    (*pcVar1)(param_1,*(undefined1 *)(iVar2 + 0xd),"hci.c",0x4e3);
  }
  if ((&hci_rsvd_evt_msk)[param_1] != '\0') {
    (**(code **)(_r_plf_funcs_p + 8))(0,"hci.c",0x4e4,*(code **)(_r_plf_funcs_p + 8));
  }
  (&hci_rsvd_evt_msk)[param_1] = 1;
  return;
}

