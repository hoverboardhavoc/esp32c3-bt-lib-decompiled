/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
  undefined1 uVar4;
  byte bVar5;
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
  if ((*(char *)(iVar6 + 0x18) == '\0') ||
     (iVar6 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0)),
     *(char *)(iVar6 + 0x25) == '\0')) {
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
_L129:
    iVar6 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    iVar6 = (**(code **)(_r_ip_funcs_p + 0x544))(*param_1,0,*(code **)(_r_ip_funcs_p + 0x544));
    bStack_3d = (byte)iVar6;
    if (iVar6 == 0xff) {
      iVar6 = (**(code **)(_r_ip_funcs_p + 0x4ac))(&bStack_3d,*(code **)(_r_ip_funcs_p + 0x4ac));
      if (iVar6 != 0) goto _L132;
      *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_3d * 0x44 + 0x3d) = 0xff;
    }
    else if (*(char *)(*(int *)(_p_llm_env + 8) + iVar6 * 0x44 + 0x40) != '\x01') goto _L129;
    if ((*param_1 < 0xf0) &&
       ((uVar1 = *(ushort *)(param_1 + 2), (uVar1 & 0x10) == 0 ||
        ((uVar1 < 0x1e && ((0x202d0000U >> (uVar1 & 0x1f) & 1) != 0)))))) {
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
      uVar1 = *(ushort *)(param_1 + 2);
      if (((*(char *)(iVar6 + 0x22) != '\0') ||
          ((((uVar1 & 0x10) == 0 || (uVar8 = uVar1 - 0x13, 10 < (uVar8 & 0xffff))) ||
           ((0x405U >> (uVar8 & 0x1f) & 1) == 0)))) &&
         (((uVar1 & 0x10) != 0 ||
          (((((uVar1 & 3) != 3 && ((uVar1 & 8) == 0)) &&
            (((uVar1 & 3) == 0 || ((uVar1 & 0x20) == 0)))) &&
           (((uVar1 & 1) == 0 ||
            (iVar6 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0)),
            *(char *)(iVar6 + 0x22) != '\0')))))))) {
        uVar1 = *(ushort *)(param_1 + 2);
        if (((uVar1 & 0x10) == 0) || (param_1[0x15] == 1)) {
          uVar9 = (uint)param_1[6] << 0x10 | (uint)param_1[5] << 8 | (uint)param_1[4];
          uVar8 = (uint)param_1[9] << 0x10 | (uint)param_1[8] << 8 | (uint)param_1[7];
          if (((((((uVar9 <= uVar8) && ((byte)(param_1[10] - 1) < 7)) && (param_1[0x13] < 4)) &&
                ((7 < uVar9 && (7 < uVar8)))) &&
               (((param_1[0x15] & 0xfd) == 1 &&
                (((uVar1 & 0x10) != 0 || ((byte)(param_1[0x17] - 1) < 3)))))) &&
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
                        (0,"llm_adv.c",0x347,*(code **)(_r_plf_funcs_p + 0xc));
            }
            *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_3d * 0x44 + 0x40) = 1;
            pcVar2 = _adv_evt_type2prop;
            bVar5 = param_1[0x14];
            if (bVar5 == 0x7f) {
              (*_bt_rf_coex_hooks_p)(6,0xd,_bt_rf_coex_hooks_p);
              bVar5 = (*pcVar2)(1);
            }
            pcVar2 = _adv_evt_type2prop;
            (*_memcpy)((int)(char)bVar5,0,_memcpy);
            uVar4 = (*pcVar2)(1);
            iVar6 = *(int *)(_p_llm_env + 8) + (uint)bStack_3d * 0x44;
            *(undefined1 *)(iVar6 + 0x3c) = uVar4;
            puVar7[1] = uVar4;
            if ((_bt_rf_coex_hooks_p != (code *)0x0) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
              uStack_38 = *(undefined2 *)(iVar6 + 0x2a);
              uStack_36 = *(undefined2 *)(iVar6 + 0x34);
              bStack_34 = param_1[10];
              uStack_3c = uVar8;
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
            uVar3 = 0;
            uVar4 = 1;
            goto _L156;
          }
        }
      }
    }
    iVar6 = 0x12;
  }
_L132:
  uVar3 = (undefined1)iVar6;
  uVar4 = 0;
_L156:
  *puVar7 = uVar3;
  (**(code **)(_r_ip_funcs_p + 0x8c))(puVar7,*(code **)(_r_ip_funcs_p + 0x8c));
  return uVar4;
}

