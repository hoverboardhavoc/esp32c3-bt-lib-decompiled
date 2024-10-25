/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> vhci.o -> API_vhci_host_check_send_available
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool API_vhci_host_check_send_available(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = r_sdk_config_get_opts();
  if ((*(char *)(iVar2 + 0xc) == '\0') ||
     (iVar2 = r_sdk_config_get_opts(), *(char *)(iVar2 + 0x17) != '\x01')) {
    bVar1 = false;
  }
  else {
    bVar1 = _vhci_env_p != 0;
  }
  return bVar1;
}

