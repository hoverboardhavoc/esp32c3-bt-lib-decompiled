/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld_test.o -> r_lld_test_evt_start_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_test_evt_start_cbk(int param_1)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  byte bStack_31;
  code *pcStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  undefined1 uStack_16;
  undefined1 uStack_14;
  
  if (_lld_test_env != param_1) {
    r_assert_err(0,"lld_test.c",0x17b);
  }
  if (param_1 == 0) {
    r_assert_err(0,"lld_test.c",0x1a5);
  }
  else {
    puVar2 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    uVar1 = *puVar2;
    r_lld_test_set_tx_power(0,uVar1 & 0x1f);
    r_bt_rma_get_ant_by_act(uVar1 & 0x1f,0,&bStack_31,&pcStack_30);
    if (((uint)bStack_31 << 7 & 0xffffff7f) != 0) {
      r_assert_err(0,"lld_test.c",0x82);
    }
    puVar2 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    uVar1 = *puVar2;
    puVar2 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    *puVar2 = uVar1 & 0xff7f | (ushort)((uint)bStack_31 << 7);
    uVar3 = ((uint)pcStack_30 & 0xff) << 6;
    if ((uVar3 & 0xffffffbf) != 0) {
      r_assert_err(0,"lld_test.c",0x8e);
    }
    puVar2 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    uVar1 = *puVar2;
    puVar2 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    *puVar2 = uVar1 & 0xffbf | (ushort)uVar3;
    pcStack_30 = r_lld_test_frm_cbk;
    uStack_2c = *(undefined4 *)(param_1 + 4);
    uStack_28 = 0;
    uStack_24 = *(undefined4 *)(param_1 + 0x10);
    uStack_20 = 0;
    uStack_14 = 0;
    uStack_1c = *(undefined1 *)(param_1 + 0x16);
    uStack_1b = 0;
    uStack_18 = 0;
    uStack_1a = 0xf00;
    uStack_16 = 0;
    r_sch_prog_push(&pcStack_30);
    *(undefined1 *)(param_1 + 0x2a) = 1;
  }
  return;
}

