/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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
  int iVar8;
  uint *puVar9;
  int *piVar10;
  uint uVar11;
  void *pvVar12;
  int iVar13;
  int iVar14;
  ushort uVar15;
  undefined4 uVar16;
  uint uVar17;
  undefined1 uVar18;
  short sVar19;
  undefined4 uVar20;
  code *pcVar21;
  byte *unaff_s4;
  int iVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  int *piStack_7c;
  int *piStack_78;
  byte bStack_49;
  byte abStack_48 [20];
  
  if (_lld_scan_env == (int *)0x0) {
    piVar10 = (int *)(**(code **)(_r_modules_funcs_p + 0x120))
                               (0x20,0,*(code **)(_r_modules_funcs_p + 0x120));
    _lld_scan_env = piVar10;
    if (piVar10 != (int *)0x0) {
      uVar11 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
      memset(_lld_scan_env,0,0x20);
      bVar7 = false;
      if ((*(byte *)((int)param_2 + 7) & 1) != 0) {
        pvVar12 = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                                    (0x84,0,*(code **)(_r_modules_funcs_p + 0x120));
        *piVar10 = (int)pvVar12;
        if (pvVar12 == (void *)0x0) {
          (**(code **)(_r_plf_funcs_p + 8))("lld_scan.c",0xb5b,*(code **)(_r_plf_funcs_p + 8));
        }
        else {
          memset(pvVar12,0,0x84);
          uVar16 = *(undefined4 *)(_r_ip_funcs_p + 1000);
          uVar20 = *(undefined4 *)(_r_ip_funcs_p + 0x3ec);
          *(undefined4 *)((int)pvVar12 + 0x1c) = 0;
          *(undefined4 *)((int)pvVar12 + 0x20) = uVar16;
          *(undefined4 *)((int)pvVar12 + 0x18) = uVar20;
          *(undefined1 *)((int)pvVar12 + 0x16) = rwip_priority;
          bVar2 = DAT_00015031;
          uVar15 = param_2[6];
          uVar17 = (uint)uVar15 * 0x4e2;
          if (_sch_slice_params < uVar17) {
            uVar17 = (uint)_sch_slice_params;
          }
          *(uint *)((int)pvVar12 + 0x10) = uVar17;
          *(ushort *)((int)pvVar12 + 0x14) = bVar2 & 0xf | 0x6000;
          uVar6 = param_2[4];
          *(ushort *)((int)pvVar12 + 0x32) = uVar15;
          *(undefined2 *)((int)pvVar12 + 0x30) = uVar6;
          cVar1 = *(char *)(param_2 + 8);
          *(undefined1 *)((int)pvVar12 + 0x3b) = 0;
          *(uint *)((int)pvVar12 + 0x24) = (uint)uVar15;
          *(char *)((int)pvVar12 + 0x39) = cVar1;
          *(undefined1 *)((int)pvVar12 + 0x40) = 0;
          *(char *)((int)pvVar12 + 0x38) = param_1;
          bVar7 = cVar1 == '\x01';
          *(byte *)(piVar10 + 3) = *(byte *)(piVar10 + 3) | 1;
        }
      }
      if ((*(byte *)((int)param_2 + 7) & 4) != 0) {
        pvVar12 = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                                    (0x84,0,*(code **)(_r_modules_funcs_p + 0x120));
        piVar10[1] = (int)pvVar12;
        if (pvVar12 == (void *)0x0) {
          (**(code **)(_r_plf_funcs_p + 8))("lld_scan.c",0xb87,*(code **)(_r_plf_funcs_p + 8));
        }
        else {
          memset(pvVar12,0,0x84);
          uVar16 = *(undefined4 *)(_r_ip_funcs_p + 1000);
          uVar20 = *(undefined4 *)(_r_ip_funcs_p + 0x3ec);
          *(undefined4 *)((int)pvVar12 + 0x1c) = 0;
          *(undefined4 *)((int)pvVar12 + 0x20) = uVar16;
          *(undefined4 *)((int)pvVar12 + 0x18) = uVar20;
          *(undefined1 *)((int)pvVar12 + 0x16) = rwip_priority;
          bVar2 = DAT_00015031;
          uVar15 = param_2[7];
          uVar17 = (uint)uVar15 * 0x4e2;
          if (_sch_slice_params < uVar17) {
            uVar17 = (uint)_sch_slice_params;
          }
          *(uint *)((int)pvVar12 + 0x10) = uVar17;
          *(ushort *)((int)pvVar12 + 0x14) = bVar2 & 0xf | 0x6000;
          uVar6 = param_2[5];
          *(ushort *)((int)pvVar12 + 0x32) = uVar15;
          *(undefined2 *)((int)pvVar12 + 0x30) = uVar6;
          cVar1 = *(char *)((int)param_2 + 0x11);
          *(undefined1 *)((int)pvVar12 + 0x3b) = 3;
          *(undefined1 *)((int)pvVar12 + 0x40) = 1;
          *(undefined1 *)((int)pvVar12 + 0x38) = 0xb;
          *(char *)((int)pvVar12 + 0x39) = cVar1;
          *(uint *)((int)pvVar12 + 0x24) = (uint)uVar15;
          *(undefined1 *)((int)pvVar12 + 0x3c) = 0;
          bVar7 = (bool)(cVar1 == '\x01' | bVar7);
          *(byte *)(piVar10 + 3) = *(byte *)(piVar10 + 3) | 2;
        }
      }
      memcpy((void *)((int)piVar10 + 0xe),param_2,6);
      *(undefined1 *)(piVar10 + 5) = *(undefined1 *)(param_2 + 9);
      uVar18 = *(undefined1 *)((int)param_2 + 0x13);
      *(char *)((int)piVar10 + 0xd) = param_1;
      *(undefined1 *)((int)piVar10 + 0x15) = uVar18;
      *(undefined1 *)((int)piVar10 + 0x16) = *(undefined1 *)(param_2 + 10);
      if ((ushort)param_2[0xb] == 0) {
        uVar17 = 0xffffffff;
      }
      else {
        uVar17 = (uint)(ushort)param_2[0xb] * 0x20 + uVar11 & 0xfffffff;
      }
      piVar10[2] = uVar17;
      sVar19 = (ushort)(byte)(param_1 * '\t') * 0xe + 0x1400;
      piStack_7c = piVar10;
      do {
        bStack_49 = 0;
        abStack_48[0] = 0;
        iVar22 = *piStack_7c;
        if (iVar22 != 0) {
          bVar2 = *(byte *)(iVar22 + 0x38);
          uVar23 = (uint)bVar2;
          iVar8 = uVar23 * 0x5a;
          *(undefined1 *)(iVar22 + 0x42) = *(undefined1 *)(param_2 + 3);
          *(undefined1 *)(iVar22 + 0x3f) = 9;
          iVar13 = _r_plf_funcs_p;
          *(undefined1 *)(iVar22 + 0x3d) = 0;
          iVar13 = (**(code **)(iVar13 + 0xbc))(0x400,*(code **)(iVar13 + 0xbc));
          *(undefined2 *)(iVar13 + iVar8 + 0xc) = 0xbed6;
          iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(undefined2 *)(iVar13 + iVar8 + 0xe) = 0x8e89;
          iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(undefined2 *)(iVar13 + iVar8 + 0x10) = 0x5555;
          iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(undefined2 *)(iVar13 + iVar8 + 0x12) = 0x55;
          iVar14 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          iVar13 = _lld_scan_sync_env;
          *(undefined2 *)(iVar14 + iVar8 + 0x46) = 0;
          uVar17 = 0;
          if (iVar13 != 0) {
            uVar17 = (uint)(*(char *)(iVar13 + 1) != '\0');
          }
          *(char *)(iVar22 + 0x44) = (char)uVar17;
          bVar3 = *(byte *)(param_2 + 9);
          bVar4 = *(byte *)((int)piVar10 + 0x15);
          bVar5 = *(byte *)(param_2 + 10);
          uVar15 = 1;
          if (*(char *)((int)piVar10 + 0x16) == '\0') {
            uVar15 = *(byte *)(piVar10 + 5) >> 1 & 1;
          }
          iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          pcVar21 = *(code **)(_r_plf_funcs_p + 0xbc);
          *(ushort *)(iVar13 + iVar8 + 0x14) =
               (ushort)bVar5 << 6 | (ushort)((bVar3 >> 1 & 1) << 2) | (ushort)bVar4 << 8 |
               (ushort)(uVar17 << 3) | uVar15;
          iVar13 = (*pcVar21)(0x400,pcVar21);
          *(undefined2 *)(iVar13 + iVar8 + 0x16) = 0x8027;
          iVar14 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          iVar13 = _r_plf_funcs_p;
          *(undefined2 *)(iVar14 + iVar8 + 0x28) = 0;
          iVar13 = (**(code **)(iVar13 + 0xbc))(0x400,*(code **)(iVar13 + 0xbc));
          *(undefined2 *)(iVar13 + iVar8 + 0x2a) = 0;
          bVar3 = *(byte *)(param_2 + 9);
          uVar15 = (ushort)DAT_0001505a;
          if ((bVar2 & 0xe0) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0xe6,*(code **)(_r_plf_funcs_p + 8));
          }
          iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar13 + iVar8 + 2) =
               uVar15 << 5 | (ushort)bVar2 | (ushort)((bVar3 & 1) << 7) | 0x800;
          uVar6 = *param_2;
          iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(undefined2 *)(iVar13 + iVar8 + 6) = uVar6;
          uVar6 = param_2[1];
          iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(undefined2 *)(iVar13 + iVar8 + 8) = uVar6;
          uVar6 = param_2[2];
          iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(undefined2 *)(iVar13 + iVar8 + 10) = uVar6;
          if (*(char *)(iVar22 + 0x39) == '\x01') {
            iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
            *(short *)(iVar13 + iVar8 + 0x1c) = sVar19;
            iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
            cVar1 = *(char *)(iVar22 + 0x42);
            *(short *)(iVar13 + iVar8 + 0x34) = sVar19;
            uVar18 = 0xb;
            if (cVar1 == '\0') {
              uVar18 = 9;
            }
          }
          else {
            iVar14 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
            iVar13 = _r_plf_funcs_p;
            *(undefined2 *)(iVar14 + iVar8 + 0x1c) = 0;
            iVar13 = (**(code **)(iVar13 + 0xbc))(0x400,*(code **)(iVar13 + 0xbc));
            cVar1 = *(char *)(iVar22 + 0x42);
            *(undefined2 *)(iVar13 + iVar8 + 0x34) = 0;
            uVar18 = 10;
            if (cVar1 == '\0') {
              uVar18 = 8;
            }
          }
          *(undefined1 *)(iVar22 + 0x3a) = uVar18;
          (**(code **)(_r_modules_funcs_p + 0x1e0))
                    (*(undefined1 *)(iVar22 + 0x3a),uVar23,&bStack_49,abStack_48,
                     *(code **)(_r_modules_funcs_p + 0x1e0));
          iVar14 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          iVar13 = _r_ip_funcs_p;
          *(undefined2 *)(iVar14 + iVar8 + 0x18) = 0;
          (**(code **)(iVar13 + 0x434))
                    (uVar23,*(undefined1 *)(iVar22 + 0x3a),*(code **)(iVar13 + 0x434));
          bVar2 = *(byte *)(iVar22 + 0x3a);
          uVar24 = (uint)abStack_48[0];
          uVar17 = (uint)DAT_00015063;
          uVar25 = (uint)bStack_49;
          if ((uVar25 << 7 & 0xffffff7f) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x42,*(code **)(_r_plf_funcs_p + 8));
          }
          if ((uVar24 << 6 & 0xffffffbf) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x43,*(code **)(_r_plf_funcs_p + 8));
          }
          if ((bVar2 & 0xe0) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x45,*(code **)(_r_plf_funcs_p + 8));
          }
          iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar13 + iVar8) =
               (ushort)(uVar25 << 7) | (ushort)(uVar24 << 6) | (ushort)bVar2 |
               (ushort)((uVar17 & 1) << 10) | (ushort)((uVar17 & 2) << 8) |
               (ushort)((uVar17 & 4) << 6) | 0x20;
          bVar2 = *(byte *)(iVar22 + 0x3b);
          if (((uint)bVar2 << 2 & 0xfffffff3) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",399,*(code **)(_r_plf_funcs_p + 8));
          }
          if ((bVar2 & 0xfc) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",400,*(code **)(_r_plf_funcs_p + 8));
          }
          iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          cVar1 = g_scan_forever;
          *(ushort *)(iVar13 + iVar8 + 4) = (ushort)((uint)bVar2 << 2) | (ushort)bVar2 | 0x1000;
          if (cVar1 == '\0') {
            uVar6 = *(undefined2 *)(iVar22 + 0x24);
            iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
            uVar17 = *(uint *)(iVar22 + 0x24);
            *(undefined2 *)(iVar13 + iVar8 + 0x20) = uVar6;
            if (0x3fff < uVar17) {
              uVar17 = 0x3fff;
            }
            iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
            *(ushort *)(iVar8 + 0x1a + iVar13) = (ushort)uVar17 | 0x8000;
          }
          else {
            iVar14 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
            iVar13 = _r_plf_funcs_p;
            *(undefined2 *)(iVar14 + iVar8 + 0x20) = 0;
            iVar13 = (**(code **)(iVar13 + 0xbc))(0x400,*(code **)(iVar13 + 0xbc));
            *(undefined2 *)(iVar8 + 0x1a + iVar13) = 0xbfff;
          }
          bVar2 = *(byte *)(iVar22 + 0x3a);
          if (bVar2 == 9) {
            uVar16 = 6;
            pcVar21 = *(code **)(_r_modules_funcs_p + 0x1a0);
_L912:
            unaff_s4 = (byte *)(*pcVar21)(uVar16,pcVar21);
          }
          else {
            if (9 < bVar2) {
              if (bVar2 == 10) {
                uVar16 = 7;
                pcVar21 = *(code **)(_r_modules_funcs_p + 0x1a0);
              }
              else {
                if (bVar2 != 0xb) goto _L818;
                uVar16 = 8;
                pcVar21 = *(code **)(_r_modules_funcs_p + 0x1a0);
              }
              goto _L912;
            }
            if (bVar2 == 8) {
              uVar16 = 5;
              pcVar21 = *(code **)(_r_modules_funcs_p + 0x1a0);
              goto _L912;
            }
_L818:
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0xc35,*(code **)(_r_plf_funcs_p + 8));
          }
          if (unaff_s4 != (byte *)0x0) {
            bVar2 = unaff_s4[1];
            if (0xb < uVar23) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x299b,*(code **)(_r_plf_funcs_p + 8));
            }
            if (((uint)bVar2 << 8 & 0xf000) != 0) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x299d,*(code **)(_r_plf_funcs_p + 8));
            }
            puVar9 = (uint *)((uVar23 + 0x1800c4cb) * 4);
            *puVar9 = *puVar9 & 0xfffff0ff | (uint)bVar2 << 8;
            bVar2 = *unaff_s4;
            if (0xb < uVar23) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x294a,*(code **)(_r_plf_funcs_p + 8));
            }
            *puVar9 = (uint)bVar2 << 0x1e | *puVar9 & 0xbfffffff;
            bVar2 = unaff_s4[3];
            if (0xb < uVar23) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x29bb,*(code **)(_r_plf_funcs_p + 8));
            }
            if ((bVar2 & 0xf0) != 0) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x29bd,*(code **)(_r_plf_funcs_p + 8));
            }
            *puVar9 = *puVar9 & 0xfffffff0 | (uint)bVar2;
            bVar2 = unaff_s4[2];
            if (0xb < uVar23) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x295a,*(code **)(_r_plf_funcs_p + 8));
            }
            *puVar9 = (uint)bVar2 << 0x1d | *puVar9 & 0xdfffffff;
            bVar2 = unaff_s4[7];
            if (0xb < uVar23) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x298b,*(code **)(_r_plf_funcs_p + 8));
            }
            if (((uint)bVar2 << 0xc & 0xf0000) != 0) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x298d,*(code **)(_r_plf_funcs_p + 8));
            }
            *puVar9 = *puVar9 & 0xffff0fff | (uint)bVar2 << 0xc;
            bVar2 = unaff_s4[8];
            if (0xb < uVar23) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x29ab,*(code **)(_r_plf_funcs_p + 8));
            }
            if (((uint)bVar2 << 4 & 0xffffff0f) != 0) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x29ad,*(code **)(_r_plf_funcs_p + 8));
            }
            *puVar9 = *puVar9 & 0xffffff0f | (uint)bVar2 << 4;
            bVar2 = unaff_s4[9];
            if (0xb < uVar23) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x297b,*(code **)(_r_plf_funcs_p + 8));
            }
            if (((uint)bVar2 << 0x10 & 0xf00000) != 0) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x297d,*(code **)(_r_plf_funcs_p + 8));
            }
            *puVar9 = *puVar9 & 0xfff0ffff | (uint)bVar2 << 0x10;
            uVar15 = *(ushort *)(unaff_s4 + 10);
            if (0xb < uVar23) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x296a,*(code **)(_r_plf_funcs_p + 8));
            }
            if (((uint)uVar15 << 0x14 & 0xe0000000) != 0) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x296c,*(code **)(_r_plf_funcs_p + 8));
            }
            *puVar9 = *puVar9 & 0xe00fffff | (uint)uVar15 << 0x14;
            bVar2 = unaff_s4[6];
            if (0xb < uVar23) {
              (**(code **)(_r_plf_funcs_p + 8))
                        (0,"lld_scan.c",0x293a,*(code **)(_r_plf_funcs_p + 8));
            }
            *puVar9 = *puVar9 & 0x7fffffff | (uint)bVar2 << 0x1f;
            if (2 < _g_bt_plf_log_level) {
              ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[SCAN[%d]] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                         ,uVar23,puVar9,*(undefined1 *)(iVar22 + 0x3a),unaff_s4[2],unaff_s4[3],
                         *unaff_s4,unaff_s4[1]);
            }
          }
        }
        piStack_7c = piStack_7c + 1;
        if (piVar10 + 2 == piStack_7c) {
          if (bVar7) {
            iVar22 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
            iVar13 = (uint)(byte)(param_1 * '\t') * 0xe;
            iVar14 = iVar13 + 2;
            uVar15 = *(ushort *)(iVar22 + iVar14);
            iVar22 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
            pcVar21 = *(code **)(_r_plf_funcs_p + 0xbc);
            *(ushort *)(iVar22 + iVar14) = uVar15 & 0xfff0 | 3;
            iVar8 = (*pcVar21)(0x1400,pcVar21);
            iVar22 = _r_plf_funcs_p;
            *(undefined2 *)(iVar8 + iVar13 + 4) = 0;
            iVar22 = (**(code **)(iVar22 + 0xbc))(0x1400,*(code **)(iVar22 + 0xbc));
            uVar15 = *(ushort *)(iVar22 + iVar14);
            iVar22 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
            pcVar21 = *(code **)(_r_plf_funcs_p + 0xbc);
            *(ushort *)(iVar22 + iVar14) = uVar15 & 0xff | 0xc00;
            iVar22 = (*pcVar21)(0x1400,pcVar21);
            uVar15 = *(ushort *)(iVar22 + iVar13);
            iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
            iVar22 = _r_plf_funcs_p;
            *(ushort *)(iVar8 + iVar13) = uVar15 & 0x8000;
            iVar22 = (**(code **)(iVar22 + 0xbc))(0x1400,*(code **)(iVar22 + 0xbc));
            uVar15 = *(ushort *)(iVar22 + iVar13);
            iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
            iVar22 = _r_modules_funcs_p;
            *(ushort *)(iVar8 + iVar13) = uVar15 & 0x7fff;
            iVar22 = (**(code **)(iVar22 + 0x1a0))(6,*(code **)(iVar22 + 0x1a0));
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
              iVar13 = iVar13 + 10;
              iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc))
              ;
              uVar15 = *(ushort *)(iVar8 + iVar13);
              iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc))
              ;
              pcVar21 = *(code **)(_r_plf_funcs_p + 0xbc);
              *(ushort *)(iVar8 + iVar13) = uVar15 & 0xf0ff | (ushort)uVar17;
              bVar2 = *(byte *)(iVar22 + 4);
              iVar22 = (*pcVar21)(0x1400,pcVar21);
              uVar15 = *(ushort *)(iVar22 + iVar13);
              iVar22 = (**(code **)(_r_plf_funcs_p + 0xbc))
                                 (0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
              *(ushort *)(iVar22 + iVar13) = uVar15 & 0xefff | (ushort)bVar2 << 0xc;
            }
          }
          _DAT_60031124 = 0x10001;
          uVar17 = (uint)_sdk_cfg_priv_opts;
          if ((_sdk_cfg_priv_opts & 0xfe00) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x29ed,*(code **)(_r_plf_funcs_p + 8));
          }
          _DAT_60031364 = _DAT_60031364 & 0xfffffe00 | uVar17;
          piStack_78 = piVar10;
          do {
            iVar22 = _r_ip_funcs_p;
            iVar13 = *piStack_78;
            if (iVar13 != 0) {
              *(uint *)(iVar13 + 4) = uVar11;
              *(uint *)(iVar13 + 0x28) = uVar11;
              iVar22 = (**(code **)(iVar22 + 0x6b0))(iVar13,*(code **)(iVar22 + 0x6b0));
              if (iVar22 == 0) {
                *(undefined1 *)(iVar13 + 0x43) = 0;
                *(undefined2 *)(iVar13 + 0x36) = 0;
                uVar11 = uVar11 + (uint)*(ushort *)(iVar13 + 0x32) * 2 & 0xfffffff;
              }
              else {
                (**(code **)(_r_plf_funcs_p + 8))
                          (0,"lld_scan.c",0xc87,*(code **)(_r_plf_funcs_p + 8));
              }
            }
            iVar22 = _r_modules_funcs_p;
            piStack_78 = piStack_78 + 1;
          } while (piVar10 + 2 != piStack_78);
          *(undefined1 *)((int)piVar10 + 0x17) = 0;
          iVar22 = (**(code **)(iVar22 + 0x2c4))(*(code **)(iVar22 + 0x2c4));
          piVar10[6] = iVar22;
          piVar10[7] = iVar22;
          return 0;
        }
      } while( true );
    }
    (**(code **)(_r_plf_funcs_p + 8))("lld_scan.c",0xc93,*(code **)(_r_plf_funcs_p + 8));
  }
  return 0xc;
}

