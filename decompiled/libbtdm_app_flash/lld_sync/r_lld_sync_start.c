/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_lld_sync_start(uint param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  byte bVar2;
  ushort uVar3;
  byte bVar4;
  undefined2 uVar5;
  byte bVar6;
  byte bVar7;
  ushort *puVar8;
  uint *puVar9;
  int iVar10;
  void *__s;
  byte *pbVar11;
  undefined4 uVar12;
  code *pcVar13;
  uint uVar14;
  ushort uVar15;
  uint uVar16;
  uint uVar18;
  byte bStack_3a;
  byte abStack_39 [21];
  int iVar17;
  
  iVar10 = r_sdk_config_get_opts();
  if ((param_1 < *(byte *)(iVar10 + 0xd)) && (*(int *)(&lld_sync_env + param_1 * 4) == 0)) {
    __s = (void *)r_ke_malloc(0x70,0);
    *(void **)(&lld_sync_env + param_1 * 4) = __s;
    if (__s != (void *)0x0) {
      puVar8 = (ushort *)*param_2;
      uVar1 = *(undefined1 *)((int)param_2 + 10);
      bStack_3a = 0;
      abStack_39[0] = 0;
      uVar14 = (uint)*puVar8 * ((-(uint)((char)puVar8[1] == '\0') & 0xfffffef2) + 300) * 2 +
               (uint)*(ushort *)(param_2 + 2);
      memset(__s,0,0x70);
      *(code **)((int)__s + 0x20) = r_lld_sync_evt_canceled_cbk;
      *(code **)((int)__s + 0x18) = r_lld_sync_evt_start_cbk;
      *(char *)((int)__s + 0x55) = (char)param_1;
      uVar3 = puVar8[2];
      uVar18 = (uint)uVar3 * 4;
      uVar16 = (uint)*(ushort *)((int)param_2 + 0xe) << 5;
      *(ushort *)((int)__s + 0x14) = rwip_priority & 0xf | 0x2000;
      *(uint *)((int)__s + 0x34) = uVar16;
      *(uint *)((int)__s + 0x40) = uVar18;
      memcpy((void *)((int)__s + 0x5c),puVar8 + 3,5);
      *(undefined1 *)((int)__s + 0x58) = uVar1;
      *(undefined1 *)((int)__s + 0x5a) = *(undefined1 *)((int)puVar8 + 0xb);
      *(undefined1 *)((int)__s + 0x59) = *(undefined1 *)((int)param_2 + 0xb);
      iVar10 = param_2[1];
      *(int *)((int)__s + 0x38) = iVar10;
      *(char *)((int)__s + 0x56) = (char)puVar8[1];
      iVar17 = uVar16 / uVar18 - 6;
      uVar15 = (ushort)iVar17;
      uVar16 = uVar14 / 0x271 + iVar10 + (uint)uVar3 * -4 & 0xfffffff;
      *(uint *)((int)__s + 0x44) = uVar16;
      *(uint *)((int)__s + 0x3c) = uVar16;
      uVar3 = puVar8[10];
      *(ushort *)((int)__s + 0x4a) = uVar3 - 1;
      *(ushort *)((int)__s + 0x4e) = uVar3 - 1;
      *(short *)((int)__s + 0x48) = (short)(uVar14 % 0x271);
      if (iVar17 * 0x10000 < 0) {
        uVar15 = 0;
      }
      if ((uint)*(ushort *)(param_2 + 3) < (uint)(int)(short)uVar15) {
        uVar15 = *(ushort *)(param_2 + 3);
      }
      iVar17 = param_1 * 0x5a;
      *(ushort *)((int)__s + 0x4c) = uVar15;
      uVar3 = puVar8[6];
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar17 + 0xc + iVar10) = uVar3;
      uVar3 = puVar8[7];
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar17 + 0xe + iVar10) = uVar3;
      uVar3 = puVar8[8];
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar17 + 0x10 + iVar10) = uVar3;
      uVar3 = puVar8[9];
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar17 + 0x12 + iVar10) = (ushort)(byte)uVar3;
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar17 + 0x14 + iVar10) = 0;
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar17 + 0x28 + iVar10) = 0x3e72;
      r_bt_rma_get_ant_by_act(10,param_1,&bStack_3a,abStack_39);
      bVar7 = abStack_39[0];
      bVar6 = bStack_3a;
      uVar16 = (uint)rwip_coex_cfg;
      bVar2 = rwip_coex_cfg >> 1;
      bVar4 = rwip_coex_cfg >> 2;
      if ((bStack_3a & 0xfe) != 0) {
        r_assert_err(0,0x10000,0x42);
      }
      if ((bVar7 & 0xfe) != 0) {
        r_assert_err(0,0x10000,0x43);
      }
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar10 + iVar17) =
           (ushort)bVar6 << 7 | (ushort)bVar7 << 6 | (ushort)((bVar4 & 1) << 8) |
           (ushort)((uVar16 & 1) << 10) | (ushort)((bVar2 & 1) << 9) | 0x2a;
      pbVar11 = (byte *)r_bt_rf_coex_st_param_get(7);
      if (pbVar11 != (byte *)0x0) {
        bVar2 = pbVar11[1];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x299b);
        }
        if ((bVar2 & 0xf0) != 0) {
          r_assert_err(0,0x10000,0x299d);
        }
        puVar9 = (uint *)((param_1 + 0x1800c4cb) * 4);
        *puVar9 = *puVar9 & 0xfffff0ff | (uint)bVar2 << 8;
        bVar2 = *pbVar11;
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x294a);
        }
        *puVar9 = *puVar9 & 0xbfffffff | (uint)bVar2 << 0x1e;
        bVar2 = pbVar11[3];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x29bb);
        }
        if (0xf < bVar2) {
          r_assert_err(0,0x10000,0x29bd);
        }
        *puVar9 = *puVar9 & 0xfffffff0 | (uint)bVar2;
        bVar2 = pbVar11[2];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x295a);
        }
        *puVar9 = *puVar9 & 0xdfffffff | (uint)bVar2 << 0x1d;
        bVar2 = pbVar11[7];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x298b);
        }
        if ((bVar2 & 0xf0) != 0) {
          r_assert_err(0,0x10000,0x298d);
        }
        *puVar9 = *puVar9 & 0xffff0fff | (uint)bVar2 << 0xc;
        bVar2 = pbVar11[8];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x29ab);
        }
        if ((bVar2 & 0xf0) != 0) {
          r_assert_err(0,0x10000,0x29ad);
        }
        *puVar9 = *puVar9 & 0xffffff0f | (uint)bVar2 << 4;
        bVar2 = pbVar11[9];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x297b);
        }
        if ((bVar2 & 0xf0) != 0) {
          r_assert_err(0,0x10000,0x297d);
        }
        *puVar9 = *puVar9 & 0xfff0ffff | (uint)bVar2 << 0x10;
        uVar3 = *(ushort *)(pbVar11 + 10);
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x296a);
        }
        if ((uVar3 >> 9 & 7) != 0) {
          r_assert_err(0,0x10000,0x296c);
        }
        *puVar9 = *puVar9 & 0xe00fffff | (uint)uVar3 << 0x14;
        bVar2 = pbVar11[6];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x293a);
        }
        *puVar9 = *puVar9 & 0x7fffffff | (uint)bVar2 << 0x1f;
        if (2 < _g_bt_plf_log_level) {
          ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[SYNC_SCAN]] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                     ,param_1,puVar9,pbVar11[2],pbVar11[3],*pbVar11,pbVar11[1],pbVar11[6]);
        }
      }
      uVar5 = *(undefined2 *)((int)__s + 0x5c);
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar17 + 0x22 + iVar10) = uVar5;
      uVar5 = *(undefined2 *)((int)__s + 0x5e);
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar17 + 0x24 + iVar10) = uVar5;
      bVar2 = *(byte *)((int)__s + 0x60);
      if (0x1f < bVar2) {
        r_assert_err(0,0x10000,0x64d);
      }
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      uVar3 = *(ushort *)(iVar10 + iVar17 + 0x26);
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar10 + iVar17 + 0x26) = (ushort)bVar2 | uVar3 & 0xffe0;
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar17 + 0x18 + iVar10) = 0;
      if (0x1f < param_1) {
        r_assert_err(0,0x10000,0xe6);
      }
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      pcVar13 = *(code **)(_r_osi_funcs_p + 0x14);
      *(short *)(iVar17 + 2 + iVar10) = (short)param_1;
      (*pcVar13)(pcVar13);
      r_lld_sync_sched(param_1,0);
      (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
      *(undefined1 *)((int)__s + 0x65) = 0;
      uVar12 = r_rwip_time_get();
      *(undefined4 *)((int)__s + 0x68) = uVar12;
      *(undefined4 *)((int)__s + 0x6c) = uVar12;
      return param_1;
    }
    uVar12 = 0x5b4;
  }
  else {
    uVar12 = 0x5b9;
  }
  r_assert_err(0,0x10000,uVar12);
  return param_1;
}

