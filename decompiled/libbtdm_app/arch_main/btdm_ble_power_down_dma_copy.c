/*
 * Last changed at upstream commit 4c16da1a1a76b439e2cf981d2f915d94df364e58
 * https://github.com/espressif/esp32c3-bt-lib/commit/4c16da1a1a76b439e2cf981d2f915d94df364e58
 * Upstream date: 2024-12-16 11:11:02 +0800
 * Upstream subject: fix(bt): Fixed that the resolvable private address does not change when light sleep is enabled(6bca137)
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
              (0x60031000,_LANCHOR2,0xe1,1,*(code **)(_r_osi_funcs_p + 0xdc));
    (**(code **)(_r_osi_funcs_p + 0xdc))
              (0x60011000,_LANCHOR3,0x38,1,*(code **)(_r_osi_funcs_p + 0xdc));
    (**(code **)(_r_osi_funcs_p + 0xdc))
              (0x60011800,_LANCHOR4,0x2d,1,*(code **)(_r_osi_funcs_p + 0xdc));
    do {
    } while ((_DAT_60042000 & 0x80) == 0);
                    /* WARNING: Could not recover jumptable at 0x000107a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_osi_funcs_p + 0xd4))();
    return;
  }
  (**(code **)(_r_osi_funcs_p + 0xd8))(*(code **)(_r_osi_funcs_p + 0xd8));
  ble_deepsleep_reset_lc_bb_reg();
  ble_deepsleep_recover_hw_reg();
  (**(code **)(_r_osi_funcs_p + 0xdc))
            (0x60031000,_LANCHOR2,0xe1,0,*(code **)(_r_osi_funcs_p + 0xdc));
  (**(code **)(_r_osi_funcs_p + 0xdc))
            (0x60011000,_LANCHOR3,0x38,0,*(code **)(_r_osi_funcs_p + 0xdc));
  ble_deepsleep_recover_hw_logic();
  (**(code **)(_r_osi_funcs_p + 0xdc))
            (0x60011800,_LANCHOR4,0x2d,0,*(code **)(_r_osi_funcs_p + 0xdc));
  uVar1 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  _DAT_60031178 = uVar1 & 0x3fffff | 0x80000000;
  uVar1 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  _DAT_6003117c = uVar1 & 0x3fffff | 0x80000000;
  return;
}

