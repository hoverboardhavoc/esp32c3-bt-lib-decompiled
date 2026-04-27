/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llm_scan.o -> f_hci_le_set_scan_en_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_set_scan_en_cmd_handler(char *param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined2 *puVar7;
  code *pcVar8;
  byte *pbVar9;
  int *piVar10;
  byte abStack_21 [5];
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x02') {
_L752:
    uVar6 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    uVar6 = 0;
    while( true ) {
      abStack_21[0] = (byte)uVar6;
      iVar3 = r_sdk_config_get_opts();
      uVar6 = (uint)abStack_21[0];
      if ((*(byte *)(iVar3 + 0xd) <= uVar6) ||
         ((byte)(*(char *)(*(int *)(_p_llm_env + 8) + uVar6 * 0x44 + 0x40) - 6U) < 3)) break;
      uVar6 = uVar6 + 1 & 0xff;
    }
    if (*param_1 == '\0') {
      iVar3 = r_sdk_config_get_opts();
      if (((uint)*(byte *)(iVar3 + 0xd) <= (uint)abStack_21[0]) ||
         (*(char *)((uint)abStack_21[0] * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) != '\a')) {
        uVar6 = 0xfe;
        if ((_sdk_cfg_priv_opts & 4) != 0) goto _L726;
        goto _L752;
      }
      uVar2 = r_lld_scan_stop();
      uVar6 = (uint)abStack_21[0];
      if (uVar2 != 0) {
        uVar6 = uVar6 << 8 | uVar2;
        uVar5 = 0x802e01f9;
_L789:
        r_ble_log_internal_x1(uVar5,uVar6);
        uVar6 = uVar2;
        goto _L726;
      }
      *(undefined1 *)(*(int *)(_p_llm_env + 8) + uVar6 * 0x44 + 0x40) = 8;
      r_ble_log_internal_x1(0x404e01f8,uVar6 | 0x800);
      if (_bt_rf_coex_hooks_p != (int *)0x0) {
        pcVar8 = (code *)*_bt_rf_coex_hooks_p;
        uVar5 = 0;
        if (pcVar8 != (code *)0x0) goto _L788;
      }
    }
    else {
      if (*param_1 != '\x01') {
        uVar6 = 0x12;
        goto _L726;
      }
      uVar2 = 0x12;
      uVar6 = 0x12;
      if (1 < (byte)param_1[1]) goto _L726;
      iVar3 = r_sdk_config_get_opts();
      uVar6 = (uint)abStack_21[0];
      if (uVar6 < *(byte *)(iVar3 + 0xd)) {
        cVar1 = *(char *)(*(int *)(_p_llm_env + 8) + uVar6 * 0x44 + 0x40);
        if (cVar1 == '\b') {
          r_ble_log_internal_x1(0x802e01fa,uVar6 << 8 | 0xc);
          goto _L752;
        }
        if (cVar1 == '\a') {
          cVar1 = param_1[1];
          if (cVar1 != '\0') {
            r_llm_env_adv_dup_filt_init_eco();
          }
          *(byte *)(_p_llm_env + 0xd4) = *(byte *)(_p_llm_env + 0xd4) & 0xfe | cVar1 != '\0';
          goto _L739;
        }
      }
      else {
        uVar2 = r_llm_activity_free_get(abStack_21);
        if (uVar2 != 0) {
          uVar6 = (uint)abStack_21[0] << 8 | uVar2;
          uVar5 = 0x802e01fb;
          goto _L789;
        }
      }
      piVar10 = (int *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
      if (*piVar10 == 0) {
        iVar4 = r_ke_msg_alloc(0,0,0,0x10);
        iVar3 = _p_llm_env;
        *piVar10 = iVar4;
        iVar3 = *(int *)(iVar3 + 8);
        puVar7 = *(undefined2 **)((uint)abStack_21[0] * 0x44 + iVar3);
        *puVar7 = 0;
        puVar7[3] = 0x10;
        puVar7[4] = 0x10;
        *(undefined1 *)(puVar7 + 2) = 0;
        *(undefined1 *)(puVar7 + 1) = 1;
        *(undefined1 *)(iVar3 + (uint)abStack_21[0] * 0x44 + 0x40) = 6;
        r_ble_log_internal_x1(0x404e01fc,abStack_21[0] | 0x600);
      }
      pbVar9 = *(byte **)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
      if ((*pbVar9 & 0xfd) == 1) {
        iVar3 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr);
        uVar6 = (uint)*pbVar9;
        if (iVar3 == 0) {
          if (((uVar6 != 3) || (iVar3 = r_lld_res_list_is_empty(), iVar3 == 0)) ||
             (iVar3 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr), iVar3 == 0))
          goto _L747;
          uVar6 = (uint)*pbVar9;
          uVar5 = 0x802e01fe;
        }
        else {
          uVar5 = 0x802e01fd;
        }
        r_ble_log_internal_x1(uVar5,uVar6 << 8 | uVar2);
        uVar6 = uVar2;
        if (uVar2 != 0) goto _L726;
      }
      else {
_L747:
        cVar1 = param_1[1];
        if (cVar1 != '\0') {
          r_llm_env_adv_dup_filt_init_eco();
          llm_cal_duplicate_scan_defer_count(*(undefined2 *)(pbVar9 + 6));
        }
        iVar3 = _p_llm_env;
        *(byte *)(_p_llm_env + 0xd4) = *(byte *)(_p_llm_env + 0xd4) & 0xfe | cVar1 != '\0';
        *(undefined4 *)(*(int *)(iVar3 + 8) + (uint)abStack_21[0] * 0x44 + 0x28) = 0;
        r_llm_scan_start_eco(0);
        *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44 + 0x40) = 7;
        r_ble_log_internal_x1(0x404e01ff,abStack_21[0] | 0x700);
        if ((_bt_rf_coex_hooks_p != (int *)0x0) &&
           (pcVar8 = (code *)*_bt_rf_coex_hooks_p, pcVar8 != (code *)0x0)) {
          uVar5 = 1;
_L788:
          (*pcVar8)(abStack_21[0],1,uVar5);
        }
      }
    }
_L739:
    uVar6 = 0;
    if (*param_1 == '\0') {
      return 0;
    }
  }
_L726:
  r_llm_cmd_cmp_send(param_2,uVar6);
  return 0;
}

