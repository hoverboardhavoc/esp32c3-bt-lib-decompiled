/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
    (**(code **)(_r_plf_funcs_p + 8))(0,"emi.c",0x27c8,*(code **)(_r_plf_funcs_p + 8));
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
  if (0x37 < uVar3) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"emi.c",0x27fa,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((int)uVar3 < 0x20) {
    _DAT_600312c4 = ~(1 << (uVar3 & 0x1f)) & _DAT_600312c4;
  }
  else if ((int)uVar3 < 0x30) {
    _DAT_600312c8 = ~(1 << (uVar3 - 0x20 & 0x1f)) & _DAT_600312c8;
  }
  else {
    _DAT_60031300 = ~(1 << (uVar3 - 0x30 & 0x1f)) & _DAT_60031300;
  }
  if (0x37 < uVar3) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"emi.c",0x27c8,*(code **)(_r_plf_funcs_p + 8));
  }
  (**(code **)(_r_osi_funcs_p + 0x7c))
            ((*puVar2 & 0x3ffff) << 2 | 0x3fc00000,*(code **)(_r_osi_funcs_p + 0x7c));
  if (0x37 < uVar3) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"emi.c",0x27c1,*(code **)(_r_plf_funcs_p + 8));
  }
  *puVar2 = *puVar2 & 0xfffc0000;
  return;
}

