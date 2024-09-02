/*
 * Last changed at upstream commit d874f55e1132416fe18293ae1aa9ac73c40b3261
 * https://github.com/espressif/esp32c3-bt-lib/commit/d874f55e1132416fe18293ae1aa9ac73c40b3261
 * Upstream date: 2024-09-02 19:56:58 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(8ce789b)
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
_L89:
      (**(code **)(_r_plf_funcs_p + 8))(0,"emi.c",0x27c8,*(code **)(_r_plf_funcs_p + 8));
    }
    if (0x2f < (int)uVar3) {
_L90:
      iVar1 = 0x488;
      goto _L101;
    }
  }
  else {
    if (0x37 < uVar3) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"emi.c",0x27fa,*(code **)(_r_plf_funcs_p + 8));
    }
    if (0x1f < (int)uVar3) {
      if ((int)uVar3 < 0x30) {
        _DAT_600312c8 = ~(1 << (uVar3 - 0x20 & 0x1f)) & _DAT_600312c8;
        goto _L87;
      }
      _DAT_60031300 = ~(1 << (uVar3 - 0x30 & 0x1f)) & _DAT_60031300;
      if (0x37 < uVar3) goto _L89;
      goto _L90;
    }
    _DAT_600312c4 = ~(1 << (uVar3 & 0x1f)) & _DAT_600312c4;
_L87:
    if (0x37 < uVar3) goto _L89;
  }
  iVar1 = 0x481;
_L101:
  puVar2 = (uint *)((iVar1 + 0x1800c000 + uVar3) * 4);
  if ((*puVar2 & 0x3ffff) != 0) {
    if (0x37 < uVar3) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"emi.c",0x27c8,*(code **)(_r_plf_funcs_p + 8));
    }
    (**(code **)(_r_osi_funcs_p + 0x7c))
              ((*puVar2 & 0x3ffff) << 2 | 0x3fc00000,*(code **)(_r_osi_funcs_p + 0x7c));
    if (0x37 < uVar3) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"emi.c",0x27c1,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar2 = *puVar2 & 0xfffc0000;
  }
  return;
}

