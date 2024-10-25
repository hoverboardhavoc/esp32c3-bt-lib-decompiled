/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_init.o -> r_lld_init_connect_req_pack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_init_connect_req_pack(undefined1 *param_1,undefined1 *param_2)

{
  undefined2 uVar1;
  
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  param_1[5] = param_2[5];
  param_1[6] = param_2[6];
  param_1[7] = param_2[7];
  uVar1 = *(undefined2 *)(param_2 + 8);
  param_1[8] = (char)uVar1;
  param_1[9] = (char)((ushort)uVar1 >> 8);
  uVar1 = *(undefined2 *)(param_2 + 10);
  param_1[10] = (char)uVar1;
  param_1[0xb] = (char)((ushort)uVar1 >> 8);
  uVar1 = *(undefined2 *)(param_2 + 0xc);
  param_1[0xc] = (char)uVar1;
  param_1[0xd] = (char)((ushort)uVar1 >> 8);
  uVar1 = *(undefined2 *)(param_2 + 0xe);
  param_1[0xe] = (char)uVar1;
  param_1[0xf] = (char)((ushort)uVar1 >> 8);
  param_1[0x10] = param_2[0x10];
  param_1[0x11] = param_2[0x11];
  param_1[0x12] = param_2[0x12];
  param_1[0x13] = param_2[0x13];
  param_1[0x14] = param_2[0x14];
  param_1[0x15] = param_2[0x15];
  return;
}

