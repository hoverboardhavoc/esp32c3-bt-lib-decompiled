/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_start
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
  byte *unaff_s0;
  char cVar9;
  int *piVar10;
  uint uVar11;
  void *pvVar12;
  int iVar13;
  undefined4 uVar14;
  ushort uVar15;
  bool bVar16;
  ushort uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  uint *puVar21;
  int iVar22;
  short sVar23;
  int *piVar24;
  byte bStack_49;
  byte abStack_48 [20];
  
  if (_lld_scan_env != (int *)0x0) {
    return 0xc;
  }
  piVar10 = (int *)r_ke_malloc(0x20,0);
  _lld_scan_env = piVar10;
  if (piVar10 == (int *)0x0) {
    r_assert_err("lld_scan.c",0xcad);
    return 0xc;
  }
  uVar11 = r_lld_read_clock();
  memset(_lld_scan_env,0,0x20);
  if ((*(byte *)((int)param_2 + 7) & 1) != 0) {
    pvVar12 = (void *)r_ke_malloc(0x84,0);
    *piVar10 = (int)pvVar12;
    if (pvVar12 != (void *)0x0) {
      memset(pvVar12,0,0x84);
      *(code **)((int)pvVar12 + 0x20) = r_lld_scan_evt_canceled_cbk;
      *(code **)((int)pvVar12 + 0x18) = r_lld_scan_evt_start_cbk_eco;
      *(undefined1 *)((int)pvVar12 + 0x16) = rwip_priority;
      uVar17 = param_2[6];
      uVar18 = (uint)uVar17 * 0x4e2;
      if (_sch_slice_params < uVar18) {
        uVar18 = (uint)_sch_slice_params;
      }
      *(uint *)((int)pvVar12 + 0x10) = uVar18;
      *(ushort *)((int)pvVar12 + 0x14) = DAT_0001507d & 0xf | 0x6000;
      uVar5 = param_2[4];
      *(ushort *)((int)pvVar12 + 0x32) = uVar17;
      *(undefined2 *)((int)pvVar12 + 0x30) = uVar5;
      cVar9 = *(char *)(param_2 + 8);
      *(uint *)((int)pvVar12 + 0x24) = (uint)uVar17;
      *(char *)((int)pvVar12 + 0x38) = param_1;
      *(char *)((int)pvVar12 + 0x39) = cVar9;
      bVar6 = cVar9 == '\x01';
      *(byte *)(piVar10 + 3) = *(byte *)(piVar10 + 3) | 1;
      goto _L799;
    }
    r_assert_err("lld_scan.c",0xb75);
  }
  bVar6 = false;
_L799:
  if ((*(byte *)((int)param_2 + 7) & 4) != 0) {
    pvVar12 = (void *)r_ke_malloc(0x84,0);
    piVar10[1] = (int)pvVar12;
    if (pvVar12 == (void *)0x0) {
      r_assert_err("lld_scan.c",0xba1);
    }
    else {
      memset(pvVar12,0,0x84);
      *(code **)((int)pvVar12 + 0x20) = r_lld_scan_evt_canceled_cbk;
      *(code **)((int)pvVar12 + 0x18) = r_lld_scan_evt_start_cbk_eco;
      *(undefined1 *)((int)pvVar12 + 0x16) = rwip_priority;
      uVar17 = param_2[7];
      uVar18 = (uint)uVar17 * 0x4e2;
      if (_sch_slice_params < uVar18) {
        uVar18 = (uint)_sch_slice_params;
      }
      *(uint *)((int)pvVar12 + 0x10) = uVar18;
      *(ushort *)((int)pvVar12 + 0x14) = DAT_0001507d & 0xf | 0x6000;
      uVar5 = param_2[5];
      *(ushort *)((int)pvVar12 + 0x32) = uVar17;
      *(undefined2 *)((int)pvVar12 + 0x30) = uVar5;
      cVar9 = *(char *)((int)param_2 + 0x11);
      *(undefined1 *)((int)pvVar12 + 0x3b) = 3;
      *(char *)((int)pvVar12 + 0x39) = cVar9;
      *(undefined1 *)((int)pvVar12 + 0x40) = 1;
      *(uint *)((int)pvVar12 + 0x24) = (uint)uVar17;
      *(undefined1 *)((int)pvVar12 + 0x38) = 0xb;
      bVar6 = (bool)(bVar6 | cVar9 == '\x01');
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
    uVar18 = (uint)(ushort)param_2[0xb] * 0x20 + uVar11 & 0xfffffff;
  }
  piVar10[2] = uVar18;
  piVar24 = piVar10;
  do {
    abStack_48[0] = 0;
    iVar22 = *piVar24;
    bStack_49 = 0;
    if (iVar22 != 0) {
      uVar1 = *(undefined1 *)(param_2 + 3);
      bVar2 = *(byte *)(iVar22 + 0x38);
      uVar18 = (uint)bVar2;
      *(undefined1 *)(iVar22 + 0x3d) = 0;
      *(undefined1 *)(iVar22 + 0x42) = uVar1;
      *(undefined1 *)(iVar22 + 0x3f) = 9;
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      iVar20 = uVar18 * 0x5a;
      *(undefined2 *)(iVar20 + 0xc + iVar13) = 0xbed6;
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar20 + 0xe + iVar13) = 0x8e89;
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar20 + 0x10 + iVar13) = 0x5555;
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar20 + 0x12 + iVar13) = 0x55;
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar20 + 0x46 + iVar13) = 0;
      if (_lld_scan_sync_env == 0) {
        bVar16 = false;
        uVar19 = 0;
      }
      else {
        bVar16 = *(char *)(_lld_scan_sync_env + 1) != '\0';
        uVar19 = (uint)bVar16;
      }
      *(bool *)(iVar22 + 0x44) = bVar16;
      uVar17 = param_2[9];
      bVar3 = *(byte *)((int)piVar10 + 0x15);
      bVar4 = *(byte *)(param_2 + 10);
      uVar15 = 1;
      if (*(char *)((int)piVar10 + 0x16) == '\0') {
        uVar15 = (ushort)((uint)piVar10[5] >> 1) & 1;
      }
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar20 + 0x14 + iVar13) =
           (ushort)bVar4 << 6 | (ushort)((uVar17 >> 1 & 1) << 2) | (ushort)bVar3 << 8 |
           (ushort)(uVar19 << 3) | uVar15;
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar20 + 0x16 + iVar13) = 0x8027;
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar20 + 0x28 + iVar13) = 0;
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar20 + 0x2a + iVar13) = 0;
      uVar17 = _sdk_cfg_priv_opts;
      bVar3 = *(byte *)(param_2 + 9);
      if (0x1f < uVar18) {
        r_assert_err(0,"lld_scan.c",0xe6);
      }
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar20 + 2 + iVar13) =
           (uVar17 & 0xff) << 5 | (ushort)bVar2 | (ushort)((bVar3 & 1) << 7) | 0x800;
      uVar5 = *param_2;
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar20 + 6 + iVar13) = uVar5;
      uVar5 = param_2[1];
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar20 + 8 + iVar13) = uVar5;
      uVar5 = param_2[2];
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar20 + 10 + iVar13) = uVar5;
      if (*(char *)(iVar22 + 0x39) == '\x01') {
        sVar23 = (ushort)(byte)(param_1 * '\t') * 0xe + 0x1400;
        iVar13 = r_emi_get_mem_addr_by_offset(0x400);
        *(short *)(iVar13 + iVar20 + 0x1c) = sVar23;
        iVar13 = r_emi_get_mem_addr_by_offset(0x400);
        *(short *)(iVar13 + iVar20 + 0x34) = sVar23;
        cVar9 = (-(*(char *)(iVar22 + 0x42) == '\0') & 0xfeU) + 0xb;
      }
      else {
        iVar13 = r_emi_get_mem_addr_by_offset(0x400);
        *(undefined2 *)(iVar13 + iVar20 + 0x1c) = 0;
        iVar13 = r_emi_get_mem_addr_by_offset(0x400);
        *(undefined2 *)(iVar13 + iVar20 + 0x34) = 0;
        cVar9 = (-(*(char *)(iVar22 + 0x42) == '\0') & 0xfeU) + 10;
      }
      *(char *)(iVar22 + 0x3a) = cVar9;
      r_bt_rma_get_ant_by_act(uVar18,&bStack_49,abStack_48);
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar20 + 0x18 + iVar13) = 0;
      r_lld_scan_set_tx_power(uVar18,*(undefined1 *)(iVar22 + 0x3a));
      bVar8 = abStack_48[0];
      bVar7 = bStack_49;
      uVar19 = (uint)rwip_coex_cfg;
      bVar3 = rwip_coex_cfg >> 1;
      bVar4 = rwip_coex_cfg >> 2;
      bVar2 = *(byte *)(iVar22 + 0x3a);
      if ((bStack_49 & 0xfe) != 0) {
        r_assert_err(0,"lld_scan.c",0x42);
      }
      if ((bVar8 & 0xfe) != 0) {
        r_assert_err(0,"lld_scan.c",0x43);
      }
      if (0x1f < bVar2) {
        r_assert_err(0,"lld_scan.c",0x45);
      }
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar13 + iVar20) =
           (ushort)bVar7 << 7 | (ushort)bVar8 << 6 | (ushort)bVar2 | (ushort)((uVar19 & 1) << 10) |
           (ushort)((bVar3 & 1) << 9) | (ushort)((bVar4 & 1) << 8) | 0x20;
      bVar2 = *(byte *)(iVar22 + 0x3b);
      if ((bVar2 & 0xfc) == 0) {
        if (3 < bVar2) goto _L817;
      }
      else {
        r_assert_err(0,"lld_scan.c",399);
_L817:
        r_assert_err(0,"lld_scan.c",400);
      }
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar20 + 4 + iVar13) =
           (ushort)bVar2 | (ushort)((int)(short)(ushort)bVar2 << 2) | 0x1000;
      if (g_scan_forever == '\0') {
        uVar5 = *(undefined2 *)(iVar22 + 0x24);
        iVar13 = r_emi_get_mem_addr_by_offset(0x400);
        uVar19 = *(uint *)(iVar22 + 0x24);
        *(undefined2 *)(iVar13 + iVar20 + 0x20) = uVar5;
        if (0x3fff < uVar19) {
          uVar19 = 0x3fff;
        }
        iVar13 = r_emi_get_mem_addr_by_offset(0x400);
        uVar17 = (ushort)uVar19 | 0x8000;
      }
      else {
        iVar13 = r_emi_get_mem_addr_by_offset(0x400);
        *(undefined2 *)(iVar13 + iVar20 + 0x20) = 0;
        iVar13 = r_emi_get_mem_addr_by_offset(0x400);
        uVar17 = 0xbfff;
      }
      *(ushort *)(iVar13 + iVar20 + 0x1a) = uVar17;
      bVar2 = *(byte *)(iVar22 + 0x3a);
      if (bVar2 == 10) {
        uVar14 = 7;
_L909:
        unaff_s0 = (byte *)r_bt_rf_coex_st_param_get(uVar14);
      }
      else {
        if (bVar2 < 0xb) {
          if (bVar2 == 8) {
            uVar14 = 5;
          }
          else {
            uVar14 = 6;
            if (bVar2 != 9) goto _L826;
          }
          goto _L909;
        }
        uVar14 = 8;
        if (bVar2 == 0xb) goto _L909;
_L826:
        r_assert_err(0,"lld_scan.c",0xc4f);
      }
      if (unaff_s0 != (byte *)0x0) {
        bVar2 = unaff_s0[1];
        if (0xb < uVar18) {
          r_assert_err(0,"lld_scan.c",0x299b);
        }
        if ((bVar2 & 0xf0) != 0) {
          r_assert_err(0,"lld_scan.c",0x299d);
        }
        puVar21 = (uint *)((uVar18 + 0x1800c4cb) * 4);
        *puVar21 = *puVar21 & 0xfffff0ff | (uint)bVar2 << 8;
        bVar2 = *unaff_s0;
        if (0xb < uVar18) {
          r_assert_err(0,"lld_scan.c",0x294a);
        }
        *puVar21 = *puVar21 & 0xbfffffff | (uint)bVar2 << 0x1e;
        bVar2 = unaff_s0[3];
        if (0xb < uVar18) {
          r_assert_err(0,"lld_scan.c",0x29bb);
        }
        if (0xf < bVar2) {
          r_assert_err(0,"lld_scan.c",0x29bd);
        }
        *puVar21 = *puVar21 & 0xfffffff0 | (uint)bVar2;
        bVar2 = unaff_s0[2];
        if (0xb < uVar18) {
          r_assert_err(0,"lld_scan.c",0x295a);
        }
        *puVar21 = *puVar21 & 0xdfffffff | (uint)bVar2 << 0x1d;
        bVar2 = unaff_s0[7];
        if (0xb < uVar18) {
          r_assert_err(0,"lld_scan.c",0x298b);
        }
        if ((bVar2 & 0xf0) != 0) {
          r_assert_err(0,"lld_scan.c",0x298d);
        }
        *puVar21 = *puVar21 & 0xffff0fff | (uint)bVar2 << 0xc;
        bVar2 = unaff_s0[8];
        if (0xb < uVar18) {
          r_assert_err(0,"lld_scan.c",0x29ab);
        }
        if ((bVar2 & 0xf0) != 0) {
          r_assert_err(0,"lld_scan.c",0x29ad);
        }
        *puVar21 = *puVar21 & 0xffffff0f | (uint)bVar2 << 4;
        bVar2 = unaff_s0[9];
        if (0xb < uVar18) {
          r_assert_err(0,"lld_scan.c",0x297b);
        }
        if ((bVar2 & 0xf0) != 0) {
          r_assert_err(0,"lld_scan.c",0x297d);
        }
        *puVar21 = *puVar21 & 0xfff0ffff | (uint)bVar2 << 0x10;
        uVar17 = *(ushort *)(unaff_s0 + 10);
        if (0xb < uVar18) {
          r_assert_err(0,"lld_scan.c",0x296a);
        }
        if ((uVar17 >> 9 & 7) != 0) {
          r_assert_err(0,"lld_scan.c",0x296c);
        }
        *puVar21 = *puVar21 & 0xe00fffff | (uint)uVar17 << 0x14;
        bVar2 = unaff_s0[6];
        if (0xb < uVar18) {
          r_assert_err(0,"lld_scan.c",0x293a);
        }
        *puVar21 = *puVar21 & 0x7fffffff | (uint)bVar2 << 0x1f;
        if (2 < _g_bt_plf_log_level) {
          ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[SCAN[%d]] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                     ,uVar18,puVar21,*(undefined1 *)(iVar22 + 0x3a),unaff_s0[2],unaff_s0[3],
                     *unaff_s0,unaff_s0[1]);
        }
      }
    }
    piVar24 = piVar24 + 1;
    if (piVar10 + 2 == piVar24) {
      if (bVar6) {
        iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar22 = (uint)(byte)(param_1 * '\t') * 0xe;
        iVar20 = iVar22 + 2;
        uVar17 = *(ushort *)(iVar13 + iVar20);
        iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar13 + iVar20) = uVar17 & 0xfff0 | 3;
        iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
        *(undefined2 *)(iVar22 + 4 + iVar13) = 0;
        iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar17 = *(ushort *)(iVar13 + iVar20);
        iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar20 + iVar13) = uVar17 & 0xff | 0xc00;
        iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar17 = *(ushort *)(iVar13 + iVar22);
        iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar13 + iVar22) = uVar17 & 0x8000;
        iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar17 = *(ushort *)(iVar13 + iVar22);
        iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar13 + iVar22) = (ushort)(((uint)uVar17 << 0x11) >> 0x11);
        iVar13 = r_bt_rf_coex_st_param_get(6);
        if (iVar13 != 0) {
          if (2 < _g_bt_plf_log_level) {
            ets_printf("TX PTI [ACT_SCAN] [EN%d] [%d] \n",*(undefined1 *)(iVar13 + 4),
                       *(undefined1 *)(iVar13 + 5));
          }
          bVar2 = *(byte *)(iVar13 + 5);
          if ((bVar2 & 0xf0) != 0) {
            r_assert_err(0,"lld_scan.c",0x33f);
          }
          iVar20 = r_emi_get_mem_addr_by_offset(0x1400);
          iVar22 = iVar22 + 10;
          uVar17 = *(ushort *)(iVar20 + iVar22);
          iVar20 = r_emi_get_mem_addr_by_offset(0x1400);
          *(ushort *)(iVar20 + iVar22) = uVar17 & 0xf0ff | (ushort)bVar2 << 8;
          bVar2 = *(byte *)(iVar13 + 4);
          iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
          uVar17 = *(ushort *)(iVar13 + iVar22);
          iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
          *(ushort *)(iVar22 + iVar13) = uVar17 & 0xefff | (ushort)bVar2 << 0xc;
        }
      }
      _DAT_60031124 = 0x10001;
      uVar18 = (uint)_sdk_cfg_priv_opts;
      if (0x1ff < uVar18) {
        r_assert_err(0,"lld_scan.c",0x29ed);
      }
      _DAT_60031364 = _DAT_60031364 & 0xfffffe00 | uVar18;
      piVar24 = piVar10;
      do {
        iVar22 = *piVar24;
        if (iVar22 != 0) {
          *(uint *)(iVar22 + 4) = uVar11;
          *(uint *)(iVar22 + 0x28) = uVar11;
          iVar13 = r_sch_arb_insert(iVar22);
          if (iVar13 == 0) {
            *(undefined1 *)(iVar22 + 0x43) = 0;
            *(undefined2 *)(iVar22 + 0x36) = 0;
            uVar11 = (uint)*(ushort *)(iVar22 + 0x32) * 2 + uVar11 & 0xfffffff;
          }
          else {
            r_assert_err(0,"lld_scan.c",0xca1);
          }
        }
        piVar24 = piVar24 + 1;
      } while (piVar10 + 2 != piVar24);
      *(undefined1 *)((int)piVar10 + 0x17) = 0;
      iVar22 = r_rwip_time_get();
      piVar10[6] = iVar22;
      piVar10[7] = iVar22;
      return 0;
    }
  } while( true );
}

