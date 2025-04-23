/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_init_start(undefined2 *param_1)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  ushort uVar11;
  byte bVar12;
  undefined4 uVar13;
  uint uVar14;
  uint uVar15;
  int *__s;
  void *pvVar16;
  byte *pbVar17;
  short sVar18;
  ushort uVar19;
  int *piVar20;
  uint uVar21;
  int *piVar22;
  uint uVar23;
  undefined1 *puVar24;
  byte bVar25;
  int iVar26;
  int iVar27;
  uint *puVar28;
  int iVar29;
  uint uVar30;
  int iVar31;
  ushort uVar32;
  byte bStack_b2;
  byte bStack_b1;
  undefined1 auStack_b0 [4];
  undefined1 auStack_ac [3];
  undefined1 uStack_a9;
  undefined2 uStack_a8;
  undefined2 uStack_a6;
  undefined2 uStack_a4;
  undefined2 uStack_a2;
  undefined1 auStack_a0 [5];
  byte bStack_9b;
  undefined1 auStack_98 [100];
  
  bVar1 = *(byte *)((int)param_1 + 0x13);
  uVar14 = r_lld_read_clock();
  uVar15 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  if (_lld_init_env == (int *)0x0) {
    __s = (int *)r_ke_malloc(0x5c,0);
    _lld_init_env = __s;
    if (__s != (int *)0x0) {
      memset(__s,0,0x5c);
      *(undefined1 *)(__s + 0xb) = *(undefined1 *)((int)param_1 + 0x13);
      *(undefined1 *)((int)__s + 0x32) = *(undefined1 *)(param_1 + 10);
      *(undefined1 *)((int)__s + 0x33) = *(undefined1 *)((int)param_1 + 0x15);
      *(undefined1 *)((int)__s + 0x4f) = *(undefined1 *)(param_1 + 0xb);
      memcpy((void *)((int)__s + 0x3e),param_1,6);
      memcpy(__s + 0x11,param_1 + 3,6);
      memcpy((void *)((int)__s + 0x2d),param_1 + 6,5);
      r_lld_aa_gen(__s + 0xd,*(undefined1 *)((int)param_1 + 0x13));
      *(char *)((int)__s + 0x3a) = (char)((uVar15 & 0xffffff) >> 0x10);
      *(short *)(__s + 0xe) = (short)uVar15;
      iVar31 = _p_lld_env;
      *(undefined1 *)((int)__s + 0x3b) = 2;
      bVar25 = (char)((uVar15 & 0xffffff) % 0xc) + 5;
      *(byte *)(__s + 0xf) = bVar25;
      cVar2 = *(char *)(iVar31 + 0xd6);
      *(char *)((int)__s + 0x3d) = cVar2;
      memcpy(auStack_b0,__s + 0xd,4);
      memcpy(auStack_ac,__s + 0xe,3);
      uStack_a9 = 2;
      uStack_a8 = 0;
      memcpy(auStack_a0,param_1 + 6,5);
      uVar7 = param_1[0xe];
      uVar8 = param_1[0xf];
      uVar9 = param_1[0x10];
      uVar10 = param_1[0x11];
      bStack_9b = bVar25 | cVar2 << 5;
      piVar20 = __s + 3;
      do {
        *(undefined2 *)piVar20 = uVar7;
        *(undefined2 *)((int)piVar20 + 2) = uVar8;
        *(undefined2 *)(piVar20 + 1) = uVar9;
        *(undefined2 *)((int)piVar20 + 6) = uVar10;
        *(undefined1 *)(piVar20 + 2) = 0;
        piVar20 = (int *)((int)piVar20 + 10);
      } while ((int *)((int)__s + 0x2a) != piVar20);
      uVar15 = *(byte *)(param_1 + 9) & 1;
      if ((*(byte *)(param_1 + 9) & 1) == 0) {
_L317:
        uVar15 = 0;
      }
      else {
        pvVar16 = (void *)r_ke_malloc(0x54,0);
        *__s = (int)pvVar16;
        if (pvVar16 == (void *)0x0) {
          r_assert_err(0x10000,0x6d3);
          goto _L317;
        }
        memset(pvVar16,0,0x54);
        *(code **)((int)pvVar16 + 0x20) = r_lld_init_evt_canceled_cbk;
        *(code **)((int)pvVar16 + 0x18) = r_lld_init_evt_start_cbk;
        *(undefined1 *)((int)pvVar16 + 0x16) = DAT_00013042;
        uVar32 = param_1[0xd];
        uVar21 = (uint)uVar32 * 0x4e2;
        if (_sch_slice_params < uVar21) {
          uVar21 = (uint)_sch_slice_params;
        }
        *(uint *)((int)pvVar16 + 0x10) = uVar21;
        *(ushort *)((int)pvVar16 + 0x14) = DAT_00013043 & 0xf | 0x6000;
        uVar7 = param_1[0xc];
        *(ushort *)((int)pvVar16 + 0x2e) = uVar32;
        *(uint *)((int)pvVar16 + 0x24) = (uint)uVar32;
        *(undefined2 *)((int)pvVar16 + 0x2c) = uVar7;
        *(undefined1 *)((int)pvVar16 + 0x3c) = 0x7f;
        *(undefined1 *)((int)pvVar16 + 0x3e) = 1;
        *(undefined1 *)((int)pvVar16 + 0x52) = *(undefined1 *)((int)param_1 + 0x13);
        *(undefined2 *)(__s + 3) = param_1[0xe];
        *(undefined2 *)((int)__s + 0xe) = param_1[0xf];
        *(undefined2 *)(__s + 4) = param_1[0x10];
        uVar7 = param_1[0x11];
        *(undefined1 *)(__s + 5) = 0;
        *(undefined2 *)((int)__s + 0x12) = uVar7;
        *(byte *)((int)__s + 0x2b) = *(byte *)((int)__s + 0x2b) | 1;
      }
      uStack_a6 = (undefined2)__s[3];
      uStack_a4 = (undefined2)__s[4];
      uStack_a2 = *(undefined2 *)((int)__s + 0x12);
      r_lld_init_connect_req_pack(auStack_98,auStack_b0);
      pvVar16 = (void *)r_emi_get_mem_addr_by_offset(0x7400);
      memcpy(pvVar16,auStack_98,0x16);
      if ((*(byte *)(param_1 + 9) & 2) != 0) {
        *(undefined2 *)((int)__s + 0x16) = param_1[uVar15 * 6 + 0xe];
        *(undefined2 *)(__s + 6) = param_1[uVar15 * 6 + 0xf];
        uVar7 = param_1[uVar15 * 6 + 0x10];
        uVar8 = param_1[uVar15 * 6 + 0x11];
        *(char *)((int)__s + 0x1e) = (char)uVar15;
        uVar15 = uVar15 + 1;
        *(undefined2 *)((int)__s + 0x1a) = uVar7;
        *(undefined2 *)(__s + 7) = uVar8;
      }
      uStack_a6 = *(undefined2 *)((int)__s + 0x16);
      uStack_a4 = *(undefined2 *)((int)__s + 0x1a);
      uStack_a2 = (undefined2)__s[7];
      r_lld_init_connect_req_pack(auStack_98,auStack_b0);
      pvVar16 = (void *)r_emi_get_mem_addr_by_offset(0x7422);
      memcpy(pvVar16,auStack_98,0x16);
      if ((*(byte *)(param_1 + 9) & 4) != 0) {
        pvVar16 = (void *)r_ke_malloc(0x54,0);
        __s[1] = (int)pvVar16;
        if (pvVar16 == (void *)0x0) {
          r_assert_err(0x10000,0x734);
        }
        else {
          memset(pvVar16,0,0x54);
          *(code **)((int)pvVar16 + 0x20) = r_lld_init_evt_canceled_cbk;
          *(code **)((int)pvVar16 + 0x18) = r_lld_init_evt_start_cbk;
          *(undefined1 *)((int)pvVar16 + 0x16) = DAT_00013042;
          uVar32 = param_1[uVar15 * 6 + 0xd];
          uVar21 = (uint)uVar32 * 0x4e2;
          if (_sch_slice_params < uVar21) {
            uVar21 = (uint)_sch_slice_params;
          }
          *(uint *)((int)pvVar16 + 0x10) = uVar21;
          *(ushort *)((int)pvVar16 + 0x14) = DAT_00013043 & 0xf | 0x6000;
          uVar7 = param_1[uVar15 * 6 + 0xc];
          *(ushort *)((int)pvVar16 + 0x2e) = uVar32;
          *(uint *)((int)pvVar16 + 0x24) = (uint)uVar32;
          *(undefined2 *)((int)pvVar16 + 0x2c) = uVar7;
          *(undefined1 *)((int)pvVar16 + 0x30) = 3;
          *(undefined1 *)((int)pvVar16 + 0x51) = 1;
          *(undefined1 *)((int)pvVar16 + 0x3e) = 1;
          *(undefined1 *)((int)pvVar16 + 0x3c) = 0x7f;
          *(undefined1 *)((int)pvVar16 + 0x52) = 10;
          *(undefined2 *)(__s + 8) = param_1[uVar15 * 6 + 0xe];
          *(undefined2 *)((int)__s + 0x22) = param_1[uVar15 * 6 + 0xf];
          uVar7 = param_1[uVar15 * 6 + 0x10];
          uVar8 = param_1[uVar15 * 6 + 0x11];
          *(char *)(__s + 10) = (char)uVar15;
          *(undefined2 *)(__s + 9) = uVar7;
          *(undefined2 *)((int)__s + 0x26) = uVar8;
          *(byte *)((int)__s + 0x2b) = *(byte *)((int)__s + 0x2b) | 2;
        }
      }
      uStack_a6 = (undefined2)__s[8];
      uStack_a4 = (undefined2)__s[9];
      uStack_a2 = *(undefined2 *)((int)__s + 0x26);
      r_lld_init_connect_req_pack(auStack_98,auStack_b0);
      pvVar16 = (void *)r_emi_get_mem_addr_by_offset(0x7444);
      memcpy(pvVar16,auStack_98,0x16);
      *(undefined1 *)((int)__s + 0x2a) = *(undefined1 *)((int)param_1 + 0x11);
      if (((*(byte *)(param_1 + 10) & 2) == 0) && (*(char *)(param_1 + 0x1e) == '\0')) {
_L327:
        uVar32 = 0;
_L417:
        uVar15 = 0;
      }
      else {
        uVar32 = 1;
        if (*(char *)(param_1 + 0xb) != '\0') goto _L417;
        uVar15 = r_lld_ral_search(param_1 + 3,*(undefined1 *)((int)param_1 + 0x15));
        if (9 < uVar15) goto _L327;
        uVar32 = 1;
        uVar15 = uVar15 * 0x34 + 0xc60 & 0xffff;
      }
      uVar21 = (uint)bVar1 * 9 & 0xff;
      uVar11 = param_1[10];
      *(bool *)((int)__s + 0x4a) = uVar15 != 0;
      sVar18 = (short)uVar21 * 0xe + 0x1400;
      piVar22 = __s + 2;
      piVar20 = __s;
      do {
        iVar31 = *piVar20;
        bStack_b2 = 0;
        bStack_b1 = 0;
        if (iVar31 != 0) {
          bVar1 = *(byte *)(iVar31 + 0x52);
          uVar30 = (uint)bVar1;
          uVar19 = *(byte *)((int)param_1 + 0x11) + 0xe & 0xff;
          r_lld_init_set_tx_power(uVar30,uVar19);
          iVar26 = __s[3];
          iVar29 = r_emi_get_mem_addr_by_offset(0x400);
          iVar27 = uVar30 * 0x5a;
          *(short *)(iVar27 + 0x22 + iVar29) = (short)iVar26;
          uVar7 = *(undefined2 *)((int)__s + 0x16);
          iVar26 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar27 + 0x38 + iVar26) = uVar7;
          iVar26 = __s[8];
          iVar29 = r_emi_get_mem_addr_by_offset(0x400);
          *(short *)(iVar27 + 0x3c + iVar29) = (short)iVar26;
          iVar26 = r_emi_get_mem_addr_by_offset(0x400);
          *(short *)(iVar27 + 0x1c + iVar26) = sVar18;
          iVar26 = r_emi_get_mem_addr_by_offset(0x400);
          *(short *)(iVar27 + 0x34 + iVar26) = sVar18;
          r_bt_rma_get_ant_by_act(uVar19,uVar30,&bStack_b2,&bStack_b1);
          bVar12 = bStack_b1;
          bVar4 = bStack_b2;
          uVar23 = (uint)DAT_000130a8;
          bVar25 = DAT_000130a8 >> 1;
          bVar3 = DAT_000130a8 >> 2;
          if ((bStack_b2 & 0xfe) != 0) {
            r_assert_err(0,0x10000,0x41);
          }
          if ((bVar12 & 0xfe) != 0) {
            r_assert_err(0,0x10000,0x42);
          }
          iVar26 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar26 + iVar27) =
               (ushort)bVar4 << 8 | (ushort)bVar12 << 7 | (ushort)((uVar23 & 1) << 10) |
               (ushort)((bVar25 & 1) << 9) | (ushort)((bVar3 & 1) << 5) | uVar19;
          iVar26 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar27 + 0xc + iVar26) = 0xbed6;
          iVar26 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar27 + 0xe + iVar26) = 0x8e89;
          iVar26 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar27 + 0x10 + iVar26) = 0x5555;
          iVar26 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar27 + 0x12 + iVar26) = 0x55;
          iVar26 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar27 + 0x46 + iVar26) = 0;
          bVar25 = *(byte *)(param_1 + 0xb);
          bVar3 = *(byte *)(param_1 + 0x1e);
          bVar4 = *(byte *)((int)__s + 0x4a);
          iVar26 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar27 + 0x14 + iVar26) =
               (ushort)bVar25 << 8 | (ushort)bVar3 << 6 | (ushort)((uVar11 >> 1 & 1) << 2) |
               (ushort)bVar4 << 1 | uVar32;
          if (*(char *)((int)__s + 0x4a) != '\0') {
            iVar26 = r_emi_get_mem_addr_by_offset(0x400);
            *(short *)(iVar27 + 0x2c + iVar26) = (short)uVar15;
          }
          if ((*(char *)(param_1 + 0xb) == '\0') && (*(char *)((int)__s + 0x4a) == '\0')) {
            puVar24 = (undefined1 *)((int)param_1 + 7);
            iVar26 = 0;
            do {
              uVar5 = *puVar24;
              uVar6 = puVar24[-1];
              iVar29 = r_emi_get_mem_addr_by_offset(0x400);
              *(ushort *)(iVar29 + iVar27 + 0x2c + iVar26) = CONCAT11(uVar5,uVar6);
              iVar26 = iVar26 + 2;
              puVar24 = puVar24 + 2;
            } while (iVar26 != 6);
            bVar25 = *(byte *)((int)param_1 + 0x15);
            iVar26 = r_emi_get_mem_addr_by_offset(0x400);
            *(ushort *)(iVar27 + 0x32 + iVar26) = bVar25 & 1;
          }
          iVar26 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar27 + 0x16 + iVar26) = 0x8027;
          iVar26 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar27 + 0x28 + iVar26) = 0;
          iVar26 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar27 + 0x2a + iVar26) = 0;
          bVar25 = *(byte *)(param_1 + 10);
          if (0x1f < uVar30) {
            r_assert_err(0,0x10000,0xe6);
          }
          iVar26 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar27 + 2 + iVar26) = (ushort)((bVar25 & 1) << 7) | (ushort)bVar1 | 0x800;
          uVar7 = *param_1;
          iVar26 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar27 + 6 + iVar26) = uVar7;
          uVar7 = param_1[1];
          iVar26 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar27 + 8 + iVar26) = uVar7;
          uVar7 = param_1[2];
          iVar26 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar27 + 10 + iVar26) = uVar7;
          bVar1 = *(byte *)(iVar31 + 0x30);
          if ((bVar1 & 0xfc) == 0) {
            if (3 < bVar1) goto _L338;
          }
          else {
            r_assert_err(0,0x10000,399);
_L338:
            r_assert_err(0,0x10000,400);
          }
          iVar26 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar27 + 4 + iVar26) =
               (ushort)bVar1 | (ushort)((int)(short)(ushort)bVar1 << 2) | 0x2000;
          uVar7 = *(undefined2 *)(iVar31 + 0x24);
          iVar26 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar27 + 0x20 + iVar26) = uVar7;
          iVar31 = *(int *)(iVar31 + 0x24);
          if (iVar31 << 0x10 < 0) {
            r_assert_err(0,0x10000,0x4ab);
          }
          iVar26 = r_emi_get_mem_addr_by_offset(0x400);
          bVar1 = *(byte *)((int)param_1 + 0x11);
          *(ushort *)(iVar27 + 0x1a + iVar26) = (ushort)iVar31 | 0x8000;
          pbVar17 = (byte *)r_bt_rf_coex_st_param_get(bVar1 + 9);
          if (pbVar17 != (byte *)0x0) {
            bVar1 = pbVar17[1];
            if (0xb < uVar30) {
              r_assert_err(0,0x10000,0x299b);
            }
            if ((bVar1 & 0xf0) != 0) {
              r_assert_err(0,0x10000,0x299d);
            }
            puVar28 = (uint *)((uVar30 + 0x1800c4cb) * 4);
            *puVar28 = *puVar28 & 0xfffff0ff | (uint)bVar1 << 8;
            bVar1 = *pbVar17;
            if (0xb < uVar30) {
              r_assert_err(0,0x10000,0x294a);
            }
            *puVar28 = *puVar28 & 0xbfffffff | (uint)bVar1 << 0x1e;
            bVar1 = pbVar17[3];
            if (0xb < uVar30) {
              r_assert_err(0,0x10000,0x29bb);
            }
            if (0xf < bVar1) {
              r_assert_err(0,0x10000,0x29bd);
            }
            *puVar28 = *puVar28 & 0xfffffff0 | (uint)bVar1;
            bVar1 = pbVar17[2];
            if (0xb < uVar30) {
              r_assert_err(0,0x10000,0x295a);
            }
            *puVar28 = *puVar28 & 0xdfffffff | (uint)bVar1 << 0x1d;
            bVar1 = pbVar17[7];
            if (0xb < uVar30) {
              r_assert_err(0,0x10000,0x298b);
            }
            if ((bVar1 & 0xf0) != 0) {
              r_assert_err(0,0x10000,0x298d);
            }
            *puVar28 = *puVar28 & 0xffff0fff | (uint)bVar1 << 0xc;
            bVar1 = pbVar17[8];
            if (0xb < uVar30) {
              r_assert_err(0,0x10000,0x29ab);
            }
            if ((bVar1 & 0xf0) != 0) {
              r_assert_err(0,0x10000,0x29ad);
            }
            *puVar28 = *puVar28 & 0xffffff0f | (uint)bVar1 << 4;
            bVar1 = pbVar17[9];
            if (0xb < uVar30) {
              r_assert_err(0,0x10000,0x297b);
            }
            if ((bVar1 & 0xf0) != 0) {
              r_assert_err(0,0x10000,0x297d);
            }
            *puVar28 = *puVar28 & 0xfff0ffff | (uint)bVar1 << 0x10;
            uVar19 = *(ushort *)(pbVar17 + 10);
            if (0xb < uVar30) {
              r_assert_err(0,0x10000,0x296a);
            }
            if ((uVar19 >> 9 & 7) != 0) {
              r_assert_err(0,0x10000,0x296c);
            }
            *puVar28 = *puVar28 & 0xe00fffff | (uint)uVar19 << 0x14;
            bVar1 = pbVar17[6];
            if (0xb < uVar30) {
              r_assert_err(0,0x10000,0x293a);
            }
            *puVar28 = *puVar28 & 0x7fffffff | (uint)bVar1 << 0x1f;
            if (2 < _g_bt_plf_log_level) {
              ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[INITIATOR] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                         ,uVar30,puVar28,pbVar17[2],pbVar17[3],*pbVar17,pbVar17[1],pbVar17[6]);
            }
          }
        }
        piVar20 = piVar20 + 1;
      } while (piVar22 != piVar20);
      iVar31 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar26 = uVar21 * 0xe;
      iVar29 = iVar26 + 2;
      uVar32 = *(ushort *)(iVar31 + iVar29);
      iVar31 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar31 + iVar29) = uVar32 & 0xfff0 | 5;
      iVar31 = r_emi_get_mem_addr_by_offset(0x1400);
      *(undefined2 *)(iVar26 + 4 + iVar31) = 0x7400;
      iVar31 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar32 = *(ushort *)(iVar31 + iVar29);
      iVar31 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar31 + iVar29) = uVar32 & 0xff | 0x2200;
      iVar31 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar32 = *(ushort *)(iVar31 + iVar26);
      iVar31 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar31 + iVar26) = uVar32 & 0x8000;
      bVar1 = *(byte *)((int)param_1 + 0x15);
      iVar31 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar29 + iVar31) = (ushort)((bVar1 & 1) << 7) | 0x2225;
      iVar31 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar32 = *(ushort *)(iVar31 + iVar26);
      iVar31 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar31 + iVar26) = (ushort)(((uint)uVar32 << 0x11) >> 0x11);
      iVar31 = r_bt_rf_coex_st_param_get(*(byte *)((int)param_1 + 0x11) + 9);
      if (iVar31 != 0) {
        if (2 < _g_bt_plf_log_level) {
          ets_printf("TX PTI [Initiator] [EN%d] [%d] \n",*(undefined1 *)(iVar31 + 4),
                     *(undefined1 *)(iVar31 + 5));
        }
        bVar1 = *(byte *)(iVar31 + 5);
        if ((bVar1 & 0xf0) != 0) {
          r_assert_err(0,0x10000,0x33f);
        }
        iVar26 = iVar26 + 10;
        iVar29 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar32 = *(ushort *)(iVar29 + iVar26);
        iVar29 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar29 + iVar26) = uVar32 & 0xf0ff | (ushort)bVar1 << 8;
        bVar1 = *(byte *)(iVar31 + 4);
        iVar31 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar32 = *(ushort *)(iVar31 + iVar26);
        iVar31 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar31 + iVar26) = uVar32 & 0xefff | (ushort)bVar1 << 0xc;
      }
      __s[2] = 0;
      uVar13 = 0xc;
      do {
        iVar31 = *__s;
        if (iVar31 != 0) {
          *(uint *)(iVar31 + 4) = uVar14;
          *(uint *)(iVar31 + 0x28) = uVar14;
          iVar26 = r_sch_arb_insert(iVar31);
          if (iVar26 == 0) {
            *(undefined1 *)(iVar31 + 0x50) = 0;
            uVar14 = (uint)*(ushort *)(iVar31 + 0x2e) * 2 + uVar14 & 0xfffffff;
            uVar13 = 0;
          }
          else {
            r_assert_err(0,0x10000,0x811);
            uVar13 = 0;
          }
        }
        __s = __s + 1;
      } while (__s != piVar22);
      goto _L365;
    }
    r_assert_err(0x10000,0x819);
  }
  uVar13 = 0xc;
_L365:
  r_lld_init_start_hook_part_0(param_1);
  return uVar13;
}

