/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ecc_p256.o -> r_SubtractFromSelfBigHex256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_SubtractFromSelfBigHex256(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 0x20;
  uVar4 = 0;
  do {
    puVar3 = (ushort *)(param_1 + iVar5);
    uVar1 = *puVar3;
    uVar2 = *(ushort *)(param_2 + iVar5);
    iVar5 = iVar5 + -2;
    *puVar3 = (uVar1 - (short)uVar4) - uVar2;
    uVar4 = (uint)((uint)uVar1 < uVar4 + uVar2);
  } while (iVar5 != -2);
  iVar5 = 0;
  do {
    if (*(short *)(iVar5 * 2 + param_1) != 0) break;
    iVar5 = iVar5 + 1;
  } while (iVar5 != 0x11);
  *(int *)(param_1 + 0x24) = 0x11 - iVar5;
  return;
}

