/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  
  iVar2 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar2 + 0x28) & 0x80) != 0) {
    iVar2 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar2 + 0x2c) < 2) {
      r_ble_log_internal_x1(0x20a2000c,param_1);
    }
  }
  iVar2 = *(int *)(&lld_sync_env + param_1 * 4);
  while (iVar3 = r_lld_rxdesc_check_hack(param_1), iVar3 != 0) {
    if (*(ushort *)(iVar2 + 0x52) < 0x673) {
      cVar1 = *(char *)(iVar2 + 99);
      r_lld_sync_process_pkt_rx_aux_sync_ind(param_1);
      r_lld_sync_process_pkt_rx_pkt_check(param_1,cVar1 == '\0');
    }
    r_lld_rxdesc_free();
  }
  return;
}

