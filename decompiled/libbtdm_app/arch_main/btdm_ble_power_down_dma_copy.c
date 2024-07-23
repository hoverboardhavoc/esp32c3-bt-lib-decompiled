/*
 * Last changed at upstream commit d4922c5890feb6ee1733e6063369ff54a30f5930
 * https://github.com/espressif/esp32c3-bt-lib/commit/d4922c5890feb6ee1733e6063369ff54a30f5930
 * Upstream date: 2024-07-23 16:16:25 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(4e58df9)
 * Source: libbtdm_app -> arch_main.o -> btdm_ble_power_down_dma_copy
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btdm_ble_power_down_dma_copy(int param_1)

{
  if (param_1 != 0) {
    (**(code **)(_r_osi_funcs_p + 0xdc))
              (0x60031000,_LANCHOR2,0xe1,1,*(code **)(_r_osi_funcs_p + 0xdc));
    (**(code **)(_r_osi_funcs_p + 0xdc))
              (0x60011000,_LANCHOR3,0x38,1,*(code **)(_r_osi_funcs_p + 0xdc));
    (**(code **)(_r_osi_funcs_p + 0xdc))
              (0x60011800,_LANCHOR4,0x2d,1,*(code **)(_r_osi_funcs_p + 0xdc));
    do {
    } while ((_DAT_60042000 & 0x80) == 0);
                    /* WARNING: Could not recover jumptable at 0x0001079a. Too many branches */
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
                    /* WARNING: Could not recover jumptable at 0x00010810. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0xdc))(0x60011800,_LANCHOR4,0x2d,0);
  return;
}

