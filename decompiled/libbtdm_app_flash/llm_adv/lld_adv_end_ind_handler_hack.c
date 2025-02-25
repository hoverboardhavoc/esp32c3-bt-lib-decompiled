/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
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
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  int iVar10;
  char cVar11;
  undefined1 uVar12;
  undefined4 *puVar13;
  undefined1 *puVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
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
  uVar17 = (uint)param_1[0x35];
  puVar13 = (undefined4 *)(*(int *)(_p_llm_env + 8) + iVar15);
  puVar14 = (undefined1 *)*puVar13;
  bStack_67 = *(byte *)((int)puVar13 + 0x3e);
  iVar4 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar4 + 0x28) & 4) != 0) &&
     (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 3)) {
    r_ble_log_internal_x1
              (0x40e00019,
               (uint)*(byte *)(*(int *)(_p_llm_env + 8) + iVar15 + 0x40) << 0x18 |
               (uint)bStack_67 << 0x10 | uVar16 | uVar17 << 8);
  }
  iVar4 = *(int *)(_p_llm_env + 8) + iVar15;
  if (*(char *)(iVar4 + 0x40) == '\x03') {
    if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
      uVar5 = 0x200a;
_L136:
      r_llm_cmd_cmp_send(uVar5,0);
    }
    else {
      if (*(char *)(_p_llm_env + 0xd6) == '\0') {
        r_assert_err(0,"llm_adv.c",0xa4f);
      }
      cVar11 = *(char *)(_p_llm_env + 0xd6) + -1;
      *(char *)(_p_llm_env + 0xd6) = cVar11;
      if (cVar11 == '\0') {
        uVar5 = 0x2039;
        goto _L136;
      }
    }
    iVar4 = *(int *)(_p_llm_env + 8) + iVar15;
_L77:
    *(undefined1 *)(iVar4 + 0x40) = 1;
_L44:
    if ((*(ushort *)(puVar14 + 2) & 1) != 0) {
      iVar4 = *(int *)(_p_llm_env + 8) + iVar15;
      if ((*(char *)(iVar4 + 0x40) != '\x02') || ((uint)*(byte *)(iVar4 + 0x3e) != (uint)bStack_67))
      {
        *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_67 * 0x44 + 0x40) = 0;
      }
    }
    uVar17 = 0;
    if (param_1[1] != 0x3c) goto _L93;
  }
  else {
    if (uVar17 == 0) {
      if ((param_1[1] != 0x3c) && (param_1[1] != 0x43)) goto _L44;
      goto _L77;
    }
    pbVar9 = param_1 + 0x15;
    iVar4 = r_llm_is_dev_connected(pbVar9,param_1[0x37]);
    if (iVar4 != 0) {
      memset(&uStack_58,0,0x28);
      iVar4 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar4 + 0x28) & 4) != 0) &&
         (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 3)) {
        r_ble_log_internal_hex(0x40e0001b,6,pbVar9);
      }
      if ((*(ushort *)(puVar14 + 2) & 0xc) != 0) {
        r_assert_err(0,"llm_adv.c",0xa6c);
      }
      uStack_40 = *(ushort *)(puVar14 + 2);
      uVar2 = uStack_40 & 4;
      uStack_4c = (uint)(byte)puVar14[9] << 0x10 | (uint)(byte)puVar14[8] << 8 |
                  (uint)(byte)puVar14[7];
      uStack_3c = CONCAT13(puVar14[0xc],
                           CONCAT12(puVar14[0xb],CONCAT11(puVar14[10],(undefined1)uStack_3c)));
      memcpy(&bStack_52,puVar14 + 0xd,6);
      uVar12 = 0;
      if (uVar2 == 0) {
        uVar12 = puVar14[0x13];
      }
      bStack_34 = puVar14[0x15];
      uStack_38 = CONCAT13(puVar14[0x16],CONCAT12(bStack_34,CONCAT11(puVar14[0x14],uVar12)));
      uStack_33 = puVar14[0x18];
      bStack_32 = puVar14[0x19];
      iVar4 = *(int *)(_p_llm_env + 8) + iVar15;
      uStack_58 = *(undefined4 *)(iVar4 + 4);
      uStack_54 = *(undefined2 *)(iVar4 + 8);
      uStack_44 = *(undefined2 *)(iVar4 + 0x2a);
      uStack_42 = *(undefined2 *)(iVar4 + 0x34);
      uStack_3c = uStack_3c & 0xffffff00;
      uStack_48 = CONCAT22(*(undefined2 *)(iVar4 + 0x32),*(undefined2 *)(iVar4 + 0x28));
      bStack_31 = *(byte *)(_p_llm_env + 0xc6);
      uStack_3e = 0;
      iVar4 = r_lld_adv_start_eco(uVar16,&uStack_58);
      if (iVar4 == 0) {
        *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar15 + 0x40) = 2;
        if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
           ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
          uVar5 = 0;
          if ((*(ushort *)(puVar14 + 2) & 0x10) == 0) {
            uVar5 = 2;
          }
          (*(code *)*_bt_rf_coex_hooks_p)(uVar16,uVar5,1);
        }
      }
      else {
        r_assert_err(0,"llm_adv.c",0xa9a);
      }
      goto _L44;
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
    iVar4 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar4 + 0x28) & 4) != 0) &&
       (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 3)) {
      r_ble_log_internal_hex(0x40e0001a,6,pbVar9);
    }
    if (bStack_67 == 0xff) {
      r_assert_err(0,"llm_adv.c",0xb33);
    }
    else {
      if (*(char *)((uint)bStack_67 * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) == '\0') {
        iVar4 = r_llm_activity_free_get(&bStack_67);
        iVar10 = *(int *)(_p_llm_env + 8);
        if (iVar4 == 0) {
          *(byte *)(iVar10 + iVar15 + 0x3e) = bStack_67;
          *(undefined1 *)((uint)bStack_67 * 0x44 + iVar10 + 0x40) = 4;
        }
        else {
          r_assert_param(uVar16,*(undefined1 *)((uint)bStack_67 * 0x44 + iVar10 + 0x40),"llm_adv.c",
                         0xac6);
        }
      }
      r_llc_start_eco(bStack_67,&uStack_58,_p_llm_env + 0x9c);
      if (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bStack_67 * 0x44 + 0x40) != '\x04') {
        r_assert_param("llm_adv.c",0xacd);
      }
      bVar3 = bStack_67;
      iVar4 = _p_llm_env;
      iVar10 = *(int *)(_p_llm_env + 8) + (uint)bStack_67 * 0x44;
      memcpy((void *)(iVar10 + 4),pbVar9,6);
      bVar1 = param_1[0x37];
      *(undefined1 *)(iVar10 + 0x28) = 1;
      *(byte *)(iVar10 + 0x41) = bVar1;
      *(undefined1 *)(iVar10 + 0x40) = 9;
      uVar2 = *(ushort *)(param_1 + 0x1e);
      *(undefined4 *)(iVar10 + 0x14) = 0;
      *(uint *)(iVar10 + 0x10) = (uint)uVar2 << 1;
      *(undefined4 *)(iVar10 + 0x18) = 5;
      *(undefined4 *)(iVar10 + 0x1c) = 5;
      if (*(char *)(iVar4 + 0xd8) == '\0') {
        *(undefined4 *)(iVar10 + 0x24) = 0;
        *(undefined1 *)(iVar10 + 0x22) = 0;
      }
      else {
        *(undefined **)(iVar10 + 0x24) = &r_llc_con_move_cbk;
        *(undefined1 *)(iVar10 + 0x22) = 1;
      }
      *(ushort *)(iVar10 + 0x20) = (ushort)bVar3;
      iVar4 = r_sdk_config_get_opts();
      if (*(char *)(iVar4 + 0x15) == '\x01') {
        uVar12 = *(undefined1 *)(iVar10 + 0x20);
        uVar18 = *(uint *)(iVar10 + 0x1c);
        uVar6 = r_lld_con_evt_duration_min_get(uVar12);
        uVar7 = uVar6 / 0x4e2;
        if (uVar6 / 0x4e2 < uVar18) {
          uVar7 = uVar18;
        }
        *(uint *)(iVar10 + 0x1c) = uVar7;
        uVar18 = *(uint *)(iVar10 + 0x18);
        uVar6 = r_lld_con_evt_duration_min_get(uVar12);
        uVar7 = uVar6 / 0x4e2;
        if (uVar6 / 0x4e2 < uVar18) {
          uVar7 = uVar18;
        }
        *(uint *)(iVar10 + 0x18) = uVar7;
      }
      else {
        iVar4 = r_sdk_config_get_opts();
        if ((*(char *)(iVar4 + 0x15) == '\x02') &&
           (iVar4 = r_lld_con_evt_sd_evt_time_get
                              (*(undefined1 *)(iVar10 + 0x20),&uStack_66,&uStack_64), iVar4 == 0)) {
          *(uint *)(iVar10 + 0x1c) = (uint)uStack_66;
          *(uint *)(iVar10 + 0x18) = (uint)uStack_64;
        }
      }
      if (sdk_cfg_priv_opts != '\0') {
        r_sch_plan_set(iVar10 + 0xc);
      }
      r_lld_res_list_peer_update(pbVar9,param_1[0x37],1);
      uVar7 = r_llm_dev_list_search(pbVar9,param_1[0x37]);
      if ((uVar7 < 0xc) && ((*(byte *)(uVar7 * 10 + _p_llm_env + 0x2d) & 2) != 0)) {
        r_lld_white_list_rem(pbVar9,param_1[0x37]);
      }
      r_hci_ble_conhdl_register(bStack_67);
      *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar15 + 0x40) = 1;
      if (_bt_rf_coex_hooks_p != (undefined4 *)0x0) {
        if ((code *)*_bt_rf_coex_hooks_p != (code *)0x0) {
          uVar5 = 0;
          if ((*(ushort *)(puVar14 + 2) & 0x10) == 0) {
            uVar5 = 2;
          }
          (*(code *)*_bt_rf_coex_hooks_p)(uVar16,uVar5,0);
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
  iVar4 = r_llm_le_evt_mask_check(9);
  if (iVar4 == 0) {
    puVar8 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,0x14);
    *puVar8 = 1;
    bVar1 = param_1[0x35];
    uVar12 = 0;
    if (bVar1 == 0) {
      uVar12 = 0x3c;
    }
    puVar8[1] = uVar12;
    if (bVar1 != 0) {
      puVar8[4] = 1;
      *(ushort *)(puVar8 + 2) = (ushort)bStack_67;
      if ((param_1[0x37] & 2) == 0) {
        puVar8[5] = param_1[0x37] & 1;
        pbVar9 = param_1 + 0x15;
      }
      else {
        puVar8[5] = 1;
        pbVar9 = param_1 + 0xf;
      }
      memcpy(puVar8 + 6,pbVar9,6);
      *(undefined2 *)(puVar8 + 0xc) = *(undefined2 *)(param_1 + 0x1e);
      *(undefined2 *)(puVar8 + 0xe) = *(undefined2 *)(param_1 + 0x20);
      *(undefined2 *)(puVar8 + 0x10) = *(undefined2 *)(param_1 + 0x22);
      puVar8[0x12] = param_1[0x2a];
    }
  }
  else {
    puVar8 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,0x20);
    *puVar8 = 10;
    bVar1 = param_1[0x35];
    uVar12 = 0;
    if (bVar1 == 0) {
      uVar12 = 0x3c;
    }
    puVar8[1] = uVar12;
    puVar8[4] = 1;
    *(ushort *)(puVar8 + 2) = (ushort)bStack_67;
    if (bVar1 == 0) {
      puVar8[5] = puVar14[0xc];
      memcpy(puVar8 + 6,puVar14 + 0xd,6);
    }
    else {
      memcpy(puVar8 + 6,param_1 + 0x15,6);
      puVar8[5] = param_1[0x37];
      if ((puVar14[0xb] & 2) == 0) {
        memset(puVar8 + 0xc,0,6);
      }
      else {
        memcpy(puVar8 + 0xc,param_1 + 9,6);
      }
      if ((param_1[0x37] & 2) == 0) {
        memset(puVar8 + 0x12,0,6);
      }
      else {
        memcpy(puVar8 + 0x12,param_1 + 0xf,6);
      }
      *(undefined2 *)(puVar8 + 0x18) = *(undefined2 *)(param_1 + 0x1e);
      *(undefined2 *)(puVar8 + 0x1a) = *(undefined2 *)(param_1 + 0x20);
      *(undefined2 *)(puVar8 + 0x1c) = *(undefined2 *)(param_1 + 0x22);
      puVar8[0x1e] = param_1[0x2a];
    }
  }
  r_hci_send_2_host(puVar8);
  if (param_1[0x35] != 0) {
    puVar8 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,6);
    *puVar8 = 0x14;
    *(ushort *)(puVar8 + 2) = (ushort)bStack_67;
    puVar8[4] = param_1[0x36];
    r_hci_send_2_host();
  }
_L93:
  if ((*(char *)(_p_llm_env + 0xd7) == '\x02') && ((uVar17 != 0 || (param_1[1] != 0)))) {
    puVar8 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,8);
    *puVar8 = 0x12;
    puVar8[1] = param_1[1];
    puVar8[2] = *puVar14;
    *(ushort *)(puVar8 + 4) = (ushort)bStack_67;
    puVar8[6] = param_1[0x38];
    r_hci_send_2_host();
  }
  iVar15 = iVar15 + *(int *)(_p_llm_env + 8);
  if (*(char *)(iVar15 + 0x40) != '\x02') {
    *(undefined1 *)(iVar15 + 0x3e) = 0xff;
  }
  return 0;
}

