/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_process_pkt_rx_aux_adv_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_process_pkt_rx_aux_adv_ind(int param_1,int param_2,char *param_3)

{
  bool bVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  undefined2 uVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  void *pvVar9;
  short *psVar10;
  undefined1 *puVar11;
  int iVar12;
  undefined2 *puVar13;
  byte bVar14;
  undefined1 uVar15;
  uint uVar16;
  int iVar17;
  short sVar18;
  short sVar19;
  uint uVar20;
  undefined4 auStack_44 [4];
  
  iVar17 = param_2 * 0x14;
  iVar7 = *(int *)(_lld_scan_env + param_1 * 4);
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  sVar2 = *(short *)(iVar8 + iVar17 + 0x12);
  *(ushort *)(iVar7 + 0x36) = (ushort)(byte)param_3[5];
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  *(byte *)(iVar7 + 0x72) = (byte)((ushort)*(undefined2 *)(iVar8 + iVar17 + 6) >> 0xe);
  puVar11 = _lld_scan_sync_env;
  if (*param_3 == '\0') {
    *(undefined1 *)(iVar7 + 0x6e) = 0xff;
    *(undefined1 *)(iVar7 + 0x3d) = 0;
    return;
  }
  if ((*(ushort *)(param_3 + 6) & 0x100) == 0) {
    sVar18 = 0;
    sVar19 = 0;
    if ((((*(byte *)(_lld_scan_env + 0x15) & 0xfd) == 1) &&
        (sVar19 = sVar18, *(char *)(iVar7 + 0x6f) == -1)) && ((_DAT_60031000 >> 10 & 1) != 0)) {
      *(undefined1 *)(iVar7 + 0x6e) = 0xff;
    }
  }
  else {
    if ((param_3[1] == '\0') && (*(char *)(iVar7 + 0x6f) != -1)) {
      *(ushort *)(param_3 + 6) = *(ushort *)(param_3 + 6) & 0xfeff;
    }
    else {
      iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      bVar14 = (byte)(*(ushort *)(iVar8 + iVar17 + 4) >> 6) & 1;
      param_3[8] = bVar14;
      *(byte *)(iVar7 + 0x6f) = bVar14;
      pvVar9 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                 ((ushort)(byte)param_3[3] + sVar2,*(code **)(_r_plf_funcs_p + 0xbc)
                                 );
      memcpy((void *)(iVar7 + 0x5c),pvVar9,6);
      if (((*(char *)(_lld_scan_env + 0x15) == '\x01') ||
          ((*(char *)(_lld_scan_env + 0x15) == '\x03' && ((*(ushort *)(param_3 + 6) & 0x200) == 0)))
          ) && (iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))
                                  (0x1000,*(code **)(_r_plf_funcs_p + 0xbc)),
               -1 < (int)((uint)*(ushort *)(iVar8 + iVar17 + 2) << 0x14))) {
        *(undefined1 *)(iVar7 + 0x6e) = 0xff;
      }
    }
    sVar19 = 6;
  }
  iVar8 = _r_plf_funcs_p;
  if ((*(ushort *)(param_3 + 6) & 0x200) != 0) {
    if (*(byte *)(iVar7 + 0x6d) == 4) {
      *(ushort *)(param_3 + 6) = *(ushort *)(param_3 + 6) & 0xfdff;
    }
    else {
      *(byte *)(iVar7 + 0x6d) = *(byte *)(iVar7 + 0x6d) | 4;
      iVar8 = (**(code **)(iVar8 + 0xbc))(0x1000,*(code **)(iVar8 + 0xbc));
      *(byte *)(iVar7 + 0x70) = (byte)(*(ushort *)(iVar8 + iVar17 + 4) >> 7) & 1;
      param_3[2] = (char)sVar19;
    }
    sVar19 = sVar19 + 6;
  }
  if ((*(ushort *)(param_3 + 6) & 0x400) != 0) {
    sVar19 = sVar19 + 1;
  }
  if (-1 < (int)((uint)*(ushort *)(param_3 + 6) << 0x14)) {
    *(undefined1 *)(iVar7 + 0x6e) = 0xff;
    return;
  }
  psVar10 = (short *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (sVar2 + sVar19,*(code **)(_r_plf_funcs_p + 0xbc));
  bVar1 = *(short *)(iVar7 + 0x34) != *psVar10;
  if (bVar1) {
    *(undefined1 *)(iVar7 + 0x6e) = 0xff;
  }
  sVar18 = sVar19 + 2;
  if (*(char *)(iVar7 + 0x6e) == -1) {
    if ((*(ushort *)(param_3 + 6) & 0x1000) != 0) goto _L446;
  }
  else {
    if ((*(ushort *)(param_3 + 6) & 0x1000) == 0) {
      if (((*(byte *)(iVar7 + 0x6d) & 2) == 0) || (*(char *)(iVar7 + 0x39) != '\x01')) {
        *(undefined1 *)(iVar7 + 0x6e) = 0;
        *(undefined1 *)(iVar7 + 0x3d) = 0;
      }
      else {
        *(undefined1 *)(iVar7 + 0x6e) = 0;
        *(undefined1 *)(iVar7 + 0x3d) = 2;
      }
      goto _L396;
    }
    pvVar9 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (sVar2 + sVar18,*(code **)(_r_plf_funcs_p + 0xbc));
    memcpy(auStack_44,pvVar9,3);
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    if ((*(ushort *)(iVar8 + iVar17 + 2) >> 9 & 1) == 0) {
      iVar8 = (**(code **)(_r_ip_funcs_p + 0x224))
                        (iVar7 + 0x48,param_2,*(code **)(_r_ip_funcs_p + 0x224));
      uVar15 = 1;
      if (iVar8 != 0) goto _L445;
      *(undefined1 *)(iVar7 + 0x6e) = 2;
    }
    else {
      *(undefined4 *)(iVar7 + 0x2c) = auStack_44[0];
      uVar15 = 2;
_L445:
      *(undefined1 *)(iVar7 + 0x3e) = uVar15;
    }
    *(undefined1 *)(iVar7 + 0x3d) = 3;
_L446:
    sVar18 = sVar19 + 5;
  }
_L396:
  if (-1 < (int)((uint)*(ushort *)(param_3 + 6) << 0x12)) goto _L398;
  if (bVar1 || puVar11 == (undefined1 *)0x0) {
_L399:
    puVar13 = (undefined2 *)
              (**(code **)(_r_plf_funcs_p + 0xbc))
                        (sVar2 + 2 + sVar18,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined2 *)(iVar7 + 0x76) = *puVar13;
  }
  else {
    uVar3 = *(ushort *)(iVar7 + 0x68);
    iVar8 = (**(code **)(_r_ip_funcs_p + 0x440))
                      (param_1,param_2,*(undefined1 *)(iVar7 + 0x6f),*(undefined4 *)(iVar7 + 0x5c),
                       *(undefined4 *)(iVar7 + 0x60),uVar3 >> 0xc,*(code **)(_r_ip_funcs_p + 0x440))
    ;
    if (iVar8 == 0) goto _L399;
    puVar11 = (undefined1 *)
              (**(code **)(_r_modules_funcs_p + 200))
                        (0x203,0,0xff,0x30,*(code **)(_r_modules_funcs_p + 200));
    iVar8 = (**(code **)(_r_ip_funcs_p + 0x444))
                      (puVar11 + 2,sVar2 + sVar18,*(code **)(_r_ip_funcs_p + 0x444));
    if (iVar8 == 0) {
      if (*(short *)(puVar11 + 2) == 0) {
        *(undefined2 *)(iVar7 + 0x76) = *(undefined2 *)(puVar11 + 6);
      }
      (**(code **)(_r_modules_funcs_p + 0xd8))(puVar11 + -0xc,*(code **)(_r_modules_funcs_p + 0xd8))
      ;
    }
    else {
      *puVar11 = *_lld_scan_sync_env;
      iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      puVar11[0x1e] = (byte)((ushort)*(undefined2 *)(iVar8 + iVar17 + 6) >> 0xe);
      iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar4 = *(ushort *)(iVar8 + iVar17 + 10);
      if ((uVar4 & 0xf000) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",1000,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar8 = _r_plf_funcs_p;
      *(uint *)(puVar11 + 0x18) = CONCAT22(uVar4,*(undefined2 *)(iVar12 + iVar17 + 8));
      iVar8 = (**(code **)(iVar8 + 0xbc))(0x1000,*(code **)(iVar8 + 0xbc));
      uVar16 = ((uint)*(ushort *)(&lld_exp_sync_pos_tab + (uint)(byte)puVar11[0x1e] * 2) * -2 +
               0x270) - (*(ushort *)(iVar8 + iVar17 + 0xc) & 0x3ff);
      uVar20 = (uint)(short)uVar16;
      if (((DAT_00015090 & 2) != 0) && (((byte)puVar11[0x1e] - 2 & 0xff) < 2)) {
        uVar20 = (int)(((uVar16 & 0xffff) + (uint)_DAT_00015092 * -2) * 0x10000) >> 0x10;
      }
      if (0x751 < (uVar20 + 0x4e1 & 0xffff)) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x6b6,*(code **)(_r_plf_funcs_p + 8));
      }
      for (; (int)uVar20 < 0; uVar20 = (int)(((uVar20 & 0xffff) + 0x271) * 0x10000) >> 0x10) {
        *(uint *)(puVar11 + 0x18) = *(int *)(puVar11 + 0x18) - 1U & 0xfffffff;
      }
      *(short *)(puVar11 + 0x1c) = (short)uVar20;
      iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      puVar6 = _lld_scan_sync_env;
      uVar5 = *(undefined2 *)(iVar17 + 0xe + iVar8);
      puVar11[0x1f] = (byte)(uVar3 >> 0xc);
      *(undefined2 *)(puVar11 + 0x20) = uVar5;
      puVar11[0x22] = puVar6[3];
      memcpy(puVar11 + 0x23,puVar6 + 4,6);
      (**(code **)(_r_modules_funcs_p + 0xe0))(puVar11,*(code **)(_r_modules_funcs_p + 0xe0));
      (**(code **)(_r_modules_funcs_p + 0x110))
                (_lld_scan_sync_env,*(code **)(_r_modules_funcs_p + 0x110));
      _lld_scan_sync_env = (undefined1 *)0x0;
    }
  }
  sVar18 = sVar18 + 0x12;
_L398:
  if ((int)((uint)*(ushort *)(param_3 + 6) << 0x11) < 0) {
    puVar11 = (undefined1 *)
              (**(code **)(_r_plf_funcs_p + 0xbc))(sVar2 + sVar18,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    *(undefined1 *)(iVar7 + 0x73) = *puVar11;
  }
  return;
}

