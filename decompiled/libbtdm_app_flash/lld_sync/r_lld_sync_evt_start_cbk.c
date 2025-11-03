/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
  uint uVar4;
  int iVar5;
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
    bVar1 = *(byte *)(param_1 + 0x55);
    uVar4 = (uint)bVar1;
    iVar5 = uVar4 * 0x5a;
    r_ble_log_internal_x1
              (0x404500d8,
               (uint)*(ushort *)(param_1 + 0x4a) |
               (uint)*(byte *)(param_1 + 99) << 0x18 | uVar4 << 0x10);
    r_lld_sync_scan_dynamic_pti_process(param_1,0);
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    r_bt_rma_get_ant_by_act(*(ushort *)(iVar3 + iVar5) & 0x1f,uVar4,&bStack_41,&pcStack_40);
    if (((uint)bStack_41 << 7 & 0xffffff7f) != 0) {
      r_assert_err(0,0x10000,0x82);
    }
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    uVar2 = *(ushort *)(iVar3 + iVar5);
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar3 + iVar5) = uVar2 & 0xff7f | (ushort)((uint)bStack_41 << 7);
    uVar4 = ((uint)pcStack_40 & 0xff) << 6;
    if ((uVar4 & 0xffffffbf) != 0) {
      r_assert_err(0,0x10000,0x8e);
    }
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    uVar2 = *(ushort *)(iVar3 + iVar5);
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar3 + iVar5) = uVar2 & 0xffbf | (ushort)uVar4;
    pcStack_40 = r_lld_sync_frm_cbk;
    uStack_3c = *(undefined4 *)(param_1 + 4);
    uStack_38 = *(undefined4 *)(param_1 + 8);
    uStack_26 = 1;
    uStack_30 = (uint)*(byte *)(param_1 + 0x55);
    uStack_2b = 0;
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
    return;
  }
  r_assert_err(0x10000,0x4ec);
  return;
}

