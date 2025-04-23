/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> emi.o -> emi_reset_em_mapping_by_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void emi_reset_em_mapping_by_offset(void)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = (**(code **)(_r_plf_funcs_p + 0xb8))(*(code **)(_r_plf_funcs_p + 0xb8));
  uVar4 = _DAT_600312c4;
  uVar5 = uVar3;
  if (0x1f < (int)uVar3) {
    if ((int)uVar3 < 0x30) {
      uVar4 = _DAT_600312c8;
      uVar5 = uVar3 - 0x20;
    }
    else {
      uVar4 = _DAT_60031300;
      uVar5 = uVar3 - 0x30;
    }
  }
  if (((1 << (uVar5 & 0x1f) & uVar4) >> (uVar5 & 0x1f) & 0xff) == 0) {
    if (0x37 < uVar3) {
_L172:
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x27c8,*(code **)(_r_plf_funcs_p + 8));
    }
    if (0x2f < (int)uVar3) {
_L175:
      iVar1 = 0x1800c488;
      goto _L185;
    }
  }
  else if (uVar3 < 0x38) {
    if ((int)uVar3 < 0x20) goto _L174;
    if (0x2f < (int)uVar3) goto _L171;
    _DAT_600312c8 = ~(1 << (uVar3 - 0x20 & 0x1f)) & _DAT_600312c8;
  }
  else {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x27fa,*(code **)(_r_plf_funcs_p + 8));
    if (0x1f < (int)uVar3) {
_L171:
      _DAT_60031300 = ~(1 << (uVar3 - 0x30 & 0x1f)) & _DAT_60031300;
      if (0x37 < uVar3) goto _L172;
      goto _L175;
    }
_L174:
    _DAT_600312c4 = ~(1 << (uVar3 & 0x1f)) & _DAT_600312c4;
    if (0x37 < uVar3) goto _L172;
  }
  iVar1 = 0x1800c481;
_L185:
  puVar2 = (uint *)((iVar1 + uVar3) * 4);
  if ((*puVar2 & 0x3ffff) != 0) {
    if (0x37 < uVar3) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x27c8,*(code **)(_r_plf_funcs_p + 8));
    }
    (**(code **)(_r_osi_funcs_p + 0x7c))
              ((*puVar2 & 0x3ffff) << 2 | 0x3fc00000,*(code **)(_r_osi_funcs_p + 0x7c));
    if (0x37 < uVar3) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x27c1,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar2 = *puVar2 & 0xfffc0000;
  }
  return;
}

