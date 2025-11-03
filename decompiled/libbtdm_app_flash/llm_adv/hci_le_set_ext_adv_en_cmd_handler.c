/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llm_adv.o -> hci_le_set_ext_adv_en_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_ext_adv_en_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  code *pcVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
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
  
  iVar5 = r_sdk_config_get_opts_ext();
  if ((*(char *)(iVar5 + 0x18) == '\0') ||
     (iVar6 = r_sdk_config_get_opts_ext(), iVar5 = _p_llm_env, *(char *)(iVar6 + 0x25) == '\0')) {
    r_llm_cmd_cmp_send(param_2,0xc);
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L740:
    iVar5 = 0xc;
    goto _L606;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  if (*param_1 == 0) {
    if (*(byte *)(iVar5 + 0xd6) != 0) {
      r_ble_log_internal_x1(0x402e0108,(uint)*(byte *)(iVar5 + 0xd6) << 0x10 | 0x12);
      return 2;
    }
_L608:
    if (*(short *)param_1 != 1) {
      if (param_1[1] == 0) {
        for (uVar10 = 0; iVar5 = r_sdk_config_get_opts(), uVar10 < *(byte *)(iVar5 + 0xd);
            uVar10 = uVar10 + 1 & 0xff) {
          if ((*(char *)(*(int *)(_p_llm_env + 8) + uVar10 * 0x44 + 0x40) == '\x02') &&
             (iVar6 = r_lld_adv_stop(uVar10), iVar5 = _p_llm_env, iVar6 == 0)) {
            *(undefined1 *)(*(int *)(_p_llm_env + 8) + uVar10 * 0x44 + 0x40) = 3;
            *(char *)(iVar5 + 0xd6) = *(char *)(iVar5 + 0xd6) + '\x01';
            r_ble_log_internal_x1(0x404e0114,uVar10 | 0x300);
            if ((_bt_rf_coex_hooks_p != (int *)0x0) && ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)
               ) {
              (*(code *)*_bt_rf_coex_hooks_p)(uVar10,2,0);
            }
          }
        }
      }
      else {
        uVar12 = 0;
        uVar10 = 0;
        do {
          if (0xef < param_1[uVar12 + 2]) goto _L739;
          iVar5 = r_llm_adv_hdl_to_id(0);
          if (iVar5 == 0xff) {
            r_ble_log_internal_x1
                      (0x802e0109,
                       (uint)param_1[uVar12 + 2] << 0x10 | (uint)*param_1 << 0x18 | uVar12 << 8 |
                       0x42);
            iVar5 = 0x42;
            goto _L606;
          }
          iVar6 = iVar5 * 0x44;
          piVar9 = (int *)(*(int *)(_p_llm_env + 8) + iVar6);
          if (((short)piVar9[0xb] != 0) || (*(short *)((int)piVar9 + 0x36) != 0)) {
            uVar10 = iVar5 << 8 | 0x12;
            uVar7 = CONCAT22(*(short *)((int)piVar9 + 0x36),(short)piVar9[0xb]);
            uVar3 = 0x802e010a;
_L741:
            r_ble_log_internal_x2(uVar3,uVar7,uVar10);
            goto _L739;
          }
          if (*param_1 == 1) {
            iVar13 = *piVar9;
            uVar2 = *(ushort *)(iVar13 + 2);
            if (((uVar2 & 2) != 0) && ((short)piVar9[0xd] == 0 && (uVar2 & 0x10) == 0)) {
              r_ble_log_internal_x1(0x802e010b,iVar5 << 8 | 0xc);
              goto _L740;
            }
            if (((uVar2 & 0x11) == 1) &&
               (iVar4 = r_llm_adv_con_len_check(iVar13,*(undefined2 *)((int)piVar9 + 0x2a)),
               iVar4 != 0)) {
              uVar10 = iVar5 << 8 | 0x12;
              uVar3 = 0x802e010c;
              uVar7 = CONCAT22(*(undefined2 *)(*(int *)(_p_llm_env + 8) + iVar6 + 0x2a),
                               *(undefined2 *)(iVar13 + 2));
              goto _L741;
            }
            if ((*(ushort *)(iVar13 + 2) & 1) != 0) {
              if (((*(ushort *)(iVar13 + 2) & 0xc) != 0) &&
                 (iVar4 = r_llm_is_dev_connected(iVar13 + 0xd,*(undefined1 *)(iVar13 + 0xc)),
                 iVar4 != 0)) {
                r_ble_log_internal_x1(0x802e010d,*(ushort *)(iVar13 + 2) | 0xb0000);
                iVar5 = 0xb;
                goto _L606;
              }
              if (((*(ushort *)(iVar13 + 2) & 8) != 0) &&
                 (0x7f < (ushort)(*(short *)(param_1 + uVar12 * 2 + 0xc) - 1U))) {
                uVar10 = uVar12 << 8 | 0x12;
                uVar7 = CONCAT22(*(short *)(param_1 + uVar12 * 2 + 0xc),*(ushort *)(iVar13 + 2));
                uVar3 = 0x802e010e;
                goto _L741;
              }
              uVar10 = uVar10 + 1 & 0xff;
            }
            if (((*(byte *)(iVar13 + 0xb) & 1) != 0) &&
               (iVar6 = r_co_bdaddr_compare(*(int *)(_p_llm_env + 8) + iVar6 + 4,&co_null_bdaddr),
               iVar6 != 0)) {
              r_ble_log_internal_x1
                        (0x802e010f,(uint)*(byte *)(iVar13 + 0xb) << 0x10 | iVar5 << 8 | 0x12);
              goto _L739;
            }
          }
          else if (((_DAT_0001405e & 2) == 0) && ((char)piVar9[0x10] != '\x02')) goto _L740;
          param_1[uVar12 + 2] = (byte)iVar5;
          uVar12 = uVar12 + 1 & 0xff;
        } while (uVar12 < param_1[1]);
        if (uVar10 != 0) {
          uVar12 = 0;
          for (uVar11 = 0; iVar5 = r_sdk_config_get_opts(), uVar11 < *(byte *)(iVar5 + 0xd);
              uVar11 = uVar11 + 1 & 0xff) {
            uVar12 = uVar12 + (*(char *)(*(int *)(_p_llm_env + 8) + uVar11 * 0x44 + 0x40) == '\0') &
                     0xff;
            if (uVar10 <= uVar12) goto _L628;
          }
          if (uVar12 < uVar10) {
            r_ble_log_internal_x1(0x802e0110,uVar12 << 8 | uVar10 << 0x10 | 7);
            iVar5 = 7;
            goto _L606;
          }
        }
_L628:
        for (uVar10 = 0; iVar5 = _p_llm_env, uVar10 < param_1[1]; uVar10 = uVar10 + 1 & 0xff) {
          uVar12 = (uint)param_1[uVar10 + 2];
          iVar6 = uVar12 * 0x44;
          piVar9 = (int *)(*(int *)(_p_llm_env + 8) + iVar6);
          if ((char)piVar9[0x10] == '\x02') {
            if (*param_1 == 0) {
_L630:
              if ((((_DAT_0001405e & 2) == 0) || ((char)piVar9[0x10] == '\x02')) &&
                 (iVar13 = r_lld_adv_stop(uVar12), iVar5 = _p_llm_env, iVar13 == 0)) {
                *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar6 + 0x40) = 3;
                *(char *)(iVar5 + 0xd6) = *(char *)(iVar5 + 0xd6) + '\x01';
                r_ble_log_internal_x1(0x404e0113,uVar12 | 0x300);
                uVar11 = 0;
                while ((iVar5 = r_sdk_config_get_opts(), uVar11 < *(byte *)(iVar5 + 0xd) &&
                       (*(char *)(*(int *)(_p_llm_env + 8) + uVar11 * 0x44 + 0x40) != '\x02'))) {
                  uVar11 = uVar11 + 1 & 0xff;
                }
                iVar5 = r_sdk_config_get_opts();
                if ((*(byte *)(iVar5 + 0xd) <= uVar11) &&
                   ((_bt_rf_coex_hooks_p != (int *)0x0 &&
                    (pcVar8 = (code *)*_bt_rf_coex_hooks_p, pcVar8 != (code *)0x0)))) {
                  uVar3 = 0;
                  goto _L738;
                }
              }
            }
            else {
              r_lld_adv_restart(uVar12,*(undefined2 *)(param_1 + uVar10 * 2 + 0xc),
                                param_1[uVar10 + 0x20]);
              piVar9 = (int *)(*(int *)(_p_llm_env + 8) + iVar6);
              iVar5 = *piVar9;
              if ((iVar5 != 0) && ((*(ushort *)(iVar5 + 2) & 1) != 0)) {
                bVar1 = *(byte *)((int)piVar9 + 0x3e);
                uStack_68 = CONCAT31(uStack_68._1_3_,bVar1);
                if ((bVar1 == 0xff) ||
                   (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bVar1 * 0x44 + 0x40) == '\0')) {
                  iVar5 = r_llm_activity_free_get(&uStack_68);
                  if (iVar5 == 0) {
                    iVar5 = *(int *)(_p_llm_env + 8);
                    *(undefined1 *)(iVar6 + iVar5 + 0x3e) = (undefined1)uStack_68;
                    *(undefined1 *)(iVar5 + (uStack_68 & 0xff) * 0x44 + 0x40) = 4;
                  }
                  else {
                    r_assert_param(0,"llm_adv.c",0x663);
                  }
                }
              }
            }
          }
          else {
            if (*param_1 == 0) goto _L630;
            iVar13 = *piVar9;
            uVar2 = *(ushort *)(iVar13 + 2);
            uStack_5c = (uint)*(byte *)(iVar13 + 9) << 0x10 | (uint)*(byte *)(iVar13 + 8) << 8 |
                        (uint)*(byte *)(iVar13 + 7);
            uStack_4b = *(undefined1 *)(iVar13 + 10);
            uStack_4a = *(undefined1 *)(iVar13 + 0xb);
            uStack_49 = *(undefined1 *)(iVar13 + 0xc);
            uStack_50 = uVar2;
            memcpy(auStack_62,(void *)(iVar13 + 0xd),6);
            uStack_48 = 0;
            if ((uVar2 & 4) == 0) {
              uStack_48 = *(undefined1 *)(iVar13 + 0x13);
            }
            uStack_47 = (undefined1)piVar9[0xf];
            uStack_45 = 0;
            uStack_46 = *(undefined1 *)(iVar13 + 0x15);
            if ((uVar2 & 0x10) == 0) {
              uStack_45 = *(undefined1 *)(iVar13 + 0x16);
            }
            uStack_44 = 1;
            if ((uVar2 & 0x10) == 0) {
              uStack_44 = *(undefined1 *)(iVar13 + 0x17);
            }
            uStack_43 = *(undefined1 *)(iVar13 + 0x18);
            uStack_42 = *(undefined1 *)(iVar13 + 0x19);
            uStack_68 = piVar9[1];
            uStack_64 = (undefined2)piVar9[2];
            uStack_58 = (undefined2)piVar9[10];
            uStack_54 = *(undefined2 *)((int)piVar9 + 0x2a);
            uStack_56 = *(undefined2 *)((int)piVar9 + 0x32);
            uStack_52 = (undefined2)piVar9[0xd];
            uStack_4e = *(undefined2 *)(param_1 + uVar10 * 2 + 0xc);
            bStack_4c = param_1[uVar10 + 0x20];
            uStack_41 = *(undefined1 *)(iVar5 + 0xc6);
            iVar5 = r_lld_adv_start_eco(uVar12,&uStack_68);
            if (iVar5 != 0) {
              r_assert_param(uVar12,0,"llm_adv.c",0x6ef);
              goto _L606;
            }
            *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar6 + 0x40) = 2;
            r_ble_log_internal_x1(0x404e0111,uVar12 | 0x200);
            bVar1 = *(byte *)(*(int *)(_p_llm_env + 8) + iVar6 + 0x3d);
            uVar11 = (uint)bVar1;
            if (((*(ushort *)(iVar13 + 2) & 0x13) == 0) &&
               (iVar5 = r_sdk_config_get_opts(), uVar11 < *(byte *)(iVar5 + 0xd))) {
              iVar5 = uVar11 * 0x44;
              piVar9 = (int *)(*(int *)(_p_llm_env + 8) + iVar5);
              if ((char)piVar9[0x10] != '\v') goto _L641;
              iVar13 = *piVar9;
              iVar4 = *(int *)(*(int *)(_p_llm_env + 8) + iVar6);
              iStack_84 = (uint)*(ushort *)(iVar13 + 4) << 1;
              uStack_88 = (uint)*(ushort *)(iVar13 + 2) << 1;
              uStack_80 = r_llm_per_adv_slot_dur
                                    (*(undefined2 *)((int)piVar9 + 0x2a),
                                     *(undefined1 *)(iVar4 + 0x17));
              uStack_76 = 0;
              uStack_7c = uStack_80;
              uStack_78 = (ushort)bVar1;
              iVar6 = r_sch_plan_req(&uStack_88);
              if (iVar6 != 0) break;
              uStack_8c = *(undefined1 *)(iVar4 + 0x17);
              uStack_96 = *(undefined2 *)(iVar13 + 6);
              uStack_98 = (undefined2)(uStack_74 >> 1);
              uStack_90 = (undefined2)uStack_70;
              uStack_94 = *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar5 + 0x28);
              uStack_8e = *(undefined1 *)(iVar4 + 0xb);
              uStack_8d = *(undefined1 *)(iVar4 + 0x14);
              iVar6 = r_lld_per_adv_start(uVar11,&uStack_98);
              if (iVar6 == 0) {
                iVar5 = *(int *)(_p_llm_env + 8) + iVar5;
                *(undefined1 *)(iVar5 + 0x40) = 0xc;
                r_ble_log_internal_x1(0x404e0112,uVar11 | 0xc00);
                r_lld_adv_sync_info_update(uVar12,uVar11,uStack_98);
                *(undefined4 *)(iVar5 + 0x14) = uStack_70;
                *(uint *)(iVar5 + 0x10) = uStack_74;
                *(undefined4 *)(iVar5 + 0x18) = uStack_80;
                *(ushort *)(iVar5 + 0x20) = (ushort)bVar1;
                *(undefined4 *)(iVar5 + 0x24) = 0;
                *(undefined4 *)(iVar5 + 0x1c) = uStack_7c;
                *(undefined1 *)(iVar5 + 0x22) = 0;
                r_sch_plan_set_hack(iVar5 + 0xc);
                if ((_bt_rf_coex_hooks_p != (int *)0x0) &&
                   ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
                  (*(code *)*_bt_rf_coex_hooks_p)(uVar11,4,1);
                }
              }
            }
            else {
_L641:
              if ((*(ushort *)(iVar13 + 2) & 1) != 0) {
                iVar5 = r_llm_activity_free_get(&uStack_88);
                if (iVar5 == 0) {
                  iVar5 = *(int *)(_p_llm_env + 8);
                  *(undefined1 *)(iVar6 + iVar5 + 0x3e) = (undefined1)uStack_88;
                  *(undefined1 *)(iVar5 + (uStack_88 & 0xff) * 0x44 + 0x40) = 4;
                }
                else {
                  r_assert_err(0,"llm_adv.c",0x6e3);
                }
              }
            }
            if (_bt_rf_coex_hooks_p != (int *)0x0) {
              pcVar8 = (code *)*_bt_rf_coex_hooks_p;
              uVar3 = 1;
              if (pcVar8 != (code *)0x0) {
_L738:
                (*pcVar8)(uVar12,2,uVar3);
              }
            }
          }
        }
      }
      if (*param_1 == 0) {
        if (*(char *)(_p_llm_env + 0xd6) != '\0') {
          return 0;
        }
        iVar5 = 0;
      }
      else {
        iVar5 = 0;
      }
      goto _L606;
    }
  }
  else if (*param_1 == 1) goto _L608;
_L739:
  iVar5 = 0x12;
_L606:
  r_llm_cmd_cmp_send(param_2,iVar5);
  return 0;
}

