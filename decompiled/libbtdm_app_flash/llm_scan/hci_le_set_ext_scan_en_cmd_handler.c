/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llm_scan.o -> hci_le_set_ext_scan_en_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_ext_scan_en_cmd_handler(char *param_1,undefined4 param_2)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  undefined2 *puVar8;
  byte *pbVar9;
  byte abStack_21 [5];
  
  iVar5 = r_sdk_config_get_opts_ext();
  if ((*(char *)(iVar5 + 0x18) == '\0') ||
     (iVar5 = r_sdk_config_get_opts_ext(), *(char *)(iVar5 + 0x23) == '\0')) {
    r_llm_cmd_cmp_send(param_2,0xc);
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar6 = 0;
    while( true ) {
      abStack_21[0] = (byte)uVar6;
      iVar5 = r_sdk_config_get_opts();
      uVar6 = (uint)abStack_21[0];
      if ((*(byte *)(iVar5 + 0xd) <= uVar6) ||
         ((byte)(*(char *)(*(int *)(_p_llm_env + 8) + uVar6 * 0x44 + 0x40) - 6U) < 3)) break;
      uVar6 = uVar6 + 1 & 0xff;
    }
    if (*param_1 != '\0') {
      if ((*param_1 == '\x01') && ((byte)param_1[1] < 3)) {
        uVar6 = (uint)*(ushort *)(param_1 + 4);
        if (param_1[1] != 2) {
          if (uVar6 != 0) goto _L830;
_L831:
          iVar5 = r_sdk_config_get_opts();
          uVar6 = (uint)abStack_21[0];
          if (uVar6 < *(byte *)(iVar5 + 0xd)) {
            piVar7 = (int *)(*(int *)(_p_llm_env + 8) + uVar6 * 0x44);
            cVar1 = (char)piVar7[0x10];
            if (cVar1 == '\b') {
              r_ble_log_internal_x1(0x802e0208,uVar6 << 8 | 0xc);
              goto _L844;
            }
            uVar6 = 0x12;
            if (cVar1 != '\a') goto _L834;
            if (*piVar7 == 0) {
              r_assert_err(0,"llm_scan.c",0x2a9);
            }
            iVar5 = 0;
            if ((**(byte **)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44) & 2) != 0) {
              iVar5 = _p_llm_env + 0x12;
            }
            r_lld_scan_params_update
                      (*(undefined2 *)(param_1 + 2),*(undefined2 *)(param_1 + 4),iVar5);
            cVar1 = param_1[1];
            if (cVar1 != '\0') {
              r_llm_env_adv_dup_filt_init_eco();
            }
            iVar5 = _p_llm_env;
            *(byte *)(_p_llm_env + 0xd4) =
                 *(byte *)(_p_llm_env + 0xd4) & 0xfc | cVar1 != '\0' | (param_1[1] == '\x02') << 1;
            iVar5 = *(int *)(iVar5 + 8) + (uint)abStack_21[0] * 0x44;
            *(undefined2 *)(iVar5 + 0x28) = *(undefined2 *)(param_1 + 2);
            *(undefined2 *)(iVar5 + 0x2a) = *(undefined2 *)(param_1 + 4);
_L843:
            uVar6 = 0;
          }
          else {
            uVar6 = r_llm_activity_free_get(abStack_21);
            if (uVar6 != 0) goto _L813;
_L834:
            piVar7 = (int *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
            if (*piVar7 == 0) {
              iVar3 = r_ke_msg_alloc(0,0,0,0x10);
              iVar5 = _p_llm_env;
              *piVar7 = iVar3;
              iVar5 = *(int *)(iVar5 + 8);
              puVar8 = *(undefined2 **)((uint)abStack_21[0] * 0x44 + iVar5);
              *puVar8 = 0;
              puVar8[3] = 0x10;
              puVar8[4] = 0x10;
              *(undefined1 *)(puVar8 + 2) = 0;
              *(undefined1 *)(puVar8 + 1) = 1;
              *(undefined1 *)(iVar5 + (uint)abStack_21[0] * 0x44 + 0x40) = 6;
              r_ble_log_internal_x1(0x404e0209,abStack_21[0] | 0x600);
            }
            pbVar9 = *(byte **)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
            if ((*pbVar9 == 1) &&
               (iVar5 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr), iVar5 != 0)) {
              bVar2 = *pbVar9;
              uVar4 = 0x802e020a;
            }
            else {
              if ((*pbVar9 != 3) ||
                 ((iVar5 = r_lld_res_list_is_empty(), iVar5 == 0 ||
                  (iVar5 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr), iVar5 == 0)))) {
                cVar1 = param_1[1];
                if (cVar1 != '\0') {
                  r_llm_env_adv_dup_filt_init_eco();
                }
                iVar5 = _p_llm_env;
                *(byte *)(_p_llm_env + 0xd4) =
                     *(byte *)(_p_llm_env + 0xd4) & 0xfc | cVar1 != '\0' |
                     (param_1[1] == '\x02') << 1;
                iVar5 = *(int *)(iVar5 + 8) + (uint)abStack_21[0] * 0x44;
                *(undefined2 *)(iVar5 + 0x28) = *(undefined2 *)(param_1 + 2);
                *(undefined2 *)(iVar5 + 0x2a) = *(undefined2 *)(param_1 + 4);
                r_llm_scan_start_eco(1);
                *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44 + 0x40) = 7;
                r_ble_log_internal_x1(0x404e020c,abStack_21[0] | 0x700);
                if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
                   ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
                  (*(code *)*_bt_rf_coex_hooks_p)(abStack_21[0],3,1);
                }
                goto _L843;
              }
              bVar2 = *pbVar9;
              uVar4 = 0x802e020b;
            }
            r_ble_log_internal_x1(uVar4,(uint)bVar2 << 8 | uVar6);
          }
          goto _L813;
        }
        if ((uVar6 == 0) || (*(short *)(param_1 + 2) == 0)) {
          r_ble_log_internal_x2
                    (0x802e0207,CONCAT22(*(short *)(param_1 + 2),*(ushort *)(param_1 + 4)),0x212);
        }
        else {
_L830:
          if ((uint)*(ushort *)(param_1 + 2) < uVar6 << 7) goto _L831;
        }
      }
      uVar6 = 0x12;
      goto _L813;
    }
    iVar5 = r_sdk_config_get_opts();
    if (((uint)abStack_21[0] < (uint)*(byte *)(iVar5 + 0xd)) &&
       (*(char *)((uint)abStack_21[0] * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) == '\a')) {
      iVar5 = r_lld_scan_stop();
      uVar6 = (uint)abStack_21[0];
      iVar3 = *(int *)(_p_llm_env + 8) + uVar6 * 0x44;
      if (iVar5 == 0) {
        *(undefined1 *)(iVar3 + 0x40) = 8;
        r_ble_log_internal_x1(0x404e0205,uVar6 | 0x800);
        if (_bt_rf_coex_hooks_p == (undefined4 *)0x0) {
          return 0;
        }
        if ((code *)*_bt_rf_coex_hooks_p == (code *)0x0) {
          return 0;
        }
        (*(code *)*_bt_rf_coex_hooks_p)(abStack_21[0],3,0);
        return 0;
      }
      *(undefined1 *)(iVar3 + 0x40) = 6;
      r_ble_log_internal_x1(0x404e0206,uVar6 | 0x600);
      r_ke_timer_clear(3,0);
      r_llm_env_adv_dup_filt_deinit_eco();
      uVar6 = 0;
      goto _L813;
    }
    uVar6 = 0xfe;
    if ((_sdk_cfg_priv_opts & 8) != 0) goto _L813;
  }
_L844:
  uVar6 = 0xc;
_L813:
  r_llm_cmd_cmp_send(param_2,uVar6);
  return 0;
}

