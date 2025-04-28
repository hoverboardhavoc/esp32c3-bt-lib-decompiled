/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_init.o -> f_hci_le_ext_create_con_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_ext_create_con_cmd_handler(char *param_1,undefined4 param_2)

{
  byte bVar1;
  ushort *puVar2;
  undefined2 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  uint uVar12;
  char *pcVar13;
  int iVar14;
  char *pcVar15;
  undefined4 uVar16;
  uint *puVar17;
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
  uint local_90 [4];
  undefined2 uStack_80;
  undefined1 auStack_7e [2];
  uint auStack_7c [19];
  
  bStack_da = 0;
  memset(local_90,0,0x60);
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L71:
    iVar5 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    while( true ) {
      iVar5 = r_sdk_config_get_opts();
      if (((uint)*(byte *)(iVar5 + 0xd) <= (uint)bStack_da) ||
         (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bStack_da * 0x44 + 0x40) == '\x05')) break;
      bStack_da = bStack_da + 1;
    }
    iVar5 = r_sdk_config_get_opts();
    if (bStack_da < *(byte *)(iVar5 + 0xd)) goto _L71;
    if (*param_1 == '\0') {
      iVar9 = r_llm_is_dev_connected(param_1 + 3,param_1[2]);
      iVar5 = 0xb;
      uVar16 = 0;
      if (iVar9 != 0) goto _L109;
    }
    bStack_d9 = param_1[2];
    memcpy(auStack_d8,param_1 + 3,6);
    if (*(char *)(_p_llm_env + 0xc6) != '\0') {
      lld_peer_rpa_to_id(auStack_d8,&bStack_d9);
    }
    bVar1 = param_1[9];
    uVar10 = (uint)bVar1;
    uVar8 = uVar10 & 0xfffffff8;
    if ((bVar1 & 0xf8) == 0) {
      uVar4 = (uint)(&one_bits)[uVar10] + (uint)one_bits & 0xff;
      puVar7 = (ushort *)(param_1 + 10);
      for (; (int)uVar8 < (int)uVar4; uVar8 = uVar8 + 1) {
        if (((bVar1 & 2) == 0) || ((uVar10 & 1) != uVar8)) {
          if ((*puVar7 < puVar7[1]) || ((puVar7[1] < 4 || (*puVar7 < 4)))) goto _L84;
        }
        puVar7 = puVar7 + 8;
      }
      pcVar13 = param_1;
      while (param_1 + uVar4 * 0x10 != pcVar13) {
        uVar8 = (uint)*(ushort *)(pcVar13 + 0x10);
        if ((((uVar8 < *(ushort *)(pcVar13 + 0xe)) ||
             (*(ushort *)(pcVar13 + 0x18) < *(ushort *)(pcVar13 + 0x16))) ||
            (puVar7 = (ushort *)(pcVar13 + 0x14), *(ushort *)(pcVar13 + 0xe) < 6)) ||
           (((0xc80 < uVar8 || (0xc76 < (*puVar7 - 10 & 0xffff))) ||
            ((puVar2 = (ushort *)(pcVar13 + 0x12), 499 < *puVar2 ||
             (pcVar13 = pcVar13 + 0x10,
             (int)((uint)*puVar7 * 10) < (int)((ushort)(*puVar2 + 1) * uVar8 * 5 + 1) >> 1))))))
        goto _L84;
      }
      if (((bStack_d9 < 2) && ((byte)param_1[1] < 4)) &&
         (((param_1[1] & 1U) == 0 ||
          (iVar5 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr), iVar5 == 0)))) {
        iVar5 = r_llm_activity_free_get(&bStack_da);
        if (iVar5 != 0) goto _L132;
        puVar17 = local_90;
        pcVar15 = param_1;
        goto _L89;
      }
    }
_L84:
    iVar5 = 0x12;
  }
_L132:
  uVar16 = 0;
_L109:
  r_llm_cmd_stat_send(param_2,iVar5);
  return uVar16;
  while( true ) {
    uVar10 = (uint)*(ushort *)(pcVar15 + 0xe) << 1;
    uVar8 = (uint)*(ushort *)(pcVar15 + 0x16);
    if (uVar10 < *(ushort *)(pcVar15 + 0x16)) {
      uVar8 = uVar10;
    }
    if (uVar8 < 2) {
      uVar8 = 2;
    }
    uVar6 = (uint)*(ushort *)(pcVar15 + 0x10) << 1;
    uVar12 = (uint)*(ushort *)(pcVar15 + 0x18);
    if (uVar6 < *(ushort *)(pcVar15 + 0x18)) {
      uVar12 = uVar6;
    }
    if (uVar12 < uVar8) {
      uVar12 = uVar8;
    }
    puVar17[1] = uVar6;
    *puVar17 = uVar10;
    puVar17[2] = uVar8;
    puVar17[3] = uVar12;
    *(undefined1 *)((int)puVar17 + 0x12) = 0;
    *(undefined1 *)((int)puVar17 + 0x13) = 0;
    *(ushort *)(puVar17 + 4) = (ushort)bStack_da;
    iVar5 = r_sch_plan_req(puVar17);
    pcVar15 = pcVar15 + 0x10;
    puVar17 = puVar17 + 8;
    if (iVar5 != 0) break;
_L89:
    if (pcVar15 == pcVar13) {
      if (*(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_da * 0x44) != 0) {
        r_assert_err(0,0x10000,0x1d2);
      }
      bVar1 = param_1[1];
      if (bVar1 == 2) {
_L97:
        iVar5 = *(int *)(_p_llm_env + 8) + (uint)bStack_da * 0x44;
        uVar3 = *(undefined2 *)(_p_llm_env + 0x10);
        *(undefined4 *)(iVar5 + 4) = *(undefined4 *)(_p_llm_env + 0xc);
        *(undefined2 *)(iVar5 + 8) = uVar3;
      }
      else {
        if (bVar1 < 3) {
          if (bVar1 == 0) goto _L97;
        }
        else if (bVar1 != 3) {
          r_assert_param(0,0x10000,0x1e7);
          goto _L101;
        }
        memcpy((void *)(*(int *)(_p_llm_env + 8) + (uint)bStack_da * 0x44 + 4),
               (void *)(_p_llm_env + 0x12),6);
      }
_L101:
      bVar1 = bStack_da;
      iVar5 = _p_llm_env;
      iVar9 = *(int *)(_p_llm_env + 8);
      *(char **)((uint)bStack_da * 0x44 + iVar9) = param_1;
      uVar8 = (uint)bStack_da;
      iVar14 = uVar8 * 0x44;
      *(undefined1 *)(iVar9 + iVar14 + 0x40) = 5;
      memcpy(auStack_ca,auStack_d8,6);
      memcpy(auStack_c4,(void *)(iVar5 + 0x1d),5);
      bStack_be = param_1[9];
      puVar11 = &uStack_d0;
      puVar17 = local_90;
      for (pcVar15 = param_1; pcVar15 != pcVar13; pcVar15 = pcVar15 + 0x10) {
        *(undefined2 *)(puVar11 + 6) = *(undefined2 *)(pcVar15 + 10);
        *(undefined2 *)((int)puVar11 + 0x1a) = *(undefined2 *)(pcVar15 + 0xc);
        *(short *)(puVar11 + 7) = (short)(puVar17[5] >> 1);
        *(short *)((int)puVar11 + 0x1e) = (short)puVar17[6];
        *(undefined2 *)(puVar11 + 8) = *(undefined2 *)(pcVar15 + 0x12);
        *(undefined2 *)((int)puVar11 + 0x22) = *(undefined2 *)(pcVar15 + 0x14);
        puVar11 = puVar11 + 3;
        puVar17 = puVar17 + 8;
      }
      if ((bStack_be & 5) == 5) {
        iVar9 = uVar4 - 1;
        uVar10 = (uint)auStack_b8[1] + (uint)auStack_b8[iVar9 * 6 + 1];
        if (auStack_b8[0] < uVar10) {
          auStack_b8[0] = (ushort)uVar10;
        }
        if (auStack_b8[iVar9 * 6] < uVar10) {
          auStack_b8[iVar9 * 6] = (ushort)uVar10;
        }
      }
      cStack_bc = param_1[1];
      bStack_bd = bVar1;
      bStack_bb = bStack_d9;
      cStack_ba = *param_1;
      iVar14 = *(int *)(iVar5 + 8) + iVar14;
      uStack_d0 = *(undefined4 *)(iVar14 + 4);
      uStack_cc = *(undefined2 *)(iVar14 + 8);
      uStack_bf = 1;
      uStack_94 = *(undefined1 *)(iVar5 + 0xc6);
      if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
         ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
        (*(code *)*_bt_rf_coex_hooks_p)(uVar8,3,1);
      }
      iVar5 = r_lld_init_start_hack(&uStack_d0);
      if (iVar5 != 0) {
        iVar5 = 3;
      }
      uVar16 = 1;
      goto _L109;
    }
  }
  iVar5 = 0x3b;
  uVar16 = 0;
  goto _L109;
}

