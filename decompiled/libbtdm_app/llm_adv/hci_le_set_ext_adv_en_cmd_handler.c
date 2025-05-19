/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app -> llm_adv.o -> hci_le_set_ext_adv_en_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_ext_adv_en_cmd_handler(short *param_1,undefined4 param_2)

{
  ushort uVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  code *pcVar8;
  uint uVar9;
  byte bVar10;
  byte bVar11;
  uint uVar12;
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
  
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if ((*(char *)(iVar4 + 0x18) == '\0') ||
     (iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0)),
     iVar4 = _p_llm_env, *(char *)(iVar5 + 0x2d) == '\0')) {
    (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,0xc,*(code **)(_r_ip_funcs_p + 0x4b8));
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L362:
    iVar4 = 0xc;
    goto _L354;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  if ((char)*param_1 == '\0') {
    psVar2 = (short *)0x2;
    if (*(char *)(iVar4 + 0xd6) != '\0') {
      return 2;
    }
_L357:
    if (*param_1 != 1) {
      if (*(char *)((int)param_1 + 1) == '\0') {
        for (uVar9 = 0;
            psVar2 = (short *)(**(code **)(_r_plf_funcs_p + 0x38))
                                        (psVar2,*(code **)(_r_plf_funcs_p + 0x38)),
            uVar9 < *(byte *)((int)psVar2 + 0xd); uVar9 = uVar9 + 1 & 0xff) {
          if ((*(char *)(*(int *)(_p_llm_env + 8) + uVar9 * 0x44 + 0x40) == '\x02') &&
             (psVar2 = (short *)(**(code **)(_r_ip_funcs_p + 0x1e8))
                                          (uVar9,*(code **)(_r_ip_funcs_p + 0x1e8)),
             iVar4 = _p_llm_env, psVar2 == (short *)0x0)) {
            *(undefined1 *)(*(int *)(_p_llm_env + 8) + uVar9 * 0x44 + 0x40) = 3;
            *(char *)(iVar4 + 0xd6) = *(char *)(iVar4 + 0xd6) + '\x01';
            if ((_bt_rf_coex_hooks_p != (int *)0x0) && ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)
               ) {
              psVar2 = (short *)(*(code *)*_bt_rf_coex_hooks_p)(uVar9,2,0);
            }
          }
        }
      }
      else {
        uVar9 = 0;
        bVar10 = 0;
        do {
          if (0xef < *(byte *)((int)param_1 + uVar9 + 2)) goto _L358;
          iVar4 = (**(code **)(_r_ip_funcs_p + 0x544))(0,*(code **)(_r_ip_funcs_p + 0x544));
          if (iVar4 == 0xff) {
            iVar4 = 0x42;
            goto _L354;
          }
          piVar7 = (int *)(*(int *)(_p_llm_env + 8) + iVar4 * 0x44);
          if (((short)piVar7[0xb] != 0) || (*(short *)((int)piVar7 + 0x36) != 0)) goto _L358;
          if ((char)*param_1 == '\x01') {
            iVar5 = *piVar7;
            uVar1 = *(ushort *)(iVar5 + 2);
            if (((uVar1 & 2) != 0) && ((uVar1 & 0x10) == 0 && (short)piVar7[0xd] == 0)) goto _L362;
            if (((uVar1 & 0x11) == 1) &&
               (iVar3 = (**(code **)(_r_ip_funcs_p + 0x540))
                                  (iVar5,*(undefined2 *)((int)piVar7 + 0x2a),
                                   *(code **)(_r_ip_funcs_p + 0x540)), iVar3 != 0)) goto _L358;
            if ((*(ushort *)(iVar5 + 2) & 1) != 0) {
              if (((*(ushort *)(iVar5 + 2) & 0xc) != 0) &&
                 (iVar3 = (**(code **)(_r_ip_funcs_p + 0x4d8))
                                    (iVar5 + 0xd,*(undefined1 *)(iVar5 + 0xc),
                                     *(code **)(_r_ip_funcs_p + 0x4d8)), iVar3 != 0)) {
                iVar4 = 0xb;
                goto _L354;
              }
              if (((*(ushort *)(iVar5 + 2) & 8) != 0) && (0x7f < (ushort)(param_1[uVar9 + 6] - 1U)))
              goto _L358;
              bVar10 = bVar10 + 1;
            }
            if (((*(byte *)(iVar5 + 0xb) & 1) != 0) &&
               (iVar5 = (*(code *)*_r_modules_funcs_p)
                                  (*(int *)(_p_llm_env + 8) + iVar4 * 0x44 + 4,&co_null_bdaddr,
                                   (code *)*_r_modules_funcs_p), iVar5 != 0)) goto _L358;
          }
          else if (((_DAT_00014032 & 2) == 0) && ((char)piVar7[0x10] != '\x02')) goto _L362;
          *(char *)((int)param_1 + uVar9 + 2) = (char)iVar4;
          uVar9 = uVar9 + 1 & 0xff;
        } while (uVar9 < *(byte *)((int)param_1 + 1));
        if (bVar10 != 0) {
          bVar11 = 0;
          for (uVar9 = 0;
              iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
              uVar9 < *(byte *)(iVar4 + 0xd); uVar9 = uVar9 + 1 & 0xff) {
            bVar11 = bVar11 + (*(char *)(*(int *)(_p_llm_env + 8) + uVar9 * 0x44 + 0x40) == '\0');
            if (bVar10 <= bVar11) goto _L377;
          }
          iVar4 = 7;
          if (bVar11 < bVar10) goto _L354;
        }
_L377:
        for (uVar9 = 0; iVar4 = _p_llm_env, uVar9 < *(byte *)((int)param_1 + 1);
            uVar9 = uVar9 + 1 & 0xff) {
          uVar12 = (uint)*(byte *)((int)param_1 + uVar9 + 2);
          iVar5 = uVar12 * 0x44;
          piVar7 = (int *)(*(int *)(_p_llm_env + 8) + iVar5);
          if ((char)piVar7[0x10] == '\x02') {
            if ((char)*param_1 == '\0') {
_L379:
              if ((((_DAT_00014032 & 2) == 0) || ((char)piVar7[0x10] == '\x02')) &&
                 (iVar3 = (**(code **)(_r_ip_funcs_p + 0x1e8))
                                    (uVar12,*(code **)(_r_ip_funcs_p + 0x1e8)), iVar4 = _p_llm_env,
                 iVar3 == 0)) {
                *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar5 + 0x40) = 3;
                *(char *)(iVar4 + 0xd6) = *(char *)(iVar4 + 0xd6) + '\x01';
                uVar14 = 0;
                while ((iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))
                                          (*(code **)(_r_plf_funcs_p + 0x38)),
                       uVar14 < *(byte *)(iVar4 + 0xd) &&
                       (*(char *)(*(int *)(_p_llm_env + 8) + uVar14 * 0x44 + 0x40) != '\x02'))) {
                  uVar14 = uVar14 + 1 & 0xff;
                }
                iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
                if (((*(byte *)(iVar4 + 0xd) <= uVar14) && (_bt_rf_coex_hooks_p != (int *)0x0)) &&
                   (pcVar8 = (code *)*_bt_rf_coex_hooks_p, pcVar8 != (code *)0x0)) {
                  uVar6 = 0;
                  goto _L473;
                }
              }
            }
            else {
              (**(code **)(_r_ip_funcs_p + 0x1d4))
                        (uVar12,param_1[uVar9 + 6],*(char *)((int)param_1 + uVar9 + 0x20),
                         *(code **)(_r_ip_funcs_p + 0x1d4));
              piVar7 = (int *)(*(int *)(_p_llm_env + 8) + iVar5);
              iVar4 = *piVar7;
              if ((iVar4 != 0) && ((*(ushort *)(iVar4 + 2) & 1) != 0)) {
                bVar10 = *(byte *)((int)piVar7 + 0x3e);
                uStack_68 = CONCAT31(uStack_68._1_3_,bVar10);
                if ((bVar10 == 0xff) ||
                   (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bVar10 * 0x44 + 0x40) == '\0')) {
                  iVar4 = (**(code **)(_r_ip_funcs_p + 0x4ac))
                                    (&uStack_68,*(code **)(_r_ip_funcs_p + 0x4ac));
                  if (iVar4 == 0) {
                    iVar4 = *(int *)(_p_llm_env + 8);
                    *(undefined1 *)(iVar5 + iVar4 + 0x3e) = (undefined1)uStack_68;
                    *(undefined1 *)(iVar4 + (uStack_68 & 0xff) * 0x44 + 0x40) = 4;
                  }
                  else {
                    (**(code **)(_r_plf_funcs_p + 0xc))
                              (0,"llm_adv.c",0x61f,*(code **)(_r_plf_funcs_p + 0xc));
                  }
                }
              }
            }
          }
          else {
            if ((char)*param_1 == '\0') goto _L379;
            iVar3 = *piVar7;
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
            uStack_47 = (undefined1)piVar7[0xf];
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
            uStack_68 = piVar7[1];
            uStack_64 = (undefined2)piVar7[2];
            uStack_58 = (undefined2)piVar7[10];
            uStack_54 = *(undefined2 *)((int)piVar7 + 0x2a);
            uStack_56 = *(undefined2 *)((int)piVar7 + 0x32);
            uStack_52 = (undefined2)piVar7[0xd];
            sStack_4e = param_1[uVar9 + 6];
            cStack_4c = *(char *)((int)param_1 + uVar9 + 0x20);
            uStack_41 = *(undefined1 *)(iVar4 + 0xc6);
            iVar4 = (**(code **)(_r_ip_funcs_p + 0x1e4))
                              (uVar12,&uStack_68,*(code **)(_r_ip_funcs_p + 0x1e4));
            if (iVar4 != 0) {
              (**(code **)(_r_plf_funcs_p + 0xc))
                        (uVar12,0,"llm_adv.c",0x6a8,*(code **)(_r_plf_funcs_p + 0xc));
              goto _L354;
            }
            iVar4 = *(int *)(_p_llm_env + 8) + iVar5;
            *(undefined1 *)(iVar4 + 0x40) = 2;
            bVar10 = *(byte *)(iVar4 + 0x3d);
            uVar14 = (uint)bVar10;
            if (((*(ushort *)(iVar3 + 2) & 0x13) == 0) &&
               (iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
               uVar14 < *(byte *)(iVar4 + 0xd))) {
              iVar4 = uVar14 * 0x44;
              piVar7 = (int *)(*(int *)(_p_llm_env + 8) + iVar4);
              if ((char)piVar7[0x10] != '\v') goto _L390;
              iVar3 = *piVar7;
              iVar13 = *(int *)(*(int *)(_p_llm_env + 8) + iVar5);
              iStack_84 = (uint)*(ushort *)(iVar3 + 4) << 1;
              uStack_88 = (uint)*(ushort *)(iVar3 + 2) << 1;
              uStack_80 = (**(code **)(_r_ip_funcs_p + 0x554))
                                    (*(undefined2 *)((int)piVar7 + 0x2a),
                                     *(undefined1 *)(iVar13 + 0x17),
                                     *(code **)(_r_ip_funcs_p + 0x554));
              uStack_76 = 0;
              uStack_7c = uStack_80;
              uStack_78 = (ushort)bVar10;
              iVar5 = (**(code **)(_r_ip_funcs_p + 0x6f8))
                                (&uStack_88,*(code **)(_r_ip_funcs_p + 0x6f8));
              if (iVar5 != 0) break;
              uStack_8c = *(undefined1 *)(iVar13 + 0x17);
              uStack_96 = *(undefined2 *)(iVar3 + 6);
              uStack_98 = (undefined2)(uStack_74 >> 1);
              uStack_90 = (undefined2)uStack_70;
              uStack_94 = *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x28);
              uStack_8e = *(undefined1 *)(iVar13 + 0xb);
              uStack_8d = *(undefined1 *)(iVar13 + 0x14);
              iVar5 = (**(code **)(_r_ip_funcs_p + 0x308))
                                (uVar14,&uStack_98,*(code **)(_r_ip_funcs_p + 0x308));
              if (iVar5 == 0) {
                iVar4 = *(int *)(_p_llm_env + 8) + iVar4;
                *(undefined1 *)(iVar4 + 0x40) = 0xc;
                (**(code **)(_r_ip_funcs_p + 0x1f0))
                          (uVar12,uVar14,uStack_98,*(code **)(_r_ip_funcs_p + 0x1f0));
                *(undefined4 *)(iVar4 + 0x14) = uStack_70;
                *(uint *)(iVar4 + 0x10) = uStack_74;
                *(undefined4 *)(iVar4 + 0x18) = uStack_80;
                *(undefined1 *)(iVar4 + 0x22) = 0;
                *(ushort *)(iVar4 + 0x20) = (ushort)bVar10;
                *(undefined4 *)(iVar4 + 0x1c) = uStack_7c;
                iVar5 = _r_ip_funcs_p;
                *(undefined4 *)(iVar4 + 0x24) = 0;
                (**(code **)(iVar5 + 0x6fc))(iVar4 + 0xc,*(code **)(iVar5 + 0x6fc));
                if ((_bt_rf_coex_hooks_p != (int *)0x0) &&
                   ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
                  (*(code *)*_bt_rf_coex_hooks_p)(uVar14,4,1);
                }
              }
            }
            else {
_L390:
              if ((*(ushort *)(iVar3 + 2) & 1) != 0) {
                iVar4 = (**(code **)(_r_ip_funcs_p + 0x4ac))
                                  (&uStack_88,*(code **)(_r_ip_funcs_p + 0x4ac));
                if (iVar4 == 0) {
                  iVar4 = *(int *)(_p_llm_env + 8);
                  *(undefined1 *)(iVar5 + iVar4 + 0x3e) = (undefined1)uStack_88;
                  *(undefined1 *)(iVar4 + (uStack_88 & 0xff) * 0x44 + 0x40) = 4;
                }
                else {
                  (**(code **)(_r_plf_funcs_p + 8))
                            (0,"llm_adv.c",0x69c,*(code **)(_r_plf_funcs_p + 8));
                }
              }
            }
            if (_bt_rf_coex_hooks_p != (int *)0x0) {
              pcVar8 = (code *)*_bt_rf_coex_hooks_p;
              uVar6 = 1;
              if (pcVar8 != (code *)0x0) {
_L473:
                (*pcVar8)(uVar12,2,uVar6);
              }
            }
          }
        }
      }
      if ((char)*param_1 == '\0') {
        if (*(char *)(_p_llm_env + 0xd6) != '\0') {
          return 0;
        }
        iVar4 = 0;
      }
      else {
        iVar4 = 0;
      }
      goto _L354;
    }
  }
  else {
    psVar2 = param_1;
    if ((char)*param_1 == '\x01') goto _L357;
  }
_L358:
  iVar4 = 0x12;
_L354:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar4,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

