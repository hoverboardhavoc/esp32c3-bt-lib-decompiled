/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  byte bVar2;
  byte bVar3;
  void *__s;
  undefined4 uVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  undefined2 uVar8;
  undefined4 uVar9;
  uint uVar10;
  byte bVar11;
  ushort uVar12;
  undefined4 uVar13;
  uint uVar14;
  code *pcVar15;
  int iVar16;
  char cVar17;
  uint *puVar18;
  int iVar19;
  char cVar20;
  ushort uVar21;
  byte bStack_42;
  byte abStack_41 [13];
  
  if (*(int *)(&lld_con_env + param_1 * 4) == 0) {
    __s = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                            (0x9c,0,*(code **)(_r_modules_funcs_p + 0x120));
    *(void **)(&lld_con_env + param_1 * 4) = __s;
    if (__s != (void *)0x0) {
      uVar4 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
      bStack_42 = 0;
      abStack_41[0] = 0;
      memset(__s,0,0x9c);
      uVar9 = *(undefined4 *)(_r_ip_funcs_p + 0x33c);
      uVar13 = *(undefined4 *)(_r_ip_funcs_p + 0x348);
      *(char *)((int)__s + 0x8e) = (char)param_1;
      *(undefined4 *)((int)__s + 0x20) = uVar9;
      *(undefined4 *)((int)__s + 0x18) = uVar13;
      *(undefined1 *)((int)__s + 0x16) = rwip_priority;
      *(undefined2 *)((int)__s + 0x14) = 0x2000;
      if (1 < *(byte *)(param_2 + 0x12)) {
        (**(code **)(_r_plf_funcs_p + 0xc))("lld_con.c",0xd53,*(code **)(_r_plf_funcs_p + 0xc));
      }
      bVar11 = *(byte *)(param_2 + 0x12);
      *(ushort *)((int)__s + 0x70) = (ushort)*(byte *)((int)param_2 + 7) << 2;
      *(uint *)((int)__s + 0x60) = (uint)(ushort)param_2[4] << 2;
      *(uint *)((int)__s + 100) = (uint)(ushort)param_2[5] << 2;
      *(undefined2 *)((int)__s + 0x72) = param_2[6];
      *(uint *)((int)__s + 0x68) = (uint)(ushort)param_2[7] << 5;
      *(undefined1 *)((int)__s + 0x8d) = *(undefined1 *)((int)param_2 + 0x15);
      uVar8 = *(undefined2 *)(&co_sca2ppm + (uint)*(byte *)(param_2 + 0xb) * 2);
      *(undefined2 *)((int)__s + 0x90) = 0;
      *(undefined1 *)((int)__s + 0x92) = 0;
      *(undefined2 *)((int)__s + 0x7a) = uVar8;
      *(ushort *)((int)__s + 0x84) = *(ushort *)((int)__s + 0x84) & 0xfbfe | (ushort)bVar11 | 0x10;
      *(undefined4 *)((int)__s + 0x24) = 0;
      *(undefined4 *)((int)__s + 0x30) = 0;
      *(undefined4 *)((int)__s + 0x7c) = 0;
      *(undefined4 *)((int)__s + 0x80) = 0;
      *(undefined2 *)((int)__s + 0x86) = 0x1b;
      cVar17 = *(char *)((int)param_2 + 0x25);
      uVar8 = 0x148;
      if ((byte)(cVar17 - 2U) < 2) {
        uVar8 = 0xa90;
      }
      *(undefined2 *)((int)__s + 0x88) = uVar8;
      *(undefined2 *)((int)__s + 0x8a) = uVar8;
      *(undefined1 *)((int)__s + 0x8c) = 0x1b;
      *(char *)((int)__s + 0x93) = cVar17;
      *(char *)((int)__s + 0x94) = cVar17;
      *(undefined1 *)((int)__s + 0x95) = 0;
      if ((bVar11 & 1) != 0) {
        (**(code **)(_r_ip_funcs_p + 0x36c))
                  (*(undefined1 *)((int)__s + 0x8e),*(code **)(_r_ip_funcs_p + 0x36c));
      }
      uVar12 = (*(char *)(param_2 + 0x12) != '\0') + 2;
      (**(code **)(_r_modules_funcs_p + 0x1e0))
                (uVar12,param_1,&bStack_42,abStack_41,*(code **)(_r_modules_funcs_p + 0x1e0));
      bVar3 = abStack_41[0];
      bVar2 = bStack_42;
      uVar14 = (uint)rwip_coex_cfg;
      bVar11 = rwip_coex_cfg >> 1;
      bVar1 = rwip_coex_cfg >> 2;
      if ((bStack_42 & 0xfe) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x42,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((bVar3 & 0xfe) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x43,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar16 = param_1 * 0x5a;
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      cVar17 = DAT_0001604f;
      *(ushort *)(iVar5 + iVar16) =
           (ushort)bVar2 << 7 | (ushort)bVar3 << 6 | (ushort)((uVar14 & 1) << 10) |
           (ushort)((bVar11 & 1) << 9) | (ushort)((bVar1 & 1) << 8) | uVar12;
      bVar11 = *(byte *)((int)param_2 + 0x25);
      uVar21 = (ushort)bVar11;
      if ((cVar17 == '\0') || (1 < (byte)(bVar11 - 2))) {
        if ((bVar11 & 0xfc) == 0) {
          if (bVar11 < 4) goto _L600;
        }
        else {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",399,*(code **)(_r_plf_funcs_p + 8));
        }
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",400,*(code **)(_r_plf_funcs_p + 8));
      }
      else {
        uVar21 = *(byte *)(_p_lld_env + 0xda) + 2 & 0xff;
      }
_L600:
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar16 + 4 + iVar5) = (ushort)bVar11 << 2 | uVar21 | 0x1100;
      if (0x1f < param_1) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0xe6,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar5 + iVar16 + 2) = (ushort)param_1 | 0x800;
      uVar8 = *param_2;
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar16 + 0xc + iVar5) = uVar8;
      uVar8 = param_2[1];
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar16 + 0xe + iVar5) = uVar8;
      uVar8 = param_2[2];
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar16 + 0x10 + iVar5) = uVar8;
      bVar11 = *(byte *)(param_2 + 3);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar16 + 0x12 + iVar5) = (ushort)bVar11;
      bVar11 = *(byte *)((int)__s + 0x8d);
      bVar1 = *(byte *)(param_2 + 0x13);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar16 + 0x16 + iVar5) =
           (ushort)((bVar11 & 0x1f) << 8) | (ushort)bVar1 << 0xe | 0x8000;
      *(ushort *)((int)__s + 0x84) =
           (ushort)((*(byte *)(param_2 + 0x13) ^ 1) << 9) | *(ushort *)((int)__s + 0x84) & 0xfdff;
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar16 + 0x18 + iVar5) = 0;
      (**(code **)(_r_ip_funcs_p + 0x3ac))(param_1,uVar12,*(code **)(_r_ip_funcs_p + 0x3ac));
      (**(code **)(_r_ip_funcs_p + 0x34c))(param_1,*(code **)(_r_ip_funcs_p + 0x34c));
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar16 + 0x28 + iVar5) = 0xfb;
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar16 + 0x2a + iVar5) = 0;
      bVar11 = DAT_00016026;
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar16 + 0x1a + iVar5) = (ushort)bVar11;
      uVar8 = param_2[8];
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar16 + 0x22 + iVar5) = uVar8;
      uVar8 = param_2[9];
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar16 + 0x24 + iVar5) = uVar8;
      uVar8 = param_2[10];
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar16 + 0x26 + iVar5) = uVar8;
      pbVar6 = (byte *)(**(code **)(_r_modules_funcs_p + 0x1a0))
                                 (*(char *)(param_2 + 0x12) != '\0',
                                  *(code **)(_r_modules_funcs_p + 0x1a0));
      if (pbVar6 != (byte *)0x0) {
        bVar11 = pbVar6[1];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x299b,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((bVar11 & 0xf0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x299d,*(code **)(_r_plf_funcs_p + 8));
        }
        puVar18 = (uint *)((param_1 + 0x1800c4cb) * 4);
        *puVar18 = *puVar18 & 0xfffff0ff | (uint)bVar11 << 8;
        bVar11 = *pbVar6;
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x294a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar18 = *puVar18 & 0xbfffffff | (uint)bVar11 << 0x1e;
        bVar11 = pbVar6[3];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x29bb,*(code **)(_r_plf_funcs_p + 8));
        }
        if (0xf < bVar11) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x29bd,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar18 = *puVar18 & 0xfffffff0 | (uint)bVar11;
        bVar11 = pbVar6[2];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x295a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar18 = *puVar18 & 0xdfffffff | (uint)bVar11 << 0x1d;
        bVar11 = pbVar6[7];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x298b,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((bVar11 & 0xf0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x298d,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar18 = *puVar18 & 0xffff0fff | (uint)bVar11 << 0xc;
        bVar11 = pbVar6[8];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x29ab,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((bVar11 & 0xf0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x29ad,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar18 = *puVar18 & 0xffffff0f | (uint)bVar11 << 4;
        bVar11 = pbVar6[9];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x297b,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((bVar11 & 0xf0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x297d,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar18 = *puVar18 & 0xfff0ffff | (uint)bVar11 << 0x10;
        uVar12 = *(ushort *)(pbVar6 + 10);
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x296a,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((uVar12 >> 9 & 7) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x296c,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar18 = *puVar18 & 0xe00fffff | (uint)uVar12 << 0x14;
        bVar11 = pbVar6[6];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x293a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar18 = *puVar18 & 0x7fffffff | (uint)bVar11 << 0x1f;
        if (2 < _g_bt_plf_log_level) {
          ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[CON[%d]] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                     ,param_1,puVar18,*(undefined1 *)(param_2 + 0x12),pbVar6[2],pbVar6[3],*pbVar6,
                     pbVar6[1]);
        }
      }
      cVar17 = '\0';
      do {
        cVar20 = *(char *)((int)__s + 0x8e) * '\t';
        bVar11 = cVar17 + 1;
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        iVar19 = (uint)(byte)(cVar17 + cVar20) * 0xe;
        *(ushort *)(iVar5 + iVar19) = (ushort)(byte)((bVar11 & 1) + cVar20) * 0xe + 0x1400 | 0x8000;
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        pcVar15 = *(code **)(_r_plf_funcs_p + 0xbc);
        *(undefined2 *)(iVar5 + 2 + iVar19) = 0;
        iVar7 = (*pcVar15)(0x1400,pcVar15);
        iVar5 = _r_modules_funcs_p;
        *(undefined2 *)(iVar7 + 4 + iVar19) = 0;
        iVar5 = (**(code **)(iVar5 + 0x1a0))
                          (*(char *)(param_2 + 0x12) != '\0',*(code **)(iVar5 + 0x1a0));
        if (iVar5 != 0) {
          if (2 < _g_bt_plf_log_level) {
            ets_printf("TX PTI [CON] [EN%d] [%d] \n",*(undefined1 *)(iVar5 + 4),
                       *(undefined1 *)(iVar5 + 5));
          }
          bVar1 = *(byte *)(iVar5 + 5);
          if ((bVar1 & 0xf0) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
          }
          iVar19 = iVar19 + 10;
          iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
          uVar12 = *(ushort *)(iVar7 + iVar19);
          iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar7 + iVar19) = uVar12 & 0xf0ff | (ushort)bVar1 << 8;
          bVar1 = *(byte *)(iVar5 + 4);
          iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
          uVar12 = *(ushort *)(iVar5 + iVar19);
          iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar5 + iVar19) = uVar12 & 0xefff | (ushort)bVar1 << 0xc;
        }
        cVar17 = '\x01';
      } while (bVar11 != 2);
      bVar11 = *(byte *)((int)__s + 0x8e);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar16 + 0x1c + iVar5) = (ushort)bVar11 * 0x7e + 0x1400;
      if ((*(ushort *)((int)__s + 0x84) & 1) == 0) {
        uVar10 = *(uint *)(param_2 + 0x10);
        uVar12 = 0;
        *(undefined2 *)((int)__s + 0x6e) = 0;
        *(uint *)((int)__s + 0x50) = uVar10;
        uVar14 = uVar10;
      }
      else {
        bVar11 = *(byte *)((int)param_2 + 0x25);
        uVar10 = *(uint *)(param_2 + 0xe);
        uVar14 = uVar10;
        for (uVar12 = *(short *)(&connect_req_dur_tab + (uint)bVar11 * 2) * 2 + param_2[0xc];
            0x270 < uVar12; uVar12 = uVar12 - 0x271) {
          uVar14 = uVar14 + 1 & 0xfffffff;
        }
        cVar17 = *(char *)((int)param_2 + 0x27);
        *(uint *)((int)__s + 0x50) = uVar10;
        *(ushort *)((int)__s + 0x6e) = uVar12;
        iVar5 = 4;
        if (cVar17 != '\0') {
          iVar5 = (uint)(1 < bVar11) * 4 + 8;
        }
        uVar14 = (uint)(*(ushort *)((int)__s + 0x70) >> 1) + *(int *)((int)__s + 0x60) + uVar14 +
                 iVar5 & 0xfffffff;
      }
      *(uint *)((int)__s + 0x54) = uVar10;
      *(uint *)((int)__s + 0x58) = uVar10;
      *(uint *)((int)__s + 0x48) = uVar14;
      if ((*(ushort *)((int)__s + 0x84) & 1) == 0) {
        *(undefined2 *)((int)__s + 0x6c) = 0;
        iVar16 = 0;
        iVar5 = (uint)DAT_00016026 << 1;
      }
      else {
        iVar16 = (int)(short)uVar12;
        iVar5 = (uint)*(ushort *)((int)__s + 0x70) * 0x271;
        *(ushort *)((int)__s + 0x6c) = uVar12;
      }
      *(int *)((int)__s + 8) = iVar16;
      iVar16 = _r_ip_funcs_p;
      *(int *)((int)__s + 0x4c) = iVar5;
      (**(code **)(iVar16 + 0x3a8))(param_1,uVar4,0,*(code **)(iVar16 + 0x3a8));
      (**(code **)(_r_ip_funcs_p + 0x72c))
                (4,*(undefined1 *)((int)__s + 0x8e),*(undefined4 *)((int)__s + 100),
                 *(undefined2 *)((int)__s + 0x10),0,*(code **)(_r_ip_funcs_p + 0x72c));
      return 0;
    }
    (**(code **)(_r_plf_funcs_p + 8))("lld_con.c",0xe28,*(code **)(_r_plf_funcs_p + 8));
  }
  return 0xc;
}

