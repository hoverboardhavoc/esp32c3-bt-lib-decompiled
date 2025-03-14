/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
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
  uint uVar5;
  int iVar6;
  uint uVar7;
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
  
  if (param_1 == 0) {
    r_assert_err("lld_per_adv.c",0x3a0);
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x52);
    uVar5 = (uint)bVar1;
    uVar2 = *(undefined2 *)(param_1 + 0x4c);
    iVar6 = uVar5 * 0x5a;
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar4 + iVar6 + 0x50) = uVar2;
    r_lld_per_adv_evt_start_chm_upd(param_1);
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    uVar3 = *(ushort *)(iVar4 + iVar6) & 0x1f;
    r_lld_per_adv_set_tx_power(uVar5,uVar3);
    r_lld_per_adv_dynamic_pti_process(param_1);
    r_bt_rma_get_ant_by_act(uVar3,uVar5,&bStack_41,&pcStack_40);
    if (((uint)bStack_41 << 7 & 0xffffff7f) != 0) {
      r_assert_err(0,"lld_per_adv.c",0x82);
    }
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    uVar3 = *(ushort *)(iVar4 + iVar6);
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar4 + iVar6) = uVar3 & 0xff7f | (ushort)((uint)bStack_41 << 7);
    uVar7 = ((uint)pcStack_40 & 0xff) << 6;
    if ((uVar7 & 0xffffffbf) != 0) {
      r_assert_err(0,"lld_per_adv.c",0x8e);
    }
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    uVar3 = *(ushort *)(iVar4 + iVar6);
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar4 + iVar6) = uVar3 & 0xffbf | (ushort)uVar7;
    pcStack_40 = r_lld_per_adv_frm_cbk;
    uStack_3c = *(undefined4 *)(param_1 + 4);
    uStack_34 = *(undefined4 *)(param_1 + 0x10);
    uStack_38 = 0;
    uStack_2c = *(undefined1 *)(param_1 + 0x16);
    uStack_2b = 0;
    uStack_2a = 0xf00;
    uStack_26 = 1;
    uStack_24 = 0;
    uStack_27 = 0;
    uStack_30 = uVar5;
    bStack_28 = bVar1;
    r_sch_prog_push(&pcStack_40);
    *(undefined1 *)(param_1 + 0x53) = 1;
  }
  return;
}

