/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_pkt_rx_send_scan_req_evt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_pkt_rx_send_scan_req_evt(uint param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  void *pvVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined1 auStack_34 [8];
  undefined1 auStack_2c [5];
  byte bStack_27;
  
  bVar3 = *(byte *)(_p_lld_env + 0xd8);
  iVar4 = (uint)bVar3 * 0x14;
  iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
  iVar9 = iVar4 + 4;
  uVar1 = *(ushort *)(iVar6 + iVar9);
  iVar6 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar6 + 0x28) & 4) != 0) {
    iVar6 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar6 + 0x2c) < 2) {
      r_ble_log_internal_x1(0x20a00016,(uint)bVar3 << 8 | param_1);
    }
  }
  if (((uVar1 & 0xf) == 3) && (*(char *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x8a) != '\0')) {
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    pvVar7 = (void *)r_emi_get_mem_addr_by_offset(*(undefined2 *)(iVar6 + iVar4 + 0x12));
    memcpy(auStack_2c,pvVar7,0xc);
    iVar6 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar6 + 0x28) & 4) != 0) {
      iVar6 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar6 + 0x2c) < 2) {
        r_ble_log_internal_hex(0x20a00017,0xc,auStack_2c);
      }
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar5 = (uint)*(ushort *)(iVar4 + 0xe + iVar6);
    if (uVar5 == 0) {
      iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
      bVar3 = (byte)(*(ushort *)(iVar4 + iVar9) >> 6) & 1;
    }
    else {
      pvVar7 = (void *)r_emi_get_mem_addr_by_offset(uVar5 + 0x18 & 0xffff);
      memcpy(auStack_34,pvVar7,6);
      iVar4 = r_emi_get_mem_addr_by_offset(0xc60);
      uVar2 = *(undefined2 *)(iVar4 + ((uVar5 - 0xc60) / 0x34 & 0xff) * 0x34);
      iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
      bVar3 = (byte)uVar2 & 1;
      if (((*(ushort *)(iVar4 + iVar9) >> 7 & 1) != 0) && ((bStack_27 & 0xc0) == 0x40)) {
        bVar3 = bVar3 | 2;
      }
    }
    puVar8 = (undefined1 *)r_ke_msg_alloc(0x202,0,0xff,8);
    *puVar8 = (char)param_1;
    puVar8[1] = bVar3;
    memcpy(puVar8 + 2,auStack_34,6);
    r_ke_msg_send(puVar8);
  }
  else {
    r_assert_err(0,"lld_adv.c",0x858);
  }
  return;
}

