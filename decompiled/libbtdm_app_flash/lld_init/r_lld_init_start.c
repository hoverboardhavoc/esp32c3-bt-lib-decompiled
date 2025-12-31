/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
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
  byte bVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  uint uVar12;
  uint uVar13;
  int *__s;
  void *pvVar14;
  byte *pbVar15;
  short sVar16;
  uint uVar17;
  int *piVar18;
  uint uVar19;
  int *piVar20;
  uint uVar21;
  undefined1 *puVar22;
  byte bVar23;
  int iVar24;
  undefined4 uVar25;
  int iVar26;
  uint *puVar27;
  uint uVar28;
  uint uVar29;
  int iVar30;
  ushort uVar31;
  int iVar32;
  ushort uVar33;
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
  uVar12 = r_lld_read_clock();
  uVar13 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
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
      *(char *)((int)__s + 0x3a) = (char)((uVar13 & 0xffffff) >> 0x10);
      *(short *)(__s + 0xe) = (short)uVar13;
      iVar32 = _p_lld_env;
      *(undefined1 *)((int)__s + 0x3b) = 2;
      bVar23 = (char)((uVar13 & 0xffffff) % 0xc) + 5;
      *(byte *)(__s + 0xf) = bVar23;
      cVar2 = *(char *)(iVar32 + 0xd6);
      *(char *)((int)__s + 0x3d) = cVar2;
      memcpy(auStack_b0,__s + 0xd,4);
      memcpy(auStack_ac,__s + 0xe,3);
      uStack_a9 = 2;
      uStack_a8 = 0;
      memcpy(auStack_a0,param_1 + 6,5);
      uVar8 = param_1[0xe];
      uVar9 = param_1[0xf];
      uVar10 = param_1[0x10];
      uVar11 = param_1[0x11];
      bStack_9b = bVar23 | cVar2 << 5;
      piVar18 = __s + 3;
      do {
        *(undefined2 *)piVar18 = uVar8;
        *(undefined2 *)((int)piVar18 + 2) = uVar9;
        *(undefined2 *)(piVar18 + 1) = uVar10;
        *(undefined2 *)((int)piVar18 + 6) = uVar11;
        *(undefined1 *)(piVar18 + 2) = 0;
        piVar18 = (int *)((int)piVar18 + 10);
      } while ((int *)((int)__s + 0x2a) != piVar18);
      uVar13 = *(byte *)(param_1 + 9) & 1;
      if ((*(byte *)(param_1 + 9) & 1) != 0) {
        pvVar14 = (void *)r_ke_malloc(0x54,0);
        *__s = (int)pvVar14;
        if (pvVar14 == (void *)0x0) {
          r_assert_err(0x10000,0x6fb);
          uVar13 = 0;
        }
        else {
          memset(pvVar14,0,0x54);
          *(code **)((int)pvVar14 + 0x20) = r_lld_init_evt_canceled_cbk;
          *(code **)((int)pvVar14 + 0x18) = r_lld_init_evt_start_cbk;
          *(undefined1 *)((int)pvVar14 + 0x16) = DAT_00013042;
          uVar33 = param_1[0xd];
          uVar19 = (uint)uVar33 * 0x4e2;
          if (_sch_slice_params < uVar19) {
            uVar19 = (uint)_sch_slice_params;
          }
          *(uint *)((int)pvVar14 + 0x10) = uVar19;
          *(ushort *)((int)pvVar14 + 0x14) = DAT_00013043 & 0xf | 0x6000;
          uVar8 = param_1[0xc];
          *(ushort *)((int)pvVar14 + 0x2e) = uVar33;
          *(uint *)((int)pvVar14 + 0x24) = (uint)uVar33;
          *(undefined2 *)((int)pvVar14 + 0x2c) = uVar8;
          *(undefined1 *)((int)pvVar14 + 0x3c) = 0x7f;
          *(undefined1 *)((int)pvVar14 + 0x3e) = 1;
          *(undefined1 *)((int)pvVar14 + 0x52) = *(undefined1 *)((int)param_1 + 0x13);
          *(undefined2 *)(__s + 3) = param_1[0xe];
          *(undefined2 *)((int)__s + 0xe) = param_1[0xf];
          *(undefined2 *)(__s + 4) = param_1[0x10];
          uVar8 = param_1[0x11];
          *(undefined1 *)(__s + 5) = 0;
          *(undefined2 *)((int)__s + 0x12) = uVar8;
          *(byte *)((int)__s + 0x2b) = *(byte *)((int)__s + 0x2b) | 1;
        }
      }
      uStack_a6 = (undefined2)__s[3];
      uStack_a4 = (undefined2)__s[4];
      uStack_a2 = *(undefined2 *)((int)__s + 0x12);
      r_lld_init_connect_req_pack(auStack_98,auStack_b0);
      pvVar14 = (void *)r_emi_get_mem_addr_by_offset(0x7400);
      memcpy(pvVar14,auStack_98,0x16);
      if ((*(byte *)(param_1 + 9) & 2) != 0) {
        *(undefined2 *)((int)__s + 0x16) = param_1[uVar13 * 6 + 0xe];
        *(undefined2 *)(__s + 6) = param_1[uVar13 * 6 + 0xf];
        uVar8 = param_1[uVar13 * 6 + 0x10];
        uVar9 = param_1[uVar13 * 6 + 0x11];
        *(char *)((int)__s + 0x1e) = (char)uVar13;
        uVar13 = uVar13 + 1;
        *(undefined2 *)((int)__s + 0x1a) = uVar8;
        *(undefined2 *)(__s + 7) = uVar9;
      }
      uStack_a6 = *(undefined2 *)((int)__s + 0x16);
      uStack_a4 = *(undefined2 *)((int)__s + 0x1a);
      uStack_a2 = (undefined2)__s[7];
      r_lld_init_connect_req_pack(auStack_98,auStack_b0);
      pvVar14 = (void *)r_emi_get_mem_addr_by_offset(0x7422);
      memcpy(pvVar14,auStack_98,0x16);
      if ((*(byte *)(param_1 + 9) & 4) != 0) {
        pvVar14 = (void *)r_ke_malloc(0x54,0);
        __s[1] = (int)pvVar14;
        if (pvVar14 == (void *)0x0) {
          r_assert_err(0x10000,0x75c);
        }
        else {
          memset(pvVar14,0,0x54);
          *(code **)((int)pvVar14 + 0x20) = r_lld_init_evt_canceled_cbk;
          *(code **)((int)pvVar14 + 0x18) = r_lld_init_evt_start_cbk;
          *(undefined1 *)((int)pvVar14 + 0x16) = DAT_00013042;
          uVar33 = param_1[uVar13 * 6 + 0xd];
          uVar19 = (uint)uVar33 * 0x4e2;
          if (_sch_slice_params < uVar19) {
            uVar19 = (uint)_sch_slice_params;
          }
          *(uint *)((int)pvVar14 + 0x10) = uVar19;
          *(ushort *)((int)pvVar14 + 0x14) = DAT_00013043 & 0xf | 0x6000;
          uVar8 = param_1[uVar13 * 6 + 0xc];
          *(ushort *)((int)pvVar14 + 0x2e) = uVar33;
          *(uint *)((int)pvVar14 + 0x24) = (uint)uVar33;
          *(undefined2 *)((int)pvVar14 + 0x2c) = uVar8;
          *(undefined1 *)((int)pvVar14 + 0x30) = 3;
          *(undefined1 *)((int)pvVar14 + 0x51) = 1;
          *(undefined1 *)((int)pvVar14 + 0x3e) = 1;
          *(undefined1 *)((int)pvVar14 + 0x3c) = 0x7f;
          *(undefined1 *)((int)pvVar14 + 0x52) = 10;
          *(undefined2 *)(__s + 8) = param_1[uVar13 * 6 + 0xe];
          *(undefined2 *)((int)__s + 0x22) = param_1[uVar13 * 6 + 0xf];
          uVar8 = param_1[uVar13 * 6 + 0x10];
          uVar9 = param_1[uVar13 * 6 + 0x11];
          *(char *)(__s + 10) = (char)uVar13;
          *(undefined2 *)(__s + 9) = uVar8;
          *(undefined2 *)((int)__s + 0x26) = uVar9;
          *(byte *)((int)__s + 0x2b) = *(byte *)((int)__s + 0x2b) | 2;
        }
      }
      uStack_a6 = (undefined2)__s[8];
      uStack_a4 = (undefined2)__s[9];
      uStack_a2 = *(undefined2 *)((int)__s + 0x26);
      r_lld_init_connect_req_pack(auStack_98,auStack_b0);
      pvVar14 = (void *)r_emi_get_mem_addr_by_offset(0x7444);
      memcpy(pvVar14,auStack_98,0x16);
      *(undefined1 *)((int)__s + 0x2a) = *(undefined1 *)((int)param_1 + 0x11);
      if (((*(byte *)(param_1 + 10) & 2) == 0) && (*(char *)(param_1 + 0x1e) == '\0')) {
_L312:
        uVar33 = 0;
_L415:
        uVar13 = 0;
      }
      else {
        uVar33 = 1;
        if (*(char *)(param_1 + 0xb) != '\0') goto _L415;
        uVar13 = r_lld_ral_search(param_1 + 3,*(undefined1 *)((int)param_1 + 0x15));
        if (9 < uVar13) goto _L312;
        uVar33 = 1;
        uVar13 = uVar13 * 0x34 + 0xc60 & 0xffff;
      }
      bVar23 = *(byte *)(param_1 + 10);
      uVar19 = (uint)bVar1 * 9 & 0xff;
      *(bool *)((int)__s + 0x4a) = uVar13 != 0;
      sVar16 = (short)uVar19 * 0xe + 0x1400;
      piVar20 = __s + 2;
      piVar18 = __s;
      do {
        bStack_b2 = 0;
        bStack_b1 = 0;
        iVar32 = *piVar18;
        if (iVar32 != 0) {
          bVar1 = *(byte *)(iVar32 + 0x52);
          uVar29 = (uint)bVar1;
          iVar26 = uVar29 * 0x5a;
          uVar31 = *(byte *)((int)param_1 + 0x11) + 0xe & 0xff;
          r_lld_init_set_tx_power(uVar29,uVar31);
          iVar24 = __s[3];
          iVar30 = r_emi_get_mem_addr_by_offset(0x400);
          *(short *)(iVar26 + 0x22 + iVar30) = (short)iVar24;
          uVar8 = *(undefined2 *)((int)__s + 0x16);
          iVar24 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar26 + 0x38 + iVar24) = uVar8;
          iVar24 = __s[8];
          iVar30 = r_emi_get_mem_addr_by_offset(0x400);
          *(short *)(iVar26 + 0x3c + iVar30) = (short)iVar24;
          iVar24 = r_emi_get_mem_addr_by_offset(0x400);
          *(short *)(iVar26 + 0x1c + iVar24) = sVar16;
          iVar24 = r_emi_get_mem_addr_by_offset(0x400);
          *(short *)(iVar26 + 0x34 + iVar24) = sVar16;
          r_bt_rma_get_ant_by_act(uVar31,uVar29,&bStack_b2,&bStack_b1);
          uVar28 = (uint)bStack_b2;
          uVar17 = (uint)bStack_b1;
          uVar21 = (uint)(byte)r_bt_rf_coex_st_param_get;
          bVar3 = (byte)r_bt_rf_coex_st_param_get >> 2;
          if ((uVar28 << 8 & 0xfffffeff) != 0) {
            r_assert_err(0,0x10000,0x41);
          }
          if ((uVar17 << 7 & 0xffffff7f) != 0) {
            r_assert_err(0,0x10000,0x42);
          }
          iVar24 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar24 + iVar26) =
               (ushort)(uVar28 << 8) | (ushort)(uVar17 << 7) | (ushort)((uVar21 & 1) << 10) |
               (ushort)((uVar21 & 2) << 8) | (ushort)((bVar3 & 1) << 5) | uVar31;
          iVar24 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar26 + 0xc + iVar24) = 0xbed6;
          iVar24 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar26 + 0xe + iVar24) = 0x8e89;
          iVar24 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar26 + 0x10 + iVar24) = 0x5555;
          iVar24 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar26 + 0x12 + iVar24) = 0x55;
          iVar24 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar26 + 0x46 + iVar24) = 0;
          bVar3 = *(byte *)(param_1 + 0xb);
          bVar4 = *(byte *)(param_1 + 0x1e);
          bVar5 = *(byte *)((int)__s + 0x4a);
          iVar24 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar26 + 0x14 + iVar24) =
               (ushort)((bVar23 & 2) << 1) | (ushort)bVar3 << 8 | (ushort)bVar4 << 6 |
               (ushort)bVar5 << 1 | uVar33;
          if (*(char *)((int)__s + 0x4a) != '\0') {
            iVar24 = r_emi_get_mem_addr_by_offset(0x400);
            *(short *)(iVar26 + 0x2c + iVar24) = (short)uVar13;
          }
          if ((*(char *)(param_1 + 0xb) == '\0') && (*(char *)((int)__s + 0x4a) == '\0')) {
            puVar22 = (undefined1 *)((int)param_1 + 7);
            iVar24 = 0;
            do {
              uVar6 = *puVar22;
              uVar7 = puVar22[-1];
              iVar30 = r_emi_get_mem_addr_by_offset(0x400);
              *(ushort *)(iVar30 + iVar26 + 0x2c + iVar24) = CONCAT11(uVar6,uVar7);
              iVar24 = iVar24 + 2;
              puVar22 = puVar22 + 2;
            } while (iVar24 != 6);
            bVar3 = *(byte *)((int)param_1 + 0x15);
            iVar24 = r_emi_get_mem_addr_by_offset(0x400);
            *(ushort *)(iVar26 + 0x32 + iVar24) = bVar3 & 1;
          }
          iVar24 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar26 + 0x16 + iVar24) = 0x8027;
          iVar24 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar26 + 0x28 + iVar24) = 0;
          iVar24 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar26 + 0x2a + iVar24) = 0;
          bVar3 = *(byte *)(param_1 + 10);
          if ((bVar1 & 0xe0) != 0) {
            r_assert_err(0,0x10000,0xe6);
          }
          iVar24 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar26 + 2 + iVar24) = (ushort)((bVar3 & 1) << 7) | (ushort)bVar1 | 0x800;
          uVar8 = *param_1;
          iVar24 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar26 + 6 + iVar24) = uVar8;
          uVar8 = param_1[1];
          iVar24 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar26 + 8 + iVar24) = uVar8;
          uVar8 = param_1[2];
          iVar24 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar26 + 10 + iVar24) = uVar8;
          bVar1 = *(byte *)(iVar32 + 0x30);
          if (((uint)bVar1 << 2 & 0xfffffff3) != 0) {
            r_assert_err(0,0x10000,399);
          }
          if ((bVar1 & 0xfc) != 0) {
            r_assert_err(0,0x10000,400);
          }
          iVar24 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar26 + 4 + iVar24) = (ushort)((uint)bVar1 << 2) | (ushort)bVar1 | 0x2000;
          uVar8 = *(undefined2 *)(iVar32 + 0x24);
          iVar24 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar26 + 0x20 + iVar24) = uVar8;
          uVar17 = *(uint *)(iVar32 + 0x24);
          if ((uVar17 >> 0xf & 1) != 0) {
            r_assert_err(0,0x10000,0x4ab);
          }
          iVar32 = r_emi_get_mem_addr_by_offset(0x400);
          bVar1 = *(byte *)((int)param_1 + 0x11);
          *(ushort *)(iVar26 + 0x1a + iVar32) = (ushort)uVar17 | 0x8000;
          pbVar15 = (byte *)r_bt_rf_coex_st_param_get(bVar1 + 9);
          if (pbVar15 != (byte *)0x0) {
            bVar1 = pbVar15[1];
            if (0xb < uVar29) {
              r_assert_err(0,0x10000,0x299b);
            }
            if (((uint)bVar1 << 8 & 0xf000) != 0) {
              r_assert_err(0,0x10000,0x299d);
            }
            puVar27 = (uint *)((uVar29 + 0x1800c4cb) * 4);
            *puVar27 = *puVar27 & 0xfffff0ff | (uint)bVar1 << 8;
            bVar1 = *pbVar15;
            if (0xb < uVar29) {
              r_assert_err(0,0x10000,0x294a);
            }
            *puVar27 = (uint)bVar1 << 0x1e | *puVar27 & 0xbfffffff;
            bVar1 = pbVar15[3];
            if (0xb < uVar29) {
              r_assert_err(0,0x10000,0x29bb);
            }
            if ((bVar1 & 0xf0) != 0) {
              r_assert_err(0,0x10000,0x29bd);
            }
            *puVar27 = *puVar27 & 0xfffffff0 | (uint)bVar1;
            bVar1 = pbVar15[2];
            if (0xb < uVar29) {
              r_assert_err(0,0x10000,0x295a);
            }
            *puVar27 = (uint)bVar1 << 0x1d | *puVar27 & 0xdfffffff;
            bVar1 = pbVar15[7];
            if (0xb < uVar29) {
              r_assert_err(0,0x10000,0x298b);
            }
            if (((uint)bVar1 << 0xc & 0xf0000) != 0) {
              r_assert_err(0,0x10000,0x298d);
            }
            *puVar27 = *puVar27 & 0xffff0fff | (uint)bVar1 << 0xc;
            bVar1 = pbVar15[8];
            if (0xb < uVar29) {
              r_assert_err(0,0x10000,0x29ab);
            }
            if (((uint)bVar1 << 4 & 0xffffff0f) != 0) {
              r_assert_err(0,0x10000,0x29ad);
            }
            *puVar27 = *puVar27 & 0xffffff0f | (uint)bVar1 << 4;
            bVar1 = pbVar15[9];
            if (0xb < uVar29) {
              r_assert_err(0,0x10000,0x297b);
            }
            if (((uint)bVar1 << 0x10 & 0xf00000) != 0) {
              r_assert_err(0,0x10000,0x297d);
            }
            *puVar27 = *puVar27 & 0xfff0ffff | (uint)bVar1 << 0x10;
            uVar31 = *(ushort *)(pbVar15 + 10);
            if (0xb < uVar29) {
              r_assert_err(0,0x10000,0x296a);
            }
            if (((uint)uVar31 << 0x14 & 0xe0000000) != 0) {
              r_assert_err(0,0x10000,0x296c);
            }
            *puVar27 = *puVar27 & 0xe00fffff | (uint)uVar31 << 0x14;
            bVar1 = pbVar15[6];
            if (0xb < uVar29) {
              r_assert_err(0,0x10000,0x293a);
            }
            *puVar27 = *puVar27 & 0x7fffffff | (uint)bVar1 << 0x1f;
            if (2 < _g_bt_plf_log_level) {
              ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[INITIATOR] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                         ,uVar29,puVar27,pbVar15[2],pbVar15[3],*pbVar15,pbVar15[1],pbVar15[6]);
            }
          }
        }
        piVar18 = piVar18 + 1;
      } while (piVar20 != piVar18);
      iVar32 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar24 = uVar19 * 0xe;
      iVar30 = iVar24 + 2;
      uVar33 = *(ushort *)(iVar32 + iVar30);
      iVar32 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar32 + iVar30) = uVar33 & 0xfff0 | 5;
      iVar32 = r_emi_get_mem_addr_by_offset(0x1400);
      *(undefined2 *)(iVar24 + 4 + iVar32) = 0x7400;
      iVar32 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar33 = *(ushort *)(iVar32 + iVar30);
      iVar32 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar32 + iVar30) = uVar33 & 0xff | 0x2200;
      iVar32 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar33 = *(ushort *)(iVar32 + iVar24);
      iVar32 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar32 + iVar24) = uVar33 & 0x8000;
      bVar1 = *(byte *)((int)param_1 + 0x15);
      iVar32 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar30 + iVar32) = (ushort)((bVar1 & 1) << 7) | 0x2225;
      iVar32 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar33 = *(ushort *)(iVar32 + iVar24);
      iVar32 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar32 + iVar24) = (ushort)(((uint)uVar33 << 0x11) >> 0x11);
      iVar32 = r_bt_rf_coex_st_param_get(*(byte *)((int)param_1 + 0x11) + 9);
      if (iVar32 != 0) {
        if (2 < _g_bt_plf_log_level) {
          ets_printf("TX PTI [Initiator] [EN%d] [%d] \n",*(undefined1 *)(iVar32 + 4),
                     *(undefined1 *)(iVar32 + 5));
        }
        uVar13 = (uint)*(byte *)(iVar32 + 5) << 8;
        if ((uVar13 & 0xf000) != 0) {
          r_assert_err(0,0x10000,0x33f);
        }
        iVar30 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar24 = iVar24 + 10;
        uVar33 = *(ushort *)(iVar30 + iVar24);
        iVar30 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar30 + iVar24) = uVar33 & 0xf0ff | (ushort)uVar13;
        bVar1 = *(byte *)(iVar32 + 4);
        iVar32 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar33 = *(ushort *)(iVar32 + iVar24);
        iVar32 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar24 + iVar32) = uVar33 & 0xefff | (ushort)bVar1 << 0xc;
      }
      __s[2] = 0;
      uVar25 = 0xc;
      do {
        iVar32 = *__s;
        if (iVar32 != 0) {
          *(uint *)(iVar32 + 4) = uVar12;
          *(uint *)(iVar32 + 0x28) = uVar12;
          iVar24 = r_sch_arb_insert(iVar32);
          if (iVar24 == 0) {
            *(undefined1 *)(iVar32 + 0x50) = 0;
            uVar12 = (uint)*(ushort *)(iVar32 + 0x2e) * 2 + uVar12 & 0xfffffff;
          }
          else {
            r_assert_err(0,0x10000,0x839);
          }
          bVar1 = *(byte *)(iVar32 + 0x52);
          iVar24 = r_emi_get_mem_addr_by_offset(0x400);
          uVar8 = *(undefined2 *)((uint)bVar1 * 0x5a + 0x14 + iVar24);
          bVar1 = *(byte *)(iVar32 + 0x52);
          iVar24 = r_emi_get_mem_addr_by_offset(0x400);
          uVar25 = 0;
          r_ble_log_internal_x2
                    (0x40010102,CONCAT22(*(undefined2 *)((uint)bVar1 * 0x5a + 0x2c + iVar24),uVar8),
                     *(undefined1 *)(iVar32 + 0x52));
        }
        __s = __s + 1;
      } while (__s != piVar20);
      goto _L300;
    }
    r_assert_err(0x10000,0x843);
  }
  uVar25 = 0xc;
_L300:
  r_lld_init_start_hook_part_0(param_1);
  return uVar25;
}

