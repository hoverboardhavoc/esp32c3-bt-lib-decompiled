/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_scan_start(char param_1,undefined2 *param_2)

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  undefined2 uVar5;
  bool bVar6;
  byte bVar7;
  byte bVar8;
  byte *unaff_s1;
  char cVar9;
  int *piVar10;
  void *pvVar11;
  int iVar12;
  int iVar13;
  ushort uVar14;
  bool bVar15;
  ushort uVar16;
  undefined4 uVar17;
  uint uVar18;
  uint uVar19;
  code *pcVar20;
  int iVar21;
  uint *puVar22;
  int iVar23;
  short sVar24;
  uint uStack_7c;
  int *piStack_74;
  int *piStack_70;
  byte bStack_49;
  byte abStack_48 [20];
  
  if (_lld_scan_env != (int *)0x0) {
    return 0xc;
  }
  piVar10 = (int *)(**(code **)(_r_modules_funcs_p + 0x120))
                             (0x20,0,*(code **)(_r_modules_funcs_p + 0x120));
  _lld_scan_env = piVar10;
  if (piVar10 == (int *)0x0) {
    (**(code **)(_r_plf_funcs_p + 8))("lld_scan.c",0xcad,*(code **)(_r_plf_funcs_p + 8));
    return 0xc;
  }
  uStack_7c = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  memset(_lld_scan_env,0,0x20);
  if ((*(byte *)((int)param_2 + 7) & 1) != 0) {
    pvVar11 = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                                (0x84,0,*(code **)(_r_modules_funcs_p + 0x120));
    *piVar10 = (int)pvVar11;
    if (pvVar11 != (void *)0x0) {
      memset(pvVar11,0,0x84);
      uVar17 = *(undefined4 *)(_r_ip_funcs_p + 0x3ec);
      *(undefined4 *)((int)pvVar11 + 0x20) = *(undefined4 *)(_r_ip_funcs_p + 1000);
      *(undefined4 *)((int)pvVar11 + 0x18) = uVar17;
      *(undefined1 *)((int)pvVar11 + 0x16) = rwip_priority;
      uVar16 = param_2[6];
      uVar18 = (uint)uVar16 * 0x4e2;
      if (_sch_slice_params < uVar18) {
        uVar18 = (uint)_sch_slice_params;
      }
      *(uint *)((int)pvVar11 + 0x10) = uVar18;
      *(ushort *)((int)pvVar11 + 0x14) = DAT_00015031 & 0xf | 0x6000;
      uVar5 = param_2[4];
      *(ushort *)((int)pvVar11 + 0x32) = uVar16;
      *(undefined2 *)((int)pvVar11 + 0x30) = uVar5;
      cVar9 = *(char *)(param_2 + 8);
      *(uint *)((int)pvVar11 + 0x24) = (uint)uVar16;
      *(char *)((int)pvVar11 + 0x38) = param_1;
      *(char *)((int)pvVar11 + 0x39) = cVar9;
      bVar6 = cVar9 == '\x01';
      *(byte *)(piVar10 + 3) = *(byte *)(piVar10 + 3) | 1;
      goto _L771;
    }
    (**(code **)(_r_plf_funcs_p + 8))("lld_scan.c",0xb75,*(code **)(_r_plf_funcs_p + 8));
  }
  bVar6 = false;
_L771:
  if ((*(byte *)((int)param_2 + 7) & 4) != 0) {
    pvVar11 = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                                (0x84,0,*(code **)(_r_modules_funcs_p + 0x120));
    piVar10[1] = (int)pvVar11;
    if (pvVar11 == (void *)0x0) {
      (**(code **)(_r_plf_funcs_p + 8))("lld_scan.c",0xba1,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      memset(pvVar11,0,0x84);
      uVar17 = *(undefined4 *)(_r_ip_funcs_p + 0x3ec);
      *(undefined4 *)((int)pvVar11 + 0x20) = *(undefined4 *)(_r_ip_funcs_p + 1000);
      *(undefined4 *)((int)pvVar11 + 0x18) = uVar17;
      *(undefined1 *)((int)pvVar11 + 0x16) = rwip_priority;
      uVar16 = param_2[7];
      uVar18 = (uint)uVar16 * 0x4e2;
      if (_sch_slice_params < uVar18) {
        uVar18 = (uint)_sch_slice_params;
      }
      *(uint *)((int)pvVar11 + 0x10) = uVar18;
      *(ushort *)((int)pvVar11 + 0x14) = DAT_00015031 & 0xf | 0x6000;
      uVar5 = param_2[5];
      *(ushort *)((int)pvVar11 + 0x32) = uVar16;
      *(undefined2 *)((int)pvVar11 + 0x30) = uVar5;
      cVar9 = *(char *)((int)param_2 + 0x11);
      *(undefined1 *)((int)pvVar11 + 0x3b) = 3;
      *(undefined1 *)((int)pvVar11 + 0x40) = 1;
      *(undefined1 *)((int)pvVar11 + 0x38) = 0xb;
      *(char *)((int)pvVar11 + 0x39) = cVar9;
      *(uint *)((int)pvVar11 + 0x24) = (uint)uVar16;
      bVar6 = (bool)(cVar9 == '\x01' | bVar6);
      *(byte *)(piVar10 + 3) = *(byte *)(piVar10 + 3) | 2;
    }
  }
  memcpy((void *)((int)piVar10 + 0xe),param_2,6);
  uVar18 = 0xffffffff;
  *(undefined1 *)(piVar10 + 5) = *(undefined1 *)(param_2 + 9);
  uVar1 = *(undefined1 *)((int)param_2 + 0x13);
  *(char *)((int)piVar10 + 0xd) = param_1;
  *(undefined1 *)((int)piVar10 + 0x15) = uVar1;
  *(undefined1 *)((int)piVar10 + 0x16) = *(undefined1 *)(param_2 + 10);
  if ((ushort)param_2[0xb] != 0) {
    uVar18 = (uint)(ushort)param_2[0xb] * 0x20 + uStack_7c & 0xfffffff;
  }
  piVar10[2] = uVar18;
  piStack_74 = piVar10;
  do {
    abStack_48[0] = 0;
    bStack_49 = 0;
    iVar23 = *piStack_74;
    if (iVar23 != 0) {
      uVar1 = *(undefined1 *)(param_2 + 3);
      *(undefined1 *)(iVar23 + 0x3d) = 0;
      bVar2 = *(byte *)(iVar23 + 0x38);
      uVar18 = (uint)bVar2;
      *(undefined1 *)(iVar23 + 0x42) = uVar1;
      *(undefined1 *)(iVar23 + 0x3f) = 9;
      iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar21 = uVar18 * 0x5a;
      *(undefined2 *)(iVar21 + 0xc + iVar12) = 0xbed6;
      iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar21 + 0xe + iVar12) = 0x8e89;
      iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar21 + 0x10 + iVar12) = 0x5555;
      iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar21 + 0x12 + iVar12) = 0x55;
      iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar21 + 0x46 + iVar12) = 0;
      if (_lld_scan_sync_env == 0) {
        bVar15 = false;
        uVar19 = 0;
      }
      else {
        bVar15 = *(char *)(_lld_scan_sync_env + 1) != '\0';
        uVar19 = (uint)bVar15;
      }
      *(bool *)(iVar23 + 0x44) = bVar15;
      uVar16 = param_2[9];
      bVar3 = *(byte *)((int)piVar10 + 0x15);
      bVar4 = *(byte *)(param_2 + 10);
      uVar14 = 1;
      if (*(char *)((int)piVar10 + 0x16) == '\0') {
        uVar14 = (ushort)((uint)piVar10[5] >> 1) & 1;
      }
      iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar21 + 0x14 + iVar12) =
           (ushort)bVar4 << 6 | (ushort)((uVar16 >> 1 & 1) << 2) | (ushort)bVar3 << 8 |
           (ushort)(uVar19 << 3) | uVar14;
      iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar21 + 0x16 + iVar12) = 0x8027;
      iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar21 + 0x28 + iVar12) = 0;
      iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar21 + 0x2a + iVar12) = 0;
      uVar16 = _sdk_cfg_priv_opts;
      bVar3 = *(byte *)(param_2 + 9);
      if (0x1f < uVar18) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0xe6,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar21 + 2 + iVar12) =
           (uVar16 & 0xff) << 5 | (ushort)bVar2 | (ushort)((bVar3 & 1) << 7) | 0x800;
      uVar5 = *param_2;
      iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar21 + 6 + iVar12) = uVar5;
      uVar5 = param_2[1];
      iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar21 + 8 + iVar12) = uVar5;
      uVar5 = param_2[2];
      iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar21 + 10 + iVar12) = uVar5;
      if (*(char *)(iVar23 + 0x39) == '\x01') {
        sVar24 = (ushort)(byte)(param_1 * '\t') * 0xe + 0x1400;
        iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400);
        iVar12 = _r_plf_funcs_p;
        *(short *)(iVar13 + iVar21 + 0x1c) = sVar24;
        iVar12 = (**(code **)(iVar12 + 0xbc))(0x400,*(code **)(iVar12 + 0xbc));
        *(short *)(iVar12 + iVar21 + 0x34) = sVar24;
        cVar9 = (-(*(char *)(iVar23 + 0x42) == '\0') & 0xfeU) + 0xb;
      }
      else {
        iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400);
        iVar12 = _r_plf_funcs_p;
        *(undefined2 *)(iVar13 + iVar21 + 0x1c) = 0;
        iVar12 = (**(code **)(iVar12 + 0xbc))(0x400,*(code **)(iVar12 + 0xbc));
        *(undefined2 *)(iVar12 + iVar21 + 0x34) = 0;
        cVar9 = (-(*(char *)(iVar23 + 0x42) == '\0') & 0xfeU) + 10;
      }
      iVar12 = _r_modules_funcs_p;
      *(char *)(iVar23 + 0x3a) = cVar9;
      (**(code **)(iVar12 + 0x1e0))(uVar18,&bStack_49,abStack_48,*(code **)(iVar12 + 0x1e0));
      iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar21 + 0x18 + iVar12) = 0;
      (**(code **)(_r_ip_funcs_p + 0x434))
                (uVar18,*(undefined1 *)(iVar23 + 0x3a),*(code **)(_r_ip_funcs_p + 0x434));
      bVar8 = abStack_48[0];
      bVar7 = bStack_49;
      uVar19 = (uint)rwip_coex_cfg;
      bVar3 = rwip_coex_cfg >> 1;
      bVar4 = rwip_coex_cfg >> 2;
      bVar2 = *(byte *)(iVar23 + 0x3a);
      if ((bStack_49 & 0xfe) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x42,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((bVar8 & 0xfe) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x43,*(code **)(_r_plf_funcs_p + 8));
      }
      if (0x1f < bVar2) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x45,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar12 + iVar21) =
           (ushort)bVar7 << 7 | (ushort)bVar8 << 6 | (ushort)bVar2 | (ushort)((uVar19 & 1) << 10) |
           (ushort)((bVar3 & 1) << 9) | (ushort)((bVar4 & 1) << 8) | 0x20;
      bVar2 = *(byte *)(iVar23 + 0x3b);
      if ((bVar2 & 0xfc) == 0) {
        if (3 < bVar2) goto _L789;
      }
      else {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",399,*(code **)(_r_plf_funcs_p + 8));
_L789:
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",400,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar21 + 4 + iVar12) =
           (ushort)bVar2 | (ushort)((int)(short)(ushort)bVar2 << 2) | 0x1000;
      if (g_scan_forever == '\0') {
        uVar5 = *(undefined2 *)(iVar23 + 0x24);
        iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400);
        uVar19 = *(uint *)(iVar23 + 0x24);
        *(undefined2 *)(iVar12 + iVar21 + 0x20) = uVar5;
        if (0x3fff < uVar19) {
          uVar19 = 0x3fff;
        }
        iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar16 = (ushort)uVar19 | 0x8000;
      }
      else {
        iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400);
        iVar12 = _r_plf_funcs_p;
        *(undefined2 *)(iVar13 + iVar21 + 0x20) = 0;
        iVar12 = (**(code **)(iVar12 + 0xbc))(0x400,*(code **)(iVar12 + 0xbc));
        uVar16 = 0xbfff;
      }
      *(ushort *)(iVar12 + iVar21 + 0x1a) = uVar16;
      bVar2 = *(byte *)(iVar23 + 0x3a);
      if (bVar2 == 10) {
        uVar17 = 7;
        pcVar20 = *(code **)(_r_modules_funcs_p + 0x1a0);
_L881:
        unaff_s1 = (byte *)(*pcVar20)(uVar17,pcVar20);
      }
      else {
        if (bVar2 < 0xb) {
          if (bVar2 == 8) {
            uVar17 = 5;
            pcVar20 = *(code **)(_r_modules_funcs_p + 0x1a0);
          }
          else {
            if (bVar2 != 9) goto _L798;
            uVar17 = 6;
            pcVar20 = *(code **)(_r_modules_funcs_p + 0x1a0);
          }
          goto _L881;
        }
        if (bVar2 == 0xb) {
          uVar17 = 8;
          pcVar20 = *(code **)(_r_modules_funcs_p + 0x1a0);
          goto _L881;
        }
_L798:
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0xc4f,*(code **)(_r_plf_funcs_p + 8));
      }
      if (unaff_s1 != (byte *)0x0) {
        bVar2 = unaff_s1[1];
        if (0xb < uVar18) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x299b,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((bVar2 & 0xf0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x299d,*(code **)(_r_plf_funcs_p + 8));
        }
        puVar22 = (uint *)((uVar18 + 0x1800c4cb) * 4);
        *puVar22 = *puVar22 & 0xfffff0ff | (uint)bVar2 << 8;
        bVar2 = *unaff_s1;
        if (0xb < uVar18) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x294a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar22 = *puVar22 & 0xbfffffff | (uint)bVar2 << 0x1e;
        bVar2 = unaff_s1[3];
        if (0xb < uVar18) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x29bb,*(code **)(_r_plf_funcs_p + 8));
        }
        if (0xf < bVar2) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x29bd,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar22 = *puVar22 & 0xfffffff0 | (uint)bVar2;
        bVar2 = unaff_s1[2];
        if (0xb < uVar18) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x295a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar22 = *puVar22 & 0xdfffffff | (uint)bVar2 << 0x1d;
        bVar2 = unaff_s1[7];
        if (0xb < uVar18) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x298b,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((bVar2 & 0xf0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x298d,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar22 = *puVar22 & 0xffff0fff | (uint)bVar2 << 0xc;
        bVar2 = unaff_s1[8];
        if (0xb < uVar18) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x29ab,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((bVar2 & 0xf0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x29ad,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar22 = *puVar22 & 0xffffff0f | (uint)bVar2 << 4;
        bVar2 = unaff_s1[9];
        if (0xb < uVar18) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x297b,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((bVar2 & 0xf0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x297d,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar22 = *puVar22 & 0xfff0ffff | (uint)bVar2 << 0x10;
        uVar16 = *(ushort *)(unaff_s1 + 10);
        if (0xb < uVar18) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x296a,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((uVar16 >> 9 & 7) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x296c,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar22 = *puVar22 & 0xe00fffff | (uint)uVar16 << 0x14;
        bVar2 = unaff_s1[6];
        if (0xb < uVar18) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x293a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar22 = *puVar22 & 0x7fffffff | (uint)bVar2 << 0x1f;
        if (2 < _g_bt_plf_log_level) {
          ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[SCAN[%d]] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                     ,uVar18,puVar22,*(undefined1 *)(iVar23 + 0x3a),unaff_s1[2],unaff_s1[3],
                     *unaff_s1,unaff_s1[1]);
        }
      }
    }
    piStack_74 = piStack_74 + 1;
    if (piVar10 + 2 == piStack_74) {
      if (bVar6) {
        iVar23 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        iVar12 = (uint)(byte)(param_1 * '\t') * 0xe;
        iVar21 = iVar12 + 2;
        uVar16 = *(ushort *)(iVar23 + iVar21);
        iVar23 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        pcVar20 = *(code **)(_r_plf_funcs_p + 0xbc);
        *(ushort *)(iVar23 + iVar21) = uVar16 & 0xfff0 | 3;
        iVar23 = (*pcVar20)(0x1400,pcVar20);
        *(undefined2 *)(iVar12 + 4 + iVar23) = 0;
        iVar23 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar16 = *(ushort *)(iVar23 + iVar21);
        iVar23 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        pcVar20 = *(code **)(_r_plf_funcs_p + 0xbc);
        *(ushort *)(iVar21 + iVar23) = uVar16 & 0xff | 0xc00;
        iVar23 = (*pcVar20)(0x1400,pcVar20);
        uVar16 = *(ushort *)(iVar23 + iVar12);
        iVar21 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        iVar23 = _r_plf_funcs_p;
        *(ushort *)(iVar21 + iVar12) = uVar16 & 0x8000;
        iVar23 = (**(code **)(iVar23 + 0xbc))(0x1400,*(code **)(iVar23 + 0xbc));
        uVar16 = *(ushort *)(iVar23 + iVar12);
        iVar23 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        pcVar20 = *(code **)(_r_modules_funcs_p + 0x1a0);
        *(ushort *)(iVar23 + iVar12) = (ushort)(((uint)uVar16 << 0x11) >> 0x11);
        iVar23 = (*pcVar20)(6,pcVar20);
        if (iVar23 != 0) {
          if (2 < _g_bt_plf_log_level) {
            ets_printf("TX PTI [ACT_SCAN] [EN%d] [%d] \n",*(undefined1 *)(iVar23 + 4),
                       *(undefined1 *)(iVar23 + 5));
          }
          bVar2 = *(byte *)(iVar23 + 5);
          if ((bVar2 & 0xf0) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
          }
          iVar12 = iVar12 + 10;
          iVar21 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
          uVar16 = *(ushort *)(iVar21 + iVar12);
          iVar21 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
          pcVar20 = *(code **)(_r_plf_funcs_p + 0xbc);
          *(ushort *)(iVar21 + iVar12) = uVar16 & 0xf0ff | (ushort)bVar2 << 8;
          bVar2 = *(byte *)(iVar23 + 4);
          iVar23 = (*pcVar20)(0x1400,pcVar20);
          uVar16 = *(ushort *)(iVar23 + iVar12);
          iVar23 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar12 + iVar23) = uVar16 & 0xefff | (ushort)bVar2 << 0xc;
        }
      }
      _DAT_60031124 = 0x10001;
      uVar18 = (uint)_sdk_cfg_priv_opts;
      if (0x1ff < uVar18) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x29ed,*(code **)(_r_plf_funcs_p + 8));
      }
      _DAT_60031364 = _DAT_60031364 & 0xfffffe00 | uVar18;
      piStack_70 = piVar10;
      do {
        iVar23 = *piStack_70;
        if (iVar23 != 0) {
          *(uint *)(iVar23 + 4) = uStack_7c;
          *(uint *)(iVar23 + 0x28) = uStack_7c;
          iVar12 = (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar23,*(code **)(_r_ip_funcs_p + 0x6b0));
          if (iVar12 == 0) {
            *(undefined1 *)(iVar23 + 0x43) = 0;
            uStack_7c = (uint)*(ushort *)(iVar23 + 0x32) * 2 + uStack_7c & 0xfffffff;
            *(undefined2 *)(iVar23 + 0x36) = 0;
          }
          else {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0xca1,*(code **)(_r_plf_funcs_p + 8));
          }
        }
        iVar23 = _r_modules_funcs_p;
        piStack_70 = piStack_70 + 1;
      } while (piVar10 + 2 != piStack_70);
      *(undefined1 *)((int)piVar10 + 0x17) = 0;
      iVar23 = (**(code **)(iVar23 + 0x2c4))(*(code **)(iVar23 + 0x2c4));
      piVar10[6] = iVar23;
      piVar10[7] = iVar23;
      return 0;
    }
  } while( true );
}

