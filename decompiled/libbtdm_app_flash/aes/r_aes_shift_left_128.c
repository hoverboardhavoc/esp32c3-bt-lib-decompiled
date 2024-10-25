/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> aes.o -> r_aes_shift_left_128
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_aes_shift_left_128(char *param_1,byte *param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  pbVar1 = (byte *)(param_1 + 0xe);
  pbVar2 = param_2 + 0xf;
  do {
    pbVar3 = pbVar2 + -1;
    *pbVar2 = pbVar1[1] << 1 | *pbVar1 >> 7;
    pbVar1 = pbVar1 + -1;
    pbVar2 = pbVar3;
  } while (param_2 != pbVar3);
  *param_2 = *param_1 << 1;
  return;
}

