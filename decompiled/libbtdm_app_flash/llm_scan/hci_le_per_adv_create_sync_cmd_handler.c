/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_scan.o -> hci_le_per_adv_create_sync_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 hci_le_per_adv_create_sync_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined1 uVar6;
  byte abStack_21 [9];
  
  iVar4 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar4 + 0x18) == '\0') {
    r_llm_cmd_stat_send(param_2,0xc);
    return 0;
  }
  if (((((ushort)(*(short *)(param_1 + 0xc) - 10U) < 0x3ff7) && (*param_1 < 2)) && (param_1[2] < 2))
     && ((param_1[1] < 0x10 && (*(ushort *)(param_1 + 10) < 500)))) {
    if (((*param_1 != 1) || (iVar4 = llm_is_pal_empty(), iVar4 == 0)) &&
       (*(char *)(_p_llm_env + 0xd7) != '\x01')) {
      *(undefined1 *)(_p_llm_env + 0xd7) = 2;
      abStack_21[0] = r_llm_activity_syncing_get();
      iVar4 = r_sdk_config_get_opts();
      if (*(byte *)(iVar4 + 0xd) <= abStack_21[0]) {
        if (*param_1 == 0) {
          iVar4 = 0xb;
          iVar3 = r_llm_is_dev_synced(param_1 + 3,param_1[2],param_1[1]);
          uVar6 = 0;
          if (iVar3 != 0) goto _L243;
        }
        iVar4 = r_llm_activity_free_get(abStack_21);
        uVar6 = 0;
        if (iVar4 == 0) {
          piVar5 = (int *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
          *(undefined1 *)(piVar5 + 0x10) = 0xe;
          if (*piVar5 != 0) {
            r_assert_err("llm_scan.c",0x334);
          }
          bVar1 = param_1[5];
          bVar2 = param_1[7];
          *(byte **)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44) = param_1;
          iVar4 = r_lld_scan_create_sync
                            (*param_1,param_1[1],param_1[2],
                             CONCAT13(param_1[6],CONCAT12(bVar1,*(undefined2 *)(param_1 + 3))),
                             CONCAT11(param_1[8],bVar2));
          if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
             ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
            (*(code *)*_bt_rf_coex_hooks_p)(abStack_21[0],6,1);
          }
          uVar6 = 1;
        }
        goto _L243;
      }
    }
    uVar6 = 0;
    iVar4 = 0xc;
  }
  else {
    uVar6 = 0;
    iVar4 = 0x12;
  }
_L243:
  r_llm_cmd_stat_send(param_2,iVar4);
  return uVar6;
}

