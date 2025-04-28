/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_adv.o -> hci_le_set_ext_adv_param_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 hci_le_set_ext_adv_param_cmd_handler(byte *param_1,undefined4 param_2)

{
  ushort uVar1;
  code *pcVar2;
  undefined1 uVar3;
  byte bVar4;
  undefined1 uVar5;
  int iVar6;
  undefined1 *puVar7;
  uint uVar8;
  uint uVar9;
  byte bStack_3d;
  uint uStack_3c;
  undefined2 uStack_38;
  undefined2 uStack_36;
  byte bStack_34;
  byte bStack_33;
  byte bStack_32;
  byte bStack_31;
  
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar6 + 0x18) == '\0') {
    puVar7 = (undefined1 *)
             (*(code *)_r_modules_funcs_p[0x32])
                       (0x1101,0,param_2,2,(code *)_r_modules_funcs_p[0x32]);
    *puVar7 = 0xc;
    (**(code **)(_r_ip_funcs_p + 0x8c))(*(code **)(_r_ip_funcs_p + 0x8c));
    return 0;
  }
  puVar7 = (undefined1 *)
           (*(code *)_r_modules_funcs_p[0x32])(0x1101,0,param_2,2,(code *)_r_modules_funcs_p[0x32]);
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L121:
    iVar6 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    iVar6 = (**(code **)(_r_ip_funcs_p + 0x544))(*param_1,0,*(code **)(_r_ip_funcs_p + 0x544));
    bStack_3d = (byte)iVar6;
    if (iVar6 == 0xff) {
      iVar6 = (**(code **)(_r_ip_funcs_p + 0x4ac))(&bStack_3d,*(code **)(_r_ip_funcs_p + 0x4ac));
      if (iVar6 != 0) goto _L124;
      *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_3d * 0x44 + 0x3d) = 0xff;
    }
    else if (*(char *)(*(int *)(_p_llm_env + 8) + iVar6 * 0x44 + 0x40) != '\x01') goto _L121;
    if (*param_1 < 0xf0) {
      uVar1 = *(ushort *)(param_1 + 2);
      uVar9 = (uint)uVar1;
      if ((uVar1 & 0x10) == 0) {
        if ((((uVar9 & 3) != 3) && ((uVar1 & 8) == 0)) &&
           (((uVar1 & 3) == 0 || ((uVar1 & 0x20) == 0)))) goto _L129;
      }
      else if (((uVar9 < 0x1e) && ((0x202d0000U >> (uVar9 & 0x1f) & 1) != 0)) &&
              (param_1[0x15] == 1)) {
_L129:
        uVar8 = (uint)param_1[6] << 0x10 | (uint)param_1[5] << 8 | (uint)param_1[4];
        uVar9 = (uint)param_1[9] << 0x10 | (uint)param_1[8] << 8 | (uint)param_1[7];
        if (((((uVar8 <= uVar9) && ((byte)(param_1[10] - 1) < 7)) &&
             ((param_1[0x13] < 4 &&
              (((7 < uVar8 && (7 < uVar9)) &&
               (((param_1[0x15] & 0xfd) == 1 &&
                (((uVar1 & 0x10) != 0 || ((byte)(param_1[0x17] - 1) < 3)))))))))) &&
            (((uVar1 & 4) == 0 ||
             (iVar6 = (*(code *)*_r_modules_funcs_p)
                                (param_1 + 0xd,&co_null_bdaddr,(code *)*_r_modules_funcs_p),
             iVar6 == 0)))) && ((param_1[0x18] < 0x10 && (param_1[0x19] < 2)))) {
          iVar6 = *(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_3d * 0x44);
          if (iVar6 != 0) {
            (*(code *)_r_modules_funcs_p[0x36])(iVar6 + -0xc,(code *)_r_modules_funcs_p[0x36]);
            *(undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_3d * 0x44) = 0;
          }
          iVar6 = *(int *)(_p_llm_env + 8);
          *(byte **)((uint)bStack_3d * 0x44 + iVar6) = param_1;
          *(undefined1 *)(iVar6 + (uint)bStack_3d * 0x44 + 0x3e) = 0xff;
          if (3 < param_1[0xb]) {
            (**(code **)(_r_plf_funcs_p + 0xc))
                      (0,"llm_adv.c",0x311,*(code **)(_r_plf_funcs_p + 0xc));
          }
          *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_3d * 0x44 + 0x40) = 1;
          pcVar2 = _memcpy;
          bVar4 = param_1[0x14];
          if (bVar4 == 0x7f) {
            (*_r_plf_funcs_p)(6,0xd,_r_plf_funcs_p);
            bVar4 = (*pcVar2)(1);
          }
          pcVar2 = _memcpy;
          (*_bt_rf_coex_hooks_p)((int)(char)bVar4,0,_bt_rf_coex_hooks_p);
          uVar3 = (*pcVar2)(1);
          iVar6 = *(int *)(_p_llm_env + 8) + (uint)bStack_3d * 0x44;
          *(undefined1 *)(iVar6 + 0x3c) = uVar3;
          puVar7[1] = uVar3;
          if ((_bt_rf_coex_hooks_p != (code *)0x0) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
            uStack_38 = *(undefined2 *)(iVar6 + 0x2a);
            uStack_36 = *(undefined2 *)(iVar6 + 0x34);
            bStack_34 = param_1[10];
            uStack_3c = uVar9;
            if ((param_1[0x15] < 3) || (iVar6 = lld_phy_coded_500k_get(), iVar6 == 0)) {
              bStack_33 = param_1[0x15] - 1;
            }
            else {
              bStack_33 = param_1[0x15];
            }
            if ((param_1[0x17] < 3) || (iVar6 = lld_phy_coded_500k_get(), iVar6 == 0)) {
              bStack_32 = param_1[0x17] - 1;
            }
            else {
              bStack_32 = param_1[0x17];
            }
            bStack_31 = param_1[0x16];
            (**(code **)(_bt_rf_coex_hooks_p + 4))
                      (bStack_3d,2,&uStack_3c,*(code **)(_bt_rf_coex_hooks_p + 4));
          }
          uVar5 = 0;
          uVar3 = 1;
          goto _L143;
        }
      }
    }
    iVar6 = 0x12;
  }
_L124:
  uVar5 = (undefined1)iVar6;
  uVar3 = 0;
_L143:
  *puVar7 = uVar5;
  (**(code **)(_r_ip_funcs_p + 0x8c))(puVar7,*(code **)(_r_ip_funcs_p + 0x8c));
  return uVar3;
}

