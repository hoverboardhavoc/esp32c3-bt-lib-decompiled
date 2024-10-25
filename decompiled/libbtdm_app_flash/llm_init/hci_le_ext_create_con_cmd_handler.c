/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  byte bStack_d1;
  undefined4 uStack_d0;
  undefined2 uStack_cc;
  undefined1 auStack_ca [6];
  undefined1 auStack_c4 [5];
  undefined1 uStack_bf;
  byte bStack_be;
  byte bStack_bd;
  char cStack_bc;
  char cStack_bb;
  char cStack_ba;
  ushort auStack_b8 [18];
  undefined1 uStack_94;
  uint auStack_90 [4];
  undefined2 uStack_80;
  undefined1 auStack_7e [2];
  uint auStack_7c [19];
  
  iVar7 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar7 + 0x18) == '\0') {
    r_llm_cmd_stat_send(param_2,0xc);
    return 0;
  }
  bStack_d1 = 0;
  memset(auStack_90,0,0x60);
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L69:
    iVar7 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    while( true ) {
      iVar7 = r_sdk_config_get_opts();
      if (((uint)*(byte *)(iVar7 + 0xd) <= (uint)bStack_d1) ||
         (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bStack_d1 * 0x44 + 0x40) == '\x05')) break;
      bStack_d1 = bStack_d1 + 1;
    }
    iVar7 = r_sdk_config_get_opts();
    if (bStack_d1 < *(byte *)(iVar7 + 0xd)) goto _L69;
    if ((*param_1 == '\0') && (iVar7 = r_llm_is_dev_connected(param_1 + 3,param_1[2]), iVar7 != 0))
    {
      iVar7 = 0xb;
    }
    else {
      bVar1 = param_1[9];
      uVar11 = (uint)bVar1;
      uVar10 = uVar11 & 0xfffffff8;
      if ((bVar1 & 0xf8) == 0) {
        uVar5 = (uint)(byte)(&one_bits)[uVar11 & 0xf] + (uint)(byte)(&one_bits)[bVar1 >> 4] & 0xff;
        puVar9 = (ushort *)(param_1 + 10);
        for (; (int)uVar10 < (int)uVar5; uVar10 = uVar10 + 1) {
          if (((bVar1 & 2) == 0) || ((uVar11 & 1) != uVar10)) {
            if ((*puVar9 < puVar9[1]) || ((puVar9[1] < 4 || (*puVar9 < 4)))) goto _L74;
          }
          puVar9 = puVar9 + 8;
        }
        pcVar14 = param_1;
        while (pcVar14 != param_1 + uVar5 * 0x10) {
          uVar10 = (uint)*(ushort *)(pcVar14 + 0x10);
          if (((((uVar10 < *(ushort *)(pcVar14 + 0xe)) ||
                (*(ushort *)(pcVar14 + 0x18) < *(ushort *)(pcVar14 + 0x16))) ||
               (puVar9 = (ushort *)(pcVar14 + 0x14), *(ushort *)(pcVar14 + 0xe) < 6)) ||
              ((0xc80 < uVar10 || (0xc76 < (*puVar9 - 10 & 0xffff))))) ||
             ((puVar3 = (ushort *)(pcVar14 + 0x12), 499 < *puVar3 ||
              (pcVar14 = pcVar14 + 0x10,
              (int)((uint)*puVar9 * 10) < (int)((*puVar3 + 1) * uVar10 * 5 + 1) >> 1)))) goto _L74;
        }
        if ((((byte)param_1[2] < 2) && ((byte)param_1[1] < 4)) &&
           (((param_1[1] & 1U) == 0 ||
            (iVar7 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr), iVar7 == 0)))) {
          iVar7 = r_llm_activity_free_get(&bStack_d1);
          if (iVar7 != 0) goto _L128;
          puVar15 = auStack_90;
          pcVar18 = param_1;
          goto _L85;
        }
      }
_L74:
      iVar7 = 0x12;
    }
  }
_L128:
  uVar17 = 0;
_L104:
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
    *(ushort *)(puVar15 + 4) = (ushort)bStack_d1;
    iVar7 = r_sch_plan_req(puVar15);
    pcVar18 = pcVar18 + 0x10;
    puVar15 = puVar15 + 8;
    if (iVar7 != 0) break;
_L85:
    if (pcVar18 == pcVar14) {
      if (*(int *)((uint)bStack_d1 * 0x44 + *(int *)(_p_llm_env + 8)) != 0) {
        r_assert_err(0,"llm_init.c",0x1c2);
      }
      cVar2 = param_1[1];
      if (cVar2 == '\x01') {
_L93:
        memcpy((void *)(*(int *)(_p_llm_env + 8) + (uint)bStack_d1 * 0x44 + 4),
               (void *)(_p_llm_env + 0x12),6);
      }
      else if ((cVar2 == '\0') || (cVar2 == '\x02')) {
        iVar7 = *(int *)(_p_llm_env + 8) + (uint)bStack_d1 * 0x44;
        uVar4 = *(undefined2 *)(_p_llm_env + 0x10);
        *(undefined4 *)(iVar7 + 4) = *(undefined4 *)(_p_llm_env + 0xc);
        *(undefined2 *)(iVar7 + 8) = uVar4;
      }
      else {
        if (cVar2 == '\x03') goto _L93;
        r_assert_param(0,"llm_init.c",0x1d7);
      }
      bVar1 = bStack_d1;
      iVar7 = _p_llm_env;
      uVar10 = (uint)bStack_d1;
      iVar16 = uVar10 * 0x44;
      puVar13 = (undefined4 *)(*(int *)(_p_llm_env + 8) + iVar16);
      *(undefined1 *)(puVar13 + 0x10) = 5;
      *puVar13 = param_1;
      memcpy(auStack_ca,param_1 + 3,6);
      memcpy(auStack_c4,(void *)(iVar7 + 0x1d),5);
      bStack_be = param_1[9];
      puVar13 = &uStack_d0;
      pcVar18 = param_1;
      puVar15 = auStack_90;
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
      cStack_bb = param_1[2];
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
      goto _L104;
    }
  }
  iVar7 = 0x3b;
  uVar17 = 0;
  goto _L104;
}

