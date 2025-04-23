/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  char cVar10;
  short sVar11;
  ushort uVar12;
  uint uVar13;
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
  uVar13 = (uint)bVar1;
  iVar6 = uVar13 * 0x5a;
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  sVar11 = *(short *)(param_1 + 0x7c) + *(short *)(param_1 + 0x7e);
  uVar12 = *(ushort *)(iVar8 + iVar6);
  *(short *)(param_1 + 0x7c) = sVar11;
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(short *)(iVar6 + 0x50 + iVar8) = sVar11;
  r_lld_con_set_tx_power(uVar13,uVar12 & 0x1f);
  r_lld_conn_dynamic_pti_process(*(undefined1 *)(param_1 + 0x8e));
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  r_bt_rma_get_ant_by_act(*(ushort *)(iVar8 + iVar6) & 0x1f,uVar13,&bStack_41,&pcStack_40);
  if ((bStack_41 & 0xfe) != 0) {
    r_assert_err(0,"lld_con.c",0x82);
  }
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  uVar12 = *(ushort *)(iVar8 + iVar6);
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar8 + iVar6) = uVar12 & 0xff7f | (ushort)bStack_41 << 7;
  if (((uint)pcStack_40 & 0xfe) != 0) {
    r_assert_err(0,"lld_con.c",0x8e);
  }
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  uVar12 = *(ushort *)(iVar8 + iVar6);
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar8 + iVar6) = uVar12 & 0xffbf | (ushort)(byte)pcStack_40 << 6;
  uVar12 = *(ushort *)(param_1 + 0x84);
  *(ushort *)(param_1 + 0x84) = uVar12 & 0xfeff;
  if ((uVar12 & 0x200) != 0) {
    bVar2 = *(byte *)(param_1 + 0x8d);
    uVar12 = *(ushort *)(param_1 + 0x7e);
    uVar3 = *(ushort *)(param_1 + 0x80);
    iVar8 = r_emi_get_mem_addr_by_offset(0x400);
    uVar4 = *(ushort *)(iVar8 + iVar6 + 0x16);
    iVar8 = r_emi_get_mem_addr_by_offset(0x400);
    uVar12 = (ushort)(((uint)uVar12 * (uint)bVar2 + (uint)uVar3) % 0x25);
    *(ushort *)(iVar8 + iVar6 + 0x16) = uVar12 | uVar4 & 0xffc0;
    *(ushort *)(param_1 + 0x80) = uVar12;
  }
  *(undefined2 *)(param_1 + 0x7e) = 0;
  if ((*(ushort *)(param_1 + 0x84) & 1) != 0) {
    uVar9 = *(int *)(param_1 + 0x4c) + 1U >> 1;
    if (uVar9 < 0x4000) {
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar12 = (ushort)(uVar9 + 1 >> 1);
    }
    else {
      uVar9 = (uVar9 + 0x270) / 0x271;
      if ((int)(uVar9 << 0x10) < 0) {
        r_assert_err(0,"lld_con.c",0x4ab);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar12 = (ushort)uVar9 | 0x8000;
    }
    *(ushort *)(iVar8 + iVar6 + 0x1a) = uVar12;
  }
  cVar10 = '\0';
  if ((*(char *)(param_1 + 0x46) != '\0') &&
     ((ushort)(*(short *)(param_1 + 0x7c) - *(short *)(param_1 + 0x44)) < 0x7fff)) {
    if (*(char *)(param_1 + 0x46) == '\x02') {
      if (0x1f < *(byte *)(param_1 + 0x38)) {
        r_assert_err(0,"lld_con.c",0xab5);
      }
      uVar5 = *(undefined2 *)(param_1 + 0x34);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + 0x22 + iVar8) = uVar5;
      uVar5 = *(undefined2 *)(param_1 + 0x36);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + 0x24 + iVar8) = uVar5;
      bVar2 = *(byte *)(param_1 + 0x38);
      if (0x1f < bVar2) {
        r_assert_err(0,"lld_con.c",0x64d);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar12 = *(ushort *)(iVar8 + iVar6 + 0x26);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar6 + 0x26) = (ushort)bVar2 | uVar12 & 0xffe0;
    }
    if (*(char *)(param_1 + 0x46) == '\x03') {
      bVar2 = *(byte *)(param_1 + 0x35);
      if ((bVar2 & 0xfc) != 0) {
        r_assert_err(0,"lld_con.c",0x1cb);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      iVar6 = iVar6 + 4;
      uVar12 = *(ushort *)(iVar8 + iVar6);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar6) = uVar12 & 0xfff3 | (ushort)bVar2 << 2;
      bVar2 = *(byte *)(param_1 + 0x34);
      if (3 < bVar2) {
        r_assert_err(0,"lld_con.c",0x1d7);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar12 = *(ushort *)(iVar8 + iVar6);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar6) = (ushort)bVar2 | uVar12 & 0xfffc;
    }
    cVar10 = '\x01';
    if (*(char *)(param_1 + 0x46) == '\x01') {
      cVar10 = *(char *)(param_1 + 0x43);
    }
  }
  pcStack_40 = r_lld_con_frm_cbk;
  uStack_3c = *(undefined4 *)(param_1 + 4);
  uStack_2c = *(undefined1 *)(param_1 + 0x16);
  uStack_38 = *(undefined4 *)(param_1 + 8);
  uStack_34 = *(undefined4 *)(param_1 + 0x10);
  uStack_2a = 0xf00;
  uStack_2b = 0;
  uStack_26 = 0;
  uStack_24 = 0;
  uStack_27 = 0;
  uStack_30 = uVar13;
  bStack_28 = bVar1;
  r_sch_prog_push(&pcStack_40);
  if (*(char *)(param_1 + 0x8f) != '\x02') {
    *(undefined1 *)(param_1 + 0x8f) = 1;
  }
  if (cVar10 == '\0') {
    return;
  }
  bVar1 = *(byte *)(param_1 + 0x8e);
  uVar13 = (uint)bVar1;
  iVar6 = *(int *)(&lld_con_env + uVar13 * 4);
  iVar8 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar8 + 0x28) & 0x20) != 0) &&
     (iVar8 = r_sdk_config_get_opts_ext(), *(byte *)(iVar8 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40a30010,CONCAT11(*(undefined1 *)(iVar6 + 0x46),bVar1));
  }
  cVar10 = *(char *)(iVar6 + 0x46);
  if (cVar10 == '\x02') {
    uVar7 = 0x210;
  }
  else {
    if (cVar10 != '\x03') {
      if (cVar10 == '\x01') {
        r_ke_msg_send_basic(0x20f,uVar13 << 8 | 1,0xff);
        r_lld_con_evt_time_update_eco(uVar13);
        r_lld_con_tx_len_update(uVar13,*(undefined1 *)(iVar6 + 0x94),*(undefined4 *)(iVar6 + 100));
      }
      else {
        r_assert_warn(0,0,"lld_con.c",0x81a);
      }
      goto _L283;
    }
    *(undefined1 *)(iVar6 + 0x93) = *(undefined1 *)(iVar6 + 0x35);
    *(undefined1 *)(iVar6 + 0x94) = *(undefined1 *)(iVar6 + 0x34);
    r_lld_con_evt_time_update_eco(uVar13);
    r_lld_con_tx_len_update(uVar13,*(undefined1 *)(iVar6 + 0x94),*(undefined4 *)(iVar6 + 100));
    uVar7 = 0x211;
  }
  r_ke_msg_send_basic(uVar7,uVar13 << 8 | 1,0xff);
_L283:
  *(undefined1 *)(iVar6 + 0x46) = 0;
  return;
}

