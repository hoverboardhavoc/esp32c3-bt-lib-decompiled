/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  uint uVar3;
  undefined1 *puVar4;
  int iVar5;
  byte bVar6;
  undefined1 uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  
  bVar6 = *(byte *)(_p_lld_env + 0xd8);
  puVar4 = (undefined1 *)r_ke_msg_alloc(0x207,0,0xff,0x3c);
  iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
  iVar9 = (uint)bVar6 * 0x14;
  uVar1 = *(ushort *)(iVar9 + 10 + iVar5);
  if ((uVar1 & 0xf000) != 0) {
    r_assert_err(0,0x10000,1000);
  }
  iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar10 = CONCAT22(uVar1,*(undefined2 *)(iVar9 + 8 + iVar5));
  iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar1 = *(ushort *)(iVar9 + 0xc + iVar5);
  iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar8 = (uint)(*(ushort *)(iVar5 + iVar9 + 6) >> 0xe);
  uVar2 = (0x270 - (uVar1 & 0x3ff)) + (uint)*(ushort *)(&lld_exp_sync_pos_tab + uVar8 * 2) * -2;
  uVar3 = (int)(uVar2 * 0x10000) >> 0x10;
  if ((((byte)ke_msg_is_in_queue & 8) != 0) && ((uVar8 - 2 & 0xff) < 2)) {
    uVar3 = (int)(((uVar2 & 0xffff) + (uint)_DAT_000170d6 * -2) * 0x10000) >> 0x10;
  }
  if (0x751 < (uVar3 + 0x4e1 & 0xffff)) {
    r_assert_err(0,0x10000,0x722);
  }
  for (; (int)uVar3 < 0; uVar3 = (int)(((uVar3 & 0xffff) + 0x271) * 0x10000) >> 0x10) {
    uVar10 = uVar10 - 1 & 0xfffffff;
  }
  puVar4[0x35] = 1;
  *puVar4 = (char)param_1;
  puVar4[1] = 0;
  bVar6 = 1;
  if ((*(ushort *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x74) & 0x10) != 0) {
    iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
    bVar6 = (byte)(*(ushort *)(iVar9 + 4 + iVar5) >> 5) & 1;
  }
  puVar4[0x36] = bVar6;
  uVar7 = 0;
  if (*(short *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x78) != 0) {
    uVar7 = *(undefined1 *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x86);
  }
  puVar4[0x38] = uVar7;
  *(undefined2 *)(puVar4 + 2) = *(undefined2 *)(param_2 + 0xc);
  *(undefined2 *)(puVar4 + 4) = *(undefined2 *)(param_2 + 0xe);
  *(undefined2 *)(puVar4 + 6) = *(undefined2 *)(param_2 + 0x10);
  puVar4[8] = *(undefined1 *)(param_2 + 0x12);
  puVar4[0x1b] = *(undefined1 *)(param_2 + 0x13);
  *(undefined2 *)(puVar4 + 0x1c) = *(undefined2 *)(param_2 + 0x14);
  *(undefined2 *)(puVar4 + 0x1e) = *(undefined2 *)(param_2 + 0x16);
  *(undefined2 *)(puVar4 + 0x20) = *(undefined2 *)(param_2 + 0x18);
  *(undefined2 *)(puVar4 + 0x22) = *(undefined2 *)(param_2 + 0x1a);
  memcpy(puVar4 + 0x24,(void *)(param_2 + 0x1c),5);
  bVar6 = *(byte *)(param_2 + 0x21);
  puVar4[0x2a] = bVar6 >> 5;
  puVar4[0x29] = bVar6 & 0x1f;
  memcpy(puVar4 + 9,param_5,6);
  memcpy(puVar4 + 0xf,param_4,6);
  memcpy(puVar4 + 0x15,param_3,6);
  puVar4[0x37] = param_6;
  *(uint *)(puVar4 + 0x30) = uVar10;
  *(short *)(puVar4 + 0x2c) = (short)uVar3;
  iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
  puVar4[0x34] = (byte)((ushort)*(undefined2 *)(iVar5 + iVar9 + 6) >> 0xe);
  r_ke_msg_send(puVar4);
  return;
}

