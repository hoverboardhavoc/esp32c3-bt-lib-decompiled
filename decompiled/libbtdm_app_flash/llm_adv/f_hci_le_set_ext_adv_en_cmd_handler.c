/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_adv.o -> f_hci_le_set_ext_adv_en_cmd_handler
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
  byte bVar7;
  uint uVar8;
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
_L576:
    iVar13 = 0xc;
    goto _L568;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  if ((char)*param_1 == '\0') {
    psVar2 = (short *)0x2;
    if (*(char *)(iVar13 + 0xd6) != '\0') {
      return 2;
    }
_L571:
    if (*param_1 != 1) {
      if (*(char *)((int)param_1 + 1) == '\0') {
        for (uVar8 = 0; psVar2 = (short *)r_sdk_config_get_opts(psVar2),
            uVar8 < *(byte *)((int)psVar2 + 0xd); uVar8 = uVar8 + 1 & 0xff) {
          if ((*(char *)(*(int *)(_p_llm_env + 8) + uVar8 * 0x44 + 0x40) == '\x02') &&
             (psVar2 = (short *)r_lld_adv_stop(uVar8), iVar13 = _p_llm_env, psVar2 == (short *)0x0))
          {
            *(undefined1 *)(*(int *)(_p_llm_env + 8) + uVar8 * 0x44 + 0x40) = 3;
            *(char *)(iVar13 + 0xd6) = *(char *)(iVar13 + 0xd6) + '\x01';
            if ((_bt_rf_coex_hooks_p != (int *)0x0) && ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)
               ) {
              psVar2 = (short *)(*(code *)*_bt_rf_coex_hooks_p)(uVar8,2,0);
            }
          }
        }
      }
      else {
        uVar8 = 0;
        bVar7 = 0;
        do {
          if (0xef < *(byte *)((int)param_1 + uVar8 + 2)) goto _L572;
          iVar13 = r_llm_adv_hdl_to_id(0);
          if (iVar13 == 0xff) {
            iVar13 = 0x42;
            goto _L568;
          }
          piVar5 = (int *)(*(int *)(_p_llm_env + 8) + iVar13 * 0x44);
          if (((short)piVar5[0xb] != 0) || (*(short *)((int)piVar5 + 0x36) != 0)) goto _L572;
          if ((char)*param_1 == '\x01') {
            iVar11 = *piVar5;
            uVar1 = *(ushort *)(iVar11 + 2);
            if (((uVar1 & 2) != 0) && ((uVar1 & 0x10) == 0 && (short)piVar5[0xd] == 0)) goto _L576;
            if (((uVar1 & 0x11) == 1) &&
               (iVar3 = r_llm_adv_con_len_check(iVar11,*(undefined2 *)((int)piVar5 + 0x2a)),
               iVar3 != 0)) goto _L572;
            if ((*(ushort *)(iVar11 + 2) & 1) != 0) {
              if (((*(ushort *)(iVar11 + 2) & 0xc) != 0) &&
                 (iVar3 = r_llm_is_dev_connected(iVar11 + 0xd,*(undefined1 *)(iVar11 + 0xc)),
                 iVar3 != 0)) {
                iVar13 = 0xb;
                goto _L568;
              }
              if (((*(ushort *)(iVar11 + 2) & 8) != 0) && (0x7f < (ushort)(param_1[uVar8 + 6] - 1U))
                 ) goto _L572;
              bVar7 = bVar7 + 1;
            }
            if (((*(byte *)(iVar11 + 0xb) & 1) != 0) &&
               (iVar11 = r_co_bdaddr_compare(*(int *)(_p_llm_env + 8) + iVar13 * 0x44 + 4,
                                             &co_null_bdaddr), iVar11 != 0)) goto _L572;
          }
          else if (((_DAT_0001405e & 2) == 0) && ((char)piVar5[0x10] != '\x02')) goto _L576;
          *(char *)((int)param_1 + uVar8 + 2) = (char)iVar13;
          uVar8 = uVar8 + 1 & 0xff;
        } while (uVar8 < *(byte *)((int)param_1 + 1));
        if (bVar7 != 0) {
          bVar9 = 0;
          for (uVar8 = 0; iVar13 = r_sdk_config_get_opts(), uVar8 < *(byte *)(iVar13 + 0xd);
              uVar8 = uVar8 + 1 & 0xff) {
            bVar9 = bVar9 + (*(char *)(*(int *)(_p_llm_env + 8) + uVar8 * 0x44 + 0x40) == '\0');
            if (bVar7 <= bVar9) goto _L591;
          }
          iVar13 = 7;
          if (bVar9 < bVar7) goto _L568;
        }
_L591:
        for (uVar8 = 0; iVar13 = _p_llm_env, uVar8 < *(byte *)((int)param_1 + 1);
            uVar8 = uVar8 + 1 & 0xff) {
          uVar10 = (uint)*(byte *)((int)param_1 + uVar8 + 2);
          iVar11 = uVar10 * 0x44;
          piVar5 = (int *)(*(int *)(_p_llm_env + 8) + iVar11);
          if ((char)piVar5[0x10] == '\x02') {
            if ((char)*param_1 == '\0') {
_L593:
              if ((((_DAT_0001405e & 2) == 0) || ((char)piVar5[0x10] == '\x02')) &&
                 (iVar3 = r_lld_adv_stop(uVar10), iVar13 = _p_llm_env, iVar3 == 0)) {
                *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar11 + 0x40) = 3;
                *(char *)(iVar13 + 0xd6) = *(char *)(iVar13 + 0xd6) + '\x01';
                uVar14 = 0;
                while ((iVar13 = r_sdk_config_get_opts(), uVar14 < *(byte *)(iVar13 + 0xd) &&
                       (*(char *)(*(int *)(_p_llm_env + 8) + uVar14 * 0x44 + 0x40) != '\x02'))) {
                  uVar14 = uVar14 + 1 & 0xff;
                }
                iVar13 = r_sdk_config_get_opts();
                if (((*(byte *)(iVar13 + 0xd) <= uVar14) && (_bt_rf_coex_hooks_p != (int *)0x0)) &&
                   (pcVar6 = (code *)*_bt_rf_coex_hooks_p, pcVar6 != (code *)0x0)) {
                  uVar4 = 0;
                  goto _L687;
                }
              }
            }
            else {
              r_lld_adv_restart(uVar10,param_1[uVar8 + 6],*(char *)((int)param_1 + uVar8 + 0x20));
              piVar5 = (int *)(*(int *)(_p_llm_env + 8) + iVar11);
              iVar13 = *piVar5;
              if ((iVar13 != 0) && ((*(ushort *)(iVar13 + 2) & 1) != 0)) {
                bVar7 = *(byte *)((int)piVar5 + 0x3e);
                uStack_68 = CONCAT31(uStack_68._1_3_,bVar7);
                if ((bVar7 == 0xff) ||
                   (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bVar7 * 0x44 + 0x40) == '\0')) {
                  iVar13 = r_llm_activity_free_get(&uStack_68);
                  if (iVar13 == 0) {
                    iVar13 = *(int *)(_p_llm_env + 8);
                    *(undefined1 *)(iVar11 + iVar13 + 0x3e) = (undefined1)uStack_68;
                    *(undefined1 *)(iVar13 + (uStack_68 & 0xff) * 0x44 + 0x40) = 4;
                  }
                  else {
                    r_assert_param(0,"llm_adv.c",0x613);
                  }
                }
              }
            }
          }
          else {
            if ((char)*param_1 == '\0') goto _L593;
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
            sStack_4e = param_1[uVar8 + 6];
            cStack_4c = *(char *)((int)param_1 + uVar8 + 0x20);
            uStack_41 = *(undefined1 *)(iVar13 + 0xc6);
            iVar13 = r_lld_adv_start_eco(uVar10,&uStack_68);
            if (iVar13 != 0) {
              r_assert_param(uVar10,0,"llm_adv.c",0x69c);
              goto _L568;
            }
            iVar13 = *(int *)(_p_llm_env + 8) + iVar11;
            *(undefined1 *)(iVar13 + 0x40) = 2;
            bVar7 = *(byte *)(iVar13 + 0x3d);
            uVar14 = (uint)bVar7;
            if (((*(ushort *)(iVar3 + 2) & 0x13) == 0) &&
               (iVar13 = r_sdk_config_get_opts(), uVar14 < *(byte *)(iVar13 + 0xd))) {
              iVar13 = uVar14 * 0x44;
              piVar5 = (int *)(*(int *)(_p_llm_env + 8) + iVar13);
              if ((char)piVar5[0x10] != '\v') goto _L604;
              iVar3 = *piVar5;
              iVar12 = *(int *)(*(int *)(_p_llm_env + 8) + iVar11);
              iStack_84 = (uint)*(ushort *)(iVar3 + 4) << 1;
              uStack_88 = (uint)*(ushort *)(iVar3 + 2) << 1;
              uStack_80 = r_llm_per_adv_slot_dur
                                    (*(undefined2 *)((int)piVar5 + 0x2a),
                                     *(undefined1 *)(iVar12 + 0x17));
              uStack_76 = 0;
              uStack_7c = uStack_80;
              uStack_78 = (ushort)bVar7;
              iVar11 = r_sch_plan_req(&uStack_88);
              if (iVar11 != 0) break;
              uStack_8c = *(undefined1 *)(iVar12 + 0x17);
              uStack_96 = *(undefined2 *)(iVar3 + 6);
              uStack_98 = (undefined2)(uStack_74 >> 1);
              uStack_90 = (undefined2)uStack_70;
              uStack_94 = *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar13 + 0x28);
              uStack_8e = *(undefined1 *)(iVar12 + 0xb);
              uStack_8d = *(undefined1 *)(iVar12 + 0x14);
              iVar11 = r_lld_per_adv_start(uVar14,&uStack_98);
              if (iVar11 == 0) {
                iVar13 = *(int *)(_p_llm_env + 8) + iVar13;
                *(undefined1 *)(iVar13 + 0x40) = 0xc;
                r_lld_adv_sync_info_update(uVar10,uVar14,uStack_98);
                *(undefined4 *)(iVar13 + 0x14) = uStack_70;
                *(uint *)(iVar13 + 0x10) = uStack_74;
                *(undefined4 *)(iVar13 + 0x18) = uStack_80;
                *(ushort *)(iVar13 + 0x20) = (ushort)bVar7;
                *(undefined4 *)(iVar13 + 0x24) = 0;
                *(undefined4 *)(iVar13 + 0x1c) = uStack_7c;
                *(undefined1 *)(iVar13 + 0x22) = 0;
                r_sch_plan_set(iVar13 + 0xc);
                if ((_bt_rf_coex_hooks_p != (int *)0x0) &&
                   ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
                  (*(code *)*_bt_rf_coex_hooks_p)(uVar14,4,1);
                }
              }
            }
            else {
_L604:
              if ((*(ushort *)(iVar3 + 2) & 1) != 0) {
                iVar13 = r_llm_activity_free_get(&uStack_88);
                if (iVar13 == 0) {
                  iVar13 = *(int *)(_p_llm_env + 8);
                  *(undefined1 *)(iVar11 + iVar13 + 0x3e) = (undefined1)uStack_88;
                  *(undefined1 *)(iVar13 + (uStack_88 & 0xff) * 0x44 + 0x40) = 4;
                }
                else {
                  r_assert_err(0,"llm_adv.c",0x690);
                }
              }
            }
            if (_bt_rf_coex_hooks_p != (int *)0x0) {
              pcVar6 = (code *)*_bt_rf_coex_hooks_p;
              uVar4 = 1;
              if (pcVar6 != (code *)0x0) {
_L687:
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
      goto _L568;
    }
  }
  else {
    psVar2 = param_1;
    if ((char)*param_1 == '\x01') goto _L571;
  }
_L572:
  iVar13 = 0x12;
_L568:
  r_llm_cmd_cmp_send(param_2,iVar13);
  return 0;
}

