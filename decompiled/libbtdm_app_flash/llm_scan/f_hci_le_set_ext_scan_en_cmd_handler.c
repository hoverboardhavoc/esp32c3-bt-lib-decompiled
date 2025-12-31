/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llm_scan.o -> f_hci_le_set_ext_scan_en_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_set_ext_scan_en_cmd_handler(char *param_1,undefined4 param_2)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int *piVar7;
  undefined2 *puVar8;
  byte *pbVar9;
  byte abStack_21 [5];
  
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar6 = 0;
    while( true ) {
      abStack_21[0] = (byte)uVar6;
      iVar3 = r_sdk_config_get_opts();
      uVar6 = (uint)abStack_21[0];
      if ((*(byte *)(iVar3 + 0xd) <= uVar6) ||
         ((byte)(*(char *)(*(int *)(_p_llm_env + 8) + uVar6 * 0x44 + 0x40) - 6U) < 3)) break;
      uVar6 = uVar6 + 1 & 0xff;
    }
    if (*param_1 != '\0') {
      if ((*param_1 == '\x01') && ((byte)param_1[1] < 3)) {
        uVar6 = (uint)*(ushort *)(param_1 + 4);
        if (param_1[1] != 2) {
          if (uVar6 != 0) goto _L826;
_L827:
          iVar3 = r_sdk_config_get_opts();
          uVar6 = (uint)abStack_21[0];
          if (uVar6 < *(byte *)(iVar3 + 0xd)) {
            piVar7 = (int *)(*(int *)(_p_llm_env + 8) + uVar6 * 0x44);
            cVar1 = (char)piVar7[0x10];
            if (cVar1 == '\b') {
              r_ble_log_internal_x1(0x802e01dd,uVar6 << 8 | 0xc);
              goto _L840;
            }
            uVar6 = 0x12;
            if (cVar1 != '\a') goto _L830;
            if (*piVar7 == 0) {
              r_assert_err(0,"llm_scan.c",0x2a1);
            }
            iVar3 = 0;
            if ((**(byte **)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44) & 2) != 0) {
              iVar3 = _p_llm_env + 0x12;
            }
            r_lld_scan_params_update
                      (*(undefined2 *)(param_1 + 2),*(undefined2 *)(param_1 + 4),iVar3);
            cVar1 = param_1[1];
            if (cVar1 != '\0') {
              r_llm_env_adv_dup_filt_init_eco();
            }
            iVar3 = _p_llm_env;
            *(byte *)(_p_llm_env + 0xd4) =
                 *(byte *)(_p_llm_env + 0xd4) & 0xfc | cVar1 != '\0' | (param_1[1] == '\x02') << 1;
            iVar3 = *(int *)(iVar3 + 8) + (uint)abStack_21[0] * 0x44;
            *(undefined2 *)(iVar3 + 0x28) = *(undefined2 *)(param_1 + 2);
            *(undefined2 *)(iVar3 + 0x2a) = *(undefined2 *)(param_1 + 4);
_L839:
            uVar6 = 0;
          }
          else {
            uVar6 = r_llm_activity_free_get(abStack_21);
            if (uVar6 != 0) goto _L809;
_L830:
            piVar7 = (int *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
            if (*piVar7 == 0) {
              iVar4 = r_ke_msg_alloc(0,0,0,0x10);
              iVar3 = _p_llm_env;
              *piVar7 = iVar4;
              iVar3 = *(int *)(iVar3 + 8);
              puVar8 = *(undefined2 **)((uint)abStack_21[0] * 0x44 + iVar3);
              *puVar8 = 0;
              puVar8[3] = 0x10;
              puVar8[4] = 0x10;
              *(undefined1 *)(puVar8 + 2) = 0;
              *(undefined1 *)(puVar8 + 1) = 1;
              *(undefined1 *)(iVar3 + (uint)abStack_21[0] * 0x44 + 0x40) = 6;
              r_ble_log_internal_x1(0x404e01de,abStack_21[0] | 0x600);
            }
            pbVar9 = *(byte **)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
            if ((*pbVar9 == 1) &&
               (iVar3 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr), iVar3 != 0)) {
              bVar2 = *pbVar9;
              uVar5 = 0x802e01df;
            }
            else {
              if ((*pbVar9 != 3) ||
                 ((iVar3 = r_lld_res_list_is_empty(), iVar3 == 0 ||
                  (iVar3 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr), iVar3 == 0)))) {
                cVar1 = param_1[1];
                if (cVar1 != '\0') {
                  r_llm_env_adv_dup_filt_init_eco();
                }
                iVar3 = _p_llm_env;
                *(byte *)(_p_llm_env + 0xd4) =
                     *(byte *)(_p_llm_env + 0xd4) & 0xfc | cVar1 != '\0' |
                     (param_1[1] == '\x02') << 1;
                iVar3 = *(int *)(iVar3 + 8) + (uint)abStack_21[0] * 0x44;
                *(undefined2 *)(iVar3 + 0x28) = *(undefined2 *)(param_1 + 2);
                *(undefined2 *)(iVar3 + 0x2a) = *(undefined2 *)(param_1 + 4);
                r_llm_scan_start_eco(1);
                *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44 + 0x40) = 7;
                r_ble_log_internal_x1(0x404e01e1,abStack_21[0] | 0x700);
                if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
                   ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
                  (*(code *)*_bt_rf_coex_hooks_p)(abStack_21[0],3,1);
                }
                goto _L839;
              }
              bVar2 = *pbVar9;
              uVar5 = 0x802e01e0;
            }
            r_ble_log_internal_x1(uVar5,(uint)bVar2 << 8 | uVar6);
          }
          goto _L809;
        }
        if ((uVar6 == 0) || (*(short *)(param_1 + 2) == 0)) {
          r_ble_log_internal_x2
                    (0x802e01dc,CONCAT22(*(short *)(param_1 + 2),*(ushort *)(param_1 + 4)),0x212);
        }
        else {
_L826:
          if ((uint)*(ushort *)(param_1 + 2) < uVar6 << 7) goto _L827;
        }
      }
      uVar6 = 0x12;
      goto _L809;
    }
    iVar3 = r_sdk_config_get_opts();
    if (((uint)abStack_21[0] < (uint)*(byte *)(iVar3 + 0xd)) &&
       (*(char *)((uint)abStack_21[0] * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) == '\a')) {
      iVar3 = r_lld_scan_stop();
      uVar6 = (uint)abStack_21[0];
      iVar4 = *(int *)(_p_llm_env + 8) + uVar6 * 0x44;
      if (iVar3 == 0) {
        *(undefined1 *)(iVar4 + 0x40) = 8;
        r_ble_log_internal_x1(0x404e01da,uVar6 | 0x800);
        if (_bt_rf_coex_hooks_p == (undefined4 *)0x0) {
          return 0;
        }
        if ((code *)*_bt_rf_coex_hooks_p == (code *)0x0) {
          return 0;
        }
        (*(code *)*_bt_rf_coex_hooks_p)(abStack_21[0],3,0);
        return 0;
      }
      *(undefined1 *)(iVar4 + 0x40) = 6;
      r_ble_log_internal_x1(0x404e01db,uVar6 | 0x600);
      r_ke_timer_clear(3,0);
      r_llm_env_adv_dup_filt_deinit_eco();
      uVar6 = 0;
      goto _L809;
    }
    uVar6 = 0xfe;
    if ((_sdk_cfg_priv_opts & 8) != 0) goto _L809;
  }
_L840:
  uVar6 = 0xc;
_L809:
  r_llm_cmd_cmp_send(param_2,uVar6);
  return 0;
}

