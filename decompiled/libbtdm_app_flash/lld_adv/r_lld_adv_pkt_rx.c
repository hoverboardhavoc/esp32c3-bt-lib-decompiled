/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_pkt_rx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_adv_pkt_rx(uint param_1)

{
  byte bVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  while (iVar2 = r_lld_rxdesc_check_hack(param_1), iVar2 != 0) {
    bVar1 = *(byte *)(_p_lld_env + 0xd8);
    iVar2 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar4 = (uint)bVar1 * 0x14;
    uVar3 = *(ushort *)(iVar4 + 2 + iVar2);
    iVar4 = iVar4 + 4;
    iVar2 = r_emi_get_mem_addr_by_offset(0x1000);
    r_ble_log_internal_x2
              (0x20a000cd,CONCAT22(*(undefined2 *)(iVar2 + iVar4),uVar3),(uint)bVar1 << 8 | param_1)
    ;
    if ((uVar3 & 0x603d) == 0) {
      iVar2 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar3 = *(ushort *)(iVar2 + iVar4) & 0xf;
      if (uVar3 == 5) {
        uVar5 = r_lld_adv_pkt_rx_connect_ind_hack(param_1);
      }
      else if ((*(char *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x8a) != '\0') && (uVar3 == 3)) {
        r_lld_adv_pkt_rx_send_scan_req_evt_hack(param_1);
      }
    }
    r_lld_rxdesc_free();
  }
  return uVar5;
}

