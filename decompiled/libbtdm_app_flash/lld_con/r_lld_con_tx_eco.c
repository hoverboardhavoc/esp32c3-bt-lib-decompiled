/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_tx_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_tx_eco(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1 * 4;
  iVar1 = *(int *)(&lld_con_env + iVar2);
  r_ble_log_internal_x1(0x20e300df,(uint)*(byte *)(iVar1 + 0x92) << 8 | param_1);
  r_lld_con_tx(param_1);
  if (((*(char *)(&lld_con_cntl_pkt_info + param_1) != '\0') &&
      (*(char *)((int)&lld_con_cntl_pkt_info + iVar2 + 2) == '\0')) &&
     (param_1 * 9 + (uint)*(byte *)(iVar1 + 0x90) ==
      (uint)*(byte *)((int)&lld_con_cntl_pkt_info + iVar2 + 1))) {
    *(undefined1 *)((int)&lld_con_cntl_pkt_info + iVar2 + 2) = 1;
  }
  return;
}

