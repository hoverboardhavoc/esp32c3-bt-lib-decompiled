/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_scan.o -> f_hci_le_per_adv_create_sync_cancel_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_per_adv_create_sync_cancel_cmd_handler(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined2 *puVar5;
  int *piVar6;
  code *pcVar7;
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
    uVar3 = 0;
    iVar2 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar3 = r_llm_activity_syncing_get();
    iVar4 = r_sdk_config_get_opts();
    iVar2 = 0xc;
    if (uVar3 < *(byte *)(iVar4 + 0xd)) {
      iVar2 = r_lld_scan_create_sync_cancel(uVar3);
      if (iVar2 != 0) {
        iVar2 = r_lld_sync_stop(uVar3);
        if (iVar2 != 0) {
          r_ke_msg_forward(param_1,0,param_2);
          return 1;
        }
        if (_bt_rf_coex_hooks_p == (undefined4 *)0x0) {
          return 0;
        }
        if ((code *)*_bt_rf_coex_hooks_p == (code *)0x0) {
          return 0;
        }
        (*(code *)*_bt_rf_coex_hooks_p)(uVar3,5,0);
        return 0;
      }
      piVar6 = (int *)(*(int *)(_p_llm_env + 8) + uVar3 * 0x44);
      *(undefined1 *)(piVar6 + 0x10) = 0;
      r_ke_msg_free(*piVar6 + -0xc);
      puVar1 = _bt_rf_coex_hooks_p;
      *(undefined4 *)(uVar3 * 0x44 + *(int *)(_p_llm_env + 8)) = 0;
      iVar2 = 0;
      if ((puVar1 != (undefined4 *)0x0) && (pcVar7 = (code *)*puVar1, pcVar7 != (code *)0x0)) {
        (*pcVar7)(uVar3,6,0);
      }
    }
  }
  r_llm_cmd_cmp_send(param_2,iVar2);
  if (iVar2 == 0) {
    puVar5 = (undefined2 *)r_ke_msg_alloc(0x1104,0,0x3e,0x12);
    puVar5[1] = (short)uVar3;
    *puVar5 = 0x440e;
    iVar2 = *(int *)(_p_llm_env + 8) + uVar3 * 0x44;
    *(undefined1 *)(puVar5 + 2) = *(undefined1 *)(iVar2 + 0x28);
    *(undefined1 *)((int)puVar5 + 5) = *(undefined1 *)(iVar2 + 0x41);
    memcpy(puVar5 + 3,(void *)(iVar2 + 4),6);
    *(undefined1 *)(puVar5 + 6) = 1;
    puVar5[7] = 6;
    *(undefined1 *)(puVar5 + 8) = 0;
    r_hci_send_2_host(puVar5);
  }
  return 0;
}

