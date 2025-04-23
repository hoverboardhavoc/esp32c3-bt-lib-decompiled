/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_rmv_dev_from_rslv_list_cmd_handler
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
      iVar2 = r_llm_is_non_con_act_ongoing_check();
      iVar1 = 0xc;
      if (iVar2 != 0) goto _L275;
    }
    iVar1 = r_lld_res_list_rem(param_1 + 1,*param_1);
    if ((iVar1 == 0) && (iVar2 = lld_ral_valid_count(), iVar2 == 0)) {
      r_ke_timer_clear(6,0);
    }
  }
_L275:
  r_llm_cmd_cmp_send(param_2,iVar1);
  return 0;
}

