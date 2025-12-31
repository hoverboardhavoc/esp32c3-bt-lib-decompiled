/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_frm_rx_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_sync_frm_rx_isr(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(&lld_sync_env + param_1 * 4) == 0) {
    r_assert_err(0,0x10000,0x45e);
    return;
  }
  iVar2 = *(int *)(&lld_sync_env + param_1 * 4);
  while (iVar3 = r_lld_rxdesc_check_hack(param_1), iVar3 != 0) {
    cVar1 = *(char *)(iVar2 + 99);
    if (*(ushort *)(iVar2 + 0x52) < 0x673) {
      r_lld_sync_process_pkt_rx_aux_sync_ind(param_1);
      r_lld_sync_process_pkt_rx_pkt_check(param_1,cVar1 == '\0');
    }
    r_lld_rxdesc_free();
  }
  return;
}

