/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_pkt_rx_connect_post
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_pkt_rx_connect_post
               (int param_1,int param_2,void *param_3,void *param_4,void *param_5,undefined1 param_6
               )

{
  ushort uVar1;
  uint uVar2;
  undefined1 *puVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  undefined1 uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  
  bVar5 = *(byte *)(_p_lld_env + 0xd8);
  puVar3 = (undefined1 *)r_ke_msg_alloc(0x207,0,0xff,0x3c);
  iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
  iVar9 = (uint)bVar5 * 0x14;
  uVar1 = *(ushort *)(iVar4 + iVar9 + 10);
  if ((uVar1 & 0xf000) != 0) {
    r_assert_err(0,"lld_adv.c",1000);
  }
  iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar2 = CONCAT22(uVar1,*(undefined2 *)(iVar4 + iVar9 + 8));
  iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar1 = *(ushort *)(iVar4 + iVar9 + 0xc);
  iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar6 = (uint)(*(ushort *)(iVar4 + iVar9 + 6) >> 0xe);
  uVar8 = (0x270 - (uVar1 & 0x3ff)) + (uint)*(ushort *)(&lld_exp_sync_pos_tab + uVar6 * 2) * -2;
  uVar10 = (uint)(short)uVar8;
  if ((((byte)r_lld_read_clock & 8) != 0) && ((uVar6 - 2 & 0xff) < 2)) {
    uVar10 = (int)(((uVar8 & 0xffff) + (uint)_DAT_000160ce * -2) * 0x10000) >> 0x10;
  }
  if (0x751 < (uVar10 + 0x4e1 & 0xffff)) {
    r_assert_err(0,"lld_adv.c",0x71a);
  }
  for (; (int)uVar10 < 0; uVar10 = (int)(((uVar10 & 0xffff) + 0x271) * 0x10000) >> 0x10) {
    uVar2 = uVar2 - 1 & 0xfffffff;
  }
  puVar3[0x35] = 1;
  *puVar3 = (char)param_1;
  puVar3[1] = 0;
  bVar5 = 1;
  if ((*(ushort *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x74) & 0x10) != 0) {
    iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
    bVar5 = (byte)(*(ushort *)(iVar9 + 4 + iVar4) >> 5) & 1;
  }
  puVar3[0x36] = bVar5;
  uVar7 = 0;
  if (*(short *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x78) != 0) {
    uVar7 = *(undefined1 *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x86);
  }
  puVar3[0x38] = uVar7;
  *(undefined2 *)(puVar3 + 2) = *(undefined2 *)(param_2 + 0xc);
  *(undefined2 *)(puVar3 + 4) = *(undefined2 *)(param_2 + 0xe);
  *(undefined2 *)(puVar3 + 6) = *(undefined2 *)(param_2 + 0x10);
  puVar3[8] = *(undefined1 *)(param_2 + 0x12);
  puVar3[0x1b] = *(undefined1 *)(param_2 + 0x13);
  *(undefined2 *)(puVar3 + 0x1c) = *(undefined2 *)(param_2 + 0x14);
  *(undefined2 *)(puVar3 + 0x1e) = *(undefined2 *)(param_2 + 0x16);
  *(undefined2 *)(puVar3 + 0x20) = *(undefined2 *)(param_2 + 0x18);
  *(undefined2 *)(puVar3 + 0x22) = *(undefined2 *)(param_2 + 0x1a);
  memcpy(puVar3 + 0x24,(void *)(param_2 + 0x1c),5);
  bVar5 = *(byte *)(param_2 + 0x21);
  puVar3[0x2a] = bVar5 >> 5;
  puVar3[0x29] = bVar5 & 0x1f;
  memcpy(puVar3 + 9,param_5,6);
  memcpy(puVar3 + 0xf,param_4,6);
  memcpy(puVar3 + 0x15,param_3,6);
  puVar3[0x37] = param_6;
  *(uint *)(puVar3 + 0x30) = uVar2;
  *(short *)(puVar3 + 0x2c) = (short)uVar10;
  iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
  puVar3[0x34] = (byte)((ushort)*(undefined2 *)(iVar4 + iVar9 + 6) >> 0xe);
  r_ke_msg_send(puVar3);
  return;
}

