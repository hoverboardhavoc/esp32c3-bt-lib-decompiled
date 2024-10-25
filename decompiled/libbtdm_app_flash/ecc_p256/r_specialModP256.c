/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> ecc_p256.o -> r_specialModP256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_specialModP256(int param_1)

{
  ushort uVar1;
  uint uVar2;
  undefined1 auStack_3c [36];
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  memset(auStack_3c,0,0x22);
  uStack_18 = 0;
  uStack_14 = 0;
  if (*(int *)(param_1 + 0x28) == 0) {
    uVar2 = *(uint *)(param_1 + 0x24);
    if (uVar2 <= _r_co_list_push_back) {
      if (uVar2 < _r_co_list_push_back) {
        return;
      }
      for (uVar2 = 0x11 - uVar2; uVar2 < 0x11; uVar2 = uVar2 + 1) {
        uVar1 = *(ushort *)(uVar2 * 2 + param_1);
        if (uVar1 < *(ushort *)(&bigHexP256 + uVar2 * 2)) {
          return;
        }
        if (*(ushort *)(&bigHexP256 + uVar2 * 2) < uVar1) break;
      }
    }
  }
  else if (*(int *)(param_1 + 0x28) != 1) {
    return;
  }
  if (_r_co_list_push_back < *(uint *)(param_1 + 0x24)) {
    r_MultiplyByU16ModP256
              (*(undefined2 *)((0x11 - *(uint *)(param_1 + 0x24)) * 2 + param_1),auStack_3c);
    if (*(int *)(param_1 + 0x28) == 0) {
      r_SubtractFromSelfBigHexSign256(param_1,auStack_3c);
    }
    else {
      *(undefined4 *)(param_1 + 0x28) = 0;
      r_SubtractFromSelfBigHexSign256(param_1,auStack_3c);
      *(undefined4 *)(param_1 + 0x28) = 1;
    }
  }
  if (*(int *)(param_1 + 0x28) == 0) {
    uVar2 = *(uint *)(param_1 + 0x24);
    if (uVar2 <= _r_co_list_push_back) {
      if (uVar2 < _r_co_list_push_back) {
        return;
      }
      for (uVar2 = 0x11 - uVar2; uVar2 < 0x11; uVar2 = uVar2 + 1) {
        uVar1 = *(ushort *)(uVar2 * 2 + param_1);
        if (uVar1 < *(ushort *)(&bigHexP256 + uVar2 * 2)) {
          return;
        }
        if (*(ushort *)(&bigHexP256 + uVar2 * 2) < uVar1) break;
      }
    }
    r_SubtractFromSelfBigHex256(param_1,&bigHexP256);
  }
  else if (*(int *)(param_1 + 0x28) == 1) {
    r_AddP256(param_1);
  }
  return;
}

