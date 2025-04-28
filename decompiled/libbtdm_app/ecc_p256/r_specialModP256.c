/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ecc_p256.o -> r_specialModP256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_specialModP256(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_4c [36];
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  memset(auStack_4c,0,0x22);
  uStack_28 = 0;
  uStack_24 = 0;
  if (*(int *)(param_1 + 0x28) == 0) {
    uVar3 = *(uint *)(param_1 + 0x24);
    if (uVar3 <= _r_plf_funcs_p) {
      if (uVar3 < _r_plf_funcs_p) {
        return;
      }
      for (uVar3 = 0x11 - uVar3; uVar3 < 0x11; uVar3 = uVar3 + 1) {
        uVar1 = *(ushort *)(uVar3 * 2 + param_1);
        if (uVar1 < *(ushort *)(&bigHexP256 + uVar3 * 2)) {
          return;
        }
        if (*(ushort *)(&bigHexP256 + uVar3 * 2) < uVar1) break;
      }
    }
  }
  else if (*(int *)(param_1 + 0x28) != 1) {
    return;
  }
  if (_r_plf_funcs_p < *(uint *)(param_1 + 0x24)) {
    (**(code **)(_r_modules_funcs_p + 0x3a0))
              (*(undefined2 *)((0x11 - *(uint *)(param_1 + 0x24)) * 2 + param_1),auStack_4c,
               *(code **)(_r_modules_funcs_p + 0x3a0));
    iVar2 = _r_modules_funcs_p;
    if (*(int *)(param_1 + 0x28) == 0) {
      (**(code **)(_r_modules_funcs_p + 0x3bc))
                (param_1,auStack_4c,*(code **)(_r_modules_funcs_p + 0x3bc));
    }
    else {
      *(undefined4 *)(param_1 + 0x28) = 0;
      (**(code **)(iVar2 + 0x3bc))(param_1,auStack_4c,*(code **)(iVar2 + 0x3bc));
      *(undefined4 *)(param_1 + 0x28) = 1;
    }
  }
  if (*(int *)(param_1 + 0x28) == 0) {
    uVar3 = *(uint *)(param_1 + 0x24);
    if (uVar3 <= _r_plf_funcs_p) {
      if (uVar3 < _r_plf_funcs_p) {
        return;
      }
      for (uVar3 = 0x11 - uVar3; uVar3 < 0x11; uVar3 = uVar3 + 1) {
        uVar1 = *(ushort *)(uVar3 * 2 + param_1);
        if (uVar1 < *(ushort *)(&bigHexP256 + uVar3 * 2)) {
          return;
        }
        if (*(ushort *)(&bigHexP256 + uVar3 * 2) < uVar1) break;
      }
    }
    (**(code **)(_r_modules_funcs_p + 0x3b8))
              (param_1,&bigHexP256,*(code **)(_r_modules_funcs_p + 0x3b8));
  }
  else if (*(int *)(param_1 + 0x28) == 1) {
    (**(code **)(_r_modules_funcs_p + 0x358))(param_1,*(code **)(_r_modules_funcs_p + 0x358));
  }
  return;
}

