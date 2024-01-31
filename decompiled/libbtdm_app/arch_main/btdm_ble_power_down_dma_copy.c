/*
 * Last changed at upstream commit 0caae2bd70a999ac8a1c07330f7168e185db81ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/0caae2bd70a999ac8a1c07330f7168e185db81ba
 * Upstream date: 2024-01-31 19:37:46 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(91980c2)
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
    (**(code **)(_r_osi_funcs_p + 0xcc))
              (0x60031000,_LANCHOR2,0xe1,1,*(code **)(_r_osi_funcs_p + 0xcc));
    (**(code **)(_r_osi_funcs_p + 0xcc))
              (0x60011000,_LANCHOR3,0x38,1,*(code **)(_r_osi_funcs_p + 0xcc));
    (**(code **)(_r_osi_funcs_p + 0xcc))
              (0x60011800,_LANCHOR4,0x2d,1,*(code **)(_r_osi_funcs_p + 0xcc));
    do {
    } while ((_DAT_60042000 & 0x80) == 0);
                    /* WARNING: Could not recover jumptable at 0x0001072a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_osi_funcs_p + 0xc4))();
    return;
  }
  (**(code **)(_r_osi_funcs_p + 200))(*(code **)(_r_osi_funcs_p + 200));
  ble_deepsleep_reset_lc_bb_reg();
  ble_deepsleep_recover_hw_reg();
  (**(code **)(_r_osi_funcs_p + 0xcc))
            (0x60031000,_LANCHOR2,0xe1,0,*(code **)(_r_osi_funcs_p + 0xcc));
  (**(code **)(_r_osi_funcs_p + 0xcc))
            (0x60011000,_LANCHOR3,0x38,0,*(code **)(_r_osi_funcs_p + 0xcc));
  ble_deepsleep_recover_hw_logic();
                    /* WARNING: Could not recover jumptable at 0x000107a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0xcc))(0x60011800,_LANCHOR4,0x2d,0);
  return;
}

