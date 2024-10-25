/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_frm_rx_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_sync_frm_rx_isr(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(&lld_sync_env + param_1 * 4) == 0) {
    r_assert_err(0,"lld_sync.c",0x421);
    return;
  }
  iVar3 = *(int *)(&lld_sync_env + param_1 * 4);
  while (iVar2 = r_lld_rxdesc_check_hack(param_1), iVar2 != 0) {
    if (*(ushort *)(iVar3 + 0x52) < 0x673) {
      bVar1 = *(char *)(iVar3 + 99) == '\0';
      r_lld_sync_process_pkt_rx_aux_sync_ind(param_1,bVar1);
      r_lld_sync_process_pkt_rx_pkt_check(param_1,bVar1);
    }
    r_lld_rxdesc_free();
  }
  return;
}

