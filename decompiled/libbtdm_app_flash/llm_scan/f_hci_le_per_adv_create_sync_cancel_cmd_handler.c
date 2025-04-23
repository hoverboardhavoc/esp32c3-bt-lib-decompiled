/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_scan.o -> f_hci_le_per_adv_create_sync_cancel_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_per_adv_create_sync_cancel_cmd_handler(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined2 *puVar4;
  int *piVar5;
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
    uVar2 = 0;
    iVar1 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar2 = r_llm_activity_syncing_get();
    iVar3 = r_sdk_config_get_opts();
    iVar1 = 0xc;
    if (uVar2 < *(byte *)(iVar3 + 0xd)) {
      iVar1 = r_lld_scan_create_sync_cancel(uVar2);
      if (iVar1 != 0) {
        iVar1 = r_lld_sync_stop(uVar2);
        if (iVar1 != 0) {
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
      piVar5 = (int *)(*(int *)(_p_llm_env + 8) + uVar2 * 0x44);
      *(undefined1 *)(piVar5 + 0x10) = 0;
      r_ke_msg_free(*piVar5 + -0xc);
      *(undefined4 *)(*(int *)(_p_llm_env + 8) + uVar2 * 0x44) = 0;
      iVar1 = 0;
      if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
         ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
        (*(code *)*_bt_rf_coex_hooks_p)(uVar2,6,0);
      }
    }
  }
  r_llm_cmd_cmp_send(param_2,iVar1);
  if (iVar1 == 0) {
    puVar4 = (undefined2 *)r_ke_msg_alloc(0x1104,0,0x3e,0x12);
    puVar4[1] = (short)uVar2;
    *puVar4 = 0x440e;
    iVar1 = *(int *)(_p_llm_env + 8) + uVar2 * 0x44;
    *(undefined1 *)(puVar4 + 2) = *(undefined1 *)(iVar1 + 0x28);
    *(undefined1 *)((int)puVar4 + 5) = *(undefined1 *)(iVar1 + 0x41);
    memcpy(puVar4 + 3,(void *)(iVar1 + 4),6);
    *(undefined1 *)(puVar4 + 6) = 1;
    puVar4[7] = 6;
    *(undefined1 *)(puVar4 + 8) = 0;
    r_hci_send_2_host(puVar4);
  }
  return 0;
}

