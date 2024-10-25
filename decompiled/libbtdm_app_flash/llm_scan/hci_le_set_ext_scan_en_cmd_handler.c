/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  byte bVar4;
  undefined4 *puVar5;
  uint uVar6;
  int *piVar7;
  undefined2 *puVar8;
  char *pcVar9;
  byte abStack_21 [5];
  
  iVar3 = r_sdk_config_get_opts_ext();
  if ((*(char *)(iVar3 + 0x18) == '\0') ||
     (iVar3 = r_sdk_config_get_opts_ext(), *(char *)(iVar3 + 0x23) == '\0')) {
    r_llm_cmd_cmp_send(param_2,0xc);
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    abStack_21[0] = 0;
    while( true ) {
      iVar3 = r_sdk_config_get_opts();
      if (((uint)*(byte *)(iVar3 + 0xd) <= (uint)abStack_21[0]) ||
         ((byte)(*(char *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44 + 0x40) - 6U) < 3))
      break;
      abStack_21[0] = abStack_21[0] + 1;
    }
    if (*param_1 != '\0') {
      if ((*param_1 == '\x01') && ((byte)param_1[1] < 3)) {
        uVar6 = (uint)*(ushort *)(param_1 + 4);
        if (param_1[1] != 2) {
          if (uVar6 != 0) goto _L809;
_L810:
          iVar3 = r_sdk_config_get_opts();
          if ((uint)abStack_21[0] < (uint)*(byte *)(iVar3 + 0xd)) {
            piVar7 = (int *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
            cVar1 = (char)piVar7[0x10];
            if (cVar1 == '\b') goto _L829;
            iVar3 = 0x12;
            if (cVar1 == '\a') {
              if (*piVar7 == 0) {
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
              bVar4 = 2;
              if (param_1[1] != '\x02') {
                bVar4 = 0;
              }
              *(byte *)(_p_llm_env + 0xd4) =
                   *(byte *)(_p_llm_env + 0xd4) & 0xfc | cVar1 != '\0' | bVar4;
              iVar3 = *(int *)(iVar3 + 8) + (uint)abStack_21[0] * 0x44;
              *(undefined2 *)(iVar3 + 0x28) = *(undefined2 *)(param_1 + 2);
              *(undefined2 *)(iVar3 + 0x2a) = *(undefined2 *)(param_1 + 4);
              goto _L864;
            }
          }
          else {
            iVar3 = r_llm_activity_free_get(abStack_21);
            if (iVar3 != 0) goto _L793;
          }
          piVar7 = (int *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
          if (*piVar7 == 0) {
            iVar2 = r_ke_msg_alloc(0,0,0,0x10);
            *piVar7 = iVar2;
            puVar5 = (undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
            puVar8 = (undefined2 *)*puVar5;
            puVar8[3] = 0x10;
            puVar8[4] = 0x10;
            *(undefined1 *)(puVar8 + 2) = 0;
            *puVar8 = 0;
            *(undefined1 *)(puVar8 + 1) = 1;
            *(undefined1 *)(puVar5 + 0x10) = 6;
          }
          pcVar9 = *(char **)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
          if (((*pcVar9 == '\x01') &&
              (iVar2 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr), iVar2 != 0)) ||
             ((*pcVar9 == '\x03' &&
              ((iVar2 = r_lld_res_list_is_empty(), iVar2 != 0 &&
               (iVar2 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr), iVar2 != 0))))))
          goto _L793;
          cVar1 = param_1[1];
          if (cVar1 != '\0') {
            r_llm_env_adv_dup_filt_init_eco();
          }
          iVar3 = _p_llm_env;
          bVar4 = 2;
          if (param_1[1] != '\x02') {
            bVar4 = 0;
          }
          *(byte *)(_p_llm_env + 0xd4) = *(byte *)(_p_llm_env + 0xd4) & 0xfc | cVar1 != '\0' | bVar4
          ;
          iVar3 = *(int *)(iVar3 + 8) + (uint)abStack_21[0] * 0x44;
          *(undefined2 *)(iVar3 + 0x28) = *(undefined2 *)(param_1 + 2);
          *(undefined2 *)(iVar3 + 0x2a) = *(undefined2 *)(param_1 + 4);
          r_llm_scan_start_eco(1);
          *(undefined1 *)((uint)abStack_21[0] * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) = 7;
          if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
             ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
            (*(code *)*_bt_rf_coex_hooks_p)(3,1);
          }
          goto _L864;
        }
        if ((uVar6 != 0) && (*(short *)(param_1 + 2) != 0)) {
_L809:
          if ((uint)*(ushort *)(param_1 + 2) < uVar6 << 7) goto _L810;
        }
      }
      iVar3 = 0x12;
      goto _L793;
    }
    iVar3 = r_sdk_config_get_opts();
    if (((uint)abStack_21[0] < (uint)*(byte *)(iVar3 + 0xd)) &&
       (*(char *)((uint)abStack_21[0] * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) == '\a')) {
      iVar3 = r_lld_scan_stop();
      uVar6 = (uint)abStack_21[0];
      if (iVar3 == 0) {
        *(undefined1 *)(uVar6 * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) = 8;
        if (_bt_rf_coex_hooks_p == (undefined4 *)0x0) {
          return 0;
        }
        if ((code *)*_bt_rf_coex_hooks_p == (code *)0x0) {
          return 0;
        }
        (*(code *)*_bt_rf_coex_hooks_p)(uVar6,3,0);
        return 0;
      }
      *(undefined1 *)(uVar6 * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) = 6;
      r_ke_timer_clear(3,0);
      r_llm_env_adv_dup_filt_deinit_eco();
_L864:
      iVar3 = 0;
      goto _L793;
    }
    iVar3 = 0xfe;
    if ((_sdk_cfg_priv_opts & 8) != 0) goto _L793;
  }
_L829:
  iVar3 = 0xc;
_L793:
  r_llm_cmd_cmp_send(param_2,iVar3);
  return 0;
}

