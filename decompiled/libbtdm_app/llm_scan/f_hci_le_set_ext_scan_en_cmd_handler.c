/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm_scan.o -> f_hci_le_set_ext_scan_en_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_set_ext_scan_en_cmd_handler(char *param_1,undefined4 param_2)

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
  byte bStack_21;
  
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    bStack_21 = 0;
    while( true ) {
      iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      if (((uint)*(byte *)(iVar2 + 0xd) <= (uint)bStack_21) ||
         ((byte)(*(char *)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44 + 0x40) - 6U) < 3))
      break;
      bStack_21 = bStack_21 + 1;
    }
    if (*param_1 != '\0') {
      if ((*param_1 == '\x01') && ((byte)param_1[1] < 3)) {
        uVar6 = (uint)*(ushort *)(param_1 + 4);
        if (param_1[1] != 2) {
          if (uVar6 != 0) goto _L98;
_L99:
          iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
          if ((uint)bStack_21 < (uint)*(byte *)(iVar2 + 0xd)) {
            piVar7 = (int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44);
            cVar1 = (char)piVar7[0x10];
            if (cVar1 == '\b') goto _L118;
            iVar2 = 0x12;
            if (cVar1 == '\a') {
              if (*piVar7 == 0) {
                (**(code **)(_r_plf_funcs_p + 8))
                          (0,"llm_scan.c",0x271,*(code **)(_r_plf_funcs_p + 8));
              }
              iVar2 = 0;
              if ((**(byte **)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44) & 2) != 0) {
                iVar2 = _p_llm_env + 0x12;
              }
              (**(code **)(_r_ip_funcs_p + 0x404))
                        (*(undefined2 *)(param_1 + 2),*(undefined2 *)(param_1 + 4),iVar2,
                         *(code **)(_r_ip_funcs_p + 0x404));
              cVar1 = param_1[1];
              if (cVar1 != '\0') {
                (**(code **)(_r_ip_funcs_p + 0x538))(*(code **)(_r_ip_funcs_p + 0x538));
              }
              iVar2 = _p_llm_env;
              bVar4 = 2;
              if (param_1[1] != '\x02') {
                bVar4 = 0;
              }
              *(byte *)(_p_llm_env + 0xd4) =
                   *(byte *)(_p_llm_env + 0xd4) & 0xfc | cVar1 != '\0' | bVar4;
              iVar2 = *(int *)(iVar2 + 8) + (uint)bStack_21 * 0x44;
              *(undefined2 *)(iVar2 + 0x28) = *(undefined2 *)(param_1 + 2);
              *(undefined2 *)(iVar2 + 0x2a) = *(undefined2 *)(param_1 + 4);
              goto _L153;
            }
          }
          else {
            iVar2 = (**(code **)(_r_ip_funcs_p + 0x4ac))
                              (&bStack_21,*(code **)(_r_ip_funcs_p + 0x4ac));
            if (iVar2 != 0) goto _L82;
          }
          piVar7 = (int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44);
          if (*piVar7 == 0) {
            iVar3 = (*(code *)_r_modules_funcs_p[0x32])(0,0,0,0x10,(code *)_r_modules_funcs_p[0x32])
            ;
            *piVar7 = iVar3;
            puVar5 = (undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44);
            puVar8 = (undefined2 *)*puVar5;
            puVar8[3] = 0x10;
            puVar8[4] = 0x10;
            *(undefined1 *)(puVar8 + 2) = 0;
            *puVar8 = 0;
            *(undefined1 *)(puVar8 + 1) = 1;
            *(undefined1 *)(puVar5 + 0x10) = 6;
          }
          pcVar9 = *(char **)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44);
          if (((*pcVar9 == '\x01') &&
              (iVar3 = (*(code *)*_r_modules_funcs_p)
                                 (_p_llm_env + 0x12,&co_null_bdaddr,(code *)*_r_modules_funcs_p),
              iVar3 != 0)) ||
             ((*pcVar9 == '\x03' &&
              ((iVar3 = (**(code **)(_r_ip_funcs_p + 0x27c))(*(code **)(_r_ip_funcs_p + 0x27c)),
               iVar3 != 0 &&
               (iVar3 = (*(code *)*_r_modules_funcs_p)
                                  (_p_llm_env + 0x12,&co_null_bdaddr,(code *)*_r_modules_funcs_p),
               iVar3 != 0)))))) goto _L82;
          cVar1 = param_1[1];
          if (cVar1 != '\0') {
            (**(code **)(_r_ip_funcs_p + 0x538))(*(code **)(_r_ip_funcs_p + 0x538));
          }
          iVar2 = _p_llm_env;
          bVar4 = 2;
          if (param_1[1] != '\x02') {
            bVar4 = 0;
          }
          *(byte *)(_p_llm_env + 0xd4) = *(byte *)(_p_llm_env + 0xd4) & 0xfc | cVar1 != '\0' | bVar4
          ;
          iVar2 = *(int *)(iVar2 + 8) + (uint)bStack_21 * 0x44;
          *(undefined2 *)(iVar2 + 0x28) = *(undefined2 *)(param_1 + 2);
          *(undefined2 *)(iVar2 + 0x2a) = *(undefined2 *)(param_1 + 4);
          (**(code **)(_r_ip_funcs_p + 0x514))(1,*(code **)(_r_ip_funcs_p + 0x514));
          *(undefined1 *)((uint)bStack_21 * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) = 7;
          if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
             ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
            (*(code *)*_bt_rf_coex_hooks_p)(3,1);
          }
          goto _L153;
        }
        if ((uVar6 != 0) && (*(short *)(param_1 + 2) != 0)) {
_L98:
          if ((uint)*(ushort *)(param_1 + 2) < uVar6 << 7) goto _L99;
        }
      }
      iVar2 = 0x12;
      goto _L82;
    }
    iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (((uint)bStack_21 < (uint)*(byte *)(iVar2 + 0xd)) &&
       (*(char *)((uint)bStack_21 * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) == '\a')) {
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x43c))(*(code **)(_r_ip_funcs_p + 0x43c));
      uVar6 = (uint)bStack_21;
      if (iVar2 == 0) {
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
      (*(code *)_r_modules_funcs_p[0x2e])(3,0,(code *)_r_modules_funcs_p[0x2e]);
      (**(code **)(_r_ip_funcs_p + 0x53c))(*(code **)(_r_ip_funcs_p + 0x53c));
_L153:
      iVar2 = 0;
      goto _L82;
    }
    iVar2 = 0xfe;
    if ((_sdk_cfg_priv_opts & 8) != 0) goto _L82;
  }
_L118:
  iVar2 = 0xc;
_L82:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar2,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

