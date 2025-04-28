/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  char cVar6;
  short sVar7;
  ushort uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
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
  uVar12 = (uint)bVar1;
  iVar11 = uVar12 * 0x5a;
  iVar10 = r_emi_get_mem_addr_by_offset(0x400);
  sVar7 = *(short *)(param_1 + 0x7c) + *(short *)(param_1 + 0x7e);
  uVar8 = *(ushort *)(iVar10 + iVar11);
  *(short *)(param_1 + 0x7c) = sVar7;
  iVar10 = r_emi_get_mem_addr_by_offset(0x400);
  *(short *)(iVar11 + 0x50 + iVar10) = sVar7;
  r_lld_con_set_tx_power(uVar12,uVar8 & 0x1f);
  r_lld_conn_dynamic_pti_process(*(undefined1 *)(param_1 + 0x8e));
  iVar10 = r_emi_get_mem_addr_by_offset(0x400);
  r_bt_rma_get_ant_by_act(*(ushort *)(iVar10 + iVar11) & 0x1f,uVar12,&bStack_41,&pcStack_40);
  if (((uint)bStack_41 << 7 & 0xffffff7f) != 0) {
    r_assert_err(0,"lld_con.c",0x82);
  }
  iVar10 = r_emi_get_mem_addr_by_offset(0x400);
  uVar8 = *(ushort *)(iVar10 + iVar11);
  iVar10 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar10 + iVar11) = uVar8 & 0xff7f | (ushort)((uint)bStack_41 << 7);
  uVar13 = ((uint)pcStack_40 & 0xff) << 6;
  if ((uVar13 & 0xffffffbf) != 0) {
    r_assert_err(0,"lld_con.c",0x8e);
  }
  iVar10 = r_emi_get_mem_addr_by_offset(0x400);
  uVar8 = *(ushort *)(iVar10 + iVar11);
  iVar10 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar10 + iVar11) = uVar8 & 0xffbf | (ushort)uVar13;
  uVar8 = *(ushort *)(param_1 + 0x84);
  *(ushort *)(param_1 + 0x84) = uVar8 & 0xfeff;
  if ((uVar8 & 0x200) != 0) {
    bVar2 = *(byte *)(param_1 + 0x8d);
    uVar8 = *(ushort *)(param_1 + 0x7e);
    uVar3 = *(ushort *)(param_1 + 0x80);
    iVar10 = r_emi_get_mem_addr_by_offset(0x400);
    uVar4 = *(ushort *)(iVar10 + iVar11 + 0x16);
    iVar10 = r_emi_get_mem_addr_by_offset(0x400);
    uVar8 = (ushort)(((uint)uVar8 * (uint)bVar2 + (uint)uVar3) % 0x25);
    *(ushort *)(iVar11 + 0x16 + iVar10) = uVar4 & 0xffc0 | uVar8;
    *(ushort *)(param_1 + 0x80) = uVar8;
  }
  *(undefined2 *)(param_1 + 0x7e) = 0;
  if ((*(ushort *)(param_1 + 0x84) & 1) != 0) {
    uVar13 = *(int *)(param_1 + 0x4c) + 1U >> 1;
    if (uVar13 < 0x4000) {
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      uVar8 = (ushort)(uVar13 + 1 >> 1);
    }
    else {
      uVar13 = (uVar13 + 0x270) / 0x271;
      if ((uVar13 >> 0xf & 1) != 0) {
        r_assert_err(0,"lld_con.c",0x4ab);
      }
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      uVar8 = (ushort)uVar13 | 0x8000;
    }
    *(ushort *)(iVar10 + iVar11 + 0x1a) = uVar8;
  }
  if ((*(char *)(param_1 + 0x46) == '\0') ||
     (0x7ffe < (ushort)(*(short *)(param_1 + 0x7c) - *(short *)(param_1 + 0x44)))) {
_L514:
    cVar6 = '\0';
  }
  else {
    if (*(char *)(param_1 + 0x46) == '\x02') {
      if ((*(byte *)(param_1 + 0x38) & 0xe0) != 0) {
        r_assert_err(0,"lld_con.c",0xab5);
      }
      uVar5 = *(undefined2 *)(param_1 + 0x34);
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar11 + 0x22 + iVar10) = uVar5;
      uVar5 = *(undefined2 *)(param_1 + 0x36);
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar11 + 0x24 + iVar10) = uVar5;
      bVar2 = *(byte *)(param_1 + 0x38);
      if ((bVar2 & 0xe0) != 0) {
        r_assert_err(0,"lld_con.c",0x64d);
      }
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      uVar8 = *(ushort *)(iVar10 + iVar11 + 0x26);
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar10 + iVar11 + 0x26) = uVar8 & 0xffe0 | (ushort)bVar2;
    }
    if (*(char *)(param_1 + 0x46) == '\x03') {
      uVar13 = (uint)*(byte *)(param_1 + 0x35) << 2;
      if ((uVar13 & 0xfffffff3) != 0) {
        r_assert_err(0,"lld_con.c",0x1cb);
      }
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      iVar11 = iVar11 + 4;
      uVar8 = *(ushort *)(iVar10 + iVar11);
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar10 + iVar11) = uVar8 & 0xfff3 | (ushort)uVar13;
      bVar2 = *(byte *)(param_1 + 0x34);
      if ((bVar2 & 0xfc) != 0) {
        r_assert_err(0,"lld_con.c",0x1d7);
      }
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      uVar8 = *(ushort *)(iVar10 + iVar11);
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar10 + iVar11) = uVar8 & 0xfffc | (ushort)bVar2;
    }
    cVar6 = '\x01';
    if ((*(char *)(param_1 + 0x46) == '\x01') && (cVar6 = *(char *)(param_1 + 0x43), cVar6 == '\0'))
    goto _L514;
  }
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
  uStack_30 = uVar12;
  bStack_28 = bVar1;
  r_sch_prog_push(&pcStack_40);
  if (*(char *)(param_1 + 0x8f) != '\x02') {
    *(undefined1 *)(param_1 + 0x8f) = 1;
  }
  if (cVar6 == '\0') {
    return;
  }
  bVar1 = *(byte *)(param_1 + 0x8e);
  uVar12 = (uint)bVar1;
  iVar10 = *(int *)(&lld_con_env + uVar12 * 4);
  iVar11 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar11 + 0x28) & 0x20) != 0) &&
     (iVar11 = r_sdk_config_get_opts_ext(), *(byte *)(iVar11 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40a30010,CONCAT11(*(undefined1 *)(iVar10 + 0x46),bVar1));
  }
  cVar6 = *(char *)(iVar10 + 0x46);
  if (cVar6 == '\x02') {
    uVar9 = 0x210;
  }
  else {
    if (cVar6 != '\x03') {
      if (cVar6 == '\x01') {
        r_ke_msg_send_basic(0x20f,uVar12 << 8 | 1,0xff);
        r_lld_con_evt_time_update_eco(uVar12);
        r_lld_con_tx_len_update(uVar12,*(undefined1 *)(iVar10 + 0x94),*(undefined4 *)(iVar10 + 100))
        ;
      }
      else {
        r_assert_warn(0,0,"lld_con.c",0x81a);
      }
      goto _L282;
    }
    *(undefined1 *)(iVar10 + 0x93) = *(undefined1 *)(iVar10 + 0x35);
    *(undefined1 *)(iVar10 + 0x94) = *(undefined1 *)(iVar10 + 0x34);
    r_lld_con_evt_time_update_eco(uVar12);
    r_lld_con_tx_len_update(uVar12,*(undefined1 *)(iVar10 + 0x94),*(undefined4 *)(iVar10 + 100));
    uVar9 = 0x211;
  }
  r_ke_msg_send_basic(uVar9,uVar12 << 8 | 1,0xff);
_L282:
  *(undefined1 *)(iVar10 + 0x46) = 0;
  return;
}

