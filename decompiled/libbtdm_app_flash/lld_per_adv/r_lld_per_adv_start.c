/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  byte bVar3;
  undefined1 uVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  uint *puVar8;
  void *__s;
  int iVar9;
  byte *pbVar10;
  undefined4 uVar11;
  int iVar12;
  byte bVar13;
  uint uVar14;
  uint uVar15;
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
      uVar4 = DAT_0001301a;
      *(char *)((int)__s + 0x52) = (char)param_1;
      *(undefined1 *)((int)__s + 0x16) = uVar4;
      *(ushort *)((int)__s + 0x48) = param_2[1];
      *(uint *)((int)__s + 0x40) = (uint)*param_2 << 2;
      *(undefined2 *)((int)__s + 0x3a) = 10;
      *(char *)((int)__s + 0x54) = (char)param_2[5];
      *(undefined1 *)((int)__s + 0x56) = *(undefined1 *)((int)param_2 + 0xb);
      iVar9 = _p_lld_env;
      bVar13 = (byte)param_2[6];
      if ((bVar13 < 3) || (*(char *)(_p_lld_env + 0xda) == '\0')) {
        bVar13 = bVar13 - 1;
      }
      *(byte *)((int)__s + 0x55) = bVar13;
      *(ushort *)((int)__s + 0x50) = param_2[3];
      uVar1 = param_2[2];
      *(undefined1 *)((int)__s + 0x2f) = 0;
      *(undefined1 *)((int)__s + 0x30) = 0;
      *(ushort *)((int)__s + 0x4e) = uVar1;
      *(undefined1 *)((int)__s + 0x31) = 0;
      *(undefined1 *)((int)__s + 0x32) = 0;
      *(undefined1 *)((int)__s + 0x33) = 0;
      iVar12 = (uint)*(byte *)(iVar9 + 0x100) + iVar9;
      for (; iVar12 != iVar9; iVar9 = iVar9 + 1) {
        bVar13 = *(byte *)(iVar9 + 0xdb) >> 3;
        *(byte *)((int)__s + bVar13 + 0x2f) =
             (byte)(1 << (*(byte *)(iVar9 + 0xdb) & 7)) | *(byte *)((int)__s + bVar13 + 0x2f);
      }
      r_lld_per_adv_chain_construct(param_1);
      r_bt_rma_get_ant_by_act(6,param_1,&bStack_32,abStack_31);
      bVar6 = abStack_31[0];
      bVar5 = bStack_32;
      uVar14 = (uint)rwip_coex_cfg;
      bVar13 = rwip_coex_cfg >> 1;
      bVar3 = rwip_coex_cfg >> 2;
      if ((bStack_32 & 0xfe) != 0) {
        r_assert_err(0,0x10000,0x42);
      }
      if ((bVar6 & 0xfe) != 0) {
        r_assert_err(0,0x10000,0x43);
      }
      iVar12 = param_1 * 0x5a;
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar9 + iVar12) =
           (ushort)bVar5 << 7 | (ushort)bVar6 << 6 | (ushort)((bVar3 & 1) << 8) |
           (ushort)((uVar14 & 1) << 10) | (ushort)((bVar13 & 1) << 9) | 6;
      pbVar10 = (byte *)r_bt_rf_coex_st_param_get(4);
      if (pbVar10 != (byte *)0x0) {
        bVar13 = pbVar10[1];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x299b);
        }
        if ((bVar13 & 0xf0) != 0) {
          r_assert_err(0,0x10000,0x299d);
        }
        puVar8 = (uint *)((param_1 + 0x1800c4cb) * 4);
        *puVar8 = *puVar8 & 0xfffff0ff | (uint)bVar13 << 8;
        bVar13 = *pbVar10;
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x294a);
        }
        *puVar8 = *puVar8 & 0xbfffffff | (uint)bVar13 << 0x1e;
        bVar13 = pbVar10[3];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x29bb);
        }
        if (0xf < bVar13) {
          r_assert_err(0,0x10000,0x29bd);
        }
        *puVar8 = *puVar8 & 0xfffffff0 | (uint)bVar13;
        bVar13 = pbVar10[2];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x295a);
        }
        *puVar8 = *puVar8 & 0xdfffffff | (uint)bVar13 << 0x1d;
        bVar13 = pbVar10[7];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x298b);
        }
        if ((bVar13 & 0xf0) != 0) {
          r_assert_err(0,0x10000,0x298d);
        }
        *puVar8 = *puVar8 & 0xffff0fff | (uint)bVar13 << 0xc;
        bVar13 = pbVar10[8];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x29ab);
        }
        if ((bVar13 & 0xf0) != 0) {
          r_assert_err(0,0x10000,0x29ad);
        }
        *puVar8 = *puVar8 & 0xffffff0f | (uint)bVar13 << 4;
        bVar13 = pbVar10[9];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x297b);
        }
        if ((bVar13 & 0xf0) != 0) {
          r_assert_err(0,0x10000,0x297d);
        }
        *puVar8 = *puVar8 & 0xfff0ffff | (uint)bVar13 << 0x10;
        uVar1 = *(ushort *)(pbVar10 + 10);
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x296a);
        }
        if ((uVar1 >> 9 & 7) != 0) {
          r_assert_err(0,0x10000,0x296c);
        }
        *puVar8 = *puVar8 & 0xe00fffff | (uint)uVar1 << 0x14;
        bVar13 = pbVar10[6];
        if (0xb < param_1) {
          r_assert_err(0,0x10000,0x293a);
        }
        *puVar8 = *puVar8 & 0x7fffffff | (uint)bVar13 << 0x1f;
        if (2 < (int)_g_bt_plf_log_level) {
          ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[PER_ADV] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                     ,param_1,puVar8,pbVar10[2],pbVar10[3],*pbVar10,pbVar10[1],pbVar10[6]);
        }
      }
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar12 + 0x16 + iVar9) = 0xc027;
      if (*(char *)((int)__s + 0x56) != '\x7f') {
        uVar11 = (*_g_bt_plf_log_level)(0,_g_bt_plf_log_level);
        r_bt_rtp_register_rule_cs_idx(param_1,uVar11);
      }
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar12 + 0x18 + iVar9) = 0;
      r_lld_per_adv_set_tx_power(param_1,6);
      uVar2 = *(undefined2 *)((int)__s + 0x2f);
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar12 + 0x22 + iVar9) = uVar2;
      uVar2 = *(undefined2 *)((int)__s + 0x31);
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar12 + 0x24 + iVar9) = uVar2;
      bVar13 = *(byte *)((int)__s + 0x33);
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar12 + 0x26 + iVar9) = (ushort)bVar13;
      r_lld_aa_gen((int)__s + 0x28,param_1);
      uVar11 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
      *(short *)((int)__s + 0x2c) = (short)uVar11;
      *(char *)((int)__s + 0x2e) = (char)((uint)uVar11 >> 0x10);
      uVar2 = *(undefined2 *)((int)__s + 0x28);
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar12 + 0xc + iVar9) = uVar2;
      uVar2 = *(undefined2 *)((int)__s + 0x2a);
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar12 + 0xe + iVar9) = uVar2;
      uVar2 = *(undefined2 *)((int)__s + 0x2c);
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar12 + 0x10 + iVar9) = uVar2;
      bVar13 = *(byte *)((int)__s + 0x2e);
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar12 + 0x12 + iVar9) = (ushort)bVar13;
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar12 + 0x28 + iVar9) = 0;
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      uVar14 = *(uint *)((int)__s + 0x44);
      *(undefined2 *)(iVar12 + 0x2a + iVar9) = 0;
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(short *)(iVar12 + 0x20 + iVar9) = (short)((uVar14 / 0x271 + 1) * 0x10000 >> 0x10);
      bVar13 = *(byte *)((int)__s + 0x55);
      if ((bVar13 & 0xfc) == 0) {
        if (3 < bVar13) goto _L301;
      }
      else {
        r_assert_err(0,0x10000,0x18e);
        r_assert_err(0,0x10000,399);
_L301:
        r_assert_err(0,0x10000,400);
      }
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar12 + 4 + iVar9) = (ushort)bVar13 | (ushort)bVar13 << 4 | (ushort)bVar13 << 2;
      uVar1 = param_2[5];
      if (0x1f < param_1) {
        r_assert_err(0,0x10000,0xe6);
      }
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar12 + 2 + iVar9) = (ushort)(((byte)uVar1 & 1) << 7) | (ushort)param_1 | 0x800;
      iVar9 = r_lld_read_clock();
      uVar15 = *(uint *)((int)__s + 0x40);
      uVar14 = rwip_prog_delay + 1 + iVar9 & 0xfffffff;
      if (uVar15 == 0) {
        r_assert_err(0,0x10000,0x94);
      }
      bVar13 = DAT_0001301b;
      uVar1 = param_2[4];
      *(undefined4 *)((int)__s + 8) = 0;
      *(uint *)((int)__s + 4) = ((uint)uVar1 * 2 + uVar15 + uVar14) - uVar14 % uVar15 & 0xfffffff;
      *(ushort *)((int)__s + 0x14) = bVar13 & 0xf | 0x2000;
      cVar7 = '\x0f';
      do {
        iVar9 = r_sch_arb_insert(__s);
        if (iVar9 == 0) {
          *(undefined1 *)((int)__s + 0x53) = 0;
          goto _L312;
        }
        cVar7 = cVar7 + -1;
        *(byte *)((int)__s + 0x16) = *(char *)((int)__s + 0x16) + bVar13;
        *(uint *)((int)__s + 4) = *(int *)((int)__s + 4) + *(int *)((int)__s + 0x40) & 0xfffffff;
      } while (cVar7 != '\0');
      r_assert_err(0,0x10000,0x57d);
_L312:
      r_lld_per_adv_coex_env_reset(__s);
      iVar9 = 0;
      goto _L308;
    }
    r_assert_err(0x10000,0x587);
  }
  iVar9 = 0xc;
_L308:
  iVar12 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar12 + 0x28) & 0x40) != 0) {
    iVar12 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar12 + 0x2c) < 3) {
      r_ble_log_internal_x2(0x40080000,iVar9 << 8 | param_1,*param_2);
    }
  }
  return iVar9;
}

