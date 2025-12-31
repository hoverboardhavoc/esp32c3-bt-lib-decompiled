/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llm_adv.o -> f_hci_le_set_ext_adv_en_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_set_ext_adv_en_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  code *pcVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
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
  
  iVar11 = _p_llm_env;
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L740:
    iVar11 = 0xc;
    goto _L606;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  if (*param_1 == 0) {
    if (*(byte *)(iVar11 + 0xd6) != 0) {
      r_ble_log_internal_x1(0x402e0166,(uint)*(byte *)(iVar11 + 0xd6) << 0x10 | 0x12);
      return 2;
    }
_L608:
    if (*(short *)param_1 != 1) {
      if (param_1[1] == 0) {
        for (uVar9 = 0; iVar11 = r_sdk_config_get_opts(), uVar9 < *(byte *)(iVar11 + 0xd);
            uVar9 = uVar9 + 1 & 0xff) {
          if ((*(char *)(*(int *)(_p_llm_env + 8) + uVar9 * 0x44 + 0x40) == '\x02') &&
             (iVar3 = r_lld_adv_stop(uVar9), iVar11 = _p_llm_env, iVar3 == 0)) {
            *(undefined1 *)(*(int *)(_p_llm_env + 8) + uVar9 * 0x44 + 0x40) = 3;
            *(char *)(iVar11 + 0xd6) = *(char *)(iVar11 + 0xd6) + '\x01';
            r_ble_log_internal_x1(0x404e0172,uVar9 | 0x300);
            if ((_bt_rf_coex_hooks_p != (int *)0x0) && ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)
               ) {
              (*(code *)*_bt_rf_coex_hooks_p)(uVar9,2,0);
            }
          }
        }
      }
      else {
        uVar12 = 0;
        uVar9 = 0;
        do {
          if (0xef < param_1[uVar12 + 2]) goto _L739;
          iVar11 = r_llm_adv_hdl_to_id(0);
          if (iVar11 == 0xff) {
            r_ble_log_internal_x1
                      (0x802e0167,
                       (uint)param_1[uVar12 + 2] << 0x10 | (uint)*param_1 << 0x18 | uVar12 << 8 |
                       0x42);
            iVar11 = 0x42;
            goto _L606;
          }
          iVar3 = iVar11 * 0x44;
          piVar8 = (int *)(*(int *)(_p_llm_env + 8) + iVar3);
          if (((short)piVar8[0xb] != 0) || (*(short *)((int)piVar8 + 0x36) != 0)) {
            uVar9 = iVar11 << 8 | 0x12;
            uVar6 = CONCAT22(*(short *)((int)piVar8 + 0x36),(short)piVar8[0xb]);
            uVar4 = 0x802e0168;
_L741:
            r_ble_log_internal_x2(uVar4,uVar6,uVar9);
            goto _L739;
          }
          if (*param_1 == 1) {
            iVar13 = *piVar8;
            uVar2 = *(ushort *)(iVar13 + 2);
            if (((uVar2 & 2) != 0) && ((short)piVar8[0xd] == 0 && (uVar2 & 0x10) == 0)) {
              r_ble_log_internal_x1(0x802e0169,iVar11 << 8 | 0xc);
              goto _L740;
            }
            if (((uVar2 & 0x11) == 1) &&
               (iVar5 = r_llm_adv_con_len_check(iVar13,*(undefined2 *)((int)piVar8 + 0x2a)),
               iVar5 != 0)) {
              uVar9 = iVar11 << 8 | 0x12;
              uVar4 = 0x802e016a;
              uVar6 = CONCAT22(*(undefined2 *)(*(int *)(_p_llm_env + 8) + iVar3 + 0x2a),
                               *(undefined2 *)(iVar13 + 2));
              goto _L741;
            }
            if ((*(ushort *)(iVar13 + 2) & 1) != 0) {
              if (((*(ushort *)(iVar13 + 2) & 0xc) != 0) &&
                 (iVar5 = r_llm_is_dev_connected(iVar13 + 0xd,*(undefined1 *)(iVar13 + 0xc)),
                 iVar5 != 0)) {
                r_ble_log_internal_x1(0x802e016b,*(ushort *)(iVar13 + 2) | 0xb0000);
                iVar11 = 0xb;
                goto _L606;
              }
              if (((*(ushort *)(iVar13 + 2) & 8) != 0) &&
                 (0x7f < (ushort)(*(short *)(param_1 + uVar12 * 2 + 0xc) - 1U))) {
                uVar9 = uVar12 << 8 | 0x12;
                uVar6 = CONCAT22(*(short *)(param_1 + uVar12 * 2 + 0xc),*(ushort *)(iVar13 + 2));
                uVar4 = 0x802e016c;
                goto _L741;
              }
              uVar9 = uVar9 + 1 & 0xff;
            }
            if (((*(byte *)(iVar13 + 0xb) & 1) != 0) &&
               (iVar3 = r_co_bdaddr_compare(*(int *)(_p_llm_env + 8) + iVar3 + 4,&co_null_bdaddr),
               iVar3 != 0)) {
              r_ble_log_internal_x1
                        (0x802e016d,(uint)*(byte *)(iVar13 + 0xb) << 0x10 | iVar11 << 8 | 0x12);
              goto _L739;
            }
          }
          else if (((_DAT_0001405e & 2) == 0) && ((char)piVar8[0x10] != '\x02')) goto _L740;
          param_1[uVar12 + 2] = (byte)iVar11;
          uVar12 = uVar12 + 1 & 0xff;
        } while (uVar12 < param_1[1]);
        if (uVar9 != 0) {
          uVar12 = 0;
          for (uVar10 = 0; iVar11 = r_sdk_config_get_opts(), uVar10 < *(byte *)(iVar11 + 0xd);
              uVar10 = uVar10 + 1 & 0xff) {
            uVar12 = uVar12 + (*(char *)(*(int *)(_p_llm_env + 8) + uVar10 * 0x44 + 0x40) == '\0') &
                     0xff;
            if (uVar9 <= uVar12) goto _L628;
          }
          if (uVar12 < uVar9) {
            r_ble_log_internal_x1(0x802e016e,uVar12 << 8 | uVar9 << 0x10 | 7);
            iVar11 = 7;
            goto _L606;
          }
        }
_L628:
        for (uVar9 = 0; iVar11 = _p_llm_env, uVar9 < param_1[1]; uVar9 = uVar9 + 1 & 0xff) {
          uVar12 = (uint)param_1[uVar9 + 2];
          iVar3 = uVar12 * 0x44;
          piVar8 = (int *)(*(int *)(_p_llm_env + 8) + iVar3);
          if ((char)piVar8[0x10] == '\x02') {
            if (*param_1 == 0) {
_L630:
              if ((((_DAT_0001405e & 2) == 0) || ((char)piVar8[0x10] == '\x02')) &&
                 (iVar13 = r_lld_adv_stop(uVar12), iVar11 = _p_llm_env, iVar13 == 0)) {
                *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar3 + 0x40) = 3;
                *(char *)(iVar11 + 0xd6) = *(char *)(iVar11 + 0xd6) + '\x01';
                r_ble_log_internal_x1(0x404e0171,uVar12 | 0x300);
                uVar10 = 0;
                while ((iVar11 = r_sdk_config_get_opts(), uVar10 < *(byte *)(iVar11 + 0xd) &&
                       (*(char *)(*(int *)(_p_llm_env + 8) + uVar10 * 0x44 + 0x40) != '\x02'))) {
                  uVar10 = uVar10 + 1 & 0xff;
                }
                iVar11 = r_sdk_config_get_opts();
                if ((*(byte *)(iVar11 + 0xd) <= uVar10) &&
                   ((_bt_rf_coex_hooks_p != (int *)0x0 &&
                    (pcVar7 = (code *)*_bt_rf_coex_hooks_p, pcVar7 != (code *)0x0)))) {
                  uVar4 = 0;
                  goto _L738;
                }
              }
            }
            else {
              r_lld_adv_restart(uVar12,*(undefined2 *)(param_1 + uVar9 * 2 + 0xc),
                                param_1[uVar9 + 0x20]);
              piVar8 = (int *)(*(int *)(_p_llm_env + 8) + iVar3);
              iVar11 = *piVar8;
              if ((iVar11 != 0) && ((*(ushort *)(iVar11 + 2) & 1) != 0)) {
                bVar1 = *(byte *)((int)piVar8 + 0x3e);
                uStack_68 = CONCAT31(uStack_68._1_3_,bVar1);
                if ((bVar1 == 0xff) ||
                   (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bVar1 * 0x44 + 0x40) == '\0')) {
                  iVar11 = r_llm_activity_free_get(&uStack_68);
                  if (iVar11 == 0) {
                    iVar11 = *(int *)(_p_llm_env + 8);
                    *(undefined1 *)(iVar3 + iVar11 + 0x3e) = (undefined1)uStack_68;
                    *(undefined1 *)(iVar11 + (uStack_68 & 0xff) * 0x44 + 0x40) = 4;
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
            iVar13 = *piVar8;
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
            uStack_47 = (undefined1)piVar8[0xf];
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
            uStack_68 = piVar8[1];
            uStack_64 = (undefined2)piVar8[2];
            uStack_58 = (undefined2)piVar8[10];
            uStack_54 = *(undefined2 *)((int)piVar8 + 0x2a);
            uStack_56 = *(undefined2 *)((int)piVar8 + 0x32);
            uStack_52 = (undefined2)piVar8[0xd];
            uStack_4e = *(undefined2 *)(param_1 + uVar9 * 2 + 0xc);
            bStack_4c = param_1[uVar9 + 0x20];
            uStack_41 = *(undefined1 *)(iVar11 + 0xc6);
            iVar11 = r_lld_adv_start_eco(uVar12,&uStack_68);
            if (iVar11 != 0) {
              r_assert_param(uVar12,0,"llm_adv.c",0x6ef);
              goto _L606;
            }
            *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar3 + 0x40) = 2;
            r_ble_log_internal_x1(0x404e016f,uVar12 | 0x200);
            bVar1 = *(byte *)(*(int *)(_p_llm_env + 8) + iVar3 + 0x3d);
            uVar10 = (uint)bVar1;
            if (((*(ushort *)(iVar13 + 2) & 0x13) == 0) &&
               (iVar11 = r_sdk_config_get_opts(), uVar10 < *(byte *)(iVar11 + 0xd))) {
              iVar11 = uVar10 * 0x44;
              piVar8 = (int *)(*(int *)(_p_llm_env + 8) + iVar11);
              if ((char)piVar8[0x10] != '\v') goto _L641;
              iVar13 = *piVar8;
              iVar5 = *(int *)(*(int *)(_p_llm_env + 8) + iVar3);
              iStack_84 = (uint)*(ushort *)(iVar13 + 4) << 1;
              uStack_88 = (uint)*(ushort *)(iVar13 + 2) << 1;
              uStack_80 = r_llm_per_adv_slot_dur
                                    (*(undefined2 *)((int)piVar8 + 0x2a),
                                     *(undefined1 *)(iVar5 + 0x17));
              uStack_76 = 0;
              uStack_7c = uStack_80;
              uStack_78 = (ushort)bVar1;
              iVar3 = r_sch_plan_req(&uStack_88);
              if (iVar3 != 0) break;
              uStack_8c = *(undefined1 *)(iVar5 + 0x17);
              uStack_96 = *(undefined2 *)(iVar13 + 6);
              uStack_98 = (undefined2)(uStack_74 >> 1);
              uStack_90 = (undefined2)uStack_70;
              uStack_94 = *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar11 + 0x28);
              uStack_8e = *(undefined1 *)(iVar5 + 0xb);
              uStack_8d = *(undefined1 *)(iVar5 + 0x14);
              iVar3 = r_lld_per_adv_start(uVar10,&uStack_98);
              if (iVar3 == 0) {
                iVar11 = *(int *)(_p_llm_env + 8) + iVar11;
                *(undefined1 *)(iVar11 + 0x40) = 0xc;
                r_ble_log_internal_x1(0x404e0170,uVar10 | 0xc00);
                r_lld_adv_sync_info_update(uVar12,uVar10,uStack_98);
                *(undefined4 *)(iVar11 + 0x14) = uStack_70;
                *(uint *)(iVar11 + 0x10) = uStack_74;
                *(undefined4 *)(iVar11 + 0x18) = uStack_80;
                *(ushort *)(iVar11 + 0x20) = (ushort)bVar1;
                *(undefined4 *)(iVar11 + 0x24) = 0;
                *(undefined4 *)(iVar11 + 0x1c) = uStack_7c;
                *(undefined1 *)(iVar11 + 0x22) = 0;
                r_sch_plan_set_hack(iVar11 + 0xc);
                if ((_bt_rf_coex_hooks_p != (int *)0x0) &&
                   ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
                  (*(code *)*_bt_rf_coex_hooks_p)(uVar10,4,1);
                }
              }
            }
            else {
_L641:
              if ((*(ushort *)(iVar13 + 2) & 1) != 0) {
                iVar11 = r_llm_activity_free_get(&uStack_88);
                if (iVar11 == 0) {
                  iVar11 = *(int *)(_p_llm_env + 8);
                  *(undefined1 *)(iVar3 + iVar11 + 0x3e) = (undefined1)uStack_88;
                  *(undefined1 *)(iVar11 + (uStack_88 & 0xff) * 0x44 + 0x40) = 4;
                }
                else {
                  r_assert_err(0,"llm_adv.c",0x6e3);
                }
              }
            }
            if (_bt_rf_coex_hooks_p != (int *)0x0) {
              pcVar7 = (code *)*_bt_rf_coex_hooks_p;
              uVar4 = 1;
              if (pcVar7 != (code *)0x0) {
_L738:
                (*pcVar7)(uVar12,2,uVar4);
              }
            }
          }
        }
      }
      if (*param_1 == 0) {
        if (*(char *)(_p_llm_env + 0xd6) != '\0') {
          return 0;
        }
        iVar11 = 0;
      }
      else {
        iVar11 = 0;
      }
      goto _L606;
    }
  }
  else if (*param_1 == 1) goto _L608;
_L739:
  iVar11 = 0x12;
_L606:
  r_llm_cmd_cmp_send(param_2,iVar11);
  return 0;
}

