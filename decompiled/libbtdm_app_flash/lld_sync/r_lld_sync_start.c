/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
  undefined2 uVar4;
  ushort *puVar5;
  uint *puVar6;
  int iVar7;
  void *__s;
  byte *pbVar8;
  undefined4 uVar9;
  uint uVar10;
  ushort uVar11;
  uint uVar12;
  uint uVar14;
  byte bStack_3a;
  byte abStack_39 [21];
  int iVar13;
  
  iVar7 = r_sdk_config_get_opts();
  if ((param_1 < *(byte *)(iVar7 + 0xd)) && (*(int *)(&lld_sync_env + param_1 * 4) == 0)) {
    __s = (void *)r_ke_malloc(0x70,0);
    *(void **)(&lld_sync_env + param_1 * 4) = __s;
    if (__s != (void *)0x0) {
      puVar5 = (ushort *)*param_2;
      iVar7 = 300;
      if ((char)puVar5[1] == '\0') {
        iVar7 = 0x1e;
      }
      uVar1 = *(undefined1 *)((int)param_2 + 10);
      bStack_3a = 0;
      abStack_39[0] = 0;
      uVar10 = (uint)*puVar5 * iVar7 * 2 + (uint)*(ushort *)(param_2 + 2);
      memset(__s,0,0x70);
      *(code **)((int)__s + 0x20) = r_lld_sync_evt_canceled_cbk;
      *(code **)((int)__s + 0x18) = r_lld_sync_evt_start_cbk;
      *(char *)((int)__s + 0x55) = (char)param_1;
      uVar3 = puVar5[2];
      uVar14 = (uint)uVar3 * 4;
      uVar12 = (uint)*(ushort *)((int)param_2 + 0xe) << 5;
      *(ushort *)((int)__s + 0x14) = rwip_priority & 0xf | 0x2000;
      *(uint *)((int)__s + 0x34) = uVar12;
      *(uint *)((int)__s + 0x40) = uVar14;
      memcpy((void *)((int)__s + 0x5c),puVar5 + 3,5);
      *(undefined1 *)((int)__s + 0x58) = uVar1;
      *(undefined1 *)((int)__s + 0x5a) = *(undefined1 *)((int)puVar5 + 0xb);
      *(undefined1 *)((int)__s + 0x59) = *(undefined1 *)((int)param_2 + 0xb);
      iVar7 = param_2[1];
      *(int *)((int)__s + 0x38) = iVar7;
      *(char *)((int)__s + 0x56) = (char)puVar5[1];
      iVar13 = uVar12 / uVar14 - 6;
      uVar11 = (ushort)iVar13;
      uVar12 = uVar10 / 0x271 + iVar7 + (uint)uVar3 * -4 & 0xfffffff;
      *(uint *)((int)__s + 0x44) = uVar12;
      *(uint *)((int)__s + 0x3c) = uVar12;
      uVar3 = puVar5[10];
      *(ushort *)((int)__s + 0x4a) = uVar3 - 1;
      *(ushort *)((int)__s + 0x4e) = uVar3 - 1;
      *(short *)((int)__s + 0x48) = (short)(uVar10 % 0x271);
      if (iVar13 * 0x10000 < 0) {
        uVar11 = 0;
      }
      if ((uint)*(ushort *)(param_2 + 3) < (uint)(int)(short)uVar11) {
        uVar11 = *(ushort *)(param_2 + 3);
      }
      iVar13 = param_1 * 0x5a;
      *(ushort *)((int)__s + 0x4c) = uVar11;
      uVar3 = puVar5[6];
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar13 + 0xc + iVar7) = uVar3;
      uVar3 = puVar5[7];
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar13 + 0xe + iVar7) = uVar3;
      uVar3 = puVar5[8];
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar13 + 0x10 + iVar7) = uVar3;
      uVar3 = puVar5[9];
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar13 + 0x12 + iVar7) = (ushort)(byte)uVar3;
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar13 + 0x14 + iVar7) = 0;
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar13 + 0x28 + iVar7) = 0x3e72;
      r_bt_rma_get_ant_by_act(10,param_1,&bStack_3a,abStack_39);
      uVar10 = (uint)rwip_coex_cfg;
      uVar12 = (uint)bStack_3a;
      uVar14 = (uint)abStack_39[0];
      if ((uVar12 << 7 & 0xffffff7f) != 0) {
        r_assert_err(0,0x10000,0x42);
      }
      if ((uVar14 << 6 & 0xffffffbf) != 0) {
        r_assert_err(0,0x10000,0x43);
      }
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar7 + iVar13) =
           (ushort)(uVar12 << 7) | (ushort)(uVar14 << 6) | (ushort)((uVar10 & 4) << 6) |
           (ushort)((uVar10 & 1) << 10) | (ushort)((uVar10 & 2) << 8) | 0x2a;
      pbVar8 = (byte *)r_bt_rf_coex_st_param_get(7);
      if (pbVar8 != (byte *)0x0) {
        bVar2 = pbVar8[1];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x299b);
        }
        if (((uint)bVar2 << 8 & 0xf000) != 0) {
          r_assert_err(0,0x10000,0x299d);
        }
        puVar6 = (uint *)((param_1 + 0x1800c4cb) * 4);
        *puVar6 = *puVar6 & 0xfffff0ff | (uint)bVar2 << 8;
        bVar2 = *pbVar8;
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x294a);
        }
        *puVar6 = (uint)bVar2 << 0x1e | *puVar6 & 0xbfffffff;
        bVar2 = pbVar8[3];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x29bb);
        }
        if ((bVar2 & 0xf0) != 0) {
          r_assert_err(0,0x10000,0x29bd);
        }
        *puVar6 = *puVar6 & 0xfffffff0 | (uint)bVar2;
        bVar2 = pbVar8[2];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x295a);
        }
        *puVar6 = (uint)bVar2 << 0x1d | *puVar6 & 0xdfffffff;
        bVar2 = pbVar8[7];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x298b);
        }
        if (((uint)bVar2 << 0xc & 0xf0000) != 0) {
          r_assert_err(0,0x10000,0x298d);
        }
        *puVar6 = *puVar6 & 0xffff0fff | (uint)bVar2 << 0xc;
        bVar2 = pbVar8[8];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x29ab);
        }
        if (((uint)bVar2 << 4 & 0xffffff0f) != 0) {
          r_assert_err(0,0x10000,0x29ad);
        }
        *puVar6 = *puVar6 & 0xffffff0f | (uint)bVar2 << 4;
        bVar2 = pbVar8[9];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x297b);
        }
        if (((uint)bVar2 << 0x10 & 0xf00000) != 0) {
          r_assert_err(0,0x10000,0x297d);
        }
        *puVar6 = *puVar6 & 0xfff0ffff | (uint)bVar2 << 0x10;
        uVar3 = *(ushort *)(pbVar8 + 10);
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x296a);
        }
        if (((uint)uVar3 << 0x14 & 0xe0000000) != 0) {
          r_assert_err(0,0x10000,0x296c);
        }
        *puVar6 = *puVar6 & 0xe00fffff | (uint)uVar3 << 0x14;
        bVar2 = pbVar8[6];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x293a);
        }
        *puVar6 = *puVar6 & 0x7fffffff | (uint)bVar2 << 0x1f;
        if (2 < _g_bt_plf_log_level) {
          ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[SYNC_SCAN]] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                     ,param_1,puVar6,pbVar8[2],pbVar8[3],*pbVar8,pbVar8[1],pbVar8[6]);
        }
      }
      uVar4 = *(undefined2 *)((int)__s + 0x5c);
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar13 + 0x22 + iVar7) = uVar4;
      uVar4 = *(undefined2 *)((int)__s + 0x5e);
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar13 + 0x24 + iVar7) = uVar4;
      bVar2 = *(byte *)((int)__s + 0x60);
      if ((bVar2 & 0xe0) != 0) {
        r_assert_err(0,0x10000,0x64d);
      }
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      uVar3 = *(ushort *)(iVar7 + iVar13 + 0x26);
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar7 + iVar13 + 0x26) = uVar3 & 0xffe0 | (ushort)bVar2;
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar13 + 0x18 + iVar7) = 0;
      if ((param_1 & 0xffffffe0) != 0) {
        r_assert_err(0,0x10000,0xe6);
      }
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(short *)(iVar13 + 2 + iVar7) = (short)param_1;
      (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
      r_lld_sync_sched(param_1,0);
      (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
      *(undefined1 *)((int)__s + 0x65) = 0;
      uVar9 = r_rwip_time_get();
      *(undefined4 *)((int)__s + 0x68) = uVar9;
      *(undefined4 *)((int)__s + 0x6c) = uVar9;
      return param_1;
    }
    uVar9 = 0x5df;
  }
  else {
    uVar9 = 0x5e4;
  }
  r_assert_err(0,0x10000,uVar9);
  return param_1;
}

