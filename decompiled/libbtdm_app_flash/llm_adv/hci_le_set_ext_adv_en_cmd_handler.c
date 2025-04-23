/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  code *pcVar6;
  byte bVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  byte bVar11;
  uint uVar12;
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
  
  iVar4 = r_sdk_config_get_opts_ext();
  iVar2 = _p_llm_env;
  if (*(char *)(iVar4 + 0x18) == '\0') {
    r_llm_cmd_cmp_send(param_2,0xc);
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L622:
    uVar8 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    if ((char)*param_1 == '\0') {
      if (*(char *)(iVar2 + 0xd6) != '\0') {
        return 2;
      }
    }
    else {
      uVar8 = 0x12;
      if ((char)*param_1 != '\x01') goto _L556;
    }
    if (*param_1 == 1) {
_L562:
      uVar8 = 0x12;
    }
    else {
      if (*(char *)((int)param_1 + 1) == '\0') {
        for (uVar8 = 0; iVar2 = r_sdk_config_get_opts(), uVar8 < *(byte *)(iVar2 + 0xd);
            uVar8 = uVar8 + 1 & 0xff) {
          if ((*(char *)(*(int *)(_p_llm_env + 8) + uVar8 * 0x44 + 0x40) == '\x02') &&
             (iVar4 = r_lld_adv_stop(uVar8), iVar2 = _p_llm_env, iVar4 == 0)) {
            *(undefined1 *)(*(int *)(_p_llm_env + 8) + uVar8 * 0x44 + 0x40) = 3;
            *(char *)(iVar2 + 0xd6) = *(char *)(iVar2 + 0xd6) + '\x01';
            if ((_bt_rf_coex_hooks_p != (int *)0x0) && ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)
               ) {
              (*(code *)*_bt_rf_coex_hooks_p)(uVar8,2,0);
            }
          }
        }
      }
      else {
        bVar7 = 0;
        for (uVar8 = 0; uVar8 < *(byte *)((int)param_1 + 1); uVar8 = uVar8 + 1 & 0xff) {
          if (0xef < *(byte *)((int)param_1 + uVar8 + 2)) goto _L562;
          iVar2 = r_llm_adv_hdl_to_id(0);
          if (iVar2 == 0xff) {
            uVar8 = 0x42;
            goto _L556;
          }
          piVar10 = (int *)(*(int *)(_p_llm_env + 8) + iVar2 * 0x44);
          if (((short)piVar10[0xb] != 0) || (*(short *)((int)piVar10 + 0x36) != 0)) goto _L562;
          if ((char)*param_1 == '\x01') {
            iVar4 = *piVar10;
            uVar1 = *(ushort *)(iVar4 + 2);
            if (((uVar1 & 2) == 0) || ((short)piVar10[0xd] != 0)) {
              if (((uVar1 & 0x11) == 1) &&
                 (iVar3 = r_llm_adv_con_len_check(iVar4,*(undefined2 *)((int)piVar10 + 0x2a)),
                 iVar3 != 0)) goto _L562;
            }
            else if ((uVar1 & 0x10) == 0) goto _L622;
            if ((*(ushort *)(iVar4 + 2) & 1) != 0) {
              if (((*(ushort *)(iVar4 + 2) & 0xc) != 0) &&
                 (iVar3 = r_llm_is_dev_connected(iVar4 + 0xd,*(undefined1 *)(iVar4 + 0xc)),
                 iVar3 != 0)) {
                uVar8 = 0xb;
                goto _L556;
              }
              if (((*(ushort *)(iVar4 + 2) & 8) != 0) && (0x7f < (ushort)(param_1[uVar8 + 6] - 1U)))
              goto _L562;
              bVar7 = bVar7 + 1;
            }
            if (((*(byte *)(iVar4 + 0xb) & 1) != 0) &&
               (iVar4 = r_co_bdaddr_compare(*(int *)(_p_llm_env + 8) + iVar2 * 0x44 + 4,
                                            &co_null_bdaddr), iVar4 != 0)) goto _L562;
          }
          else if (((_DAT_0001405e & 2) == 0) && ((char)piVar10[0x10] != '\x02')) goto _L622;
          *(char *)((int)param_1 + uVar8 + 2) = (char)iVar2;
        }
        if (bVar7 != 0) {
          bVar11 = 0;
          for (uVar8 = 0; iVar2 = r_sdk_config_get_opts(), uVar8 < *(byte *)(iVar2 + 0xd);
              uVar8 = uVar8 + 1 & 0xff) {
            bVar11 = bVar11 + (*(char *)(*(int *)(_p_llm_env + 8) + uVar8 * 0x44 + 0x40) == '\0');
            if (bVar7 <= bVar11) goto _L579;
          }
          uVar8 = 7;
          if (bVar11 < bVar7) goto _L556;
        }
_L579:
        for (uVar12 = 0; iVar2 = _p_llm_env, uVar12 < *(byte *)((int)param_1 + 1);
            uVar12 = uVar12 + 1 & 0xff) {
          uVar13 = (uint)*(byte *)((int)param_1 + uVar12 + 2);
          iVar4 = uVar13 * 0x44;
          piVar10 = (int *)(*(int *)(_p_llm_env + 8) + iVar4);
          if ((char)piVar10[0x10] == '\x02') {
            if ((char)*param_1 == '\0') {
_L582:
              if ((((_DAT_0001405e & 2) == 0) || ((char)piVar10[0x10] == '\x02')) &&
                 (iVar3 = r_lld_adv_stop(uVar13), iVar2 = _p_llm_env, iVar3 == 0)) {
                *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x40) = 3;
                *(char *)(iVar2 + 0xd6) = *(char *)(iVar2 + 0xd6) + '\x01';
                uVar8 = 0;
                while ((iVar2 = r_sdk_config_get_opts(), uVar8 < *(byte *)(iVar2 + 0xd) &&
                       (*(char *)(*(int *)(_p_llm_env + 8) + uVar8 * 0x44 + 0x40) != '\x02'))) {
                  uVar8 = uVar8 + 1 & 0xff;
                }
                iVar2 = r_sdk_config_get_opts();
                if (((*(byte *)(iVar2 + 0xd) <= uVar8) && (_bt_rf_coex_hooks_p != (int *)0x0)) &&
                   (pcVar6 = (code *)*_bt_rf_coex_hooks_p, pcVar6 != (code *)0x0)) {
                  uVar5 = 0;
                  goto _L674;
                }
              }
            }
            else {
              r_lld_adv_restart(uVar13,param_1[uVar12 + 6],*(char *)((int)param_1 + uVar12 + 0x20));
              piVar10 = (int *)(*(int *)(_p_llm_env + 8) + iVar4);
              iVar2 = *piVar10;
              if ((iVar2 != 0) && ((*(ushort *)(iVar2 + 2) & 1) != 0)) {
                bVar7 = *(byte *)((int)piVar10 + 0x3e);
                uStack_68 = CONCAT31(uStack_68._1_3_,bVar7);
                if ((bVar7 == 0xff) ||
                   (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bVar7 * 0x44 + 0x40) == '\0')) {
                  iVar2 = r_llm_activity_free_get(&uStack_68);
                  if (iVar2 == 0) {
                    iVar2 = *(int *)(_p_llm_env + 8);
                    *(undefined1 *)(iVar4 + iVar2 + 0x3e) = (undefined1)uStack_68;
                    *(undefined1 *)(iVar2 + (uStack_68 & 0xff) * 0x44 + 0x40) = 4;
                  }
                  else {
                    r_assert_param(0,"llm_adv.c",0x613);
                  }
                }
              }
            }
          }
          else {
            if ((char)*param_1 == '\0') goto _L582;
            iVar3 = *piVar10;
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
            uStack_47 = (undefined1)piVar10[0xf];
            uStack_46 = *(undefined1 *)(iVar3 + 0x15);
            if ((uVar1 & 0x10) == 0) {
              uStack_45 = *(undefined1 *)(iVar3 + 0x16);
              uStack_44 = *(undefined1 *)(iVar3 + 0x17);
            }
            else {
              uStack_45 = 0;
              uStack_44 = 1;
            }
            uStack_43 = *(undefined1 *)(iVar3 + 0x18);
            uStack_42 = *(undefined1 *)(iVar3 + 0x19);
            uStack_68 = piVar10[1];
            uStack_64 = (undefined2)piVar10[2];
            uStack_58 = (undefined2)piVar10[10];
            uStack_54 = *(undefined2 *)((int)piVar10 + 0x2a);
            uStack_56 = *(undefined2 *)((int)piVar10 + 0x32);
            uStack_52 = (undefined2)piVar10[0xd];
            sStack_4e = param_1[uVar12 + 6];
            cStack_4c = *(char *)((int)param_1 + uVar12 + 0x20);
            uStack_41 = *(undefined1 *)(iVar2 + 0xc6);
            uVar8 = r_lld_adv_start_eco(uVar13,&uStack_68);
            if (uVar8 != 0) {
              r_assert_param(uVar13,0,"llm_adv.c",0x69c);
              goto _L556;
            }
            iVar2 = *(int *)(_p_llm_env + 8) + iVar4;
            *(undefined1 *)(iVar2 + 0x40) = 2;
            if ((*(ushort *)(iVar3 + 2) & 0x13) == 0) {
              bVar7 = *(byte *)(iVar2 + 0x3d);
              uVar8 = (uint)bVar7;
              iVar2 = r_sdk_config_get_opts();
              if (*(byte *)(iVar2 + 0xd) <= uVar8) goto _L593;
              iVar2 = uVar8 * 0x44;
              piVar10 = (int *)(*(int *)(_p_llm_env + 8) + iVar2);
              if ((char)piVar10[0x10] != '\v') goto _L593;
              iVar3 = *piVar10;
              iVar9 = *(int *)(*(int *)(_p_llm_env + 8) + iVar4);
              iStack_84 = (uint)*(ushort *)(iVar3 + 4) << 1;
              uStack_88 = (uint)*(ushort *)(iVar3 + 2) << 1;
              uStack_80 = r_llm_per_adv_slot_dur
                                    (*(undefined2 *)((int)piVar10 + 0x2a),
                                     *(undefined1 *)(iVar9 + 0x17));
              uStack_76 = 0;
              uStack_7c = uStack_80;
              uStack_78 = (ushort)bVar7;
              iVar4 = r_sch_plan_req(&uStack_88);
              if (iVar4 != 0) break;
              uStack_96 = *(undefined2 *)(iVar3 + 6);
              uStack_98 = (undefined2)(uStack_74 >> 1);
              uStack_90 = (undefined2)uStack_70;
              uStack_94 = *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x28);
              uStack_8e = *(undefined1 *)(iVar9 + 0xb);
              uStack_8d = *(undefined1 *)(iVar9 + 0x14);
              uStack_8c = *(undefined1 *)(iVar9 + 0x17);
              iVar4 = r_lld_per_adv_start(uVar8,&uStack_98);
              if (iVar4 == 0) {
                iVar2 = *(int *)(_p_llm_env + 8) + iVar2;
                *(undefined1 *)(iVar2 + 0x40) = 0xc;
                r_lld_adv_sync_info_update(uVar13,uVar8,uStack_98);
                *(undefined4 *)(iVar2 + 0x14) = uStack_70;
                *(uint *)(iVar2 + 0x10) = uStack_74;
                *(undefined4 *)(iVar2 + 0x18) = uStack_80;
                *(ushort *)(iVar2 + 0x20) = (ushort)bVar7;
                *(undefined4 *)(iVar2 + 0x24) = 0;
                *(undefined4 *)(iVar2 + 0x1c) = uStack_7c;
                *(undefined1 *)(iVar2 + 0x22) = 0;
                r_sch_plan_set(iVar2 + 0xc);
                if ((_bt_rf_coex_hooks_p != (int *)0x0) &&
                   ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
                  (*(code *)*_bt_rf_coex_hooks_p)(uVar8,4,1);
                }
              }
            }
            else {
_L593:
              if ((*(ushort *)(iVar3 + 2) & 1) != 0) {
                iVar2 = r_llm_activity_free_get(&uStack_88);
                if (iVar2 == 0) {
                  iVar2 = *(int *)(_p_llm_env + 8);
                  *(undefined1 *)(iVar4 + iVar2 + 0x3e) = (undefined1)uStack_88;
                  *(undefined1 *)(iVar2 + (uStack_88 & 0xff) * 0x44 + 0x40) = 4;
                }
                else {
                  r_assert_err(0,"llm_adv.c",0x690);
                }
              }
            }
            if (_bt_rf_coex_hooks_p != (int *)0x0) {
              pcVar6 = (code *)*_bt_rf_coex_hooks_p;
              uVar5 = 1;
              if (pcVar6 != (code *)0x0) {
_L674:
                (*pcVar6)(uVar13,2,uVar5);
              }
            }
          }
        }
      }
      if ((char)*param_1 == '\0') {
        uVar8 = (uint)*(byte *)(_p_llm_env + 0xd6);
        if (uVar8 != 0) {
          return 0;
        }
      }
      else {
        uVar8 = 0;
      }
    }
  }
_L556:
  r_llm_cmd_cmp_send(param_2,uVar8);
  return 0;
}

