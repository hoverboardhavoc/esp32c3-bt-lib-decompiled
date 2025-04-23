/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_init.o -> f_hci_le_ext_create_con_cmd_handler
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
  code *pcVar15;
  undefined4 *puVar16;
  undefined4 uVar17;
  int iVar18;
  uint *puVar19;
  ushort *puVar20;
  byte bStack_ea;
  byte bStack_e9;
  undefined1 auStack_e8 [8];
  undefined4 uStack_e0;
  undefined2 uStack_dc;
  undefined1 auStack_da [6];
  undefined1 auStack_d4 [5];
  undefined1 uStack_cf;
  byte bStack_ce;
  byte bStack_cd;
  char cStack_cc;
  byte bStack_cb;
  char cStack_ca;
  ushort auStack_c8 [18];
  undefined1 uStack_a4;
  uint local_a0 [4];
  undefined2 uStack_90;
  undefined1 auStack_8e [2];
  uint auStack_8c [22];
  
  bStack_ea = 0;
  memset(local_a0,0,0x60);
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L69:
    iVar7 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    while( true ) {
      iVar7 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      if (((uint)*(byte *)(iVar7 + 0xd) <= (uint)bStack_ea) ||
         (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bStack_ea * 0x44 + 0x40) == '\x05')) break;
      bStack_ea = bStack_ea + 1;
    }
    iVar7 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (bStack_ea < *(byte *)(iVar7 + 0xd)) goto _L69;
    if (*param_1 == '\0') {
      iVar18 = (**(code **)(_r_ip_funcs_p + 0x4d8))
                         (param_1 + 3,param_1[2],*(code **)(_r_ip_funcs_p + 0x4d8));
      iVar7 = 0xb;
      uVar17 = 0;
      if (iVar18 != 0) goto _L111;
    }
    bStack_e9 = param_1[2];
    memcpy(auStack_e8,param_1 + 3,6);
    if (*(char *)(_p_llm_env + 0xc6) != '\0') {
      lld_peer_rpa_to_id(auStack_e8,&bStack_e9);
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
      puVar20 = (ushort *)(param_1 + 0xe);
      puVar9 = puVar20;
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
      if (((1 < bStack_e9) || (3 < (byte)param_1[1])) ||
         (((param_1[1] & 1U) != 0 &&
          (iVar7 = (*(code *)*_r_modules_funcs_p)
                             (_p_llm_env + 0x12,&co_null_bdaddr,(code *)*_r_modules_funcs_p),
          iVar7 != 0)))) goto _L82;
      iVar7 = (**(code **)(_r_ip_funcs_p + 0x4ac))(&bStack_ea,*(code **)(_r_ip_funcs_p + 0x4ac));
      if (iVar7 == 0) {
        puVar19 = local_a0;
        for (uVar13 = 0; uVar5 != uVar13; uVar13 = uVar13 + 1) {
          uVar10 = (uint)*puVar20 << 1;
          uVar11 = (uint)puVar20[4];
          if (uVar10 < puVar20[4]) {
            uVar11 = uVar10;
          }
          if (uVar11 < 2) {
            uVar11 = 2;
          }
          uVar8 = (uint)puVar20[1] << 1;
          uVar14 = (uint)puVar20[5];
          if (uVar8 < puVar20[5]) {
            uVar14 = uVar8;
          }
          if (uVar14 < uVar11) {
            uVar14 = uVar11;
          }
          puVar19[3] = uVar14;
          *(undefined1 *)((int)puVar19 + 0x12) = 0;
          puVar19[1] = uVar8;
          *(ushort *)(puVar19 + 4) = (ushort)bStack_ea;
          *puVar19 = uVar10;
          puVar19[2] = uVar11;
          pcVar15 = *(code **)(_r_ip_funcs_p + 0x6f8);
          *(undefined1 *)((int)puVar19 + 0x13) = 0;
          iVar7 = (*pcVar15)(puVar19,pcVar15);
          puVar20 = puVar20 + 8;
          puVar19 = puVar19 + 8;
          if (iVar7 != 0) {
            iVar7 = 0x3b;
            uVar17 = 0;
            if ((int)uVar13 < (int)uVar5) goto _L111;
            break;
          }
        }
        if (*(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_ea * 0x44) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x1d2,*(code **)(_r_plf_funcs_p + 8));
        }
        bVar1 = param_1[1];
        if (bVar1 == 2) {
_L99:
          iVar7 = *(int *)(_p_llm_env + 8) + (uint)bStack_ea * 0x44;
          uVar4 = *(undefined2 *)(_p_llm_env + 0x10);
          *(undefined4 *)(iVar7 + 4) = *(undefined4 *)(_p_llm_env + 0xc);
          *(undefined2 *)(iVar7 + 8) = uVar4;
        }
        else {
          if (bVar1 < 3) {
            if (bVar1 == 0) goto _L99;
          }
          else if (bVar1 != 3) {
            (**(code **)(_r_plf_funcs_p + 0xc))(0,0x10000,0x1e7,*(code **)(_r_plf_funcs_p + 0xc));
            goto _L103;
          }
          memcpy((void *)(*(int *)(_p_llm_env + 8) + (uint)bStack_ea * 0x44 + 4),
                 (void *)(_p_llm_env + 0x12),6);
        }
_L103:
        bVar1 = bStack_ea;
        iVar7 = _p_llm_env;
        uVar13 = (uint)bStack_ea;
        iVar18 = uVar13 * 0x44;
        puVar16 = (undefined4 *)(*(int *)(_p_llm_env + 8) + iVar18);
        *puVar16 = param_1;
        *(undefined1 *)(puVar16 + 0x10) = 5;
        memcpy(auStack_da,auStack_e8,6);
        memcpy(auStack_d4,(void *)(iVar7 + 0x1d),5);
        bStack_ce = param_1[9];
        puVar16 = &uStack_e0;
        puVar19 = local_a0;
        for (pcVar12 = param_1; pcVar12 != param_1 + uVar5 * 0x10; pcVar12 = pcVar12 + 0x10) {
          *(undefined2 *)(puVar16 + 6) = *(undefined2 *)(pcVar12 + 10);
          *(undefined2 *)((int)puVar16 + 0x1a) = *(undefined2 *)(pcVar12 + 0xc);
          *(short *)(puVar16 + 7) = (short)(puVar19[5] >> 1);
          *(short *)((int)puVar16 + 0x1e) = (short)puVar19[6];
          *(undefined2 *)(puVar16 + 8) = *(undefined2 *)(pcVar12 + 0x12);
          *(undefined2 *)((int)puVar16 + 0x22) = *(undefined2 *)(pcVar12 + 0x14);
          puVar16 = puVar16 + 3;
          puVar19 = puVar19 + 8;
        }
        if ((bStack_ce & 5) == 5) {
          iVar6 = uVar5 - 1;
          uVar5 = (uint)auStack_c8[1] + (uint)auStack_c8[iVar6 * 6 + 1];
          if (auStack_c8[0] < uVar5) {
            auStack_c8[0] = (ushort)uVar5;
          }
          if (auStack_c8[iVar6 * 6] < uVar5) {
            auStack_c8[iVar6 * 6] = (ushort)uVar5;
          }
        }
        cStack_cc = param_1[1];
        bStack_cd = bVar1;
        bStack_cb = bStack_e9;
        cStack_ca = *param_1;
        iVar18 = *(int *)(iVar7 + 8) + iVar18;
        uStack_e0 = *(undefined4 *)(iVar18 + 4);
        uStack_dc = *(undefined2 *)(iVar18 + 8);
        uStack_cf = 1;
        uStack_a4 = *(undefined1 *)(iVar7 + 0xc6);
        if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
           ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
          (*(code *)*_bt_rf_coex_hooks_p)(uVar13,3);
        }
        iVar7 = (**(code **)(_r_ip_funcs_p + 0x494))(&uStack_e0,*(code **)(_r_ip_funcs_p + 0x494));
        if (iVar7 != 0) {
          iVar7 = 3;
        }
        uVar17 = 1;
        goto _L111;
      }
    }
    else {
_L82:
      iVar7 = 0x12;
    }
  }
  uVar17 = 0;
_L111:
  (**(code **)(_r_ip_funcs_p + 0x4bc))(param_2,iVar7,*(code **)(_r_ip_funcs_p + 0x4bc));
  return uVar17;
}

