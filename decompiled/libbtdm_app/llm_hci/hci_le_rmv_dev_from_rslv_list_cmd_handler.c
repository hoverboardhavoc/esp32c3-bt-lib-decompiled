/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
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
      if (iVar2 != 0) goto _L149;
    }
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x290))
                      (param_1 + 1,*param_1,*(code **)(_r_ip_funcs_p + 0x290));
    if ((iVar1 == 0) && (iVar2 = lld_ral_valid_count(), iVar2 == 0)) {
      (**(code **)(_r_modules_funcs_p + 0xb8))(6,0,*(code **)(_r_modules_funcs_p + 0xb8));
    }
  }
_L149:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar1,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

