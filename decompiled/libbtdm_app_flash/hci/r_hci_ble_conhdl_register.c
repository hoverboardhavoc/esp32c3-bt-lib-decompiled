/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> hci.o -> r_hci_ble_conhdl_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_hci_ble_conhdl_register(uint param_1)

{
  int iVar1;
  
  iVar1 = r_sdk_config_get_opts();
  if (*(byte *)(iVar1 + 0xd) <= param_1) {
    iVar1 = r_sdk_config_get_opts();
    r_assert_param(param_1,*(undefined1 *)(iVar1 + 0xd),"hci.c",0x4ec);
  }
  if (r_hci_look_for_evt_desc[param_1] != (code)0x0) {
    r_assert_err(0,"hci.c",0x4ed);
  }
  r_hci_look_for_evt_desc[param_1] = (code)0x1;
  return;
}

