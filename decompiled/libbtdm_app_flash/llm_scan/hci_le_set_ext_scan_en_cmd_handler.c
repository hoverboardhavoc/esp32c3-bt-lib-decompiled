/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  undefined2 *puVar7;
  char *pcVar8;
  byte abStack_21 [5];
  
  iVar3 = r_sdk_config_get_opts_ext();
  if ((*(char *)(iVar3 + 0x18) == '\0') ||
     (iVar3 = r_sdk_config_get_opts_ext(), *(char *)(iVar3 + 0x23) == '\0')) {
    r_llm_cmd_cmp_send(param_2,0xc);
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar5 = 0;
    while( true ) {
      abStack_21[0] = (byte)uVar5;
      iVar3 = r_sdk_config_get_opts();
      uVar5 = (uint)abStack_21[0];
      if ((*(byte *)(iVar3 + 0xd) <= uVar5) ||
         ((byte)(*(char *)(*(int *)(_p_llm_env + 8) + uVar5 * 0x44 + 0x40) - 6U) < 3)) break;
      uVar5 = uVar5 + 1 & 0xff;
    }
    if (*param_1 != '\0') {
      if ((*param_1 == '\x01') && ((byte)param_1[1] < 3)) {
        uVar5 = (uint)*(ushort *)(param_1 + 4);
        if (param_1[1] != 2) {
          if (uVar5 != 0) goto _L817;
_L818:
          iVar3 = r_sdk_config_get_opts();
          if ((uint)abStack_21[0] < (uint)*(byte *)(iVar3 + 0xd)) {
            piVar6 = (int *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
            cVar1 = (char)piVar6[0x10];
            if (cVar1 == '\b') goto _L835;
            iVar3 = 0x12;
            if (cVar1 != '\a') goto _L820;
            if (*piVar6 == 0) {
              r_assert_err(0,"llm_scan.c",0x271);
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
          }
          else {
            iVar3 = r_llm_activity_free_get(abStack_21);
            if (iVar3 != 0) goto _L801;
_L820:
            piVar6 = (int *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
            if (*piVar6 == 0) {
              iVar2 = r_ke_msg_alloc(0,0,0,0x10);
              iVar4 = _p_llm_env;
              *piVar6 = iVar2;
              iVar4 = *(int *)(iVar4 + 8);
              puVar7 = *(undefined2 **)((uint)abStack_21[0] * 0x44 + iVar4);
              puVar7[3] = 0x10;
              puVar7[4] = 0x10;
              *puVar7 = 0;
              *(undefined1 *)(puVar7 + 2) = 0;
              *(undefined1 *)(puVar7 + 1) = 1;
              *(undefined1 *)(iVar4 + (uint)abStack_21[0] * 0x44 + 0x40) = 6;
            }
            pcVar8 = *(char **)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
            if (((*pcVar8 == '\x01') &&
                (iVar4 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr), iVar4 != 0)) ||
               ((*pcVar8 == '\x03' &&
                ((iVar4 = r_lld_res_list_is_empty(), iVar4 != 0 &&
                 (iVar4 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr), iVar4 != 0))))))
            goto _L801;
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
            r_llm_scan_start_eco(1);
            *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44 + 0x40) = 7;
            if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
               ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
              (*(code *)*_bt_rf_coex_hooks_p)(3,1);
            }
          }
          iVar3 = 0;
          goto _L801;
        }
        if ((uVar5 != 0) && (*(short *)(param_1 + 2) != 0)) {
_L817:
          if ((uint)*(ushort *)(param_1 + 2) < uVar5 << 7) goto _L818;
        }
      }
      iVar3 = 0x12;
      goto _L801;
    }
    iVar3 = r_sdk_config_get_opts();
    if (((uint)abStack_21[0] < (uint)*(byte *)(iVar3 + 0xd)) &&
       (*(char *)((uint)abStack_21[0] * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) == '\a')) {
      iVar3 = r_lld_scan_stop();
      uVar5 = (uint)abStack_21[0];
      if (iVar3 == 0) {
        *(undefined1 *)(*(int *)(_p_llm_env + 8) + uVar5 * 0x44 + 0x40) = 8;
        if (_bt_rf_coex_hooks_p == (undefined4 *)0x0) {
          return 0;
        }
        if ((code *)*_bt_rf_coex_hooks_p == (code *)0x0) {
          return 0;
        }
        (*(code *)*_bt_rf_coex_hooks_p)(uVar5,3,0);
        return 0;
      }
      *(undefined1 *)(*(int *)(_p_llm_env + 8) + uVar5 * 0x44 + 0x40) = 6;
      r_ke_timer_clear(3,0);
      r_llm_env_adv_dup_filt_deinit_eco();
      iVar3 = 0;
      goto _L801;
    }
    iVar3 = 0xfe;
    if ((_sdk_cfg_priv_opts & 8) != 0) goto _L801;
  }
_L835:
  iVar3 = 0xc;
_L801:
  r_llm_cmd_cmp_send(param_2,iVar3);
  return 0;
}

