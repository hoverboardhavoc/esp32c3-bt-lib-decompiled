/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_start
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
  byte bVar3;
  byte bVar4;
  void *__s;
  undefined4 uVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  undefined2 uVar9;
  uint uVar10;
  ushort uVar11;
  uint uVar12;
  int iVar13;
  char cVar14;
  uint *puVar15;
  int iVar16;
  char cVar17;
  ushort uVar18;
  byte bVar19;
  byte bStack_42;
  byte abStack_41 [13];
  
  if (*(int *)(&lld_con_env + param_1 * 4) == 0) {
    __s = (void *)r_ke_malloc(0x9c,0);
    *(void **)(&lld_con_env + param_1 * 4) = __s;
    if (__s != (void *)0x0) {
      uVar5 = r_lld_read_clock();
      bStack_42 = 0;
      abStack_41[0] = 0;
      memset(__s,0,0x9c);
      *(code **)((int)__s + 0x20) = r_lld_con_evt_canceled_cbk_eco;
      *(code **)((int)__s + 0x18) = r_lld_con_evt_start_cbk_eco;
      uVar2 = rwip_priority;
      *(char *)((int)__s + 0x8e) = (char)param_1;
      *(undefined1 *)((int)__s + 0x16) = uVar2;
      *(undefined2 *)((int)__s + 0x14) = 0x2000;
      if (1 < *(byte *)(param_2 + 0x12)) {
        r_assert_param("lld_con.c",0xd53);
      }
      bVar19 = *(byte *)(param_2 + 0x12);
      *(ushort *)((int)__s + 0x70) = (ushort)*(byte *)((int)param_2 + 7) << 2;
      *(uint *)((int)__s + 0x60) = (uint)(ushort)param_2[4] << 2;
      *(uint *)((int)__s + 100) = (uint)(ushort)param_2[5] << 2;
      *(undefined2 *)((int)__s + 0x72) = param_2[6];
      *(uint *)((int)__s + 0x68) = (uint)(ushort)param_2[7] << 5;
      *(undefined1 *)((int)__s + 0x8d) = *(undefined1 *)((int)param_2 + 0x15);
      uVar9 = *(undefined2 *)(&co_sca2ppm + (uint)*(byte *)(param_2 + 0xb) * 2);
      *(undefined2 *)((int)__s + 0x90) = 0;
      *(undefined1 *)((int)__s + 0x92) = 0;
      *(undefined2 *)((int)__s + 0x7a) = uVar9;
      *(ushort *)((int)__s + 0x84) = *(ushort *)((int)__s + 0x84) & 0xfbfe | (ushort)bVar19 | 0x10;
      *(undefined4 *)((int)__s + 0x24) = 0;
      *(undefined4 *)((int)__s + 0x30) = 0;
      *(undefined4 *)((int)__s + 0x7c) = 0;
      *(undefined4 *)((int)__s + 0x80) = 0;
      *(undefined2 *)((int)__s + 0x86) = 0x1b;
      cVar14 = *(char *)((int)param_2 + 0x25);
      uVar9 = 0x148;
      if ((byte)(cVar14 - 2U) < 2) {
        uVar9 = 0xa90;
      }
      *(undefined2 *)((int)__s + 0x88) = uVar9;
      *(undefined2 *)((int)__s + 0x8a) = uVar9;
      *(undefined1 *)((int)__s + 0x8c) = 0x1b;
      *(char *)((int)__s + 0x93) = cVar14;
      *(char *)((int)__s + 0x94) = cVar14;
      *(undefined1 *)((int)__s + 0x95) = 0;
      if ((bVar19 & 1) != 0) {
        r_lld_con_max_lat_calc(*(undefined1 *)((int)__s + 0x8e));
      }
      uVar11 = (*(char *)(param_2 + 0x12) != '\0') + 2;
      r_bt_rma_get_ant_by_act(uVar11,param_1,&bStack_42,abStack_41);
      bVar4 = abStack_41[0];
      bVar3 = bStack_42;
      uVar12 = (uint)rwip_coex_cfg;
      bVar19 = rwip_coex_cfg >> 1;
      bVar1 = rwip_coex_cfg >> 2;
      if ((bStack_42 & 0xfe) != 0) {
        r_assert_err(0,"lld_con.c",0x42);
      }
      if ((bVar4 & 0xfe) != 0) {
        r_assert_err(0,"lld_con.c",0x43);
      }
      iVar13 = param_1 * 0x5a;
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      cVar14 = DAT_0001608f;
      *(ushort *)(iVar6 + iVar13) =
           (ushort)bVar3 << 7 | (ushort)bVar4 << 6 | (ushort)((uVar12 & 1) << 10) |
           (ushort)((bVar19 & 1) << 9) | (ushort)((bVar1 & 1) << 8) | uVar11;
      bVar19 = *(byte *)((int)param_2 + 0x25);
      uVar18 = (ushort)bVar19;
      if ((cVar14 == '\0') || (1 < (byte)(bVar19 - 2))) {
        if ((bVar19 & 0xfc) == 0) {
          if (bVar19 < 4) goto _L643;
        }
        else {
          r_assert_err(0,"lld_con.c",399);
        }
        r_assert_err(0,"lld_con.c",400);
      }
      else {
        uVar18 = *(byte *)(_p_lld_env + 0xda) + 2 & 0xff;
      }
_L643:
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar13 + 4 + iVar6) = (ushort)bVar19 << 2 | uVar18 | 0x1100;
      if (0x1f < param_1) {
        r_assert_err(0,"lld_con.c",0xe6);
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + iVar13 + 2) = (ushort)param_1 | 0x800;
      uVar9 = *param_2;
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar13 + 0xc + iVar6) = uVar9;
      uVar9 = param_2[1];
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar13 + 0xe + iVar6) = uVar9;
      uVar9 = param_2[2];
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar13 + 0x10 + iVar6) = uVar9;
      bVar19 = *(byte *)(param_2 + 3);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar13 + 0x12 + iVar6) = (ushort)bVar19;
      bVar19 = *(byte *)((int)__s + 0x8d);
      bVar1 = *(byte *)(param_2 + 0x13);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar13 + 0x16 + iVar6) =
           (ushort)((bVar19 & 0x1f) << 8) | (ushort)bVar1 << 0xe | 0x8000;
      *(ushort *)((int)__s + 0x84) =
           (ushort)((*(byte *)(param_2 + 0x13) ^ 1) << 9) | *(ushort *)((int)__s + 0x84) & 0xfdff;
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar13 + 0x18 + iVar6) = 0;
      r_lld_con_set_tx_power(param_1,uVar11);
      r_lld_con_evt_time_update_eco(param_1);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar13 + 0x28 + iVar6) = 0xfb;
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar13 + 0x2a + iVar6) = 0;
      bVar19 = DAT_00016066;
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar13 + 0x1a + iVar6) = (ushort)bVar19;
      uVar9 = param_2[8];
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar13 + 0x22 + iVar6) = uVar9;
      uVar9 = param_2[9];
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar13 + 0x24 + iVar6) = uVar9;
      uVar9 = param_2[10];
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar13 + 0x26 + iVar6) = uVar9;
      pbVar7 = (byte *)r_bt_rf_coex_st_param_get(*(char *)(param_2 + 0x12) != '\0');
      if (pbVar7 != (byte *)0x0) {
        bVar19 = pbVar7[1];
        if (0xb < param_1) {
          r_assert_err(0,"lld_con.c",0x299b);
        }
        if ((bVar19 & 0xf0) != 0) {
          r_assert_err(0,"lld_con.c",0x299d);
        }
        puVar15 = (uint *)((param_1 + 0x1800c4cb) * 4);
        *puVar15 = *puVar15 & 0xfffff0ff | (uint)bVar19 << 8;
        bVar19 = *pbVar7;
        if (0xb < param_1) {
          r_assert_err(0,"lld_con.c",0x294a);
        }
        *puVar15 = *puVar15 & 0xbfffffff | (uint)bVar19 << 0x1e;
        bVar19 = pbVar7[3];
        if (0xb < param_1) {
          r_assert_err(0,"lld_con.c",0x29bb);
        }
        if (0xf < bVar19) {
          r_assert_err(0,"lld_con.c",0x29bd);
        }
        *puVar15 = *puVar15 & 0xfffffff0 | (uint)bVar19;
        bVar19 = pbVar7[2];
        if (0xb < param_1) {
          r_assert_err(0,"lld_con.c",0x295a);
        }
        *puVar15 = *puVar15 & 0xdfffffff | (uint)bVar19 << 0x1d;
        bVar19 = pbVar7[7];
        if (0xb < param_1) {
          r_assert_err(0,"lld_con.c",0x298b);
        }
        if ((bVar19 & 0xf0) != 0) {
          r_assert_err(0,"lld_con.c",0x298d);
        }
        *puVar15 = *puVar15 & 0xffff0fff | (uint)bVar19 << 0xc;
        bVar19 = pbVar7[8];
        if (0xb < param_1) {
          r_assert_err(0,"lld_con.c",0x29ab);
        }
        if ((bVar19 & 0xf0) != 0) {
          r_assert_err(0,"lld_con.c",0x29ad);
        }
        *puVar15 = *puVar15 & 0xffffff0f | (uint)bVar19 << 4;
        bVar19 = pbVar7[9];
        if (0xb < param_1) {
          r_assert_err(0,"lld_con.c",0x297b);
        }
        if ((bVar19 & 0xf0) != 0) {
          r_assert_err(0,"lld_con.c",0x297d);
        }
        *puVar15 = *puVar15 & 0xfff0ffff | (uint)bVar19 << 0x10;
        uVar11 = *(ushort *)(pbVar7 + 10);
        if (0xb < param_1) {
          r_assert_err(0,"lld_con.c",0x296a);
        }
        if ((uVar11 >> 9 & 7) != 0) {
          r_assert_err(0,"lld_con.c",0x296c);
        }
        *puVar15 = *puVar15 & 0xe00fffff | (uint)uVar11 << 0x14;
        bVar19 = pbVar7[6];
        if (0xb < param_1) {
          r_assert_err(0,"lld_con.c",0x293a);
        }
        *puVar15 = *puVar15 & 0x7fffffff | (uint)bVar19 << 0x1f;
        if (2 < _g_bt_plf_log_level) {
          ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[CON[%d]] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                     ,param_1,puVar15,*(undefined1 *)(param_2 + 0x12),pbVar7[2],pbVar7[3],*pbVar7,
                     pbVar7[1]);
        }
      }
      cVar14 = '\0';
      do {
        cVar17 = *(char *)((int)__s + 0x8e) * '\t';
        iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
        bVar19 = cVar14 + 1;
        iVar16 = (uint)(byte)(cVar14 + cVar17) * 0xe;
        *(ushort *)(iVar6 + iVar16) = (ushort)(byte)((bVar19 & 1) + cVar17) * 0xe + 0x1400 | 0x8000;
        iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
        *(undefined2 *)(iVar6 + 2 + iVar16) = 0;
        iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
        *(undefined2 *)(iVar6 + 4 + iVar16) = 0;
        iVar6 = r_bt_rf_coex_st_param_get(*(char *)(param_2 + 0x12) != '\0');
        if (iVar6 != 0) {
          if (2 < _g_bt_plf_log_level) {
            ets_printf("TX PTI [CON] [EN%d] [%d] \n",*(undefined1 *)(iVar6 + 4),
                       *(undefined1 *)(iVar6 + 5));
          }
          bVar1 = *(byte *)(iVar6 + 5);
          if ((bVar1 & 0xf0) != 0) {
            r_assert_err(0,"lld_con.c",0x33f);
          }
          iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
          iVar16 = iVar16 + 10;
          uVar11 = *(ushort *)(iVar8 + iVar16);
          iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
          *(ushort *)(iVar8 + iVar16) = uVar11 & 0xf0ff | (ushort)bVar1 << 8;
          bVar1 = *(byte *)(iVar6 + 4);
          iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
          uVar11 = *(ushort *)(iVar6 + iVar16);
          iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
          *(ushort *)(iVar6 + iVar16) = uVar11 & 0xefff | (ushort)bVar1 << 0xc;
        }
        cVar14 = '\x01';
      } while (bVar19 != 2);
      bVar19 = *(byte *)((int)__s + 0x8e);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar13 + 0x1c + iVar6) = (ushort)bVar19 * 0x7e + 0x1400;
      if ((*(ushort *)((int)__s + 0x84) & 1) == 0) {
        uVar10 = *(uint *)(param_2 + 0x10);
        uVar11 = 0;
        *(undefined2 *)((int)__s + 0x6e) = 0;
        *(uint *)((int)__s + 0x50) = uVar10;
        uVar12 = uVar10;
      }
      else {
        bVar19 = *(byte *)((int)param_2 + 0x25);
        uVar10 = *(uint *)(param_2 + 0xe);
        uVar12 = uVar10;
        for (uVar11 = *(short *)(&connect_req_dur_tab + (uint)bVar19 * 2) * 2 + param_2[0xc];
            0x270 < uVar11; uVar11 = uVar11 - 0x271) {
          uVar12 = uVar12 + 1 & 0xfffffff;
        }
        cVar14 = *(char *)((int)param_2 + 0x27);
        *(uint *)((int)__s + 0x50) = uVar10;
        *(ushort *)((int)__s + 0x6e) = uVar11;
        iVar6 = 4;
        if (cVar14 != '\0') {
          iVar6 = (uint)(1 < bVar19) * 4 + 8;
        }
        uVar12 = (uint)(*(ushort *)((int)__s + 0x70) >> 1) + *(int *)((int)__s + 0x60) + uVar12 +
                 iVar6 & 0xfffffff;
      }
      *(uint *)((int)__s + 0x54) = uVar10;
      *(uint *)((int)__s + 0x58) = uVar10;
      *(uint *)((int)__s + 0x48) = uVar12;
      if ((*(ushort *)((int)__s + 0x84) & 1) == 0) {
        uVar12 = (uint)DAT_00016066;
        *(undefined2 *)((int)__s + 0x6c) = 0;
        iVar13 = 0;
        iVar6 = uVar12 << 1;
      }
      else {
        iVar13 = (int)(short)uVar11;
        iVar6 = (uint)*(ushort *)((int)__s + 0x70) * 0x271;
        *(ushort *)((int)__s + 0x6c) = uVar11;
      }
      *(int *)((int)__s + 0x4c) = iVar6;
      *(int *)((int)__s + 8) = iVar13;
      r_lld_con_sched(param_1,uVar5,0);
      r_sch_slice_per_add(4,*(undefined1 *)((int)__s + 0x8e),*(undefined4 *)((int)__s + 100),
                          *(undefined2 *)((int)__s + 0x10),0);
      return 0;
    }
    r_assert_err("lld_con.c",0xe28);
  }
  return 0xc;
}

