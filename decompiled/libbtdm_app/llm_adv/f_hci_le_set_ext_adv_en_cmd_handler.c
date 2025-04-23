/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_adv.o -> f_hci_le_set_ext_adv_en_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_set_ext_adv_en_cmd_handler(short *param_1,undefined4 param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  code *pcVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  byte bVar12;
  uint uVar13;
  undefined2 uStack_98;
  undefined2 uStack_96;
  undefined4 uStack_94;
  undefined2 uStack_90;
  undefined1 uStack_8e;
  undefined1 uStack_8d;
  undefined1 uStack_8c;
  uint uStack_88;
  int iStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  ushort uStack_78;
  undefined2 uStack_76;
  uint uStack_74;
  undefined4 uStack_70;
  uint uStack_68;
  undefined2 uStack_64;
  undefined1 auStack_62 [6];
  uint uStack_5c;
  undefined2 uStack_58;
  undefined2 uStack_56;
  undefined2 uStack_54;
  undefined2 uStack_52;
  ushort uStack_50;
  short sStack_4e;
  char cStack_4c;
  undefined1 uStack_4b;
  undefined1 uStack_4a;
  undefined1 uStack_49;
  undefined1 uStack_48;
  undefined1 uStack_47;
  undefined1 uStack_46;
  undefined1 uStack_45;
  undefined1 uStack_44;
  undefined1 uStack_43;
  undefined1 uStack_42;
  undefined1 uStack_41;
  
  iVar2 = _p_llm_env;
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L396:
    uVar9 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    if ((char)*param_1 == '\0') {
      if (*(char *)(iVar2 + 0xd6) != '\0') {
        return 2;
      }
    }
    else {
      uVar9 = 0x12;
      if ((char)*param_1 != '\x01') goto _L330;
    }
    if (*param_1 == 1) {
_L336:
      uVar9 = 0x12;
    }
    else {
      if (*(char *)((int)param_1 + 1) == '\0') {
        for (uVar9 = 0;
            iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
            uVar9 < *(byte *)(iVar2 + 0xd); uVar9 = uVar9 + 1 & 0xff) {
          if ((*(char *)(*(int *)(_p_llm_env + 8) + uVar9 * 0x44 + 0x40) == '\x02') &&
             (iVar3 = (**(code **)(_r_ip_funcs_p + 0x1e8))(uVar9,*(code **)(_r_ip_funcs_p + 0x1e8)),
             iVar2 = _p_llm_env, iVar3 == 0)) {
            *(undefined1 *)(*(int *)(_p_llm_env + 8) + uVar9 * 0x44 + 0x40) = 3;
            *(char *)(iVar2 + 0xd6) = *(char *)(iVar2 + 0xd6) + '\x01';
            if ((_bt_rf_coex_hooks_p != (int *)0x0) && ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)
               ) {
              (*(code *)*_bt_rf_coex_hooks_p)(uVar9,2,0);
            }
          }
        }
      }
      else {
        bVar8 = 0;
        for (uVar9 = 0; uVar9 < *(byte *)((int)param_1 + 1); uVar9 = uVar9 + 1 & 0xff) {
          if (0xef < *(byte *)((int)param_1 + uVar9 + 2)) goto _L336;
          iVar2 = (**(code **)(_r_ip_funcs_p + 0x544))(0,*(code **)(_r_ip_funcs_p + 0x544));
          if (iVar2 == 0xff) {
            uVar9 = 0x42;
            goto _L330;
          }
          piVar11 = (int *)(*(int *)(_p_llm_env + 8) + iVar2 * 0x44);
          if (((short)piVar11[0xb] != 0) || (*(short *)((int)piVar11 + 0x36) != 0)) goto _L336;
          if ((char)*param_1 == '\x01') {
            iVar3 = *piVar11;
            uVar1 = *(ushort *)(iVar3 + 2);
            if (((uVar1 & 2) == 0) || ((short)piVar11[0xd] != 0)) {
              if (((uVar1 & 0x11) == 1) &&
                 (iVar4 = (**(code **)(_r_ip_funcs_p + 0x540))
                                    (iVar3,*(undefined2 *)((int)piVar11 + 0x2a),
                                     *(code **)(_r_ip_funcs_p + 0x540)), iVar4 != 0)) goto _L336;
            }
            else if ((uVar1 & 0x10) == 0) goto _L396;
            if ((*(ushort *)(iVar3 + 2) & 1) != 0) {
              if (((*(ushort *)(iVar3 + 2) & 0xc) != 0) &&
                 (iVar4 = (**(code **)(_r_ip_funcs_p + 0x4d8))
                                    (iVar3 + 0xd,*(undefined1 *)(iVar3 + 0xc),
                                     *(code **)(_r_ip_funcs_p + 0x4d8)), iVar4 != 0)) {
                uVar9 = 0xb;
                goto _L330;
              }
              if (((*(ushort *)(iVar3 + 2) & 8) != 0) && (0x7f < (ushort)(param_1[uVar9 + 6] - 1U)))
              goto _L336;
              bVar8 = bVar8 + 1;
            }
            if (((*(byte *)(iVar3 + 0xb) & 1) != 0) &&
               (iVar3 = (*(code *)*_r_modules_funcs_p)
                                  (*(int *)(_p_llm_env + 8) + iVar2 * 0x44 + 4,&co_null_bdaddr,
                                   (code *)*_r_modules_funcs_p), iVar3 != 0)) goto _L336;
          }
          else if (((_DAT_00014032 & 2) == 0) && ((char)piVar11[0x10] != '\x02')) goto _L396;
          *(char *)((int)param_1 + uVar9 + 2) = (char)iVar2;
        }
        if (bVar8 != 0) {
          bVar12 = 0;
          for (uVar9 = 0;
              iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
              uVar9 < *(byte *)(iVar2 + 0xd); uVar9 = uVar9 + 1 & 0xff) {
            bVar12 = bVar12 + (*(char *)(*(int *)(_p_llm_env + 8) + uVar9 * 0x44 + 0x40) == '\0');
            if (bVar8 <= bVar12) goto _L353;
          }
          uVar9 = 7;
          if (bVar12 < bVar8) goto _L330;
        }
_L353:
        for (uVar13 = 0; iVar2 = _p_llm_env, uVar13 < *(byte *)((int)param_1 + 1);
            uVar13 = uVar13 + 1 & 0xff) {
          uVar6 = (uint)*(byte *)((int)param_1 + uVar13 + 2);
          iVar3 = uVar6 * 0x44;
          piVar11 = (int *)(*(int *)(_p_llm_env + 8) + iVar3);
          if ((char)piVar11[0x10] == '\x02') {
            if ((char)*param_1 == '\0') {
_L356:
              if ((((_DAT_00014032 & 2) == 0) || ((char)piVar11[0x10] == '\x02')) &&
                 (iVar4 = (**(code **)(_r_ip_funcs_p + 0x1e8))
                                    (uVar6,*(code **)(_r_ip_funcs_p + 0x1e8)), iVar2 = _p_llm_env,
                 iVar4 == 0)) {
                *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar3 + 0x40) = 3;
                *(char *)(iVar2 + 0xd6) = *(char *)(iVar2 + 0xd6) + '\x01';
                uVar9 = 0;
                while ((iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))
                                          (*(code **)(_r_plf_funcs_p + 0x38)),
                       uVar9 < *(byte *)(iVar2 + 0xd) &&
                       (*(char *)(*(int *)(_p_llm_env + 8) + uVar9 * 0x44 + 0x40) != '\x02'))) {
                  uVar9 = uVar9 + 1 & 0xff;
                }
                iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
                if (((*(byte *)(iVar2 + 0xd) <= uVar9) && (_bt_rf_coex_hooks_p != (int *)0x0)) &&
                   (pcVar7 = (code *)*_bt_rf_coex_hooks_p, pcVar7 != (code *)0x0)) {
                  uVar5 = 0;
                  goto _L448;
                }
              }
            }
            else {
              (**(code **)(_r_ip_funcs_p + 0x1d4))
                        (uVar6,param_1[uVar13 + 6],*(char *)((int)param_1 + uVar13 + 0x20),
                         *(code **)(_r_ip_funcs_p + 0x1d4));
              piVar11 = (int *)(*(int *)(_p_llm_env + 8) + iVar3);
              iVar2 = *piVar11;
              if ((iVar2 != 0) && ((*(ushort *)(iVar2 + 2) & 1) != 0)) {
                bVar8 = *(byte *)((int)piVar11 + 0x3e);
                uStack_68 = CONCAT31(uStack_68._1_3_,bVar8);
                if ((bVar8 == 0xff) ||
                   (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bVar8 * 0x44 + 0x40) == '\0')) {
                  iVar2 = (**(code **)(_r_ip_funcs_p + 0x4ac))
                                    (&uStack_68,*(code **)(_r_ip_funcs_p + 0x4ac));
                  if (iVar2 == 0) {
                    iVar2 = *(int *)(_p_llm_env + 8);
                    *(undefined1 *)(iVar3 + iVar2 + 0x3e) = (undefined1)uStack_68;
                    *(undefined1 *)(iVar2 + (uStack_68 & 0xff) * 0x44 + 0x40) = 4;
                  }
                  else {
                    (**(code **)(_r_plf_funcs_p + 0xc))
                              (0,"llm_adv.c",0x613,*(code **)(_r_plf_funcs_p + 0xc));
                  }
                }
              }
            }
          }
          else {
            if ((char)*param_1 == '\0') goto _L356;
            iVar4 = *piVar11;
            uVar1 = *(ushort *)(iVar4 + 2);
            uStack_5c = (uint)*(byte *)(iVar4 + 9) << 0x10 | (uint)*(byte *)(iVar4 + 8) << 8 |
                        (uint)*(byte *)(iVar4 + 7);
            uStack_4b = *(undefined1 *)(iVar4 + 10);
            uStack_4a = *(undefined1 *)(iVar4 + 0xb);
            uStack_49 = *(undefined1 *)(iVar4 + 0xc);
            uStack_50 = uVar1;
            memcpy(auStack_62,(void *)(iVar4 + 0xd),6);
            uStack_48 = 0;
            if ((uVar1 & 4) == 0) {
              uStack_48 = *(undefined1 *)(iVar4 + 0x13);
            }
            uStack_47 = (undefined1)piVar11[0xf];
            uStack_46 = *(undefined1 *)(iVar4 + 0x15);
            if ((uVar1 & 0x10) == 0) {
              uStack_45 = *(undefined1 *)(iVar4 + 0x16);
              uStack_44 = *(undefined1 *)(iVar4 + 0x17);
            }
            else {
              uStack_45 = 0;
              uStack_44 = 1;
            }
            uStack_43 = *(undefined1 *)(iVar4 + 0x18);
            uStack_42 = *(undefined1 *)(iVar4 + 0x19);
            uStack_68 = piVar11[1];
            uStack_64 = (undefined2)piVar11[2];
            uStack_58 = (undefined2)piVar11[10];
            uStack_54 = *(undefined2 *)((int)piVar11 + 0x2a);
            uStack_56 = *(undefined2 *)((int)piVar11 + 0x32);
            uStack_52 = (undefined2)piVar11[0xd];
            sStack_4e = param_1[uVar13 + 6];
            cStack_4c = *(char *)((int)param_1 + uVar13 + 0x20);
            uStack_41 = *(undefined1 *)(iVar2 + 0xc6);
            uVar9 = (**(code **)(_r_ip_funcs_p + 0x1e4))
                              (uVar6,&uStack_68,*(code **)(_r_ip_funcs_p + 0x1e4));
            if (uVar9 != 0) {
              (**(code **)(_r_plf_funcs_p + 0xc))
                        (uVar6,0,"llm_adv.c",0x69c,*(code **)(_r_plf_funcs_p + 0xc));
              goto _L330;
            }
            iVar2 = *(int *)(_p_llm_env + 8) + iVar3;
            *(undefined1 *)(iVar2 + 0x40) = 2;
            if ((*(ushort *)(iVar4 + 2) & 0x13) == 0) {
              bVar8 = *(byte *)(iVar2 + 0x3d);
              uVar9 = (uint)bVar8;
              iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
              if (*(byte *)(iVar2 + 0xd) <= uVar9) goto _L367;
              iVar2 = uVar9 * 0x44;
              piVar11 = (int *)(*(int *)(_p_llm_env + 8) + iVar2);
              if ((char)piVar11[0x10] != '\v') goto _L367;
              iVar4 = *piVar11;
              iVar10 = *(int *)(*(int *)(_p_llm_env + 8) + iVar3);
              iStack_84 = (uint)*(ushort *)(iVar4 + 4) << 1;
              uStack_88 = (uint)*(ushort *)(iVar4 + 2) << 1;
              uStack_80 = (**(code **)(_r_ip_funcs_p + 0x554))
                                    (*(undefined2 *)((int)piVar11 + 0x2a),
                                     *(undefined1 *)(iVar10 + 0x17),
                                     *(code **)(_r_ip_funcs_p + 0x554));
              uStack_76 = 0;
              uStack_7c = uStack_80;
              uStack_78 = (ushort)bVar8;
              iVar3 = (**(code **)(_r_ip_funcs_p + 0x6f8))
                                (&uStack_88,*(code **)(_r_ip_funcs_p + 0x6f8));
              if (iVar3 != 0) break;
              uStack_96 = *(undefined2 *)(iVar4 + 6);
              uStack_98 = (undefined2)(uStack_74 >> 1);
              uStack_90 = (undefined2)uStack_70;
              uStack_94 = *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x28);
              uStack_8e = *(undefined1 *)(iVar10 + 0xb);
              uStack_8d = *(undefined1 *)(iVar10 + 0x14);
              uStack_8c = *(undefined1 *)(iVar10 + 0x17);
              iVar3 = (**(code **)(_r_ip_funcs_p + 0x308))
                                (uVar9,&uStack_98,*(code **)(_r_ip_funcs_p + 0x308));
              if (iVar3 == 0) {
                iVar2 = *(int *)(_p_llm_env + 8) + iVar2;
                *(undefined1 *)(iVar2 + 0x40) = 0xc;
                (**(code **)(_r_ip_funcs_p + 0x1f0))
                          (uVar6,uVar9,uStack_98,*(code **)(_r_ip_funcs_p + 0x1f0));
                *(undefined4 *)(iVar2 + 0x14) = uStack_70;
                *(uint *)(iVar2 + 0x10) = uStack_74;
                *(undefined4 *)(iVar2 + 0x1c) = uStack_7c;
                iVar3 = _r_ip_funcs_p;
                *(undefined1 *)(iVar2 + 0x22) = 0;
                *(undefined4 *)(iVar2 + 0x18) = uStack_80;
                pcVar7 = *(code **)(iVar3 + 0x6fc);
                *(ushort *)(iVar2 + 0x20) = (ushort)bVar8;
                *(undefined4 *)(iVar2 + 0x24) = 0;
                (*pcVar7)(iVar2 + 0xc,pcVar7);
                if ((_bt_rf_coex_hooks_p != (int *)0x0) &&
                   ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
                  (*(code *)*_bt_rf_coex_hooks_p)(uVar9,4,1);
                }
              }
            }
            else {
_L367:
              if ((*(ushort *)(iVar4 + 2) & 1) != 0) {
                iVar2 = (**(code **)(_r_ip_funcs_p + 0x4ac))
                                  (&uStack_88,*(code **)(_r_ip_funcs_p + 0x4ac));
                if (iVar2 == 0) {
                  iVar2 = *(int *)(_p_llm_env + 8);
                  *(undefined1 *)(iVar3 + iVar2 + 0x3e) = (undefined1)uStack_88;
                  *(undefined1 *)(iVar2 + (uStack_88 & 0xff) * 0x44 + 0x40) = 4;
                }
                else {
                  (**(code **)(_r_plf_funcs_p + 8))
                            (0,"llm_adv.c",0x690,*(code **)(_r_plf_funcs_p + 8));
                }
              }
            }
            if (_bt_rf_coex_hooks_p != (int *)0x0) {
              pcVar7 = (code *)*_bt_rf_coex_hooks_p;
              uVar5 = 1;
              if (pcVar7 != (code *)0x0) {
_L448:
                (*pcVar7)(uVar6,2,uVar5);
              }
            }
          }
        }
      }
      if ((char)*param_1 == '\0') {
        uVar9 = (uint)*(byte *)(_p_llm_env + 0xd6);
        if (uVar9 != 0) {
          return 0;
        }
      }
      else {
        uVar9 = 0;
      }
    }
  }
_L330:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar9,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

