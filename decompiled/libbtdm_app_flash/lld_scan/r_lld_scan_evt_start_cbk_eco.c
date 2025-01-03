/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_evt_start_cbk_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_evt_start_cbk_eco(int param_1)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  uint uVar7;
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
  uint uStack_24;
  
  uVar3 = r_ble_ll_qa_config_get();
  if (param_1 != 0) {
    if (*(uint *)(param_1 + 0x24) == (uint)*(ushort *)(param_1 + 0x32)) {
      uStack_24 = uVar3;
      r_llm_update_duplicate_scan_count();
      uVar3 = uStack_24;
    }
    uVar6 = *(ushort *)(uVar3 + 0x18);
    if (uVar6 != 0) {
      bVar1 = *(byte *)(param_1 + 0x38);
      if ((uVar6 & 0xc0) != 0) {
        r_assert_err(0,"lld_scan.c",0x3cf);
      }
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      iVar5 = (uint)bVar1 * 0x5a + 0x16;
      uVar2 = *(ushort *)(iVar4 + iVar5);
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar4 + iVar5) = uVar2 & 0xffc0 | uVar6 & 0xff;
    }
    if ((*(byte *)(_lld_scan_env + 0xc) & 3) == 3) {
      lld_scan_sched_optimize_part_0(param_1,0xffffffff);
    }
  }
  if ((((g_scan_forever != '\0') && (param_1 != 0)) && (*(char *)(param_1 + 0x3c) != '\x02')) &&
     (bVar1 = *(byte *)(param_1 + 0x38), iVar4 = r_emi_get_mem_addr_by_offset(0x400),
     *(short *)(iVar4 + (uint)bVar1 * 0x5a + 0x20) != 1)) {
    bVar1 = *(byte *)(param_1 + 0x38);
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar4 + (uint)bVar1 * 0x5a + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0xffffffff;
  }
  if (param_1 == 0) {
    r_assert_err("lld_scan.c",0xa5c);
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x38);
    uVar3 = (uint)bVar1;
    iVar5 = uVar3 * 0x5a;
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    uVar6 = *(ushort *)(iVar4 + iVar5) & 0x1f;
    if (*(char *)(param_1 + 0x3e) != '\x01') {
      uVar7 = 0;
      if (_lld_scan_sync_env != 0) {
        uVar7 = (uint)(*(char *)(_lld_scan_sync_env + 1) != '\0');
      }
      *(char *)(param_1 + 0x44) = (char)uVar7;
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      uVar2 = *(ushort *)(iVar4 + iVar5 + 0x14);
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar4 + iVar5 + 0x14) = uVar2 & 0xfff7 | (ushort)(uVar7 << 3);
    }
    r_bt_rma_get_ant_by_act(uVar6,uVar3,&bStack_41,&pcStack_40);
    if (((uint)bStack_41 << 7 & 0xffffff7f) != 0) {
      r_assert_err(0,"lld_scan.c",0x82);
    }
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    uVar2 = *(ushort *)(iVar4 + iVar5);
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar4 + iVar5) = uVar2 & 0xff7f | (ushort)((uint)bStack_41 << 7);
    uVar7 = ((uint)pcStack_40 & 0xff) << 6;
    if ((uVar7 & 0xffffffbf) != 0) {
      r_assert_err(0,"lld_scan.c",0x8e);
    }
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    uVar2 = *(ushort *)(iVar4 + iVar5);
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar4 + iVar5) = uVar2 & 0xffbf | (ushort)uVar7;
    r_lld_scan_set_tx_power(uVar3,uVar6);
    pcStack_40 = r_lld_scan_frm_cbk;
    uStack_3c = *(undefined4 *)(param_1 + 4);
    uStack_38 = *(undefined4 *)(param_1 + 8);
    uStack_2b = 0;
    uStack_24 = uStack_24 & 0xffffff00;
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
  }
  return;
}

