/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llm_adv.o -> lld_adv_end_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_adv_end_ind_handler_hack(byte *param_1)

{
  byte bVar1;
  ushort uVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  char cVar10;
  undefined1 uVar11;
  int iVar12;
  int iVar13;
  undefined *puVar14;
  uint uVar15;
  int iVar16;
  byte bVar17;
  uint uVar18;
  byte bStack_67;
  ushort uStack_66;
  ushort uStack_64;
  undefined2 uStack_62;
  uint uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined2 uStack_54;
  byte bStack_52;
  byte bStack_51;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  undefined2 uStack_42;
  ushort uStack_40;
  undefined2 uStack_3e;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  byte bStack_34;
  undefined1 uStack_33;
  byte bStack_32;
  byte bStack_31;
  
  bVar1 = *param_1;
  uVar15 = (uint)bVar1;
  iVar16 = uVar15 * 0x44;
  bVar17 = param_1[0x35];
  puVar9 = (undefined4 *)(*(int *)(_p_llm_env + 8) + iVar16);
  bStack_67 = *(byte *)((int)puVar9 + 0x3e);
  puVar3 = (undefined1 *)*puVar9;
  r_ble_log_internal_x1
            (0x406e01b6,
             CONCAT13(*(undefined1 *)(puVar9 + 0x10),CONCAT12(bStack_67,CONCAT11(bVar17,bVar1))));
  iVar12 = *(int *)(_p_llm_env + 8) + iVar16;
  if (*(char *)(iVar12 + 0x40) == '\x03') {
    if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
      uVar4 = 0x200a;
_L130:
      r_llm_cmd_cmp_send(uVar4,0);
    }
    else {
      if (*(char *)(_p_llm_env + 0xd6) == '\0') {
        r_assert_err(0,"llm_adv.c",0xadd);
      }
      cVar10 = *(char *)(_p_llm_env + 0xd6) + -1;
      *(char *)(_p_llm_env + 0xd6) = cVar10;
      if (cVar10 == '\0') {
        uVar4 = 0x2039;
        goto _L130;
      }
    }
    uVar15 = uVar15 | 0x100;
    uVar4 = 0x404e01b7;
    *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar16 + 0x40) = 1;
_L133:
    r_ble_log_internal_x1(uVar4,uVar15);
_L43:
    if ((*(ushort *)(puVar3 + 2) & 1) != 0) {
      iVar12 = *(int *)(_p_llm_env + 8) + iVar16;
      if ((*(char *)(iVar12 + 0x40) != '\x02') ||
         ((uint)*(byte *)(iVar12 + 0x3e) != (uint)bStack_67)) {
        *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_67 * 0x44 + 0x40) = 0;
        r_ble_log_internal_x1(0x404e01c0,CONCAT11(*(undefined1 *)(iVar12 + 0x40),bVar1));
      }
    }
    bVar17 = 0;
    if (param_1[1] != 0x3c) goto _L73;
  }
  else {
    if (bVar17 == 0) {
      if ((param_1[1] != 0x3c) && (param_1[1] != 0x43)) goto _L43;
      *(undefined1 *)(iVar12 + 0x40) = 1;
      uVar15 = uVar15 | 0x100;
      uVar4 = 0x404e01bf;
      goto _L133;
    }
    pbVar8 = param_1 + 0x15;
    iVar12 = r_llm_is_dev_connected(pbVar8,param_1[0x37]);
    if (iVar12 != 0) {
      memset(&uStack_58,0,0x28);
      r_ble_log_internal_x1(0x606e01b8,param_1[0x37]);
      r_ble_log_internal_hex(0x606e01b9,6,pbVar8);
      if ((*(ushort *)(puVar3 + 2) & 0xc) != 0) {
        r_assert_err(0,"llm_adv.c",0xafc);
      }
      uStack_40 = *(ushort *)(puVar3 + 2);
      uVar2 = uStack_40 & 4;
      uStack_4c = (uint)(byte)puVar3[9] << 0x10 | (uint)(byte)puVar3[8] << 8 | (uint)(byte)puVar3[7]
      ;
      uStack_3c = CONCAT13(puVar3[0xc],
                           CONCAT12(puVar3[0xb],CONCAT11(puVar3[10],(undefined1)uStack_3c)));
      memcpy(&bStack_52,puVar3 + 0xd,6);
      uVar11 = 0;
      if (uVar2 == 0) {
        uVar11 = puVar3[0x13];
      }
      bStack_34 = puVar3[0x15];
      uStack_38 = CONCAT13(puVar3[0x16],CONCAT12(bStack_34,CONCAT11(puVar3[0x14],uVar11)));
      uStack_33 = puVar3[0x18];
      bStack_32 = puVar3[0x19];
      iVar12 = *(int *)(_p_llm_env + 8) + iVar16;
      uStack_58 = *(undefined4 *)(iVar12 + 4);
      uStack_54 = *(undefined2 *)(iVar12 + 8);
      uStack_44 = *(undefined2 *)(iVar12 + 0x2a);
      uStack_42 = *(undefined2 *)(iVar12 + 0x34);
      uStack_3c = uStack_3c & 0xffffff00;
      uStack_48 = CONCAT22(*(undefined2 *)(iVar12 + 0x32),*(undefined2 *)(iVar12 + 0x28));
      bStack_31 = *(byte *)(_p_llm_env + 0xc6);
      uStack_3e = 0;
      iVar12 = r_lld_adv_start_eco(uVar15,&uStack_58);
      if (iVar12 == 0) {
        *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar16 + 0x40) = 2;
        if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
           ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
          uVar4 = 0;
          if ((*(ushort *)(puVar3 + 2) & 0x10) == 0) {
            uVar4 = 2;
          }
          (*(code *)*_bt_rf_coex_hooks_p)(uVar15,uVar4,1);
        }
        uVar4 = 0x404e01ba;
        uVar15 = (uint)CONCAT11(*(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar16 + 0x40),bVar1);
        goto _L133;
      }
      r_assert_err(0,"llm_adv.c",0xb2b);
      goto _L43;
    }
    uStack_38 = 0;
    uStack_58 = *(undefined4 *)(param_1 + 2);
    uStack_54 = *(undefined2 *)(param_1 + 6);
    bStack_52 = param_1[8];
    bStack_51 = param_1[0x1b];
    uStack_50 = *(undefined4 *)(param_1 + 0x1c);
    uStack_4c = *(uint *)(param_1 + 0x20);
    uStack_48 = *(undefined4 *)(param_1 + 0x24);
    uStack_44 = *(undefined2 *)(param_1 + 0x28);
    uStack_42 = CONCAT11(uStack_42._1_1_,param_1[0x2a]);
    uStack_40 = *(ushort *)(param_1 + 0x2c);
    uStack_3c = *(uint *)(param_1 + 0x30);
    uStack_33 = 1;
    bStack_34 = param_1[0x34];
    bStack_32 = param_1[0x36];
    bStack_31 = ((byte)(*(ushort *)(puVar3 + 2) >> 4) ^ 1) & 1;
    r_ble_log_internal_x1(0x406e01bb,param_1[0x37]);
    r_ble_log_internal_hex(0x406e01bc,6,pbVar8);
    if (bStack_67 == 0xff) {
      r_assert_err(0,"llm_adv.c",0xbc9);
    }
    else {
      if (*(char *)((uint)bStack_67 * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) == '\0') {
        iVar12 = r_llm_activity_free_get(&bStack_67);
        uVar7 = (uint)bStack_67;
        iVar13 = *(int *)(_p_llm_env + 8);
        if (iVar12 == 0) {
          *(byte *)(iVar13 + iVar16 + 0x3e) = bStack_67;
          *(undefined1 *)(iVar13 + uVar7 * 0x44 + 0x40) = 4;
          r_ble_log_internal_x1(0x404e01bd,uVar7 | 0x400);
        }
        else {
          r_assert_param(uVar15,*(undefined1 *)(iVar13 + uVar7 * 0x44 + 0x40),"llm_adv.c",0xb5a);
        }
      }
      r_llc_start_eco_hack(bStack_67,&uStack_58,_p_llm_env + 0x9c);
      if (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bStack_67 * 0x44 + 0x40) != '\x04') {
        r_assert_param("llm_adv.c",0xb61);
      }
      uVar7 = (uint)bStack_67;
      iVar12 = *(int *)(_p_llm_env + 8) + uVar7 * 0x44;
      memcpy((void *)(iVar12 + 4),pbVar8,6);
      *(byte *)(iVar12 + 0x41) = param_1[0x37];
      *(undefined1 *)(iVar12 + 0x40) = 9;
      *(undefined1 *)(iVar12 + 0x28) = 1;
      r_ble_log_internal_x1(0x404e01be,uVar7 | 0x900);
      iVar12 = _p_llm_env;
      iVar13 = *(int *)(_p_llm_env + 8) + (uint)bStack_67 * 0x44;
      *(uint *)(iVar13 + 0x10) = (uint)*(ushort *)(param_1 + 0x1e) << 1;
      *(undefined4 *)(iVar13 + 0x18) = 5;
      *(undefined4 *)(iVar13 + 0x1c) = 5;
      *(undefined4 *)(iVar13 + 0x14) = 0;
      cVar10 = *(char *)(iVar12 + 0xd8);
      puVar14 = (undefined *)0x0;
      if (cVar10 != '\0') {
        puVar14 = &r_llc_con_move_cbk;
        cVar10 = '\x01';
      }
      *(undefined **)(iVar13 + 0x24) = puVar14;
      *(char *)(iVar13 + 0x22) = cVar10;
      *(ushort *)(iVar13 + 0x20) = (ushort)bStack_67;
      iVar12 = r_sdk_config_get_opts();
      if (*(char *)(iVar12 + 0x15) == '\x01') {
        uVar11 = *(undefined1 *)(iVar13 + 0x20);
        uVar18 = *(uint *)(iVar13 + 0x1c);
        uVar6 = r_lld_con_evt_duration_min_get(uVar11);
        uVar7 = uVar6 / 0x4e2;
        if (uVar6 / 0x4e2 < uVar18) {
          uVar7 = uVar18;
        }
        *(uint *)(iVar13 + 0x1c) = uVar7;
        uVar18 = *(uint *)(iVar13 + 0x18);
        uVar6 = r_lld_con_evt_duration_min_get(uVar11);
        uVar7 = uVar6 / 0x4e2;
        if (uVar6 / 0x4e2 < uVar18) {
          uVar7 = uVar18;
        }
        *(uint *)(iVar13 + 0x18) = uVar7;
      }
      else {
        iVar12 = r_sdk_config_get_opts();
        if ((*(char *)(iVar12 + 0x15) == '\x02') &&
           (iVar12 = r_lld_con_evt_sd_evt_time_get
                               (*(undefined1 *)(iVar13 + 0x20),&uStack_66,&uStack_64), iVar12 == 0))
        {
          *(uint *)(iVar13 + 0x1c) = (uint)uStack_66;
          *(uint *)(iVar13 + 0x18) = (uint)uStack_64;
        }
      }
      if (sdk_cfg_priv_opts != '\0') {
        r_sch_plan_set_hack(iVar13 + 0xc);
      }
      r_lld_res_list_peer_update_hack(pbVar8,param_1[0x37],1);
      uVar7 = r_llm_dev_list_search(pbVar8,param_1[0x37]);
      if (uVar7 < 0xc) {
        if ((*(byte *)(uVar7 * 10 + _p_llm_env + 0x2d) & 2) != 0) {
          r_lld_white_list_rem(pbVar8,param_1[0x37]);
        }
      }
      r_hci_ble_conhdl_register(bStack_67);
      *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar16 + 0x40) = 1;
      if (_bt_rf_coex_hooks_p != (undefined4 *)0x0) {
        if ((code *)*_bt_rf_coex_hooks_p != (code *)0x0) {
          uVar4 = 0;
          if ((*(ushort *)(puVar3 + 2) & 0x10) == 0) {
            uVar4 = 2;
          }
          (*(code *)*_bt_rf_coex_hooks_p)(uVar15,uVar4,0);
          (*(code *)*_bt_rf_coex_hooks_p)(bStack_67,7,1,(code *)*_bt_rf_coex_hooks_p);
        }
        if ((code *)_bt_rf_coex_hooks_p[1] != (code *)0x0) {
          uStack_64 = *(ushort *)(param_1 + 0x1e);
          uStack_62 = *(undefined2 *)(param_1 + 0x20);
          uStack_5c = 0;
          uStack_60 = *(uint *)(*(int *)(_p_llm_env + 8) + iVar16 + 0x1c) & 0xffff;
          (*(code *)_bt_rf_coex_hooks_p[1])(bStack_67,7,&uStack_64);
        }
      }
    }
  }
  iVar12 = r_llm_le_evt_mask_check(9);
  if (iVar12 == 0) {
    puVar5 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,0x14);
    *puVar5 = 1;
    bVar1 = param_1[0x35];
    uVar11 = 0;
    if (bVar1 == 0) {
      uVar11 = 0x3c;
    }
    puVar5[1] = uVar11;
    if (bVar1 != 0) {
      puVar5[4] = 1;
      *(ushort *)(puVar5 + 2) = (ushort)bStack_67;
      if ((param_1[0x37] & 2) == 0) {
        puVar5[5] = param_1[0x37] & 1;
        pbVar8 = param_1 + 0x15;
      }
      else {
        puVar5[5] = 1;
        pbVar8 = param_1 + 0xf;
      }
      memcpy(puVar5 + 6,pbVar8,6);
      *(undefined2 *)(puVar5 + 0xc) = *(undefined2 *)(param_1 + 0x1e);
      *(undefined2 *)(puVar5 + 0xe) = *(undefined2 *)(param_1 + 0x20);
      *(undefined2 *)(puVar5 + 0x10) = *(undefined2 *)(param_1 + 0x22);
      puVar5[0x12] = param_1[0x2a];
    }
  }
  else {
    puVar5 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,0x20);
    *puVar5 = 10;
    bVar1 = param_1[0x35];
    uVar11 = 0;
    if (bVar1 == 0) {
      uVar11 = 0x3c;
    }
    puVar5[1] = uVar11;
    puVar5[4] = 1;
    *(ushort *)(puVar5 + 2) = (ushort)bStack_67;
    if (bVar1 == 0) {
      puVar5[5] = puVar3[0xc];
      memcpy(puVar5 + 6,puVar3 + 0xd,6);
    }
    else {
      memcpy(puVar5 + 6,param_1 + 0x15,6);
      puVar5[5] = param_1[0x37];
      if ((puVar3[0xb] & 2) == 0) {
        memset(puVar5 + 0xc,0,6);
      }
      else {
        memcpy(puVar5 + 0xc,param_1 + 9,6);
      }
      if ((param_1[0x37] & 2) == 0) {
        memset(puVar5 + 0x12,0,6);
      }
      else {
        memcpy(puVar5 + 0x12,param_1 + 0xf,6);
      }
      *(undefined2 *)(puVar5 + 0x18) = *(undefined2 *)(param_1 + 0x1e);
      *(undefined2 *)(puVar5 + 0x1a) = *(undefined2 *)(param_1 + 0x20);
      *(undefined2 *)(puVar5 + 0x1c) = *(undefined2 *)(param_1 + 0x22);
      puVar5[0x1e] = param_1[0x2a];
    }
  }
  r_hci_send_2_host(puVar5);
  if (param_1[0x35] != 0) {
    puVar5 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,6);
    *puVar5 = 0x14;
    *(ushort *)(puVar5 + 2) = (ushort)bStack_67;
    puVar5[4] = param_1[0x36];
    r_hci_send_2_host();
  }
_L73:
  if ((*(char *)(_p_llm_env + 0xd7) == '\x02') && ((bVar17 != 0 || (param_1[1] != 0)))) {
    puVar5 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,8);
    *puVar5 = 0x12;
    puVar5[1] = param_1[1];
    puVar5[2] = *puVar3;
    *(ushort *)(puVar5 + 4) = (ushort)bStack_67;
    puVar5[6] = param_1[0x38];
    r_hci_send_2_host();
  }
  iVar16 = *(int *)(_p_llm_env + 8) + iVar16;
  if (*(char *)(iVar16 + 0x40) != '\x02') {
    *(undefined1 *)(iVar16 + 0x3e) = 0xff;
  }
  return 0;
}

