/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_ext_pkt_prepare_set_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_lld_adv_ext_pkt_prepare_set_hack
               (int param_1,int param_2,uint param_3,int param_4,int param_5,int param_6,
               short *param_7,short *param_8)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  byte in_stack_00000000;
  byte in_stack_00000004;
  byte in_stack_00000008;
  
  iVar9 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar7 = (uint)*(byte *)(iVar9 + 0x87) * 9;
  uVar10 = (uint)in_stack_00000000 + in_stack_00000004 + 1 & 0xff;
  if (param_2 == iVar7) {
    bVar1 = *(byte *)(iVar9 + 0x93);
    iVar6 = r_co_ble_pkt_dur_in_us(uVar10,*(undefined1 *)(iVar9 + 0x8e));
    uVar4 = (iVar6 + 0x96) * (uint)bVar1;
  }
  else {
    uVar4 = r_co_ble_pkt_dur_in_us(uVar10,*(undefined1 *)(iVar9 + 0x90));
    if (param_2 == (uint)*(byte *)(iVar9 + 0x87) * 9 + 1) {
      *(uint *)(iVar9 + 0x70) = uVar4;
    }
  }
  uVar5 = 0;
  if (param_6 != 0) {
    if (DAT_00016954 == 0) {
      iVar6 = 300;
    }
    else {
      iVar6 = DAT_00016954 + -0x96;
    }
    uVar4 = uVar4 + iVar6;
    if (uVar4 < 0x257ed5) {
      uVar5 = 0x1e;
      if (0x3bfc3 < uVar4) {
        uVar5 = 300;
      }
      uVar5 = uVar4 / uVar5 + 1;
      if (param_2 == iVar7) {
        *(short *)(iVar9 + 0x7a) = (short)uVar5;
      }
      else {
        *(short *)(iVar9 + 0x7c) = (short)uVar5;
      }
      if (uVar4 < 0x3bfc4) {
        uVar4 = uVar5 * 0x1e;
        param_6 = 0;
      }
      else {
        uVar4 = uVar5 * 300;
      }
    }
    else {
      param_6 = 0;
      uVar5 = 0;
    }
  }
  bVar1 = *(byte *)(iVar9 + 0x91);
  uVar2 = *(ushort *)(_p_lld_env + 0xd4);
  if ((bVar1 & 0xc0) != 0) {
    r_assert_err(0,0x10000,0x2b0);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  param_2 = param_2 * 0xe;
  *(ushort *)(param_2 + 8 + iVar7) =
       (ushort)(uVar2 < 0x33) << 6 | (ushort)bVar1 | (ushort)(uVar5 << 8) | (ushort)(param_6 << 7);
  uVar8 = (uint)*(byte *)(iVar9 + 0x90) << 5;
  if ((uVar8 & 0xffffff1f) != 0) {
    r_assert_err(0,0x10000,0x31c);
  }
  if ((uVar5 >> 8 & 0xffffffe0) != 0) {
    r_assert_err(0,0x10000,0x31d);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar6 = param_2 + 10;
  *(ushort *)(iVar7 + iVar6) = (ushort)uVar8 | (ushort)(uVar5 >> 8);
  sVar3 = *param_7;
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(short *)(param_2 + 0xc + iVar7) = sVar3;
  *param_7 = *param_7 + (ushort)in_stack_00000008;
  uVar5 = 0;
  if (param_5 != 0) {
    uVar5 = *(byte *)(iVar9 + 0x8c) & 1;
  }
  uVar8 = 0;
  if (param_4 != 0) {
    uVar8 = *(byte *)(iVar9 + 0x8b) & 1;
  }
  if ((param_3 & 0xfffffff0) != 0) {
    r_assert_err(0,0x10000,0x126);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar7 + param_2 + 2) =
       (ushort)(uVar8 << 6) | (ushort)param_3 | (ushort)(uVar10 << 8) | (ushort)(uVar5 << 7) | 0x20;
  sVar3 = *param_8;
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(short *)(param_2 + 4 + iVar7) = sVar3;
  *param_8 = *param_8 + (ushort)in_stack_00000004;
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar2 = *(ushort *)(iVar7 + param_2);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(param_2 + iVar7) = (ushort)(((uint)uVar2 << 0x11) >> 0x11);
  iVar7 = r_bt_rf_coex_st_param_get(4);
  if (iVar7 != 0) {
    if (2 < _g_bt_plf_log_level) {
      ets_printf("TX PTI [EXT ADV DATA] [EN%d] [%d] \n",*(undefined1 *)(iVar7 + 4),
                 *(undefined1 *)(iVar7 + 5));
    }
    uVar10 = (uint)*(byte *)(iVar7 + 5) << 8;
    if ((uVar10 & 0xf000) != 0) {
      r_assert_err(0,0x10000,0x33f);
    }
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar2 = *(ushort *)(iVar9 + iVar6);
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar9 + iVar6) = uVar2 & 0xf0ff | (ushort)uVar10;
    bVar1 = *(byte *)(iVar7 + 4);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar2 = *(ushort *)(iVar7 + iVar6);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar7 + iVar6) = uVar2 & 0xefff | (ushort)bVar1 << 0xc;
  }
  return uVar4;
}

