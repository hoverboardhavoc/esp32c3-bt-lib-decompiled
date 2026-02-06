/*
 * Last changed at upstream commit ebd6043a8e3c3bbde45ee483895303b9c1229ab5
 * https://github.com/espressif/esp32c3-bt-lib/commit/ebd6043a8e3c3bbde45ee483895303b9c1229ab5
 * Upstream date: 2026-02-06 15:59:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b7de11e)
 * Source: libbtdm_app -> arch_main.o -> btdm_ble_power_down_dma_copy
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btdm_ble_power_down_dma_copy(int param_1)

{
  uint uVar1;
  
  if (param_1 != 0) {
    (**(code **)(_r_osi_funcs_p + 0xdc))
              (0x60031000,lc_mem_addr,0xe1,1,*(code **)(_r_osi_funcs_p + 0xdc));
    (**(code **)(_r_osi_funcs_p + 0xdc))
              (0x60011000,bb_mem_addr,0x38,1,*(code **)(_r_osi_funcs_p + 0xdc));
    (**(code **)(_r_osi_funcs_p + 0xdc))
              (0x60011800,bb_agc_mem_addr,0x2d,1,*(code **)(_r_osi_funcs_p + 0xdc));
    do {
    } while ((_DAT_60042000 & 0x80) == 0);
                    /* WARNING: Could not recover jumptable at 0x00010cc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_osi_funcs_p + 0xd4))(*(code **)(_r_osi_funcs_p + 0xd4));
    return;
  }
  (**(code **)(_r_osi_funcs_p + 0xd8))(*(code **)(_r_osi_funcs_p + 0xd8));
  ble_deepsleep_reset_lc_bb_reg();
  ble_deepsleep_recover_hw_reg();
  (**(code **)(_r_osi_funcs_p + 0xdc))
            (0x60031000,lc_mem_addr,0xe1,0,*(code **)(_r_osi_funcs_p + 0xdc));
  (**(code **)(_r_osi_funcs_p + 0xdc))
            (0x60011000,bb_mem_addr,0x38,0,*(code **)(_r_osi_funcs_p + 0xdc));
  ble_deepsleep_recover_hw_logic();
  (**(code **)(_r_osi_funcs_p + 0xdc))
            (0x60011800,bb_agc_mem_addr,0x2d,0,*(code **)(_r_osi_funcs_p + 0xdc));
  uVar1 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  _DAT_60031178 = uVar1 & 0x3fffff | 0x80000000;
  uVar1 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  _DAT_6003117c = uVar1 & 0x3fffff | 0x80000000;
  if (_DAT_6003100c == 0) {
                    /* WARNING: Could not recover jumptable at 0x00010d8e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 8))(0,"arch_main.c",0x3a7,*(code **)(_r_plf_funcs_p + 8));
    return;
  }
  return;
}

