/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_process_pkt_rx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_sync_process_pkt_rx(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
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

