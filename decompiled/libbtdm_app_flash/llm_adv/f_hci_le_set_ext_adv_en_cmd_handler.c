/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_adv.o -> f_hci_le_set_ext_adv_en_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_set_ext_adv_en_cmd_handler(byte *param_1,undefined4 param_2)

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
  
  iVar12 = _p_llm_env;
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L561:
    iVar12 = 0xc;
    goto _L552;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  if (*param_1 == 0) {
    pbVar4 = (byte *)0x2;
    if (*(char *)(iVar12 + 0xd6) != '\0') {
      return 2;
    }
_L555:
    if (*(short *)param_1 != 1) {
      if (param_1[1] == 0) {
        for (uVar9 = 0; iVar12 = r_sdk_config_get_opts(), uVar9 < *(byte *)(iVar12 + 0xd);
            uVar9 = uVar9 + 1 & 0xff) {
          if ((*(char *)(*(int *)(_p_llm_env + 8) + uVar9 * 0x44 + 0x40) == '\x02') &&
             (iVar2 = r_lld_adv_stop(uVar9), iVar12 = _p_llm_env, iVar2 == 0)) {
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
          if (0xef < param_1[uVar9 + 2]) goto _L556;
          pbVar3 = (byte *)r_llm_adv_hdl_to_id(0);
          if (pbVar3 == (byte *)0xff) {
            iVar12 = 0x42;
            goto _L552;
          }
          piVar13 = (int *)(*(int *)(_p_llm_env + 8) + (int)pbVar3 * 0x44);
          if (((short)piVar13[0xb] != 0) || (*(short *)((int)piVar13 + 0x36) != 0)) goto _L556;
          pbVar4 = pbVar3;
          if (*param_1 == 1) {
            iVar12 = *piVar13;
            uVar1 = *(ushort *)(iVar12 + 2);
            if (((uVar1 & 2) != 0) && ((uVar1 & 0x10) == 0 && (short)piVar13[0xd] == 0)) goto _L561;
            if (((uVar1 & 0x11) == 1) &&
               (pbVar4 = (byte *)r_llm_adv_con_len_check
                                           (iVar12,*(undefined2 *)((int)piVar13 + 0x2a)),
               pbVar4 != (byte *)0x0)) goto _L556;
            if ((*(ushort *)(iVar12 + 2) & 1) != 0) {
              if (((*(ushort *)(iVar12 + 2) & 0xc) != 0) &&
                 (pbVar4 = (byte *)r_llm_is_dev_connected
                                             (iVar12 + 0xd,*(undefined1 *)(iVar12 + 0xc)),
                 pbVar4 != (byte *)0x0)) {
                iVar12 = 0xb;
                goto _L552;
              }
              if (((*(ushort *)(iVar12 + 2) & 8) != 0) &&
                 (0x7f < (ushort)(*(short *)(param_1 + uVar9 * 2 + 0xc) - 1U))) goto _L556;
              bVar8 = bVar8 + 1;
            }
            if (((*(byte *)(iVar12 + 0xb) & 1) != 0) &&
               (pbVar4 = (byte *)r_co_bdaddr_compare(*(int *)(_p_llm_env + 8) + (int)pbVar3 * 0x44 +
                                                     4,&co_null_bdaddr), pbVar4 != (byte *)0x0))
            goto _L556;
          }
          else if (((_DAT_00014056 & 2) == 0) && ((char)piVar13[0x10] != '\x02')) goto _L561;
          param_1[uVar9 + 2] = (byte)pbVar3;
        }
        if (bVar8 != 0) {
          bVar10 = 0;
          for (uVar9 = 0; pbVar4 = (byte *)r_sdk_config_get_opts(pbVar4), uVar9 < pbVar4[0xd];
              uVar9 = uVar9 + 1 & 0xff) {
            bVar10 = bVar10 + (*(char *)(*(int *)(_p_llm_env + 8) + uVar9 * 0x44 + 0x40) == '\0');
            if (bVar8 <= bVar10) goto _L576;
          }
          iVar12 = 7;
          if (bVar10 < bVar8) goto _L552;
        }
_L576:
        for (uVar9 = 0; iVar12 = _p_llm_env, uVar9 < param_1[1]; uVar9 = uVar9 + 1 & 0xff) {
          uVar11 = (uint)param_1[uVar9 + 2];
          iVar2 = uVar11 * 0x44;
          piVar13 = (int *)(*(int *)(_p_llm_env + 8) + iVar2);
          if ((char)piVar13[0x10] == '\x02') {
            if (*param_1 == 0) {
_L578:
              if ((((_DAT_00014056 & 2) == 0) || ((char)piVar13[0x10] == '\x02')) &&
                 (iVar5 = r_lld_adv_stop(uVar11), iVar12 = _p_llm_env, iVar5 == 0)) {
                *(undefined1 *)(iVar2 + *(int *)(_p_llm_env + 8) + 0x40) = 3;
                *(char *)(iVar12 + 0xd6) = *(char *)(iVar12 + 0xd6) + '\x01';
                uVar14 = 0;
                while ((iVar12 = r_sdk_config_get_opts(), uVar14 < *(byte *)(iVar12 + 0xd) &&
                       (*(char *)(*(int *)(_p_llm_env + 8) + uVar14 * 0x44 + 0x40) != '\x02'))) {
                  uVar14 = uVar14 + 1 & 0xff;
                }
                iVar12 = r_sdk_config_get_opts();
                if (((*(byte *)(iVar12 + 0xd) <= uVar14) && (_bt_rf_coex_hooks_p != (int *)0x0)) &&
                   (pcVar7 = (code *)*_bt_rf_coex_hooks_p, pcVar7 != (code *)0x0)) {
                  uVar6 = 0;
                  goto _L670;
                }
              }
            }
            else {
              r_lld_adv_restart(uVar11,*(undefined2 *)(param_1 + uVar9 * 2 + 0xc),
                                param_1[uVar9 + 0x20]);
              piVar13 = (int *)(*(int *)(_p_llm_env + 8) + iVar2);
              iVar12 = *piVar13;
              if ((iVar12 != 0) && ((*(ushort *)(iVar12 + 2) & 1) != 0)) {
                bVar8 = *(byte *)((int)piVar13 + 0x3e);
                uStack_68 = CONCAT31(uStack_68._1_3_,bVar8);
                if ((bVar8 == 0xff) ||
                   (*(char *)((uint)bVar8 * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) == '\0')) {
                  iVar12 = r_llm_activity_free_get(&uStack_68);
                  if (iVar12 == 0) {
                    iVar12 = *(int *)(_p_llm_env + 8);
                    *(undefined1 *)(iVar2 + iVar12 + 0x3e) = (undefined1)uStack_68;
                    *(undefined1 *)(iVar12 + (uStack_68 & 0xff) * 0x44 + 0x40) = 4;
                  }
                  else {
                    r_assert_param(0,"llm_adv.c",0x613);
                  }
                }
              }
            }
          }
          else {
            if (*param_1 == 0) goto _L578;
            iVar5 = *piVar13;
            uVar1 = *(ushort *)(iVar5 + 2);
            uStack_5c = (uint)*(byte *)(iVar5 + 9) << 0x10 | (uint)*(byte *)(iVar5 + 8) << 8 |
                        (uint)*(byte *)(iVar5 + 7);
            uStack_4b = *(undefined1 *)(iVar5 + 10);
            uStack_4a = *(undefined1 *)(iVar5 + 0xb);
            uStack_49 = *(undefined1 *)(iVar5 + 0xc);
            uStack_50 = uVar1;
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
            uStack_68 = piVar13[1];
            uStack_64 = (undefined2)piVar13[2];
            uStack_58 = (undefined2)piVar13[10];
            uStack_54 = *(undefined2 *)((int)piVar13 + 0x2a);
            uStack_56 = *(undefined2 *)((int)piVar13 + 0x32);
            uStack_52 = (undefined2)piVar13[0xd];
            uStack_4e = *(undefined2 *)(param_1 + uVar9 * 2 + 0xc);
            bStack_4c = param_1[uVar9 + 0x20];
            uStack_41 = *(undefined1 *)(iVar12 + 0xc6);
            iVar12 = r_lld_adv_start_eco(uVar11,&uStack_68);
            if (iVar12 != 0) {
              r_assert_param(uVar11,0,"llm_adv.c",0x69c);
              goto _L552;
            }
            iVar12 = *(int *)(_p_llm_env + 8) + iVar2;
            *(undefined1 *)(iVar12 + 0x40) = 2;
            if ((*(ushort *)(iVar5 + 2) & 0x13) == 0) {
              bVar8 = *(byte *)(iVar12 + 0x3d);
              uVar14 = (uint)bVar8;
              iVar12 = r_sdk_config_get_opts();
              if (*(byte *)(iVar12 + 0xd) <= uVar14) goto _L589;
              iVar12 = uVar14 * 0x44;
              piVar13 = (int *)(*(int *)(_p_llm_env + 8) + iVar12);
              if ((char)piVar13[0x10] != '\v') goto _L589;
              iVar5 = *piVar13;
              iVar15 = *(int *)(iVar2 + *(int *)(_p_llm_env + 8));
              iStack_84 = (uint)*(ushort *)(iVar5 + 4) << 1;
              uStack_88 = (uint)*(ushort *)(iVar5 + 2) << 1;
              uStack_80 = r_llm_per_adv_slot_dur
                                    (*(undefined2 *)((int)piVar13 + 0x2a),
                                     *(undefined1 *)(iVar15 + 0x17));
              uStack_76 = 0;
              uStack_7c = uStack_80;
              uStack_78 = (ushort)bVar8;
              iVar2 = r_sch_plan_req(&uStack_88);
              if (iVar2 != 0) break;
              uStack_96 = *(undefined2 *)(iVar5 + 6);
              uStack_98 = (undefined2)(uStack_74 >> 1);
              uStack_90 = (undefined2)uStack_70;
              uStack_94 = *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar12 + 0x28);
              uStack_8e = *(undefined1 *)(iVar15 + 0xb);
              uStack_8d = *(undefined1 *)(iVar15 + 0x14);
              uStack_8c = *(undefined1 *)(iVar15 + 0x17);
              iVar2 = r_lld_per_adv_start(uVar14,&uStack_98);
              if (iVar2 == 0) {
                iVar12 = *(int *)(_p_llm_env + 8) + iVar12;
                *(undefined1 *)(iVar12 + 0x40) = 0xc;
                r_lld_adv_sync_info_update(uVar11,uVar14,uStack_98);
                *(undefined4 *)(iVar12 + 0x14) = uStack_70;
                *(uint *)(iVar12 + 0x10) = uStack_74;
                *(undefined4 *)(iVar12 + 0x18) = uStack_80;
                *(ushort *)(iVar12 + 0x20) = (ushort)bVar8;
                *(undefined4 *)(iVar12 + 0x24) = 0;
                *(undefined4 *)(iVar12 + 0x1c) = uStack_7c;
                *(undefined1 *)(iVar12 + 0x22) = 0;
                r_sch_plan_set(iVar12 + 0xc);
                if ((_bt_rf_coex_hooks_p != (int *)0x0) &&
                   ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
                  (*(code *)*_bt_rf_coex_hooks_p)(uVar14,4,1);
                }
              }
            }
            else {
_L589:
              if ((*(ushort *)(iVar5 + 2) & 1) != 0) {
                iVar12 = r_llm_activity_free_get(&uStack_88);
                if (iVar12 == 0) {
                  iVar12 = *(int *)(_p_llm_env + 8);
                  *(undefined1 *)(iVar2 + iVar12 + 0x3e) = (undefined1)uStack_88;
                  *(undefined1 *)(iVar12 + (uStack_88 & 0xff) * 0x44 + 0x40) = 4;
                }
                else {
                  r_assert_err(0,"llm_adv.c",0x690);
                }
              }
            }
            if (_bt_rf_coex_hooks_p != (int *)0x0) {
              pcVar7 = (code *)*_bt_rf_coex_hooks_p;
              uVar6 = 1;
              if (pcVar7 != (code *)0x0) {
_L670:
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
      goto _L552;
    }
  }
  else {
    pbVar4 = param_1;
    if (*param_1 < 2) goto _L555;
  }
_L556:
  iVar12 = 0x12;
_L552:
  r_llm_cmd_cmp_send(param_2,iVar12);
  return 0;
}

