/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  undefined1 uVar2;
  void *__s;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  undefined2 uVar8;
  undefined4 uVar9;
  byte bVar10;
  ushort uVar11;
  undefined4 uVar12;
  code *pcVar13;
  uint uVar14;
  int iVar15;
  char cVar16;
  uint uVar17;
  uint *puVar18;
  int iVar19;
  ushort uVar20;
  char cVar21;
  uint uVar22;
  byte bStack_42;
  byte abStack_41 [13];
  
  if (*(int *)(&lld_con_env + param_1 * 4) == 0) {
    __s = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                            (0x9c,0,*(code **)(_r_modules_funcs_p + 0x120));
    *(void **)(&lld_con_env + param_1 * 4) = __s;
    if (__s != (void *)0x0) {
      uVar3 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
      bStack_42 = 0;
      abStack_41[0] = 0;
      memset(__s,0,0x9c);
      uVar9 = *(undefined4 *)(_r_ip_funcs_p + 0x33c);
      uVar12 = *(undefined4 *)(_r_ip_funcs_p + 0x348);
      *(undefined4 *)((int)__s + 0x1c) = 0;
      *(undefined4 *)((int)__s + 0x20) = uVar9;
      *(undefined4 *)((int)__s + 0x18) = uVar12;
      uVar2 = rwip_priority;
      *(undefined4 *)((int)__s + 8) = 0;
      *(char *)((int)__s + 0x8e) = (char)param_1;
      *(undefined1 *)((int)__s + 0x16) = uVar2;
      *(undefined2 *)((int)__s + 0x14) = 0x2000;
      if ((*(byte *)(param_2 + 0x12) & 0xfe) != 0) {
        (**(code **)(_r_plf_funcs_p + 0xc))(1,"lld_con.c",0xd2b,*(code **)(_r_plf_funcs_p + 0xc));
      }
      bVar10 = *(byte *)(param_2 + 0x12);
      *(ushort *)((int)__s + 0x70) = (ushort)*(byte *)((int)param_2 + 7) << 2;
      *(uint *)((int)__s + 0x60) = (uint)(ushort)param_2[4] << 2;
      *(uint *)((int)__s + 100) = (uint)(ushort)param_2[5] << 2;
      *(undefined2 *)((int)__s + 0x72) = param_2[6];
      *(uint *)((int)__s + 0x68) = (uint)(ushort)param_2[7] << 5;
      *(undefined1 *)((int)__s + 0x8d) = *(undefined1 *)((int)param_2 + 0x15);
      bVar1 = *(byte *)(param_2 + 0xb);
      *(undefined2 *)((int)__s + 0x90) = 0;
      *(undefined1 *)((int)__s + 0x92) = 0;
      uVar8 = *(undefined2 *)(&co_sca2ppm + (uint)bVar1 * 2);
      *(undefined4 *)((int)__s + 0x24) = 0;
      *(undefined4 *)((int)__s + 0x30) = 0;
      *(undefined2 *)((int)__s + 0x7a) = uVar8;
      *(ushort *)((int)__s + 0x84) = *(ushort *)((int)__s + 0x84) & 0xfbfe | (ushort)bVar10 | 0x10;
      *(undefined2 *)((int)__s + 0x86) = 0x1b;
      *(undefined4 *)((int)__s + 0x7c) = 0;
      *(undefined4 *)((int)__s + 0x80) = 0;
      cVar16 = *(char *)((int)param_2 + 0x25);
      if ((byte)(cVar16 - 2U) < 2) {
        uVar8 = 0xa90;
      }
      else {
        uVar8 = 0x148;
      }
      *(undefined2 *)((int)__s + 0x88) = uVar8;
      *(undefined2 *)((int)__s + 0x8a) = uVar8;
      *(undefined1 *)((int)__s + 0x8c) = 0x1b;
      *(char *)((int)__s + 0x93) = cVar16;
      *(char *)((int)__s + 0x94) = cVar16;
      *(undefined1 *)((int)__s + 0x95) = 0;
      if ((bVar10 & 1) != 0) {
        (**(code **)(_r_ip_funcs_p + 0x36c))
                  (*(undefined1 *)((int)__s + 0x8e),*(code **)(_r_ip_funcs_p + 0x36c));
      }
      uVar20 = (*(char *)(param_2 + 0x12) != '\0') + 2;
      (**(code **)(_r_modules_funcs_p + 0x1e0))
                (uVar20,param_1,&bStack_42,abStack_41,*(code **)(_r_modules_funcs_p + 0x1e0));
      uVar14 = (uint)rwip_coex_cfg;
      uVar22 = (uint)abStack_41[0];
      uVar17 = (uint)bStack_42;
      if ((uVar17 << 7 & 0xffffff7f) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x42,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((uVar22 << 6 & 0xffffffbf) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x43,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar15 = param_1 * 0x5a;
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar15) =
           (ushort)(uVar17 << 7) | (ushort)(uVar22 << 6) | (ushort)((uVar14 & 1) << 10) |
           (ushort)((uVar14 & 2) << 8) | (ushort)((uVar14 & 4) << 6) | uVar20;
      uVar17 = (uint)*(byte *)((int)param_2 + 0x25);
      uVar14 = uVar17;
      if ((DAT_0001604f != '\0') && ((uVar17 - 2 & 0xff) < 2)) {
        uVar14 = (*(char *)(_p_lld_env + 0xda) != '\0') + 2;
      }
      if ((uVar17 << 2 & 0xfffffff3) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",399,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((uVar14 & 0xfffffffc) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",400,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar15 + 4) = (ushort)(uVar17 << 2) | (ushort)uVar14 | 0x1100;
      if ((param_1 & 0xffffffe0) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0xe6,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar15 + 2) = (ushort)param_1 | 0x800;
      uVar8 = *param_2;
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar4 + iVar15 + 0xc) = uVar8;
      uVar8 = param_2[1];
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar4 + iVar15 + 0xe) = uVar8;
      uVar8 = param_2[2];
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar4 = _r_plf_funcs_p;
      *(undefined2 *)(iVar5 + iVar15 + 0x10) = uVar8;
      bVar10 = *(byte *)(param_2 + 3);
      iVar4 = (**(code **)(iVar4 + 0xbc))(0x400,*(code **)(iVar4 + 0xbc));
      *(ushort *)(iVar4 + iVar15 + 0x12) = (ushort)bVar10;
      bVar10 = *(byte *)((int)__s + 0x8d);
      bVar1 = *(byte *)(param_2 + 0x13);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar15 + 0x16) =
           (ushort)((bVar10 & 0x1f) << 8) | (ushort)bVar1 << 0xe | 0x8000;
      *(ushort *)((int)__s + 0x84) =
           (ushort)((*(byte *)(param_2 + 0x13) ^ 1) << 9) | *(ushort *)((int)__s + 0x84) & 0xfdff;
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar4 = _r_ip_funcs_p;
      *(undefined2 *)(iVar5 + iVar15 + 0x18) = 0;
      (**(code **)(iVar4 + 0x3ac))(param_1,uVar20,*(code **)(iVar4 + 0x3ac));
      (**(code **)(_r_ip_funcs_p + 0x34c))(param_1,*(code **)(_r_ip_funcs_p + 0x34c));
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar4 + iVar15 + 0x28) = 0xfb;
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar4 = _r_plf_funcs_p;
      *(undefined2 *)(iVar5 + iVar15 + 0x2a) = 0;
      bVar10 = DAT_00016026;
      iVar4 = (**(code **)(iVar4 + 0xbc))(0x400,*(code **)(iVar4 + 0xbc));
      *(ushort *)(iVar4 + iVar15 + 0x1a) = (ushort)bVar10;
      uVar8 = param_2[8];
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar4 + iVar15 + 0x22) = uVar8;
      uVar8 = param_2[9];
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar4 + iVar15 + 0x24) = uVar8;
      uVar8 = param_2[10];
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar4 = _r_modules_funcs_p;
      *(undefined2 *)(iVar5 + iVar15 + 0x26) = uVar8;
      pbVar6 = (byte *)(**(code **)(iVar4 + 0x1a0))
                                 (*(char *)(param_2 + 0x12) != '\0',*(code **)(iVar4 + 0x1a0));
      if (pbVar6 != (byte *)0x0) {
        bVar10 = pbVar6[1];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x299b,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar10 << 8 & 0xf000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x299d,*(code **)(_r_plf_funcs_p + 8));
        }
        puVar18 = (uint *)((param_1 + 0x1800c4cb) * 4);
        *puVar18 = *puVar18 & 0xfffff0ff | (uint)bVar10 << 8;
        bVar10 = *pbVar6;
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x294a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar18 = (uint)bVar10 << 0x1e | *puVar18 & 0xbfffffff;
        bVar10 = pbVar6[3];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x29bb,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((bVar10 & 0xf0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x29bd,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar18 = *puVar18 & 0xfffffff0 | (uint)bVar10;
        bVar10 = pbVar6[2];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x295a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar18 = (uint)bVar10 << 0x1d | *puVar18 & 0xdfffffff;
        bVar10 = pbVar6[7];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x298b,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar10 << 0xc & 0xf0000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x298d,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar18 = *puVar18 & 0xffff0fff | (uint)bVar10 << 0xc;
        bVar10 = pbVar6[8];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x29ab,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar10 << 4 & 0xffffff0f) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x29ad,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar18 = *puVar18 & 0xffffff0f | (uint)bVar10 << 4;
        bVar10 = pbVar6[9];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x297b,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar10 << 0x10 & 0xf00000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x297d,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar18 = *puVar18 & 0xfff0ffff | (uint)bVar10 << 0x10;
        uVar20 = *(ushort *)(pbVar6 + 10);
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x296a,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)uVar20 << 0x14 & 0xe0000000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x296c,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar18 = *puVar18 & 0xe00fffff | (uint)uVar20 << 0x14;
        bVar10 = pbVar6[6];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x293a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar18 = *puVar18 & 0x7fffffff | (uint)bVar10 << 0x1f;
        if (2 < _g_bt_plf_log_level) {
          ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[CON[%d]] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                     ,param_1,puVar18,*(undefined1 *)(param_2 + 0x12),pbVar6[2],pbVar6[3],*pbVar6,
                     pbVar6[1]);
        }
      }
      cVar16 = '\0';
      do {
        cVar21 = *(char *)((int)__s + 0x8e) * '\t';
        bVar10 = cVar16 + 1;
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        iVar19 = (uint)(byte)(cVar16 + cVar21) * 0xe;
        *(ushort *)(iVar4 + iVar19) = (ushort)(byte)((bVar10 & 1) + cVar21) * 0xe + 0x1400 | 0x8000;
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        pcVar13 = *(code **)(_r_plf_funcs_p + 0xbc);
        *(undefined2 *)(iVar4 + 2 + iVar19) = 0;
        iVar5 = (*pcVar13)(0x1400,pcVar13);
        iVar4 = _r_modules_funcs_p;
        *(undefined2 *)(iVar5 + 4 + iVar19) = 0;
        iVar4 = (**(code **)(iVar4 + 0x1a0))
                          (*(char *)(param_2 + 0x12) != '\0',*(code **)(iVar4 + 0x1a0));
        if (iVar4 != 0) {
          if (2 < _g_bt_plf_log_level) {
            ets_printf("TX PTI [CON] [EN%d] [%d] \n",*(undefined1 *)(iVar4 + 4),
                       *(undefined1 *)(iVar4 + 5));
          }
          uVar14 = (uint)*(byte *)(iVar4 + 5) << 8;
          if ((uVar14 & 0xfffff0ff) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
          }
          iVar19 = iVar19 + 10;
          iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
          uVar20 = *(ushort *)(iVar5 + iVar19);
          iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
          iVar5 = _r_plf_funcs_p;
          *(ushort *)(iVar7 + iVar19) = uVar20 & 0xf0ff | (ushort)uVar14;
          bVar1 = *(byte *)(iVar4 + 4);
          iVar4 = (**(code **)(iVar5 + 0xbc))(0x1400,*(code **)(iVar5 + 0xbc));
          uVar20 = *(ushort *)(iVar4 + iVar19);
          iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar4 + iVar19) = uVar20 & 0xefff | (ushort)bVar1 << 0xc;
        }
        cVar16 = '\x01';
      } while (bVar10 != 2);
      bVar10 = *(byte *)((int)__s + 0x8e);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar15 + 0x1c + iVar4) = (ushort)bVar10 * 0x7e + 0x1400;
      uVar20 = *(ushort *)((int)__s + 0x84);
      if ((uVar20 & 1) == 0) {
        uVar14 = *(uint *)(param_2 + 0x10);
        uVar11 = 0;
        *(undefined2 *)((int)__s + 0x6e) = 0;
        *(uint *)((int)__s + 0x50) = uVar14;
      }
      else {
        bVar10 = *(byte *)((int)param_2 + 0x25);
        uVar14 = *(uint *)(param_2 + 0xe);
        for (uVar11 = *(short *)(&connect_req_dur_tab + (uint)bVar10 * 2) * 2 + param_2[0xc];
            0x270 < uVar11; uVar11 = uVar11 - 0x271) {
          uVar14 = uVar14 + 1 & 0xfffffff;
        }
        *(uint *)((int)__s + 0x50) = *(uint *)(param_2 + 0xe);
        cVar16 = *(char *)((int)param_2 + 0x27);
        *(ushort *)((int)__s + 0x6e) = uVar11;
        iVar4 = 4;
        if ((cVar16 != '\0') && (iVar4 = 8, 1 < bVar10)) {
          iVar4 = 0xc;
        }
        uVar14 = (uVar14 + *(int *)((int)__s + 0x60) + iVar4 & 0xfffffff) +
                 (uint)(*(ushort *)((int)__s + 0x70) >> 1) & 0xfffffff;
      }
      *(uint *)((int)__s + 0x48) = uVar14;
      *(undefined4 *)((int)__s + 0x54) = *(undefined4 *)((int)__s + 0x50);
      *(undefined4 *)((int)__s + 0x58) = *(undefined4 *)((int)__s + 0x50);
      if ((uVar20 & 1) == 0) {
        uVar11 = 0;
      }
      iVar4 = (int)(short)uVar11;
      *(ushort *)((int)__s + 0x6c) = uVar11;
      if ((uVar20 & 1) == 0) {
        iVar15 = (uint)DAT_00016026 << 1;
      }
      else {
        iVar15 = (uint)*(ushort *)((int)__s + 0x70) * 0x271;
      }
      *(int *)((int)__s + 0x4c) = iVar15;
      if ((uVar20 & 1) == 0) {
        iVar4 = 0;
      }
      *(int *)((int)__s + 8) = iVar4;
      (**(code **)(_r_ip_funcs_p + 0x3a8))(param_1,uVar3,0,*(code **)(_r_ip_funcs_p + 0x3a8));
      (**(code **)(_r_ip_funcs_p + 0x72c))
                (4,*(undefined1 *)((int)__s + 0x8e),*(undefined4 *)((int)__s + 100),
                 *(undefined2 *)((int)__s + 0x10),0,*(code **)(_r_ip_funcs_p + 0x72c));
      return 0;
    }
    (**(code **)(_r_plf_funcs_p + 8))("lld_con.c",0xe00,*(code **)(_r_plf_funcs_p + 8));
  }
  return 0xc;
}

