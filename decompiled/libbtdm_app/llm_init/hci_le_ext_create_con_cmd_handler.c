/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_init.o -> hci_le_ext_create_con_cmd_handler
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
  code *pcVar13;
  char *pcVar14;
  int iVar15;
  char *pcVar16;
  undefined4 uVar17;
  uint *puVar18;
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
  uint auStack_a0 [4];
  undefined2 uStack_90;
  undefined1 auStack_8e [2];
  uint auStack_8c [22];
  
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar5 + 0x18) == '\0') {
    (**(code **)(_r_ip_funcs_p + 0x4bc))(param_2,0xc,*(code **)(_r_ip_funcs_p + 0x4bc));
    return 0;
  }
  bStack_ea = 0;
  memset(auStack_a0,0,0x60);
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L71:
    iVar5 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    while( true ) {
      iVar5 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      if (((uint)*(byte *)(iVar5 + 0xd) <= (uint)bStack_ea) ||
         (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bStack_ea * 0x44 + 0x40) == '\x05')) break;
      bStack_ea = bStack_ea + 1;
    }
    iVar5 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (bStack_ea < *(byte *)(iVar5 + 0xd)) goto _L71;
    if (*param_1 == '\0') {
      iVar9 = (**(code **)(_r_ip_funcs_p + 0x4d8))
                        (param_1 + 3,param_1[2],*(code **)(_r_ip_funcs_p + 0x4d8));
      iVar5 = 0xb;
      uVar17 = 0;
      if (iVar9 != 0) goto _L109;
    }
    bStack_e9 = param_1[2];
    memcpy(auStack_e8,param_1 + 3,6);
    if (*(char *)(_p_llm_env + 0xc6) != '\0') {
      lld_peer_rpa_to_id(auStack_e8,&bStack_e9);
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
      pcVar14 = param_1;
      while (param_1 + uVar4 * 0x10 != pcVar14) {
        uVar8 = (uint)*(ushort *)(pcVar14 + 0x10);
        if ((((uVar8 < *(ushort *)(pcVar14 + 0xe)) ||
             (*(ushort *)(pcVar14 + 0x18) < *(ushort *)(pcVar14 + 0x16))) ||
            (puVar7 = (ushort *)(pcVar14 + 0x14), *(ushort *)(pcVar14 + 0xe) < 6)) ||
           (((0xc80 < uVar8 || (0xc76 < (*puVar7 - 10 & 0xffff))) ||
            ((puVar2 = (ushort *)(pcVar14 + 0x12), 499 < *puVar2 ||
             (pcVar14 = pcVar14 + 0x10,
             (int)((uint)*puVar7 * 10) < (int)((ushort)(*puVar2 + 1) * uVar8 * 5 + 1) >> 1))))))
        goto _L84;
      }
      if (((bStack_e9 < 2) && ((byte)param_1[1] < 4)) &&
         (((param_1[1] & 1U) == 0 ||
          (iVar5 = (*(code *)*_r_modules_funcs_p)
                             (_p_llm_env + 0x12,&co_null_bdaddr,(code *)*_r_modules_funcs_p),
          iVar5 == 0)))) {
        iVar5 = (**(code **)(_r_ip_funcs_p + 0x4ac))(&bStack_ea,*(code **)(_r_ip_funcs_p + 0x4ac));
        if (iVar5 != 0) goto _L132;
        puVar18 = auStack_a0;
        pcVar16 = param_1;
        goto _L89;
      }
    }
_L84:
    iVar5 = 0x12;
  }
_L132:
  uVar17 = 0;
_L109:
  (**(code **)(_r_ip_funcs_p + 0x4bc))(param_2,iVar5,*(code **)(_r_ip_funcs_p + 0x4bc));
  return uVar17;
  while( true ) {
    uVar10 = (uint)*(ushort *)(pcVar16 + 0xe) << 1;
    uVar8 = (uint)*(ushort *)(pcVar16 + 0x16);
    if (uVar10 < *(ushort *)(pcVar16 + 0x16)) {
      uVar8 = uVar10;
    }
    if (uVar8 < 2) {
      uVar8 = 2;
    }
    uVar6 = (uint)*(ushort *)(pcVar16 + 0x10) << 1;
    uVar12 = (uint)*(ushort *)(pcVar16 + 0x18);
    if (uVar6 < *(ushort *)(pcVar16 + 0x18)) {
      uVar12 = uVar6;
    }
    if (uVar12 < uVar8) {
      uVar12 = uVar8;
    }
    puVar18[3] = uVar12;
    *(undefined1 *)((int)puVar18 + 0x12) = 0;
    puVar18[1] = uVar6;
    pcVar13 = *(code **)(_r_ip_funcs_p + 0x6f8);
    *puVar18 = uVar10;
    puVar18[2] = uVar8;
    *(undefined1 *)((int)puVar18 + 0x13) = 0;
    *(ushort *)(puVar18 + 4) = (ushort)bStack_ea;
    iVar5 = (*pcVar13)(puVar18,pcVar13);
    pcVar16 = pcVar16 + 0x10;
    puVar18 = puVar18 + 8;
    if (iVar5 != 0) break;
_L89:
    if (pcVar16 == pcVar14) {
      if (*(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_ea * 0x44) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x1d2,*(code **)(_r_plf_funcs_p + 8));
      }
      bVar1 = param_1[1];
      if (bVar1 == 2) {
_L97:
        iVar5 = *(int *)(_p_llm_env + 8) + (uint)bStack_ea * 0x44;
        uVar3 = *(undefined2 *)(_p_llm_env + 0x10);
        *(undefined4 *)(iVar5 + 4) = *(undefined4 *)(_p_llm_env + 0xc);
        *(undefined2 *)(iVar5 + 8) = uVar3;
      }
      else {
        if (bVar1 < 3) {
          if (bVar1 == 0) goto _L97;
        }
        else if (bVar1 != 3) {
          (**(code **)(_r_plf_funcs_p + 0xc))(0,0x10000,0x1e7,*(code **)(_r_plf_funcs_p + 0xc));
          goto _L101;
        }
        memcpy((void *)(*(int *)(_p_llm_env + 8) + (uint)bStack_ea * 0x44 + 4),
               (void *)(_p_llm_env + 0x12),6);
      }
_L101:
      bVar1 = bStack_ea;
      iVar5 = _p_llm_env;
      iVar9 = *(int *)(_p_llm_env + 8);
      *(char **)((uint)bStack_ea * 0x44 + iVar9) = param_1;
      uVar8 = (uint)bStack_ea;
      iVar15 = uVar8 * 0x44;
      *(undefined1 *)(iVar9 + iVar15 + 0x40) = 5;
      memcpy(auStack_da,auStack_e8,6);
      memcpy(auStack_d4,(void *)(iVar5 + 0x1d),5);
      bStack_ce = param_1[9];
      puVar11 = &uStack_e0;
      puVar18 = auStack_a0;
      for (pcVar16 = param_1; pcVar16 != pcVar14; pcVar16 = pcVar16 + 0x10) {
        *(undefined2 *)(puVar11 + 6) = *(undefined2 *)(pcVar16 + 10);
        *(undefined2 *)((int)puVar11 + 0x1a) = *(undefined2 *)(pcVar16 + 0xc);
        *(short *)(puVar11 + 7) = (short)(puVar18[5] >> 1);
        *(short *)((int)puVar11 + 0x1e) = (short)puVar18[6];
        *(undefined2 *)(puVar11 + 8) = *(undefined2 *)(pcVar16 + 0x12);
        *(undefined2 *)((int)puVar11 + 0x22) = *(undefined2 *)(pcVar16 + 0x14);
        puVar11 = puVar11 + 3;
        puVar18 = puVar18 + 8;
      }
      if ((bStack_ce & 5) == 5) {
        iVar9 = uVar4 - 1;
        uVar10 = (uint)auStack_c8[1] + (uint)auStack_c8[iVar9 * 6 + 1];
        if (auStack_c8[0] < uVar10) {
          auStack_c8[0] = (ushort)uVar10;
        }
        if (auStack_c8[iVar9 * 6] < uVar10) {
          auStack_c8[iVar9 * 6] = (ushort)uVar10;
        }
      }
      cStack_cc = param_1[1];
      bStack_cd = bVar1;
      bStack_cb = bStack_e9;
      cStack_ca = *param_1;
      iVar15 = *(int *)(iVar5 + 8) + iVar15;
      uStack_e0 = *(undefined4 *)(iVar15 + 4);
      uStack_dc = *(undefined2 *)(iVar15 + 8);
      uStack_cf = 1;
      uStack_a4 = *(undefined1 *)(iVar5 + 0xc6);
      if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
         ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
        (*(code *)*_bt_rf_coex_hooks_p)(uVar8,3,1);
      }
      iVar5 = (**(code **)(_r_ip_funcs_p + 0x494))(&uStack_e0,*(code **)(_r_ip_funcs_p + 0x494));
      if (iVar5 != 0) {
        iVar5 = 3;
      }
      uVar17 = 1;
      goto _L109;
    }
  }
  iVar5 = 0x3b;
  uVar17 = 0;
  goto _L109;
}

