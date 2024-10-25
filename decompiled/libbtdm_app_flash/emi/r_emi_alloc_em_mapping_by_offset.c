/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> emi.o -> r_emi_alloc_em_mapping_by_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_emi_alloc_em_mapping_by_offset(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  uVar3 = r_emi_get_em_mapping_idx_by_offset();
  uVar4 = _DAT_600312c4;
  uVar6 = uVar3;
  if (0x1f < (int)uVar3) {
    if ((int)uVar3 < 0x30) {
      uVar4 = _DAT_600312c8;
      uVar6 = uVar3 - 0x20;
    }
    else {
      uVar4 = _DAT_60031300;
      uVar6 = uVar3 - 0x30;
    }
  }
  if (((1 << (uVar6 & 0x1f) & uVar4) >> (uVar6 & 0x1f) & 0xff) == 1) {
    if (0 < _g_bt_plf_log_level) {
      ets_printf("EMI: alloc must after em mapping [%d] disable\n",uVar3);
    }
    uVar5 = 0x179;
  }
  else {
    if (0x37 < uVar3) {
      r_assert_err(0,"emi.c",0x27c8);
    }
    if ((int)uVar3 < 0x30) {
      iVar1 = 0x1800c481;
    }
    else {
      iVar1 = 0x1800c488;
    }
    puVar2 = (uint *)((iVar1 + uVar3) * 4);
    if ((*puVar2 & 0x3ffff) == 0) {
      uVar4 = (**(code **)(_r_osi_funcs_p + 0x78))(param_2,*(code **)(_r_osi_funcs_p + 0x78));
      if (uVar4 == 0) {
        return 7;
      }
      if (0x37 < uVar3) {
        r_assert_err(0,"emi.c",0x27c1);
      }
      *puVar2 = *puVar2 & 0xfffc0000 | uVar4 >> 2 & 0x3ffff;
      if (0x37 < uVar3) {
        r_assert_err(0,"emi.c",0x27fa);
      }
      if ((int)uVar3 < 0x20) {
        uVar4 = 1 << (uVar3 & 0x1f);
        _DAT_600312c4 = ~uVar4 & _DAT_600312c4 | uVar4;
      }
      else if ((int)uVar3 < 0x30) {
        uVar4 = 1 << (uVar3 - 0x20 & 0x1f);
        _DAT_600312c8 = ~uVar4 & _DAT_600312c8 | uVar4;
      }
      else {
        uVar4 = 1 << (uVar3 - 0x30 & 0x1f);
        _DAT_60031300 = ~uVar4 & _DAT_60031300 | uVar4;
      }
      return 0;
    }
    if (0 < _g_bt_plf_log_level) {
      ets_printf("EMI: alloc must after em mapping [%d] free\n",uVar3);
    }
    uVar5 = 0x17f;
  }
  r_assert_param(param_1,0,"emi.c",uVar5);
  return 0x1f;
}

