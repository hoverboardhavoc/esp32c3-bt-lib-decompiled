/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
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
  undefined1 uVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  undefined1 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  int *__s;
  void *pvVar15;
  byte *pbVar16;
  uint uVar17;
  short sVar18;
  int *piVar19;
  uint uVar20;
  int *piVar21;
  uint uVar22;
  undefined1 *puVar23;
  byte bVar24;
  int iVar25;
  int iVar26;
  uint *puVar27;
  int iVar28;
  uint uVar29;
  uint uVar30;
  int iVar31;
  ushort uVar32;
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
  uVar13 = r_lld_read_clock();
  uVar14 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  if (_lld_init_env == (int *)0x0) {
    __s = (int *)r_ke_malloc(0x5c,0);
    _lld_init_env = __s;
    if (__s != (int *)0x0) {
      uVar14 = uVar14 & 0xffffff;
      memset(__s,0,0x5c);
      *(undefined1 *)(__s + 0xb) = *(undefined1 *)((int)param_1 + 0x13);
      *(undefined1 *)((int)__s + 0x32) = *(undefined1 *)(param_1 + 10);
      *(undefined1 *)((int)__s + 0x33) = *(undefined1 *)((int)param_1 + 0x15);
      uVar2 = *(undefined1 *)(param_1 + 0xb);
      *(undefined1 *)(__s + 0x14) = 0;
      *(undefined1 *)(__s + 0x16) = 0;
      *(undefined1 *)((int)__s + 0x4f) = uVar2;
      memcpy((void *)((int)__s + 0x3e),param_1,6);
      memcpy(__s + 0x11,param_1 + 3,6);
      memcpy((void *)((int)__s + 0x2d),param_1 + 6,5);
      r_lld_aa_gen(__s + 0xd,*(undefined1 *)((int)param_1 + 0x13));
      *(char *)((int)__s + 0x3a) = (char)(uVar14 >> 0x10);
      *(short *)(__s + 0xe) = (short)uVar14;
      iVar28 = _p_lld_env;
      *(undefined1 *)((int)__s + 0x3b) = 2;
      bVar24 = (char)(uVar14 % 0xc) + 5;
      *(byte *)(__s + 0xf) = bVar24;
      cVar3 = *(char *)(iVar28 + 0xd6);
      *(char *)((int)__s + 0x3d) = cVar3;
      memcpy(auStack_b0,__s + 0xd,4);
      memcpy(auStack_ac,__s + 0xe,3);
      uStack_a9 = 2;
      uStack_a8 = 0;
      memcpy(auStack_a0,param_1 + 6,5);
      uVar8 = param_1[0xe];
      uVar9 = param_1[0xf];
      uVar10 = param_1[0x10];
      uVar11 = param_1[0x11];
      bStack_9b = cVar3 << 5 | bVar24;
      piVar19 = __s + 3;
      do {
        *(undefined2 *)piVar19 = uVar8;
        *(undefined2 *)((int)piVar19 + 2) = uVar9;
        *(undefined2 *)(piVar19 + 1) = uVar10;
        *(undefined2 *)((int)piVar19 + 6) = uVar11;
        *(undefined1 *)(piVar19 + 2) = 0;
        piVar19 = (int *)((int)piVar19 + 10);
      } while ((int *)((int)__s + 0x2a) != piVar19);
      iVar28 = 0;
      if ((*(byte *)(param_1 + 9) & 1) != 0) {
        pvVar15 = (void *)r_ke_malloc(0x54,0);
        *__s = (int)pvVar15;
        if (pvVar15 == (void *)0x0) {
          r_assert_err("lld_init.c",0x6d3);
        }
        else {
          memset(pvVar15,0,0x54);
          *(code **)((int)pvVar15 + 0x20) = r_lld_init_evt_canceled_cbk;
          *(code **)((int)pvVar15 + 0x18) = r_lld_init_evt_start_cbk;
          uVar2 = DAT_00013042;
          *(undefined4 *)((int)pvVar15 + 0x1c) = 0;
          *(undefined4 *)((int)pvVar15 + 8) = 0;
          *(undefined1 *)((int)pvVar15 + 0x16) = uVar2;
          uVar33 = param_1[0xd];
          uVar14 = (uint)uVar33 * 0x4e2;
          if (_sch_slice_params < uVar14) {
            uVar14 = (uint)_sch_slice_params;
          }
          *(uint *)((int)pvVar15 + 0x10) = uVar14;
          iVar28 = 1;
          *(ushort *)((int)pvVar15 + 0x14) = DAT_00013043 & 0xf | 0x6000;
          uVar8 = param_1[0xc];
          *(undefined1 *)((int)pvVar15 + 0x30) = 0;
          *(undefined1 *)((int)pvVar15 + 0x51) = 0;
          *(undefined2 *)((int)pvVar15 + 0x2c) = uVar8;
          *(undefined2 *)((int)pvVar15 + 0x3c) = 0x7f;
          *(undefined1 *)((int)pvVar15 + 0x3e) = 1;
          *(ushort *)((int)pvVar15 + 0x2e) = uVar33;
          *(uint *)((int)pvVar15 + 0x24) = (uint)uVar33;
          *(undefined1 *)((int)pvVar15 + 0x52) = *(undefined1 *)((int)param_1 + 0x13);
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
      pvVar15 = (void *)r_emi_get_mem_addr_by_offset(0x7400);
      memcpy(pvVar15,auStack_98,0x16);
      if ((*(byte *)(param_1 + 9) & 2) != 0) {
        *(undefined2 *)((int)__s + 0x16) = param_1[iVar28 * 6 + 0xe];
        *(undefined2 *)(__s + 6) = param_1[iVar28 * 6 + 0xf];
        uVar8 = param_1[iVar28 * 6 + 0x10];
        uVar9 = param_1[iVar28 * 6 + 0x11];
        *(char *)((int)__s + 0x1e) = (char)iVar28;
        iVar28 = iVar28 + 1;
        *(undefined2 *)((int)__s + 0x1a) = uVar8;
        *(undefined2 *)(__s + 7) = uVar9;
      }
      uStack_a6 = *(undefined2 *)((int)__s + 0x16);
      uStack_a4 = *(undefined2 *)((int)__s + 0x1a);
      uStack_a2 = (undefined2)__s[7];
      r_lld_init_connect_req_pack(auStack_98,auStack_b0);
      pvVar15 = (void *)r_emi_get_mem_addr_by_offset(0x7422);
      memcpy(pvVar15,auStack_98,0x16);
      if ((*(byte *)(param_1 + 9) & 4) != 0) {
        pvVar15 = (void *)r_ke_malloc(0x54,0);
        __s[1] = (int)pvVar15;
        if (pvVar15 == (void *)0x0) {
          r_assert_err("lld_init.c",0x734);
        }
        else {
          memset(pvVar15,0,0x54);
          *(code **)((int)pvVar15 + 0x20) = r_lld_init_evt_canceled_cbk;
          *(code **)((int)pvVar15 + 0x18) = r_lld_init_evt_start_cbk;
          uVar2 = DAT_00013042;
          *(undefined4 *)((int)pvVar15 + 0x1c) = 0;
          *(undefined1 *)((int)pvVar15 + 0x16) = uVar2;
          uVar33 = param_1[iVar28 * 6 + 0xd];
          uVar14 = (uint)uVar33 * 0x4e2;
          if (_sch_slice_params < uVar14) {
            uVar14 = (uint)_sch_slice_params;
          }
          *(uint *)((int)pvVar15 + 0x10) = uVar14;
          *(ushort *)((int)pvVar15 + 0x14) = DAT_00013043 & 0xf | 0x6000;
          uVar8 = param_1[iVar28 * 6 + 0xc];
          *(ushort *)((int)pvVar15 + 0x2e) = uVar33;
          *(uint *)((int)pvVar15 + 0x24) = (uint)uVar33;
          *(undefined2 *)((int)pvVar15 + 0x2c) = uVar8;
          *(undefined1 *)((int)pvVar15 + 0x51) = 1;
          *(undefined2 *)((int)pvVar15 + 0x30) = 3;
          *(undefined1 *)((int)pvVar15 + 0x3e) = 1;
          *(undefined2 *)((int)pvVar15 + 0x3c) = 0x7f;
          *(undefined1 *)((int)pvVar15 + 0x52) = 10;
          *(undefined2 *)(__s + 8) = param_1[iVar28 * 6 + 0xe];
          *(undefined2 *)((int)__s + 0x22) = param_1[iVar28 * 6 + 0xf];
          uVar8 = param_1[iVar28 * 6 + 0x10];
          uVar9 = param_1[iVar28 * 6 + 0x11];
          *(char *)(__s + 10) = (char)iVar28;
          *(undefined2 *)(__s + 9) = uVar8;
          *(undefined2 *)((int)__s + 0x26) = uVar9;
          *(byte *)((int)__s + 0x2b) = *(byte *)((int)__s + 0x2b) | 2;
        }
      }
      uStack_a6 = (undefined2)__s[8];
      uStack_a4 = (undefined2)__s[9];
      uStack_a2 = *(undefined2 *)((int)__s + 0x26);
      r_lld_init_connect_req_pack(auStack_98,auStack_b0);
      pvVar15 = (void *)r_emi_get_mem_addr_by_offset(0x7444);
      memcpy(pvVar15,auStack_98,0x16);
      *(undefined1 *)((int)__s + 0x2a) = *(undefined1 *)((int)param_1 + 0x11);
      if (((*(byte *)(param_1 + 10) & 2) == 0) && (*(char *)(param_1 + 0x1e) == '\0')) {
_L327:
        uVar33 = 0;
_L434:
        uVar14 = 0;
      }
      else {
        uVar33 = 1;
        if (*(char *)(param_1 + 0xb) != '\0') goto _L434;
        uVar14 = r_lld_ral_search(param_1 + 3,*(undefined1 *)((int)param_1 + 0x15));
        if (9 < uVar14) goto _L327;
        uVar33 = 1;
        uVar14 = uVar14 * 0x34 + 0xc60 & 0xffff;
      }
      uVar20 = (uint)bVar1 * 9 & 0xff;
      bVar1 = *(byte *)(param_1 + 10);
      *(bool *)((int)__s + 0x4a) = uVar14 != 0;
      piVar21 = __s + 2;
      sVar18 = (short)uVar20 * 0xe + 0x1400;
      piVar19 = __s;
      do {
        bStack_b2 = 0;
        bStack_b1 = 0;
        iVar28 = *piVar19;
        if (iVar28 != 0) {
          bVar24 = *(byte *)(iVar28 + 0x52);
          uVar30 = (uint)bVar24;
          iVar26 = uVar30 * 0x5a;
          uVar32 = (*(char *)((int)param_1 + 0x11) != '\0') + 0xe;
          r_lld_init_set_tx_power(uVar30,uVar32);
          iVar25 = __s[3];
          iVar31 = r_emi_get_mem_addr_by_offset(0x400);
          *(short *)(iVar31 + iVar26 + 0x22) = (short)iVar25;
          uVar8 = *(undefined2 *)((int)__s + 0x16);
          iVar25 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar25 + iVar26 + 0x38) = uVar8;
          iVar25 = __s[8];
          iVar31 = r_emi_get_mem_addr_by_offset(0x400);
          *(short *)(iVar31 + iVar26 + 0x3c) = (short)iVar25;
          iVar25 = r_emi_get_mem_addr_by_offset(0x400);
          *(short *)(iVar25 + iVar26 + 0x1c) = sVar18;
          iVar25 = r_emi_get_mem_addr_by_offset(0x400);
          *(short *)(iVar25 + iVar26 + 0x34) = sVar18;
          r_bt_rma_get_ant_by_act(uVar32,uVar30,&bStack_b2,&bStack_b1);
          uVar17 = (uint)bStack_b1;
          uVar22 = (uint)(byte)r_bt_rf_coex_st_param_get;
          bVar4 = (byte)r_bt_rf_coex_st_param_get >> 2;
          uVar29 = (uint)bStack_b2;
          if ((uVar29 << 8 & 0xfffffeff) != 0) {
            r_assert_err(0,"lld_init.c",0x41);
          }
          if ((uVar17 << 7 & 0xffffff7f) != 0) {
            r_assert_err(0,"lld_init.c",0x42);
          }
          iVar25 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar25 + iVar26) =
               (ushort)(uVar29 << 8) | (ushort)(uVar17 << 7) | (ushort)((uVar22 & 1) << 10) |
               (ushort)((uVar22 & 2) << 8) | (ushort)((bVar4 & 1) << 5) | uVar32;
          iVar25 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar25 + iVar26 + 0xc) = 0xbed6;
          iVar25 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar25 + iVar26 + 0xe) = 0x8e89;
          iVar25 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar25 + iVar26 + 0x10) = 0x5555;
          iVar25 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar25 + iVar26 + 0x12) = 0x55;
          iVar25 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar25 + iVar26 + 0x46) = 0;
          bVar4 = *(byte *)(param_1 + 0xb);
          bVar5 = *(byte *)(param_1 + 0x1e);
          bVar6 = *(byte *)((int)__s + 0x4a);
          iVar25 = r_emi_get_mem_addr_by_offset(0x400);
          cVar3 = *(char *)((int)__s + 0x4a);
          *(ushort *)(iVar25 + iVar26 + 0x14) =
               (ushort)(((bVar1 & 2) << 0x11) >> 0x10) | (ushort)bVar4 << 8 | (ushort)bVar5 << 6 |
               (ushort)bVar6 << 1 | uVar33;
          if (cVar3 != '\0') {
            iVar25 = r_emi_get_mem_addr_by_offset(0x400);
            *(short *)(iVar25 + iVar26 + 0x2c) = (short)uVar14;
          }
          if ((*(char *)(param_1 + 0xb) == '\0') && (*(char *)((int)__s + 0x4a) == '\0')) {
            puVar23 = (undefined1 *)((int)param_1 + 7);
            iVar25 = 0;
            do {
              uVar2 = *puVar23;
              uVar7 = puVar23[-1];
              iVar31 = r_emi_get_mem_addr_by_offset(0x400);
              *(ushort *)(iVar31 + iVar26 + 0x2c + iVar25) = CONCAT11(uVar2,uVar7);
              iVar25 = iVar25 + 2;
              puVar23 = puVar23 + 2;
            } while (iVar25 != 6);
            bVar4 = *(byte *)((int)param_1 + 0x15);
            iVar25 = r_emi_get_mem_addr_by_offset(0x400);
            *(ushort *)(iVar25 + iVar26 + 0x32) = bVar4 & 1;
          }
          iVar25 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar25 + iVar26 + 0x16) = 0x8027;
          iVar25 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar25 + iVar26 + 0x28) = 0;
          iVar25 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar25 + iVar26 + 0x2a) = 0;
          bVar4 = *(byte *)(param_1 + 10);
          if ((bVar24 & 0xe0) != 0) {
            r_assert_err(0,"lld_init.c",0xe6);
          }
          iVar25 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar25 + iVar26 + 2) = (ushort)((bVar4 & 1) << 7) | (ushort)bVar24 | 0x800;
          uVar8 = *param_1;
          iVar25 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar25 + iVar26 + 6) = uVar8;
          uVar8 = param_1[1];
          iVar25 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar25 + iVar26 + 8) = uVar8;
          uVar8 = param_1[2];
          iVar25 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar25 + iVar26 + 10) = uVar8;
          bVar24 = *(byte *)(iVar28 + 0x30);
          if (((uint)bVar24 << 2 & 0xfffffff3) != 0) {
            r_assert_err(0,"lld_init.c",399);
          }
          if ((bVar24 & 0xfc) != 0) {
            r_assert_err(0,"lld_init.c",400);
          }
          iVar25 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar25 + iVar26 + 4) = (ushort)((uint)bVar24 << 2) | (ushort)bVar24 | 0x2000;
          uVar8 = *(undefined2 *)(iVar28 + 0x24);
          iVar25 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar25 + iVar26 + 0x20) = uVar8;
          iVar28 = *(int *)(iVar28 + 0x24);
          if (iVar28 << 0x10 < 0) {
            r_assert_err(0,"lld_init.c",0x4ab);
          }
          iVar25 = r_emi_get_mem_addr_by_offset(0x400);
          cVar3 = *(char *)((int)param_1 + 0x11);
          *(ushort *)(iVar26 + 0x1a + iVar25) = (ushort)iVar28 | 0x8000;
          pbVar16 = (byte *)r_bt_rf_coex_st_param_get((cVar3 != '\0') + '\t');
          if (pbVar16 != (byte *)0x0) {
            bVar24 = pbVar16[1];
            if (0xb < uVar30) {
              r_assert_err(0,"lld_init.c",0x299b);
            }
            if (((uint)bVar24 << 8 & 0xf000) != 0) {
              r_assert_err(0,"lld_init.c",0x299d);
            }
            puVar27 = (uint *)((uVar30 + 0x1800c4cb) * 4);
            *puVar27 = *puVar27 & 0xfffff0ff | (uint)bVar24 << 8;
            bVar24 = *pbVar16;
            if (0xb < uVar30) {
              r_assert_err(0,"lld_init.c",0x294a);
            }
            *puVar27 = (uint)bVar24 << 0x1e | *puVar27 & 0xbfffffff;
            bVar24 = pbVar16[3];
            if (0xb < uVar30) {
              r_assert_err(0,"lld_init.c",0x29bb);
            }
            if ((bVar24 & 0xf0) != 0) {
              r_assert_err(0,"lld_init.c",0x29bd);
            }
            *puVar27 = *puVar27 & 0xfffffff0 | (uint)bVar24;
            bVar24 = pbVar16[2];
            if (0xb < uVar30) {
              r_assert_err(0,"lld_init.c",0x295a);
            }
            *puVar27 = (uint)bVar24 << 0x1d | *puVar27 & 0xdfffffff;
            bVar24 = pbVar16[7];
            if (0xb < uVar30) {
              r_assert_err(0,"lld_init.c",0x298b);
            }
            if (((uint)bVar24 << 0xc & 0xf0000) != 0) {
              r_assert_err(0,"lld_init.c",0x298d);
            }
            *puVar27 = *puVar27 & 0xffff0fff | (uint)bVar24 << 0xc;
            bVar24 = pbVar16[8];
            if (0xb < uVar30) {
              r_assert_err(0,"lld_init.c",0x29ab);
            }
            if (((uint)bVar24 << 4 & 0xffffff0f) != 0) {
              r_assert_err(0,"lld_init.c",0x29ad);
            }
            *puVar27 = *puVar27 & 0xffffff0f | (uint)bVar24 << 4;
            bVar24 = pbVar16[9];
            if (0xb < uVar30) {
              r_assert_err(0,"lld_init.c",0x297b);
            }
            if (((uint)bVar24 << 0x10 & 0xf00000) != 0) {
              r_assert_err(0,"lld_init.c",0x297d);
            }
            *puVar27 = *puVar27 & 0xfff0ffff | (uint)bVar24 << 0x10;
            uVar32 = *(ushort *)(pbVar16 + 10);
            if (0xb < uVar30) {
              r_assert_err(0,"lld_init.c",0x296a);
            }
            if (((uint)uVar32 << 0x14 & 0xe0000000) != 0) {
              r_assert_err(0,"lld_init.c",0x296c);
            }
            *puVar27 = *puVar27 & 0xe00fffff | (uint)uVar32 << 0x14;
            bVar24 = pbVar16[6];
            if (0xb < uVar30) {
              r_assert_err(0,"lld_init.c",0x293a);
            }
            *puVar27 = *puVar27 & 0x7fffffff | (uint)bVar24 << 0x1f;
            if (2 < _g_bt_plf_log_level) {
              ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[INITIATOR] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                         ,uVar30,puVar27,pbVar16[2],pbVar16[3],*pbVar16,pbVar16[1],pbVar16[6]);
            }
          }
        }
        piVar19 = piVar19 + 1;
      } while (piVar21 != piVar19);
      iVar28 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar25 = uVar20 * 0xe;
      iVar31 = iVar25 + 2;
      uVar33 = *(ushort *)(iVar28 + iVar31);
      iVar28 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar28 + iVar31) = uVar33 & 0xfff0 | 5;
      iVar28 = r_emi_get_mem_addr_by_offset(0x1400);
      *(undefined2 *)(iVar28 + iVar25 + 4) = 0x7400;
      iVar28 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar33 = *(ushort *)(iVar28 + iVar31);
      iVar28 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar28 + iVar31) = uVar33 & 0xff | 0x2200;
      iVar28 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar33 = *(ushort *)(iVar28 + iVar25);
      iVar28 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar28 + iVar25) = uVar33 & 0x8000;
      bVar1 = *(byte *)((int)param_1 + 0x15);
      iVar28 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar28 + iVar31) = (ushort)((bVar1 & 1) << 7) | 0x2225;
      iVar28 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar33 = *(ushort *)(iVar28 + iVar25);
      iVar28 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar28 + iVar25) = uVar33 & 0x7fff;
      iVar28 = r_bt_rf_coex_st_param_get((*(char *)((int)param_1 + 0x11) != '\0') + '\t');
      if (iVar28 != 0) {
        if (2 < _g_bt_plf_log_level) {
          ets_printf("TX PTI [Initiator] [EN%d] [%d] \n",*(undefined1 *)(iVar28 + 4),
                     *(undefined1 *)(iVar28 + 5));
        }
        uVar14 = (uint)*(byte *)(iVar28 + 5) << 8;
        if ((uVar14 & 0xf000) != 0) {
          r_assert_err(0,"lld_init.c",0x33f);
        }
        iVar25 = iVar25 + 10;
        iVar31 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar33 = *(ushort *)(iVar31 + iVar25);
        iVar31 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar31 + iVar25) = uVar33 & 0xf0ff | (ushort)uVar14;
        bVar1 = *(byte *)(iVar28 + 4);
        iVar28 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar33 = *(ushort *)(iVar28 + iVar25);
        iVar28 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar28 + iVar25) = uVar33 & 0xefff | (ushort)bVar1 << 0xc;
      }
      __s[2] = 0;
      uVar12 = 0xc;
      do {
        iVar28 = *__s;
        if (iVar28 != 0) {
          *(uint *)(iVar28 + 4) = uVar13;
          *(uint *)(iVar28 + 0x28) = uVar13;
          iVar25 = r_sch_arb_insert(iVar28);
          if (iVar25 == 0) {
            *(undefined1 *)(iVar28 + 0x50) = 0;
            uVar13 = uVar13 + (uint)*(ushort *)(iVar28 + 0x2e) * 2 & 0xfffffff;
            uVar12 = 0;
          }
          else {
            r_assert_err(0,"lld_init.c",0x811);
            uVar12 = 0;
          }
        }
        __s = __s + 1;
      } while (piVar21 != __s);
      goto _L315;
    }
    r_assert_err("lld_init.c",0x819);
  }
  uVar12 = 0xc;
_L315:
  r_lld_init_start_hook_part_0(param_1);
  return uVar12;
}

