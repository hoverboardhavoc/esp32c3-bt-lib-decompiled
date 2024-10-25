/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_scan.o -> hci_le_per_adv_create_sync_cancel_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_per_adv_create_sync_cancel_cmd_handler(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  int *piVar6;
  code *pcVar7;
  
  iVar5 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar5 + 0x18) == '\0') {
    r_llm_cmd_cmp_send(param_2,0xc);
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
    uVar2 = 0;
    iVar5 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar2 = r_llm_activity_syncing_get();
    iVar3 = r_sdk_config_get_opts();
    iVar5 = 0xc;
    if (uVar2 < *(byte *)(iVar3 + 0xd)) {
      iVar5 = r_lld_scan_create_sync_cancel(uVar2);
      if (iVar5 != 0) {
        iVar5 = r_lld_sync_stop(uVar2);
        if (iVar5 != 0) {
          r_ke_msg_forward(param_1,0,param_2);
          return 1;
        }
        if (_bt_rf_coex_hooks_p == (undefined4 *)0x0) {
          return 0;
        }
        if ((code *)*_bt_rf_coex_hooks_p == (code *)0x0) {
          return 0;
        }
        (*(code *)*_bt_rf_coex_hooks_p)(uVar2,5,0);
        return 0;
      }
      piVar6 = (int *)(*(int *)(_p_llm_env + 8) + uVar2 * 0x44);
      *(undefined1 *)(piVar6 + 0x10) = 0;
      r_ke_msg_free(*piVar6 + -0xc);
      puVar1 = _bt_rf_coex_hooks_p;
      *(undefined4 *)(uVar2 * 0x44 + *(int *)(_p_llm_env + 8)) = 0;
      iVar5 = 0;
      if ((puVar1 != (undefined4 *)0x0) && (pcVar7 = (code *)*puVar1, pcVar7 != (code *)0x0)) {
        (*pcVar7)(uVar2,6,0);
      }
    }
  }
  r_llm_cmd_cmp_send(param_2,iVar5);
  if (iVar5 == 0) {
    puVar4 = (undefined2 *)r_ke_msg_alloc(0x1104,0,0x3e,0x12);
    puVar4[1] = (short)uVar2;
    *puVar4 = 0x440e;
    iVar5 = *(int *)(_p_llm_env + 8) + uVar2 * 0x44;
    *(undefined1 *)(puVar4 + 2) = *(undefined1 *)(iVar5 + 0x28);
    *(undefined1 *)((int)puVar4 + 5) = *(undefined1 *)(iVar5 + 0x41);
    memcpy(puVar4 + 3,(void *)(iVar5 + 4),6);
    *(undefined1 *)(puVar4 + 6) = 1;
    puVar4[7] = 6;
    *(undefined1 *)(puVar4 + 8) = 0;
    r_hci_send_2_host(puVar4);
  }
  return 0;
}

