/*
 * Last changed at upstream commit 70f95a1b6f8f232018b17c687cc819044501774c
 * https://github.com/espressif/esp32c3-bt-lib/commit/70f95a1b6f8f232018b17c687cc819044501774c
 * Upstream date: 2024-04-02 18:59:02 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(5274796)
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
  code *pcVar13;
  undefined4 *puVar14;
  char *pcVar15;
  int iVar16;
  uint *puVar17;
  undefined4 uVar18;
  char *pcVar19;
  byte bStack_e1;
  undefined4 uStack_e0;
  undefined2 uStack_dc;
  undefined1 auStack_da [6];
  undefined1 auStack_d4 [5];
  undefined1 uStack_cf;
  byte bStack_ce;
  byte bStack_cd;
  char cStack_cc;
  char cStack_cb;
  char cStack_ca;
  ushort auStack_c8 [18];
  undefined1 uStack_a4;
  uint local_a0 [4];
  undefined2 uStack_90;
  undefined1 auStack_8e [2];
  uint auStack_8c [22];
  
  bStack_e1 = 0;
  memset(local_a0,0,0x60);
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L63:
    iVar7 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    while( true ) {
      iVar7 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      if (((uint)*(byte *)(iVar7 + 0xd) <= (uint)bStack_e1) ||
         (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bStack_e1 * 0x44 + 0x40) == '\x05')) break;
      bStack_e1 = bStack_e1 + 1;
    }
    iVar7 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (bStack_e1 < *(byte *)(iVar7 + 0xd)) goto _L63;
    if ((*param_1 == '\0') &&
       (iVar7 = (**(code **)(_r_ip_funcs_p + 0x4d8))
                          (param_1 + 3,param_1[2],*(code **)(_r_ip_funcs_p + 0x4d8)), iVar7 != 0)) {
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
            if ((*puVar9 < puVar9[1]) || ((puVar9[1] < 4 || (*puVar9 < 4)))) goto _L68;
          }
          puVar9 = puVar9 + 8;
        }
        pcVar15 = param_1;
        while (pcVar15 != param_1 + uVar5 * 0x10) {
          uVar10 = (uint)*(ushort *)(pcVar15 + 0x10);
          if (((((uVar10 < *(ushort *)(pcVar15 + 0xe)) ||
                (*(ushort *)(pcVar15 + 0x18) < *(ushort *)(pcVar15 + 0x16))) ||
               (puVar9 = (ushort *)(pcVar15 + 0x14), *(ushort *)(pcVar15 + 0xe) < 6)) ||
              ((0xc80 < uVar10 || (0xc76 < (*puVar9 - 10 & 0xffff))))) ||
             ((puVar3 = (ushort *)(pcVar15 + 0x12), 499 < *puVar3 ||
              (pcVar15 = pcVar15 + 0x10,
              (int)((uint)*puVar9 * 10) < (int)((*puVar3 + 1) * uVar10 * 5 + 1) >> 1)))) goto _L68;
        }
        if ((((byte)param_1[2] < 2) && ((byte)param_1[1] < 4)) &&
           (((param_1[1] & 1U) == 0 ||
            (iVar7 = (*(code *)*_r_modules_funcs_p)
                               (_p_llm_env + 0x12,&co_null_bdaddr,(code *)*_r_modules_funcs_p),
            iVar7 == 0)))) {
          iVar7 = (**(code **)(_r_ip_funcs_p + 0x4ac))(&bStack_e1,*(code **)(_r_ip_funcs_p + 0x4ac))
          ;
          if (iVar7 != 0) goto _L122;
          puVar17 = local_a0;
          pcVar19 = param_1;
          goto _L79;
        }
      }
_L68:
      iVar7 = 0x12;
    }
  }
_L122:
  uVar18 = 0;
_L98:
  (**(code **)(_r_ip_funcs_p + 0x4bc))(param_2,iVar7,*(code **)(_r_ip_funcs_p + 0x4bc));
  return uVar18;
  while( true ) {
    uVar11 = (uint)*(ushort *)(pcVar19 + 0xe) << 1;
    uVar10 = (uint)*(ushort *)(pcVar19 + 0x16);
    if (uVar11 < *(ushort *)(pcVar19 + 0x16)) {
      uVar10 = uVar11;
    }
    if (uVar10 < 2) {
      uVar10 = 2;
    }
    uVar8 = (uint)*(ushort *)(pcVar19 + 0x10) << 1;
    uVar12 = (uint)*(ushort *)(pcVar19 + 0x18);
    if (uVar8 < *(ushort *)(pcVar19 + 0x18)) {
      uVar12 = uVar8;
    }
    if (uVar12 < uVar10) {
      uVar12 = uVar10;
    }
    puVar17[3] = uVar12;
    *(undefined1 *)((int)puVar17 + 0x12) = 0;
    puVar17[1] = uVar8;
    pcVar13 = *(code **)(_r_ip_funcs_p + 0x6f8);
    *puVar17 = uVar11;
    puVar17[2] = uVar10;
    *(undefined1 *)((int)puVar17 + 0x13) = 0;
    *(ushort *)(puVar17 + 4) = (ushort)bStack_e1;
    iVar7 = (*pcVar13)(puVar17,pcVar13);
    pcVar19 = pcVar19 + 0x10;
    puVar17 = puVar17 + 8;
    if (iVar7 != 0) break;
_L79:
    if (pcVar19 == pcVar15) {
      if (*(int *)((uint)bStack_e1 * 0x44 + *(int *)(_p_llm_env + 8)) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"llm_init.c",0x1b7,*(code **)(_r_plf_funcs_p + 8));
      }
      cVar2 = param_1[1];
      if (cVar2 == '\x01') {
_L87:
        memcpy((void *)(*(int *)(_p_llm_env + 8) + (uint)bStack_e1 * 0x44 + 4),
               (void *)(_p_llm_env + 0x12),6);
      }
      else if ((cVar2 == '\0') || (cVar2 == '\x02')) {
        iVar7 = *(int *)(_p_llm_env + 8) + (uint)bStack_e1 * 0x44;
        uVar4 = *(undefined2 *)(_p_llm_env + 0x10);
        *(undefined4 *)(iVar7 + 4) = *(undefined4 *)(_p_llm_env + 0xc);
        *(undefined2 *)(iVar7 + 8) = uVar4;
      }
      else {
        if (cVar2 == '\x03') goto _L87;
        (**(code **)(_r_plf_funcs_p + 0xc))(0,"llm_init.c",0x1cc,*(code **)(_r_plf_funcs_p + 0xc));
      }
      bVar1 = bStack_e1;
      iVar7 = _p_llm_env;
      uVar10 = (uint)bStack_e1;
      iVar16 = uVar10 * 0x44;
      puVar14 = (undefined4 *)(*(int *)(_p_llm_env + 8) + iVar16);
      *(undefined1 *)(puVar14 + 0x10) = 5;
      *puVar14 = param_1;
      memcpy(auStack_da,param_1 + 3,6);
      memcpy(auStack_d4,(void *)(iVar7 + 0x1d),5);
      bStack_ce = param_1[9];
      puVar14 = &uStack_e0;
      pcVar19 = param_1;
      puVar17 = local_a0;
      while( true ) {
        if (pcVar15 == pcVar19) break;
        *(undefined2 *)(puVar14 + 6) = *(undefined2 *)(pcVar19 + 10);
        *(undefined2 *)((int)puVar14 + 0x1a) = *(undefined2 *)(pcVar19 + 0xc);
        *(short *)(puVar14 + 7) = (short)(puVar17[5] >> 1);
        *(short *)((int)puVar14 + 0x1e) = (short)puVar17[6];
        *(undefined2 *)(puVar14 + 8) = *(undefined2 *)(pcVar19 + 0x12);
        *(undefined2 *)((int)puVar14 + 0x22) = *(undefined2 *)(pcVar19 + 0x14);
        puVar14 = puVar14 + 3;
        pcVar19 = pcVar19 + 0x10;
        puVar17 = puVar17 + 8;
      }
      if ((bStack_ce & 5) == 5) {
        iVar6 = uVar5 - 1;
        uVar11 = (uint)auStack_c8[1] + (uint)auStack_c8[iVar6 * 6 + 1];
        if (auStack_c8[0] < uVar11) {
          auStack_c8[0] = (ushort)uVar11;
        }
        if (auStack_c8[iVar6 * 6] < uVar11) {
          auStack_c8[iVar6 * 6] = (ushort)uVar11;
        }
      }
      cStack_cc = param_1[1];
      bStack_cd = bVar1;
      cStack_cb = param_1[2];
      cStack_ca = *param_1;
      iVar16 = *(int *)(iVar7 + 8) + iVar16;
      uStack_e0 = *(undefined4 *)(iVar16 + 4);
      uStack_dc = *(undefined2 *)(iVar16 + 8);
      uStack_cf = 1;
      uStack_a4 = *(undefined1 *)(iVar7 + 0xc6);
      if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
         ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
        (*(code *)*_bt_rf_coex_hooks_p)(uVar10,3,1);
      }
      iVar7 = (**(code **)(_r_ip_funcs_p + 0x494))(&uStack_e0,*(code **)(_r_ip_funcs_p + 0x494));
      if (iVar7 != 0) {
        iVar7 = 3;
      }
      uVar18 = 1;
      goto _L98;
    }
  }
  iVar7 = 0x3b;
  uVar18 = 0;
  goto _L98;
}

