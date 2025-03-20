/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
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
  undefined2 uVar3;
  ushort *puVar4;
  uint *puVar5;
  int iVar6;
  void *__s;
  byte *pbVar7;
  undefined4 uVar8;
  ushort uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  byte bStack_3a;
  byte abStack_39 [21];
  
  iVar6 = r_sdk_config_get_opts();
  if ((param_1 < *(byte *)(iVar6 + 0xd)) && (*(int *)(&lld_sync_env + param_1 * 4) == 0)) {
    __s = (void *)r_ke_malloc(0x70,0);
    *(void **)(&lld_sync_env + param_1 * 4) = __s;
    if (__s != (void *)0x0) {
      puVar4 = (ushort *)*param_2;
      iVar6 = 300;
      if ((char)puVar4[1] == '\0') {
        iVar6 = 0x1e;
      }
      uVar1 = *(undefined1 *)((int)param_2 + 10);
      bStack_3a = 0;
      abStack_39[0] = 0;
      uVar12 = (uint)*puVar4 * iVar6 * 2 + (uint)*(ushort *)(param_2 + 2);
      memset(__s,0,0x70);
      *(code **)((int)__s + 0x20) = r_lld_sync_evt_canceled_cbk;
      *(code **)((int)__s + 0x18) = r_lld_sync_evt_start_cbk;
      *(char *)((int)__s + 0x55) = (char)param_1;
      uVar9 = puVar4[2];
      uVar13 = (uint)uVar9 * 4;
      uVar10 = (uint)*(ushort *)((int)param_2 + 0xe) << 5;
      *(ushort *)((int)__s + 0x14) = rwip_priority & 0xf | 0x2000;
      *(uint *)((int)__s + 0x34) = uVar10;
      *(uint *)((int)__s + 0x40) = uVar13;
      memcpy((void *)((int)__s + 0x5c),puVar4 + 3,5);
      *(undefined1 *)((int)__s + 0x58) = uVar1;
      *(undefined1 *)((int)__s + 0x5a) = *(undefined1 *)((int)puVar4 + 0xb);
      *(undefined1 *)((int)__s + 0x59) = *(undefined1 *)((int)param_2 + 0xb);
      iVar6 = param_2[1];
      *(undefined1 *)((int)__s + 0x57) = 0;
      *(int *)((int)__s + 0x38) = iVar6;
      *(char *)((int)__s + 0x56) = (char)puVar4[1];
      iVar11 = (int)((uVar10 / uVar13 - 6) * 0x10000) >> 0x10;
      uVar10 = uVar12 / 0x271 + iVar6 + (uint)uVar9 * -4 & 0xfffffff;
      *(uint *)((int)__s + 0x44) = uVar10;
      *(uint *)((int)__s + 0x3c) = uVar10;
      uVar9 = puVar4[10];
      *(undefined1 *)((int)__s + 100) = 0;
      *(undefined1 *)((int)__s + 99) = 0;
      *(ushort *)((int)__s + 0x4a) = uVar9 - 1;
      *(ushort *)((int)__s + 0x4e) = uVar9 - 1;
      *(undefined1 *)((int)__s + 0x61) = 0;
      uVar9 = *(ushort *)(param_2 + 3);
      *(short *)((int)__s + 0x48) = (short)(uVar12 % 0x271);
      if (iVar11 < 0) {
        iVar11 = 0;
      }
      if ((uint)(int)(short)(ushort)iVar11 < (uint)uVar9) {
        uVar9 = (ushort)iVar11;
      }
      iVar11 = param_1 * 0x5a;
      *(ushort *)((int)__s + 0x4c) = uVar9;
      uVar9 = puVar4[6];
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + iVar11 + 0xc) = uVar9;
      uVar9 = puVar4[7];
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + iVar11 + 0xe) = uVar9;
      uVar9 = puVar4[8];
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + iVar11 + 0x10) = uVar9;
      uVar9 = puVar4[9];
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + iVar11 + 0x12) = (ushort)(byte)uVar9;
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + iVar11 + 0x14) = 0;
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + iVar11 + 0x28) = 0x3e72;
      r_bt_rma_get_ant_by_act(10,param_1,&bStack_3a,abStack_39);
      uVar12 = (uint)rwip_coex_cfg;
      uVar10 = (uint)bStack_3a;
      uVar13 = (uint)abStack_39[0];
      if ((uVar10 << 7 & 0xffffff7f) != 0) {
        r_assert_err(0,"lld_sync.c",0x42);
      }
      if ((uVar13 << 6 & 0xffffffbf) != 0) {
        r_assert_err(0,"lld_sync.c",0x43);
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + iVar11) =
           (ushort)(uVar10 << 7) | (ushort)(uVar13 << 6) | (ushort)((uVar12 & 4) << 6) |
           (ushort)((uVar12 & 1) << 10) | (ushort)((uVar12 & 2) << 8) | 0x2a;
      pbVar7 = (byte *)r_bt_rf_coex_st_param_get(7);
      if (pbVar7 != (byte *)0x0) {
        bVar2 = pbVar7[1];
        if (0xb < param_1) {
          r_assert_err(0,"lld_sync.c",0x299b);
        }
        if (((uint)bVar2 << 8 & 0xf000) != 0) {
          r_assert_err(0,"lld_sync.c",0x299d);
        }
        puVar5 = (uint *)((param_1 + 0x1800c4cb) * 4);
        *puVar5 = *puVar5 & 0xfffff0ff | (uint)bVar2 << 8;
        bVar2 = *pbVar7;
        if (0xb < param_1) {
          r_assert_err(0,"lld_sync.c",0x294a);
        }
        *puVar5 = (uint)bVar2 << 0x1e | *puVar5 & 0xbfffffff;
        bVar2 = pbVar7[3];
        if (0xb < param_1) {
          r_assert_err(0,"lld_sync.c",0x29bb);
        }
        if ((bVar2 & 0xf0) != 0) {
          r_assert_err(0,"lld_sync.c",0x29bd);
        }
        *puVar5 = *puVar5 & 0xfffffff0 | (uint)bVar2;
        bVar2 = pbVar7[2];
        if (0xb < param_1) {
          r_assert_err(0,"lld_sync.c",0x295a);
        }
        *puVar5 = (uint)bVar2 << 0x1d | *puVar5 & 0xdfffffff;
        bVar2 = pbVar7[7];
        if (0xb < param_1) {
          r_assert_err(0,"lld_sync.c",0x298b);
        }
        if (((uint)bVar2 << 0xc & 0xf0000) != 0) {
          r_assert_err(0,"lld_sync.c",0x298d);
        }
        *puVar5 = *puVar5 & 0xffff0fff | (uint)bVar2 << 0xc;
        bVar2 = pbVar7[8];
        if (0xb < param_1) {
          r_assert_err(0,"lld_sync.c",0x29ab);
        }
        if (((uint)bVar2 << 4 & 0xffffff0f) != 0) {
          r_assert_err(0,"lld_sync.c",0x29ad);
        }
        *puVar5 = *puVar5 & 0xffffff0f | (uint)bVar2 << 4;
        bVar2 = pbVar7[9];
        if (0xb < param_1) {
          r_assert_err(0,"lld_sync.c",0x297b);
        }
        if (((uint)bVar2 << 0x10 & 0xf00000) != 0) {
          r_assert_err(0,"lld_sync.c",0x297d);
        }
        *puVar5 = *puVar5 & 0xfff0ffff | (uint)bVar2 << 0x10;
        uVar9 = *(ushort *)(pbVar7 + 10);
        if (0xb < param_1) {
          r_assert_err(0,"lld_sync.c",0x296a);
        }
        if (((uint)uVar9 << 0x14 & 0xe0000000) != 0) {
          r_assert_err(0,"lld_sync.c",0x296c);
        }
        *puVar5 = *puVar5 & 0xe00fffff | (uint)uVar9 << 0x14;
        bVar2 = pbVar7[6];
        if (0xb < param_1) {
          r_assert_err(0,"lld_sync.c",0x293a);
        }
        *puVar5 = *puVar5 & 0x7fffffff | (uint)bVar2 << 0x1f;
        if (2 < _g_bt_plf_log_level) {
          ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[SYNC_SCAN]] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                     ,param_1,puVar5,pbVar7[2],pbVar7[3],*pbVar7,pbVar7[1],pbVar7[6]);
        }
      }
      uVar3 = *(undefined2 *)((int)__s + 0x5c);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + iVar11 + 0x22) = uVar3;
      uVar3 = *(undefined2 *)((int)__s + 0x5e);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + iVar11 + 0x24) = uVar3;
      bVar2 = *(byte *)((int)__s + 0x60);
      if ((bVar2 & 0xe0) != 0) {
        r_assert_err(0,"lld_sync.c",0x64d);
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      uVar9 = *(ushort *)(iVar6 + iVar11 + 0x26);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + iVar11 + 0x26) = uVar9 & 0xffe0 | (ushort)bVar2;
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + iVar11 + 0x18) = 0;
      if ((param_1 & 0xffffffe0) != 0) {
        r_assert_err(0,"lld_sync.c",0xe6);
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(short *)(iVar11 + 2 + iVar6) = (short)param_1;
      (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
      r_lld_sync_sched(param_1,0);
      (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
      *(undefined1 *)((int)__s + 0x65) = 0;
      uVar8 = r_rwip_time_get();
      *(undefined4 *)((int)__s + 0x68) = uVar8;
      *(undefined4 *)((int)__s + 0x6c) = uVar8;
      return param_1;
    }
    uVar8 = 0x5b4;
  }
  else {
    uVar8 = 0x5b9;
  }
  r_assert_err(0,"lld_sync.c",uVar8);
  return param_1;
}

