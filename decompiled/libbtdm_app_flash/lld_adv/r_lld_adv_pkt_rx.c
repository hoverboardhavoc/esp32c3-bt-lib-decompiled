/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_pkt_rx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_adv_pkt_rx(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  ushort uVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  while (iVar2 = r_lld_rxdesc_check_hack(param_1), iVar2 != 0) {
    bVar1 = *(byte *)(_p_lld_env + 0xd8);
    iVar3 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar2 = (uint)bVar1 * 0x14;
    if ((*(ushort *)(iVar3 + iVar2 + 2) & 0x603d) == 0) {
      iVar3 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar4 = *(ushort *)(iVar2 + 4 + iVar3) & 0xf;
      if (uVar4 == 5) {
        uVar5 = r_lld_adv_pkt_rx_connect_ind(param_1);
      }
      else if ((*(char *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x8a) != '\0') && (uVar4 == 3)) {
        r_lld_adv_pkt_rx_send_scan_req_evt(param_1);
      }
    }
    r_lld_rxdesc_free();
  }
  return uVar5;
}

