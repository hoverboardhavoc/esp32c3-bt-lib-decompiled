/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_start
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
  undefined4 uVar15;
  ushort uVar16;
  uint uVar17;
  undefined1 uVar18;
  short sVar19;
  byte *unaff_s3;
  int iVar20;
  uint uVar21;
  uint uVar22;
  int *piVar23;
  uint uVar24;
  byte bStack_49;
  byte abStack_48 [20];
  
  if (_lld_scan_env == (int *)0x0) {
    piVar10 = (int *)r_ke_malloc(0x20,0);
    _lld_scan_env = piVar10;
    if (piVar10 != (int *)0x0) {
      uVar11 = r_lld_read_clock();
      bVar7 = false;
      memset(_lld_scan_env,0,0x20);
      if ((*(byte *)((int)param_2 + 7) & 1) != 0) {
        pvVar12 = (void *)r_ke_malloc(0x84,0);
        *piVar10 = (int)pvVar12;
        if (pvVar12 == (void *)0x0) {
          r_assert_err("lld_scan.c",0xb66);
        }
        else {
          memset(pvVar12,0,0x84);
          *(code **)((int)pvVar12 + 0x20) = r_lld_scan_evt_canceled_cbk;
          *(code **)((int)pvVar12 + 0x18) = r_lld_scan_evt_start_cbk_eco;
          uVar18 = rwip_priority;
          *(undefined4 *)((int)pvVar12 + 0x1c) = 0;
          *(undefined1 *)((int)pvVar12 + 0x16) = uVar18;
          bVar2 = DAT_0001507d;
          uVar16 = param_2[6];
          uVar17 = (uint)uVar16 * 0x4e2;
          if (_sch_slice_params < uVar17) {
            uVar17 = (uint)_sch_slice_params;
          }
          *(uint *)((int)pvVar12 + 0x10) = uVar17;
          *(ushort *)((int)pvVar12 + 0x14) = bVar2 & 0xf | 0x6000;
          uVar6 = param_2[4];
          *(ushort *)((int)pvVar12 + 0x32) = uVar16;
          *(undefined2 *)((int)pvVar12 + 0x30) = uVar6;
          cVar1 = *(char *)(param_2 + 8);
          *(undefined1 *)((int)pvVar12 + 0x3b) = 0;
          *(uint *)((int)pvVar12 + 0x24) = (uint)uVar16;
          *(char *)((int)pvVar12 + 0x39) = cVar1;
          *(undefined1 *)((int)pvVar12 + 0x40) = 0;
          *(char *)((int)pvVar12 + 0x38) = param_1;
          bVar7 = cVar1 == '\x01';
          *(byte *)(piVar10 + 3) = *(byte *)(piVar10 + 3) | 1;
        }
      }
      if ((*(byte *)((int)param_2 + 7) & 4) != 0) {
        pvVar12 = (void *)r_ke_malloc(0x84,0);
        piVar10[1] = (int)pvVar12;
        if (pvVar12 == (void *)0x0) {
          r_assert_err("lld_scan.c",0xb92);
        }
        else {
          memset(pvVar12,0,0x84);
          *(code **)((int)pvVar12 + 0x20) = r_lld_scan_evt_canceled_cbk;
          *(code **)((int)pvVar12 + 0x18) = r_lld_scan_evt_start_cbk_eco;
          uVar18 = rwip_priority;
          *(undefined4 *)((int)pvVar12 + 0x1c) = 0;
          *(undefined1 *)((int)pvVar12 + 0x16) = uVar18;
          bVar2 = DAT_0001507d;
          uVar16 = param_2[7];
          uVar17 = (uint)uVar16 * 0x4e2;
          if (_sch_slice_params < uVar17) {
            uVar17 = (uint)_sch_slice_params;
          }
          *(uint *)((int)pvVar12 + 0x10) = uVar17;
          *(ushort *)((int)pvVar12 + 0x14) = bVar2 & 0xf | 0x6000;
          uVar6 = param_2[5];
          *(ushort *)((int)pvVar12 + 0x32) = uVar16;
          *(undefined2 *)((int)pvVar12 + 0x30) = uVar6;
          cVar1 = *(char *)((int)param_2 + 0x11);
          *(undefined1 *)((int)pvVar12 + 0x3b) = 3;
          *(char *)((int)pvVar12 + 0x39) = cVar1;
          *(undefined1 *)((int)pvVar12 + 0x40) = 1;
          *(uint *)((int)pvVar12 + 0x24) = (uint)uVar16;
          *(undefined1 *)((int)pvVar12 + 0x3c) = 0;
          *(undefined1 *)((int)pvVar12 + 0x38) = 0xb;
          bVar7 = (bool)(bVar7 | cVar1 == '\x01');
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
      piVar23 = piVar10;
      do {
        bStack_49 = 0;
        abStack_48[0] = 0;
        iVar20 = *piVar23;
        if (iVar20 != 0) {
          bVar2 = *(byte *)(iVar20 + 0x38);
          uVar21 = (uint)bVar2;
          uVar18 = *(undefined1 *)(param_2 + 3);
          iVar8 = uVar21 * 0x5a;
          *(undefined1 *)(iVar20 + 0x3d) = 0;
          *(undefined1 *)(iVar20 + 0x42) = uVar18;
          *(undefined1 *)(iVar20 + 0x3f) = 9;
          iVar13 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar13 + iVar8 + 0xc) = 0xbed6;
          iVar13 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar13 + iVar8 + 0xe) = 0x8e89;
          iVar13 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar13 + iVar8 + 0x10) = 0x5555;
          iVar13 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar13 + iVar8 + 0x12) = 0x55;
          iVar14 = r_emi_get_mem_addr_by_offset(0x400);
          iVar13 = _lld_scan_sync_env;
          *(undefined2 *)(iVar14 + iVar8 + 0x46) = 0;
          uVar17 = 0;
          if (iVar13 != 0) {
            uVar17 = (uint)(*(char *)(iVar13 + 1) != '\0');
          }
          *(char *)(iVar20 + 0x44) = (char)uVar17;
          bVar3 = *(byte *)(param_2 + 9);
          bVar4 = *(byte *)((int)piVar10 + 0x15);
          bVar5 = *(byte *)(param_2 + 10);
          uVar16 = 1;
          if (*(char *)((int)piVar10 + 0x16) == '\0') {
            uVar16 = *(byte *)(piVar10 + 5) >> 1 & 1;
          }
          iVar13 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar13 + iVar8 + 0x14) =
               (ushort)bVar5 << 6 | (ushort)((bVar3 >> 1 & 1) << 2) | (ushort)bVar4 << 8 |
               (ushort)(uVar17 << 3) | uVar16;
          iVar13 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar13 + iVar8 + 0x16) = 0x8027;
          iVar13 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar13 + iVar8 + 0x28) = 0;
          iVar13 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar13 + iVar8 + 0x2a) = 0;
          bVar3 = *(byte *)(param_2 + 9);
          uVar16 = (ushort)DAT_0001508e;
          if ((bVar2 & 0xe0) != 0) {
            r_assert_err(0,"lld_scan.c",0xe6);
          }
          iVar13 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar13 + iVar8 + 2) =
               uVar16 << 5 | (ushort)bVar2 | (ushort)((bVar3 & 1) << 7) | 0x800;
          uVar6 = *param_2;
          iVar13 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar13 + iVar8 + 6) = uVar6;
          uVar6 = param_2[1];
          iVar13 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar13 + iVar8 + 8) = uVar6;
          uVar6 = param_2[2];
          iVar13 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar13 + iVar8 + 10) = uVar6;
          if (*(char *)(iVar20 + 0x39) == '\x01') {
            iVar13 = r_emi_get_mem_addr_by_offset();
            *(short *)(iVar13 + iVar8 + 0x1c) = sVar19;
            iVar13 = r_emi_get_mem_addr_by_offset(0x400);
            cVar1 = *(char *)(iVar20 + 0x42);
            *(short *)(iVar13 + iVar8 + 0x34) = sVar19;
            uVar18 = 0xb;
            if (cVar1 == '\0') {
              uVar18 = 9;
            }
          }
          else {
            iVar13 = r_emi_get_mem_addr_by_offset(0x400);
            *(undefined2 *)(iVar13 + iVar8 + 0x1c) = 0;
            iVar13 = r_emi_get_mem_addr_by_offset(0x400);
            cVar1 = *(char *)(iVar20 + 0x42);
            *(undefined2 *)(iVar13 + iVar8 + 0x34) = 0;
            uVar18 = 10;
            if (cVar1 == '\0') {
              uVar18 = 8;
            }
          }
          *(undefined1 *)(iVar20 + 0x3a) = uVar18;
          r_bt_rma_get_ant_by_act(*(undefined1 *)(iVar20 + 0x3a),uVar21,&bStack_49,abStack_48);
          iVar13 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar13 + iVar8 + 0x18) = 0;
          r_lld_scan_set_tx_power(uVar21,*(undefined1 *)(iVar20 + 0x3a));
          bVar2 = *(byte *)(iVar20 + 0x3a);
          uVar24 = (uint)abStack_48[0];
          uVar17 = (uint)DAT_000150bf;
          uVar22 = (uint)bStack_49;
          if ((uVar22 << 7 & 0xffffff7f) != 0) {
            r_assert_err(0,"lld_scan.c",0x42);
          }
          if ((uVar24 << 6 & 0xffffffbf) != 0) {
            r_assert_err(0,"lld_scan.c",0x43);
          }
          if ((bVar2 & 0xe0) != 0) {
            r_assert_err(0,"lld_scan.c",0x45);
          }
          iVar13 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar13 + iVar8) =
               (ushort)(uVar22 << 7) | (ushort)(uVar24 << 6) | (ushort)bVar2 |
               (ushort)((uVar17 & 1) << 10) | (ushort)((uVar17 & 2) << 8) |
               (ushort)((uVar17 & 4) << 6) | 0x20;
          bVar2 = *(byte *)(iVar20 + 0x3b);
          if (((uint)bVar2 << 2 & 0xfffffff3) != 0) {
            r_assert_err(0,"lld_scan.c",399);
          }
          if ((bVar2 & 0xfc) != 0) {
            r_assert_err(0,"lld_scan.c",400);
          }
          iVar13 = r_emi_get_mem_addr_by_offset(0x400);
          cVar1 = g_scan_forever;
          *(ushort *)(iVar13 + iVar8 + 4) = (ushort)((uint)bVar2 << 2) | (ushort)bVar2 | 0x1000;
          if (cVar1 == '\0') {
            uVar6 = *(undefined2 *)(iVar20 + 0x24);
            iVar13 = r_emi_get_mem_addr_by_offset(0x400);
            uVar17 = *(uint *)(iVar20 + 0x24);
            *(undefined2 *)(iVar13 + iVar8 + 0x20) = uVar6;
            if (0x3fff < uVar17) {
              uVar17 = 0x3fff;
            }
            iVar13 = r_emi_get_mem_addr_by_offset(0x400);
            *(ushort *)(iVar8 + 0x1a + iVar13) = (ushort)uVar17 | 0x8000;
          }
          else {
            iVar13 = r_emi_get_mem_addr_by_offset(0x400);
            *(undefined2 *)(iVar13 + iVar8 + 0x20) = 0;
            iVar13 = r_emi_get_mem_addr_by_offset(0x400);
            *(undefined2 *)(iVar8 + 0x1a + iVar13) = 0xbfff;
          }
          bVar2 = *(byte *)(iVar20 + 0x3a);
          if (bVar2 == 9) {
            uVar15 = 6;
_L942:
            unaff_s3 = (byte *)r_bt_rf_coex_st_param_get(uVar15);
          }
          else {
            if (9 < bVar2) {
              if (bVar2 == 10) {
                uVar15 = 7;
              }
              else {
                uVar15 = 8;
                if (bVar2 != 0xb) goto _L848;
              }
              goto _L942;
            }
            uVar15 = 5;
            if (bVar2 == 8) goto _L942;
_L848:
            r_assert_err(0,"lld_scan.c",0xc40);
          }
          if (unaff_s3 != (byte *)0x0) {
            bVar2 = unaff_s3[1];
            if (0xb < uVar21) {
              r_assert_err(0,"lld_scan.c",0x299b);
            }
            if (((uint)bVar2 << 8 & 0xf000) != 0) {
              r_assert_err(0,"lld_scan.c",0x299d);
            }
            puVar9 = (uint *)((uVar21 + 0x1800c4cb) * 4);
            *puVar9 = *puVar9 & 0xfffff0ff | (uint)bVar2 << 8;
            bVar2 = *unaff_s3;
            if (0xb < uVar21) {
              r_assert_err(0,"lld_scan.c",0x294a);
            }
            *puVar9 = (uint)bVar2 << 0x1e | *puVar9 & 0xbfffffff;
            bVar2 = unaff_s3[3];
            if (0xb < uVar21) {
              r_assert_err(0,"lld_scan.c",0x29bb);
            }
            if ((bVar2 & 0xf0) != 0) {
              r_assert_err(0,"lld_scan.c",0x29bd);
            }
            *puVar9 = *puVar9 & 0xfffffff0 | (uint)bVar2;
            bVar2 = unaff_s3[2];
            if (0xb < uVar21) {
              r_assert_err(0,"lld_scan.c",0x295a);
            }
            *puVar9 = (uint)bVar2 << 0x1d | *puVar9 & 0xdfffffff;
            bVar2 = unaff_s3[7];
            if (0xb < uVar21) {
              r_assert_err(0,"lld_scan.c",0x298b);
            }
            if (((uint)bVar2 << 0xc & 0xf0000) != 0) {
              r_assert_err(0,"lld_scan.c",0x298d);
            }
            *puVar9 = *puVar9 & 0xffff0fff | (uint)bVar2 << 0xc;
            bVar2 = unaff_s3[8];
            if (0xb < uVar21) {
              r_assert_err(0,"lld_scan.c",0x29ab);
            }
            if (((uint)bVar2 << 4 & 0xffffff0f) != 0) {
              r_assert_err(0,"lld_scan.c",0x29ad);
            }
            *puVar9 = *puVar9 & 0xffffff0f | (uint)bVar2 << 4;
            bVar2 = unaff_s3[9];
            if (0xb < uVar21) {
              r_assert_err(0,"lld_scan.c",0x297b);
            }
            if (((uint)bVar2 << 0x10 & 0xf00000) != 0) {
              r_assert_err(0,"lld_scan.c",0x297d);
            }
            *puVar9 = *puVar9 & 0xfff0ffff | (uint)bVar2 << 0x10;
            uVar16 = *(ushort *)(unaff_s3 + 10);
            if (0xb < uVar21) {
              r_assert_err(0,"lld_scan.c",0x296a);
            }
            if (((uint)uVar16 << 0x14 & 0xe0000000) != 0) {
              r_assert_err(0,"lld_scan.c",0x296c);
            }
            *puVar9 = *puVar9 & 0xe00fffff | (uint)uVar16 << 0x14;
            bVar2 = unaff_s3[6];
            if (0xb < uVar21) {
              r_assert_err(0,"lld_scan.c",0x293a);
            }
            *puVar9 = *puVar9 & 0x7fffffff | (uint)bVar2 << 0x1f;
            if (2 < _g_bt_plf_log_level) {
              ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[SCAN[%d]] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                         ,uVar21,puVar9,*(undefined1 *)(iVar20 + 0x3a),unaff_s3[2],unaff_s3[3],
                         *unaff_s3,unaff_s3[1]);
            }
          }
        }
        piVar23 = piVar23 + 1;
        if (piVar10 + 2 == piVar23) {
          if (bVar7) {
            iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
            iVar20 = (uint)(byte)(param_1 * '\t') * 0xe;
            iVar8 = iVar20 + 2;
            uVar16 = *(ushort *)(iVar13 + iVar8);
            iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
            *(ushort *)(iVar13 + iVar8) = uVar16 & 0xfff0 | 3;
            iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
            *(undefined2 *)(iVar13 + iVar20 + 4) = 0;
            iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
            uVar16 = *(ushort *)(iVar13 + iVar8);
            iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
            *(ushort *)(iVar13 + iVar8) = uVar16 & 0xff | 0xc00;
            iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
            uVar16 = *(ushort *)(iVar13 + iVar20);
            iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
            *(ushort *)(iVar13 + iVar20) = uVar16 & 0x8000;
            iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
            uVar16 = *(ushort *)(iVar13 + iVar20);
            iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
            *(ushort *)(iVar13 + iVar20) = uVar16 & 0x7fff;
            iVar13 = r_bt_rf_coex_st_param_get(6);
            if (iVar13 != 0) {
              if (2 < _g_bt_plf_log_level) {
                ets_printf("TX PTI [ACT_SCAN] [EN%d] [%d] \n",*(undefined1 *)(iVar13 + 4),
                           *(undefined1 *)(iVar13 + 5));
              }
              uVar17 = (uint)*(byte *)(iVar13 + 5) << 8;
              if ((uVar17 & 0xf000) != 0) {
                r_assert_err(0,"lld_scan.c",0x33f);
              }
              iVar20 = iVar20 + 10;
              iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
              uVar16 = *(ushort *)(iVar8 + iVar20);
              iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
              *(ushort *)(iVar8 + iVar20) = uVar16 & 0xf0ff | (ushort)uVar17;
              bVar2 = *(byte *)(iVar13 + 4);
              iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
              uVar16 = *(ushort *)(iVar13 + iVar20);
              iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
              *(ushort *)(iVar13 + iVar20) = uVar16 & 0xefff | (ushort)bVar2 << 0xc;
            }
          }
          _DAT_60031124 = 0x10001;
          uVar17 = (uint)_sdk_cfg_priv_opts;
          if ((_sdk_cfg_priv_opts & 0xfe00) != 0) {
            r_assert_err(0,"lld_scan.c",0x29ed);
          }
          _DAT_60031364 = _DAT_60031364 & 0xfffffe00 | uVar17;
          piVar23 = piVar10;
          do {
            iVar20 = *piVar23;
            if (iVar20 != 0) {
              *(uint *)(iVar20 + 4) = uVar11;
              *(uint *)(iVar20 + 0x28) = uVar11;
              iVar13 = r_sch_arb_insert(iVar20);
              if (iVar13 == 0) {
                *(undefined1 *)(iVar20 + 0x43) = 0;
                *(undefined2 *)(iVar20 + 0x36) = 0;
                uVar11 = uVar11 + (uint)*(ushort *)(iVar20 + 0x32) * 2 & 0xfffffff;
              }
              else {
                r_assert_err(0,"lld_scan.c",0xc92);
              }
            }
            piVar23 = piVar23 + 1;
          } while (piVar10 + 2 != piVar23);
          *(undefined1 *)((int)piVar10 + 0x17) = 0;
          iVar20 = r_rwip_time_get();
          piVar10[6] = iVar20;
          piVar10[7] = iVar20;
          return 0;
        }
      } while( true );
    }
    r_assert_err("lld_scan.c",0xc9e);
  }
  return 0xc;
}

