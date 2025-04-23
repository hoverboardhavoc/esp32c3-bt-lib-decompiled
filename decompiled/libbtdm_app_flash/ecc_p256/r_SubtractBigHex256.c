/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ecc_p256.o -> r_SubtractBigHex256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_SubtractBigHex256(int param_1,int param_2,int param_3)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0x20;
  uVar2 = 0;
  do {
    sVar1 = (short)uVar2;
    uVar2 = (uint)((uint)*(ushort *)(param_1 + iVar3) < uVar2 + *(ushort *)(param_2 + iVar3));
    *(ushort *)(param_3 + iVar3) =
         (*(ushort *)(param_1 + iVar3) - sVar1) - *(ushort *)(param_2 + iVar3);
    iVar3 = iVar3 + -2;
  } while (iVar3 != -2);
  iVar3 = 0;
  do {
    if (*(short *)(iVar3 * 2 + param_3) != 0) break;
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0x11);
  *(int *)(param_3 + 0x24) = 0x11 - iVar3;
  return;
}

