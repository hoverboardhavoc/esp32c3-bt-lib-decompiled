/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
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
  int iVar3;
  
  iVar3 = param_1 * 4;
  iVar1 = *(int *)(&lld_con_env + iVar3);
  iVar2 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar2 + 0x28) & 0x20) != 0) {
    iVar2 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar2 + 0x2c) < 3) {
      r_ble_log_internal_x1(0x40e30012,(uint)*(byte *)(iVar1 + 0x92) << 8 | param_1);
    }
  }
  r_lld_con_tx(param_1);
  if (((*(char *)(&lld_con_cntl_pkt_info + param_1) != '\0') &&
      (*(char *)((int)&lld_con_cntl_pkt_info + iVar3 + 2) == '\0')) &&
     (param_1 * 9 + (uint)*(byte *)(iVar1 + 0x90) ==
      (uint)*(byte *)((int)&lld_con_cntl_pkt_info + iVar3 + 1))) {
    *(undefined1 *)((int)&lld_con_cntl_pkt_info + iVar3 + 2) = 1;
  }
  return;
}

