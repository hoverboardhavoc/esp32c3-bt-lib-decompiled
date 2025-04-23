/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  r_sch_plan_rem(iVar3 + 0xc);
  iVar3 = *(int *)(_p_llm_env + 8) + iVar1;
  iVar3 = r_llm_dev_list_search(iVar3 + 4,*(undefined1 *)(iVar3 + 0x41));
  if (iVar3 != 0xc) {
    if ((*(byte *)(iVar3 * 10 + _p_llm_env + 0x2d) & 2) != 0) {
      iVar3 = *(int *)(_p_llm_env + 8) + iVar1;
      r_lld_white_list_add(iVar3 + 4,*(undefined1 *)(iVar3 + 0x41));
    }
  }
  iVar1 = *(int *)(_p_llm_env + 8) + iVar1;
  uVar2 = 0;
  r_lld_res_list_peer_update(iVar1 + 4,*(undefined1 *)(iVar1 + 0x41),0);
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
                    /* WARNING: Could not recover jumptable at 0x00010f64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*_bt_rf_coex_hooks_p)(param_1,7,0);
    return;
  }
  return;
}

