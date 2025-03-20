/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_evt_start_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_evt_start_cbk(int param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  undefined2 uVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  short sVar9;
  ushort uVar10;
  uint uVar11;
  uint uVar12;
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
    r_assert_err("lld_con.c",0xb90);
    return;
  }
  bVar1 = *(byte *)(param_1 + 0x8e);
  uVar11 = (uint)bVar1;
  iVar7 = uVar11 * 0x5a;
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  sVar9 = *(short *)(param_1 + 0x7c) + *(short *)(param_1 + 0x7e);
  uVar10 = *(ushort *)(iVar8 + iVar7);
  *(short *)(param_1 + 0x7c) = sVar9;
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(short *)(iVar8 + iVar7 + 0x50) = sVar9;
  r_lld_con_set_tx_power(uVar11,uVar10 & 0x1f);
  r_lld_conn_dynamic_pti_process(*(undefined1 *)(param_1 + 0x8e));
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  r_bt_rma_get_ant_by_act(*(ushort *)(iVar8 + iVar7) & 0x1f,uVar11,&bStack_41,&pcStack_40);
  if (((uint)bStack_41 << 7 & 0xffffff7f) != 0) {
    r_assert_err(0,"lld_con.c",0x82);
  }
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  uVar10 = *(ushort *)(iVar8 + iVar7);
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar8 + iVar7) = uVar10 & 0xff7f | (ushort)((uint)bStack_41 << 7);
  uVar12 = ((uint)pcStack_40 & 0xff) << 6;
  if ((uVar12 & 0xffffffbf) != 0) {
    r_assert_err(0,"lld_con.c",0x8e);
  }
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  uVar10 = *(ushort *)(iVar8 + iVar7);
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar8 + iVar7) = uVar10 & 0xffbf | (ushort)uVar12;
  uVar10 = *(ushort *)(param_1 + 0x84);
  *(ushort *)(param_1 + 0x84) = uVar10 & 0xfeff;
  if ((uVar10 & 0x200) != 0) {
    bVar2 = *(byte *)(param_1 + 0x8d);
    uVar10 = *(ushort *)(param_1 + 0x7e);
    uVar3 = *(ushort *)(param_1 + 0x80);
    iVar8 = r_emi_get_mem_addr_by_offset(0x400);
    uVar4 = *(ushort *)(iVar8 + iVar7 + 0x16);
    iVar8 = r_emi_get_mem_addr_by_offset(0x400);
    uVar10 = (ushort)(((uint)uVar10 * (uint)bVar2 + (uint)uVar3) % 0x25);
    *(ushort *)(iVar8 + iVar7 + 0x16) = uVar4 & 0xffc0 | uVar10;
    *(ushort *)(param_1 + 0x80) = uVar10;
  }
  *(undefined2 *)(param_1 + 0x7e) = 0;
  if ((*(ushort *)(param_1 + 0x84) & 1) != 0) {
    uVar12 = *(int *)(param_1 + 0x4c) + 1U >> 1;
    if (uVar12 < 0x4000) {
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar10 = (ushort)(uVar12 + 1 >> 1);
    }
    else {
      uVar12 = (uVar12 + 0x270) / 0x271;
      if ((int)(uVar12 << 0x10) < 0) {
        r_assert_err(0,"lld_con.c",0x4ab);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar10 = (ushort)uVar12 | 0x8000;
    }
    *(ushort *)(iVar8 + iVar7 + 0x1a) = uVar10;
  }
  if ((*(char *)(param_1 + 0x46) != '\0') &&
     ((ushort)(*(short *)(param_1 + 0x7c) - *(short *)(param_1 + 0x44)) < 0x7fff)) {
    if (*(char *)(param_1 + 0x46) == '\x02') {
      if ((*(byte *)(param_1 + 0x38) & 0xe0) != 0) {
        r_assert_err(0,"lld_con.c",0xab5);
      }
      uVar5 = *(undefined2 *)(param_1 + 0x34);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar8 + iVar7 + 0x22) = uVar5;
      uVar5 = *(undefined2 *)(param_1 + 0x36);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar8 + iVar7 + 0x24) = uVar5;
      bVar2 = *(byte *)(param_1 + 0x38);
      if ((bVar2 & 0xe0) != 0) {
        r_assert_err(0,"lld_con.c",0x64d);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar10 = *(ushort *)(iVar8 + iVar7 + 0x26);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar7 + 0x26) = uVar10 & 0xffe0 | (ushort)bVar2;
    }
    if (*(char *)(param_1 + 0x46) == '\x03') {
      uVar12 = (uint)*(byte *)(param_1 + 0x35) << 2;
      if ((uVar12 & 0xfffffff3) != 0) {
        r_assert_err(0,"lld_con.c",0x1cb);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      iVar7 = iVar7 + 4;
      uVar10 = *(ushort *)(iVar8 + iVar7);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar7) = uVar10 & 0xfff3 | (ushort)uVar12;
      bVar2 = *(byte *)(param_1 + 0x34);
      if ((bVar2 & 0xfc) != 0) {
        r_assert_err(0,"lld_con.c",0x1d7);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar10 = *(ushort *)(iVar8 + iVar7);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar7 + iVar8) = uVar10 & 0xfffc | (ushort)bVar2;
    }
    cVar6 = '\x01';
    if ((*(char *)(param_1 + 0x46) != '\x01') || (cVar6 = *(char *)(param_1 + 0x43), cVar6 != '\0'))
    goto _L532;
  }
  cVar6 = '\0';
_L532:
  pcStack_40 = r_lld_con_frm_cbk;
  uStack_3c = *(undefined4 *)(param_1 + 4);
  uStack_38 = *(undefined4 *)(param_1 + 8);
  uStack_2b = 0;
  uStack_34 = *(undefined4 *)(param_1 + 0x10);
  uStack_26 = 0;
  uStack_24 = 0;
  uStack_2c = *(undefined1 *)(param_1 + 0x16);
  uStack_27 = 0;
  uStack_2a = 0xf00;
  uStack_30 = uVar11;
  bStack_28 = bVar1;
  r_sch_prog_push(&pcStack_40);
  if (*(char *)(param_1 + 0x8f) != '\x02') {
    *(undefined1 *)(param_1 + 0x8f) = 1;
  }
  if (cVar6 != '\0') {
    r_lld_instant_proc_end(*(undefined1 *)(param_1 + 0x8e));
  }
  return;
}

