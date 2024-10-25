/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> vhci.o -> r_vhci_check_packet_allow
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_vhci_check_packet_allow(uint param_1)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = r_sdk_config_get_opts();
  if (*(char *)(iVar1 + 0xc) == '\0') {
    if (_g_bt_plf_log_level < 3) {
      return 0;
    }
    pcVar2 = "VHCI: Controller is not run\n";
  }
  else {
    if (param_1 < 0x105) {
      return 1;
    }
    if (_g_bt_plf_log_level < 3) {
      return 0;
    }
    pcVar2 = "VHCI: Packet length not supported\n";
  }
  ets_printf(pcVar2);
  return 0;
}

