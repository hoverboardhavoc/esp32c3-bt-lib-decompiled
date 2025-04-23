/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_scan.o -> hci_le_per_adv_create_sync_cancel_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_per_adv_create_sync_cancel_cmd_handler(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar4 + 0x18) == '\0') {
    r_llm_cmd_cmp_send(param_2,0xc);
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
    uVar1 = 0;
    iVar4 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar1 = r_llm_activity_syncing_get();
    iVar2 = r_sdk_config_get_opts();
    iVar4 = 0xc;
    if (uVar1 < *(byte *)(iVar2 + 0xd)) {
      iVar4 = r_lld_scan_create_sync_cancel(uVar1);
      if (iVar4 != 0) {
        iVar4 = r_lld_sync_stop(uVar1);
        if (iVar4 != 0) {
          r_ke_msg_forward(param_1,0,param_2);
          return 1;
        }
        if (_bt_rf_coex_hooks_p == (undefined4 *)0x0) {
          return 0;
        }
        if ((code *)*_bt_rf_coex_hooks_p == (code *)0x0) {
          return 0;
        }
        (*(code *)*_bt_rf_coex_hooks_p)(uVar1,5,0);
        return 0;
      }
      piVar5 = (int *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44);
      *(undefined1 *)(piVar5 + 0x10) = 0;
      r_ke_msg_free(*piVar5 + -0xc);
      *(undefined4 *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44) = 0;
      iVar4 = 0;
      if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
         ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
        (*(code *)*_bt_rf_coex_hooks_p)(uVar1,6,0);
      }
    }
  }
  r_llm_cmd_cmp_send(param_2,iVar4);
  if (iVar4 == 0) {
    puVar3 = (undefined2 *)r_ke_msg_alloc(0x1104,0,0x3e,0x12);
    puVar3[1] = (short)uVar1;
    *puVar3 = 0x440e;
    iVar4 = *(int *)(_p_llm_env + 8) + uVar1 * 0x44;
    *(undefined1 *)(puVar3 + 2) = *(undefined1 *)(iVar4 + 0x28);
    *(undefined1 *)((int)puVar3 + 5) = *(undefined1 *)(iVar4 + 0x41);
    memcpy(puVar3 + 3,(void *)(iVar4 + 4),6);
    *(undefined1 *)(puVar3 + 6) = 1;
    puVar3[7] = 6;
    *(undefined1 *)(puVar3 + 8) = 0;
    r_hci_send_2_host(puVar3);
  }
  return 0;
}

