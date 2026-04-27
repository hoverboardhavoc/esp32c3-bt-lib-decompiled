/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_scan_start(char param_1,undefined2 *param_2)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  undefined2 uVar6;
  bool bVar7;
  byte *unaff_s1;
  undefined1 uVar8;
  int *piVar9;
  uint uVar10;
  void *pvVar11;
  int iVar12;
  int iVar13;
  short sVar14;
  ushort uVar15;
  undefined4 uVar16;
  uint uVar17;
  uint uVar18;
  code *pcVar19;
  int iVar20;
  uint *puVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  int *piStack_7c;
  int *piStack_78;
  byte bStack_49;
  byte abStack_48 [20];
  
  if (_lld_scan_env == (int *)0x0) {
    piVar9 = (int *)(**(code **)(_r_modules_funcs_p + 0x120))
                              (0x20,0,*(code **)(_r_modules_funcs_p + 0x120));
    _lld_scan_env = piVar9;
    if (piVar9 != (int *)0x0) {
      uVar10 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
      memset(_lld_scan_env,0,0x20);
      bVar7 = false;
      if ((*(byte *)((int)param_2 + 7) & 1) != 0) {
        pvVar11 = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                                    (0x84,0,*(code **)(_r_modules_funcs_p + 0x120));
        *piVar9 = (int)pvVar11;
        if (pvVar11 == (void *)0x0) {
          (**(code **)(_r_plf_funcs_p + 8))("lld_scan.c",0xbc8,*(code **)(_r_plf_funcs_p + 8));
        }
        else {
          memset(pvVar11,0,0x84);
          uVar16 = *(undefined4 *)(_r_ip_funcs_p + 0x3ec);
          *(undefined4 *)((int)pvVar11 + 0x20) = *(undefined4 *)(_r_ip_funcs_p + 1000);
          *(undefined4 *)((int)pvVar11 + 0x18) = uVar16;
          *(undefined1 *)((int)pvVar11 + 0x16) = rwip_priority;
          uVar15 = param_2[6];
          uVar17 = (uint)uVar15 * 0x4e2;
          if (_sch_slice_params < uVar17) {
            uVar17 = (uint)_sch_slice_params;
          }
          *(uint *)((int)pvVar11 + 0x10) = uVar17;
          *(ushort *)((int)pvVar11 + 0x14) = DAT_00015031 & 0xf | 0x6000;
          uVar6 = param_2[4];
          *(ushort *)((int)pvVar11 + 0x32) = uVar15;
          *(undefined2 *)((int)pvVar11 + 0x30) = uVar6;
          cVar1 = *(char *)(param_2 + 8);
          *(uint *)((int)pvVar11 + 0x24) = (uint)uVar15;
          *(char *)((int)pvVar11 + 0x38) = param_1;
          *(char *)((int)pvVar11 + 0x39) = cVar1;
          bVar7 = cVar1 == '\x01';
          *(byte *)(piVar9 + 3) = *(byte *)(piVar9 + 3) | 1;
        }
      }
      if ((*(byte *)((int)param_2 + 7) & 4) != 0) {
        pvVar11 = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                                    (0x84,0,*(code **)(_r_modules_funcs_p + 0x120));
        piVar9[1] = (int)pvVar11;
        if (pvVar11 == (void *)0x0) {
          (**(code **)(_r_plf_funcs_p + 8))("lld_scan.c",0xbf4,*(code **)(_r_plf_funcs_p + 8));
        }
        else {
          memset(pvVar11,0,0x84);
          uVar16 = *(undefined4 *)(_r_ip_funcs_p + 0x3ec);
          *(undefined4 *)((int)pvVar11 + 0x20) = *(undefined4 *)(_r_ip_funcs_p + 1000);
          *(undefined4 *)((int)pvVar11 + 0x18) = uVar16;
          *(undefined1 *)((int)pvVar11 + 0x16) = rwip_priority;
          uVar15 = param_2[7];
          uVar17 = (uint)uVar15 * 0x4e2;
          if (_sch_slice_params < uVar17) {
            uVar17 = (uint)_sch_slice_params;
          }
          *(uint *)((int)pvVar11 + 0x10) = uVar17;
          *(ushort *)((int)pvVar11 + 0x14) = DAT_00015031 & 0xf | 0x6000;
          uVar6 = param_2[5];
          *(ushort *)((int)pvVar11 + 0x32) = uVar15;
          *(undefined2 *)((int)pvVar11 + 0x30) = uVar6;
          cVar1 = *(char *)((int)param_2 + 0x11);
          *(undefined1 *)((int)pvVar11 + 0x3b) = 3;
          *(undefined1 *)((int)pvVar11 + 0x40) = 1;
          *(undefined1 *)((int)pvVar11 + 0x38) = 0xb;
          *(char *)((int)pvVar11 + 0x39) = cVar1;
          *(uint *)((int)pvVar11 + 0x24) = (uint)uVar15;
          bVar7 = (bool)(cVar1 == '\x01' | bVar7);
          *(byte *)(piVar9 + 3) = *(byte *)(piVar9 + 3) | 2;
        }
      }
      memcpy((void *)((int)piVar9 + 0xe),param_2,6);
      uVar17 = 0xffffffff;
      *(undefined1 *)(piVar9 + 5) = *(undefined1 *)(param_2 + 9);
      uVar8 = *(undefined1 *)((int)param_2 + 0x13);
      *(char *)((int)piVar9 + 0xd) = param_1;
      *(undefined1 *)((int)piVar9 + 0x15) = uVar8;
      *(undefined1 *)((int)piVar9 + 0x16) = *(undefined1 *)(param_2 + 10);
      if ((ushort)param_2[0xb] != 0) {
        uVar17 = (uint)(ushort)param_2[0xb] * 0x20 + uVar10 & 0xfffffff;
      }
      piVar9[2] = uVar17;
      sVar14 = (ushort)(byte)(param_1 * '\t') * 0xe + 0x1400;
      piStack_7c = piVar9;
      do {
        bStack_49 = 0;
        abStack_48[0] = 0;
        iVar22 = *piStack_7c;
        if (iVar22 != 0) {
          bVar2 = *(byte *)(iVar22 + 0x38);
          uVar23 = (uint)bVar2;
          iVar20 = uVar23 * 0x5a;
          *(undefined1 *)(iVar22 + 0x42) = *(undefined1 *)(param_2 + 3);
          *(undefined1 *)(iVar22 + 0x3f) = 9;
          iVar12 = _r_plf_funcs_p;
          *(undefined1 *)(iVar22 + 0x3d) = 0;
          iVar12 = (**(code **)(iVar12 + 0xbc))(0x400,*(code **)(iVar12 + 0xbc));
          *(undefined2 *)(iVar20 + 0xc + iVar12) = 0xbed6;
          iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(undefined2 *)(iVar20 + 0xe + iVar12) = 0x8e89;
          iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(undefined2 *)(iVar20 + 0x10 + iVar12) = 0x5555;
          iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(undefined2 *)(iVar20 + 0x12 + iVar12) = 0x55;
          iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(undefined2 *)(iVar20 + 0x46 + iVar12) = 0;
          uVar17 = 0;
          if (_lld_scan_sync_env != 0) {
            uVar17 = (uint)(*(char *)(_lld_scan_sync_env + 1) != '\0');
          }
          *(char *)(iVar22 + 0x44) = (char)uVar17;
          bVar3 = *(byte *)(param_2 + 9);
          bVar4 = *(byte *)((int)piVar9 + 0x15);
          bVar5 = *(byte *)(param_2 + 10);
          uVar15 = 1;
          if (*(char *)((int)piVar9 + 0x16) == '\0') {
            uVar15 = *(byte *)(piVar9 + 5) >> 1 & 1;
          }
          iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar20 + 0x14 + iVar12) =
               (ushort)bVar5 << 6 | (ushort)((bVar3 >> 1 & 1) << 2) | (ushort)bVar4 << 8 |
               (ushort)(uVar17 << 3) | uVar15;
          iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(undefined2 *)(iVar20 + 0x16 + iVar12) = 0x8027;
          iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(undefined2 *)(iVar20 + 0x28 + iVar12) = 0;
          iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(undefined2 *)(iVar20 + 0x2a + iVar12) = 0;
          bVar3 = *(byte *)(param_2 + 9);
          uVar15 = (ushort)DAT_0001505a;
          if ((bVar2 & 0xe0) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0xe6,*(code **)(_r_plf_funcs_p + 8));
          }
          iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar20 + 2 + iVar12) =
               uVar15 << 5 | (ushort)bVar2 | (ushort)((bVar3 & 1) << 7) | 0x800;
          uVar6 = *param_2;
          iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(undefined2 *)(iVar20 + 6 + iVar12) = uVar6;
          uVar6 = param_2[1];
          iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(undefined2 *)(iVar20 + 8 + iVar12) = uVar6;
          uVar6 = param_2[2];
          iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(undefined2 *)(iVar20 + 10 + iVar12) = uVar6;
          if (*(char *)(iVar22 + 0x39) == '\x01') {
            iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
            *(short *)(iVar12 + iVar20 + 0x1c) = sVar14;
            iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
            *(short *)(iVar12 + iVar20 + 0x34) = sVar14;
            uVar8 = 0xb;
            if (*(char *)(iVar22 + 0x42) == '\0') {
              uVar8 = 9;
            }
          }
          else {
            iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
            iVar12 = _r_plf_funcs_p;
            *(undefined2 *)(iVar13 + iVar20 + 0x1c) = 0;
            iVar12 = (**(code **)(iVar12 + 0xbc))(0x400,*(code **)(iVar12 + 0xbc));
            cVar1 = *(char *)(iVar22 + 0x42);
            *(undefined2 *)(iVar12 + iVar20 + 0x34) = 0;
            uVar8 = 10;
            if (cVar1 == '\0') {
              uVar8 = 8;
            }
          }
          iVar12 = _r_modules_funcs_p;
          *(undefined1 *)(iVar22 + 0x3a) = uVar8;
          (**(code **)(iVar12 + 0x1e0))(uVar23,&bStack_49,abStack_48,*(code **)(iVar12 + 0x1e0));
          iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(undefined2 *)(iVar20 + 0x18 + iVar12) = 0;
          (**(code **)(_r_ip_funcs_p + 0x434))
                    (uVar23,*(undefined1 *)(iVar22 + 0x3a),*(code **)(_r_ip_funcs_p + 0x434));
          bVar2 = *(byte *)(iVar22 + 0x3a);
          uVar24 = (uint)abStack_48[0];
          uVar17 = (uint)DAT_00015063;
          uVar18 = (uint)bStack_49;
          if ((uVar18 << 7 & 0xffffff7f) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x42,*(code **)(_r_plf_funcs_p + 8));
          }
          if ((uVar24 << 6 & 0xffffffbf) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x43,*(code **)(_r_plf_funcs_p + 8));
          }
          if ((bVar2 & 0xe0) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x45,*(code **)(_r_plf_funcs_p + 8));
          }
          iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar12 + iVar20) =
               (ushort)(uVar18 << 7) | (ushort)(uVar24 << 6) | (ushort)bVar2 |
               (ushort)((uVar17 & 1) << 10) | (ushort)((uVar17 & 2) << 8) |
               (ushort)((uVar17 & 4) << 6) | 0x20;
          bVar2 = *(byte *)(iVar22 + 0x3b);
          if (((uint)bVar2 << 2 & 0xfffffff3) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",399,*(code **)(_r_plf_funcs_p + 8));
          }
          if ((bVar2 & 0xfc) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",400,*(code **)(_r_plf_funcs_p + 8));
          }
          iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar20 + 4 + iVar12) = (ushort)((uint)bVar2 << 2) | (ushort)bVar2 | 0x1000;
          if (g_scan_forever == '\0') {
            uVar6 = *(undefined2 *)(iVar22 + 0x24);
            iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
            uVar17 = *(uint *)(iVar22 + 0x24);
            *(undefined2 *)(iVar12 + iVar20 + 0x20) = uVar6;
            if (0x3fff < uVar17) {
              uVar17 = 0x3fff;
            }
            iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
            uVar15 = (ushort)uVar17 | 0x8000;
          }
          else {
            iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
            iVar12 = _r_plf_funcs_p;
            *(undefined2 *)(iVar13 + iVar20 + 0x20) = 0;
            iVar12 = (**(code **)(iVar12 + 0xbc))(0x400,*(code **)(iVar12 + 0xbc));
            uVar15 = 0xbfff;
          }
          *(ushort *)(iVar12 + iVar20 + 0x1a) = uVar15;
          bVar2 = *(byte *)(iVar22 + 0x3a);
          if (bVar2 == 10) {
            uVar16 = 7;
            pcVar19 = *(code **)(_r_modules_funcs_p + 0x1a0);
_L918:
            unaff_s1 = (byte *)(*pcVar19)(uVar16,pcVar19);
          }
          else {
            if (bVar2 < 0xb) {
              if (bVar2 == 8) {
                uVar16 = 5;
                pcVar19 = *(code **)(_r_modules_funcs_p + 0x1a0);
              }
              else {
                if (bVar2 != 9) goto _L820;
                uVar16 = 6;
                pcVar19 = *(code **)(_r_modules_funcs_p + 0x1a0);
              }
              goto _L918;
            }
            if (bVar2 == 0xb) {
              uVar16 = 8;
              pcVar19 = *(code **)(_r_modules_funcs_p + 0x1a0);
              goto _L918;
            }
_L820:
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0xca2,*(code **)(_r_plf_funcs_p + 8));
          }
          if (unaff_s1 != (byte *)0x0) {
            bVar2 = unaff_s1[1];
            if (0xb < uVar23) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x299b,*(code **)(_r_plf_funcs_p + 8));
            }
            if (((uint)bVar2 << 8 & 0xf000) != 0) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x299d,*(code **)(_r_plf_funcs_p + 8));
            }
            puVar21 = (uint *)((uVar23 + 0x1800c4cb) * 4);
            *puVar21 = *puVar21 & 0xfffff0ff | (uint)bVar2 << 8;
            bVar2 = *unaff_s1;
            if (0xb < uVar23) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x294a,*(code **)(_r_plf_funcs_p + 8));
            }
            *puVar21 = (uint)bVar2 << 0x1e | *puVar21 & 0xbfffffff;
            bVar2 = unaff_s1[3];
            if (0xb < uVar23) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x29bb,*(code **)(_r_plf_funcs_p + 8));
            }
            if ((bVar2 & 0xf0) != 0) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x29bd,*(code **)(_r_plf_funcs_p + 8));
            }
            *puVar21 = *puVar21 & 0xfffffff0 | (uint)bVar2;
            bVar2 = unaff_s1[2];
            if (0xb < uVar23) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x295a,*(code **)(_r_plf_funcs_p + 8));
            }
            *puVar21 = (uint)bVar2 << 0x1d | *puVar21 & 0xdfffffff;
            bVar2 = unaff_s1[7];
            if (0xb < uVar23) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x298b,*(code **)(_r_plf_funcs_p + 8));
            }
            if (((uint)bVar2 << 0xc & 0xf0000) != 0) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x298d,*(code **)(_r_plf_funcs_p + 8));
            }
            *puVar21 = *puVar21 & 0xffff0fff | (uint)bVar2 << 0xc;
            bVar2 = unaff_s1[8];
            if (0xb < uVar23) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x29ab,*(code **)(_r_plf_funcs_p + 8));
            }
            if (((uint)bVar2 << 4 & 0xffffff0f) != 0) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x29ad,*(code **)(_r_plf_funcs_p + 8));
            }
            *puVar21 = *puVar21 & 0xffffff0f | (uint)bVar2 << 4;
            bVar2 = unaff_s1[9];
            if (0xb < uVar23) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x297b,*(code **)(_r_plf_funcs_p + 8));
            }
            if (((uint)bVar2 << 0x10 & 0xf00000) != 0) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x297d,*(code **)(_r_plf_funcs_p + 8));
            }
            *puVar21 = *puVar21 & 0xfff0ffff | (uint)bVar2 << 0x10;
            uVar15 = *(ushort *)(unaff_s1 + 10);
            if (0xb < uVar23) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x296a,*(code **)(_r_plf_funcs_p + 8));
            }
            if (((uint)uVar15 << 0x14 & 0xe0000000) != 0) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x296c,*(code **)(_r_plf_funcs_p + 8));
            }
            *puVar21 = *puVar21 & 0xe00fffff | (uint)uVar15 << 0x14;
            bVar2 = unaff_s1[6];
            if (0xb < uVar23) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x293a,*(code **)(_r_plf_funcs_p + 8));
            }
            *puVar21 = *puVar21 & 0x7fffffff | (uint)bVar2 << 0x1f;
            if (2 < _g_bt_plf_log_level) {
              ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[SCAN[%d]] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                         ,uVar23,puVar21,*(undefined1 *)(iVar22 + 0x3a),unaff_s1[2],unaff_s1[3],
                         *unaff_s1,unaff_s1[1]);
            }
          }
        }
        piStack_7c = piStack_7c + 1;
        if (piVar9 + 2 == piStack_7c) {
          if (bVar7) {
            iVar22 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
            iVar12 = (uint)(byte)(param_1 * '\t') * 0xe;
            iVar20 = iVar12 + 2;
            uVar15 = *(ushort *)(iVar22 + iVar20);
            iVar22 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
            pcVar19 = *(code **)(_r_plf_funcs_p + 0xbc);
            *(ushort *)(iVar22 + iVar20) = uVar15 & 0xfff0 | 3;
            iVar22 = (*pcVar19)(0x1400,pcVar19);
            *(undefined2 *)(iVar12 + 4 + iVar22) = 0;
            iVar22 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
            uVar15 = *(ushort *)(iVar22 + iVar20);
            iVar22 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
            pcVar19 = *(code **)(_r_plf_funcs_p + 0xbc);
            *(ushort *)(iVar22 + iVar20) = uVar15 & 0xff | 0xc00;
            iVar22 = (*pcVar19)(0x1400,pcVar19);
            uVar15 = *(ushort *)(iVar22 + iVar12);
            iVar20 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
            iVar22 = _r_plf_funcs_p;
            *(ushort *)(iVar20 + iVar12) = uVar15 & 0x8000;
            iVar22 = (**(code **)(iVar22 + 0xbc))(0x1400,*(code **)(iVar22 + 0xbc));
            uVar15 = *(ushort *)(iVar22 + iVar12);
            iVar22 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
            pcVar19 = *(code **)(_r_modules_funcs_p + 0x1a0);
            *(ushort *)(iVar22 + iVar12) = (ushort)(((uint)uVar15 << 0x11) >> 0x11);
            iVar22 = (*pcVar19)(6,pcVar19);
            if (iVar22 != 0) {
              if (2 < _g_bt_plf_log_level) {
                ets_printf("TX PTI [ACT_SCAN] [EN%d] [%d] \n",*(undefined1 *)(iVar22 + 4),
                           *(undefined1 *)(iVar22 + 5));
              }
              uVar17 = (uint)*(byte *)(iVar22 + 5) << 8;
              if ((uVar17 & 0xf000) != 0) {
                (**(code **)(_r_plf_funcs_p + 8))
                          (0,"lld_scan.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
              }
              iVar12 = iVar12 + 10;
              iVar20 = (**(code **)(_r_plf_funcs_p + 0xbc))
                                 (0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
              uVar15 = *(ushort *)(iVar20 + iVar12);
              iVar20 = (**(code **)(_r_plf_funcs_p + 0xbc))
                                 (0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
              pcVar19 = *(code **)(_r_plf_funcs_p + 0xbc);
              *(ushort *)(iVar20 + iVar12) = uVar15 & 0xf0ff | (ushort)uVar17;
              bVar2 = *(byte *)(iVar22 + 4);
              iVar22 = (*pcVar19)(0x1400,pcVar19);
              uVar15 = *(ushort *)(iVar22 + iVar12);
              iVar22 = (**(code **)(_r_plf_funcs_p + 0xbc))
                                 (0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
              *(ushort *)(iVar22 + iVar12) = uVar15 & 0xefff | (ushort)bVar2 << 0xc;
            }
          }
          _DAT_60031124 = 0x10001;
          uVar17 = (uint)_sdk_cfg_priv_opts;
          if ((_sdk_cfg_priv_opts & 0xfe00) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x29ed,*(code **)(_r_plf_funcs_p + 8));
          }
          _DAT_60031364 = _DAT_60031364 & 0xfffffe00 | uVar17;
          piStack_78 = piVar9;
          do {
            iVar22 = _r_ip_funcs_p;
            iVar12 = *piStack_78;
            if (iVar12 != 0) {
              *(uint *)(iVar12 + 4) = uVar10;
              *(uint *)(iVar12 + 0x28) = uVar10;
              iVar22 = (**(code **)(iVar22 + 0x6b0))(iVar12,*(code **)(iVar22 + 0x6b0));
              if (iVar22 == 0) {
                *(undefined1 *)(iVar12 + 0x43) = 0;
                *(undefined2 *)(iVar12 + 0x36) = 0;
                uVar10 = (uint)*(ushort *)(iVar12 + 0x32) * 2 + uVar10 & 0xfffffff;
              }
              else {
                (**(code **)(_r_plf_funcs_p + 8))
                          (0,"lld_scan.c",0xcf4,*(code **)(_r_plf_funcs_p + 8));
              }
            }
            iVar22 = _r_modules_funcs_p;
            piStack_78 = piStack_78 + 1;
          } while (piVar9 + 2 != piStack_78);
          *(undefined1 *)((int)piVar9 + 0x17) = 0;
          iVar22 = (**(code **)(iVar22 + 0x2c4))(*(code **)(iVar22 + 0x2c4));
          piVar9[6] = iVar22;
          piVar9[7] = iVar22;
          return 0;
        }
      } while( true );
    }
    (**(code **)(_r_plf_funcs_p + 8))("lld_scan.c",0xd00,*(code **)(_r_plf_funcs_p + 8));
  }
  return 0xc;
}

