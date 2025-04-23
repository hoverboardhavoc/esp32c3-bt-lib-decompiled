/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_clear_rslv_list_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_clear_rslv_list_cmd_handler(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = param_1;
  if (*(char *)(_p_llm_env + 0xc6) != '\0') {
    iVar1 = r_llm_is_non_con_act_ongoing_check();
    uVar2 = 0xc;
    uVar3 = 0xc;
    if (iVar1 != 0) goto _L270;
  }
  r_lld_res_list_clear(uVar2);
  iVar1 = lld_ral_valid_count();
  if (iVar1 == 0) {
    r_ke_timer_clear(6,0);
  }
  uVar3 = 0;
_L270:
  r_llm_cmd_cmp_send(param_1,uVar3);
  return 0;
}

