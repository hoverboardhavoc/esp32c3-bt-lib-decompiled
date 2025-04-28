/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> aes_k2.o -> r_aes_k2_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_aes_k2_continue(int param_1,void *param_2)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  ushort uVar4;
  code *pcVar5;
  void *pvVar6;
  
  iVar3 = (**(code **)(_r_modules_funcs_p + 0x340))(*(code **)(_r_modules_funcs_p + 0x340));
  if (iVar3 == 0) {
    return 0;
  }
  bVar1 = *(byte *)(param_1 + 0x38);
  if (bVar1 == 2) {
    memcpy((void *)(param_1 + 0x4a),param_2,0x10);
    memcpy((void *)(*(byte *)(param_1 + 0x39) + 0x5a + param_1),param_2,0x10);
    iVar3 = _r_modules_funcs_p;
    uVar2 = 3;
    *(undefined1 *)(param_1 + 0x6a) = 3;
    pcVar5 = *(code **)(iVar3 + 0x344);
    uVar4 = (ushort)*(byte *)(param_1 + 0x39);
  }
  else {
    if (2 < bVar1) {
      if (bVar1 != 3) {
        (**(code **)(_r_plf_funcs_p + 0xc))(0,0x10000,0xbb,*(code **)(_r_plf_funcs_p + 0xc));
        return iVar3;
      }
      pvVar6 = memcpy((void *)(param_1 + 0x3a),param_2,0x10);
      *(byte *)(param_1 + 0x5a) = *(byte *)(param_1 + 0x5a) & 0x7f;
      if (*(code **)(param_1 + 0x34) != (code *)0x0) {
        (**(code **)(param_1 + 0x34))(0,pvVar6,*(undefined4 *)(param_1 + 0x14));
        return iVar3;
      }
      return iVar3;
    }
    pvVar6 = (void *)(param_1 + 0x3a);
    if (bVar1 != 0) {
      memcpy((void *)(param_1 + 0x5a),param_2,0x10);
      memcpy((void *)(*(byte *)(param_1 + 0x39) + 0x5a + param_1),param_2,0x10);
      iVar3 = _r_modules_funcs_p;
      *(undefined1 *)(param_1 + 0x6a) = 2;
      (**(code **)(iVar3 + 0x344))
                (param_1,pvVar6,param_1 + 0x6a,*(undefined1 *)(param_1 + 0x39),
                 *(code **)(iVar3 + 0x344));
      *(undefined1 *)(param_1 + 0x38) = 2;
      return 0;
    }
    memcpy(pvVar6,param_2,0x10);
    (**(code **)(_r_modules_funcs_p + 0x344))
              (param_1,pvVar6,0,0,*(code **)(_r_modules_funcs_p + 0x344));
    iVar3 = _r_modules_funcs_p;
    uVar2 = 1;
    *(undefined1 *)(param_1 + 0x6a) = 1;
    uVar4 = *(byte *)(param_1 + 0x39) - 0x10;
    pcVar5 = *(code **)(iVar3 + 0x344);
  }
  (*pcVar5)(param_1,param_1 + 0x3a,param_1 + 0x6a,uVar4,pcVar5);
  *(undefined1 *)(param_1 + 0x38) = uVar2;
  return 0;
}

