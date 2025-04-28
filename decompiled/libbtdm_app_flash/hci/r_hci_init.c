/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  else if (param_1 != 2) goto _L98;
  memset(&hci_env,0,0x22);
  r_hci_evt_mask_set(&hci_def_evt_msk,3);
  r_hci_evt_mask_set(&hci_le_def_evt_msk,4);
  r_hci_fc_init();
_L98:
  r_hci_tl_init(param_1);
  r_hci_register_vendor_desc_tab();
  return;
}

