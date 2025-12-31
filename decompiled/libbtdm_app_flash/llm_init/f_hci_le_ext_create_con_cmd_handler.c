/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llm_init.o -> f_hci_le_ext_create_con_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_ext_create_con_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort uVar4;
  ushort uVar5;
  undefined2 uVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  ushort *puVar12;
  byte *pbVar13;
  undefined4 *puVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint *puVar18;
  ushort *puVar19;
  uint uVar20;
  byte bStack_da;
  byte bStack_d9;
  undefined1 auStack_d8 [8];
  undefined4 uStack_d0;
  undefined2 uStack_cc;
  undefined1 auStack_ca [6];
  undefined1 auStack_c4 [5];
  undefined1 uStack_bf;
  byte bStack_be;
  byte bStack_bd;
  byte bStack_bc;
  byte bStack_bb;
  byte bStack_ba;
  ushort auStack_b8 [18];
  undefined1 uStack_94;
  uint local_90 [4];
  undefined2 uStack_80;
  undefined1 auStack_7e [2];
  uint auStack_7c [20];
  
  bStack_da = 0;
  memset(local_90,0,0x60);
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L128:
    uVar9 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    while( true ) {
      iVar7 = r_sdk_config_get_opts();
      if ((uint)*(byte *)(iVar7 + 0xd) <= (uint)bStack_da) break;
      if (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bStack_da * 0x44 + 0x40) == '\x05') break;
      bStack_da = bStack_da + 1;
    }
    iVar7 = r_sdk_config_get_opts();
    if ((uint)bStack_da < (uint)*(byte *)(iVar7 + 0xd)) {
      r_ble_log_internal_x1(0x802e01b6,(uint)bStack_da << 8 | 0xc);
      goto _L128;
    }
    if ((*param_1 == 0) && (iVar7 = r_llm_is_dev_connected(param_1 + 3,param_1[2]), iVar7 != 0)) {
      r_ble_log_internal_x1(0x802e01b7,(uint)*param_1 << 8 | 0xb);
      uVar9 = 0xb;
      uVar8 = 0;
      goto _L123;
    }
    bStack_d9 = param_1[2];
    memcpy(auStack_d8,param_1 + 3,6);
    if (*(char *)(_p_llm_env + 0xc6) != '\0') {
      lld_peer_rpa_to_id(auStack_d8,&bStack_d9);
    }
    bVar1 = param_1[9];
    uVar9 = (uint)bVar1;
    uVar20 = uVar9 & 0xfffffff8;
    if ((bVar1 & 0xf8) == 0) {
      puVar12 = (ushort *)(param_1 + 10);
      uVar16 = (uint)(&one_bits)[uVar9] + (uint)one_bits & 0xff;
      for (uVar10 = 0; (int)uVar10 < (int)uVar16; uVar10 = uVar10 + 1) {
        if (((bVar1 & 2) == 0) || ((uVar9 & 1) != uVar10)) {
          uVar4 = puVar12[1];
          uVar5 = *puVar12;
          if ((uVar5 < uVar4) || ((uVar4 < 4 || (uVar5 < 4)))) {
            r_ble_log_internal_x2(0x802e01b9,CONCAT22(uVar5,uVar4),uVar10 << 8 | 0x12);
            goto _L163;
          }
        }
        puVar12 = puVar12 + 8;
      }
      puVar19 = (ushort *)(param_1 + 0xe);
      puVar12 = puVar19;
      for (uVar9 = 0; uVar16 != uVar9; uVar9 = uVar9 + 1) {
        uVar10 = (uint)puVar12[1];
        if (((((uVar10 < *puVar12) || (puVar12[5] < puVar12[4])) ||
             (puVar2 = puVar12 + 3, *puVar12 < 6)) ||
            ((0xc80 < uVar10 || (0xc76 < (*puVar2 - 10 & 0xffff))))) ||
           (puVar3 = puVar12 + 2, 499 < *puVar3)) {
_L96:
          uVar9 = uVar9 << 8 | 0x12;
          uVar8 = 0x802e01ba;
          goto _L162;
        }
        puVar12 = puVar12 + 8;
        if ((int)((uint)*puVar2 * 10) < (int)((ushort)(*puVar3 + 1) * uVar10 * 5 + 1) >> 1)
        goto _L96;
      }
      bVar1 = param_1[1];
      if ((1 < bStack_d9) || (3 < bVar1)) {
        uVar9 = (uint)bStack_d9 << 8 | (uint)bVar1 << 0x10 | 0x12;
        uVar8 = 0x802e01bb;
        goto _L162;
      }
      if (((bVar1 & 1) != 0) &&
         (iVar7 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr), iVar7 != 0)) {
        uVar8 = 0x802e01bc;
        uVar9 = (uint)param_1[1] << 8 | 0x12;
        goto _L162;
      }
      uVar9 = r_llm_activity_free_get(&bStack_da);
      if (uVar9 == 0) {
        puVar18 = local_90;
        while( true ) {
          if (uVar16 == uVar20) break;
          uVar10 = (uint)*puVar19 << 1;
          uVar9 = (uint)puVar19[4];
          if (uVar10 < puVar19[4]) {
            uVar9 = uVar10;
          }
          if (uVar9 < 2) {
            uVar9 = 2;
          }
          uVar11 = (uint)puVar19[1] << 1;
          uVar15 = (uint)puVar19[5];
          if (uVar11 < puVar19[5]) {
            uVar15 = uVar11;
          }
          if (uVar15 < uVar9) {
            uVar15 = uVar9;
          }
          puVar18[1] = uVar11;
          *puVar18 = uVar10;
          puVar18[2] = uVar9;
          puVar18[3] = uVar15;
          *(undefined1 *)((int)puVar18 + 0x12) = 0;
          *(undefined1 *)((int)puVar18 + 0x13) = 0;
          *(ushort *)(puVar18 + 4) = (ushort)bStack_da;
          iVar7 = r_sch_plan_req(puVar18);
          puVar19 = puVar19 + 8;
          puVar18 = puVar18 + 8;
          if (iVar7 != 0) {
            r_ble_log_internal_x1(0x802e01be,uVar20 << 8 | 0xd);
            uVar9 = 0x3b;
            uVar8 = 0;
            goto _L123;
          }
          uVar20 = uVar20 + 1;
        }
        if (*(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_da * 0x44) != 0) {
          r_assert_err(0,0x10000,0x1ec);
        }
        bVar1 = param_1[1];
        if (bVar1 == 2) {
_L111:
          iVar7 = *(int *)(_p_llm_env + 8) + (uint)bStack_da * 0x44;
          uVar6 = *(undefined2 *)(_p_llm_env + 0x10);
          *(undefined4 *)(iVar7 + 4) = *(undefined4 *)(_p_llm_env + 0xc);
          *(undefined2 *)(iVar7 + 8) = uVar6;
        }
        else if (bVar1 < 3) {
          if (bVar1 == 0) goto _L111;
_L113:
          memcpy((void *)(*(int *)(_p_llm_env + 8) + (uint)bStack_da * 0x44 + 4),
                 (void *)(_p_llm_env + 0x12),6);
        }
        else {
          if (bVar1 == 3) goto _L113;
          r_assert_param(0,0x10000,0x201);
        }
        iVar7 = *(int *)(_p_llm_env + 8);
        *(byte **)((uint)bStack_da * 0x44 + iVar7) = param_1;
        *(undefined1 *)(iVar7 + (uint)bStack_da * 0x44 + 0x40) = 5;
        r_ble_log_internal_x1(0x404e01bf,bStack_da | 0x500);
        memcpy(auStack_ca,auStack_d8,6);
        iVar7 = _p_llm_env;
        memcpy(auStack_c4,(void *)(_p_llm_env + 0x1d),5);
        bStack_be = param_1[9];
        puVar14 = &uStack_d0;
        puVar18 = local_90;
        for (pbVar13 = param_1; pbVar13 != param_1 + uVar16 * 0x10; pbVar13 = pbVar13 + 0x10) {
          *(undefined2 *)(puVar14 + 6) = *(undefined2 *)(pbVar13 + 10);
          *(undefined2 *)((int)puVar14 + 0x1a) = *(undefined2 *)(pbVar13 + 0xc);
          *(short *)(puVar14 + 7) = (short)(puVar18[5] >> 1);
          *(short *)((int)puVar14 + 0x1e) = (short)puVar18[6];
          *(undefined2 *)(puVar14 + 8) = *(undefined2 *)(pbVar13 + 0x12);
          *(undefined2 *)((int)puVar14 + 0x22) = *(undefined2 *)(pbVar13 + 0x14);
          puVar14 = puVar14 + 3;
          puVar18 = puVar18 + 8;
        }
        if ((bStack_be & 5) == 5) {
          iVar17 = uVar16 - 1;
          uVar9 = (uint)auStack_b8[1] + (uint)auStack_b8[iVar17 * 6 + 1];
          if (auStack_b8[0] < uVar9) {
            auStack_b8[0] = (ushort)uVar9;
          }
          if (auStack_b8[iVar17 * 6] < uVar9) {
            auStack_b8[iVar17 * 6] = (ushort)uVar9;
          }
        }
        bStack_bc = param_1[1];
        bStack_bd = bStack_da;
        bStack_bb = bStack_d9;
        bStack_ba = *param_1;
        iVar17 = *(int *)(iVar7 + 8) + (uint)bStack_da * 0x44;
        uStack_d0 = *(undefined4 *)(iVar17 + 4);
        uStack_cc = *(undefined2 *)(iVar17 + 8);
        uStack_bf = 1;
        uStack_94 = *(undefined1 *)(iVar7 + 0xc6);
        if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
           ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
          (*(code *)*_bt_rf_coex_hooks_p)(3,1);
        }
        uVar9 = r_lld_init_start_hack(&uStack_d0);
        uVar8 = 1;
        if (uVar9 != 0) {
          r_ble_log_internal_x1(0x802e01c0,(uint)bStack_da << 8 | uVar9);
          uVar9 = 3;
        }
        goto _L123;
      }
      r_ble_log_internal_x1(0x802e01bd,(uint)bStack_da << 8 | uVar9);
    }
    else {
      uVar9 = uVar9 << 8 | 0x12;
      uVar8 = 0x802e01b8;
_L162:
      r_ble_log_internal_x1(uVar8,uVar9);
_L163:
      uVar9 = 0x12;
    }
  }
  uVar8 = 0;
_L123:
  r_llm_cmd_stat_send(param_2,uVar9);
  return uVar8;
}

