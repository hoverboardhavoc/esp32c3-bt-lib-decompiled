/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
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
  
  if (*param_1 < 2) {
    if ((*(char *)(_p_llm_env + 0xc6) == '\0') ||
       (iVar1 = r_llm_is_non_con_act_ongoing_check(), iVar1 == 0)) {
      iVar1 = r_lld_res_list_rem_hack(param_1 + 1,*param_1);
      if ((iVar1 == 0) && (iVar2 = lld_ral_valid_count(), iVar2 == 0)) {
        r_ke_timer_clear(6,0);
      }
    }
    else {
      iVar1 = 0xc;
      r_ble_log_internal_x1(0x802e01d5,(uint)*(byte *)(_p_llm_env + 0xc6) << 8 | 0xc);
    }
  }
  else {
    r_ble_log_internal_x1(0x802e01d4,(uint)*param_1 << 8 | 0x12);
    iVar1 = 0x12;
  }
  r_llm_cmd_cmp_send(param_2,iVar1);
  return 0;
}

