/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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
  byte bVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 *puVar7;
  byte *pbVar8;
  int iVar9;
  undefined4 *puVar10;
  int iVar11;
  char cVar12;
  undefined1 uVar13;
  undefined1 *puVar14;
  int iVar15;
  uint uVar16;
  byte bVar17;
  uint uVar18;
  byte bStack_67;
  ushort uStack_66;
  ushort uStack_64;
  undefined2 uStack_62;
  undefined2 uStack_60;
  undefined2 uStack_5e;
  undefined2 uStack_5c;
  undefined2 uStack_5a;
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
  
  uVar16 = (uint)*param_1;
  iVar15 = uVar16 * 0x44;
  bVar17 = param_1[0x35];
  puVar10 = (undefined4 *)(*(int *)(_p_llm_env + 8) + iVar15);
  bStack_67 = *(byte *)((int)puVar10 + 0x3e);
  puVar14 = (undefined1 *)*puVar10;
  if (*(char *)(puVar10 + 0x10) == '\x03') {
    if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
      uVar4 = 0x200a;
_L127:
      r_llm_cmd_cmp_send(uVar4,0);
    }
    else {
      if (*(char *)(_p_llm_env + 0xd6) == '\0') {
        r_assert_err(0,"llm_adv.c",0xa4e);
      }
      cVar12 = *(char *)(_p_llm_env + 0xd6) + -1;
      *(char *)(_p_llm_env + 0xd6) = cVar12;
      if (cVar12 == '\0') {
        uVar4 = 0x2039;
        goto _L127;
      }
    }
    *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar15 + 0x40) = 1;
_L41:
    if ((*(ushort *)(puVar14 + 2) & 1) != 0) {
      iVar9 = *(int *)(_p_llm_env + 8) + iVar15;
      if ((*(char *)(iVar9 + 0x40) != '\x02') || ((uint)*(byte *)(iVar9 + 0x3e) != (uint)bStack_67))
      {
        *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_67 * 0x44 + 0x40) = 0;
      }
    }
    bVar17 = 0;
    if (param_1[1] != 0x3c) goto _L84;
  }
  else {
    if (bVar17 == 0) {
      if ((param_1[1] == 0x3c) || (param_1[1] == 0x43)) {
        *(undefined1 *)(puVar10 + 0x10) = 1;
      }
      goto _L41;
    }
    pbVar8 = param_1 + 0x15;
    iVar9 = r_llm_is_dev_connected(pbVar8,param_1[0x37]);
    if (iVar9 != 0) {
      memset(&uStack_58,0,0x28);
      if ((*(ushort *)(puVar14 + 2) & 0xc) != 0) {
        r_assert_err(0,"llm_adv.c",0xa6a);
      }
      uStack_40 = *(ushort *)(puVar14 + 2);
      uVar2 = uStack_40 & 4;
      uStack_4c = (uint)(byte)puVar14[9] << 0x10 | (uint)(byte)puVar14[8] << 8 |
                  (uint)(byte)puVar14[7];
      uStack_3c = CONCAT13(puVar14[0xc],
                           CONCAT12(puVar14[0xb],CONCAT11(puVar14[10],(undefined1)uStack_3c)));
      memcpy(&bStack_52,puVar14 + 0xd,6);
      uVar13 = 0;
      if (uVar2 == 0) {
        uVar13 = puVar14[0x13];
      }
      bStack_34 = puVar14[0x15];
      uStack_38 = CONCAT13(puVar14[0x16],CONCAT12(bStack_34,CONCAT11(puVar14[0x14],uVar13)));
      uStack_33 = puVar14[0x18];
      bStack_32 = puVar14[0x19];
      iVar9 = *(int *)(_p_llm_env + 8) + iVar15;
      uStack_58 = *(undefined4 *)(iVar9 + 4);
      uStack_54 = *(undefined2 *)(iVar9 + 8);
      uStack_44 = *(undefined2 *)(iVar9 + 0x2a);
      uStack_42 = *(undefined2 *)(iVar9 + 0x34);
      uStack_3c = uStack_3c & 0xffffff00;
      uStack_48 = CONCAT22(*(undefined2 *)(iVar9 + 0x32),*(undefined2 *)(iVar9 + 0x28));
      bStack_31 = *(byte *)(_p_llm_env + 0xc6);
      uStack_3e = 0;
      iVar9 = r_lld_adv_start_eco(uVar16,&uStack_58);
      if (iVar9 == 0) {
        *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar15 + 0x40) = 2;
        if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
           ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
          uVar4 = 0;
          if ((*(ushort *)(puVar14 + 2) & 0x10) == 0) {
            uVar4 = 2;
          }
          (*(code *)*_bt_rf_coex_hooks_p)(uVar16,uVar4,1);
        }
      }
      else {
        r_assert_err(0,"llm_adv.c",0xa98);
      }
      goto _L41;
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
    bStack_31 = ((byte)(*(ushort *)(puVar14 + 2) >> 4) ^ 1) & 1;
    if (bStack_67 == 0xff) {
      r_assert_err("llm_adv.c",0xb2f);
    }
    else {
      if (*(char *)((uint)bStack_67 * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) == '\0') {
        iVar9 = r_llm_activity_free_get(&bStack_67);
        iVar11 = *(int *)(_p_llm_env + 8);
        if (iVar9 == 0) {
          *(byte *)(iVar11 + iVar15 + 0x3e) = bStack_67;
          *(undefined1 *)((uint)bStack_67 * 0x44 + iVar11 + 0x40) = 4;
        }
        else {
          r_assert_param(uVar16,*(undefined1 *)((uint)bStack_67 * 0x44 + iVar11 + 0x40),"llm_adv.c",
                         0xac2);
        }
      }
      r_llc_start_eco(bStack_67,&uStack_58,_p_llm_env + 0x9c);
      if (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bStack_67 * 0x44 + 0x40) != '\x04') {
        r_assert_param("llm_adv.c",0xac9);
      }
      bVar3 = bStack_67;
      iVar9 = _p_llm_env;
      iVar11 = *(int *)(_p_llm_env + 8) + (uint)bStack_67 * 0x44;
      memcpy((void *)(iVar11 + 4),pbVar8,6);
      bVar1 = param_1[0x37];
      *(undefined1 *)(iVar11 + 0x28) = 1;
      *(byte *)(iVar11 + 0x41) = bVar1;
      *(undefined1 *)(iVar11 + 0x40) = 9;
      uVar2 = *(ushort *)(param_1 + 0x1e);
      *(undefined4 *)(iVar11 + 0x14) = 0;
      *(uint *)(iVar11 + 0x10) = (uint)uVar2 << 1;
      *(undefined4 *)(iVar11 + 0x18) = 5;
      *(undefined4 *)(iVar11 + 0x1c) = 5;
      if (*(char *)(iVar9 + 0xd8) == '\0') {
        *(undefined4 *)(iVar11 + 0x24) = 0;
        *(undefined1 *)(iVar11 + 0x22) = 0;
      }
      else {
        *(undefined **)(iVar11 + 0x24) = &r_llc_con_move_cbk;
        *(undefined1 *)(iVar11 + 0x22) = 1;
      }
      *(ushort *)(iVar11 + 0x20) = (ushort)bVar3;
      iVar9 = r_sdk_config_get_opts();
      if (*(char *)(iVar9 + 0x15) == '\x01') {
        uVar13 = *(undefined1 *)(iVar11 + 0x20);
        uVar18 = *(uint *)(iVar11 + 0x1c);
        uVar5 = r_lld_con_evt_duration_min_get(uVar13);
        uVar6 = uVar5 / 0x4e2;
        if (uVar5 / 0x4e2 < uVar18) {
          uVar6 = uVar18;
        }
        *(uint *)(iVar11 + 0x1c) = uVar6;
        uVar18 = *(uint *)(iVar11 + 0x18);
        uVar5 = r_lld_con_evt_duration_min_get(uVar13);
        uVar6 = uVar5 / 0x4e2;
        if (uVar5 / 0x4e2 < uVar18) {
          uVar6 = uVar18;
        }
        *(uint *)(iVar11 + 0x18) = uVar6;
      }
      else {
        iVar9 = r_sdk_config_get_opts();
        if ((*(char *)(iVar9 + 0x15) == '\x02') &&
           (iVar9 = r_lld_con_evt_sd_evt_time_get
                              (*(undefined1 *)(iVar11 + 0x20),&uStack_66,&uStack_64), iVar9 == 0)) {
          *(uint *)(iVar11 + 0x1c) = (uint)uStack_66;
          *(uint *)(iVar11 + 0x18) = (uint)uStack_64;
        }
      }
      if (sdk_cfg_priv_opts != '\0') {
        r_sch_plan_set(iVar11 + 0xc);
      }
      r_lld_res_list_peer_update(pbVar8,param_1[0x37],1);
      uVar6 = r_llm_dev_list_search(pbVar8,param_1[0x37]);
      if ((uVar6 < 0xc) && ((*(byte *)(uVar6 * 10 + _p_llm_env + 0x2d) & 2) != 0)) {
        r_lld_white_list_rem(pbVar8,param_1[0x37]);
      }
      r_hci_ble_conhdl_register(bStack_67);
      *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar15 + 0x40) = 1;
      if (_bt_rf_coex_hooks_p != (undefined4 *)0x0) {
        if ((code *)*_bt_rf_coex_hooks_p != (code *)0x0) {
          uVar4 = 0;
          if ((*(ushort *)(puVar14 + 2) & 0x10) == 0) {
            uVar4 = 2;
          }
          (*(code *)*_bt_rf_coex_hooks_p)(uVar16,uVar4,0);
          (*(code *)*_bt_rf_coex_hooks_p)(bStack_67,7,1,(code *)*_bt_rf_coex_hooks_p);
        }
        if ((code *)_bt_rf_coex_hooks_p[1] != (code *)0x0) {
          uStack_64 = *(ushort *)(param_1 + 0x1e);
          uStack_62 = *(undefined2 *)(param_1 + 0x20);
          uStack_5e = 0;
          uStack_5c = 0;
          uStack_5a = 0;
          uStack_60 = (undefined2)*(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar15 + 0x1c);
          (*(code *)_bt_rf_coex_hooks_p[1])(bStack_67,7,&uStack_64);
        }
      }
    }
  }
  iVar9 = r_llm_le_evt_mask_check(9);
  if (iVar9 == 0) {
    puVar7 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,0x14);
    *puVar7 = 1;
    bVar1 = param_1[0x35];
    uVar13 = 0;
    if (bVar1 == 0) {
      uVar13 = 0x3c;
    }
    puVar7[1] = uVar13;
    if (bVar1 != 0) {
      puVar7[4] = 1;
      *(ushort *)(puVar7 + 2) = (ushort)bStack_67;
      if ((param_1[0x37] & 2) == 0) {
        puVar7[5] = param_1[0x37] & 1;
        pbVar8 = param_1 + 0x15;
      }
      else {
        puVar7[5] = 1;
        pbVar8 = param_1 + 0xf;
      }
      memcpy(puVar7 + 6,pbVar8,6);
      *(undefined2 *)(puVar7 + 0xc) = *(undefined2 *)(param_1 + 0x1e);
      *(undefined2 *)(puVar7 + 0xe) = *(undefined2 *)(param_1 + 0x20);
      *(undefined2 *)(puVar7 + 0x10) = *(undefined2 *)(param_1 + 0x22);
      puVar7[0x12] = param_1[0x2a];
    }
  }
  else {
    puVar7 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,0x20);
    *puVar7 = 10;
    bVar1 = param_1[0x35];
    uVar13 = 0;
    if (bVar1 == 0) {
      uVar13 = 0x3c;
    }
    puVar7[1] = uVar13;
    puVar7[4] = 1;
    *(ushort *)(puVar7 + 2) = (ushort)bStack_67;
    if (bVar1 == 0) {
      puVar7[5] = puVar14[0xc];
      memcpy(puVar7 + 6,puVar14 + 0xd,6);
    }
    else {
      memcpy(puVar7 + 6,param_1 + 0x15,6);
      puVar7[5] = param_1[0x37];
      if ((puVar14[0xb] & 2) == 0) {
        memset(puVar7 + 0xc,0,6);
      }
      else {
        memcpy(puVar7 + 0xc,param_1 + 9,6);
      }
      if ((param_1[0x37] & 2) == 0) {
        memset(puVar7 + 0x12,0,6);
      }
      else {
        memcpy(puVar7 + 0x12,param_1 + 0xf,6);
      }
      *(undefined2 *)(puVar7 + 0x18) = *(undefined2 *)(param_1 + 0x1e);
      *(undefined2 *)(puVar7 + 0x1a) = *(undefined2 *)(param_1 + 0x20);
      *(undefined2 *)(puVar7 + 0x1c) = *(undefined2 *)(param_1 + 0x22);
      puVar7[0x1e] = param_1[0x2a];
    }
  }
  r_hci_send_2_host(puVar7);
  if (param_1[0x35] != 0) {
    puVar7 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,6);
    *puVar7 = 0x14;
    *(ushort *)(puVar7 + 2) = (ushort)bStack_67;
    puVar7[4] = param_1[0x36];
    r_hci_send_2_host();
  }
_L84:
  if ((*(char *)(_p_llm_env + 0xd7) == '\x02') && ((bVar17 != 0 || (param_1[1] != 0)))) {
    puVar7 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,8);
    *puVar7 = 0x12;
    puVar7[1] = param_1[1];
    puVar7[2] = *puVar14;
    *(ushort *)(puVar7 + 4) = (ushort)bStack_67;
    puVar7[6] = param_1[0x38];
    r_hci_send_2_host();
  }
  iVar15 = iVar15 + *(int *)(_p_llm_env + 8);
  if (*(char *)(iVar15 + 0x40) != '\x02') {
    *(undefined1 *)(iVar15 + 0x3e) = 0xff;
  }
  return 0;
}

