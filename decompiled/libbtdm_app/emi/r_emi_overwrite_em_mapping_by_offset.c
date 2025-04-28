/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> emi.o -> r_emi_overwrite_em_mapping_by_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_emi_overwrite_em_mapping_by_offset(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  
  iVar1 = (**(code **)(_r_osi_funcs_p + 0x78))(param_2,*(code **)(_r_osi_funcs_p + 0x78));
  if (iVar1 == 0) {
    return 7;
  }
  uVar2 = (**(code **)(_r_plf_funcs_p + 0xb8))(param_1,*(code **)(_r_plf_funcs_p + 0xb8));
  if (0x37 < uVar2) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x27c1,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((int)uVar2 < 0x30) {
    iVar3 = 0x1800c481;
  }
  else {
    iVar3 = 0x1800c488;
  }
  puVar4 = (uint *)((iVar3 + uVar2) * 4);
  *puVar4 = *puVar4 & 0xfffc0000 | (uint)(iVar1 << 0xc) >> 0xe;
  if (0x37 < uVar2) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x27fa,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((int)uVar2 < 0x20) {
    puVar4 = (uint *)&DAT_600312c4;
  }
  else {
    if ((int)uVar2 < 0x30) {
      puVar4 = (uint *)&DAT_600312c8;
      uVar2 = 1 << (uVar2 - 0x20 & 0x1f);
      uVar2 = ~uVar2 & _DAT_600312c8 | uVar2;
      goto _L119;
    }
    uVar2 = uVar2 - 0x30;
    puVar4 = (uint *)&DAT_60031300;
  }
  uVar2 = 1 << (uVar2 & 0x1f);
  uVar2 = ~uVar2 & *puVar4 | uVar2;
_L119:
  *puVar4 = uVar2;
  return 0;
}

