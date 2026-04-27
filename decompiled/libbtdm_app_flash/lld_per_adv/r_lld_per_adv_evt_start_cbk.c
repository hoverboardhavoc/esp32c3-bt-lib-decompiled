/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_evt_start_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_evt_start_cbk(int param_1)

{
  byte bVar1;
  undefined2 uVar2;
  ushort uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  byte bStack_41;
  code *pcStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined2 uStack_2a;
  byte bStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined1 uStack_24;
  
  if (param_1 != 0) {
    bVar1 = *(byte *)(param_1 + 0x52);
    uVar6 = (uint)bVar1;
    uVar5 = *(undefined4 *)(param_1 + 4);
    iVar7 = uVar6 * 0x5a;
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    r_ble_log_internal_x3
              (0x40440132,uVar5,*(int *)(param_1 + 8) << 0x10 | *(ushort *)(iVar4 + iVar7) & 0x1f,
               uVar6);
    uVar2 = *(undefined2 *)(param_1 + 0x4c);
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar7 + 0x50 + iVar4) = uVar2;
    r_lld_per_adv_evt_start_chm_upd(param_1);
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    uVar3 = *(ushort *)(iVar4 + iVar7) & 0x1f;
    r_lld_per_adv_set_tx_power(uVar6,uVar3);
    r_lld_per_adv_dynamic_pti_process(param_1);
    r_bt_rma_get_ant_by_act(uVar3,uVar6,&bStack_41,&pcStack_40);
    if (((uint)bStack_41 << 7 & 0xffffff7f) != 0) {
      r_assert_err(0,0x10000,0x82);
    }
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    uVar3 = *(ushort *)(iVar4 + iVar7);
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar4 + iVar7) = uVar3 & 0xff7f | (ushort)((uint)bStack_41 << 7);
    uVar8 = ((uint)pcStack_40 & 0xff) << 6;
    if ((uVar8 & 0xffffffbf) != 0) {
      r_assert_err(0,0x10000,0x8e);
    }
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    uVar3 = *(ushort *)(iVar4 + iVar7);
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar4 + iVar7) = uVar3 & 0xffbf | (ushort)uVar8;
    pcStack_40 = r_lld_per_adv_frm_cbk;
    uStack_3c = *(undefined4 *)(param_1 + 4);
    uStack_34 = *(undefined4 *)(param_1 + 0x10);
    uStack_2c = *(undefined1 *)(param_1 + 0x16);
    uStack_26 = 1;
    uStack_38 = 0;
    uStack_2b = 0;
    uStack_2a = 0xf00;
    uStack_24 = 0;
    uStack_27 = 0;
    uStack_30 = uVar6;
    bStack_28 = bVar1;
    r_sch_prog_push(&pcStack_40);
    *(undefined1 *)(param_1 + 0x53) = 1;
    return;
  }
  r_assert_err(0x10000,0x3c5);
  return;
}

