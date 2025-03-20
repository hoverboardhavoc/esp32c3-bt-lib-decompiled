/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
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
      bVar1 = *(char *)(iVar2 + 99) == '\0';
      r_lld_sync_process_pkt_rx_aux_sync_ind(param_1,bVar1);
      r_lld_sync_process_pkt_rx_pkt_check(param_1,bVar1);
    }
    r_lld_rxdesc_free();
  }
  return;
}

