/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_process_pkt_rx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_sync_process_pkt_rx(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
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

