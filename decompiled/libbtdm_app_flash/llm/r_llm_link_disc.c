/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llm.o -> r_llm_link_disc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_link_disc(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = param_1 * 0x44;
  iVar3 = *(int *)(_p_llm_env + 8) + iVar1;
  *(undefined1 *)(iVar3 + 0x40) = 0;
  r_ble_log_internal_x1(0x404e0148,param_1);
  r_sch_plan_rem(iVar3 + 0xc);
  iVar3 = *(int *)(_p_llm_env + 8) + iVar1;
  uVar2 = r_llm_dev_list_search(iVar3 + 4,*(undefined1 *)(iVar3 + 0x41));
  if (uVar2 < 0xc) {
    if ((*(byte *)(uVar2 * 10 + _p_llm_env + 0x2d) & 2) != 0) {
      iVar3 = *(int *)(_p_llm_env + 8) + iVar1;
      r_lld_white_list_add(iVar3 + 4,*(undefined1 *)(iVar3 + 0x41));
    }
  }
  iVar1 = *(int *)(_p_llm_env + 8) + iVar1;
  uVar2 = 0;
  r_lld_res_list_peer_update_hack(iVar1 + 4,*(undefined1 *)(iVar1 + 0x41),0);
  r_hci_ble_conhdl_unregister(param_1);
  while( true ) {
    iVar1 = r_sdk_config_get_opts();
    if ((*(byte *)(iVar1 + 0xd) <= uVar2) ||
       (*(char *)(*(int *)(_p_llm_env + 8) + uVar2 * 0x44 + 0x40) == '\t')) break;
    uVar2 = uVar2 + 1 & 0xff;
  }
  iVar1 = r_sdk_config_get_opts();
  if (((*(byte *)(iVar1 + 0xd) <= uVar2) && (_bt_rf_coex_hooks_p != (undefined4 *)0x0)) &&
     ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x000110be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*_bt_rf_coex_hooks_p)(param_1,7,0);
    return;
  }
  return;
}

