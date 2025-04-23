/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> hci_tl.o -> r_hci_build_acl_data
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_hci_build_acl_data(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  uVar1 = *(undefined2 *)(param_1 + 0xc);
  iVar2 = *(int *)(param_1 + 0x14);
  *(char *)(iVar2 + -4) = (char)uVar1;
  *(char *)(iVar2 + -3) = (char)((ushort)uVar1 >> 8);
  uVar1 = *(undefined2 *)(param_1 + 0xe);
  *(char *)(iVar2 + -2) = (char)uVar1;
  *(char *)(iVar2 + -1) = (char)((ushort)uVar1 >> 8);
  return;
}

