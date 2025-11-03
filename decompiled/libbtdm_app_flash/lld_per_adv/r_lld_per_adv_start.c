/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_lld_per_adv_start(uint param_1,ushort *param_2)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  void *__s;
  byte *pbVar4;
  undefined4 uVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  char cVar9;
  uint uVar10;
  uint *puVar11;
  int iVar12;
  uint uVar13;
  byte bStack_32;
  byte abStack_31 [5];
  
  iVar12 = 0xc;
  if (*(int *)(&lld_per_adv_env + param_1 * 4) == 0) {
    __s = (void *)r_ke_malloc(0x60,0);
    *(void **)(&lld_per_adv_env + param_1 * 4) = __s;
    if (__s == (void *)0x0) {
      r_assert_err(0x10000,0x59d);
    }
    else {
      bStack_32 = 0;
      abStack_31[0] = 0;
      memset(__s,0,0x60);
      *(code **)((int)__s + 0x20) = r_lld_per_adv_evt_canceled_cbk;
      *(code **)((int)__s + 0x18) = r_lld_per_adv_evt_start_cbk;
      uVar3 = DAT_0001301a;
      *(char *)((int)__s + 0x52) = (char)param_1;
      *(undefined1 *)((int)__s + 0x16) = uVar3;
      *(ushort *)((int)__s + 0x48) = param_2[1];
      *(uint *)((int)__s + 0x40) = (uint)*param_2 << 2;
      *(undefined2 *)((int)__s + 0x3a) = 10;
      *(char *)((int)__s + 0x54) = (char)param_2[5];
      *(undefined1 *)((int)__s + 0x56) = *(undefined1 *)((int)param_2 + 0xb);
      bVar7 = (byte)param_2[6];
      if ((bVar7 < 3) || (*(char *)(_p_lld_env + 0xda) == '\0')) {
        bVar7 = bVar7 - 1;
      }
      *(byte *)((int)__s + 0x55) = bVar7;
      iVar12 = _p_lld_env;
      *(ushort *)((int)__s + 0x50) = param_2[3];
      uVar1 = param_2[2];
      *(undefined1 *)((int)__s + 0x2f) = 0;
      *(undefined1 *)((int)__s + 0x30) = 0;
      *(ushort *)((int)__s + 0x4e) = uVar1;
      *(undefined1 *)((int)__s + 0x31) = 0;
      *(undefined1 *)((int)__s + 0x32) = 0;
      *(undefined1 *)((int)__s + 0x33) = 0;
      iVar6 = (uint)*(byte *)(iVar12 + 0x100) + iVar12;
      for (; iVar12 != iVar6; iVar12 = iVar12 + 1) {
        bVar7 = *(byte *)(iVar12 + 0xdb) >> 3;
        *(byte *)((int)__s + bVar7 + 0x2f) =
             (byte)(1 << (*(byte *)(iVar12 + 0xdb) & 7)) | *(byte *)((int)__s + bVar7 + 0x2f);
      }
      r_lld_per_adv_chain_construct(param_1);
      r_bt_rma_get_ant_by_act(6,param_1,&bStack_32,abStack_31);
      uVar8 = (uint)rwip_coex_cfg;
      uVar10 = (uint)bStack_32;
      uVar13 = (uint)abStack_31[0];
      if ((uVar10 << 7 & 0xffffff7f) != 0) {
        r_assert_err(0,0x10000,0x42);
      }
      if ((uVar13 << 6 & 0xffffffbf) != 0) {
        r_assert_err(0,0x10000,0x43);
      }
      iVar6 = param_1 * 0x5a;
      iVar12 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar12 + iVar6) =
           (ushort)(uVar10 << 7) | (ushort)(uVar13 << 6) | (ushort)((uVar8 & 4) << 6) |
           (ushort)((uVar8 & 1) << 10) | (ushort)((uVar8 & 2) << 8) | 6;
      pbVar4 = (byte *)r_bt_rf_coex_st_param_get(4);
      if (pbVar4 != (byte *)0x0) {
        bVar7 = pbVar4[1];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x299b);
        }
        if (((uint)bVar7 << 8 & 0xf000) != 0) {
          r_assert_err(0,0x10000,0x299d);
        }
        puVar11 = (uint *)((param_1 + 0x1800c4cb) * 4);
        *puVar11 = *puVar11 & 0xfffff0ff | (uint)bVar7 << 8;
        bVar7 = *pbVar4;
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x294a);
        }
        *puVar11 = (uint)bVar7 << 0x1e | *puVar11 & 0xbfffffff;
        bVar7 = pbVar4[3];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x29bb);
        }
        if ((bVar7 & 0xf0) != 0) {
          r_assert_err(0,0x10000,0x29bd);
        }
        *puVar11 = *puVar11 & 0xfffffff0 | (uint)bVar7;
        bVar7 = pbVar4[2];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x295a);
        }
        *puVar11 = (uint)bVar7 << 0x1d | *puVar11 & 0xdfffffff;
        bVar7 = pbVar4[7];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x298b);
        }
        if (((uint)bVar7 << 0xc & 0xf0000) != 0) {
          r_assert_err(0,0x10000,0x298d);
        }
        *puVar11 = *puVar11 & 0xffff0fff | (uint)bVar7 << 0xc;
        bVar7 = pbVar4[8];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x29ab);
        }
        if (((uint)bVar7 << 4 & 0xffffff0f) != 0) {
          r_assert_err(0,0x10000,0x29ad);
        }
        *puVar11 = *puVar11 & 0xffffff0f | (uint)bVar7 << 4;
        bVar7 = pbVar4[9];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x297b);
        }
        if (((uint)bVar7 << 0x10 & 0xf00000) != 0) {
          r_assert_err(0,0x10000,0x297d);
        }
        *puVar11 = *puVar11 & 0xfff0ffff | (uint)bVar7 << 0x10;
        uVar1 = *(ushort *)(pbVar4 + 10);
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x296a);
        }
        if (((uint)uVar1 << 0x14 & 0xe0000000) != 0) {
          r_assert_err(0,0x10000,0x296c);
        }
        *puVar11 = *puVar11 & 0xe00fffff | (uint)uVar1 << 0x14;
        bVar7 = pbVar4[6];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x293a);
        }
        *puVar11 = *puVar11 & 0x7fffffff | (uint)bVar7 << 0x1f;
        if (2 < (int)_g_bt_plf_log_level) {
          ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[PER_ADV] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                     ,param_1,puVar11,pbVar4[2],pbVar4[3],*pbVar4,pbVar4[1],pbVar4[6]);
        }
      }
      iVar12 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + 0x16 + iVar12) = 0xc027;
      if (*(char *)((int)__s + 0x56) != '\x7f') {
        uVar5 = (*_g_bt_plf_log_level)(0,_g_bt_plf_log_level);
        r_bt_rtp_register_rule_cs_idx(param_1,uVar5);
      }
      iVar12 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + 0x18 + iVar12) = 0;
      r_lld_per_adv_set_tx_power(param_1,6);
      uVar2 = *(undefined2 *)((int)__s + 0x2f);
      iVar12 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + 0x22 + iVar12) = uVar2;
      uVar2 = *(undefined2 *)((int)__s + 0x31);
      iVar12 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + 0x24 + iVar12) = uVar2;
      bVar7 = *(byte *)((int)__s + 0x33);
      iVar12 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + 0x26 + iVar12) = (ushort)bVar7;
      r_lld_aa_gen((int)__s + 0x28,param_1);
      uVar5 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
      *(short *)((int)__s + 0x2c) = (short)uVar5;
      *(char *)((int)__s + 0x2e) = (char)((uint)uVar5 >> 0x10);
      uVar2 = *(undefined2 *)((int)__s + 0x28);
      iVar12 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + 0xc + iVar12) = uVar2;
      uVar2 = *(undefined2 *)((int)__s + 0x2a);
      iVar12 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + 0xe + iVar12) = uVar2;
      uVar2 = *(undefined2 *)((int)__s + 0x2c);
      iVar12 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + 0x10 + iVar12) = uVar2;
      bVar7 = *(byte *)((int)__s + 0x2e);
      iVar12 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + 0x12 + iVar12) = (ushort)bVar7;
      iVar12 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + 0x28 + iVar12) = 0;
      iVar12 = r_emi_get_mem_addr_by_offset(0x400);
      uVar8 = *(uint *)((int)__s + 0x44);
      *(undefined2 *)(iVar6 + 0x2a + iVar12) = 0;
      iVar12 = r_emi_get_mem_addr_by_offset(0x400);
      *(short *)(iVar6 + 0x20 + iVar12) = (short)((uVar8 / 0x271 + 1) * 0x10000 >> 0x10);
      bVar7 = *(byte *)((int)__s + 0x55);
      uVar8 = (uint)bVar7 << 4;
      if ((uVar8 & 0xffffffcf) != 0) {
        r_assert_err(0,0x10000,0x18e);
      }
      uVar10 = (uint)bVar7 << 2;
      if ((uVar10 & 0xfffffff3) != 0) {
        r_assert_err(0,0x10000,399);
      }
      if ((bVar7 & 0xfc) != 0) {
        r_assert_err(0,0x10000,400);
      }
      iVar12 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + 4 + iVar12) = (ushort)uVar8 | (ushort)uVar10 | (ushort)bVar7;
      uVar1 = param_2[5];
      if ((param_1 & 0xffffffe0) != 0) {
        r_assert_err(0,0x10000,0xe6);
      }
      iVar12 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + 2 + iVar12) = (ushort)(((byte)uVar1 & 1) << 7) | (ushort)param_1 | 0x800;
      iVar12 = r_lld_read_clock();
      uVar10 = *(uint *)((int)__s + 0x40);
      uVar8 = rwip_prog_delay + 1 + iVar12 & 0xfffffff;
      if (uVar10 == 0) {
        r_assert_err(0,0x10000,0x94);
      }
      bVar7 = DAT_0001301b;
      uVar1 = param_2[4];
      *(undefined4 *)((int)__s + 8) = 0;
      *(uint *)((int)__s + 4) = ((uint)uVar1 * 2 + uVar10 + uVar8) - uVar8 % uVar10 & 0xfffffff;
      *(ushort *)((int)__s + 0x14) = bVar7 & 0xf | 0x2000;
      cVar9 = '\x0f';
      do {
        iVar12 = r_sch_arb_insert(__s);
        if (iVar12 == 0) {
          *(undefined1 *)((int)__s + 0x53) = 0;
          goto _L315;
        }
        cVar9 = cVar9 + -1;
        *(byte *)((int)__s + 0x16) = *(char *)((int)__s + 0x16) + bVar7;
        *(uint *)((int)__s + 4) = *(int *)((int)__s + 4) + *(int *)((int)__s + 0x40) & 0xfffffff;
      } while (cVar9 != '\0');
      r_assert_err(0,0x10000,0x593);
_L315:
      r_lld_per_adv_coex_env_reset(__s);
      iVar12 = 0;
    }
  }
  r_ble_log_internal_x1(0x400400ab,iVar12 << 0x18 | param_1 << 0x10 | (uint)*param_2);
  return iVar12;
}

