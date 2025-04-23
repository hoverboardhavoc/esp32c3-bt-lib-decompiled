/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_init.o -> hci_le_ext_create_con_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_ext_create_con_cmd_handler(char *param_1,undefined4 param_2)

{
  byte bVar1;
  ushort *puVar2;
  ushort *puVar3;
  undefined2 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  ushort *puVar9;
  uint uVar10;
  uint uVar11;
  char *pcVar12;
  uint uVar13;
  uint uVar14;
  undefined4 *puVar15;
  undefined4 uVar16;
  int iVar17;
  uint *puVar18;
  ushort *puVar19;
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
  char cStack_bc;
  byte bStack_bb;
  char cStack_ba;
  ushort auStack_b8 [18];
  undefined1 uStack_94;
  uint auStack_90 [4];
  undefined2 uStack_80;
  undefined1 auStack_7e [2];
  uint auStack_7c [20];
  
  iVar7 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar7 + 0x18) == '\0') {
    r_llm_cmd_stat_send(param_2,0xc);
    return 0;
  }
  bStack_da = 0;
  memset(auStack_90,0,0x60);
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L69:
    iVar7 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    while( true ) {
      iVar7 = r_sdk_config_get_opts();
      if (((uint)*(byte *)(iVar7 + 0xd) <= (uint)bStack_da) ||
         (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bStack_da * 0x44 + 0x40) == '\x05')) break;
      bStack_da = bStack_da + 1;
    }
    iVar7 = r_sdk_config_get_opts();
    if (bStack_da < *(byte *)(iVar7 + 0xd)) goto _L69;
    if (*param_1 == '\0') {
      iVar17 = r_llm_is_dev_connected(param_1 + 3,param_1[2]);
      iVar7 = 0xb;
      uVar16 = 0;
      if (iVar17 != 0) goto _L111;
    }
    bStack_d9 = param_1[2];
    memcpy(auStack_d8,param_1 + 3,6);
    if (*(char *)(_p_llm_env + 0xc6) != '\0') {
      lld_peer_rpa_to_id(auStack_d8,&bStack_d9);
    }
    uVar13 = (uint)(byte)param_1[9];
    if (uVar13 < 8) {
      puVar9 = (ushort *)(param_1 + 10);
      uVar5 = (uint)(&one_bits)[uVar13] + (uint)one_bits & 0xff;
      for (uVar11 = 0; (int)uVar11 < (int)uVar5; uVar11 = uVar11 + 1) {
        if (((param_1[9] & 2U) == 0) || ((uVar13 & 1) != uVar11)) {
          if ((*puVar9 < puVar9[1]) || ((puVar9[1] < 4 || (*puVar9 < 4)))) goto _L82;
        }
        puVar9 = puVar9 + 8;
      }
      puVar19 = (ushort *)(param_1 + 0xe);
      puVar9 = puVar19;
      for (uVar13 = 0; uVar5 != uVar13; uVar13 = uVar13 + 1) {
        uVar11 = (uint)puVar9[1];
        if (((((uVar11 < *puVar9) || (puVar9[5] < puVar9[4])) ||
             (puVar2 = puVar9 + 3, 0xc76 < (*puVar2 - 10 & 0xffff))) ||
            ((*puVar9 < 6 || (0xc80 < uVar11)))) ||
           ((puVar3 = puVar9 + 2, 499 < *puVar3 ||
            (puVar9 = puVar9 + 8,
            (int)((uint)*puVar2 * 10) < (int)((*puVar3 + 1) * uVar11 * 5 + 1) >> 1)))) {
          if ((int)uVar13 < (int)uVar5) goto _L82;
          break;
        }
      }
      if (((1 < bStack_d9) || (3 < (byte)param_1[1])) ||
         (((param_1[1] & 1U) != 0 &&
          (iVar7 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr), iVar7 != 0)))) goto _L82;
      iVar7 = r_llm_activity_free_get(&bStack_da);
      if (iVar7 == 0) {
        puVar18 = auStack_90;
        for (uVar13 = 0; uVar5 != uVar13; uVar13 = uVar13 + 1) {
          uVar10 = (uint)*puVar19 << 1;
          uVar11 = (uint)puVar19[4];
          if (uVar10 < puVar19[4]) {
            uVar11 = uVar10;
          }
          if (uVar11 < 2) {
            uVar11 = 2;
          }
          uVar8 = (uint)puVar19[1] << 1;
          uVar14 = (uint)puVar19[5];
          if (uVar8 < puVar19[5]) {
            uVar14 = uVar8;
          }
          if (uVar14 < uVar11) {
            uVar14 = uVar11;
          }
          puVar18[3] = uVar14;
          puVar18[1] = uVar8;
          *puVar18 = uVar10;
          puVar18[2] = uVar11;
          *(undefined1 *)((int)puVar18 + 0x12) = 0;
          *(undefined1 *)((int)puVar18 + 0x13) = 0;
          *(ushort *)(puVar18 + 4) = (ushort)bStack_da;
          iVar7 = r_sch_plan_req(puVar18);
          puVar19 = puVar19 + 8;
          puVar18 = puVar18 + 8;
          if (iVar7 != 0) {
            iVar7 = 0x3b;
            uVar16 = 0;
            if ((int)uVar13 < (int)uVar5) goto _L111;
            break;
          }
        }
        if (*(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_da * 0x44) != 0) {
          r_assert_err(0,0x10000,0x1d2);
        }
        bVar1 = param_1[1];
        if (bVar1 == 2) {
_L99:
          iVar7 = *(int *)(_p_llm_env + 8) + (uint)bStack_da * 0x44;
          uVar4 = *(undefined2 *)(_p_llm_env + 0x10);
          *(undefined4 *)(iVar7 + 4) = *(undefined4 *)(_p_llm_env + 0xc);
          *(undefined2 *)(iVar7 + 8) = uVar4;
        }
        else {
          if (bVar1 < 3) {
            if (bVar1 == 0) goto _L99;
          }
          else if (bVar1 != 3) {
            r_assert_param(0,0x10000,0x1e7);
            goto _L103;
          }
          memcpy((void *)(*(int *)(_p_llm_env + 8) + (uint)bStack_da * 0x44 + 4),
                 (void *)(_p_llm_env + 0x12),6);
        }
_L103:
        bVar1 = bStack_da;
        iVar7 = _p_llm_env;
        uVar13 = (uint)bStack_da;
        iVar17 = uVar13 * 0x44;
        puVar15 = (undefined4 *)(*(int *)(_p_llm_env + 8) + iVar17);
        *puVar15 = param_1;
        *(undefined1 *)(puVar15 + 0x10) = 5;
        memcpy(auStack_ca,auStack_d8,6);
        memcpy(auStack_c4,(void *)(iVar7 + 0x1d),5);
        bStack_be = param_1[9];
        puVar15 = &uStack_d0;
        puVar18 = auStack_90;
        for (pcVar12 = param_1; param_1 + uVar5 * 0x10 != pcVar12; pcVar12 = pcVar12 + 0x10) {
          *(undefined2 *)(puVar15 + 6) = *(undefined2 *)(pcVar12 + 10);
          *(undefined2 *)((int)puVar15 + 0x1a) = *(undefined2 *)(pcVar12 + 0xc);
          *(short *)(puVar15 + 7) = (short)(puVar18[5] >> 1);
          *(short *)((int)puVar15 + 0x1e) = (short)puVar18[6];
          *(undefined2 *)(puVar15 + 8) = *(undefined2 *)(pcVar12 + 0x12);
          *(undefined2 *)((int)puVar15 + 0x22) = *(undefined2 *)(pcVar12 + 0x14);
          puVar15 = puVar15 + 3;
          puVar18 = puVar18 + 8;
        }
        if ((bStack_be & 5) == 5) {
          iVar6 = uVar5 - 1;
          uVar5 = (uint)auStack_b8[1] + (uint)auStack_b8[iVar6 * 6 + 1];
          if (auStack_b8[0] < uVar5) {
            auStack_b8[0] = (ushort)uVar5;
          }
          if (auStack_b8[iVar6 * 6] < uVar5) {
            auStack_b8[iVar6 * 6] = (ushort)uVar5;
          }
        }
        cStack_bc = param_1[1];
        bStack_bd = bVar1;
        bStack_bb = bStack_d9;
        cStack_ba = *param_1;
        iVar17 = *(int *)(iVar7 + 8) + iVar17;
        uStack_d0 = *(undefined4 *)(iVar17 + 4);
        uStack_cc = *(undefined2 *)(iVar17 + 8);
        uStack_bf = 1;
        uStack_94 = *(undefined1 *)(iVar7 + 0xc6);
        if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
           ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
          (*(code *)*_bt_rf_coex_hooks_p)(uVar13,3);
        }
        iVar7 = r_lld_init_start_hack(&uStack_d0);
        if (iVar7 != 0) {
          iVar7 = 3;
        }
        uVar16 = 1;
        goto _L111;
      }
    }
    else {
_L82:
      iVar7 = 0x12;
    }
  }
  uVar16 = 0;
_L111:
  r_llm_cmd_stat_send(param_2,iVar7);
  return uVar16;
}

