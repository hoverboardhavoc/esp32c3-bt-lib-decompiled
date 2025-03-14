/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_per_adv_start(uint param_1,ushort *param_2)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  uint uVar4;
  uint *puVar5;
  void *__s;
  int iVar6;
  byte *pbVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  byte bVar11;
  char cVar12;
  uint uVar13;
  byte bStack_32;
  byte abStack_31 [5];
  
  if (*(int *)(&lld_per_adv_env + param_1 * 4) == 0) {
    __s = (void *)r_ke_malloc(0x60,0);
    *(void **)(&lld_per_adv_env + param_1 * 4) = __s;
    if (__s != (void *)0x0) {
      bStack_32 = 0;
      abStack_31[0] = 0;
      memset(__s,0,0x60);
      *(code **)((int)__s + 0x20) = r_lld_per_adv_evt_canceled_cbk;
      *(code **)((int)__s + 0x18) = r_lld_per_adv_evt_start_cbk;
      uVar3 = DAT_0001301a;
      *(char *)((int)__s + 0x52) = (char)param_1;
      *(undefined4 *)((int)__s + 0x1c) = 0;
      *(undefined1 *)((int)__s + 0x16) = uVar3;
      uVar1 = param_2[1];
      *(undefined4 *)((int)__s + 8) = 0;
      *(ushort *)((int)__s + 0x48) = uVar1;
      uVar1 = *param_2;
      *(undefined2 *)((int)__s + 0x4c) = 0;
      *(uint *)((int)__s + 0x40) = (uint)uVar1 << 2;
      *(undefined2 *)((int)__s + 0x3a) = 10;
      *(char *)((int)__s + 0x54) = (char)param_2[5];
      *(undefined1 *)((int)__s + 0x56) = *(undefined1 *)((int)param_2 + 0xb);
      bVar11 = (byte)param_2[6];
      if ((bVar11 < 3) || (*(char *)(_p_lld_env + 0xda) == '\0')) {
        bVar11 = bVar11 - 1;
      }
      *(byte *)((int)__s + 0x55) = bVar11;
      iVar6 = _p_lld_env;
      *(ushort *)((int)__s + 0x50) = param_2[3];
      uVar1 = param_2[2];
      *(undefined1 *)((int)__s + 0x2f) = 0;
      *(undefined1 *)((int)__s + 0x30) = 0;
      *(ushort *)((int)__s + 0x4e) = uVar1;
      *(undefined1 *)((int)__s + 0x31) = 0;
      *(undefined1 *)((int)__s + 0x32) = 0;
      *(undefined1 *)((int)__s + 0x33) = 0;
      iVar9 = (uint)*(byte *)(iVar6 + 0x100) + iVar6;
      for (; iVar9 != iVar6; iVar6 = iVar6 + 1) {
        bVar11 = *(byte *)(iVar6 + 0xdb) >> 3;
        *(byte *)((int)__s + bVar11 + 0x2f) =
             (byte)(1 << (*(byte *)(iVar6 + 0xdb) & 7)) | *(byte *)((int)__s + bVar11 + 0x2f);
      }
      r_lld_per_adv_chain_construct(param_1);
      r_bt_rma_get_ant_by_act(6,param_1,&bStack_32,abStack_31);
      uVar10 = (uint)rwip_coex_cfg;
      uVar4 = (uint)bStack_32;
      uVar13 = (uint)abStack_31[0];
      if ((uVar4 << 7 & 0xffffff7f) != 0) {
        r_assert_err(0,"lld_per_adv.c",0x42);
      }
      if ((uVar13 << 6 & 0xffffffbf) != 0) {
        r_assert_err(0,"lld_per_adv.c",0x43);
      }
      iVar9 = param_1 * 0x5a;
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + iVar9) =
           (ushort)(uVar4 << 7) | (ushort)(uVar13 << 6) | (ushort)((uVar10 & 4) << 6) |
           (ushort)((uVar10 & 1) << 10) | (ushort)((uVar10 & 2) << 8) | 6;
      pbVar7 = (byte *)r_bt_rf_coex_st_param_get(4);
      if (pbVar7 != (byte *)0x0) {
        bVar11 = pbVar7[1];
        if (0xb < param_1) {
          r_assert_err(0,"lld_per_adv.c",0x299b);
        }
        if (((uint)bVar11 << 8 & 0xf000) != 0) {
          r_assert_err(0,"lld_per_adv.c",0x299d);
        }
        puVar5 = (uint *)((param_1 + 0x1800c4cb) * 4);
        *puVar5 = *puVar5 & 0xfffff0ff | (uint)bVar11 << 8;
        bVar11 = *pbVar7;
        if (0xb < param_1) {
          r_assert_err(0,"lld_per_adv.c",0x294a);
        }
        *puVar5 = (uint)bVar11 << 0x1e | *puVar5 & 0xbfffffff;
        bVar11 = pbVar7[3];
        if (0xb < param_1) {
          r_assert_err(0,"lld_per_adv.c",0x29bb);
        }
        if ((bVar11 & 0xf0) != 0) {
          r_assert_err(0,"lld_per_adv.c",0x29bd);
        }
        *puVar5 = *puVar5 & 0xfffffff0 | (uint)bVar11;
        bVar11 = pbVar7[2];
        if (0xb < param_1) {
          r_assert_err(0,"lld_per_adv.c",0x295a);
        }
        *puVar5 = (uint)bVar11 << 0x1d | *puVar5 & 0xdfffffff;
        bVar11 = pbVar7[7];
        if (0xb < param_1) {
          r_assert_err(0,"lld_per_adv.c",0x298b);
        }
        if (((uint)bVar11 << 0xc & 0xf0000) != 0) {
          r_assert_err(0,"lld_per_adv.c",0x298d);
        }
        *puVar5 = *puVar5 & 0xffff0fff | (uint)bVar11 << 0xc;
        bVar11 = pbVar7[8];
        if (0xb < param_1) {
          r_assert_err(0,"lld_per_adv.c",0x29ab);
        }
        if (((uint)bVar11 << 4 & 0xffffff0f) != 0) {
          r_assert_err(0,"lld_per_adv.c",0x29ad);
        }
        *puVar5 = *puVar5 & 0xffffff0f | (uint)bVar11 << 4;
        bVar11 = pbVar7[9];
        if (0xb < param_1) {
          r_assert_err(0,"lld_per_adv.c",0x297b);
        }
        if (((uint)bVar11 << 0x10 & 0xf00000) != 0) {
          r_assert_err(0,"lld_per_adv.c",0x297d);
        }
        *puVar5 = *puVar5 & 0xfff0ffff | (uint)bVar11 << 0x10;
        uVar1 = *(ushort *)(pbVar7 + 10);
        if (0xb < param_1) {
          r_assert_err(0,"lld_per_adv.c",0x296a);
        }
        if (((uint)uVar1 << 0x14 & 0xe0000000) != 0) {
          r_assert_err(0,"lld_per_adv.c",0x296c);
        }
        *puVar5 = *puVar5 & 0xe00fffff | (uint)uVar1 << 0x14;
        bVar11 = pbVar7[6];
        if (0xb < param_1) {
          r_assert_err(0,"lld_per_adv.c",0x293a);
        }
        *puVar5 = *puVar5 & 0x7fffffff | (uint)bVar11 << 0x1f;
        if (2 < _g_bt_plf_log_level) {
          ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[PER_ADV] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                     ,param_1,puVar5,pbVar7[2],pbVar7[3],*pbVar7,pbVar7[1],pbVar7[6]);
        }
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + iVar9 + 0x16) = 0xc027;
      if (*(char *)((int)__s + 0x56) != '\x7f') {
        uVar8 = (*_rwip_rf)(0,_rwip_rf);
        r_bt_rtp_register_rule_cs_idx(param_1,uVar8);
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + iVar9 + 0x18) = 0;
      r_lld_per_adv_set_tx_power(param_1,6);
      uVar2 = *(undefined2 *)((int)__s + 0x2f);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + iVar9 + 0x22) = uVar2;
      uVar2 = *(undefined2 *)((int)__s + 0x31);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + iVar9 + 0x24) = uVar2;
      bVar11 = *(byte *)((int)__s + 0x33);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + iVar9 + 0x26) = (ushort)bVar11;
      r_lld_aa_gen((int)__s + 0x28,param_1);
      uVar8 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
      uVar2 = *(undefined2 *)((int)__s + 0x28);
      *(short *)((int)__s + 0x2c) = (short)uVar8;
      *(char *)((int)__s + 0x2e) = (char)((uint)uVar8 >> 0x10);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + iVar9 + 0xc) = uVar2;
      uVar2 = *(undefined2 *)((int)__s + 0x2a);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + iVar9 + 0xe) = uVar2;
      uVar2 = *(undefined2 *)((int)__s + 0x2c);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + iVar9 + 0x10) = uVar2;
      bVar11 = *(byte *)((int)__s + 0x2e);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + iVar9 + 0x12) = (ushort)bVar11;
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + iVar9 + 0x28) = 0;
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      uVar4 = *(uint *)((int)__s + 0x44);
      *(undefined2 *)(iVar6 + iVar9 + 0x2a) = 0;
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(short *)(iVar6 + iVar9 + 0x20) = (short)((uVar4 / 0x271 + 1) * 0x10000 >> 0x10);
      bVar11 = *(byte *)((int)__s + 0x55);
      uVar4 = (uint)bVar11 << 4;
      if ((uVar4 & 0xffffffcf) != 0) {
        r_assert_err(0,"lld_per_adv.c",0x18e);
      }
      uVar10 = (uint)bVar11 << 2;
      if ((uVar10 & 0xfffffff3) != 0) {
        r_assert_err(0,"lld_per_adv.c",399);
      }
      if ((bVar11 & 0xfc) != 0) {
        r_assert_err(0,"lld_per_adv.c",400);
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + iVar9 + 4) = (ushort)uVar4 | (ushort)uVar10 | (ushort)bVar11;
      uVar1 = param_2[5];
      if ((param_1 & 0xffffffe0) != 0) {
        r_assert_err(0,"lld_per_adv.c",0xe6);
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar9 + 2 + iVar6) = (ushort)(((byte)uVar1 & 1) << 7) | (ushort)param_1 | 0x800;
      iVar6 = r_lld_read_clock();
      uVar10 = *(uint *)((int)__s + 0x40);
      uVar4 = rwip_prog_delay + 1 + iVar6 & 0xfffffff;
      if (uVar10 == 0) {
        r_assert_err(0,"lld_per_adv.c",0x94);
      }
      bVar11 = DAT_0001301b;
      uVar1 = param_2[4];
      *(undefined4 *)((int)__s + 8) = 0;
      cVar12 = '\x0f';
      *(uint *)((int)__s + 4) = ((uint)uVar1 * 2 + uVar10 + uVar4) - uVar4 % uVar10 & 0xfffffff;
      *(ushort *)((int)__s + 0x14) = bVar11 & 0xf | 0x2000;
      do {
        iVar6 = r_sch_arb_insert(__s);
        if (iVar6 == 0) {
          *(undefined1 *)((int)__s + 0x53) = 0;
          goto _L308;
        }
        cVar12 = cVar12 + -1;
        *(byte *)((int)__s + 0x16) = *(char *)((int)__s + 0x16) + bVar11;
        *(uint *)((int)__s + 4) = *(int *)((int)__s + 4) + *(int *)((int)__s + 0x40) & 0xfffffff;
      } while (cVar12 != '\0');
      r_assert_err(0,"lld_per_adv.c",0x570);
_L308:
      r_lld_per_adv_coex_env_reset(__s);
      return 0;
    }
    r_assert_err("lld_per_adv.c",0x57a);
  }
  return 0xc;
}

