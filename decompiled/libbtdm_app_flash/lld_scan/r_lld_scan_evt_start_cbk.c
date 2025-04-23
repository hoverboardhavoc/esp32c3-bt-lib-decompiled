/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_evt_start_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_evt_start_cbk(int param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ushort uVar7;
  byte bStack_41;
  code *pcStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  byte bStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined1 uStack_24;
  
  if (param_1 != 0) {
    bVar1 = *(byte *)(param_1 + 0x38);
    uVar6 = (uint)bVar1;
    iVar3 = uVar6 * 0x5a;
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    uVar7 = *(ushort *)(iVar4 + iVar3) & 0x1f;
    if (*(char *)(param_1 + 0x3e) != '\x01') {
      if (_lld_scan_sync_env == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = (uint)(*(char *)(_lld_scan_sync_env + 1) != '\0');
      }
      *(char *)(param_1 + 0x44) = (char)uVar5;
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      uVar2 = *(ushort *)(iVar4 + iVar3 + 0x14);
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar4 + iVar3 + 0x14) = uVar2 & 0xfff7 | (ushort)(uVar5 << 3);
    }
    r_bt_rma_get_ant_by_act(uVar7,uVar6,&bStack_41,&pcStack_40);
    if ((bStack_41 & 0xfe) != 0) {
      r_assert_err(0,"lld_scan.c",0x82);
    }
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    uVar2 = *(ushort *)(iVar4 + iVar3);
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar4 + iVar3) = uVar2 & 0xff7f | (ushort)bStack_41 << 7;
    if (((uint)pcStack_40 & 0xfe) != 0) {
      r_assert_err(0,"lld_scan.c",0x8e);
    }
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    uVar2 = *(ushort *)(iVar4 + iVar3);
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar3 + iVar4) = uVar2 & 0xffbf | (ushort)(byte)pcStack_40 << 6;
    r_lld_scan_set_tx_power(uVar6,uVar7);
    pcStack_40 = r_lld_scan_frm_cbk;
    uStack_3c = *(undefined4 *)(param_1 + 4);
    uStack_38 = *(undefined4 *)(param_1 + 8);
    uStack_2b = 0;
    uStack_24 = 0;
    uStack_30 = (uint)*(byte *)(param_1 + 0x40);
    uStack_27 = 0;
    uStack_34 = *(undefined4 *)(param_1 + 0x10);
    uStack_2c = *(undefined1 *)(param_1 + 0x16);
    uStack_2a = rwip_priority;
    uStack_29 = 0xf;
    uStack_26 = *(char *)(param_1 + 0x3e) == '\x01';
    bStack_28 = bVar1;
    r_sch_prog_push(&pcStack_40);
    r_sch_slice_bg_add(0);
    *(undefined1 *)(param_1 + 0x3c) = 1;
    return;
  }
  r_assert_err("lld_scan.c",0xa74);
  return;
}

