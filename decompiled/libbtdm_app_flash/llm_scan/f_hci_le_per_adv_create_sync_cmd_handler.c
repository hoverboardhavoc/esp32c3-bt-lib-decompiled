/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llm_scan.o -> f_hci_le_per_adv_create_sync_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 f_hci_le_per_adv_create_sync_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined1 uVar7;
  byte abStack_21 [9];
  
  bVar1 = *param_1;
  if ((((0x3ff6 < (ushort)(*(short *)(param_1 + 0xc) - 10U)) || (1 < (bVar1 | param_1[2]))) ||
      (0xf < param_1[1])) || (499 < *(ushort *)(param_1 + 10))) {
    r_ble_log_internal_x2
              (0x802e0184,CONCAT22(*(ushort *)(param_1 + 10),*(short *)(param_1 + 0xc)),
               (uint)param_1[2] << 8 | (uint)bVar1 << 0x18 | (uint)param_1[1] << 0x10 | 0x12);
    uVar7 = 0;
    uVar3 = 0x12;
    goto _L248;
  }
  if ((bVar1 == 1) && (iVar4 = llm_is_pal_empty(), iVar4 != 0)) {
    uVar3 = 0x10c;
    uVar5 = 0x802e0185;
_L267:
    r_ble_log_internal_x1(uVar5,uVar3);
  }
  else if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    abStack_21[0] = r_llm_activity_syncing_get();
    iVar4 = r_sdk_config_get_opts();
    if ((uint)*(byte *)(iVar4 + 0xd) <= (uint)abStack_21[0]) {
      if ((*param_1 == 0) &&
         (iVar4 = r_llm_is_dev_synced(param_1 + 3,param_1[2],param_1[1]), iVar4 != 0)) {
        r_ble_log_internal_x1(0x802e0187,(uint)*param_1 << 8 | 0xb);
        uVar3 = 0xb;
        uVar7 = 0;
      }
      else {
        uVar3 = r_llm_activity_free_get(abStack_21);
        uVar6 = (uint)abStack_21[0];
        if (uVar3 == 0) {
          *(undefined1 *)(*(int *)(_p_llm_env + 8) + uVar6 * 0x44 + 0x40) = 0xe;
          r_ble_log_internal_x1(0x404e0189,uVar6 | 0xe00);
          if (*(int *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44) != 0) {
            r_assert_err(0,"llm_scan.c",0x379);
          }
          bVar1 = param_1[5];
          bVar2 = param_1[7];
          uVar7 = 1;
          *(byte **)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44) = param_1;
          uVar3 = r_lld_scan_create_sync
                            (abStack_21[0],*param_1,param_1[1],param_1[2],
                             CONCAT13(param_1[6],CONCAT12(bVar1,*(undefined2 *)(param_1 + 3))),
                             CONCAT11(param_1[8],bVar2));
          if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
             ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
            (*(code *)*_bt_rf_coex_hooks_p)(abStack_21[0],6,1);
          }
        }
        else {
          r_ble_log_internal_x1(0x802e0188,uVar6 << 8 | uVar3);
          uVar7 = 0;
        }
      }
      goto _L248;
    }
    uVar3 = (uint)abStack_21[0] << 8 | 0xc;
    uVar5 = 0x802e0186;
    goto _L267;
  }
  uVar7 = 0;
  uVar3 = 0xc;
_L248:
  r_llm_cmd_stat_send(param_2,uVar3);
  return uVar7;
}

