/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> emi.o -> r_emi_free_em_mapping_by_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_emi_free_em_mapping_by_offset(void)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  
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
  if ((((1 << (uVar5 & 0x1f) & uVar4) >> (uVar5 & 0x1f) & 0xff) == 0) && (2 < _g_bt_plf_log_level))
  {
    ets_printf("EMI: em mapping [%d] already disable\n",uVar3);
  }
  if (0x37 < uVar3) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x27c8,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((int)uVar3 < 0x30) {
    iVar1 = 0x1800c481;
  }
  else {
    iVar1 = 0x1800c488;
  }
  puVar2 = (uint *)((iVar1 + uVar3) * 4);
  if (((*puVar2 & 0x3ffff) == 0) && (2 < _g_bt_plf_log_level)) {
    ets_printf("EMI: em mapping [%d] already freed\n",uVar3);
  }
  if (uVar3 < 0x38) {
    if ((int)uVar3 < 0x20) goto _L159;
    if ((int)uVar3 < 0x30) {
      _DAT_600312c8 = ~(1 << (uVar3 - 0x20 & 0x1f)) & _DAT_600312c8;
      goto _L160;
    }
_L157:
    puVar6 = (uint *)&DAT_60031300;
    uVar4 = uVar3 - 0x30;
    uVar5 = _DAT_60031300;
  }
  else {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x27fa,*(code **)(_r_plf_funcs_p + 8));
    if (0x1f < (int)uVar3) goto _L157;
_L159:
    puVar6 = (uint *)&DAT_600312c4;
    uVar5 = _DAT_600312c4;
    uVar4 = uVar3;
  }
  *puVar6 = ~(1 << (uVar4 & 0x1f)) & uVar5;
  if (0x37 < uVar3) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x27c8,*(code **)(_r_plf_funcs_p + 8));
  }
_L160:
  (**(code **)(_r_osi_funcs_p + 0x7c))
            ((*puVar2 & 0x3ffff) << 2 | 0x3fc00000,*(code **)(_r_osi_funcs_p + 0x7c));
  if (0x37 < uVar3) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x27c1,*(code **)(_r_plf_funcs_p + 8));
  }
  *puVar2 = *puVar2 & 0xfffc0000;
  return;
}

