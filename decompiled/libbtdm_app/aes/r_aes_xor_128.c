/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> aes.o -> r_aes_xor_128
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_aes_xor_128(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  for (iVar1 = (param_4 + -1) * 0x1000000 >> 0x18; -1 < (char)iVar1; iVar1 = iVar1 + -1) {
    *(byte *)(param_1 + iVar1) = *(byte *)(param_2 + iVar1) ^ *(byte *)(param_3 + iVar1);
  }
  return;
}

