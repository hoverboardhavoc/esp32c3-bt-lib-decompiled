/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_rx_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_rx_isr(uint param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  
  if (*(int *)(&lld_con_env + param_1 * 4) == 0) {
    r_assert_param(0,"lld_con.c",0xc6a);
    return;
  }
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  *(ushort *)(iVar2 + 0x84) = *(ushort *)(iVar2 + 0x84) & 0xfffb;
  while (iVar3 = r_lld_rxdesc_check_hack(param_1), iVar3 != 0) {
    uVar7 = (uint)*(byte *)(_p_lld_env + 0xd8);
    iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar6 = uVar7 * 0x14;
    uVar5 = *(ushort *)(iVar6 + 2 + iVar4);
    iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar1 = *(ushort *)(iVar6 + 4 + iVar4);
    r_ble_log_internal_x2(0x20c300e8,CONCAT22(uVar1,uVar5),uVar7 << 8 | param_1);
    if (((uVar5 & 1) == 0) && (r_lld_con_rx_sync_time_update(param_1,iVar2), (uVar5 & 8) == 0)) {
      *(undefined4 *)(iVar2 + 0x58) = *(undefined4 *)(iVar2 + 0x50);
      if ((uVar5 & 0x66) == 0) {
        if ((uVar5 & 0x10) == 0) {
          iVar4 = r_emi_get_mem_addr_by_offset(0x400);
          uVar5 = uVar1 >> 8;
          *(undefined2 *)(iVar2 + 0x98) = *(undefined2 *)(iVar4 + param_1 * 0x5a + 0x50);
          if ((uVar5 != 0) && ((uVar1 & 3) != 0)) {
            if ((4 < uVar5) && ((*(ushort *)(iVar2 + 0x84) & 0x20) != 0)) {
              uVar5 = uVar5 - 4;
            }
            iVar4 = r_lld_con_rx_llcp_check(param_1,iVar2,uVar5);
            if (iVar4 == 0) {
              iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
              *(undefined2 *)(iVar6 + 0x12 + iVar4) = 0;
            }
          }
        }
        else {
          r_ble_log_internal_x1(0x80c300e9,uVar7 << 0x18 | param_1 << 0x10 | (uint)uVar5);
          *(undefined1 *)(iVar2 + 0x8f) = 2;
          *(ushort *)(iVar2 + 0x84) = *(ushort *)(iVar2 + 0x84) | 0x80;
        }
      }
    }
    else {
      iVar3 = 0;
    }
    r_lld_con_rx_channel_assess_hack(iVar2,iVar3);
    r_lld_rxdesc_free();
  }
  return;
}

