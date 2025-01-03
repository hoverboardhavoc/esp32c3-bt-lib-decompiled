/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
 * Source: libbtdm_app_flash -> llm_init.o -> lld_init_end_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_init_end_ind_handler(byte *param_1)

{
  byte bVar1;
  undefined1 uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined1 *puVar8;
  undefined4 uVar9;
  int *piVar10;
  uint uVar11;
  ushort uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  byte bVar16;
  int iVar17;
  byte *pbVar18;
  uint uVar19;
  ushort uStack_76;
  ushort uStack_74;
  undefined2 uStack_72;
  undefined2 uStack_70;
  undefined2 uStack_6e;
  undefined2 uStack_6c;
  undefined2 uStack_6a;
  undefined1 auStack_68 [4];
  undefined1 auStack_64 [3];
  undefined1 uStack_61;
  undefined2 uStack_60;
  undefined2 uStack_5e;
  undefined2 uStack_5c;
  undefined2 uStack_5a;
  undefined1 auStack_58 [5];
  byte bStack_53;
  byte bStack_52;
  undefined2 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  byte bStack_44;
  undefined1 uStack_43;
  byte bStack_42;
  
  bVar1 = *param_1;
  uVar13 = (uint)bVar1;
  uVar14 = (uint)param_1[0x26];
  bVar16 = param_1[1];
  iVar5 = r_sdk_config_get_opts();
  if (*(byte *)(iVar5 + 0xd) <= uVar13) {
    r_assert_param(uVar13,0,"llm_init.c",0x288);
  }
  iVar5 = uVar13 * 0x44;
  piVar10 = (int *)(*(int *)(_p_llm_env + 8) + iVar5);
  if ((char)piVar10[0x10] == '\x05') {
    iVar15 = *piVar10;
    uVar12 = (ushort)bVar1;
    if (iVar15 == 0) {
      r_llm_cmd_cmp_send(0x200e,0);
      bVar16 = 0;
      *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar5 + 0x40) = 0;
    }
    else {
      if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
         ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
        uVar9 = 3;
        if (*(char *)(_p_llm_env + 0xd7) != '\x02') {
          uVar9 = 1;
        }
        (*(code *)*_bt_rf_coex_hooks_p)(uVar13,uVar9,0);
      }
      iVar6 = _p_llm_env;
      if (bVar16 == 0) {
        *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar5 + 0x40) = 0;
      }
      else {
        memcpy(auStack_68,param_1 + 0x14,4);
        memcpy(auStack_64,param_1 + 0x2c,3);
        uStack_5e = *(undefined2 *)(param_1 + 0x18);
        iVar17 = uVar14 * 0x10 + iVar15;
        uStack_5c = *(undefined2 *)(iVar17 + 0x12);
        uStack_5a = *(undefined2 *)(iVar17 + 0x14);
        uStack_61 = 0;
        bStack_53 = param_1[0x30];
        uStack_60 = 0;
        memcpy(auStack_58,(void *)(iVar6 + 0x1d),5);
        bStack_52 = param_1[0x31];
        uStack_48 = *(undefined4 *)(param_1 + 0x1c);
        uStack_50 = 0;
        bStack_44 = param_1[0x27];
        uStack_4c = 0;
        uStack_43 = 0;
        bStack_42 = param_1[0x34];
        r_llc_start_eco(uVar13,auStack_68,iVar6 + 0x9c);
        if (*(char *)(_p_llm_env + 0x22) == '\0') {
          *(undefined1 *)(_p_llm_env + 0x22) = 1;
          r_ke_timer_set(4,0,(uint)_sdk_cfg_priv_opts * 100);
        }
        iVar6 = _p_llm_env;
        iVar4 = *(int *)(_p_llm_env + 8) + iVar5;
        *(uint *)(iVar4 + 0x14) = (uint)*(ushort *)(param_1 + 0x1a);
        *(uint *)(iVar4 + 0x10) = (uint)*(ushort *)(param_1 + 0x18) << 1;
        uVar11 = (uint)*(ushort *)(iVar17 + 0x16);
        if (uVar11 < 2) {
          uVar11 = 2;
        }
        uVar3 = *(ushort *)(iVar17 + 0x18);
        *(uint *)(iVar4 + 0x18) = uVar11;
        uVar7 = (uint)uVar3;
        if (uVar3 < uVar11) {
          uVar7 = uVar11;
        }
        *(uint *)(iVar4 + 0x1c) = uVar7;
        *(ushort *)(iVar4 + 0x20) = uVar12;
        if (*(char *)(iVar6 + 0xd8) == '\0') {
          *(undefined4 *)(iVar4 + 0x24) = 0;
          *(undefined1 *)(iVar4 + 0x22) = 0;
        }
        else {
          *(undefined **)(iVar4 + 0x24) = &r_llc_con_move_cbk;
          *(undefined1 *)(iVar4 + 0x22) = 4;
        }
        iVar6 = r_sdk_config_get_opts();
        if (*(char *)(iVar6 + 0x15) == '\x01') {
          uVar2 = *(undefined1 *)(iVar4 + 0x20);
          uVar19 = *(uint *)(iVar4 + 0x1c);
          uVar7 = r_lld_con_evt_duration_min_get(uVar2);
          uVar11 = uVar7 / 0x4e2;
          if (uVar7 / 0x4e2 < uVar19) {
            uVar11 = uVar19;
          }
          *(uint *)(iVar4 + 0x1c) = uVar11;
          uVar19 = *(uint *)(iVar4 + 0x18);
          uVar7 = r_lld_con_evt_duration_min_get(uVar2);
          uVar11 = uVar7 / 0x4e2;
          if (uVar7 / 0x4e2 < uVar19) {
            uVar11 = uVar19;
          }
          *(uint *)(iVar4 + 0x18) = uVar11;
        }
        else {
          iVar6 = r_sdk_config_get_opts();
          if ((*(char *)(iVar6 + 0x15) == '\x02') &&
             (iVar6 = r_lld_con_evt_sd_evt_time_get
                                (*(undefined1 *)(iVar4 + 0x20),&uStack_76,&uStack_74), iVar6 == 0))
          {
            *(uint *)(iVar4 + 0x1c) = (uint)uStack_76;
            *(uint *)(iVar4 + 0x18) = (uint)uStack_74;
          }
        }
        r_sch_plan_set(iVar4 + 0xc);
        pbVar18 = param_1 + 0xe;
        iVar6 = *(int *)(_p_llm_env + 8) + iVar5;
        memcpy((void *)(iVar6 + 4),pbVar18,6);
        bVar1 = param_1[0x20];
        *(undefined1 *)(iVar6 + 0x28) = 0;
        *(byte *)(iVar6 + 0x41) = bVar1 & 1;
        *(undefined1 *)(iVar6 + 0x40) = 9;
        r_lld_res_list_peer_update(pbVar18,1);
        uVar11 = r_llm_dev_list_search(pbVar18,param_1[0x20]);
        if (uVar11 < 0xc) {
          if ((*(byte *)(uVar11 * 10 + _p_llm_env + 0x2d) & 2) != 0) {
            r_lld_white_list_rem(pbVar18,param_1[0x20]);
          }
        }
        r_hci_ble_conhdl_register(uVar13);
        if (_bt_rf_coex_hooks_p != (undefined4 *)0x0) {
          if ((code *)*_bt_rf_coex_hooks_p != (code *)0x0) {
            (*(code *)*_bt_rf_coex_hooks_p)(uVar13,7,1);
          }
          if ((code *)_bt_rf_coex_hooks_p[1] != (code *)0x0) {
            uStack_74 = *(ushort *)(param_1 + 0x18);
            uStack_72 = *(undefined2 *)(iVar17 + 0x12);
            uStack_6c = 0;
            uStack_70 = (undefined2)*(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar5 + 0x1c);
            uStack_6a = 0;
            uStack_6e = 1;
            (*(code *)_bt_rf_coex_hooks_p[1])(uVar13,7,&uStack_74);
          }
        }
      }
    }
    iVar6 = r_llm_le_evt_mask_check(9);
    if (iVar6 == 0) {
      puVar8 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,0x14);
      memset(puVar8 + 2,0,0x12);
      *puVar8 = 1;
      puVar8[1] = (bVar16 == 0) << 1;
      if (bVar16 != 0) {
        puVar8[4] = 0;
        *(ushort *)(puVar8 + 2) = uVar12;
        if ((param_1[0x20] & 2) == 0) {
          puVar8[5] = param_1[0x20] & 1;
          pbVar18 = param_1 + 0xe;
        }
        else {
          puVar8[5] = 1;
          pbVar18 = param_1 + 8;
        }
        memcpy(puVar8 + 6,pbVar18,6);
        iVar15 = iVar15 + uVar14 * 0x10;
        *(undefined2 *)(puVar8 + 0xc) = *(undefined2 *)(param_1 + 0x18);
        *(undefined2 *)(puVar8 + 0xe) = *(undefined2 *)(iVar15 + 0x12);
        *(undefined2 *)(puVar8 + 0x10) = *(undefined2 *)(iVar15 + 0x14);
        puVar8[0x12] = param_1[0x31];
      }
    }
    else {
      puVar8 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,0x20);
      memset(puVar8 + 2,0,0x1e);
      *puVar8 = 10;
      puVar8[1] = (bVar16 == 0) << 1;
      if (bVar16 != 0) {
        puVar8[4] = 0;
        *(ushort *)(puVar8 + 2) = uVar12;
        memcpy(puVar8 + 6,param_1 + 0xe,6);
        if ((*(byte *)(iVar15 + 1) & 2) == 0) {
          memset(puVar8 + 0xc,0,6);
        }
        else {
          memcpy(puVar8 + 0xc,param_1 + 2,6);
        }
        if ((param_1[0x20] & 2) == 0) {
          memset(puVar8 + 0x12,0,6);
        }
        else {
          memcpy(puVar8 + 0x12,param_1 + 8,6);
        }
        iVar15 = iVar15 + uVar14 * 0x10;
        puVar8[5] = param_1[0x20];
        *(undefined2 *)(puVar8 + 0x18) = *(undefined2 *)(param_1 + 0x18);
        *(undefined2 *)(puVar8 + 0x1a) = *(undefined2 *)(iVar15 + 0x12);
        *(undefined2 *)(puVar8 + 0x1c) = *(undefined2 *)(iVar15 + 0x14);
        puVar8[0x1e] = param_1[0x31];
      }
    }
    r_hci_send_2_host(puVar8);
    iVar15 = *(int *)(*(int *)(_p_llm_env + 8) + iVar5);
    if (iVar15 != 0) {
      r_ke_msg_free(iVar15 + -0xc);
      *(undefined4 *)(iVar5 + *(int *)(_p_llm_env + 8)) = 0;
    }
    if (bVar16 != 0) {
      puVar8 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,6);
      *puVar8 = 0x14;
      bVar16 = param_1[0x34];
      *(ushort *)(puVar8 + 2) = uVar12;
      puVar8[4] = bVar16;
      r_hci_send_2_host();
    }
  }
  else {
    r_assert_param(uVar13,*(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)*param_1 * 0x44 + 0x40),
                   "llm_init.c",0x379);
  }
  return 0;
}

