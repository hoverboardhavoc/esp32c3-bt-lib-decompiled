/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_scan.o -> hci_le_set_scan_en_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_scan_en_cmd_handler(char *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined2 *puVar7;
  code *pcVar8;
  int *piVar9;
  byte *pbVar10;
  byte abStack_21 [5];
  
  iVar3 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar3 + 0x23) == '\0') {
    r_llm_cmd_cmp_send(param_2,0xc);
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) == '\x02') {
_L753:
    iVar3 = 0xc;
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
        iVar3 = 0xfe;
        if ((_sdk_cfg_priv_opts & 4) != 0) goto _L728;
        goto _L753;
      }
      iVar3 = r_lld_scan_stop();
      if (iVar3 != 0) goto _L728;
      *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44 + 0x40) = 8;
      if (_bt_rf_coex_hooks_p != (int *)0x0) {
        pcVar8 = (code *)*_bt_rf_coex_hooks_p;
        uVar4 = 0;
        if (pcVar8 != (code *)0x0) goto _L778;
      }
    }
    else {
      if (*param_1 != '\x01') {
        iVar3 = 0x12;
        goto _L728;
      }
      iVar3 = 0x12;
      if (1 < (byte)param_1[1]) goto _L728;
      iVar3 = r_sdk_config_get_opts();
      if ((uint)abStack_21[0] < (uint)*(byte *)(iVar3 + 0xd)) {
        cVar1 = *(char *)((uint)abStack_21[0] * 0x44 + *(int *)(_p_llm_env + 8) + 0x40);
        if (cVar1 == '\b') goto _L753;
        iVar3 = 0x12;
        if (cVar1 == '\a') {
          cVar1 = param_1[1];
          if (cVar1 != '\0') {
            r_llm_env_adv_dup_filt_init_eco();
          }
          *(byte *)(_p_llm_env + 0xd4) = *(byte *)(_p_llm_env + 0xd4) & 0xfe | cVar1 != '\0';
          goto _L741;
        }
      }
      else {
        iVar3 = r_llm_activity_free_get(abStack_21);
        if (iVar3 != 0) goto _L728;
      }
      piVar9 = (int *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
      if (*piVar9 == 0) {
        iVar2 = r_ke_msg_alloc(0,0,0,0x10);
        iVar5 = _p_llm_env;
        *piVar9 = iVar2;
        iVar5 = *(int *)(iVar5 + 8);
        puVar7 = *(undefined2 **)((uint)abStack_21[0] * 0x44 + iVar5);
        puVar7[3] = 0x10;
        puVar7[4] = 0x10;
        *puVar7 = 0;
        *(undefined1 *)(puVar7 + 2) = 0;
        *(undefined1 *)(puVar7 + 1) = 1;
        *(undefined1 *)(iVar5 + (uint)abStack_21[0] * 0x44 + 0x40) = 6;
      }
      pbVar10 = *(byte **)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
      if (((*pbVar10 & 0xfd) == 1) &&
         ((iVar5 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr), iVar5 != 0 ||
          (((*pbVar10 == 3 && (iVar5 = r_lld_res_list_is_empty(), iVar5 != 0)) &&
           (iVar5 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr), iVar5 != 0)))))) {
        if (iVar3 != 0) goto _L728;
      }
      else {
        cVar1 = param_1[1];
        if (cVar1 != '\0') {
          r_llm_env_adv_dup_filt_init_eco();
          llm_cal_duplicate_scan_defer_count(*(undefined2 *)(pbVar10 + 6));
        }
        iVar3 = _p_llm_env;
        *(byte *)(_p_llm_env + 0xd4) = *(byte *)(_p_llm_env + 0xd4) & 0xfe | cVar1 != '\0';
        *(undefined4 *)(*(int *)(iVar3 + 8) + (uint)abStack_21[0] * 0x44 + 0x28) = 0;
        r_llm_scan_start_eco(0);
        *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44 + 0x40) = 7;
        if ((_bt_rf_coex_hooks_p != (int *)0x0) &&
           (pcVar8 = (code *)*_bt_rf_coex_hooks_p, pcVar8 != (code *)0x0)) {
          uVar4 = 1;
_L778:
          (*pcVar8)(1,uVar4);
        }
      }
    }
_L741:
    iVar3 = 0;
    if (*param_1 == '\0') {
      return 0;
    }
  }
_L728:
  r_llm_cmd_cmp_send(param_2,iVar3);
  return 0;
}

