/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> hci_tl.o -> r_hci_acl_tx_data_alloc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_hci_acl_tx_data_alloc(uint param_1,uint param_2)

{
  int iVar1;
  byte *pbVar2;
  undefined1 *puVar3;
  
  pbVar2 = (byte *)r_sdk_config_get_hl_derived_opts();
  if ((param_1 & 0xfff) < (uint)*pbVar2) {
    iVar1 = 0;
    if (((param_1 >> 0xe == 0) && (param_2 < 0xfc)) &&
       (iVar1 = r_ble_util_buf_acl_tx_alloc(param_2), iVar1 == 0)) {
      puVar3 = (undefined1 *)r_ke_msg_alloc(0x1103,0,0x1a,1);
      *puVar3 = 1;
      r_hci_send_2_host();
      hci_tl_env = 1;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

