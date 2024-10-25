/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> hci.o -> r_hci_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_hci_init(int param_1)

{
  if (param_1 == 0) {
    hci_ext_host = sdk_cfg_priv_opts ^ 1;
  }
  else if (param_1 != 2) goto _L96;
  memset(&hci_env,0,0x22);
  r_hci_evt_mask_set(&_LANCHOR0,3);
  r_hci_evt_mask_set(&_LANCHOR1,4);
  r_hci_fc_init();
_L96:
  r_hci_tl_init(param_1);
  r_hci_register_vendor_desc_tab();
  return;
}

