/*
 * Last changed at upstream commit f3c359a685a17bcc301e43778e7f581605e32d0a
 * https://github.com/espressif/esp32c3-bt-lib/commit/f3c359a685a17bcc301e43778e7f581605e32d0a
 * Upstream date: 2022-07-04 22:08:59 +0800
 * Upstream subject: fix ke_mem.c assert(0821b2a)
 * Source: libbtdm_app -> arch_main.o -> btdm_ble_power_down_dma_copy
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btdm_ble_power_down_dma_copy(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    (**(code **)(_r_osi_funcs_p + 200))(*(code **)(_r_osi_funcs_p + 200));
    ble_deepsleep_reset_lc_bb_reg();
    ble_deepsleep_recover_hw_reg();
    (**(code **)(_r_osi_funcs_p + 0xcc))
              (0x60031000,_LANCHOR1,0xe1,0,*(code **)(_r_osi_funcs_p + 0xcc));
    (**(code **)(_r_osi_funcs_p + 0xcc))
              (0x60011000,_LANCHOR2,0x38,0,*(code **)(_r_osi_funcs_p + 0xcc));
    _DAT_60026018 = _DAT_60026018 & 0xfffffdf7;
    return;
  }
  (**(code **)(_r_osi_funcs_p + 0xcc))
            (0x60031000,_LANCHOR1,0xe1,1,*(code **)(_r_osi_funcs_p + 0xcc));
  (**(code **)(_r_osi_funcs_p + 0xcc))
            (0x60011000,_LANCHOR2,0x38,1,*(code **)(_r_osi_funcs_p + 0xcc));
  do {
    iVar1 = btdm_sleep_clock_sync();
  } while (iVar1 == 0);
                    /* WARNING: Could not recover jumptable at 0x00011298. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0xc4))();
  return;
}

