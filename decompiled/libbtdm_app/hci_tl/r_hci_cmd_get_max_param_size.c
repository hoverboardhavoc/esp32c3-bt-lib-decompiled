/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> hci_tl.o -> r_hci_cmd_get_max_param_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_hci_cmd_get_max_param_size(void)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x90))(*(code **)(_r_ip_funcs_p + 0x90));
  if (iVar2 == 0) {
    uVar1 = 0xff;
  }
  else {
    uVar1 = *(undefined1 *)(iVar2 + 3);
  }
  return uVar1;
}

