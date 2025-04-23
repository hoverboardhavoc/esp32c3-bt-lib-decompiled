/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  uint uVar4;
  int *piVar5;
  undefined2 *puVar6;
  char *pcVar7;
  byte bStack_21;
  
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar4 = 0;
    while( true ) {
      bStack_21 = (byte)uVar4;
      iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      uVar4 = (uint)bStack_21;
      if ((*(byte *)(iVar2 + 0xd) <= uVar4) ||
         ((byte)(*(char *)(*(int *)(_p_llm_env + 8) + uVar4 * 0x44 + 0x40) - 6U) < 3)) break;
      uVar4 = uVar4 + 1 & 0xff;
    }
    if (*param_1 != '\0') {
      if ((*param_1 == '\x01') && ((byte)param_1[1] < 3)) {
        uVar4 = (uint)*(ushort *)(param_1 + 4);
        if (param_1[1] != 2) {
          if (uVar4 != 0) goto _L85;
_L86:
          iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
          if ((uint)bStack_21 < (uint)*(byte *)(iVar2 + 0xd)) {
            piVar5 = (int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44);
            cVar1 = (char)piVar5[0x10];
            if (cVar1 == '\b') goto _L69;
            iVar2 = 0x12;
            if (cVar1 == '\a') {
              if (*piVar5 == 0) {
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
              *(byte *)(_p_llm_env + 0xd4) =
                   *(byte *)(_p_llm_env + 0xd4) & 0xfc | cVar1 != '\0' | (param_1[1] == '\x02') << 1
              ;
              iVar2 = *(int *)(iVar2 + 8) + (uint)bStack_21 * 0x44;
              *(undefined2 *)(iVar2 + 0x28) = *(undefined2 *)(param_1 + 2);
              *(undefined2 *)(iVar2 + 0x2a) = *(undefined2 *)(param_1 + 4);
              goto _L83;
            }
          }
          else {
            iVar2 = (**(code **)(_r_ip_funcs_p + 0x4ac))
                              (&bStack_21,*(code **)(_r_ip_funcs_p + 0x4ac));
            if (iVar2 != 0) goto _L101;
          }
          piVar5 = (int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44);
          iVar3 = _p_llm_env;
          if (*piVar5 == 0) {
            iVar3 = (*(code *)_r_modules_funcs_p[0x32])(0,0,0,0x10,(code *)_r_modules_funcs_p[0x32])
            ;
            *piVar5 = iVar3;
            iVar3 = _p_llm_env;
            piVar5 = (int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44);
            puVar6 = (undefined2 *)*piVar5;
            puVar6[3] = 0x10;
            puVar6[4] = 0x10;
            *(undefined1 *)(puVar6 + 2) = 0;
            *puVar6 = 0;
            *(undefined1 *)(puVar6 + 1) = 1;
            *(undefined1 *)(piVar5 + 0x10) = 6;
          }
          pcVar7 = (char *)*piVar5;
          if (((*pcVar7 == '\x01') &&
              (iVar3 = (*(code *)*_r_modules_funcs_p)
                                 (iVar3 + 0x12,&co_null_bdaddr,(code *)*_r_modules_funcs_p),
              iVar3 != 0)) ||
             ((*pcVar7 == '\x03' &&
              ((iVar3 = (**(code **)(_r_ip_funcs_p + 0x27c))(*(code **)(_r_ip_funcs_p + 0x27c)),
               iVar3 != 0 &&
               (iVar3 = (*(code *)*_r_modules_funcs_p)
                                  (_p_llm_env + 0x12,&co_null_bdaddr,(code *)*_r_modules_funcs_p),
               iVar3 != 0)))))) goto _L101;
          cVar1 = param_1[1];
          if (cVar1 != '\0') {
            (**(code **)(_r_ip_funcs_p + 0x538))(*(code **)(_r_ip_funcs_p + 0x538));
          }
          iVar2 = _p_llm_env;
          *(byte *)(_p_llm_env + 0xd4) =
               *(byte *)(_p_llm_env + 0xd4) & 0xfc | cVar1 != '\0' | (param_1[1] == '\x02') << 1;
          iVar2 = *(int *)(iVar2 + 8) + (uint)bStack_21 * 0x44;
          *(undefined2 *)(iVar2 + 0x28) = *(undefined2 *)(param_1 + 2);
          *(undefined2 *)(iVar2 + 0x2a) = *(undefined2 *)(param_1 + 4);
          (**(code **)(_r_ip_funcs_p + 0x514))(1,*(code **)(_r_ip_funcs_p + 0x514));
          *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44 + 0x40) = 7;
          if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
             ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
            (*(code *)*_bt_rf_coex_hooks_p)(3,1);
          }
          goto _L83;
        }
        if ((uVar4 != 0) && (*(short *)(param_1 + 2) != 0)) {
_L85:
          if ((uint)*(ushort *)(param_1 + 2) < uVar4 << 7) goto _L86;
        }
      }
      iVar2 = 0x12;
      goto _L101;
    }
    iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (((uint)bStack_21 < (uint)*(byte *)(iVar2 + 0xd)) &&
       (*(char *)((uint)bStack_21 * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) == '\a')) {
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x43c))(*(code **)(_r_ip_funcs_p + 0x43c));
      iVar3 = *(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44;
      if (iVar2 == 0) {
        *(undefined1 *)(iVar3 + 0x40) = 8;
        if (_bt_rf_coex_hooks_p == (undefined4 *)0x0) {
          return 0;
        }
        if ((code *)*_bt_rf_coex_hooks_p == (code *)0x0) {
          return 0;
        }
        (*(code *)*_bt_rf_coex_hooks_p)((uint)bStack_21,3,0);
        return 0;
      }
      *(undefined1 *)(iVar3 + 0x40) = 6;
      (*(code *)_r_modules_funcs_p[0x2e])(3,0,(code *)_r_modules_funcs_p[0x2e]);
      (**(code **)(_r_ip_funcs_p + 0x53c))(*(code **)(_r_ip_funcs_p + 0x53c));
_L83:
      iVar2 = 0;
      goto _L101;
    }
    iVar2 = 0xfe;
    if ((_sdk_cfg_priv_opts & 8) != 0) goto _L101;
  }
_L69:
  iVar2 = 0xc;
_L101:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar2,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

