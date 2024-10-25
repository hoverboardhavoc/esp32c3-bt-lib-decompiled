/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> hci_tl.o -> r_hci_build_cs_evt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_hci_build_cs_evt(int param_1)

{
  undefined2 uVar1;
  char cVar2;
  
  *(undefined1 *)(param_1 + 7) = 0xf;
  uVar1 = *(undefined2 *)(param_1 + 8);
  *(undefined1 *)(param_1 + 8) = 4;
  *(undefined1 *)(param_1 + 9) = *(undefined1 *)(param_1 + 0xc);
  cVar2 = hci_tl_env;
  if (hci_tl_env < '\0') {
    cVar2 = '\0';
  }
  *(char *)(param_1 + 0xb) = (char)uVar1;
  *(char *)(param_1 + 10) = cVar2;
  *(char *)(param_1 + 0xc) = (char)((ushort)uVar1 >> 8);
  return param_1 + 7;
}

