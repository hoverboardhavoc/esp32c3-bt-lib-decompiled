/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_evt_start_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_sync_evt_start_cbk(int param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
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
  
  if (param_1 == 0) {
    r_assert_err("lld_sync.c",0x4ac);
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x55);
    iVar4 = (uint)bVar1 * 0x5a;
    r_lld_sync_scan_dynamic_pti_process(0);
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    r_bt_rma_get_ant_by_act(*(ushort *)(iVar3 + iVar4) & 0x1f,(uint)bVar1,&bStack_41,&pcStack_40);
    if (((uint)bStack_41 << 7 & 0xffffff7f) != 0) {
      r_assert_err(0,"lld_sync.c",0x82);
    }
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    uVar2 = *(ushort *)(iVar3 + iVar4);
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar3 + iVar4) = uVar2 & 0xff7f | (ushort)((uint)bStack_41 << 7);
    uVar5 = ((uint)pcStack_40 & 0xff) << 6;
    if ((uVar5 & 0xffffffbf) != 0) {
      r_assert_err(0,"lld_sync.c",0x8e);
    }
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    uVar2 = *(ushort *)(iVar3 + iVar4);
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar3 + iVar4) = uVar2 & 0xffbf | (ushort)uVar5;
    pcStack_40 = r_lld_sync_frm_cbk;
    uStack_3c = *(undefined4 *)(param_1 + 4);
    uStack_38 = *(undefined4 *)(param_1 + 8);
    uStack_2b = 0;
    uStack_30 = (uint)*(byte *)(param_1 + 0x55);
    uStack_26 = 1;
    uStack_24 = 0;
    uStack_34 = *(undefined4 *)(param_1 + 0x10);
    uStack_27 = 0;
    uStack_2c = *(undefined1 *)(param_1 + 0x16);
    uStack_29 = 0xf;
    uStack_2a = uStack_2c;
    bStack_28 = bVar1;
    r_sch_prog_push(&pcStack_40);
    *(undefined1 *)(param_1 + 0x5b) = 1;
    *(undefined1 *)(param_1 + 100) = 0;
  }
  return;
}

