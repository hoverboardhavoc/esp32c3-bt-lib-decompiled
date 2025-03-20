/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
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
    r_assert_err("lld_sync.c",0x4c1);
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x55);
    iVar3 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar3 + 0x28) & 0x80) != 0) {
      iVar3 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar3 + 0x2c) < 3) {
        r_ble_log_internal_x1
                  (0x40420007,
                   (uint)*(byte *)(param_1 + 0x55) |
                   (uint)*(ushort *)(param_1 + 0x4a) << 0x10 | (uint)*(byte *)(param_1 + 99) << 8);
      }
    }
    iVar4 = (uint)bVar1 * 0x5a;
    r_lld_sync_scan_dynamic_pti_process(param_1,0);
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

