/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ecc_p256.o -> r_specialModP256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_specialModP256(void *param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  uint uVar4;
  int iVar5;
  undefined1 auStack_4c [16];
  undefined1 auStack_3c [20];
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_18;
  
  memset(auStack_4c,0,0x22);
  iVar5 = *(int *)((int)param_1 + 0x28);
  uStack_28 = 0;
  uStack_24 = 0;
  if (iVar5 == 0) {
    uVar4 = *(uint *)((int)param_1 + 0x24);
    if (uVar4 <= _r_co_list_push_back) {
      if (uVar4 < _r_co_list_push_back) {
        return;
      }
      for (uVar4 = 0x11 - uVar4; uVar4 < 0x11; uVar4 = uVar4 + 1) {
        uVar2 = *(ushort *)(uVar4 * 2 + (int)param_1);
        if (uVar2 < *(ushort *)(&bigHexP256 + uVar4 * 2)) {
          return;
        }
        if (*(ushort *)(&bigHexP256 + uVar4 * 2) < uVar2) break;
      }
    }
  }
  else if (iVar5 != 1) {
    return;
  }
  if (_r_co_list_push_back < *(uint *)((int)param_1 + 0x24)) {
    r_MultiplyByU16ModP256
              (*(undefined2 *)((0x11 - *(uint *)((int)param_1 + 0x24)) * 2 + (int)param_1),
               auStack_4c);
    if (iVar5 == 0) {
      r_SubtractFromSelfBigHexSign256(param_1,auStack_4c);
    }
    else {
      *(undefined4 *)((int)param_1 + 0x28) = 0;
      r_SubtractFromSelfBigHexSign256(param_1,auStack_4c);
      *(undefined4 *)((int)param_1 + 0x28) = 1;
    }
  }
  if (*(int *)((int)param_1 + 0x28) != 0) {
    if (*(int *)((int)param_1 + 0x28) != 1) {
      return;
    }
    r_SubtractBigHex256(&bigHexP256,param_1,auStack_3c);
    memcpy(param_1,auStack_3c,0x22);
    *(undefined4 *)((int)param_1 + 0x28) = 0;
    *(undefined4 *)((int)param_1 + 0x24) = uStack_18;
    return;
  }
  uVar4 = *(uint *)((int)param_1 + 0x24);
  if (uVar4 <= _r_co_list_push_back) {
    if (uVar4 < _r_co_list_push_back) {
      return;
    }
    for (uVar4 = 0x11 - uVar4; uVar4 < 0x11; uVar4 = uVar4 + 1) {
      uVar2 = *(ushort *)(uVar4 * 2 + (int)param_1);
      if (uVar2 < *(ushort *)(&bigHexP256 + uVar4 * 2)) {
        return;
      }
      if (*(ushort *)(&bigHexP256 + uVar4 * 2) < uVar2) break;
    }
  }
  iVar5 = 0x20;
  uVar4 = 0;
  do {
    puVar3 = (ushort *)((int)param_1 + iVar5);
    uVar2 = *puVar3;
    uVar1 = *(ushort *)(&bigHexP256 + iVar5);
    iVar5 = iVar5 + -2;
    *puVar3 = (uVar2 - (short)uVar4) - uVar1;
    uVar4 = (uint)((uint)uVar2 < uVar4 + uVar1);
  } while (iVar5 != -2);
  iVar5 = 0;
  do {
    if (*(short *)(iVar5 * 2 + (int)param_1) != 0) break;
    iVar5 = iVar5 + 1;
  } while (iVar5 != 0x11);
  *(int *)((int)param_1 + 0x24) = 0x11 - iVar5;
  return;
}

