/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
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
  uint uVar2;
  ushort *puVar3;
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
    r_assert_err(0,0x10000,0x183);
  }
  if (param_1 != 0) {
    puVar3 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    uVar2 = *puVar3 & 0x1f;
    r_lld_test_set_tx_power(0,uVar2);
    r_ble_log_internal_x3
              (0x40260167,*(undefined4 *)(param_1 + 4),*(int *)(param_1 + 8) << 0x10 | uVar2,0);
    r_bt_rma_get_ant_by_act(uVar2,0,&bStack_31,&pcStack_30);
    if (((uint)bStack_31 << 7 & 0xffffff7f) != 0) {
      r_assert_err(0,0x10000,0x82);
    }
    puVar3 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    uVar1 = *puVar3;
    puVar3 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    *puVar3 = uVar1 & 0xff7f | (ushort)((uint)bStack_31 << 7);
    uVar2 = ((uint)pcStack_30 & 0xff) << 6;
    if ((uVar2 & 0xffffffbf) != 0) {
      r_assert_err(0,0x10000,0x8e);
    }
    puVar3 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    uVar1 = *puVar3;
    puVar3 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    *puVar3 = uVar1 & 0xffbf | (ushort)uVar2;
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
    return;
  }
  r_assert_err(0,0x10000,0x1af);
  return;
}

