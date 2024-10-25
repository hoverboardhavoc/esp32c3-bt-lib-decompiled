/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_rmv_dev_from_rslv_list_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rmv_dev_from_rslv_list_cmd_handler(byte *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0x12;
  if (*param_1 < 2) {
    if (*(char *)(_p_llm_env + 0xc6) != '\0') {
      iVar1 = 0xc;
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x504))(*(code **)(_r_ip_funcs_p + 0x504));
      if (iVar2 != 0) goto _L140;
    }
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x290))
                      (param_1 + 1,*param_1,*(code **)(_r_ip_funcs_p + 0x290));
    if ((iVar1 == 0) && (iVar2 = lld_ral_valid_count(), iVar2 == 0)) {
      (**(code **)(_r_modules_funcs_p + 0xb8))(6,0,*(code **)(_r_modules_funcs_p + 0xb8));
    }
  }
_L140:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar1,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

