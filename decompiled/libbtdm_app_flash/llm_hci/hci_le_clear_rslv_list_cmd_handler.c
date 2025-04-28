/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  undefined4 uVar1;
  int iVar2;
  
  if (*(char *)(_p_llm_env + 0xc6) != '\0') {
    iVar2 = r_llm_is_non_con_act_ongoing_check();
    uVar1 = 0xc;
    if (iVar2 != 0) goto _L277;
  }
  r_lld_res_list_clear();
  iVar2 = lld_ral_valid_count();
  if (iVar2 == 0) {
    r_ke_timer_clear(6,0);
    uVar1 = 0;
  }
  else {
    uVar1 = 0;
  }
_L277:
  r_llm_cmd_cmp_send(param_1,uVar1);
  return 0;
}

