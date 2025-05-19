/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> llm_adv.o -> hci_le_set_ext_adv_en_cmd_handler
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
  byte bVar9;
  uint uVar10;
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
  
  iVar4 = r_sdk_config_get_opts_ext();
  if ((*(char *)(iVar4 + 0x18) == '\0') ||
     (iVar5 = r_sdk_config_get_opts_ext(), iVar4 = _p_llm_env, *(char *)(iVar5 + 0x2d) == '\0')) {
    r_llm_cmd_cmp_send(param_2,0xc);
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L600:
    iVar4 = 0xc;
    goto _L592;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  if ((char)*param_1 == '\0') {
    psVar2 = (short *)0x2;
    if (*(char *)(iVar4 + 0xd6) != '\0') {
      return 2;
    }
_L595:
    if (*param_1 != 1) {
      if (*(char *)((int)param_1 + 1) == '\0') {
        for (uVar10 = 0; psVar2 = (short *)r_sdk_config_get_opts(psVar2),
            uVar10 < *(byte *)((int)psVar2 + 0xd); uVar10 = uVar10 + 1 & 0xff) {
          if ((*(char *)(*(int *)(_p_llm_env + 8) + uVar10 * 0x44 + 0x40) == '\x02') &&
             (psVar2 = (short *)r_lld_adv_stop(uVar10), iVar4 = _p_llm_env, psVar2 == (short *)0x0))
          {
            *(undefined1 *)(*(int *)(_p_llm_env + 8) + uVar10 * 0x44 + 0x40) = 3;
            *(char *)(iVar4 + 0xd6) = *(char *)(iVar4 + 0xd6) + '\x01';
            if ((_bt_rf_coex_hooks_p != (int *)0x0) && ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)
               ) {
              psVar2 = (short *)(*(code *)*_bt_rf_coex_hooks_p)(uVar10,2,0);
            }
          }
        }
      }
      else {
        uVar10 = 0;
        bVar9 = 0;
        do {
          if (0xef < *(byte *)((int)param_1 + uVar10 + 2)) goto _L596;
          iVar4 = r_llm_adv_hdl_to_id(0);
          if (iVar4 == 0xff) {
            iVar4 = 0x42;
            goto _L592;
          }
          piVar7 = (int *)(*(int *)(_p_llm_env + 8) + iVar4 * 0x44);
          if (((short)piVar7[0xb] != 0) || (*(short *)((int)piVar7 + 0x36) != 0)) goto _L596;
          if ((char)*param_1 == '\x01') {
            iVar5 = *piVar7;
            uVar1 = *(ushort *)(iVar5 + 2);
            if (((uVar1 & 2) != 0) && ((uVar1 & 0x10) == 0 && (short)piVar7[0xd] == 0)) goto _L600;
            if (((uVar1 & 0x11) == 1) &&
               (iVar3 = r_llm_adv_con_len_check(iVar5,*(undefined2 *)((int)piVar7 + 0x2a)),
               iVar3 != 0)) goto _L596;
            if ((*(ushort *)(iVar5 + 2) & 1) != 0) {
              if (((*(ushort *)(iVar5 + 2) & 0xc) != 0) &&
                 (iVar3 = r_llm_is_dev_connected(iVar5 + 0xd,*(undefined1 *)(iVar5 + 0xc)),
                 iVar3 != 0)) {
                iVar4 = 0xb;
                goto _L592;
              }
              if (((*(ushort *)(iVar5 + 2) & 8) != 0) && (0x7f < (ushort)(param_1[uVar10 + 6] - 1U))
                 ) goto _L596;
              bVar9 = bVar9 + 1;
            }
            if (((*(byte *)(iVar5 + 0xb) & 1) != 0) &&
               (iVar5 = r_co_bdaddr_compare(*(int *)(_p_llm_env + 8) + iVar4 * 0x44 + 4,
                                            &co_null_bdaddr), iVar5 != 0)) goto _L596;
          }
          else if (((_DAT_0001405e & 2) == 0) && ((char)piVar7[0x10] != '\x02')) goto _L600;
          *(char *)((int)param_1 + uVar10 + 2) = (char)iVar4;
          uVar10 = uVar10 + 1 & 0xff;
        } while (uVar10 < *(byte *)((int)param_1 + 1));
        if (bVar9 != 0) {
          bVar11 = 0;
          for (uVar10 = 0; iVar4 = r_sdk_config_get_opts(), uVar10 < *(byte *)(iVar4 + 0xd);
              uVar10 = uVar10 + 1 & 0xff) {
            bVar11 = bVar11 + (*(char *)(*(int *)(_p_llm_env + 8) + uVar10 * 0x44 + 0x40) == '\0');
            if (bVar9 <= bVar11) goto _L615;
          }
          iVar4 = 7;
          if (bVar11 < bVar9) goto _L592;
        }
_L615:
        for (uVar10 = 0; iVar4 = _p_llm_env, uVar10 < *(byte *)((int)param_1 + 1);
            uVar10 = uVar10 + 1 & 0xff) {
          uVar12 = (uint)*(byte *)((int)param_1 + uVar10 + 2);
          iVar5 = uVar12 * 0x44;
          piVar7 = (int *)(*(int *)(_p_llm_env + 8) + iVar5);
          if ((char)piVar7[0x10] == '\x02') {
            if ((char)*param_1 == '\0') {
_L617:
              if ((((_DAT_0001405e & 2) == 0) || ((char)piVar7[0x10] == '\x02')) &&
                 (iVar3 = r_lld_adv_stop(uVar12), iVar4 = _p_llm_env, iVar3 == 0)) {
                *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar5 + 0x40) = 3;
                *(char *)(iVar4 + 0xd6) = *(char *)(iVar4 + 0xd6) + '\x01';
                uVar14 = 0;
                while ((iVar4 = r_sdk_config_get_opts(), uVar14 < *(byte *)(iVar4 + 0xd) &&
                       (*(char *)(*(int *)(_p_llm_env + 8) + uVar14 * 0x44 + 0x40) != '\x02'))) {
                  uVar14 = uVar14 + 1 & 0xff;
                }
                iVar4 = r_sdk_config_get_opts();
                if (((*(byte *)(iVar4 + 0xd) <= uVar14) && (_bt_rf_coex_hooks_p != (int *)0x0)) &&
                   (pcVar8 = (code *)*_bt_rf_coex_hooks_p, pcVar8 != (code *)0x0)) {
                  uVar6 = 0;
                  goto _L711;
                }
              }
            }
            else {
              r_lld_adv_restart(uVar12,param_1[uVar10 + 6],*(char *)((int)param_1 + uVar10 + 0x20));
              piVar7 = (int *)(*(int *)(_p_llm_env + 8) + iVar5);
              iVar4 = *piVar7;
              if ((iVar4 != 0) && ((*(ushort *)(iVar4 + 2) & 1) != 0)) {
                bVar9 = *(byte *)((int)piVar7 + 0x3e);
                uStack_68 = CONCAT31(uStack_68._1_3_,bVar9);
                if ((bVar9 == 0xff) ||
                   (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bVar9 * 0x44 + 0x40) == '\0')) {
                  iVar4 = r_llm_activity_free_get(&uStack_68);
                  if (iVar4 == 0) {
                    iVar4 = *(int *)(_p_llm_env + 8);
                    *(undefined1 *)(iVar5 + iVar4 + 0x3e) = (undefined1)uStack_68;
                    *(undefined1 *)(iVar4 + (uStack_68 & 0xff) * 0x44 + 0x40) = 4;
                  }
                  else {
                    r_assert_param(0,"llm_adv.c",0x61f);
                  }
                }
              }
            }
          }
          else {
            if ((char)*param_1 == '\0') goto _L617;
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
            sStack_4e = param_1[uVar10 + 6];
            cStack_4c = *(char *)((int)param_1 + uVar10 + 0x20);
            uStack_41 = *(undefined1 *)(iVar4 + 0xc6);
            iVar4 = r_lld_adv_start_eco(uVar12,&uStack_68);
            if (iVar4 != 0) {
              r_assert_param(uVar12,0,"llm_adv.c",0x6a8);
              goto _L592;
            }
            iVar4 = *(int *)(_p_llm_env + 8) + iVar5;
            *(undefined1 *)(iVar4 + 0x40) = 2;
            bVar9 = *(byte *)(iVar4 + 0x3d);
            uVar14 = (uint)bVar9;
            if (((*(ushort *)(iVar3 + 2) & 0x13) == 0) &&
               (iVar4 = r_sdk_config_get_opts(), uVar14 < *(byte *)(iVar4 + 0xd))) {
              iVar4 = uVar14 * 0x44;
              piVar7 = (int *)(*(int *)(_p_llm_env + 8) + iVar4);
              if ((char)piVar7[0x10] != '\v') goto _L628;
              iVar3 = *piVar7;
              iVar13 = *(int *)(*(int *)(_p_llm_env + 8) + iVar5);
              iStack_84 = (uint)*(ushort *)(iVar3 + 4) << 1;
              uStack_88 = (uint)*(ushort *)(iVar3 + 2) << 1;
              uStack_80 = r_llm_per_adv_slot_dur
                                    (*(undefined2 *)((int)piVar7 + 0x2a),
                                     *(undefined1 *)(iVar13 + 0x17));
              uStack_76 = 0;
              uStack_7c = uStack_80;
              uStack_78 = (ushort)bVar9;
              iVar5 = r_sch_plan_req(&uStack_88);
              if (iVar5 != 0) break;
              uStack_8c = *(undefined1 *)(iVar13 + 0x17);
              uStack_96 = *(undefined2 *)(iVar3 + 6);
              uStack_98 = (undefined2)(uStack_74 >> 1);
              uStack_90 = (undefined2)uStack_70;
              uStack_94 = *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x28);
              uStack_8e = *(undefined1 *)(iVar13 + 0xb);
              uStack_8d = *(undefined1 *)(iVar13 + 0x14);
              iVar5 = r_lld_per_adv_start(uVar14,&uStack_98);
              if (iVar5 == 0) {
                iVar4 = *(int *)(_p_llm_env + 8) + iVar4;
                *(undefined1 *)(iVar4 + 0x40) = 0xc;
                r_lld_adv_sync_info_update(uVar12,uVar14,uStack_98);
                *(undefined4 *)(iVar4 + 0x14) = uStack_70;
                *(uint *)(iVar4 + 0x10) = uStack_74;
                *(undefined4 *)(iVar4 + 0x18) = uStack_80;
                *(ushort *)(iVar4 + 0x20) = (ushort)bVar9;
                *(undefined4 *)(iVar4 + 0x24) = 0;
                *(undefined4 *)(iVar4 + 0x1c) = uStack_7c;
                *(undefined1 *)(iVar4 + 0x22) = 0;
                r_sch_plan_set_hack(iVar4 + 0xc);
                if ((_bt_rf_coex_hooks_p != (int *)0x0) &&
                   ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
                  (*(code *)*_bt_rf_coex_hooks_p)(uVar14,4,1);
                }
              }
            }
            else {
_L628:
              if ((*(ushort *)(iVar3 + 2) & 1) != 0) {
                iVar4 = r_llm_activity_free_get(&uStack_88);
                if (iVar4 == 0) {
                  iVar4 = *(int *)(_p_llm_env + 8);
                  *(undefined1 *)(iVar5 + iVar4 + 0x3e) = (undefined1)uStack_88;
                  *(undefined1 *)(iVar4 + (uStack_88 & 0xff) * 0x44 + 0x40) = 4;
                }
                else {
                  r_assert_err(0,"llm_adv.c",0x69c);
                }
              }
            }
            if (_bt_rf_coex_hooks_p != (int *)0x0) {
              pcVar8 = (code *)*_bt_rf_coex_hooks_p;
              uVar6 = 1;
              if (pcVar8 != (code *)0x0) {
_L711:
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
      goto _L592;
    }
  }
  else {
    psVar2 = param_1;
    if ((char)*param_1 == '\x01') goto _L595;
  }
_L596:
  iVar4 = 0x12;
_L592:
  r_llm_cmd_cmp_send(param_2,iVar4);
  return 0;
}

