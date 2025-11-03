/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> emi.o -> r_emi_free_em_mapping_by_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_emi_free_em_mapping_by_offset(undefined4 param_1)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  
  uVar3 = r_emi_get_em_mapping_idx_by_offset();
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
    r_assert_err(0,0x10000,0x27c8);
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
    r_assert_err(0,0x10000,0x27fa);
  }
  if ((int)uVar3 < 0x20) {
    puVar6 = (uint *)&DAT_600312c4;
    uVar5 = _DAT_600312c4;
    uVar4 = uVar3;
  }
  else if ((int)uVar3 < 0x30) {
    puVar6 = (uint *)&DAT_600312c8;
    uVar4 = uVar3 - 0x20;
    uVar5 = _DAT_600312c8;
  }
  else {
    puVar6 = (uint *)&DAT_60031300;
    uVar4 = uVar3 - 0x30;
    uVar5 = _DAT_60031300;
  }
  *puVar6 = ~(1 << (uVar4 & 0x1f)) & uVar5;
  if (0x37 < uVar3) {
    r_assert_err(0,0x10000,0x27c8);
  }
  (**(code **)(_r_osi_funcs_p + 0x7c))
            ((*puVar2 & 0x3ffff) << 2 | 0x3fc00000,*(code **)(_r_osi_funcs_p + 0x7c));
  if (0x37 < uVar3) {
    r_assert_err(0,0x10000,0x27c1);
  }
  *puVar2 = *puVar2 & 0xfffc0000;
  r_ble_log_internal_x3(0x206801cf,param_1,*puVar2,uVar3);
  return;
}

