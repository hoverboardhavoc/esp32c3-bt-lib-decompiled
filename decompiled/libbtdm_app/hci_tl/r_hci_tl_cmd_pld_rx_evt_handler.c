/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> hci_tl.o -> r_hci_tl_cmd_pld_rx_evt_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_tl_cmd_pld_rx_evt_handler(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x48))(*(code **)(_r_ip_funcs_p + 0x48));
  if (_hci_tl_env == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"hci_tl.c",0x5b0,*(code **)(_r_plf_funcs_p + 8));
  }
  (**(code **)(_r_modules_funcs_p + 0xec))(7,*(code **)(_r_modules_funcs_p + 0xec));
  (**(code **)(_r_ip_funcs_p + 0x2c))
            (*(undefined2 *)(iVar1 + 1),*(undefined1 *)(iVar1 + 3),iVar1 + 4,
             *(code **)(_r_ip_funcs_p + 0x2c));
                    /* WARNING: Could not recover jumptable at 0x00010c54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 0xdc))();
  return;
}

