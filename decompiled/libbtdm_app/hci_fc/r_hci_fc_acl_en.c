/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> hci_fc.o -> r_hci_fc_acl_en
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_hci_fc_acl_en(undefined1 param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  while( true ) {
    iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (*(byte *)(iVar2 + 0xd) <= uVar1) {
      hci_fc_env = param_1;
      return 0;
    }
    if (*(char *)(uVar1 + 0x1101c) != '\0') break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  return 0xc;
}

