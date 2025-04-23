/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ecc_p256.o -> r_SubtractFromSelfBigHexSign256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_SubtractFromSelfBigHexSign256(void *param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  uint uVar4;
  ushort *puVar5;
  int iVar6;
  undefined1 auStack_3c [36];
  undefined4 uStack_18;
  
  if (*(int *)((int)param_1 + 0x28) == 0) {
    if (*(int *)(param_2 + 0x28) == 0) {
      uVar4 = *(uint *)((int)param_1 + 0x24);
      if (uVar4 <= *(uint *)(param_2 + 0x24)) {
        if (uVar4 < *(uint *)(param_2 + 0x24)) {
_L71:
          r_SubtractBigHex256(param_1,auStack_3c);
          memcpy(param_1,auStack_3c,0x22);
          *(undefined4 *)((int)param_1 + 0x24) = uStack_18;
          *(undefined4 *)((int)param_1 + 0x28) = 1;
          return;
        }
        for (uVar4 = 0x11 - uVar4; uVar4 < 0x11; uVar4 = uVar4 + 1) {
          uVar1 = *(ushort *)(param_2 + uVar4 * 2);
          uVar2 = *(ushort *)(uVar4 * 2 + (int)param_1);
          if (uVar2 < uVar1) goto _L71;
          if (uVar1 < uVar2) break;
        }
      }
r_SubtractFromSelfBigHex256:
      iVar6 = 0x20;
      uVar4 = 0;
      do {
        puVar3 = (ushort *)((int)param_1 + iVar6);
        uVar1 = *puVar3;
        uVar2 = *(ushort *)(param_2 + iVar6);
        iVar6 = iVar6 + -2;
        *puVar3 = (uVar1 - (short)uVar4) - uVar2;
        uVar4 = (uint)((uint)uVar1 < uVar4 + uVar2);
      } while (iVar6 != -2);
      iVar6 = 0;
      do {
        if (*(short *)(iVar6 * 2 + (int)param_1) != 0) break;
        iVar6 = iVar6 + 1;
      } while (iVar6 != 0x11);
      *(int *)((int)param_1 + 0x24) = 0x11 - iVar6;
      return;
    }
  }
  else if (*(int *)(param_2 + 0x28) != 0) {
    uVar4 = *(uint *)(param_2 + 0x24);
    if (uVar4 <= *(uint *)((int)param_1 + 0x24)) {
      if (uVar4 < *(uint *)((int)param_1 + 0x24)) goto r_SubtractFromSelfBigHex256;
      for (uVar4 = 0x11 - uVar4; uVar4 < 0x11; uVar4 = uVar4 + 1) {
        uVar1 = *(ushort *)((int)param_1 + uVar4 * 2);
        uVar2 = *(ushort *)(uVar4 * 2 + param_2);
        if (uVar2 < uVar1) goto r_SubtractFromSelfBigHex256;
        if (uVar1 < uVar2) break;
      }
    }
    r_SubtractBigHex256(param_1,auStack_3c);
    memcpy(param_1,auStack_3c,0x22);
    *(undefined4 *)((int)param_1 + 0x28) = 0;
    *(undefined4 *)((int)param_1 + 0x24) = uStack_18;
    return;
  }
  iVar6 = 0x20;
  uVar4 = 0;
  do {
    puVar3 = (ushort *)((int)param_1 + iVar6);
    puVar5 = (ushort *)(param_2 + iVar6);
    iVar6 = iVar6 + -2;
    uVar4 = (uint)*puVar5 + (uint)*puVar3 + uVar4;
    *puVar3 = (ushort)uVar4;
    uVar4 = uVar4 >> 0x10 & 1;
  } while (iVar6 != -2);
  iVar6 = 0;
  do {
    if (puVar3[iVar6] != 0) break;
    iVar6 = iVar6 + 1;
  } while (iVar6 != 0x11);
  *(int *)(puVar3 + 0x12) = 0x11 - iVar6;
  return;
}

