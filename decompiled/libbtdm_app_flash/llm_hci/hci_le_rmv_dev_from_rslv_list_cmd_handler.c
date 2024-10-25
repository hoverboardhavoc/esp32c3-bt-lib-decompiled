/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
      if (iVar2 != 0) goto _L269;
    }
    iVar1 = r_lld_res_list_rem(param_1 + 1,*param_1);
    if ((iVar1 == 0) && (iVar2 = lld_ral_valid_count(), iVar2 == 0)) {
      r_ke_timer_clear(6,0);
    }
  }
_L269:
  r_llm_cmd_cmp_send(param_2,iVar1);
  return 0;
}

