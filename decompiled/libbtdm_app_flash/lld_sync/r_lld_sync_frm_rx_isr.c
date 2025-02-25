/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
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
    r_assert_err(0,"lld_sync.c",0x433);
    return;
  }
  iVar2 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar2 + 0x28) & 0x80) != 0) &&
     (iVar2 = r_sdk_config_get_opts_ext(), *(byte *)(iVar2 + 0x2c) < 2)) {
    r_ble_log_internal_x1(0x20a2000c,param_1);
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

