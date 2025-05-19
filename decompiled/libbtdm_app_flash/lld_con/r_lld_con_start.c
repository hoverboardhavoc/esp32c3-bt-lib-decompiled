/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
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
  void *__s;
  undefined4 uVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  undefined2 uVar7;
  ushort uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  char cVar12;
  uint uVar13;
  uint *puVar14;
  int iVar15;
  ushort uVar16;
  char cVar17;
  byte bVar18;
  byte bStack_42;
  byte abStack_41 [13];
  
  if (*(int *)(&lld_con_env + param_1 * 4) == 0) {
    __s = (void *)r_ke_malloc(0x9c,0);
    *(void **)(&lld_con_env + param_1 * 4) = __s;
    if (__s != (void *)0x0) {
      uVar3 = r_lld_read_clock();
      bStack_42 = 0;
      abStack_41[0] = 0;
      memset(__s,0,0x9c);
      *(code **)((int)__s + 0x20) = r_lld_con_evt_canceled_cbk_eco;
      *(code **)((int)__s + 0x18) = r_lld_con_evt_start_cbk_eco;
      uVar2 = rwip_priority;
      *(char *)((int)__s + 0x8e) = (char)param_1;
      *(undefined1 *)((int)__s + 0x16) = uVar2;
      *(undefined2 *)((int)__s + 0x14) = 0x2000;
      if ((*(byte *)(param_2 + 0x12) & 0xfe) != 0) {
        r_assert_param(1,"lld_con.c",0xd53);
      }
      bVar18 = *(byte *)(param_2 + 0x12);
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
      *(ushort *)((int)__s + 0x84) = *(ushort *)((int)__s + 0x84) & 0xfbfe | (ushort)bVar18 | 0x10;
      *(undefined2 *)((int)__s + 0x86) = 0x1b;
      *(undefined4 *)((int)__s + 0x24) = 0;
      *(undefined4 *)((int)__s + 0x30) = 0;
      *(undefined4 *)((int)__s + 0x7c) = 0;
      *(undefined4 *)((int)__s + 0x80) = 0;
      cVar12 = *(char *)((int)param_2 + 0x25);
      if ((byte)(cVar12 - 2U) < 2) {
        uVar7 = 0xa90;
      }
      else {
        uVar7 = 0x148;
      }
      *(undefined2 *)((int)__s + 0x88) = uVar7;
      *(undefined2 *)((int)__s + 0x8a) = uVar7;
      *(undefined1 *)((int)__s + 0x8c) = 0x1b;
      *(char *)((int)__s + 0x93) = cVar12;
      *(char *)((int)__s + 0x94) = cVar12;
      *(undefined1 *)((int)__s + 0x95) = 0;
      if ((bVar18 & 1) != 0) {
        r_lld_con_max_lat_calc(*(undefined1 *)((int)__s + 0x8e));
      }
      uVar16 = (*(char *)(param_2 + 0x12) != '\0') + 2;
      r_bt_rma_get_ant_by_act(uVar16,param_1,&bStack_42,abStack_41);
      uVar9 = (uint)rwip_coex_cfg;
      uVar10 = (uint)bStack_42;
      uVar13 = (uint)abStack_41[0];
      if ((uVar10 << 7 & 0xffffff7f) != 0) {
        r_assert_err(0,"lld_con.c",0x42);
      }
      if ((uVar13 << 6 & 0xffffffbf) != 0) {
        r_assert_err(0,"lld_con.c",0x43);
      }
      iVar11 = param_1 * 0x5a;
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar4 + iVar11) =
           (ushort)(uVar10 << 7) | (ushort)(uVar13 << 6) | (ushort)((uVar9 & 1) << 10) |
           (ushort)((uVar9 & 2) << 8) | (ushort)((uVar9 & 4) << 6) | uVar16;
      uVar10 = (uint)*(byte *)((int)param_2 + 0x25);
      uVar9 = uVar10;
      if ((DAT_0001608f != '\0') && ((uVar10 - 2 & 0xff) < 2)) {
        uVar9 = *(byte *)(_p_lld_env + 0xda) + 2 & 0xff;
      }
      if ((uVar10 << 2 & 0xfffffff3) != 0) {
        r_assert_err(0,"lld_con.c",399);
      }
      if ((uVar9 & 0xfffffffc) != 0) {
        r_assert_err(0,"lld_con.c",400);
      }
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar11 + 4 + iVar4) = (ushort)(uVar10 << 2) | (ushort)uVar9 | 0x1100;
      if ((param_1 & 0xffffffe0) != 0) {
        r_assert_err(0,"lld_con.c",0xe6);
      }
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar4 + iVar11 + 2) = (ushort)param_1 | 0x800;
      uVar7 = *param_2;
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar11 + 0xc + iVar4) = uVar7;
      uVar7 = param_2[1];
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar11 + 0xe + iVar4) = uVar7;
      uVar7 = param_2[2];
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar11 + 0x10 + iVar4) = uVar7;
      bVar18 = *(byte *)(param_2 + 3);
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar11 + 0x12 + iVar4) = (ushort)bVar18;
      bVar18 = *(byte *)((int)__s + 0x8d);
      bVar1 = *(byte *)(param_2 + 0x13);
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar11 + 0x16 + iVar4) =
           (ushort)((bVar18 & 0x1f) << 8) | (ushort)bVar1 << 0xe | 0x8000;
      *(ushort *)((int)__s + 0x84) =
           (ushort)((*(byte *)(param_2 + 0x13) ^ 1) << 9) | *(ushort *)((int)__s + 0x84) & 0xfdff;
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar11 + 0x18 + iVar4) = 0;
      r_lld_con_set_tx_power(param_1,uVar16);
      r_lld_con_evt_time_update_eco(param_1);
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar11 + 0x28 + iVar4) = 0xfb;
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar11 + 0x2a + iVar4) = 0;
      bVar18 = DAT_00016066;
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar11 + 0x1a + iVar4) = (ushort)bVar18;
      uVar7 = param_2[8];
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar11 + 0x22 + iVar4) = uVar7;
      uVar7 = param_2[9];
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar11 + 0x24 + iVar4) = uVar7;
      uVar7 = param_2[10];
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar11 + 0x26 + iVar4) = uVar7;
      pbVar5 = (byte *)r_bt_rf_coex_st_param_get(*(char *)(param_2 + 0x12) != '\0');
      if (pbVar5 != (byte *)0x0) {
        bVar18 = pbVar5[1];
        if (0xb < param_1) {
          r_assert_err(0,"lld_con.c",0x299b);
        }
        if (((uint)bVar18 << 8 & 0xf000) != 0) {
          r_assert_err(0,"lld_con.c",0x299d);
        }
        puVar14 = (uint *)((param_1 + 0x1800c4cb) * 4);
        *puVar14 = *puVar14 & 0xfffff0ff | (uint)bVar18 << 8;
        bVar18 = *pbVar5;
        if (0xb < param_1) {
          r_assert_err(0,"lld_con.c",0x294a);
        }
        *puVar14 = (uint)bVar18 << 0x1e | *puVar14 & 0xbfffffff;
        bVar18 = pbVar5[3];
        if (0xb < param_1) {
          r_assert_err(0,"lld_con.c",0x29bb);
        }
        if ((bVar18 & 0xf0) != 0) {
          r_assert_err(0,"lld_con.c",0x29bd);
        }
        *puVar14 = *puVar14 & 0xfffffff0 | (uint)bVar18;
        bVar18 = pbVar5[2];
        if (0xb < param_1) {
          r_assert_err(0,"lld_con.c",0x295a);
        }
        *puVar14 = (uint)bVar18 << 0x1d | *puVar14 & 0xdfffffff;
        bVar18 = pbVar5[7];
        if (0xb < param_1) {
          r_assert_err(0,"lld_con.c",0x298b);
        }
        if (((uint)bVar18 << 0xc & 0xf0000) != 0) {
          r_assert_err(0,"lld_con.c",0x298d);
        }
        *puVar14 = *puVar14 & 0xffff0fff | (uint)bVar18 << 0xc;
        bVar18 = pbVar5[8];
        if (0xb < param_1) {
          r_assert_err(0,"lld_con.c",0x29ab);
        }
        if (((uint)bVar18 << 4 & 0xffffff0f) != 0) {
          r_assert_err(0,"lld_con.c",0x29ad);
        }
        *puVar14 = *puVar14 & 0xffffff0f | (uint)bVar18 << 4;
        bVar18 = pbVar5[9];
        if (0xb < param_1) {
          r_assert_err(0,"lld_con.c",0x297b);
        }
        if (((uint)bVar18 << 0x10 & 0xf00000) != 0) {
          r_assert_err(0,"lld_con.c",0x297d);
        }
        *puVar14 = *puVar14 & 0xfff0ffff | (uint)bVar18 << 0x10;
        uVar16 = *(ushort *)(pbVar5 + 10);
        if (0xb < param_1) {
          r_assert_err(0,"lld_con.c",0x296a);
        }
        if (((uint)uVar16 << 0x14 & 0xe0000000) != 0) {
          r_assert_err(0,"lld_con.c",0x296c);
        }
        *puVar14 = *puVar14 & 0xe00fffff | (uint)uVar16 << 0x14;
        bVar18 = pbVar5[6];
        if (0xb < param_1) {
          r_assert_err(0,"lld_con.c",0x293a);
        }
        *puVar14 = *puVar14 & 0x7fffffff | (uint)bVar18 << 0x1f;
        if (2 < _g_bt_plf_log_level) {
          ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[CON[%d]] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                     ,param_1,puVar14,*(undefined1 *)(param_2 + 0x12),pbVar5[2],pbVar5[3],*pbVar5,
                     pbVar5[1]);
        }
      }
      cVar12 = '\0';
      do {
        cVar17 = *(char *)((int)__s + 0x8e) * '\t';
        bVar18 = cVar12 + 1;
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar15 = (uint)(byte)(cVar12 + cVar17) * 0xe;
        *(ushort *)(iVar4 + iVar15) = (ushort)(byte)((bVar18 & 1) + cVar17) * 0xe + 0x1400 | 0x8000;
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        *(undefined2 *)(iVar4 + 2 + iVar15) = 0;
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        *(undefined2 *)(iVar4 + 4 + iVar15) = 0;
        iVar4 = r_bt_rf_coex_st_param_get(*(char *)(param_2 + 0x12) != '\0');
        if (iVar4 != 0) {
          if (2 < _g_bt_plf_log_level) {
            ets_printf("TX PTI [CON] [EN%d] [%d] \n",*(undefined1 *)(iVar4 + 4),
                       *(undefined1 *)(iVar4 + 5));
          }
          uVar9 = (uint)*(byte *)(iVar4 + 5) << 8;
          if ((uVar9 & 0xfffff0ff) != 0) {
            r_assert_err(0,"lld_con.c",0x33f);
          }
          iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
          iVar15 = iVar15 + 10;
          uVar16 = *(ushort *)(iVar6 + iVar15);
          iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
          *(ushort *)(iVar6 + iVar15) = uVar16 & 0xf0ff | (ushort)uVar9;
          bVar1 = *(byte *)(iVar4 + 4);
          iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
          uVar16 = *(ushort *)(iVar4 + iVar15);
          iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
          *(ushort *)(iVar4 + iVar15) = uVar16 & 0xefff | (ushort)bVar1 << 0xc;
        }
        cVar12 = '\x01';
      } while (bVar18 != 2);
      bVar18 = *(byte *)((int)__s + 0x8e);
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar11 + 0x1c + iVar4) = (ushort)bVar18 * 0x7e + 0x1400;
      uVar16 = *(ushort *)((int)__s + 0x84);
      if ((uVar16 & 1) == 0) {
        uVar9 = *(uint *)(param_2 + 0x10);
        uVar8 = 0;
        *(undefined2 *)((int)__s + 0x6e) = 0;
        *(uint *)((int)__s + 0x50) = uVar9;
      }
      else {
        bVar18 = *(byte *)((int)param_2 + 0x25);
        uVar9 = *(uint *)(param_2 + 0xe);
        for (uVar8 = *(short *)(&connect_req_dur_tab + (uint)bVar18 * 2) * 2 + param_2[0xc];
            0x270 < uVar8; uVar8 = uVar8 - 0x271) {
          uVar9 = uVar9 + 1 & 0xfffffff;
        }
        cVar12 = *(char *)((int)param_2 + 0x27);
        *(uint *)((int)__s + 0x50) = *(uint *)(param_2 + 0xe);
        *(ushort *)((int)__s + 0x6e) = uVar8;
        iVar4 = 4;
        if ((cVar12 != '\0') && (iVar4 = 8, 1 < bVar18)) {
          iVar4 = 0xc;
        }
        uVar9 = (uint)(*(ushort *)((int)__s + 0x70) >> 1) + *(int *)((int)__s + 0x60) + uVar9 +
                iVar4 & 0xfffffff;
      }
      *(uint *)((int)__s + 0x48) = uVar9;
      *(undefined4 *)((int)__s + 0x54) = *(undefined4 *)((int)__s + 0x50);
      *(undefined4 *)((int)__s + 0x58) = *(undefined4 *)((int)__s + 0x50);
      if ((uVar16 & 1) == 0) {
        uVar8 = 0;
      }
      iVar4 = (int)(short)uVar8;
      *(ushort *)((int)__s + 0x6c) = uVar8;
      if ((uVar16 & 1) == 0) {
        iVar11 = (uint)DAT_00016066 << 1;
      }
      else {
        iVar11 = (uint)*(ushort *)((int)__s + 0x70) * 0x271;
      }
      *(int *)((int)__s + 0x4c) = iVar11;
      if ((uVar16 & 1) == 0) {
        iVar4 = 0;
      }
      *(int *)((int)__s + 8) = iVar4;
      r_lld_con_sched_hack(param_1,uVar3,0);
      r_sch_slice_per_add(4,*(undefined1 *)((int)__s + 0x8e),*(undefined4 *)((int)__s + 100),
                          *(undefined2 *)((int)__s + 0x10),0);
      return 0;
    }
    r_assert_err("lld_con.c",0xe28);
  }
  return 0xc;
}

