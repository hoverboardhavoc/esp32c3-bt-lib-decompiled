/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
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
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  code *pcVar7;
  int *piVar8;
  byte *pbVar9;
  byte abStack_21 [5];
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x02') {
_L766:
    iVar2 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    abStack_21[0] = 0;
    while( true ) {
      iVar2 = r_sdk_config_get_opts();
      if (((uint)*(byte *)(iVar2 + 0xd) <= (uint)abStack_21[0]) ||
         ((byte)(*(char *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44 + 0x40) - 6U) < 3))
      break;
      abStack_21[0] = abStack_21[0] + 1;
    }
    if (*param_1 == '\0') {
      iVar2 = r_sdk_config_get_opts();
      if (((uint)*(byte *)(iVar2 + 0xd) <= (uint)abStack_21[0]) ||
         (*(char *)((uint)abStack_21[0] * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) != '\a')) {
        iVar2 = 0xfe;
        if ((_sdk_cfg_priv_opts & 4) != 0) goto _L741;
        goto _L766;
      }
      iVar2 = r_lld_scan_stop();
      if (iVar2 != 0) goto _L741;
      *(undefined1 *)((uint)abStack_21[0] * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) = 8;
      if (_bt_rf_coex_hooks_p != (int *)0x0) {
        pcVar7 = (code *)*_bt_rf_coex_hooks_p;
        uVar4 = 0;
        if (pcVar7 != (code *)0x0) goto _L791;
      }
    }
    else {
      if (*param_1 != '\x01') {
        iVar2 = 0x12;
        goto _L741;
      }
      iVar2 = 0x12;
      if (1 < (byte)param_1[1]) goto _L741;
      iVar2 = r_sdk_config_get_opts();
      if ((uint)abStack_21[0] < (uint)*(byte *)(iVar2 + 0xd)) {
        cVar1 = *(char *)((uint)abStack_21[0] * 0x44 + *(int *)(_p_llm_env + 8) + 0x40);
        if (cVar1 == '\b') goto _L766;
        iVar2 = 0x12;
        if (cVar1 == '\a') {
          cVar1 = param_1[1];
          if (cVar1 != '\0') {
            r_llm_env_adv_dup_filt_init_eco();
          }
          *(byte *)(_p_llm_env + 0xd4) = *(byte *)(_p_llm_env + 0xd4) & 0xfe | cVar1 != '\0';
          goto _L754;
        }
      }
      else {
        iVar2 = r_llm_activity_free_get(abStack_21);
        if (iVar2 != 0) goto _L741;
      }
      piVar8 = (int *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
      if (*piVar8 == 0) {
        iVar3 = r_ke_msg_alloc(0,0,0,0x10);
        *piVar8 = iVar3;
        puVar5 = (undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
        puVar6 = (undefined2 *)*puVar5;
        puVar6[3] = 0x10;
        puVar6[4] = 0x10;
        *(undefined1 *)(puVar6 + 2) = 0;
        *puVar6 = 0;
        *(undefined1 *)(puVar6 + 1) = 1;
        *(undefined1 *)(puVar5 + 0x10) = 6;
      }
      pbVar9 = *(byte **)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
      if (((*pbVar9 & 0xfd) == 1) &&
         ((iVar3 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr), iVar3 != 0 ||
          (((*pbVar9 == 3 && (iVar3 = r_lld_res_list_is_empty(), iVar3 != 0)) &&
           (iVar3 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr), iVar3 != 0)))))) {
        if (iVar2 != 0) goto _L741;
      }
      else {
        cVar1 = param_1[1];
        if (cVar1 != '\0') {
          r_llm_env_adv_dup_filt_init_eco();
          llm_cal_duplicate_scan_defer_count(*(undefined2 *)(pbVar9 + 6));
        }
        iVar2 = _p_llm_env;
        *(byte *)(_p_llm_env + 0xd4) = *(byte *)(_p_llm_env + 0xd4) & 0xfe | cVar1 != '\0';
        *(undefined4 *)(*(int *)(iVar2 + 8) + (uint)abStack_21[0] * 0x44 + 0x28) = 0;
        r_llm_scan_start_eco(0);
        *(undefined1 *)((uint)abStack_21[0] * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) = 7;
        if ((_bt_rf_coex_hooks_p != (int *)0x0) &&
           (pcVar7 = (code *)*_bt_rf_coex_hooks_p, pcVar7 != (code *)0x0)) {
          uVar4 = 1;
_L791:
          (*pcVar7)(1,uVar4);
        }
      }
    }
_L754:
    iVar2 = 0;
    if (*param_1 == '\0') {
      return 0;
    }
  }
_L741:
  r_llm_cmd_cmp_send(param_2,iVar2);
  return 0;
}

