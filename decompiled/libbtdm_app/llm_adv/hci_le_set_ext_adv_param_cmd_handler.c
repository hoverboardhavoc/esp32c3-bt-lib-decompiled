/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
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
  undefined2 uVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  byte bVar6;
  undefined1 *puVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint uVar11;
  byte bStack_2d;
  uint uStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_26;
  byte bStack_24;
  byte bStack_23;
  byte bStack_22;
  byte bStack_21;
  
  puVar7 = (undefined1 *)
           (*(code *)_r_modules_funcs_p[0x32])(0x1101,0,param_2,2,(code *)_r_modules_funcs_p[0x32]);
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L118:
    iVar8 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    iVar8 = (**(code **)(_r_ip_funcs_p + 0x544))(*param_1,0,*(code **)(_r_ip_funcs_p + 0x544));
    bStack_2d = (byte)iVar8;
    if (iVar8 == 0xff) {
      iVar8 = (**(code **)(_r_ip_funcs_p + 0x4ac))(&bStack_2d,*(code **)(_r_ip_funcs_p + 0x4ac));
      if (iVar8 != 0) goto _L121;
      *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44 + 0x3d) = 0xff;
    }
    else if (*(char *)(iVar8 * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) != '\x01') goto _L118;
    if (*param_1 < 0xf0) {
      uVar1 = *(ushort *)(param_1 + 2);
      uVar9 = (uint)uVar1;
      if ((uVar1 & 0x10) == 0) {
        if ((((uVar9 & 3) != 3) && ((uVar1 & 8) == 0)) &&
           (((uVar1 & 3) == 0 || ((uVar1 & 0x20) == 0)))) goto _L126;
      }
      else if (((uVar9 < 0x1e) && ((0x202d0000U >> (uVar9 & 0x1f) & 1) != 0)) &&
              (param_1[0x15] == 1)) {
_L126:
        uVar9 = (uint)param_1[6] << 0x10 | (uint)param_1[5] << 8 | (uint)param_1[4];
        uVar11 = (uint)param_1[9] << 0x10 | (uint)param_1[8] << 8 | (uint)param_1[7];
        if (((((uVar9 <= uVar11) && ((byte)(param_1[10] - 1) < 7)) &&
             ((param_1[0x13] < 4 &&
              (((0x1f < uVar9 && (0x1f < uVar11)) &&
               (((param_1[0x15] & 0xfd) == 1 &&
                (((uVar1 & 0x10) != 0 || ((byte)(param_1[0x17] - 1) < 3)))))))))) &&
            (((uVar1 & 4) == 0 ||
             (iVar8 = (*(code *)*_r_modules_funcs_p)
                                (param_1 + 0xd,&co_null_bdaddr,(code *)*_r_modules_funcs_p),
             iVar8 == 0)))) && ((param_1[0x18] < 0x10 && (param_1[0x19] < 2)))) {
          iVar8 = *(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44);
          if (iVar8 != 0) {
            (*(code *)_r_modules_funcs_p[0x36])(iVar8 + -0xc,(code *)_r_modules_funcs_p[0x36]);
            *(undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44) = 0;
          }
          iVar8 = _p_llm_env;
          puVar10 = (undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44);
          *(undefined1 *)((int)puVar10 + 0x3e) = 0xff;
          *puVar10 = param_1;
          bVar6 = param_1[0xb];
          if (bVar6 != 1) {
            if ((bVar6 == 0) || (bVar6 == 2)) {
              uVar2 = *(undefined2 *)(iVar8 + 0x10);
              puVar10[1] = *(undefined4 *)(iVar8 + 0xc);
              *(undefined2 *)(puVar10 + 2) = uVar2;
            }
            else if (bVar6 != 3) {
              (**(code **)(_r_plf_funcs_p + 0xc))
                        (0,"llm_adv.c",0x30a,*(code **)(_r_plf_funcs_p + 0xc));
            }
          }
          *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44 + 0x40) = 1;
          pcVar3 = _memcpy;
          bVar6 = param_1[0x14];
          if (bVar6 == 0x7f) {
            (*_r_plf_funcs_p)(6,0xd,_r_plf_funcs_p);
            bVar6 = (*pcVar3)(1);
          }
          pcVar3 = _memcpy;
          (*_bt_rf_coex_hooks_p)((int)(char)bVar6,0,_bt_rf_coex_hooks_p);
          uVar5 = (*pcVar3)(1);
          iVar8 = *(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44;
          *(undefined1 *)(iVar8 + 0x3c) = uVar5;
          puVar7[1] = uVar5;
          if ((_bt_rf_coex_hooks_p != (code *)0x0) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
            uStack_28 = *(undefined2 *)(iVar8 + 0x2a);
            uStack_26 = *(undefined2 *)(iVar8 + 0x34);
            bStack_24 = param_1[10];
            uStack_2c = uVar11;
            if ((param_1[0x15] < 3) || (iVar8 = lld_phy_coded_500k_get(), iVar8 == 0)) {
              bStack_23 = param_1[0x15] - 1;
            }
            else {
              bStack_23 = param_1[0x15];
            }
            if ((param_1[0x17] < 3) || (iVar8 = lld_phy_coded_500k_get(), iVar8 == 0)) {
              bStack_22 = param_1[0x17] - 1;
            }
            else {
              bStack_22 = param_1[0x17];
            }
            bStack_21 = param_1[0x16];
            (**(code **)(_bt_rf_coex_hooks_p + 4))
                      (bStack_2d,2,&uStack_2c,*(code **)(_bt_rf_coex_hooks_p + 4));
          }
          uVar5 = 0;
          uVar4 = 1;
          goto _L142;
        }
      }
    }
    iVar8 = 0x12;
  }
_L121:
  uVar5 = (undefined1)iVar8;
  uVar4 = 0;
_L142:
  *puVar7 = uVar5;
  (**(code **)(_r_ip_funcs_p + 0x8c))(puVar7,*(code **)(_r_ip_funcs_p + 0x8c));
  return uVar4;
}

