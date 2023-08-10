/*
 * Last changed at upstream commit 0cfac1b21ebc995e8e9aa040ab1ab29deee4f580
 * https://github.com/espressif/esp32c3-bt-lib/commit/0cfac1b21ebc995e8e9aa040ab1ab29deee4f580
 * Upstream date: 2023-08-10 21:56:13 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(59725b5)
 * Source: libbtdm_app -> llm_adv.o -> hci_le_set_ext_adv_param_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_ext_adv_param_cmd_handler(byte *param_1,undefined4 param_2)

{
  ushort uVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  byte bVar5;
  undefined1 *puVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint uVar10;
  byte bStack_2d;
  uint uStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_26;
  byte bStack_24;
  byte bStack_23;
  byte bStack_22;
  byte bStack_21;
  
  puVar6 = (undefined1 *)
           (*(code *)_r_modules_funcs_p[0x32])(0x1101,0,param_2,2,(code *)_r_modules_funcs_p[0x32]);
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L118:
    iVar7 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    iVar7 = (**(code **)(_r_ip_funcs_p + 0x544))(*param_1,0,*(code **)(_r_ip_funcs_p + 0x544));
    bStack_2d = (byte)iVar7;
    if (iVar7 == 0xff) {
      iVar7 = (**(code **)(_r_ip_funcs_p + 0x4ac))(&bStack_2d,*(code **)(_r_ip_funcs_p + 0x4ac));
      if (iVar7 != 0) goto _L121;
      *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44 + 0x3d) = 0xff;
    }
    else if (*(char *)(iVar7 * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) != '\x01') goto _L118;
    if (*param_1 < 0xf0) {
      uVar1 = *(ushort *)(param_1 + 2);
      uVar8 = (uint)uVar1;
      if ((uVar1 & 0x10) == 0) {
        if ((((uVar8 & 3) != 3) && ((uVar1 & 8) == 0)) &&
           (((uVar1 & 3) == 0 || ((uVar1 & 0x20) == 0)))) goto _L126;
      }
      else if (((uVar8 < 0x1e) && ((0x202d0000U >> (uVar8 & 0x1f) & 1) != 0)) &&
              (param_1[0x15] == 1)) {
_L126:
        uVar8 = (uint)param_1[6] << 0x10 | (uint)param_1[5] << 8 | (uint)param_1[4];
        uVar10 = (uint)param_1[9] << 0x10 | (uint)param_1[8] << 8 | (uint)param_1[7];
        if (((((uVar8 <= uVar10) && ((byte)(param_1[10] - 1) < 7)) &&
             ((param_1[0x13] < 4 &&
              (((7 < uVar8 && (7 < uVar10)) &&
               (((param_1[0x15] & 0xfd) == 1 &&
                (((uVar1 & 0x10) != 0 || ((byte)(param_1[0x17] - 1) < 3)))))))))) &&
            (((uVar1 & 4) == 0 ||
             (iVar7 = (*(code *)*_r_modules_funcs_p)
                                (param_1 + 0xd,&co_null_bdaddr,(code *)*_r_modules_funcs_p),
             iVar7 == 0)))) && ((param_1[0x18] < 0x10 && (param_1[0x19] < 2)))) {
          iVar7 = *(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44);
          if (iVar7 != 0) {
            (*(code *)_r_modules_funcs_p[0x36])(iVar7 + -0xc,(code *)_r_modules_funcs_p[0x36]);
            *(undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44) = 0;
          }
          puVar9 = (undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44);
          *puVar9 = param_1;
          *(undefined1 *)((int)puVar9 + 0x3e) = 0xff;
          if (3 < param_1[0xb]) {
            (**(code **)(_r_plf_funcs_p + 0xc))
                      (0,"llm_adv.c",0x309,*(code **)(_r_plf_funcs_p + 0xc));
          }
          *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44 + 0x40) = 1;
          pcVar2 = _memcpy;
          bVar5 = param_1[0x14];
          if (bVar5 == 0x7f) {
            (*_r_plf_funcs_p)(6,0xd,_r_plf_funcs_p);
            bVar5 = (*pcVar2)(1);
          }
          pcVar2 = _memcpy;
          (*_bt_rf_coex_hooks_p)((int)(char)bVar5,0,_bt_rf_coex_hooks_p);
          uVar4 = (*pcVar2)(1);
          iVar7 = *(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44;
          *(undefined1 *)(iVar7 + 0x3c) = uVar4;
          puVar6[1] = uVar4;
          if ((_bt_rf_coex_hooks_p != (code *)0x0) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
            uStack_28 = *(undefined2 *)(iVar7 + 0x2a);
            uStack_26 = *(undefined2 *)(iVar7 + 0x34);
            bStack_24 = param_1[10];
            uStack_2c = uVar10;
            if ((param_1[0x15] < 3) || (iVar7 = lld_phy_coded_500k_get(), iVar7 == 0)) {
              bStack_23 = param_1[0x15] - 1;
            }
            else {
              bStack_23 = param_1[0x15];
            }
            if ((param_1[0x17] < 3) || (iVar7 = lld_phy_coded_500k_get(), iVar7 == 0)) {
              bStack_22 = param_1[0x17] - 1;
            }
            else {
              bStack_22 = param_1[0x17];
            }
            bStack_21 = param_1[0x16];
            (**(code **)(_bt_rf_coex_hooks_p + 4))
                      (bStack_2d,2,&uStack_2c,*(code **)(_bt_rf_coex_hooks_p + 4));
          }
          uVar4 = 0;
          uVar3 = 1;
          goto _L140;
        }
      }
    }
    iVar7 = 0x12;
  }
_L121:
  uVar4 = (undefined1)iVar7;
  uVar3 = 0;
_L140:
  *puVar6 = uVar4;
  (**(code **)(_r_ip_funcs_p + 0x8c))(puVar6,*(code **)(_r_ip_funcs_p + 0x8c));
  return uVar3;
}

