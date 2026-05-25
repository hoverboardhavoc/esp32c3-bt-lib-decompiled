/*
 * Last changed at upstream commit 0a08c4b32f3666003080b662a1a61794da24ff0f
 * https://github.com/espressif/esp32c3-bt-lib/commit/0a08c4b32f3666003080b662a1a61794da24ff0f
 * Upstream date: 2026-05-25 14:11:16 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(51d9dfde)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_con_start(uint param_1,undefined2 *param_2)

{
  byte bVar1;
  void *__s;
  undefined4 uVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  undefined4 uVar8;
  byte bVar9;
  ushort uVar10;
  undefined4 uVar11;
  code *pcVar12;
  uint uVar13;
  int iVar14;
  char cVar15;
  uint *puVar16;
  int iVar17;
  ushort uVar18;
  char cVar19;
  uint uVar20;
  uint uVar21;
  byte bStack_42;
  byte abStack_41 [13];
  
  if (*(int *)(&lld_con_env + param_1 * 4) == 0) {
    __s = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                            (0x9c,0,*(code **)(_r_modules_funcs_p + 0x120));
    *(void **)(&lld_con_env + param_1 * 4) = __s;
    if (__s != (void *)0x0) {
      uVar2 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
      bStack_42 = 0;
      abStack_41[0] = 0;
      memset(__s,0,0x9c);
      uVar8 = *(undefined4 *)(_r_ip_funcs_p + 0x33c);
      uVar11 = *(undefined4 *)(_r_ip_funcs_p + 0x348);
      *(char *)((int)__s + 0x8e) = (char)param_1;
      *(undefined4 *)((int)__s + 0x20) = uVar8;
      *(undefined4 *)((int)__s + 0x18) = uVar11;
      *(undefined1 *)((int)__s + 0x16) = rwip_priority;
      *(undefined2 *)((int)__s + 0x14) = 0x2000;
      if ((*(byte *)(param_2 + 0x12) & 0xfe) != 0) {
        (**(code **)(_r_plf_funcs_p + 0xc))(1,"lld_con.c",0xec0,*(code **)(_r_plf_funcs_p + 0xc));
      }
      bVar9 = *(byte *)(param_2 + 0x12);
      *(ushort *)((int)__s + 0x70) = (ushort)*(byte *)((int)param_2 + 7) << 2;
      *(uint *)((int)__s + 0x60) = (uint)(ushort)param_2[4] << 2;
      *(uint *)((int)__s + 100) = (uint)(ushort)param_2[5] << 2;
      *(undefined2 *)((int)__s + 0x72) = param_2[6];
      *(uint *)((int)__s + 0x68) = (uint)(ushort)param_2[7] << 5;
      *(undefined1 *)((int)__s + 0x8d) = *(undefined1 *)((int)param_2 + 0x15);
      uVar7 = *(undefined2 *)(&co_sca2ppm + (uint)*(byte *)(param_2 + 0xb) * 2);
      *(undefined2 *)((int)__s + 0x90) = 0;
      *(undefined1 *)((int)__s + 0x92) = 0;
      *(undefined2 *)((int)__s + 0x7a) = uVar7;
      *(ushort *)((int)__s + 0x84) = *(ushort *)((int)__s + 0x84) & 0xfbfe | (ushort)bVar9 | 0x10;
      *(undefined2 *)((int)__s + 0x86) = 0x1b;
      *(undefined4 *)((int)__s + 0x24) = 0;
      *(undefined4 *)((int)__s + 0x30) = 0;
      *(undefined4 *)((int)__s + 0x7c) = 0;
      *(undefined4 *)((int)__s + 0x80) = 0;
      cVar15 = *(char *)((int)param_2 + 0x25);
      if ((byte)(cVar15 - 2U) < 2) {
        uVar7 = 0xa90;
      }
      else {
        uVar7 = 0x148;
      }
      *(undefined2 *)((int)__s + 0x88) = uVar7;
      *(undefined2 *)((int)__s + 0x8a) = uVar7;
      *(undefined1 *)((int)__s + 0x8c) = 0x1b;
      *(char *)((int)__s + 0x93) = cVar15;
      *(char *)((int)__s + 0x94) = cVar15;
      *(undefined1 *)((int)__s + 0x95) = 0;
      if ((bVar9 & 1) != 0) {
        (**(code **)(_r_ip_funcs_p + 0x36c))
                  (*(undefined1 *)((int)__s + 0x8e),*(code **)(_r_ip_funcs_p + 0x36c));
      }
      uVar18 = (*(char *)(param_2 + 0x12) != '\0') + 2;
      (**(code **)(_r_modules_funcs_p + 0x1e0))
                (uVar18,param_1,&bStack_42,abStack_41,*(code **)(_r_modules_funcs_p + 0x1e0));
      uVar13 = (uint)bStack_42;
      uVar20 = (uint)rwip_coex_cfg;
      uVar21 = (uint)abStack_41[0];
      if ((uVar13 << 7 & 0xffffff7f) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x42,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((uVar21 << 6 & 0xffffffbf) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x43,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar14 = param_1 * 0x5a;
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar3 + iVar14) =
           (ushort)(uVar13 << 7) | (ushort)(uVar21 << 6) | (ushort)((uVar20 & 1) << 10) |
           (ushort)((uVar20 & 2) << 8) | (ushort)((uVar20 & 4) << 6) | uVar18;
      uVar20 = (uint)*(byte *)((int)param_2 + 0x25);
      uVar13 = uVar20;
      if ((DAT_0001604f != '\0') && ((uVar20 - 2 & 0xff) < 2)) {
        uVar13 = *(byte *)(_p_lld_env + 0xda) + 2 & 0xff;
      }
      if ((uVar20 << 2 & 0xfffffff3) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",399,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((uVar13 & 0xfffffffc) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",400,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar14 + 4 + iVar3) = (ushort)(uVar20 << 2) | (ushort)uVar13 | 0x1100;
      if ((param_1 & 0xffffffe0) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0xe6,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar3 + iVar14 + 2) = (ushort)param_1 | 0x800;
      uVar7 = *param_2;
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar14 + 0xc + iVar3) = uVar7;
      uVar7 = param_2[1];
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar14 + 0xe + iVar3) = uVar7;
      uVar7 = param_2[2];
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar14 + 0x10 + iVar3) = uVar7;
      bVar9 = *(byte *)(param_2 + 3);
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar14 + 0x12 + iVar3) = (ushort)bVar9;
      bVar9 = *(byte *)((int)__s + 0x8d);
      bVar1 = *(byte *)(param_2 + 0x13);
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar14 + 0x16 + iVar3) =
           (ushort)((bVar9 & 0x1f) << 8) | (ushort)bVar1 << 0xe | 0x8000;
      *(ushort *)((int)__s + 0x84) =
           (ushort)((*(byte *)(param_2 + 0x13) ^ 1) << 9) | *(ushort *)((int)__s + 0x84) & 0xfdff;
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar14 + 0x18 + iVar3) = 0;
      (**(code **)(_r_ip_funcs_p + 0x3ac))(param_1,uVar18,*(code **)(_r_ip_funcs_p + 0x3ac));
      (**(code **)(_r_ip_funcs_p + 0x34c))(param_1,*(code **)(_r_ip_funcs_p + 0x34c));
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar14 + 0x28 + iVar3) = 0xfb;
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar14 + 0x2a + iVar3) = 0;
      bVar9 = DAT_00016026;
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar14 + 0x1a + iVar3) = (ushort)bVar9;
      uVar7 = param_2[8];
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar14 + 0x22 + iVar3) = uVar7;
      uVar7 = param_2[9];
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar14 + 0x24 + iVar3) = uVar7;
      uVar7 = param_2[10];
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar14 + 0x26 + iVar3) = uVar7;
      pbVar4 = (byte *)(**(code **)(_r_modules_funcs_p + 0x1a0))
                                 (*(char *)(param_2 + 0x12) != '\0',
                                  *(code **)(_r_modules_funcs_p + 0x1a0));
      if (pbVar4 != (byte *)0x0) {
        bVar9 = pbVar4[1];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x299b,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar9 << 8 & 0xf000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x299d,*(code **)(_r_plf_funcs_p + 8));
        }
        puVar16 = (uint *)((param_1 + 0x1800c4cb) * 4);
        *puVar16 = *puVar16 & 0xfffff0ff | (uint)bVar9 << 8;
        bVar9 = *pbVar4;
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x294a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar16 = (uint)bVar9 << 0x1e | *puVar16 & 0xbfffffff;
        bVar9 = pbVar4[3];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x29bb,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((bVar9 & 0xf0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x29bd,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar16 = *puVar16 & 0xfffffff0 | (uint)bVar9;
        bVar9 = pbVar4[2];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x295a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar16 = (uint)bVar9 << 0x1d | *puVar16 & 0xdfffffff;
        bVar9 = pbVar4[7];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x298b,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar9 << 0xc & 0xf0000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x298d,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar16 = *puVar16 & 0xffff0fff | (uint)bVar9 << 0xc;
        bVar9 = pbVar4[8];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x29ab,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar9 << 4 & 0xffffff0f) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x29ad,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar16 = *puVar16 & 0xffffff0f | (uint)bVar9 << 4;
        bVar9 = pbVar4[9];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x297b,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar9 << 0x10 & 0xf00000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x297d,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar16 = *puVar16 & 0xfff0ffff | (uint)bVar9 << 0x10;
        uVar18 = *(ushort *)(pbVar4 + 10);
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x296a,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)uVar18 << 0x14 & 0xe0000000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x296c,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar16 = *puVar16 & 0xe00fffff | (uint)uVar18 << 0x14;
        bVar9 = pbVar4[6];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x293a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar16 = *puVar16 & 0x7fffffff | (uint)bVar9 << 0x1f;
        if (2 < _g_bt_plf_log_level) {
          ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[CON[%d]] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                     ,param_1,puVar16,*(undefined1 *)(param_2 + 0x12),pbVar4[2],pbVar4[3],*pbVar4,
                     pbVar4[1]);
        }
      }
      cVar15 = '\0';
      do {
        cVar19 = *(char *)((int)__s + 0x8e) * '\t';
        bVar9 = cVar15 + 1;
        iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        iVar17 = (uint)(byte)(cVar15 + cVar19) * 0xe;
        *(ushort *)(iVar3 + iVar17) = (ushort)(byte)((bVar9 & 1) + cVar19) * 0xe + 0x1400 | 0x8000;
        iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        pcVar12 = *(code **)(_r_plf_funcs_p + 0xbc);
        *(undefined2 *)(iVar3 + 2 + iVar17) = 0;
        iVar5 = (*pcVar12)(0x1400,pcVar12);
        iVar3 = _r_modules_funcs_p;
        *(undefined2 *)(iVar5 + 4 + iVar17) = 0;
        iVar3 = (**(code **)(iVar3 + 0x1a0))
                          (*(char *)(param_2 + 0x12) != '\0',*(code **)(iVar3 + 0x1a0));
        if (iVar3 != 0) {
          if (2 < _g_bt_plf_log_level) {
            ets_printf("TX PTI [CON] [EN%d] [%d] \n",*(undefined1 *)(iVar3 + 4),
                       *(undefined1 *)(iVar3 + 5));
          }
          uVar13 = (uint)*(byte *)(iVar3 + 5) << 8;
          if ((uVar13 & 0xfffff0ff) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
          }
          iVar17 = iVar17 + 10;
          iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
          uVar18 = *(ushort *)(iVar5 + iVar17);
          iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
          iVar5 = _r_plf_funcs_p;
          *(ushort *)(iVar6 + iVar17) = uVar18 & 0xf0ff | (ushort)uVar13;
          bVar1 = *(byte *)(iVar3 + 4);
          iVar3 = (**(code **)(iVar5 + 0xbc))(0x1400,*(code **)(iVar5 + 0xbc));
          uVar18 = *(ushort *)(iVar3 + iVar17);
          iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar3 + iVar17) = uVar18 & 0xefff | (ushort)bVar1 << 0xc;
        }
        cVar15 = '\x01';
      } while (bVar9 != 2);
      bVar9 = *(byte *)((int)__s + 0x8e);
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar14 + 0x1c + iVar3) = (ushort)bVar9 * 0x7e + 0x1400;
      uVar18 = *(ushort *)((int)__s + 0x84);
      if ((uVar18 & 1) == 0) {
        uVar13 = *(uint *)(param_2 + 0x10);
        uVar10 = 0;
        *(undefined2 *)((int)__s + 0x6e) = 0;
        *(uint *)((int)__s + 0x50) = uVar13;
      }
      else {
        bVar9 = *(byte *)((int)param_2 + 0x25);
        uVar13 = *(uint *)(param_2 + 0xe);
        for (uVar10 = *(short *)(&connect_req_dur_tab + (uint)bVar9 * 2) * 2 + param_2[0xc];
            0x270 < uVar10; uVar10 = uVar10 - 0x271) {
          uVar13 = uVar13 + 1 & 0xfffffff;
        }
        cVar15 = *(char *)((int)param_2 + 0x27);
        *(uint *)((int)__s + 0x50) = *(uint *)(param_2 + 0xe);
        *(ushort *)((int)__s + 0x6e) = uVar10;
        iVar3 = 4;
        if ((cVar15 != '\0') && (iVar3 = 8, 1 < bVar9)) {
          iVar3 = 0xc;
        }
        uVar13 = (uint)(*(ushort *)((int)__s + 0x70) >> 1) + *(int *)((int)__s + 0x60) + uVar13 +
                 iVar3 & 0xfffffff;
      }
      *(uint *)((int)__s + 0x48) = uVar13;
      *(undefined4 *)((int)__s + 0x54) = *(undefined4 *)((int)__s + 0x50);
      *(undefined4 *)((int)__s + 0x58) = *(undefined4 *)((int)__s + 0x50);
      if ((uVar18 & 1) == 0) {
        uVar10 = 0;
      }
      iVar3 = (int)(short)uVar10;
      *(ushort *)((int)__s + 0x6c) = uVar10;
      if ((uVar18 & 1) == 0) {
        iVar14 = (uint)DAT_00016026 << 1;
      }
      else {
        iVar14 = (uint)*(ushort *)((int)__s + 0x70) * 0x271;
      }
      *(int *)((int)__s + 0x4c) = iVar14;
      if ((uVar18 & 1) == 0) {
        iVar3 = 0;
      }
      *(int *)((int)__s + 8) = iVar3;
      (**(code **)(_r_ip_funcs_p + 0x3a8))(param_1,uVar2,0,*(code **)(_r_ip_funcs_p + 0x3a8));
      (**(code **)(_r_ip_funcs_p + 0x72c))
                (4,*(undefined1 *)((int)__s + 0x8e),*(undefined4 *)((int)__s + 100),
                 *(undefined2 *)((int)__s + 0x10),0,*(code **)(_r_ip_funcs_p + 0x72c));
      return 0;
    }
    (**(code **)(_r_plf_funcs_p + 8))("lld_con.c",0xf96,*(code **)(_r_plf_funcs_p + 8));
  }
  return 0xc;
}

