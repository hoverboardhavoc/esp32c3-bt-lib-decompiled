/*
 * Last changed at upstream commit a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * https://github.com/espressif/esp32c3-bt-lib/commit/a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * Upstream date: 2021-12-28 18:10:18 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (33175c8)
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

