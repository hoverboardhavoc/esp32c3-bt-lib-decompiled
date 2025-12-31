/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
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
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  int iVar6;
  byte bVar7;
  undefined1 uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar11 = (uint)bVar1 * 0x14;
  puVar5 = (undefined1 *)r_ke_msg_alloc(0x207,0,0xff,0x3c);
  iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar2 = *(ushort *)(iVar11 + 10 + iVar6);
  if ((uVar2 & 0xf000) != 0) {
    r_assert_err(0,0x10000,1000);
  }
  iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar10 = CONCAT22(uVar2,*(undefined2 *)(iVar11 + 8 + iVar6));
  iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar2 = *(ushort *)(iVar11 + 0xc + iVar6);
  iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar9 = (uint)(*(ushort *)(iVar6 + iVar11 + 6) >> 0xe);
  uVar3 = (0x270 - (uVar2 & 0x3ff)) + (uint)*(ushort *)(&lld_exp_sync_pos_tab + uVar9 * 2) * -2;
  uVar4 = (int)(uVar3 * 0x10000) >> 0x10;
  if (((rwip_coex_cfg & 8) != 0) && ((uVar9 - 2 & 0xff) < 2)) {
    uVar4 = (int)(((uVar3 & 0xffff) + (uint)_DAT_000170d6 * -2) * 0x10000) >> 0x10;
  }
  if (0x751 < (uVar4 + 0x4e1 & 0xffff)) {
    r_assert_err(0,0x10000,0x758);
  }
  for (; (int)uVar4 < 0; uVar4 = (int)(((uVar4 & 0xffff) + 0x271) * 0x10000) >> 0x10) {
    uVar10 = uVar10 - 1 & 0xfffffff;
  }
  puVar5[0x35] = 1;
  *puVar5 = (char)param_1;
  puVar5[1] = 0;
  bVar7 = 1;
  if ((*(ushort *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x74) & 0x10) != 0) {
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    bVar7 = (byte)(*(ushort *)(iVar6 + iVar11 + 4) >> 5) & 1;
  }
  puVar5[0x36] = bVar7;
  uVar8 = 0;
  if (*(short *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x78) != 0) {
    uVar8 = *(undefined1 *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x86);
  }
  puVar5[0x38] = uVar8;
  *(undefined2 *)(puVar5 + 2) = *(undefined2 *)(param_2 + 0xc);
  *(undefined2 *)(puVar5 + 4) = *(undefined2 *)(param_2 + 0xe);
  *(undefined2 *)(puVar5 + 6) = *(undefined2 *)(param_2 + 0x10);
  puVar5[8] = *(undefined1 *)(param_2 + 0x12);
  puVar5[0x1b] = *(undefined1 *)(param_2 + 0x13);
  *(undefined2 *)(puVar5 + 0x1c) = *(undefined2 *)(param_2 + 0x14);
  *(undefined2 *)(puVar5 + 0x1e) = *(undefined2 *)(param_2 + 0x16);
  *(undefined2 *)(puVar5 + 0x20) = *(undefined2 *)(param_2 + 0x18);
  *(undefined2 *)(puVar5 + 0x22) = *(undefined2 *)(param_2 + 0x1a);
  memcpy(puVar5 + 0x24,(void *)(param_2 + 0x1c),5);
  bVar7 = *(byte *)(param_2 + 0x21);
  puVar5[0x29] = bVar7 & 0x1f;
  puVar5[0x2a] = bVar7 >> 5;
  memcpy(puVar5 + 9,param_5,6);
  memcpy(puVar5 + 0xf,param_4,6);
  memcpy(puVar5 + 0x15,param_3,6);
  *(uint *)(puVar5 + 0x30) = uVar10;
  *(short *)(puVar5 + 0x2c) = (short)uVar4;
  puVar5[0x37] = param_6;
  iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
  puVar5[0x34] = (byte)((ushort)*(undefined2 *)(iVar6 + iVar11 + 6) >> 0xe);
  r_ke_msg_send(puVar5);
  iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar3 = uVar4 + uVar10 * 0x271;
  r_ble_log_internal_x2
            (0x40a000c4,
             ((uint)(uVar3 < uVar10 * 0x271) +
             (int)((ulonglong)uVar10 * 0x271 >> 0x20) + ((int)uVar4 >> 0x1f)) * -0x80000000 |
             uVar3 >> 1,
             param_1 << 0x10 | (uint)bVar1 << 0x18 | (uint)*(ushort *)(iVar6 + iVar11 + 4));
  return;
}

