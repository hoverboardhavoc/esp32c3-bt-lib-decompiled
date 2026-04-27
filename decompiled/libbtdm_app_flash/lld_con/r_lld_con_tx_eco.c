/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_tx_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_tx_eco(uint param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = param_1 * 4;
  iVar4 = *(int *)(&lld_con_env + iVar8);
  bVar1 = *(byte *)(iVar4 + 0x8e);
  bVar2 = *(byte *)(iVar4 + 0x90);
  r_ble_log_internal_x1(0x20e30100,(uint)*(byte *)(iVar4 + 0x92) << 8 | param_1);
  if (*(short *)(iVar4 + 0x84) < 0) {
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar6 = (uint)bVar2 + (uint)bVar1 * 9 & 0xff;
    iVar7 = uVar6 * 0xe;
    if (*(short *)(iVar5 + iVar7) < 0) {
      r_ble_log_internal_x1(0x20e30101,uVar6 << 8 | param_1);
      iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar3 = *(ushort *)(iVar5 + iVar7);
      iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar7 + iVar5) = (ushort)(((uint)uVar3 << 0x11) >> 0x11);
      *(ushort *)(iVar4 + 0x84) = *(ushort *)(iVar4 + 0x84) | 0x800;
    }
  }
  r_lld_con_tx(param_1);
  if (((*(char *)(&lld_con_cntl_pkt_info + param_1) != '\0') &&
      (*(char *)((int)&lld_con_cntl_pkt_info + iVar8 + 2) == '\0')) &&
     (param_1 * 9 + (uint)*(byte *)(iVar4 + 0x90) ==
      (uint)*(byte *)((int)&lld_con_cntl_pkt_info + iVar8 + 1))) {
    uVar3 = *(ushort *)(iVar4 + 0x7c);
    *(undefined1 *)((int)&lld_con_cntl_pkt_info + iVar8 + 2) = 1;
    r_ble_log_internal_x1(0x40a30102,(uint)uVar3 | param_1 << 0x10);
    return;
  }
  return;
}

