/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> ecc_p256.o -> r_AddBigHexModP256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_AddBigHexModP256(void *param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  undefined1 auStack_3c [36];
  undefined4 uStack_18;
  
  r_AddBigHex256();
  if (*(int *)((int)param_1 + 0x28) != 0) {
    r_SubtractBigHex256(&bigHexP256,param_1,auStack_3c);
    memcpy(param_1,auStack_3c,0x22);
    *(undefined4 *)((int)param_1 + 0x28) = 0;
    *(undefined4 *)((int)param_1 + 0x24) = uStack_18;
    return;
  }
  uVar5 = *(uint *)((int)param_1 + 0x24);
  if (uVar5 <= _r_co_list_push_back) {
    if (uVar5 < _r_co_list_push_back) {
      return;
    }
    for (uVar5 = 0x11 - uVar5; uVar5 < 0x11; uVar5 = uVar5 + 1) {
      uVar2 = *(ushort *)(uVar5 * 2 + (int)param_1);
      if (uVar2 < *(ushort *)(&bigHexP256 + uVar5 * 2)) {
        return;
      }
      if (*(ushort *)(&bigHexP256 + uVar5 * 2) < uVar2) break;
    }
  }
  iVar3 = 0x20;
  uVar5 = 0;
  do {
    puVar4 = (ushort *)((int)param_1 + iVar3);
    uVar2 = *puVar4;
    uVar1 = *(ushort *)(&bigHexP256 + iVar3);
    *puVar4 = (ushort)(((uVar2 - uVar5) - (uint)uVar1) * 0x10000 >> 0x10);
    uVar5 = (uint)((uint)uVar2 < uVar5 + uVar1);
    iVar3 = iVar3 + -2;
  } while (iVar3 != -2);
  iVar3 = 0;
  do {
    if (puVar4[iVar3] != 0) break;
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0x11);
  *(int *)(puVar4 + 0x12) = 0x11 - iVar3;
  return;
}

