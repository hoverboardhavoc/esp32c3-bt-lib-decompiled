/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_scan.o -> hci_le_set_ext_scan_en_cmd_handler
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
  byte bStack_21;
  
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if ((*(char *)(iVar3 + 0x18) == '\0') ||
     (iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0)),
     *(char *)(iVar3 + 0x23) == '\0')) {
    (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,0xc,*(code **)(_r_ip_funcs_p + 0x4b8));
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar5 = 0;
    while( true ) {
      bStack_21 = (byte)uVar5;
      iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      uVar5 = (uint)bStack_21;
      if ((*(byte *)(iVar3 + 0xd) <= uVar5) ||
         ((byte)(*(char *)(*(int *)(_p_llm_env + 8) + uVar5 * 0x44 + 0x40) - 6U) < 3)) break;
      uVar5 = uVar5 + 1 & 0xff;
    }
    if (*param_1 != '\0') {
      if ((*param_1 == '\x01') && ((byte)param_1[1] < 3)) {
        uVar5 = (uint)*(ushort *)(param_1 + 4);
        if (param_1[1] != 2) {
          if (uVar5 != 0) goto _L95;
_L96:
          iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
          if ((uint)bStack_21 < (uint)*(byte *)(iVar3 + 0xd)) {
            piVar6 = (int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44);
            cVar1 = (char)piVar6[0x10];
            if (cVar1 == '\b') goto _L113;
            iVar3 = 0x12;
            if (cVar1 != '\a') goto _L98;
            if (*piVar6 == 0) {
              (**(code **)(_r_plf_funcs_p + 8))(0,"llm_scan.c",0x271,*(code **)(_r_plf_funcs_p + 8))
              ;
            }
            iVar3 = 0;
            if ((**(byte **)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44) & 2) != 0) {
              iVar3 = _p_llm_env + 0x12;
            }
            (**(code **)(_r_ip_funcs_p + 0x404))
                      (*(undefined2 *)(param_1 + 2),*(undefined2 *)(param_1 + 4),iVar3,
                       *(code **)(_r_ip_funcs_p + 0x404));
            cVar1 = param_1[1];
            if (cVar1 != '\0') {
              (**(code **)(_r_ip_funcs_p + 0x538))(*(code **)(_r_ip_funcs_p + 0x538));
            }
            iVar3 = _p_llm_env;
            *(byte *)(_p_llm_env + 0xd4) =
                 *(byte *)(_p_llm_env + 0xd4) & 0xfc | cVar1 != '\0' | (param_1[1] == '\x02') << 1;
            iVar3 = *(int *)(iVar3 + 8) + (uint)bStack_21 * 0x44;
            *(undefined2 *)(iVar3 + 0x28) = *(undefined2 *)(param_1 + 2);
            *(undefined2 *)(iVar3 + 0x2a) = *(undefined2 *)(param_1 + 4);
          }
          else {
            iVar3 = (**(code **)(_r_ip_funcs_p + 0x4ac))
                              (&bStack_21,*(code **)(_r_ip_funcs_p + 0x4ac));
            if (iVar3 != 0) goto _L79;
_L98:
            piVar6 = (int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44);
            if (*piVar6 == 0) {
              iVar2 = (*(code *)_r_modules_funcs_p[0x32])
                                (0,0,0,0x10,(code *)_r_modules_funcs_p[0x32]);
              iVar4 = _p_llm_env;
              *piVar6 = iVar2;
              iVar4 = *(int *)(iVar4 + 8);
              puVar7 = *(undefined2 **)((uint)bStack_21 * 0x44 + iVar4);
              puVar7[3] = 0x10;
              puVar7[4] = 0x10;
              *puVar7 = 0;
              *(undefined1 *)(puVar7 + 2) = 0;
              *(undefined1 *)(puVar7 + 1) = 1;
              *(undefined1 *)(iVar4 + (uint)bStack_21 * 0x44 + 0x40) = 6;
            }
            pcVar8 = *(char **)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44);
            if (((*pcVar8 == '\x01') &&
                (iVar4 = (*(code *)*_r_modules_funcs_p)
                                   (_p_llm_env + 0x12,&co_null_bdaddr,(code *)*_r_modules_funcs_p),
                iVar4 != 0)) ||
               ((*pcVar8 == '\x03' &&
                ((iVar4 = (**(code **)(_r_ip_funcs_p + 0x27c))(*(code **)(_r_ip_funcs_p + 0x27c)),
                 iVar4 != 0 &&
                 (iVar4 = (*(code *)*_r_modules_funcs_p)
                                    (_p_llm_env + 0x12,&co_null_bdaddr,(code *)*_r_modules_funcs_p),
                 iVar4 != 0)))))) goto _L79;
            cVar1 = param_1[1];
            if (cVar1 != '\0') {
              (**(code **)(_r_ip_funcs_p + 0x538))(*(code **)(_r_ip_funcs_p + 0x538));
            }
            iVar3 = _p_llm_env;
            *(byte *)(_p_llm_env + 0xd4) =
                 *(byte *)(_p_llm_env + 0xd4) & 0xfc | cVar1 != '\0' | (param_1[1] == '\x02') << 1;
            iVar3 = *(int *)(iVar3 + 8) + (uint)bStack_21 * 0x44;
            *(undefined2 *)(iVar3 + 0x28) = *(undefined2 *)(param_1 + 2);
            *(undefined2 *)(iVar3 + 0x2a) = *(undefined2 *)(param_1 + 4);
            (**(code **)(_r_ip_funcs_p + 0x514))(1,*(code **)(_r_ip_funcs_p + 0x514));
            *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44 + 0x40) = 7;
            if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
               ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
              (*(code *)*_bt_rf_coex_hooks_p)(3,1);
            }
          }
          iVar3 = 0;
          goto _L79;
        }
        if ((uVar5 != 0) && (*(short *)(param_1 + 2) != 0)) {
_L95:
          if ((uint)*(ushort *)(param_1 + 2) < uVar5 << 7) goto _L96;
        }
      }
      iVar3 = 0x12;
      goto _L79;
    }
    iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (((uint)bStack_21 < (uint)*(byte *)(iVar3 + 0xd)) &&
       (*(char *)((uint)bStack_21 * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) == '\a')) {
      iVar3 = (**(code **)(_r_ip_funcs_p + 0x43c))(*(code **)(_r_ip_funcs_p + 0x43c));
      uVar5 = (uint)bStack_21;
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
      (*(code *)_r_modules_funcs_p[0x2e])(3,0,(code *)_r_modules_funcs_p[0x2e]);
      (**(code **)(_r_ip_funcs_p + 0x53c))(*(code **)(_r_ip_funcs_p + 0x53c));
      iVar3 = 0;
      goto _L79;
    }
    iVar3 = 0xfe;
    if ((_sdk_cfg_priv_opts & 8) != 0) goto _L79;
  }
_L113:
  iVar3 = 0xc;
_L79:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar3,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

