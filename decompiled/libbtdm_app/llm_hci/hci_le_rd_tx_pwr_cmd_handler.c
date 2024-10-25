/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_rd_tx_pwr_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rd_tx_pwr_cmd_handler(void)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,0,0x204b,3,*(code **)(_r_modules_funcs_p + 200));
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  uVar1 = 0xc;
  if (*(char *)(iVar3 + 0x18) != '\0') {
    uVar1 = 0;
  }
  *puVar2 = uVar1;
  uVar1 = (*_lld_wl_rpa_res)(rw_rf_le_exit_test_mode,1,_lld_wl_rpa_res);
  puVar2[1] = uVar1;
  uVar1 = (*_lld_wl_rpa_res)(DAT_00012049,1,_lld_wl_rpa_res);
  puVar2[2] = uVar1;
  (**(code **)(_r_ip_funcs_p + 0x8c))(puVar2,*(code **)(_r_ip_funcs_p + 0x8c));
  return 0;
}

