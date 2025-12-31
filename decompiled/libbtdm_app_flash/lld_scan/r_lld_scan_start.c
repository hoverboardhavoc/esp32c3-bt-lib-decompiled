/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
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
  byte *unaff_s0;
  undefined1 uVar8;
  int *piVar9;
  uint uVar10;
  void *pvVar11;
  int iVar12;
  undefined4 uVar13;
  short sVar14;
  ushort uVar15;
  uint uVar16;
  int iVar17;
  uint *puVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  int *piVar22;
  uint uVar23;
  byte bStack_49;
  byte abStack_48 [20];
  
  if (_lld_scan_env == (int *)0x0) {
    piVar9 = (int *)r_ke_malloc(0x20,0);
    _lld_scan_env = piVar9;
    if (piVar9 != (int *)0x0) {
      uVar10 = r_lld_read_clock();
      bVar7 = false;
      memset(_lld_scan_env,0,0x20);
      if ((*(byte *)((int)param_2 + 7) & 1) != 0) {
        pvVar11 = (void *)r_ke_malloc(0x84,0);
        *piVar9 = (int)pvVar11;
        if (pvVar11 == (void *)0x0) {
          r_assert_err("lld_scan.c",0xbb6);
        }
        else {
          memset(pvVar11,0,0x84);
          *(code **)((int)pvVar11 + 0x20) = r_lld_scan_evt_canceled_cbk;
          *(code **)((int)pvVar11 + 0x18) = r_lld_scan_evt_start_cbk_eco;
          *(undefined1 *)((int)pvVar11 + 0x16) = rwip_priority;
          uVar15 = param_2[6];
          uVar16 = (uint)uVar15 * 0x4e2;
          if (_sch_slice_params < uVar16) {
            uVar16 = (uint)_sch_slice_params;
          }
          *(uint *)((int)pvVar11 + 0x10) = uVar16;
          *(ushort *)((int)pvVar11 + 0x14) = DAT_0001507d & 0xf | 0x6000;
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
        pvVar11 = (void *)r_ke_malloc(0x84,0);
        piVar9[1] = (int)pvVar11;
        if (pvVar11 == (void *)0x0) {
          r_assert_err("lld_scan.c",0xbe2);
        }
        else {
          memset(pvVar11,0,0x84);
          *(code **)((int)pvVar11 + 0x20) = r_lld_scan_evt_canceled_cbk;
          *(code **)((int)pvVar11 + 0x18) = r_lld_scan_evt_start_cbk_eco;
          *(undefined1 *)((int)pvVar11 + 0x16) = rwip_priority;
          uVar15 = param_2[7];
          uVar16 = (uint)uVar15 * 0x4e2;
          if (_sch_slice_params < uVar16) {
            uVar16 = (uint)_sch_slice_params;
          }
          *(uint *)((int)pvVar11 + 0x10) = uVar16;
          *(ushort *)((int)pvVar11 + 0x14) = DAT_0001507d & 0xf | 0x6000;
          uVar6 = param_2[5];
          *(ushort *)((int)pvVar11 + 0x32) = uVar15;
          *(undefined2 *)((int)pvVar11 + 0x30) = uVar6;
          cVar1 = *(char *)((int)param_2 + 0x11);
          *(undefined1 *)((int)pvVar11 + 0x3b) = 3;
          *(char *)((int)pvVar11 + 0x39) = cVar1;
          *(undefined1 *)((int)pvVar11 + 0x40) = 1;
          *(uint *)((int)pvVar11 + 0x24) = (uint)uVar15;
          *(undefined1 *)((int)pvVar11 + 0x38) = 0xb;
          bVar7 = (bool)(bVar7 | cVar1 == '\x01');
          *(byte *)(piVar9 + 3) = *(byte *)(piVar9 + 3) | 2;
        }
      }
      memcpy((void *)((int)piVar9 + 0xe),param_2,6);
      uVar16 = 0xffffffff;
      *(undefined1 *)(piVar9 + 5) = *(undefined1 *)(param_2 + 9);
      uVar8 = *(undefined1 *)((int)param_2 + 0x13);
      *(char *)((int)piVar9 + 0xd) = param_1;
      *(undefined1 *)((int)piVar9 + 0x15) = uVar8;
      *(undefined1 *)((int)piVar9 + 0x16) = *(undefined1 *)(param_2 + 10);
      if ((ushort)param_2[0xb] != 0) {
        uVar16 = (uint)(ushort)param_2[0xb] * 0x20 + uVar10 & 0xfffffff;
      }
      piVar9[2] = uVar16;
      sVar14 = (ushort)(byte)(param_1 * '\t') * 0xe + 0x1400;
      piVar22 = piVar9;
      do {
        bStack_49 = 0;
        abStack_48[0] = 0;
        iVar19 = *piVar22;
        if (iVar19 != 0) {
          bVar2 = *(byte *)(iVar19 + 0x38);
          uVar20 = (uint)bVar2;
          uVar8 = *(undefined1 *)(param_2 + 3);
          iVar17 = uVar20 * 0x5a;
          *(undefined1 *)(iVar19 + 0x3d) = 0;
          *(undefined1 *)(iVar19 + 0x42) = uVar8;
          *(undefined1 *)(iVar19 + 0x3f) = 9;
          iVar12 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar17 + 0xc + iVar12) = 0xbed6;
          iVar12 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar17 + 0xe + iVar12) = 0x8e89;
          iVar12 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar17 + 0x10 + iVar12) = 0x5555;
          iVar12 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar17 + 0x12 + iVar12) = 0x55;
          iVar12 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar17 + 0x46 + iVar12) = 0;
          uVar16 = 0;
          if (_lld_scan_sync_env != 0) {
            uVar16 = (uint)(*(char *)(_lld_scan_sync_env + 1) != '\0');
          }
          *(char *)(iVar19 + 0x44) = (char)uVar16;
          bVar3 = *(byte *)(param_2 + 9);
          bVar4 = *(byte *)((int)piVar9 + 0x15);
          bVar5 = *(byte *)(param_2 + 10);
          uVar15 = 1;
          if (*(char *)((int)piVar9 + 0x16) == '\0') {
            uVar15 = *(byte *)(piVar9 + 5) >> 1 & 1;
          }
          iVar12 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar17 + 0x14 + iVar12) =
               (ushort)bVar5 << 6 | (ushort)((bVar3 >> 1 & 1) << 2) | (ushort)bVar4 << 8 |
               (ushort)(uVar16 << 3) | uVar15;
          iVar12 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar17 + 0x16 + iVar12) = 0x8027;
          iVar12 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar17 + 0x28 + iVar12) = 0;
          iVar12 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar17 + 0x2a + iVar12) = 0;
          bVar3 = *(byte *)(param_2 + 9);
          uVar15 = (ushort)DAT_00015096;
          if ((bVar2 & 0xe0) != 0) {
            r_assert_err(0,"lld_scan.c",0xe6);
          }
          iVar12 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar17 + 2 + iVar12) =
               uVar15 << 5 | (ushort)bVar2 | (ushort)((bVar3 & 1) << 7) | 0x800;
          uVar6 = *param_2;
          iVar12 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar17 + 6 + iVar12) = uVar6;
          uVar6 = param_2[1];
          iVar12 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar17 + 8 + iVar12) = uVar6;
          uVar6 = param_2[2];
          iVar12 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar17 + 10 + iVar12) = uVar6;
          if (*(char *)(iVar19 + 0x39) == '\x01') {
            iVar12 = r_emi_get_mem_addr_by_offset();
            *(short *)(iVar12 + iVar17 + 0x1c) = sVar14;
            iVar12 = r_emi_get_mem_addr_by_offset(0x400);
            *(short *)(iVar12 + iVar17 + 0x34) = sVar14;
            uVar8 = 0xb;
            if (*(char *)(iVar19 + 0x42) == '\0') {
              uVar8 = 9;
            }
          }
          else {
            iVar12 = r_emi_get_mem_addr_by_offset(0x400);
            *(undefined2 *)(iVar12 + iVar17 + 0x1c) = 0;
            iVar12 = r_emi_get_mem_addr_by_offset(0x400);
            cVar1 = *(char *)(iVar19 + 0x42);
            *(undefined2 *)(iVar12 + iVar17 + 0x34) = 0;
            uVar8 = 10;
            if (cVar1 == '\0') {
              uVar8 = 8;
            }
          }
          *(undefined1 *)(iVar19 + 0x3a) = uVar8;
          r_bt_rma_get_ant_by_act(uVar20,&bStack_49,abStack_48);
          iVar12 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar17 + 0x18 + iVar12) = 0;
          r_lld_scan_set_tx_power(uVar20,*(undefined1 *)(iVar19 + 0x3a));
          bVar2 = *(byte *)(iVar19 + 0x3a);
          uVar21 = (uint)bStack_49;
          uVar16 = (uint)DAT_000150cb;
          uVar23 = (uint)abStack_48[0];
          if ((uVar21 << 7 & 0xffffff7f) != 0) {
            r_assert_err(0,"lld_scan.c",0x42);
          }
          if ((uVar23 << 6 & 0xffffffbf) != 0) {
            r_assert_err(0,"lld_scan.c",0x43);
          }
          if ((bVar2 & 0xe0) != 0) {
            r_assert_err(0,"lld_scan.c",0x45);
          }
          iVar12 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar12 + iVar17) =
               (ushort)(uVar21 << 7) | (ushort)(uVar23 << 6) | (ushort)bVar2 |
               (ushort)((uVar16 & 1) << 10) | (ushort)((uVar16 & 2) << 8) |
               (ushort)((uVar16 & 4) << 6) | 0x20;
          bVar2 = *(byte *)(iVar19 + 0x3b);
          if (((uint)bVar2 << 2 & 0xfffffff3) != 0) {
            r_assert_err(0,"lld_scan.c",399);
          }
          if ((bVar2 & 0xfc) != 0) {
            r_assert_err(0,"lld_scan.c",400);
          }
          iVar12 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar17 + 4 + iVar12) = (ushort)((uint)bVar2 << 2) | (ushort)bVar2 | 0x1000;
          if (g_scan_forever == '\0') {
            uVar6 = *(undefined2 *)(iVar19 + 0x24);
            iVar12 = r_emi_get_mem_addr_by_offset(0x400);
            uVar16 = *(uint *)(iVar19 + 0x24);
            *(undefined2 *)(iVar12 + iVar17 + 0x20) = uVar6;
            if (0x3fff < uVar16) {
              uVar16 = 0x3fff;
            }
            iVar12 = r_emi_get_mem_addr_by_offset(0x400);
            uVar15 = (ushort)uVar16 | 0x8000;
          }
          else {
            iVar12 = r_emi_get_mem_addr_by_offset(0x400);
            *(undefined2 *)(iVar12 + iVar17 + 0x20) = 0;
            iVar12 = r_emi_get_mem_addr_by_offset(0x400);
            uVar15 = 0xbfff;
          }
          *(ushort *)(iVar12 + iVar17 + 0x1a) = uVar15;
          bVar2 = *(byte *)(iVar19 + 0x3a);
          if (bVar2 == 10) {
            uVar13 = 7;
_L924:
            unaff_s0 = (byte *)r_bt_rf_coex_st_param_get(uVar13);
          }
          else {
            if (bVar2 < 0xb) {
              if (bVar2 == 8) {
                uVar13 = 5;
              }
              else {
                uVar13 = 6;
                if (bVar2 != 9) goto _L826;
              }
              goto _L924;
            }
            uVar13 = 8;
            if (bVar2 == 0xb) goto _L924;
_L826:
            r_assert_err(0,"lld_scan.c",0xc90);
          }
          if (unaff_s0 != (byte *)0x0) {
            bVar2 = unaff_s0[1];
            if (0xb < uVar20) {
              r_assert_err(0,"lld_scan.c",0x299b);
            }
            if (((uint)bVar2 << 8 & 0xf000) != 0) {
              r_assert_err(0,"lld_scan.c",0x299d);
            }
            puVar18 = (uint *)((uVar20 + 0x1800c4cb) * 4);
            *puVar18 = *puVar18 & 0xfffff0ff | (uint)bVar2 << 8;
            bVar2 = *unaff_s0;
            if (0xb < uVar20) {
              r_assert_err(0,"lld_scan.c",0x294a);
            }
            *puVar18 = (uint)bVar2 << 0x1e | *puVar18 & 0xbfffffff;
            bVar2 = unaff_s0[3];
            if (0xb < uVar20) {
              r_assert_err(0,"lld_scan.c",0x29bb);
            }
            if ((bVar2 & 0xf0) != 0) {
              r_assert_err(0,"lld_scan.c",0x29bd);
            }
            *puVar18 = *puVar18 & 0xfffffff0 | (uint)bVar2;
            bVar2 = unaff_s0[2];
            if (0xb < uVar20) {
              r_assert_err(0,"lld_scan.c",0x295a);
            }
            *puVar18 = (uint)bVar2 << 0x1d | *puVar18 & 0xdfffffff;
            bVar2 = unaff_s0[7];
            if (0xb < uVar20) {
              r_assert_err(0,"lld_scan.c",0x298b);
            }
            if (((uint)bVar2 << 0xc & 0xf0000) != 0) {
              r_assert_err(0,"lld_scan.c",0x298d);
            }
            *puVar18 = *puVar18 & 0xffff0fff | (uint)bVar2 << 0xc;
            bVar2 = unaff_s0[8];
            if (0xb < uVar20) {
              r_assert_err(0,"lld_scan.c",0x29ab);
            }
            if (((uint)bVar2 << 4 & 0xffffff0f) != 0) {
              r_assert_err(0,"lld_scan.c",0x29ad);
            }
            *puVar18 = *puVar18 & 0xffffff0f | (uint)bVar2 << 4;
            bVar2 = unaff_s0[9];
            if (0xb < uVar20) {
              r_assert_err(0,"lld_scan.c",0x297b);
            }
            if (((uint)bVar2 << 0x10 & 0xf00000) != 0) {
              r_assert_err(0,"lld_scan.c",0x297d);
            }
            *puVar18 = *puVar18 & 0xfff0ffff | (uint)bVar2 << 0x10;
            uVar15 = *(ushort *)(unaff_s0 + 10);
            if (0xb < uVar20) {
              r_assert_err(0,"lld_scan.c",0x296a);
            }
            if (((uint)uVar15 << 0x14 & 0xe0000000) != 0) {
              r_assert_err(0,"lld_scan.c",0x296c);
            }
            *puVar18 = *puVar18 & 0xe00fffff | (uint)uVar15 << 0x14;
            bVar2 = unaff_s0[6];
            if (0xb < uVar20) {
              r_assert_err(0,"lld_scan.c",0x293a);
            }
            *puVar18 = *puVar18 & 0x7fffffff | (uint)bVar2 << 0x1f;
            if (2 < _g_bt_plf_log_level) {
              ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[SCAN[%d]] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                         ,uVar20,puVar18,*(undefined1 *)(iVar19 + 0x3a),unaff_s0[2],unaff_s0[3],
                         *unaff_s0,unaff_s0[1]);
            }
          }
        }
        piVar22 = piVar22 + 1;
        if (piVar9 + 2 == piVar22) {
          if (bVar7) {
            iVar12 = r_emi_get_mem_addr_by_offset(0x1400);
            iVar19 = (uint)(byte)(param_1 * '\t') * 0xe;
            iVar17 = iVar19 + 2;
            uVar15 = *(ushort *)(iVar12 + iVar17);
            iVar12 = r_emi_get_mem_addr_by_offset(0x1400);
            *(ushort *)(iVar12 + iVar17) = uVar15 & 0xfff0 | 3;
            iVar12 = r_emi_get_mem_addr_by_offset(0x1400);
            *(undefined2 *)(iVar19 + 4 + iVar12) = 0;
            iVar12 = r_emi_get_mem_addr_by_offset(0x1400);
            uVar15 = *(ushort *)(iVar12 + iVar17);
            iVar12 = r_emi_get_mem_addr_by_offset(0x1400);
            *(ushort *)(iVar12 + iVar17) = uVar15 & 0xff | 0xc00;
            iVar12 = r_emi_get_mem_addr_by_offset(0x1400);
            uVar15 = *(ushort *)(iVar12 + iVar19);
            iVar12 = r_emi_get_mem_addr_by_offset(0x1400);
            *(ushort *)(iVar12 + iVar19) = uVar15 & 0x8000;
            iVar12 = r_emi_get_mem_addr_by_offset(0x1400);
            uVar15 = *(ushort *)(iVar12 + iVar19);
            iVar12 = r_emi_get_mem_addr_by_offset(0x1400);
            *(ushort *)(iVar12 + iVar19) = (ushort)(((uint)uVar15 << 0x11) >> 0x11);
            iVar12 = r_bt_rf_coex_st_param_get(6);
            if (iVar12 != 0) {
              if (2 < _g_bt_plf_log_level) {
                ets_printf("TX PTI [ACT_SCAN] [EN%d] [%d] \n",*(undefined1 *)(iVar12 + 4),
                           *(undefined1 *)(iVar12 + 5));
              }
              uVar16 = (uint)*(byte *)(iVar12 + 5) << 8;
              if ((uVar16 & 0xf000) != 0) {
                r_assert_err(0,"lld_scan.c",0x33f);
              }
              iVar17 = r_emi_get_mem_addr_by_offset(0x1400);
              iVar19 = iVar19 + 10;
              uVar15 = *(ushort *)(iVar17 + iVar19);
              iVar17 = r_emi_get_mem_addr_by_offset(0x1400);
              *(ushort *)(iVar17 + iVar19) = uVar15 & 0xf0ff | (ushort)uVar16;
              bVar2 = *(byte *)(iVar12 + 4);
              iVar12 = r_emi_get_mem_addr_by_offset(0x1400);
              uVar15 = *(ushort *)(iVar12 + iVar19);
              iVar12 = r_emi_get_mem_addr_by_offset(0x1400);
              *(ushort *)(iVar12 + iVar19) = uVar15 & 0xefff | (ushort)bVar2 << 0xc;
            }
          }
          _DAT_60031124 = 0x10001;
          uVar16 = (uint)_sdk_cfg_priv_opts;
          if ((_sdk_cfg_priv_opts & 0xfe00) != 0) {
            r_assert_err(0,"lld_scan.c",0x29ed);
          }
          _DAT_60031364 = _DAT_60031364 & 0xfffffe00 | uVar16;
          piVar22 = piVar9;
          do {
            iVar19 = *piVar22;
            if (iVar19 != 0) {
              *(uint *)(iVar19 + 4) = uVar10;
              *(uint *)(iVar19 + 0x28) = uVar10;
              iVar12 = r_sch_arb_insert(iVar19);
              if (iVar12 == 0) {
                *(undefined1 *)(iVar19 + 0x43) = 0;
                *(undefined2 *)(iVar19 + 0x36) = 0;
                uVar10 = (uint)*(ushort *)(iVar19 + 0x32) * 2 + uVar10 & 0xfffffff;
              }
              else {
                r_assert_err(0,"lld_scan.c",0xce2);
              }
            }
            piVar22 = piVar22 + 1;
          } while (piVar9 + 2 != piVar22);
          *(undefined1 *)((int)piVar9 + 0x17) = 0;
          iVar19 = r_rwip_time_get();
          piVar9[6] = iVar19;
          piVar9[7] = iVar19;
          return 0;
        }
      } while( true );
    }
    r_assert_err("lld_scan.c",0xcee);
  }
  return 0xc;
}

