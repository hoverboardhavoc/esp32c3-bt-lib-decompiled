/*
 * Last changed at upstream commit c57c0b11c3c0065a16b66685715100a189ef9b27
 * https://github.com/espressif/esp32c3-bt-lib/commit/c57c0b11c3c0065a16b66685715100a189ef9b27
 * Upstream date: 2024-12-13 13:39:25 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(555b0a2)
 * Source: libbtdm_app_flash -> llm_scan.o -> hci_le_per_adv_create_sync_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_per_adv_create_sync_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
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
        if ((*param_1 == 0) &&
           (iVar4 = r_llm_is_dev_synced(param_1 + 3,param_1[2],param_1[1]), iVar4 != 0)) {
          uVar3 = 0;
          iVar4 = 0xb;
        }
        else {
          iVar4 = r_llm_activity_free_get(abStack_21);
          uVar3 = 0;
          if (iVar4 == 0) {
            piVar5 = (int *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
            *(undefined1 *)(piVar5 + 0x10) = 0xe;
            if (*piVar5 != 0) {
              r_assert_err("llm_scan.c",0x334);
            }
            bVar1 = param_1[7];
            uVar3 = 1;
            uVar2 = *(undefined2 *)(param_1 + 3);
            *(byte **)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44) = param_1;
            iVar4 = r_lld_scan_create_sync
                              (*param_1,param_1[1],param_1[2],
                               CONCAT13(param_1[6],CONCAT12(param_1[5],uVar2)),
                               CONCAT11(param_1[8],bVar1));
            if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
               ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
              (*(code *)*_bt_rf_coex_hooks_p)(abStack_21[0],6,1);
            }
          }
        }
        goto _L253;
      }
    }
    uVar3 = 0;
    iVar4 = 0xc;
  }
  else {
    uVar3 = 0;
    iVar4 = 0x12;
  }
_L253:
  r_llm_cmd_stat_send(param_2,iVar4);
  return uVar3;
}

