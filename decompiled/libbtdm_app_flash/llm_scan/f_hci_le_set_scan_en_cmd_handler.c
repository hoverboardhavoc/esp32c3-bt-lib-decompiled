/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  int *piVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined2 *puVar8;
  code *pcVar9;
  byte abStack_21 [5];
  
  if (*(char *)(_p_llm_env + 0xd7) != '\x02') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    uVar7 = 0;
    while( true ) {
      abStack_21[0] = (byte)uVar7;
      iVar4 = r_sdk_config_get_opts();
      uVar7 = (uint)abStack_21[0];
      if ((*(byte *)(iVar4 + 0xd) <= uVar7) ||
         ((byte)(*(char *)(*(int *)(_p_llm_env + 8) + uVar7 * 0x44 + 0x40) - 6U) < 3)) break;
      uVar7 = uVar7 + 1 & 0xff;
    }
    if (*param_1 != '\0') {
      if ((*param_1 == '\x01') && ((byte)param_1[1] < 2)) {
        iVar4 = r_sdk_config_get_opts();
        if ((uint)abStack_21[0] < (uint)*(byte *)(iVar4 + 0xd)) {
          cVar1 = *(char *)((uint)abStack_21[0] * 0x44 + *(int *)(_p_llm_env + 8) + 0x40);
          if (cVar1 == '\b') goto _L742;
          iVar4 = 0x12;
          if (cVar1 == '\a') {
            cVar1 = param_1[1];
            if (cVar1 != '\0') {
              r_llm_env_adv_dup_filt_init_eco();
            }
            *(byte *)(_p_llm_env + 0xd4) = cVar1 != '\0' | *(byte *)(_p_llm_env + 0xd4) & 0xfe;
            goto _L755;
          }
        }
        else {
          iVar4 = r_llm_activity_free_get(abStack_21);
          if (iVar4 != 0) goto _L767;
        }
        piVar2 = (int *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
        iVar5 = _p_llm_env;
        if (*piVar2 == 0) {
          iVar5 = r_ke_msg_alloc(0,0,0,0x10);
          *piVar2 = iVar5;
          iVar5 = _p_llm_env;
          piVar2 = (int *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
          puVar8 = (undefined2 *)*piVar2;
          puVar8[3] = 0x10;
          puVar8[4] = 0x10;
          *(undefined1 *)(puVar8 + 2) = 0;
          *puVar8 = 0;
          *(undefined1 *)(puVar8 + 1) = 1;
          *(undefined1 *)(piVar2 + 0x10) = 6;
        }
        pbVar3 = (byte *)*piVar2;
        if (((*pbVar3 & 0xfd) == 1) &&
           ((iVar5 = r_co_bdaddr_compare(iVar5 + 0x12,&co_null_bdaddr), iVar5 != 0 ||
            (((*pbVar3 == 3 && (iVar5 = r_lld_res_list_is_empty(), iVar5 != 0)) &&
             (iVar5 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr), iVar5 != 0)))))) {
          if (iVar4 != 0) goto _L768;
        }
        else {
          cVar1 = param_1[1];
          if (cVar1 != '\0') {
            r_llm_env_adv_dup_filt_init_eco();
            llm_cal_duplicate_scan_defer_count(*(undefined2 *)(pbVar3 + 6));
          }
          iVar4 = _p_llm_env;
          *(byte *)(_p_llm_env + 0xd4) = cVar1 != '\0' | *(byte *)(_p_llm_env + 0xd4) & 0xfe;
          *(undefined4 *)(*(int *)(iVar4 + 8) + (uint)abStack_21[0] * 0x44 + 0x28) = 0;
          r_llm_scan_start_eco(0);
          *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44 + 0x40) = 7;
          if (_bt_rf_coex_hooks_p != (int *)0x0) {
            pcVar9 = (code *)*_bt_rf_coex_hooks_p;
            uVar6 = 1;
            if (pcVar9 != (code *)0x0) goto _L793;
          }
        }
_L755:
        if (*param_1 == '\0') {
          return 0;
        }
        iVar4 = 0;
      }
      else {
_L768:
        iVar4 = 0x12;
      }
      goto _L767;
    }
    iVar4 = r_sdk_config_get_opts();
    if (((uint)abStack_21[0] < (uint)*(byte *)(iVar4 + 0xd)) &&
       (*(char *)((uint)abStack_21[0] * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) == '\a')) {
      iVar4 = r_lld_scan_stop();
      if (iVar4 != 0) goto _L767;
      *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44 + 0x40) = 8;
      if ((_bt_rf_coex_hooks_p != (int *)0x0) &&
         (pcVar9 = (code *)*_bt_rf_coex_hooks_p, pcVar9 != (code *)0x0)) {
        uVar6 = 0;
_L793:
        (*pcVar9)(1,uVar6);
      }
      goto _L755;
    }
    iVar4 = 0xfe;
    if ((_sdk_cfg_priv_opts & 4) != 0) goto _L767;
  }
_L742:
  iVar4 = 0xc;
_L767:
  r_llm_cmd_cmp_send(param_2,iVar4);
  return 0;
}

