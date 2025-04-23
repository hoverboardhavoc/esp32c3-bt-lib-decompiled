/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_ext_pkt_prepare_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_lld_adv_ext_pkt_prepare_set
               (int param_1,int param_2,uint param_3,int param_4,int param_5,int param_6,
               short *param_7,short *param_8)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  byte in_stack_00000000;
  byte in_stack_00000004;
  byte in_stack_00000008;
  
  iVar8 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar5 = (uint)*(byte *)(iVar8 + 0x87) * 9;
  uVar9 = (uint)in_stack_00000000 + in_stack_00000004 + 1 & 0xff;
  if (param_2 == iVar5) {
    bVar1 = *(byte *)(iVar8 + 0x93);
    iVar7 = r_co_ble_pkt_dur_in_us(uVar9,*(undefined1 *)(iVar8 + 0x8e));
    uVar4 = (iVar7 + 0x96) * (uint)bVar1;
  }
  else {
    uVar4 = r_co_ble_pkt_dur_in_us(uVar9,*(undefined1 *)(iVar8 + 0x90));
    if (param_2 == (uint)*(byte *)(iVar8 + 0x87) * 9 + 1) {
      *(uint *)(iVar8 + 0x70) = uVar4;
    }
  }
  uVar10 = 0;
  if (param_6 != 0) {
    if (DAT_00016470 == 0) {
      iVar7 = 300;
    }
    else {
      iVar7 = DAT_00016470 + -0x96;
    }
    uVar4 = uVar4 + iVar7;
    if (uVar4 < 0x257ed5) {
      if (uVar4 < 0x3bfc4) {
        uVar10 = 0x1e;
      }
      else {
        uVar10 = 300;
      }
      uVar10 = uVar4 / uVar10 + 1;
      if (param_2 == iVar5) {
        *(short *)(iVar8 + 0x7a) = (short)uVar10;
      }
      else {
        *(short *)(iVar8 + 0x7c) = (short)uVar10;
      }
      if (uVar4 < 0x3bfc4) {
        uVar4 = uVar10 * 0x1e;
        param_6 = 0;
      }
      else {
        uVar4 = uVar10 * 300;
      }
    }
    else {
      param_6 = 0;
      uVar10 = 0;
    }
  }
  uVar2 = *(ushort *)(_p_lld_env + 0xd4);
  bVar1 = *(byte *)(iVar8 + 0x91);
  if (0x3f < bVar1) {
    r_assert_err(0,0x10000,0x2b0);
  }
  iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
  param_2 = param_2 * 0xe;
  *(ushort *)(param_2 + 8 + iVar5) =
       (ushort)(uVar2 < 0x33) << 6 | (ushort)bVar1 | (ushort)(param_6 << 7) |
       (ushort)((uVar10 & 0xff) << 8);
  bVar1 = *(byte *)(iVar8 + 0x90);
  if ((bVar1 & 0xf8) != 0) {
    r_assert_err(0,0x10000,0x31c);
  }
  if (uVar10 >> 8 == 0x20) {
    r_assert_err(0,0x10000,0x31d);
  }
  iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar7 = param_2 + 10;
  *(ushort *)(iVar5 + iVar7) = (ushort)bVar1 << 5 | (ushort)(uVar10 >> 8);
  sVar3 = *param_7;
  iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
  *(short *)(param_2 + 0xc + iVar5) = sVar3;
  *param_7 = (ushort)in_stack_00000008 + *param_7;
  uVar10 = 0;
  if (param_5 != 0) {
    uVar10 = *(byte *)(iVar8 + 0x8c) & 1;
  }
  uVar6 = 0;
  if (param_4 != 0) {
    uVar6 = *(byte *)(iVar8 + 0x8b) & 1;
  }
  if (0xf < param_3) {
    r_assert_err(0,0x10000,0x126);
  }
  iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar5 + param_2 + 2) =
       (ushort)(uVar6 << 6) | (ushort)param_3 | (ushort)(uVar9 << 8) | (ushort)(uVar10 << 7) | 0x20;
  sVar3 = *param_8;
  iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
  *(short *)(param_2 + 4 + iVar5) = sVar3;
  *param_8 = (ushort)in_stack_00000004 + *param_8;
  iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar2 = *(ushort *)(iVar5 + param_2);
  iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(param_2 + iVar5) = (ushort)(((uint)uVar2 << 0x11) >> 0x11);
  iVar5 = r_bt_rf_coex_st_param_get(4);
  if (iVar5 != 0) {
    if (2 < _g_bt_plf_log_level) {
      ets_printf("TX PTI [EXT ADV DATA] [EN%d] [%d] \n",*(undefined1 *)(iVar5 + 4),
                 *(undefined1 *)(iVar5 + 5));
    }
    bVar1 = *(byte *)(iVar5 + 5);
    if ((bVar1 & 0xf0) != 0) {
      r_assert_err(0,0x10000,0x33f);
    }
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar2 = *(ushort *)(iVar8 + iVar7);
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar8 + iVar7) = uVar2 & 0xf0ff | (ushort)bVar1 << 8;
    bVar1 = *(byte *)(iVar5 + 4);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar2 = *(ushort *)(iVar5 + iVar7);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar5 + iVar7) = uVar2 & 0xefff | (ushort)bVar1 << 0xc;
  }
  return uVar4;
}

