/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> arch_main.o -> btdm_ble_power_down_dma_copy
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
                    /* WARNING: Could not recover jumptable at 0x00010714. Too many branches */
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

