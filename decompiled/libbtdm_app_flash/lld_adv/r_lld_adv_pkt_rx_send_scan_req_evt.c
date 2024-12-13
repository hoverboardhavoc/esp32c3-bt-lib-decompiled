/*
 * Last changed at upstream commit c57c0b11c3c0065a16b66685715100a189ef9b27
 * https://github.com/espressif/esp32c3-bt-lib/commit/c57c0b11c3c0065a16b66685715100a189ef9b27
 * Upstream date: 2024-12-13 13:39:25 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(555b0a2)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_pkt_rx_send_scan_req_evt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_pkt_rx_send_scan_req_evt(int param_1)

{
  undefined2 uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  void *pvVar6;
  undefined1 *puVar7;
  undefined1 auStack_34 [8];
  undefined1 auStack_2c [24];
  
  bVar2 = *(byte *)(_p_lld_env + 0xd8);
  iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
  iVar3 = (uint)bVar2 * 0x14;
  if ((*(ushort *)(iVar5 + iVar3 + 4) & 0xf) == 3) {
    if (*(char *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x8a) != '\0') {
      iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
      pvVar6 = (void *)r_emi_get_mem_addr_by_offset(*(undefined2 *)(iVar5 + iVar3 + 0x12));
      memcpy(auStack_2c,pvVar6,0xc);
      iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar4 = (uint)*(ushort *)(iVar3 + 0xe + iVar5);
      if (uVar4 == 0) {
        iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
        bVar2 = (byte)(*(ushort *)(iVar5 + iVar3 + 4) >> 6) & 1;
      }
      else {
        pvVar6 = (void *)r_emi_get_mem_addr_by_offset(uVar4 + 0x18 & 0xffff);
        memcpy(auStack_34,pvVar6,6);
        iVar5 = r_emi_get_mem_addr_by_offset(0xc60);
        iVar3 = ((uVar4 - 0xc60) / 0x34 & 0xff) * 0x34;
        uVar1 = *(undefined2 *)(iVar5 + iVar3);
        iVar5 = r_emi_get_mem_addr_by_offset(0xc60);
        bVar2 = (byte)*(undefined2 *)(iVar5 + iVar3) & 2 | (byte)uVar1 & 1;
      }
      puVar7 = (undefined1 *)r_ke_msg_alloc(0x202,0,0xff,8);
      *puVar7 = (char)param_1;
      puVar7[1] = bVar2;
      memcpy(puVar7 + 2,auStack_34,6);
      r_ke_msg_send(puVar7);
      return;
    }
  }
  r_assert_err(0,"lld_adv.c",0x839);
  return;
}

