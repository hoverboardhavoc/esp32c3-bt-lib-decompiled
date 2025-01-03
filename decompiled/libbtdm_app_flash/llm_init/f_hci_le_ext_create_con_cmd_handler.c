/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
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
  char cVar2;
  ushort *puVar3;
  undefined2 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  ushort *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined4 *puVar13;
  char *pcVar14;
  uint *puVar15;
  int iVar16;
  undefined4 uVar17;
  char *pcVar18;
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
_L70:
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
    if (bStack_da < *(byte *)(iVar7 + 0xd)) goto _L70;
    if ((*param_1 == '\0') && (iVar7 = r_llm_is_dev_connected(param_1 + 3,param_1[2]), iVar7 != 0))
    {
      iVar7 = 0xb;
    }
    else {
      bStack_d9 = param_1[2];
      memcpy(auStack_d8,param_1 + 3,6);
      if (*(char *)(_p_llm_env + 0xc6) != '\0') {
        lld_peer_rpa_to_id(auStack_d8,&bStack_d9);
      }
      bVar1 = param_1[9];
      uVar11 = (uint)bVar1;
      uVar10 = uVar11 & 0xfffffff8;
      if ((bVar1 & 0xf8) == 0) {
        uVar5 = (uint)(byte)(&one_bits)[uVar11 & 0xf] + (uint)(byte)(&one_bits)[bVar1 >> 4] & 0xff;
        puVar9 = (ushort *)(param_1 + 10);
        for (; (int)uVar10 < (int)uVar5; uVar10 = uVar10 + 1) {
          if (((bVar1 & 2) == 0) || ((uVar11 & 1) != uVar10)) {
            if ((*puVar9 < puVar9[1]) || ((puVar9[1] < 4 || (*puVar9 < 4)))) goto _L83;
          }
          puVar9 = puVar9 + 8;
        }
        pcVar14 = param_1;
        while (pcVar14 != param_1 + uVar5 * 0x10) {
          uVar10 = (uint)*(ushort *)(pcVar14 + 0x10);
          if ((((uVar10 < *(ushort *)(pcVar14 + 0xe)) ||
               (*(ushort *)(pcVar14 + 0x18) < *(ushort *)(pcVar14 + 0x16))) ||
              (puVar9 = (ushort *)(pcVar14 + 0x14), *(ushort *)(pcVar14 + 0xe) < 6)) ||
             (((0xc80 < uVar10 || (0xc76 < (*puVar9 - 10 & 0xffff))) ||
              ((puVar3 = (ushort *)(pcVar14 + 0x12), 499 < *puVar3 ||
               (pcVar14 = pcVar14 + 0x10,
               (int)((uint)*puVar9 * 10) < (int)((*puVar3 + 1) * uVar10 * 5 + 1) >> 1))))))
          goto _L83;
        }
        if (((bStack_d9 < 2) && ((byte)param_1[1] < 4)) &&
           (((param_1[1] & 1U) == 0 ||
            (iVar7 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr), iVar7 == 0)))) {
          iVar7 = r_llm_activity_free_get(&bStack_da);
          if (iVar7 != 0) goto _L130;
          puVar15 = local_90;
          pcVar18 = param_1;
          goto _L88;
        }
      }
_L83:
      iVar7 = 0x12;
    }
  }
_L130:
  uVar17 = 0;
_L107:
  r_llm_cmd_stat_send(param_2,iVar7);
  return uVar17;
  while( true ) {
    uVar11 = (uint)*(ushort *)(pcVar18 + 0xe) << 1;
    uVar10 = (uint)*(ushort *)(pcVar18 + 0x16);
    if (uVar11 < *(ushort *)(pcVar18 + 0x16)) {
      uVar10 = uVar11;
    }
    if (uVar10 < 2) {
      uVar10 = 2;
    }
    uVar8 = (uint)*(ushort *)(pcVar18 + 0x10) << 1;
    uVar12 = (uint)*(ushort *)(pcVar18 + 0x18);
    if (uVar8 < *(ushort *)(pcVar18 + 0x18)) {
      uVar12 = uVar8;
    }
    if (uVar12 < uVar10) {
      uVar12 = uVar10;
    }
    puVar15[1] = uVar8;
    *puVar15 = uVar11;
    puVar15[2] = uVar10;
    puVar15[3] = uVar12;
    *(undefined1 *)((int)puVar15 + 0x12) = 0;
    *(undefined1 *)((int)puVar15 + 0x13) = 0;
    *(ushort *)(puVar15 + 4) = (ushort)bStack_da;
    iVar7 = r_sch_plan_req(puVar15);
    pcVar18 = pcVar18 + 0x10;
    puVar15 = puVar15 + 8;
    if (iVar7 != 0) break;
_L88:
    if (pcVar18 == pcVar14) {
      if (*(int *)((uint)bStack_da * 0x44 + *(int *)(_p_llm_env + 8)) != 0) {
        r_assert_err(0,"llm_init.c",0x1d2);
      }
      cVar2 = param_1[1];
      if (cVar2 == '\x01') {
_L96:
        memcpy((void *)(*(int *)(_p_llm_env + 8) + (uint)bStack_da * 0x44 + 4),
               (void *)(_p_llm_env + 0x12),6);
      }
      else if ((cVar2 == '\0') || (cVar2 == '\x02')) {
        iVar7 = *(int *)(_p_llm_env + 8) + (uint)bStack_da * 0x44;
        uVar4 = *(undefined2 *)(_p_llm_env + 0x10);
        *(undefined4 *)(iVar7 + 4) = *(undefined4 *)(_p_llm_env + 0xc);
        *(undefined2 *)(iVar7 + 8) = uVar4;
      }
      else {
        if (cVar2 == '\x03') goto _L96;
        r_assert_param(0,"llm_init.c",0x1e7);
      }
      bVar1 = bStack_da;
      iVar7 = _p_llm_env;
      uVar10 = (uint)bStack_da;
      iVar16 = uVar10 * 0x44;
      puVar13 = (undefined4 *)(*(int *)(_p_llm_env + 8) + iVar16);
      *(undefined1 *)(puVar13 + 0x10) = 5;
      *puVar13 = param_1;
      memcpy(auStack_ca,auStack_d8,6);
      memcpy(auStack_c4,(void *)(iVar7 + 0x1d),5);
      bStack_be = param_1[9];
      puVar13 = &uStack_d0;
      pcVar18 = param_1;
      puVar15 = local_90;
      while( true ) {
        if (pcVar14 == pcVar18) break;
        *(undefined2 *)(puVar13 + 6) = *(undefined2 *)(pcVar18 + 10);
        *(undefined2 *)((int)puVar13 + 0x1a) = *(undefined2 *)(pcVar18 + 0xc);
        *(short *)(puVar13 + 7) = (short)(puVar15[5] >> 1);
        *(short *)((int)puVar13 + 0x1e) = (short)puVar15[6];
        *(undefined2 *)(puVar13 + 8) = *(undefined2 *)(pcVar18 + 0x12);
        *(undefined2 *)((int)puVar13 + 0x22) = *(undefined2 *)(pcVar18 + 0x14);
        puVar13 = puVar13 + 3;
        pcVar18 = pcVar18 + 0x10;
        puVar15 = puVar15 + 8;
      }
      if ((bStack_be & 5) == 5) {
        iVar6 = uVar5 - 1;
        uVar11 = (uint)auStack_b8[1] + (uint)auStack_b8[iVar6 * 6 + 1];
        if (auStack_b8[0] < uVar11) {
          auStack_b8[0] = (ushort)uVar11;
        }
        if (auStack_b8[iVar6 * 6] < uVar11) {
          auStack_b8[iVar6 * 6] = (ushort)uVar11;
        }
      }
      cStack_bc = param_1[1];
      bStack_bd = bVar1;
      bStack_bb = bStack_d9;
      cStack_ba = *param_1;
      iVar16 = *(int *)(iVar7 + 8) + iVar16;
      uStack_d0 = *(undefined4 *)(iVar16 + 4);
      uStack_cc = *(undefined2 *)(iVar16 + 8);
      uStack_bf = 1;
      uStack_94 = *(undefined1 *)(iVar7 + 0xc6);
      if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
         ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
        (*(code *)*_bt_rf_coex_hooks_p)(uVar10,3,1);
      }
      iVar7 = r_lld_init_start_hack(&uStack_d0);
      if (iVar7 != 0) {
        iVar7 = 3;
      }
      uVar17 = 1;
      goto _L107;
    }
  }
  iVar7 = 0x3b;
  uVar17 = 0;
  goto _L107;
}

