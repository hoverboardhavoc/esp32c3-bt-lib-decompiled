/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  short *psVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  code *pcVar6;
  uint uVar7;
  byte bVar8;
  byte bVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
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
  
  iVar13 = _p_llm_env;
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L338:
    iVar13 = 0xc;
    goto _L330;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  if ((char)*param_1 == '\0') {
    psVar2 = (short *)0x2;
    if (*(char *)(iVar13 + 0xd6) != '\0') {
      return 2;
    }
_L333:
    if (*param_1 != 1) {
      if (*(char *)((int)param_1 + 1) == '\0') {
        for (uVar7 = 0;
            psVar2 = (short *)(**(code **)(_r_plf_funcs_p + 0x38))
                                        (psVar2,*(code **)(_r_plf_funcs_p + 0x38)),
            uVar7 < *(byte *)((int)psVar2 + 0xd); uVar7 = uVar7 + 1 & 0xff) {
          if ((*(char *)(*(int *)(_p_llm_env + 8) + uVar7 * 0x44 + 0x40) == '\x02') &&
             (psVar2 = (short *)(**(code **)(_r_ip_funcs_p + 0x1e8))
                                          (uVar7,*(code **)(_r_ip_funcs_p + 0x1e8)),
             iVar13 = _p_llm_env, psVar2 == (short *)0x0)) {
            *(undefined1 *)(*(int *)(_p_llm_env + 8) + uVar7 * 0x44 + 0x40) = 3;
            *(char *)(iVar13 + 0xd6) = *(char *)(iVar13 + 0xd6) + '\x01';
            if ((_bt_rf_coex_hooks_p != (int *)0x0) && ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)
               ) {
              psVar2 = (short *)(*(code *)*_bt_rf_coex_hooks_p)(uVar7,2,0);
            }
          }
        }
      }
      else {
        uVar7 = 0;
        bVar8 = 0;
        do {
          if (0xef < *(byte *)((int)param_1 + uVar7 + 2)) goto _L334;
          iVar13 = (**(code **)(_r_ip_funcs_p + 0x544))(0,*(code **)(_r_ip_funcs_p + 0x544));
          if (iVar13 == 0xff) {
            iVar13 = 0x42;
            goto _L330;
          }
          piVar5 = (int *)(*(int *)(_p_llm_env + 8) + iVar13 * 0x44);
          if (((short)piVar5[0xb] != 0) || (*(short *)((int)piVar5 + 0x36) != 0)) goto _L334;
          if ((char)*param_1 == '\x01') {
            iVar11 = *piVar5;
            uVar1 = *(ushort *)(iVar11 + 2);
            if (((uVar1 & 2) != 0) && ((uVar1 & 0x10) == 0 && (short)piVar5[0xd] == 0)) goto _L338;
            if (((uVar1 & 0x11) == 1) &&
               (iVar3 = (**(code **)(_r_ip_funcs_p + 0x540))
                                  (iVar11,*(undefined2 *)((int)piVar5 + 0x2a),
                                   *(code **)(_r_ip_funcs_p + 0x540)), iVar3 != 0)) goto _L334;
            if ((*(ushort *)(iVar11 + 2) & 1) != 0) {
              if (((*(ushort *)(iVar11 + 2) & 0xc) != 0) &&
                 (iVar3 = (**(code **)(_r_ip_funcs_p + 0x4d8))
                                    (iVar11 + 0xd,*(undefined1 *)(iVar11 + 0xc),
                                     *(code **)(_r_ip_funcs_p + 0x4d8)), iVar3 != 0)) {
                iVar13 = 0xb;
                goto _L330;
              }
              if (((*(ushort *)(iVar11 + 2) & 8) != 0) && (0x7f < (ushort)(param_1[uVar7 + 6] - 1U))
                 ) goto _L334;
              bVar8 = bVar8 + 1;
            }
            if (((*(byte *)(iVar11 + 0xb) & 1) != 0) &&
               (iVar11 = (*(code *)*_r_modules_funcs_p)
                                   (*(int *)(_p_llm_env + 8) + iVar13 * 0x44 + 4,&co_null_bdaddr,
                                    (code *)*_r_modules_funcs_p), iVar11 != 0)) goto _L334;
          }
          else if (((_DAT_00014032 & 2) == 0) && ((char)piVar5[0x10] != '\x02')) goto _L338;
          *(char *)((int)param_1 + uVar7 + 2) = (char)iVar13;
          uVar7 = uVar7 + 1 & 0xff;
        } while (uVar7 < *(byte *)((int)param_1 + 1));
        if (bVar8 != 0) {
          bVar9 = 0;
          for (uVar7 = 0;
              iVar13 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
              uVar7 < *(byte *)(iVar13 + 0xd); uVar7 = uVar7 + 1 & 0xff) {
            bVar9 = bVar9 + (*(char *)(*(int *)(_p_llm_env + 8) + uVar7 * 0x44 + 0x40) == '\0');
            if (bVar8 <= bVar9) goto _L353;
          }
          iVar13 = 7;
          if (bVar9 < bVar8) goto _L330;
        }
_L353:
        for (uVar7 = 0; iVar13 = _p_llm_env, uVar7 < *(byte *)((int)param_1 + 1);
            uVar7 = uVar7 + 1 & 0xff) {
          uVar10 = (uint)*(byte *)((int)param_1 + uVar7 + 2);
          iVar11 = uVar10 * 0x44;
          piVar5 = (int *)(*(int *)(_p_llm_env + 8) + iVar11);
          if ((char)piVar5[0x10] == '\x02') {
            if ((char)*param_1 == '\0') {
_L355:
              if ((((_DAT_00014032 & 2) == 0) || ((char)piVar5[0x10] == '\x02')) &&
                 (iVar3 = (**(code **)(_r_ip_funcs_p + 0x1e8))
                                    (uVar10,*(code **)(_r_ip_funcs_p + 0x1e8)), iVar13 = _p_llm_env,
                 iVar3 == 0)) {
                *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar11 + 0x40) = 3;
                *(char *)(iVar13 + 0xd6) = *(char *)(iVar13 + 0xd6) + '\x01';
                uVar14 = 0;
                while ((iVar13 = (**(code **)(_r_plf_funcs_p + 0x38))
                                           (*(code **)(_r_plf_funcs_p + 0x38)),
                       uVar14 < *(byte *)(iVar13 + 0xd) &&
                       (*(char *)(*(int *)(_p_llm_env + 8) + uVar14 * 0x44 + 0x40) != '\x02'))) {
                  uVar14 = uVar14 + 1 & 0xff;
                }
                iVar13 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
                if (((*(byte *)(iVar13 + 0xd) <= uVar14) && (_bt_rf_coex_hooks_p != (int *)0x0)) &&
                   (pcVar6 = (code *)*_bt_rf_coex_hooks_p, pcVar6 != (code *)0x0)) {
                  uVar4 = 0;
                  goto _L449;
                }
              }
            }
            else {
              (**(code **)(_r_ip_funcs_p + 0x1d4))
                        (uVar10,param_1[uVar7 + 6],*(char *)((int)param_1 + uVar7 + 0x20),
                         *(code **)(_r_ip_funcs_p + 0x1d4));
              piVar5 = (int *)(*(int *)(_p_llm_env + 8) + iVar11);
              iVar13 = *piVar5;
              if ((iVar13 != 0) && ((*(ushort *)(iVar13 + 2) & 1) != 0)) {
                bVar8 = *(byte *)((int)piVar5 + 0x3e);
                uStack_68 = CONCAT31(uStack_68._1_3_,bVar8);
                if ((bVar8 == 0xff) ||
                   (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bVar8 * 0x44 + 0x40) == '\0')) {
                  iVar13 = (**(code **)(_r_ip_funcs_p + 0x4ac))
                                     (&uStack_68,*(code **)(_r_ip_funcs_p + 0x4ac));
                  if (iVar13 == 0) {
                    iVar13 = *(int *)(_p_llm_env + 8);
                    *(undefined1 *)(iVar11 + iVar13 + 0x3e) = (undefined1)uStack_68;
                    *(undefined1 *)(iVar13 + (uStack_68 & 0xff) * 0x44 + 0x40) = 4;
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
            if ((char)*param_1 == '\0') goto _L355;
            iVar3 = *piVar5;
            uVar1 = *(ushort *)(iVar3 + 2);
            uStack_5c = (uint)*(byte *)(iVar3 + 9) << 0x10 | (uint)*(byte *)(iVar3 + 8) << 8 |
                        (uint)*(byte *)(iVar3 + 7);
            uStack_4b = *(undefined1 *)(iVar3 + 10);
            uStack_4a = *(undefined1 *)(iVar3 + 0xb);
            uStack_49 = *(undefined1 *)(iVar3 + 0xc);
            uStack_50 = uVar1;
            memcpy(auStack_62,(void *)(iVar3 + 0xd),6);
            uStack_48 = 0;
            if ((uVar1 & 4) == 0) {
              uStack_48 = *(undefined1 *)(iVar3 + 0x13);
            }
            uStack_47 = (undefined1)piVar5[0xf];
            uStack_46 = *(undefined1 *)(iVar3 + 0x15);
            uStack_45 = 0;
            if ((uVar1 & 0x10) == 0) {
              uStack_45 = *(undefined1 *)(iVar3 + 0x16);
            }
            uStack_44 = 1;
            if ((uVar1 & 0x10) == 0) {
              uStack_44 = *(undefined1 *)(iVar3 + 0x17);
            }
            uStack_43 = *(undefined1 *)(iVar3 + 0x18);
            uStack_42 = *(undefined1 *)(iVar3 + 0x19);
            uStack_68 = piVar5[1];
            uStack_64 = (undefined2)piVar5[2];
            uStack_58 = (undefined2)piVar5[10];
            uStack_54 = *(undefined2 *)((int)piVar5 + 0x2a);
            uStack_56 = *(undefined2 *)((int)piVar5 + 0x32);
            uStack_52 = (undefined2)piVar5[0xd];
            sStack_4e = param_1[uVar7 + 6];
            cStack_4c = *(char *)((int)param_1 + uVar7 + 0x20);
            uStack_41 = *(undefined1 *)(iVar13 + 0xc6);
            iVar13 = (**(code **)(_r_ip_funcs_p + 0x1e4))
                               (uVar10,&uStack_68,*(code **)(_r_ip_funcs_p + 0x1e4));
            if (iVar13 != 0) {
              (**(code **)(_r_plf_funcs_p + 0xc))
                        (uVar10,0,"llm_adv.c",0x69c,*(code **)(_r_plf_funcs_p + 0xc));
              goto _L330;
            }
            iVar13 = *(int *)(_p_llm_env + 8) + iVar11;
            *(undefined1 *)(iVar13 + 0x40) = 2;
            bVar8 = *(byte *)(iVar13 + 0x3d);
            uVar14 = (uint)bVar8;
            if (((*(ushort *)(iVar3 + 2) & 0x13) == 0) &&
               (iVar13 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
               uVar14 < *(byte *)(iVar13 + 0xd))) {
              iVar13 = uVar14 * 0x44;
              piVar5 = (int *)(*(int *)(_p_llm_env + 8) + iVar13);
              if ((char)piVar5[0x10] != '\v') goto _L366;
              iVar3 = *piVar5;
              iVar12 = *(int *)(*(int *)(_p_llm_env + 8) + iVar11);
              iStack_84 = (uint)*(ushort *)(iVar3 + 4) << 1;
              uStack_88 = (uint)*(ushort *)(iVar3 + 2) << 1;
              uStack_80 = (**(code **)(_r_ip_funcs_p + 0x554))
                                    (*(undefined2 *)((int)piVar5 + 0x2a),
                                     *(undefined1 *)(iVar12 + 0x17),
                                     *(code **)(_r_ip_funcs_p + 0x554));
              uStack_76 = 0;
              uStack_7c = uStack_80;
              uStack_78 = (ushort)bVar8;
              iVar11 = (**(code **)(_r_ip_funcs_p + 0x6f8))
                                 (&uStack_88,*(code **)(_r_ip_funcs_p + 0x6f8));
              if (iVar11 != 0) break;
              uStack_8c = *(undefined1 *)(iVar12 + 0x17);
              uStack_96 = *(undefined2 *)(iVar3 + 6);
              uStack_98 = (undefined2)(uStack_74 >> 1);
              uStack_90 = (undefined2)uStack_70;
              uStack_94 = *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar13 + 0x28);
              uStack_8e = *(undefined1 *)(iVar12 + 0xb);
              uStack_8d = *(undefined1 *)(iVar12 + 0x14);
              iVar11 = (**(code **)(_r_ip_funcs_p + 0x308))
                                 (uVar14,&uStack_98,*(code **)(_r_ip_funcs_p + 0x308));
              if (iVar11 == 0) {
                iVar13 = *(int *)(_p_llm_env + 8) + iVar13;
                *(undefined1 *)(iVar13 + 0x40) = 0xc;
                (**(code **)(_r_ip_funcs_p + 0x1f0))
                          (uVar10,uVar14,uStack_98,*(code **)(_r_ip_funcs_p + 0x1f0));
                *(undefined4 *)(iVar13 + 0x14) = uStack_70;
                *(uint *)(iVar13 + 0x10) = uStack_74;
                *(undefined4 *)(iVar13 + 0x18) = uStack_80;
                *(undefined1 *)(iVar13 + 0x22) = 0;
                *(ushort *)(iVar13 + 0x20) = (ushort)bVar8;
                *(undefined4 *)(iVar13 + 0x1c) = uStack_7c;
                iVar11 = _r_ip_funcs_p;
                *(undefined4 *)(iVar13 + 0x24) = 0;
                (**(code **)(iVar11 + 0x6fc))(iVar13 + 0xc,*(code **)(iVar11 + 0x6fc));
                if ((_bt_rf_coex_hooks_p != (int *)0x0) &&
                   ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
                  (*(code *)*_bt_rf_coex_hooks_p)(uVar14,4,1);
                }
              }
            }
            else {
_L366:
              if ((*(ushort *)(iVar3 + 2) & 1) != 0) {
                iVar13 = (**(code **)(_r_ip_funcs_p + 0x4ac))
                                   (&uStack_88,*(code **)(_r_ip_funcs_p + 0x4ac));
                if (iVar13 == 0) {
                  iVar13 = *(int *)(_p_llm_env + 8);
                  *(undefined1 *)(iVar11 + iVar13 + 0x3e) = (undefined1)uStack_88;
                  *(undefined1 *)(iVar13 + (uStack_88 & 0xff) * 0x44 + 0x40) = 4;
                }
                else {
                  (**(code **)(_r_plf_funcs_p + 8))
                            (0,"llm_adv.c",0x690,*(code **)(_r_plf_funcs_p + 8));
                }
              }
            }
            if (_bt_rf_coex_hooks_p != (int *)0x0) {
              pcVar6 = (code *)*_bt_rf_coex_hooks_p;
              uVar4 = 1;
              if (pcVar6 != (code *)0x0) {
_L449:
                (*pcVar6)(uVar10,2,uVar4);
              }
            }
          }
        }
      }
      if ((char)*param_1 == '\0') {
        if (*(char *)(_p_llm_env + 0xd6) != '\0') {
          return 0;
        }
        iVar13 = 0;
      }
      else {
        iVar13 = 0;
      }
      goto _L330;
    }
  }
  else {
    psVar2 = param_1;
    if ((char)*param_1 == '\x01') goto _L333;
  }
_L334:
  iVar13 = 0x12;
_L330:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar13,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

