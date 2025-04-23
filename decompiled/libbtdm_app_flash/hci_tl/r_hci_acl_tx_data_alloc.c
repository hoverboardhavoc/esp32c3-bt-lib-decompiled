/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> hci_tl.o -> r_hci_acl_tx_data_alloc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_hci_acl_tx_data_alloc(uint param_1,uint param_2)

{
  byte *pbVar1;
  int iVar2;
  undefined1 *puVar3;
  
  pbVar1 = (byte *)r_sdk_config_get_hl_derived_opts();
  if (((param_1 & 0xfff) < (uint)*pbVar1) && (param_1 >> 0xe == 0)) {
    iVar2 = 0;
    if ((param_2 < 0xfc) && (iVar2 = r_ble_util_buf_acl_tx_alloc(param_2), iVar2 == 0)) {
      puVar3 = (undefined1 *)r_ke_msg_alloc(0x1103,0,0x1a,1);
      *puVar3 = 1;
      r_hci_send_2_host();
      hci_tl_env = 1;
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}

