/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_start_set_cs
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort r_lld_adv_start_set_cs(uint param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  undefined4 uVar6;
  byte *pbVar7;
  uint uVar8;
  ushort uVar9;
  uint uVar10;
  byte bStack_32;
  byte abStack_31 [13];
  
  iVar3 = *(int *)(&lld_adv_env + param_1 * 4);
  uVar9 = *(ushort *)(iVar3 + 0x74);
  bStack_32 = 0;
  abStack_31[0] = 0;
  if ((uVar9 & 8) == 0) {
    if ((uVar9 & 0x10) == 0) {
      uVar6 = 4;
      uVar9 = 6;
    }
    else {
      uVar6 = 2;
      uVar9 = 4;
    }
  }
  else {
    r_sch_slice_fg_add(2,param_2 + 0x1000U & 0xfffffff);
    uVar6 = 3;
    uVar9 = 5;
    *(uint *)(iVar3 + 0x10) = (uint)_sch_slice_params;
  }
  r_bt_rma_get_ant_by_act(uVar9,param_1,&bStack_32,abStack_31);
  uVar8 = (uint)rwip_coex_cfg;
  uVar10 = (uint)abStack_31[0];
  uVar4 = (uint)bStack_32;
  if ((uVar4 << 7 & 0xffffff7f) != 0) {
    r_assert_err(0,"lld_adv.c",0x42);
  }
  if ((uVar10 << 6 & 0xffffffbf) != 0) {
    r_assert_err(0,"lld_adv.c",0x43);
  }
  iVar3 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar3 + param_1 * 0x5a) =
       (ushort)(uVar4 << 7) | (ushort)(uVar10 << 6) | (ushort)((uVar8 & 1) << 10) |
       (ushort)((uVar8 & 2) << 8) | (ushort)((uVar8 & 4) << 6) | uVar9;
  pbVar7 = (byte *)r_bt_rf_coex_st_param_get(uVar6);
  if (pbVar7 != (byte *)0x0) {
    bVar1 = pbVar7[1];
    if (0xb < param_1) {
      r_assert_err(0,"lld_adv.c",0x299b);
    }
    if (((uint)bVar1 << 8 & 0xf000) != 0) {
      r_assert_err(0,"lld_adv.c",0x299d);
    }
    puVar5 = (uint *)((param_1 + 0x1800c4cb) * 4);
    *puVar5 = *puVar5 & 0xfffff0ff | (uint)bVar1 << 8;
    bVar1 = *pbVar7;
    if (0xb < param_1) {
      r_assert_err(0,"lld_adv.c",0x294a);
    }
    *puVar5 = (uint)bVar1 << 0x1e | *puVar5 & 0xbfffffff;
    bVar1 = pbVar7[3];
    if (0xb < param_1) {
      r_assert_err(0,"lld_adv.c",0x29bb);
    }
    if ((bVar1 & 0xf0) != 0) {
      r_assert_err(0,"lld_adv.c",0x29bd);
    }
    *puVar5 = *puVar5 & 0xfffffff0 | (uint)bVar1;
    bVar1 = pbVar7[2];
    if (0xb < param_1) {
      r_assert_err(0,"lld_adv.c",0x295a);
    }
    *puVar5 = (uint)bVar1 << 0x1d | *puVar5 & 0xdfffffff;
    bVar1 = pbVar7[7];
    if (0xb < param_1) {
      r_assert_err(0,"lld_adv.c",0x298b);
    }
    if (((uint)bVar1 << 0xc & 0xf0000) != 0) {
      r_assert_err(0,"lld_adv.c",0x298d);
    }
    *puVar5 = *puVar5 & 0xffff0fff | (uint)bVar1 << 0xc;
    bVar1 = pbVar7[8];
    if (0xb < param_1) {
      r_assert_err(0,"lld_adv.c",0x29ab);
    }
    if (((uint)bVar1 << 4 & 0xffffff0f) != 0) {
      r_assert_err(0,"lld_adv.c",0x29ad);
    }
    *puVar5 = *puVar5 & 0xffffff0f | (uint)bVar1 << 4;
    bVar1 = pbVar7[9];
    if (0xb < param_1) {
      r_assert_err(0,"lld_adv.c",0x297b);
    }
    if (((uint)bVar1 << 0x10 & 0xf00000) != 0) {
      r_assert_err(0,"lld_adv.c",0x297d);
    }
    *puVar5 = *puVar5 & 0xfff0ffff | (uint)bVar1 << 0x10;
    uVar2 = *(ushort *)(pbVar7 + 10);
    if (0xb < param_1) {
      r_assert_err(0,"lld_adv.c",0x296a);
    }
    if (((uint)uVar2 << 0x14 & 0xe0000000) != 0) {
      r_assert_err(0,"lld_adv.c",0x296c);
    }
    *puVar5 = *puVar5 & 0xe00fffff | (uint)uVar2 << 0x14;
    bVar1 = pbVar7[6];
    if (0xb < param_1) {
      r_assert_err(0,"lld_adv.c",0x293a);
    }
    *puVar5 = *puVar5 & 0x7fffffff | (uint)bVar1 << 0x1f;
    if (2 < _g_bt_plf_log_level) {
      ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[EXT ADV] RXEN[%d] RX[%d], IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                 ,param_1,puVar5,pbVar7[2],pbVar7[3],*pbVar7,pbVar7[1],pbVar7[6]);
    }
  }
  return uVar9;
}

