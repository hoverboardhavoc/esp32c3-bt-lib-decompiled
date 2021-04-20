/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> llm_scan.o -> hci_le_set_scan_en_cmd_handler
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
  undefined4 *puVar5;
  undefined2 *puVar6;
  code *pcVar7;
  int *piVar8;
  byte *pbVar9;
  byte bStack_21;
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x02') {
_L364:
    iVar2 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    bStack_21 = 0;
    while( true ) {
      iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      if (((uint)*(byte *)(iVar2 + 0xd) <= (uint)bStack_21) ||
         ((byte)(*(char *)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44 + 0x40) - 6U) < 3))
      break;
      bStack_21 = bStack_21 + 1;
    }
    if (*param_1 == '\0') {
      iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      if (((uint)*(byte *)(iVar2 + 0xd) <= (uint)bStack_21) ||
         (*(char *)((uint)bStack_21 * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) != '\a')) {
        iVar2 = 0xfe;
        if ((_sdk_cfg_priv_opts & 4) != 0) goto _L339;
        goto _L364;
      }
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x43c))(*(code **)(_r_ip_funcs_p + 0x43c));
      if (iVar2 != 0) goto _L339;
      *(undefined1 *)((uint)bStack_21 * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) = 8;
      if (_bt_rf_coex_hooks_p != (int *)0x0) {
        pcVar7 = (code *)*_bt_rf_coex_hooks_p;
        uVar4 = 0;
        if (pcVar7 != (code *)0x0) goto _L389;
      }
    }
    else {
      if (*param_1 != '\x01') {
        iVar2 = 0x12;
        goto _L339;
      }
      iVar2 = 0x12;
      if (1 < (byte)param_1[1]) goto _L339;
      iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      if ((uint)bStack_21 < (uint)*(byte *)(iVar2 + 0xd)) {
        cVar1 = *(char *)((uint)bStack_21 * 0x44 + *(int *)(_p_llm_env + 8) + 0x40);
        if (cVar1 == '\b') goto _L364;
        iVar2 = 0x12;
        if (cVar1 == '\a') {
          cVar1 = param_1[1];
          if (cVar1 != '\0') {
            (**(code **)(_r_ip_funcs_p + 0x538))(*(code **)(_r_ip_funcs_p + 0x538));
          }
          *(byte *)(_p_llm_env + 0xd4) = *(byte *)(_p_llm_env + 0xd4) & 0xfe | cVar1 != '\0';
          goto _L352;
        }
      }
      else {
        iVar2 = (**(code **)(_r_ip_funcs_p + 0x4ac))(&bStack_21,*(code **)(_r_ip_funcs_p + 0x4ac));
        if (iVar2 != 0) goto _L339;
      }
      piVar8 = (int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44);
      if (*piVar8 == 0) {
        iVar3 = (*(code *)_r_modules_funcs_p[0x32])(0,0,0,0x10,(code *)_r_modules_funcs_p[0x32]);
        *piVar8 = iVar3;
        puVar5 = (undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44);
        puVar6 = (undefined2 *)*puVar5;
        puVar6[3] = 0x10;
        puVar6[4] = 0x10;
        *(undefined1 *)(puVar6 + 2) = 0;
        *puVar6 = 0;
        *(undefined1 *)(puVar6 + 1) = 1;
        *(undefined1 *)(puVar5 + 0x10) = 6;
      }
      pbVar9 = *(byte **)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44);
      if (((*pbVar9 & 0xfd) == 1) &&
         ((iVar3 = (*(code *)*_r_modules_funcs_p)
                             (_p_llm_env + 0x12,&co_null_bdaddr,(code *)*_r_modules_funcs_p),
          iVar3 != 0 ||
          (((*pbVar9 == 3 &&
            (iVar3 = (**(code **)(_r_ip_funcs_p + 0x27c))(*(code **)(_r_ip_funcs_p + 0x27c)),
            iVar3 != 0)) &&
           (iVar3 = (*(code *)*_r_modules_funcs_p)
                              (_p_llm_env + 0x12,&co_null_bdaddr,(code *)*_r_modules_funcs_p),
           iVar3 != 0)))))) {
        if (iVar2 != 0) goto _L339;
      }
      else {
        cVar1 = param_1[1];
        if (cVar1 != '\0') {
          (**(code **)(_r_ip_funcs_p + 0x538))(*(code **)(_r_ip_funcs_p + 0x538));
          llm_cal_duplicate_scan_defer_count(*(undefined2 *)(pbVar9 + 6));
        }
        iVar2 = _p_llm_env;
        *(byte *)(_p_llm_env + 0xd4) = cVar1 != '\0' | *(byte *)(_p_llm_env + 0xd4) & 0xfe;
        *(undefined4 *)(*(int *)(iVar2 + 8) + (uint)bStack_21 * 0x44 + 0x28) = 0;
        (**(code **)(_r_ip_funcs_p + 0x514))(0,*(code **)(_r_ip_funcs_p + 0x514));
        *(undefined1 *)((uint)bStack_21 * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) = 7;
        if ((_bt_rf_coex_hooks_p != (int *)0x0) &&
           (pcVar7 = (code *)*_bt_rf_coex_hooks_p, pcVar7 != (code *)0x0)) {
          uVar4 = 1;
_L389:
          (*pcVar7)(1,uVar4);
        }
      }
    }
_L352:
    iVar2 = 0;
    if (*param_1 == '\0') {
      return 0;
    }
  }
_L339:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar2,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

