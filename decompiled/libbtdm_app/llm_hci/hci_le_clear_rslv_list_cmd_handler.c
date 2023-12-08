/*
 * Last changed at upstream commit bb9f0f59db474924c9288ab92aed1abb88bc9419
 * https://github.com/espressif/esp32c3-bt-lib/commit/bb9f0f59db474924c9288ab92aed1abb88bc9419
 * Upstream date: 2023-12-08 13:35:16 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(65db61f)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_clear_rslv_list_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_clear_rslv_list_cmd_handler(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(char *)(_p_llm_env + 0xc6) != '\0') {
    uVar1 = 0xc;
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x504))(*(code **)(_r_ip_funcs_p + 0x504));
    if (iVar2 != 0) goto _L168;
  }
  (**(code **)(_r_ip_funcs_p + 0x278))(*(code **)(_r_ip_funcs_p + 0x278));
  iVar2 = lld_ral_valid_count();
  if (iVar2 == 0) {
    (**(code **)(_r_modules_funcs_p + 0xb8))(6,0,*(code **)(_r_modules_funcs_p + 0xb8));
    uVar1 = 0;
  }
  else {
    uVar1 = 0;
  }
_L168:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_1,uVar1,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

