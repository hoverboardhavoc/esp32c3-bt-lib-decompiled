/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_evt_start_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_evt_start_cbk(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  ushort uVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  ushort uVar9;
  byte bStack_51;
  code *pcStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  uint uStack_40;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined1 uStack_3a;
  undefined1 uStack_39;
  byte bStack_38;
  undefined1 uStack_37;
  undefined1 uStack_36;
  undefined1 uStack_34;
  
  iVar7 = _lld_init_env;
  if (param_1 != 0) {
    iVar5 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar5 + 0x28) & 0x10) != 0) {
      iVar5 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar5 + 0x2c) < 3) {
        r_ble_log_internal_x1
                  (0x404f0003,
                   CONCAT11(*(undefined1 *)(param_1 + 0x31),*(undefined1 *)(param_1 + 0x52)));
      }
    }
    bVar1 = *(byte *)(param_1 + 0x52);
    uVar8 = (uint)bVar1;
    iVar5 = uVar8 * 0x5a;
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    uVar2 = *(undefined1 *)(param_1 + 0x3e);
    uVar9 = *(ushort *)(iVar6 + iVar5) & 0x1f;
    r_bt_rma_get_ant_by_act(uVar9,uVar8,&bStack_51,&pcStack_50);
    if ((bStack_51 & 0xfe) != 0) {
      r_assert_err(0,0x10000,0x82);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    uVar3 = *(ushort *)(iVar6 + iVar5);
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar6 + iVar5) = uVar3 & 0xff7f | (ushort)bStack_51 << 7;
    if (((uint)pcStack_50 & 0xfe) != 0) {
      r_assert_err(0,0x10000,0x8e);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    uVar3 = *(ushort *)(iVar6 + iVar5);
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar6 + iVar5) = uVar3 & 0xffbf | (ushort)(byte)pcStack_50 << 6;
    uVar4 = r_lld_init_compute_winoffset
                      (*(undefined2 *)(iVar7 + 0xc),*(undefined2 *)(iVar7 + 0xe),uVar2,
                       *(undefined4 *)(param_1 + 4));
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar5 + 0x1e + iVar6) = uVar4;
    uVar4 = r_lld_init_compute_winoffset
                      (*(undefined2 *)(iVar7 + 0x16),*(undefined2 *)(iVar7 + 0x18),uVar2,
                       *(undefined4 *)(param_1 + 4));
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar5 + 0x36 + iVar6) = uVar4;
    uVar4 = r_lld_init_compute_winoffset
                      (*(undefined2 *)(iVar7 + 0x20),*(undefined2 *)(iVar7 + 0x22),uVar2,
                       *(undefined4 *)(param_1 + 4));
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar5 + 0x3a + iVar7) = uVar4;
    r_lld_init_set_tx_power(uVar8,uVar9);
    pcStack_50 = r_lld_init_frm_cbk;
    uStack_4c = *(undefined4 *)(param_1 + 4);
    uStack_48 = *(undefined4 *)(param_1 + 8);
    uStack_3b = 0;
    uStack_34 = 0;
    uStack_40 = (uint)*(byte *)(param_1 + 0x51);
    uStack_37 = 0;
    uStack_44 = *(undefined4 *)(param_1 + 0x10);
    uStack_3c = *(undefined1 *)(param_1 + 0x16);
    uStack_3a = rwip_priority;
    uStack_39 = 0xf;
    uStack_36 = *(char *)(param_1 + 0x3d) == '\x01';
    bStack_38 = bVar1;
    r_sch_prog_push(&pcStack_50);
    r_sch_slice_bg_add(1);
    *(undefined1 *)(param_1 + 0x31) = 1;
    return;
  }
  r_assert_err(0x10000,0x58c);
  return;
}

