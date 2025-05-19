/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_pkt_rx_send_scan_req_evt_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_pkt_rx_send_scan_req_evt_hack(uint param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  undefined1 *puVar7;
  uint uVar8;
  int iVar9;
  undefined1 auStack_34 [8];
  undefined1 auStack_2c [5];
  byte bStack_27;
  
  bVar3 = *(byte *)(_p_lld_env + 0xd8);
  iVar4 = (uint)bVar3 * 0x14;
  iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
  iVar9 = iVar4 + 4;
  uVar1 = *(ushort *)(iVar5 + iVar9);
  iVar5 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar5 + 0x28) & 4) != 0) {
    iVar5 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar5 + 0x2c) < 2) {
      r_ble_log_internal_x1(0x20a00016,(uint)bVar3 << 8 | param_1);
    }
  }
  if ((uVar1 & 0xf) == 3) {
    if (*(char *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x8a) != '\0') {
      iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
      pvVar6 = (void *)r_emi_get_mem_addr_by_offset(*(undefined2 *)(iVar4 + 0x12 + iVar5));
      memcpy(auStack_2c,pvVar6,0xc);
      iVar5 = r_sdk_config_get_opts_ext();
      if ((*(uint *)(iVar5 + 0x28) & 4) != 0) {
        iVar5 = r_sdk_config_get_opts_ext();
        if (*(byte *)(iVar5 + 0x2c) < 2) {
          r_ble_log_internal_hex(0x20a00017,0xc,auStack_2c);
        }
      }
      iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar8 = (uint)*(ushort *)(iVar4 + 0xe + iVar5);
      if (uVar8 == 0) {
        iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
        bVar3 = (byte)(*(ushort *)(iVar4 + iVar9) >> 6) & 1;
      }
      else {
        pvVar6 = (void *)r_emi_get_mem_addr_by_offset(uVar8 + 0x18 & 0xffff);
        memcpy(auStack_34,pvVar6,6);
        iVar4 = r_emi_get_mem_addr_by_offset(0xc60);
        uVar2 = *(undefined2 *)(((uVar8 - 0xc60) / 0x34 & 0xff) * 0x34 + iVar4);
        iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
        bVar3 = (byte)uVar2 & 1;
        if (((*(ushort *)(iVar4 + iVar9) >> 7 & 1) != 0) && ((bStack_27 & 0xc0) == 0x40)) {
          bVar3 = bVar3 | 2;
        }
      }
      puVar7 = (undefined1 *)r_ke_msg_alloc(0x202,0,0xff,8);
      *puVar7 = (char)param_1;
      puVar7[1] = bVar3;
      memcpy(puVar7 + 2,auStack_34,6);
      r_ke_msg_send(puVar7);
      return;
    }
  }
  r_assert_err(0,0x10000,0x849);
  return;
}

