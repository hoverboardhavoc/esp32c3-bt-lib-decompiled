/*
 * Last changed at upstream commit 0cfac1b21ebc995e8e9aa040ab1ab29deee4f580
 * https://github.com/espressif/esp32c3-bt-lib/commit/0cfac1b21ebc995e8e9aa040ab1ab29deee4f580
 * Upstream date: 2023-08-10 21:56:13 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(59725b5)
 * Source: libbtdm_app -> llm_adv.o -> hci_le_set_ext_adv_en_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_ext_adv_en_cmd_handler(byte *param_1,undefined4 param_2)

{
  ushort uVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  undefined4 uVar6;
  code *pcVar7;
  byte bVar8;
  uint uVar9;
  byte bVar10;
  uint uVar11;
  int iVar12;
  int *piVar13;
  uint uVar14;
  int iVar15;
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
  undefined2 uStack_4e;
  byte bStack_4c;
  undefined1 uStack_4b;
  byte bStack_4a;
  undefined1 uStack_49;
  undefined1 uStack_48;
  undefined1 uStack_47;
  undefined1 uStack_46;
  undefined1 uStack_45;
  undefined1 uStack_44;
  undefined1 uStack_43;
  undefined1 uStack_42;
  undefined1 uStack_41;
  
  iVar12 = _p_llm_env;
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L309:
    iVar12 = 0xc;
    goto _L300;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  if (*param_1 == 0) {
    pbVar4 = (byte *)0x2;
    if (*(char *)(iVar12 + 0xd6) != '\0') {
      return 2;
    }
_L303:
    if (*(short *)param_1 != 1) {
      if (param_1[1] == 0) {
        for (uVar9 = 0;
            iVar12 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
            uVar9 < *(byte *)(iVar12 + 0xd); uVar9 = uVar9 + 1 & 0xff) {
          if ((*(char *)(*(int *)(_p_llm_env + 8) + uVar9 * 0x44 + 0x40) == '\x02') &&
             (iVar2 = (**(code **)(_r_ip_funcs_p + 0x1e8))(uVar9,*(code **)(_r_ip_funcs_p + 0x1e8)),
             iVar12 = _p_llm_env, iVar2 == 0)) {
            *(undefined1 *)(*(int *)(_p_llm_env + 8) + uVar9 * 0x44 + 0x40) = 3;
            *(char *)(iVar12 + 0xd6) = *(char *)(iVar12 + 0xd6) + '\x01';
            if ((_bt_rf_coex_hooks_p != (int *)0x0) && ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)
               ) {
              (*(code *)*_bt_rf_coex_hooks_p)(uVar9,2,0);
            }
          }
        }
      }
      else {
        bVar8 = 0;
        for (uVar9 = 0; uVar9 < param_1[1]; uVar9 = uVar9 + 1 & 0xff) {
          if (0xef < param_1[uVar9 + 2]) goto _L304;
          pbVar3 = (byte *)(**(code **)(_r_ip_funcs_p + 0x544))(0,*(code **)(_r_ip_funcs_p + 0x544))
          ;
          if (pbVar3 == (byte *)0xff) {
            iVar12 = 0x42;
            goto _L300;
          }
          piVar13 = (int *)(*(int *)(_p_llm_env + 8) + (int)pbVar3 * 0x44);
          if (((short)piVar13[0xb] != 0) || (*(short *)((int)piVar13 + 0x36) != 0)) goto _L304;
          pbVar4 = pbVar3;
          if (*param_1 == 1) {
            iVar12 = *piVar13;
            uVar1 = *(ushort *)(iVar12 + 2);
            if (((uVar1 & 2) != 0) && ((uVar1 & 0x10) == 0 && (short)piVar13[0xd] == 0)) goto _L309;
            if (((uVar1 & 0x11) == 1) &&
               (pbVar4 = (byte *)(**(code **)(_r_ip_funcs_p + 0x540))
                                           (iVar12,*(undefined2 *)((int)piVar13 + 0x2a),
                                            *(code **)(_r_ip_funcs_p + 0x540)),
               pbVar4 != (byte *)0x0)) goto _L304;
            if ((*(ushort *)(iVar12 + 2) & 1) != 0) {
              if (((*(ushort *)(iVar12 + 2) & 0xc) != 0) &&
                 (pbVar4 = (byte *)(**(code **)(_r_ip_funcs_p + 0x4d8))
                                             (iVar12 + 0xd,*(undefined1 *)(iVar12 + 0xc),
                                              *(code **)(_r_ip_funcs_p + 0x4d8)),
                 pbVar4 != (byte *)0x0)) {
                iVar12 = 0xb;
                goto _L300;
              }
              if (((*(ushort *)(iVar12 + 2) & 8) != 0) &&
                 (0x7f < (ushort)(*(short *)(param_1 + uVar9 * 2 + 0xc) - 1U))) goto _L304;
              bVar8 = bVar8 + 1;
            }
            if (((*(byte *)(iVar12 + 0xb) & 1) != 0) &&
               (pbVar4 = (byte *)(*(code *)*_r_modules_funcs_p)
                                           (*(int *)(_p_llm_env + 8) + (int)pbVar3 * 0x44 + 4,
                                            &co_null_bdaddr,(code *)*_r_modules_funcs_p),
               pbVar4 != (byte *)0x0)) goto _L304;
          }
          else if (((_DAT_00013032 & 2) == 0) && ((char)piVar13[0x10] != '\x02')) goto _L309;
          param_1[uVar9 + 2] = (byte)pbVar3;
        }
        if (bVar8 != 0) {
          bVar10 = 0;
          for (uVar9 = 0;
              pbVar4 = (byte *)(**(code **)(_r_plf_funcs_p + 0x38))
                                         (pbVar4,*(code **)(_r_plf_funcs_p + 0x38)),
              uVar9 < pbVar4[0xd]; uVar9 = uVar9 + 1 & 0xff) {
            bVar10 = bVar10 + (*(char *)(*(int *)(_p_llm_env + 8) + uVar9 * 0x44 + 0x40) == '\0');
            if (bVar8 <= bVar10) goto _L324;
          }
          iVar12 = 7;
          if (bVar10 < bVar8) goto _L300;
        }
_L324:
        for (uVar9 = 0; iVar12 = _p_llm_env, uVar9 < param_1[1]; uVar9 = uVar9 + 1 & 0xff) {
          uVar11 = (uint)param_1[uVar9 + 2];
          iVar2 = uVar11 * 0x44;
          piVar13 = (int *)(*(int *)(_p_llm_env + 8) + iVar2);
          if ((char)piVar13[0x10] == '\x02') {
            if (*param_1 == 0) {
_L326:
              if ((((_DAT_00013032 & 2) == 0) || ((char)piVar13[0x10] == '\x02')) &&
                 (iVar5 = (**(code **)(_r_ip_funcs_p + 0x1e8))
                                    (uVar11,*(code **)(_r_ip_funcs_p + 0x1e8)), iVar12 = _p_llm_env,
                 iVar5 == 0)) {
                *(undefined1 *)(iVar2 + *(int *)(_p_llm_env + 8) + 0x40) = 3;
                *(char *)(iVar12 + 0xd6) = *(char *)(iVar12 + 0xd6) + '\x01';
                uVar14 = 0;
                while ((iVar12 = (**(code **)(_r_plf_funcs_p + 0x38))
                                           (*(code **)(_r_plf_funcs_p + 0x38)),
                       uVar14 < *(byte *)(iVar12 + 0xd) &&
                       (*(char *)(*(int *)(_p_llm_env + 8) + uVar14 * 0x44 + 0x40) != '\x02'))) {
                  uVar14 = uVar14 + 1 & 0xff;
                }
                iVar12 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
                if (((*(byte *)(iVar12 + 0xd) <= uVar14) && (_bt_rf_coex_hooks_p != (int *)0x0)) &&
                   (pcVar7 = (code *)*_bt_rf_coex_hooks_p, pcVar7 != (code *)0x0)) {
                  uVar6 = 0;
                  goto _L421;
                }
              }
            }
            else {
              (**(code **)(_r_ip_funcs_p + 0x1d4))
                        (uVar11,*(undefined2 *)(param_1 + uVar9 * 2 + 0xc),param_1[uVar9 + 0x20],
                         *(code **)(_r_ip_funcs_p + 0x1d4));
              piVar13 = (int *)(*(int *)(_p_llm_env + 8) + iVar2);
              iVar12 = *piVar13;
              if ((iVar12 != 0) && ((*(ushort *)(iVar12 + 2) & 1) != 0)) {
                bVar8 = *(byte *)((int)piVar13 + 0x3e);
                uStack_68 = CONCAT31(uStack_68._1_3_,bVar8);
                if ((bVar8 == 0xff) ||
                   (*(char *)((uint)bVar8 * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) == '\0')) {
                  iVar12 = (**(code **)(_r_ip_funcs_p + 0x4ac))
                                     (&uStack_68,*(code **)(_r_ip_funcs_p + 0x4ac));
                  if (iVar12 == 0) {
                    iVar12 = *(int *)(_p_llm_env + 8);
                    *(undefined1 *)(iVar2 + iVar12 + 0x3e) = (undefined1)uStack_68;
                    *(undefined1 *)(iVar12 + (uStack_68 & 0xff) * 0x44 + 0x40) = 4;
                  }
                  else {
                    (**(code **)(_r_plf_funcs_p + 0xc))
                              (0,"llm_adv.c",0x5d6,*(code **)(_r_plf_funcs_p + 0xc));
                  }
                }
              }
            }
          }
          else {
            if (*param_1 == 0) goto _L326;
            iVar5 = *piVar13;
            uVar1 = *(ushort *)(iVar5 + 2);
            uStack_5c = (uint)*(byte *)(iVar5 + 9) << 0x10 | (uint)*(byte *)(iVar5 + 8) << 8 |
                        (uint)*(byte *)(iVar5 + 7);
            uStack_4b = *(undefined1 *)(iVar5 + 10);
            bVar8 = *(byte *)(iVar5 + 0xb);
            uStack_49 = *(undefined1 *)(iVar5 + 0xc);
            uStack_50 = uVar1;
            bStack_4a = bVar8;
            memcpy(auStack_62,(void *)(iVar5 + 0xd),6);
            uStack_48 = 0;
            if ((uVar1 & 4) == 0) {
              uStack_48 = *(undefined1 *)(iVar5 + 0x13);
            }
            uStack_47 = (undefined1)piVar13[0xf];
            uStack_46 = *(undefined1 *)(iVar5 + 0x15);
            uStack_45 = 0;
            if ((uVar1 & 0x10) == 0) {
              uStack_45 = *(undefined1 *)(iVar5 + 0x16);
            }
            uStack_44 = 1;
            if ((uVar1 & 0x10) == 0) {
              uStack_44 = *(undefined1 *)(iVar5 + 0x17);
            }
            uStack_43 = *(undefined1 *)(iVar5 + 0x18);
            uStack_42 = *(undefined1 *)(iVar5 + 0x19);
            if ((bVar8 & 1) == 0) {
              uStack_68 = *(uint *)(iVar12 + 0xc);
              uStack_64 = *(undefined2 *)(iVar12 + 0x10);
            }
            else {
              uStack_68 = piVar13[1];
              uStack_64 = (undefined2)piVar13[2];
            }
            uStack_58 = (undefined2)piVar13[10];
            uStack_54 = *(undefined2 *)((int)piVar13 + 0x2a);
            uStack_56 = *(undefined2 *)((int)piVar13 + 0x32);
            uStack_52 = (undefined2)piVar13[0xd];
            uStack_4e = *(undefined2 *)(param_1 + uVar9 * 2 + 0xc);
            bStack_4c = param_1[uVar9 + 0x20];
            uStack_41 = *(undefined1 *)(iVar12 + 0xc6);
            iVar12 = (**(code **)(_r_ip_funcs_p + 0x1e4))
                               (uVar11,&uStack_68,*(code **)(_r_ip_funcs_p + 0x1e4));
            if (iVar12 != 0) {
              (**(code **)(_r_plf_funcs_p + 0xc))
                        (uVar11,0,"llm_adv.c",0x65f,*(code **)(_r_plf_funcs_p + 0xc));
              goto _L300;
            }
            iVar12 = *(int *)(_p_llm_env + 8) + iVar2;
            *(undefined1 *)(iVar12 + 0x40) = 2;
            if ((*(ushort *)(iVar5 + 2) & 0x13) == 0) {
              bVar8 = *(byte *)(iVar12 + 0x3d);
              uVar14 = (uint)bVar8;
              iVar12 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
              if (*(byte *)(iVar12 + 0xd) <= uVar14) goto _L339;
              iVar12 = uVar14 * 0x44;
              piVar13 = (int *)(*(int *)(_p_llm_env + 8) + iVar12);
              if ((char)piVar13[0x10] != '\v') goto _L339;
              iVar5 = *piVar13;
              iVar15 = *(int *)(iVar2 + *(int *)(_p_llm_env + 8));
              iStack_84 = (uint)*(ushort *)(iVar5 + 4) << 1;
              uStack_88 = (uint)*(ushort *)(iVar5 + 2) << 1;
              uStack_80 = (**(code **)(_r_ip_funcs_p + 0x554))
                                    (*(undefined2 *)((int)piVar13 + 0x2a),
                                     *(undefined1 *)(iVar15 + 0x17),
                                     *(code **)(_r_ip_funcs_p + 0x554));
              uStack_76 = 0;
              uStack_7c = uStack_80;
              uStack_78 = (ushort)bVar8;
              iVar2 = (**(code **)(_r_ip_funcs_p + 0x6f8))
                                (&uStack_88,*(code **)(_r_ip_funcs_p + 0x6f8));
              if (iVar2 != 0) break;
              uStack_96 = *(undefined2 *)(iVar5 + 6);
              uStack_98 = (undefined2)(uStack_74 >> 1);
              uStack_90 = (undefined2)uStack_70;
              uStack_94 = *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar12 + 0x28);
              uStack_8e = *(undefined1 *)(iVar15 + 0xb);
              uStack_8d = *(undefined1 *)(iVar15 + 0x14);
              uStack_8c = *(undefined1 *)(iVar15 + 0x17);
              iVar2 = (**(code **)(_r_ip_funcs_p + 0x308))
                                (uVar14,&uStack_98,*(code **)(_r_ip_funcs_p + 0x308));
              if (iVar2 == 0) {
                iVar12 = *(int *)(_p_llm_env + 8) + iVar12;
                *(undefined1 *)(iVar12 + 0x40) = 0xc;
                (**(code **)(_r_ip_funcs_p + 0x1f0))
                          (uVar11,uVar14,uStack_98,*(code **)(_r_ip_funcs_p + 0x1f0));
                *(undefined4 *)(iVar12 + 0x14) = uStack_70;
                *(uint *)(iVar12 + 0x10) = uStack_74;
                *(undefined4 *)(iVar12 + 0x18) = uStack_80;
                *(undefined1 *)(iVar12 + 0x22) = 0;
                *(ushort *)(iVar12 + 0x20) = (ushort)bVar8;
                *(undefined4 *)(iVar12 + 0x1c) = uStack_7c;
                iVar2 = _r_ip_funcs_p;
                *(undefined4 *)(iVar12 + 0x24) = 0;
                (**(code **)(iVar2 + 0x6fc))(iVar12 + 0xc,*(code **)(iVar2 + 0x6fc));
                if ((_bt_rf_coex_hooks_p != (int *)0x0) &&
                   ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
                  (*(code *)*_bt_rf_coex_hooks_p)(uVar14,4,1);
                }
              }
            }
            else {
_L339:
              if ((*(ushort *)(iVar5 + 2) & 1) != 0) {
                iVar12 = (**(code **)(_r_ip_funcs_p + 0x4ac))
                                   (&uStack_88,*(code **)(_r_ip_funcs_p + 0x4ac));
                if (iVar12 == 0) {
                  iVar12 = *(int *)(_p_llm_env + 8);
                  *(undefined1 *)(iVar2 + iVar12 + 0x3e) = (undefined1)uStack_88;
                  *(undefined1 *)(iVar12 + (uStack_88 & 0xff) * 0x44 + 0x40) = 4;
                }
                else {
                  (**(code **)(_r_plf_funcs_p + 8))
                            (0,"llm_adv.c",0x653,*(code **)(_r_plf_funcs_p + 8));
                }
              }
            }
            if (_bt_rf_coex_hooks_p != (int *)0x0) {
              pcVar7 = (code *)*_bt_rf_coex_hooks_p;
              uVar6 = 1;
              if (pcVar7 != (code *)0x0) {
_L421:
                (*pcVar7)(uVar11,2,uVar6);
              }
            }
          }
        }
      }
      if (*param_1 == 0) {
        if (*(char *)(_p_llm_env + 0xd6) != '\0') {
          return 0;
        }
        iVar12 = 0;
      }
      else {
        iVar12 = 0;
      }
      goto _L300;
    }
  }
  else {
    pbVar4 = param_1;
    if (*param_1 < 2) goto _L303;
  }
_L304:
  iVar12 = 0x12;
_L300:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar12,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

